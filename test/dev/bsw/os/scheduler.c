//**************************************************************************************************
// @Module        SCHDL
//! \file   scheduler.c
//! \par    Platform
//!             Independent
//! \par    Compatible
//!             Independent
//! \brief  Implementation of the task scheduler functionality.
//!
//! \par    History
//! Date       | Version | Author  | Comment
//! :---------:|:-------:|:-------:|---------------
//! 30.05.2017 |  1.0.0  |   SHA   | First release.
//! 26.11.2018 |  1.1.0  |   SRM   | ISR optimization avoidance has been added.
//! 25.06.2019 |  1.2.0  |   ZAO   | Added function SCHDL_GetAndResetIdleCounter().
//! 22.07.2019 |  1.3.0  |   SHA   | Added function SCHDL_RunLevelImmed().
//! 14.04.2023 |  1.3.1  |   PAV   | Refactoring according to Doxygen rules.
//**************************************************************************************************



//**************************************************************************************************
//! \defgroup   SCHDL Scheduler
//! \brief      Implements work with scheduler
//! \addtogroup SCHDL
//! @{
//! \file scheduler.h
//! \file scheduler.c
//! \file scheduler_cfg.h.tmpl
//! \file portable.c
//! \file portable.h
//! @}
//**************************************************************************************************



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Native header
#include "scheduler.h"

#include "error_tracer.h"
#include "portable.h"



//**************************************************************************************************
// Verification of the imported configuration parameters
//**************************************************************************************************

#if((SCHDL_TASK_COUNT < 1) || (SCHDL_TASK_COUNT > 255))
    #error "scheduler_cfg.h:" SCHDL_TASK_COUNT should be in the range from 1 to 255.
#endif

#if((SCHDL_MAX_RUN_TASK < 1) || (SCHDL_MAX_RUN_TASK > SCHDL_TASK_COUNT))
    #error "scheduler_cfg.h:" SCHDL_MAX_RUN_TASK should be in the range from 1 to SCHDL_TASK_COUNT.
#endif



//**************************************************************************************************
// Definitions of global (public) variables
//**************************************************************************************************

//! Functions array
extern _FUNC_ TaskTable[];

//! Task requests table
U16 SCHDL_nTaskQuery[SCHDL_TASK_COUNT] = {0};

//! Task running flags table
U16 SCHDL_nTaskRunning[SCHDL_TASK_COUNT] = {0};

//! Running task counter
U8  SCHDL_nRunningTaskCounter = 0;



//**************************************************************************************************
// Declarations of local (private) data types
//**************************************************************************************************

//! Program module API IDs
typedef enum SCHDL_API_ID_enu
{
    //! Inner function ID
    SCHDL_API_ID_INNER_FUNC             = (U8)0U,
    //! Init function ID
    SCHDL_API_ID_INIT                   = (U8)1U,
    //! Deinit function ID
    SCHDL_API_ID_DEINIT                 = (U8)2U,
    //! Enable function ID
    SCHDL_API_ID_ENABLE                 = (U8)3U,
    //! Disable function ID
    SCHDL_API_ID_DISABLE                = (U8)4U,
    //! StartLevel function ID
    SCHDL_API_ID_STARTLEVEL             = (U8)5U,
    //! ActivateLevel function ID
    SCHDL_API_ID_ACTIVATELEVEL          = (U8)6U,
    //! StartSchedule function ID
    SCHDL_API_ID_STARTSCHEDULE          = (U8)7U,
    //! RunLevelImmed function ID
    SCHDL_API_ID_RUNLEVELIMMED          = (U8)8U,
    //! IncIdleCounter function ID
    SCHDL_API_ID_INCIDLECOUNTER         = (U8)9U,
    //! GetIdleCounter function ID
    SCHDL_API_ID_GETIDLECOUNTER         = (U8)10U,
    //! GetAdnResetIdleCounter function ID
    SCHDL_API_ID_GETANDRESETIDLECOUNTER = (U8)11U

} SCHDL_API_ID;

//! Standard result type
typedef enum SCHDL_RESULT_enum
{
    //! Function succeeded
    SCHDL_FUNC_OK     = (U8)0U,
    //! Function not succeeded
    SCHDL_FUNC_NOT_OK = (U8)1U

} SCHDL_RESULT;



//**************************************************************************************************
// Definitions of local (private) constants
//**************************************************************************************************

#if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
//! Program module ID ( = program module prefix)
static const U8 SCHDL_moduleID[] = "SCHEDULER";
#endif



//**************************************************************************************************
// Definitions of static global (private) variables
//**************************************************************************************************

#if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
//! SCHDL initialization state
static BOOLEAN SCHDL_bInitialized = FALSE;
#endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)

//! Idle counter
static NEAR U32 SCHDL_nIdleCounter;

//! Active task number
static U16 SCHDL_nActiveTaskNumber = 0;

//! Reset request flag
static BOOLEAN SCHDL_bResetIdleCounterRequest = 0;

#if(ON == SCHDL_INTERNAL_DIAGNOSTICS)
//! Task query counters
static U16 SCHDL_nTaskQueryCounter[SCHDL_TASK_COUNT] = {0};

//! Task overrun counters
static U16 SCHDL_nTaskOverrunCounter[SCHDL_TASK_COUNT] = {0};
#endif // #if(ON == SCHDL_INTERNAL_DIAGNOSTICS)



//**************************************************************************************************
// Declarations of local (private) functions
//**************************************************************************************************

//! \brief Level activate in query table
static U8 SCHDL_SetActivateLevel(U16 nLevelNumber);



//**************************************************************************************************
//==================================================================================================
// Definitions of global (public) functions
//==================================================================================================
//**************************************************************************************************



//**************************************************************************************************
//! Initializes SW and HW resources for task scheduler.
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
void SCHDL_Init(void)
{
    // For clear bit maps
    U8 nNumWord = 0;

    SCHDL_AvoidISRLibraryOptimization();

    #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
    // Checking whether initialization is done or not
    if (FALSE == SCHDL_bInitialized)
    {
    #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)

        // Initialization HW module which used for scheduler and interrupt
        SCHDL_InitHW();

        // Cleaning of bit maps
        for(nNumWord = 0; nNumWord < SCHDL_TASK_COUNT; nNumWord++)
        {
            SCHDL_nTaskQuery[nNumWord]     = OFF;
            SCHDL_nTaskRunning[nNumWord]   = OFF;
        }

        // Counters reset
        SCHDL_nRunningTaskCounter = 0;
        SCHDL_nIdleCounter = 0;

    #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
        SCHDL_bInitialized = TRUE;
    }
    else
    {
        ET_ReportDevelopmentError(SCHDL_moduleID,
                                  SIZE_OF_ARRAY(SCHDL_moduleID) - 1U,
                                  0U,
                                  SCHDL_API_ID_INIT,
                                  DEV_ERROR_ALREADY_INIT);
    }
    #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)

} // End of function: SCHDL_Init()



//**************************************************************************************************
//! Deinitializes SW and HW resources for task scheduler.
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
void SCHDL_DeInit(void)
{
    // For clear bit maps
    U8 nNumWord = 0;

    #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
    // Checking whether initialization is done or not
    if (TRUE == SCHDL_bInitialized)
    {
    #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)

        // Disable module which used for scheduler
        SCHDL_DeInitHW();

        // Clear bit maps
        for(nNumWord = 0; nNumWord < SCHDL_TASK_COUNT; nNumWord++)
        {
            SCHDL_nTaskQuery[nNumWord]     = OFF;
            SCHDL_nTaskRunning[nNumWord]   = OFF;
        }

        SCHDL_nRunningTaskCounter = 0;

    #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
        SCHDL_bInitialized = FALSE;
    }
    else
    {
        ET_ReportDevelopmentError(SCHDL_moduleID,
                                  SIZE_OF_ARRAY(SCHDL_moduleID) - 1U,
                                  0U,
                                  SCHDL_API_ID_DEINIT,
                                  DEV_ERROR_NOT_INIT);
    }
    #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)

} // End of function: SCHDL_DeInit()



//**************************************************************************************************
//! Enable of task scheduler functionality.
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
void SCHDL_Enable(void)
{
    #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
    // Checking whether initialization is done or not
    if (TRUE == SCHDL_bInitialized)
    {
    #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)

        SCHDL_SchedulEnable();

    #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
    }
    else
    {
        ET_ReportDevelopmentError(SCHDL_moduleID,
                                  SIZE_OF_ARRAY(SCHDL_moduleID) - 1U,
                                  0U,
                                  SCHDL_API_ID_ENABLE,
                                  DEV_ERROR_NOT_INIT);
    }
    #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)

} // End of function: SCHDL_Enable()



//**************************************************************************************************
//! Disable of task scheduler functionality.
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
void SCHDL_Disable(void)
{
    #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
    // Checking whether initialization is done or not
    if (TRUE == SCHDL_bInitialized)
    {
    #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)

        SCHDL_SchedulDisable();

    #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
    }
    else
    {
        ET_ReportDevelopmentError(SCHDL_moduleID,
                                  SIZE_OF_ARRAY(SCHDL_moduleID) - 1U,
                                  0U,
                                  SCHDL_API_ID_DISABLE,
                                  DEV_ERROR_NOT_INIT);
    }
    #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)

} // End of function: SCHDL_Disable()



//**************************************************************************************************
//! Launch the specified level.
//!
//! \note None
//!
//! \param[in] nLevelNumber level number
//!
//! \return SCHDL_FUNC_OK - activate the level succeeded
//!         SCHDL_FUNC_NOT_OK - activate the level NOT succeeded
//**************************************************************************************************
U8 SCHDL_StartLevel(U16 nLevelNumber)
{
    // Function result
    U8 nFuncResult;

    #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
    // Checking whether initialization is done or not
    if (TRUE == SCHDL_bInitialized)
    {
    #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)

        // Check of level number
        if(nLevelNumber <= SCHDL_TASK_COUNT)
        {
            nFuncResult = SCHDL_SetActivateLevel(nLevelNumber);
            // Start of scheduler
            SCHDL_SchedulStart();
        } // End of if(nLevelNumber < SCHDL_TASK_COUNT)
        else
        {
            #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
            ET_ReportDevelopmentError(SCHDL_moduleID,
                                      SIZE_OF_ARRAY(SCHDL_moduleID) - 1U,
                                      0U,
                                      SCHDL_API_ID_ACTIVATELEVEL,
                                      DEV_ERROR_PARAM_0);
            #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
            // Function result is RESULT_NOT_OK
            nFuncResult = SCHDL_FUNC_NOT_OK;
        } // End of else if(nLevelNumber < SCHDL_TASK_COUNT)

    #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
    }
    else
    {
        ET_ReportDevelopmentError(SCHDL_moduleID,
                                  SIZE_OF_ARRAY(SCHDL_moduleID) - 1U,
                                  0U,
                                  SCHDL_API_ID_ACTIVATELEVEL,
                                  DEV_ERROR_NOT_INIT);
    }
    #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)

    return nFuncResult;

} // End of function: SCHDL_StartLevel()



//**************************************************************************************************
//! To activate the level, but do not start.
//!
//! \note None
//!
//! \param[in] nLevelNumber level number
//!
//! \return SCHDL_FUNC_OK - activate the level succeeded
//!         SCHDL_FUNC_NOT_OK - activate the level NOT succeeded
//**************************************************************************************************
U8 SCHDL_ActivateLevel(U16 nLevelNumber)
{
    // Function result
    U8 nFuncResult = SCHDL_FUNC_OK;

    #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
    // Checking whether initialization is done or not
    if (TRUE == SCHDL_bInitialized)
    {
    #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)

        // Check of level number
        if(nLevelNumber <= SCHDL_TASK_COUNT)
        {
            nFuncResult = SCHDL_SetActivateLevel(nLevelNumber);
        } // End of if(nLevelNumber < SCHDL_TASK_COUNT)
        else
        {
            #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
            ET_ReportDevelopmentError(SCHDL_moduleID,
                                      SIZE_OF_ARRAY(SCHDL_moduleID) - 1U,
                                      0U,
                                      SCHDL_API_ID_ACTIVATELEVEL,
                                      DEV_ERROR_PARAM_0);
            #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
            // Function result is RESULT_NOT_OK
            nFuncResult = SCHDL_FUNC_NOT_OK;
        } // End of else if(nLevelNumber < SCHDL_TASK_COUNT)

    #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
    }
    else
    {
        ET_ReportDevelopmentError(SCHDL_moduleID,
                                  SIZE_OF_ARRAY(SCHDL_moduleID) - 1U,
                                  0U,
                                  SCHDL_API_ID_ACTIVATELEVEL,
                                  DEV_ERROR_NOT_INIT);
    }
    #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)

    return nFuncResult;

} // End of function: SCHDL_ActivateLevel()



//**************************************************************************************************
//! Start the scheduler.
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
void SCHDL_StartSchedule(void)
{
    #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
    // Checking whether initialization is done or not
    if (TRUE == SCHDL_bInitialized)
    {
    #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)

        // Start of scheduler
        SCHDL_SchedulStart();

    #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
    }
    else
    {
        ET_ReportDevelopmentError(SCHDL_moduleID,
                                  SIZE_OF_ARRAY(SCHDL_moduleID) - 1U,
                                  0U,
                                  SCHDL_API_ID_STARTSCHEDULE,
                                  DEV_ERROR_NOT_INIT);
    }
    #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)

} // End of function: SCHDL_StartSchedule()



//**************************************************************************************************
//! Level Start Immediately.
//!
//! \note None
//!
//! \param[in] nLevelNumber level number
//!
//! \return None
//**************************************************************************************************
void SCHDL_RunLevelImmed(U16 nLevelNumber)
{
    #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
    // Checking whether initialization is done or not
    if (TRUE == SCHDL_bInitialized)
    {
    #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)

        // Level run
        TaskTable[nLevelNumber]();

    #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
    }
    else
    {
        ET_ReportDevelopmentError(SCHDL_moduleID,
                                  SIZE_OF_ARRAY(SCHDL_moduleID) - 1U,
                                  0U,
                                  SCHDL_API_ID_RUNLEVELIMMED,
                                  DEV_ERROR_NOT_INIT);
    }
    #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)

} // End of function: SCHDL_RunLevelImmed()



//**************************************************************************************************
//! Increment of idle counter.
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
void SCHDL_IncIdleCounter(void)
{
    #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
    // Checking whether initialization is done or not
    if (TRUE == SCHDL_bInitialized)
    {
    #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)

        // Check reset request flag
        if(FALSE == SCHDL_bResetIdleCounterRequest)
        {
            // Incrementing of idle counter
            SCHDL_nIdleCounter++;
        }
        else
        {
            // Clear of idle counter
            SCHDL_nIdleCounter = 1U;
            // Clear flag of reset request
            SCHDL_bResetIdleCounterRequest = FALSE;
        }


    #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
    }
    else
    {
        ET_ReportDevelopmentError(SCHDL_moduleID,
                                  SIZE_OF_ARRAY(SCHDL_moduleID) - 1U,
                                  0U,
                                  SCHDL_API_ID_INCIDLECOUNTER,
                                  DEV_ERROR_NOT_INIT);
    }
    #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)

} // End of SCHDL_IncIdleCounter()



//**************************************************************************************************
//! Returns idle counter value.
//!
//! \note None
//!
//! \param None
//!
//! \return U32 - idle counter value
//**************************************************************************************************
U32 SCHDL_GetIdleCounter(void)
{
    #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
    // Checking whether initialization is done or not
    if (FALSE == SCHDL_bInitialized)
    {
        ET_ReportDevelopmentError(SCHDL_moduleID,
                                  SIZE_OF_ARRAY(SCHDL_moduleID) - 1U,
                                  0U,
                                  SCHDL_API_ID_GETIDLECOUNTER,
                                  DEV_ERROR_NOT_INIT);
    }
    #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)

    return SCHDL_nIdleCounter;
} // End of SCHDL_GetIdleCounter()



//**************************************************************************************************
//! Returns idle counter value and reset it.
//!
//! \note Reset implemented in SCHDL_IncIdleCounter() because race condition.
//!
//! \param None
//!
//! \return U32 - idle counter value
//**************************************************************************************************
U32 SCHDL_GetAndResetIdleCounter(void)
{
    #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
    // Checking whether initialization is done or not
    if (FALSE == SCHDL_bInitialized)
    {
        ET_ReportDevelopmentError(SCHDL_moduleID,
                                  SIZE_OF_ARRAY(SCHDL_moduleID) - 1U,
                                  0U,
                                  SCHDL_API_ID_GETANDRESETIDLECOUNTER,
                                  DEV_ERROR_NOT_INIT);
    }
    #endif // #if (ON == SCHDL_DEVELOPMENT_ERROR_DETECTION)
    U32 nReturnValue = 0U;
    nReturnValue = SCHDL_nIdleCounter;
    SCHDL_bResetIdleCounterRequest = TRUE;

    return nReturnValue;
}



//**************************************************************************************************
//==================================================================================================
// Definitions of local (private) functions
//==================================================================================================
//**************************************************************************************************

//**************************************************************************************************
//! Level activate in query table.
//!
//! \note None
//!
//! \param[in] nLevelNumber level number
//!
//! \return SCHDL_FUNC_OK - activate the level succeeded
//!         SCHDL_FUNC_NOT_OK - activate the level NOT succeeded
//**************************************************************************************************
static U8 SCHDL_SetActivateLevel(U16 nLevelNumber)
{
    // Function result
    U8 nFuncResult = SCHDL_FUNC_OK;

    // Save of active level number
    SCHDL_nActiveTaskNumber = nLevelNumber;

    if(SCHDL_nTaskQuery[nLevelNumber] != OFF)
    {
        #if(ON == SCHDL_INTERNAL_DIAGNOSTICS)
        // Overflow counter incremented
        SCHDL_nTaskOverrunCounter[nLevelNumber]++;
        #endif // #if(ON == SCHDL_INTERNAL_DIAGNOSTICS)

        // Function result is RESULT_NOT_OK
        nFuncResult = SCHDL_FUNC_NOT_OK;
    } // End of if((SCHDL_nTaskQuery[nIndex] & nBitMask) != 0)
    else
    {
        // Set task request
        SCHDL_nTaskQuery[nLevelNumber] = ON;
        #if(ON == SCHDL_INTERNAL_DIAGNOSTICS)
        // Query counter incremented
        SCHDL_nTaskQueryCounter[nLevelNumber]++;
        #endif // #if(ON == SCHDL_INTERNAL_DIAGNOSTICS)
    } // End of else if((SCHDL_nTaskQuery[nIndex] & nBitMask) != 0)

    return nFuncResult;

} // End of function: SCHDL_SetActivateLevel()



//****************************************** end of file *******************************************
