//**************************************************************************************************
// @Module  PIT driver
//! \file       pit_drv.c
//! \par    Platform
//!             STM32F4, GD32F4, APM32F4, AT32F4, HC23F4A
//! \par    Compatible
//!             STM32F4xx, GD32F4xx, APM32F4xx, AT32F4xx, HC23F4Axx
//! \brief  This file contains functions for the Periodic Interrupt PIT (PIT) driver.
//!
//! \par    Abbreviations
//!             PIT - Periodic Interrupt Timer
//!
//! \par    History
//! Date           | Version | Author | Comment
//! :-------------:|:-------:|:------:|----------------------------------
//!    24.03.2022  |  1.0.0  |  YSY   | First release.
//!    22.06.2022  |  2.0.0  |  MVV   | STM32 new registers config
//!    27.06.2022  |  2.0.1  |  MVV   | Tested compatibility with AT32F4
//!    18.07.2022  |  3.0.0  |  MVV   | Changed clocking source
//!    14.04.2023  |  3.0.1  |  KMM   | Tested compatibility with HC32F4A
//**************************************************************************************************



//**************************************************************************************************
//! \defgroup   MODULE PIT driver
//! \brief      PIT driver
//! \addtogroup MODULE
//! @{
//! \file pit_drv.h
//! \file pit_drv.c
//! \file pit_drv_cfg.h
//! \file pit_drv_irq.c
//! \file pit_drv_irq.h
//! \file programmer_guide.md
//! @}
//**************************************************************************************************



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Native header
#include "pit_drv.h"

#include "derivative_cfg.h"
#include "mcu_drv.h"
#include "error_tracer.h"



//**************************************************************************************************
// Verification of the imported configuration parameters
//**************************************************************************************************

// Checking software prescaler for bus frequency
#if ((PIT_PRESCALER < 1) || (PIT_PRESCALER > 255))
#error "pit_drv_cfg.h: PIT_PRESCALER must be in the range from 1 to 255"
#endif



//**************************************************************************************************
// Definitions of global (public) variables
//**************************************************************************************************

#if (ON == PIT_MONITORING_FUNCTION)
//! \name Diagnostic variables for monitoring call functions
//! @{
U8 PIT_nDgnInit = 0U;
U8 PIT_nDgnDeInit = 0U;
U8 PIT_nDgnGetTime = 0U;
U8 PIT_nDgnSetTime = 0U;
U8 PIT_nDgnStartTimer = 0U;
U8 PIT_nDgnStopTimer = 0U;
U8 PIT_nDgnGetTickPeriod = 0U;
U8 PIT_nDgnSetCallbackFunction = 0U;
U8 PIT_nDgnHighLevel_ISR = 0U;
//! @}
#endif



//**************************************************************************************************
// Declarations of local (private) data types
//**************************************************************************************************

//! PIT initialization states
typedef enum
{
    //! State not initialized
    PIT_INIT_STATE_NOT_INIT = 0U,
    //! State initialized
    PIT_INIT_STATE_INIT     = 1U,
} PIT_INIT_STATE;


#if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
//! Program module API IDs
typedef enum
{
    //! API ID for inner function
    PIT_API_ID_INNER_FUNC          = 0U,
    //! API ID for PIT_Init() function
    PIT_API_ID_INIT                = 1U,
    //! API ID for PIT_DeInit() function
    PIT_API_ID_DEINIT              = 2U,
    //! API ID for PIT_GetTime() function
    PIT_API_ID_GETTIME             = 3U,
    //! API ID for PIT_SetTime() function
    PIT_API_ID_SETTIME             = 4U,
    //! API ID for PIT_StartPit() function
    PIT_API_ID_STARTPIT            = 5U,
    //! API ID for PIT_StopPit() function
    PIT_API_ID_STOPPIT             = 6U,
    //! API ID for PIT_GetTickPeriod() function
    PIT_API_ID_GETTICKPERIOD       = 7U,
    //! API ID for PIT_SetCallbackFunction() function
    PIT_API_ID_SETCALLBACKFUNCTION = 8U,
    //! API ID for PIT_HighLevelISR() function
    PIT_API_ID_HIGHLEVELISR        = 9U,
} PIT_API_ID;
#endif



//**************************************************************************************************
// Definitions of local (private) constants
//**************************************************************************************************

//! Maximum counter value
#define PIT_MAX_VALUE           (0x00FFFFFFUL)

//! Nanoseconds in second
#define PIT_NSEC_IN_SEC         (1000000000UL)

//! Timer minimum period, ns
#define PIT_PERIOD_MIN_NS       (10000U)

#if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
//! \name Program module ID constants and macros for error tracing
//! @{
static const U8 PIT_pModuleID[] = "PIT_DRIVER";
static const U8 PIT_nModuleIDSize = SIZE_OF_ARRAY(PIT_pModuleID) - 1U;
//! @}

//! Error tracer function
#define PIT_REPORT_DEV_ERROR(PIT_nAPIID, nErrorID)  \
ET_ReportDevelopmentError(PIT_pModuleID,            \
                          PIT_nModuleIDSize,        \
                          nTimerNumber,             \
                          PIT_nAPIID,               \
                          nErrorID);
#endif



//**************************************************************************************************
// Definitions of static global (private) variables
//**************************************************************************************************

//! Pointer to callback function for PIT interrupt
static PIT_CALLBACK PIT_pCallbackFunction = NULL_PTR;

//! PIT current initialization state
static PIT_INIT_STATE PIT_nInitState = PIT_INIT_STATE_NOT_INIT;

//! Timer tick period, ns
static U32 PIT_nTickPeriod = 0UL;



//**************************************************************************************************
// Declarations of local (private) functions
//**************************************************************************************************

// None



//**************************************************************************************************
//==================================================================================================
// Definitions of global (public) functions
//==================================================================================================
//**************************************************************************************************



//**************************************************************************************************
//! PIT driver initialization function.
//!
//! \note      Should be called before any action can be take with the PITs.
//!
//! \param[in] nTimerNumber - PIT timer number.
//!
//! \return    RESULT_OK     - ADC driver initialization succeeded.
//!            RESULT_NOT_OK - ADC driver is already initialized.
//**************************************************************************************************
STD_RESULT PIT_Init(const U8 nTimerNumber)
{
    // Function result
    STD_RESULT nFuncResult = RESULT_OK;

    #if (ON == PIT_MONITORING_FUNCTION)
    PIT_nDgnInit++;
    #endif

    if (PIT_INIT_STATE_INIT == PIT_nInitState)
    {
        nFuncResult = RESULT_NOT_OK;
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_INIT, DEV_ERROR_ALREADY_INIT);
        #endif
    }
    else if (nTimerNumber > PIT_LAST)
    {
        nFuncResult = RESULT_NOT_OK;
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_INIT, DEV_ERROR_PARAM_0);
        #endif
    }
    else
    {
        // Get BUS0 clock frequency
        PIT_nTickPeriod = (U32)(PIT_NSEC_IN_SEC /
                               (MCU_GetBusFrequency(MCU_CLOCK_SOURCE_BUS0) / PIT_PRESCALER));
        // Set no callback function
        PIT_pCallbackFunction = NULL_PTR;
        // Reset reload value
        STK.LOAD.B.RELOAD = 0U;
        // Clear current value register
        STK.VAL.B.CURRENT = 0U;
        // Disable the counter
        STK.CTRL.B.ENABLE = OFF;
        // Set ref clock source
        STK.CTRL.B.CLKSOURCE = ON;
        // Set initialized state of PIT
        PIT_nInitState = PIT_INIT_STATE_INIT;
    }

    return nFuncResult;
} // end of PIT_Init()



//**************************************************************************************************
//! PIT driver deinitialization function.
//!
//! \note      None.
//!
//! \param[in] nTimerNumber - PIT timer number.
//!
//! \return    RESULT_OK     - The function succeeded.
//!            RESULT_NOT_OK - The function is not succeeded because of an error.
//**************************************************************************************************
STD_RESULT PIT_DeInit(const U8 nTimerNumber)
{
    // Function result
    STD_RESULT nFuncResult = RESULT_OK;

    #if (ON == PIT_MONITORING_FUNCTION)
    PIT_nDgnDeInit++;
    #endif

    if (PIT_INIT_STATE_NOT_INIT == PIT_nInitState)
    {
        nFuncResult = RESULT_NOT_OK;
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_DEINIT, DEV_ERROR_NOT_INIT);
        #endif
    }
    else if (nTimerNumber > PIT_LAST)
    {
        nFuncResult = RESULT_NOT_OK;
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_DEINIT, DEV_ERROR_PARAM_0);
        #endif
    }
    else
    {
        // Stop timer
        STK.CTRL.B.ENABLE = OFF;
        // No callback function
        PIT_pCallbackFunction = NULL_PTR;
        // Reset reload value
        STK.LOAD.B.RELOAD = 0U;
        // Clear current value
        STK.VAL.B.CURRENT = 0U;
        // Reset clock source
        STK.CTRL.B.CLKSOURCE = OFF;
        // Set deinitialized state of PIT
        PIT_nInitState = PIT_INIT_STATE_NOT_INIT;
    }

    return nFuncResult;
} // end of PIT_DeInit()



//**************************************************************************************************
//! Reading current volume of PIT counter.
//!
//! \note       None.
//!
//! \param[in]  nTimerNumber  - PIT timer number.
//! \param[out] pTimerCounter - Pointer for save current PIT value.
//!
//! \return     RESULT_OK     - The function succeeded.
//!             RESULT_NOT_OK - The function is not succeeded because of an error.
//**************************************************************************************************
STD_RESULT PIT_GetTime(const U8 nTimerNumber,
                       PIT_SZ* const pTimerCounter)
{
    // Function result
    STD_RESULT nFuncResult = RESULT_OK;

    #if (ON == PIT_MONITORING_FUNCTION)
    PIT_nDgnGetTime++;
    #endif

    if (PIT_INIT_STATE_NOT_INIT == PIT_nInitState)
    {
        nFuncResult = RESULT_NOT_OK;
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_GETTIME, DEV_ERROR_NOT_INIT);
        #endif
    }
    else if (nTimerNumber > PIT_LAST)
    {
        nFuncResult = RESULT_NOT_OK;
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_GETTIME, DEV_ERROR_PARAM_0);
        #endif
    }
    else if (NULL_PTR == pTimerCounter)
    {
        nFuncResult = RESULT_NOT_OK;
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_GETTIME, DEV_ERROR_PARAM_1);
        #endif
    }
    else
    {
        // Get current value of timer
        *pTimerCounter = STK.VAL.B.CURRENT / PIT_PRESCALER;
    }

    return nFuncResult;
} // end of PIT_GetTime()



//**************************************************************************************************
//!  Set PIT counter.
//!
//! \note      None.
//!
//! \param[in] nTimerNumber  - PIT timer number.
//! \param[in] nTimerCounter - Value for PIT counter.
//!
//! \return    RESULT_OK     - The function succeeded.
//!            RESULT_NOT_OK - The function is not succeeded because of an error.
//**************************************************************************************************
STD_RESULT PIT_SetTime(const U8 nTimerNumber,
                       const PIT_SZ nTimerCounter)
{
    (void)nTimerNumber;
    (void)nTimerCounter;

    #if (ON == PIT_MONITORING_FUNCTION)
    PIT_nDgnSetTime++;
    #endif

    #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
    PIT_REPORT_DEV_ERROR(PIT_API_ID_SETTIME, DEV_ERROR_FUNC_NOT_SUPP);
    #endif

    return RESULT_NOT_OK;
} // end of PIT_SetTime()



//**************************************************************************************************
//! Start PIT timer with period setting.
//!
//! \note      None.
//!
//! \param[in] nTimerNumber  - PIT timer number.
//! \param[in] nTimerCounter - Value for PIT counter.
//!
//! \return    RESULT_OK     - The function succeeded.
//!            RESULT_NOT_OK - The function is not succeeded because of an error.
//**************************************************************************************************
STD_RESULT PIT_StartTimer(const U8 nTimerNumber,
                          const PIT_SZ nTimerPeriod)
{
    // Function result
    STD_RESULT nFuncResult = RESULT_OK;

    #if (ON == PIT_MONITORING_FUNCTION)
    PIT_nDgnStartTimer++;
    #endif

    PIT_SZ nScaledTimerPeriod = (nTimerPeriod * PIT_PRESCALER) - 1U;

    if (PIT_INIT_STATE_NOT_INIT == PIT_nInitState)
    {
        nFuncResult = RESULT_NOT_OK;
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_STARTPIT, DEV_ERROR_NOT_INIT);
        #endif
    }
    else if (nTimerNumber > PIT_LAST)
    {
        nFuncResult = RESULT_NOT_OK;
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_STARTPIT, DEV_ERROR_PARAM_0);
        #endif
    }
    else if (nScaledTimerPeriod > PIT_MAX_VALUE)
    {
        nFuncResult = RESULT_NOT_OK;
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_STARTPIT, DEV_ERROR_PARAM_1);
        #endif
    }
    else if ((nTimerPeriod * PIT_nTickPeriod) < PIT_PERIOD_MIN_NS)
    {
        nFuncResult = RESULT_NOT_OK;
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_STARTPIT, DEV_ERROR_PARAM_1);
        #endif
    }
    else
    {
        // Set reload register
        STK.LOAD.B.RELOAD     = nScaledTimerPeriod;
        // Start timer
        STK.CTRL.B.ENABLE     = PIT_T0_ENABLE;
    }

    return nFuncResult;
} // end of PIT_StartTimer()



//**************************************************************************************************
//! Stop PIT timer.
//!
//! \note      None.
//!
//! \param[in] nTimerNumber  - PIT timer number.
//!
//! \return    RESULT_OK     - The function succeeded.
//!            RESULT_NOT_OK - The function is not succeeded because of an error.
//**************************************************************************************************
STD_RESULT PIT_StopTimer(const U8 nTimerNumber)
{
    // Function result
    STD_RESULT nFuncResult = RESULT_OK;

    #if (ON == PIT_MONITORING_FUNCTION)
    PIT_nDgnStopTimer++;
    #endif

    if (PIT_INIT_STATE_NOT_INIT == PIT_nInitState)
    {
        nFuncResult = RESULT_NOT_OK;
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_STOPPIT, DEV_ERROR_NOT_INIT);
        #endif
    }
    else if (nTimerNumber > PIT_LAST)
    {
        nFuncResult = RESULT_NOT_OK;
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_STOPPIT, DEV_ERROR_PARAM_0);
        #endif
    }
    else
    {
        // Stop timer
        STK.CTRL.B.ENABLE = OFF;
    }

    return nFuncResult;
} // end of PIT_StopTimer()



//**************************************************************************************************
//! Get PIT tick period in nanoseconds.
//!
//! \note       None.
//!
//! \param[in]  nTimerNumber  - PIT timer number.
//! \param[out] pTickPeriod   - Pointer to the tick period variable.
//!
//! \return     RESULT_OK     - The function succeeded.
//!             RESULT_NOT_OK - The function is not succeeded because of an error.
//**************************************************************************************************
STD_RESULT PIT_GetTickPeriod(const U8 nTimerNumber,
                             U32* const pTickPeriod)
{
    // Function result
    STD_RESULT nFuncResult = RESULT_OK;

    #if (ON == PIT_MONITORING_FUNCTION)
    PIT_nDgnGetTickPeriod++;
    #endif

    if (PIT_INIT_STATE_NOT_INIT == PIT_nInitState)
    {
        nFuncResult = RESULT_NOT_OK;
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_GETTICKPERIOD, DEV_ERROR_NOT_INIT);
        #endif
    }
    else if (nTimerNumber > PIT_LAST)
    {
        nFuncResult = RESULT_NOT_OK;
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_GETTICKPERIOD, DEV_ERROR_PARAM_0);
        #endif
    }
    else if (NULL_PTR == pTickPeriod)
    {
        nFuncResult = RESULT_NOT_OK;
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_GETTICKPERIOD, DEV_ERROR_PARAM_1);
        #endif
    }
    else
    {
        // Get tick period
        *pTickPeriod = PIT_nTickPeriod;
    }

    return nFuncResult;
} // end of PIT_GetTickPeriod()



//**************************************************************************************************
//! Set callback function pointer for the PIT timer.
//!
//! \note      None.
//!
//! \param[in] nTimerNumber  - PIT timer number.
//! \param[in] pCallbackFunction - Pointer to the callback function. Can be null pointer.
//!
//! \return    RESULT_OK     - The function succeeded.
//!            RESULT_NOT_OK - The function is not succeeded because of an error.
//**************************************************************************************************
STD_RESULT PIT_SetCallbackFunction(const U8 nTimerNumber,
                                   const PIT_CALLBACK pCallbackFunction)
{
    // Function result
    STD_RESULT nFuncResult = RESULT_OK;

    #if (ON == PIT_MONITORING_FUNCTION)
    PIT_nDgnSetCallbackFunction++;
    #endif

    if (PIT_INIT_STATE_NOT_INIT == PIT_nInitState)
    {
        nFuncResult = RESULT_NOT_OK;
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_SETCALLBACKFUNCTION, DEV_ERROR_NOT_INIT);
        #endif
    }
    else if (nTimerNumber > PIT_LAST)
    {
        nFuncResult = RESULT_NOT_OK;
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_SETCALLBACKFUNCTION, DEV_ERROR_PARAM_0);
        #endif
    }
    else
    {
        // Set callback function
        PIT_pCallbackFunction = pCallbackFunction;
    }
    
    return nFuncResult;
} // end of PIT_SetCallbackFunction()



//**************************************************************************************************
//! Set callback function pointer for the PIT timer.
//!
//! \note      None.
//!
//! \param[in] nTimerNumber  - PIT timer number.
//!
//! \return    None.
//**************************************************************************************************
void PIT_HighLevel_ISR(const U8 nTimerNumber)
{
    #if (ON == PIT_MONITORING_FUNCTION)
    PIT_nDgnHighLevel_ISR++;
    #endif

    if (PIT_INIT_STATE_NOT_INIT == PIT_nInitState)
    {
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_HIGHLEVELISR, DEV_ERROR_NOT_INIT);
        #endif
    }
    else if (nTimerNumber > PIT_LAST)
    {
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_HIGHLEVELISR, DEV_ERROR_PARAM_0);
        #endif
    }
    else if (NULL_PTR == PIT_pCallbackFunction)
    {
        #if (ON == PIT_DEVELOPMENT_ERROR_DETECTION)
        PIT_REPORT_DEV_ERROR(PIT_API_ID_HIGHLEVELISR, DEV_ERROR_PARAM_1);
        #endif
    }
    else
    {
        // Call callback function
        PIT_pCallbackFunction();
    }
} // end of PIT_HighLevel_ISR()



//**************************************************************************************************
//==================================================================================================
// Definitions of local (private) functions
//==================================================================================================
//**************************************************************************************************

// None



//****************************************** end of file *******************************************
