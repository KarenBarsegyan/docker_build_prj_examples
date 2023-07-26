//**************************************************************************************************
// @Module  SPI driver
//! \file   spi_drv.c
//! \par    Platform
//!             YTM32
//! \par    Compatible
//!             YTM32B1M families
//! \brief  Implementation of the SPI driver functionality
//!
//! \par    Abbreviations
//!             MCU - MicroController Unit
//!             SPI - Serial Peripheral Interface
//! \par    History
//! | Date       | Version | Author  | Comment
//! |:----------:|:-------:|:-------:|--------------------------------------------------------------
//! | 00.00.2023 |  1.0.0  |   BKR   | First release.
//**************************************************************************************************



//**************************************************************************************************
//! \defgroup   SPI_DRV SPI driver
//! \brief      Implements work with SPI interface
//! \addtogroup SPI_DRV
//! @{
//! \file spi_drv.h
//! \file spi_drv.c
//! \file spi_drv_cfg.h.tmpl
//! \file spi_drv_irq.c
//! \file spi_drv_irq.h
//! @}
//**************************************************************************************************



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Get Native header
#include "spi_drv.h"

// Get irq header
#include "spi_drv_irq.h"

// Get config header
#include "spi_drv_cfg.h"

// Get config verification header
#include "spi_drv_cfg_verif.h"

// Get program module specific types
#include "spi_drv_types.h"

// Get MCU driver header
#include "mcu_drv.h"

// Get SFR registers header
#include "ytm32b1m_sfr.h"

// Get generic definitions
#include "general.h"

#if (ON == SPI_DEVELOPMENT_ERROR_DETECTION)
// Get error tracer functions
#include "error_tracer.h"
#endif



//**************************************************************************************************
// Verification of the imported configuration parameters
//**************************************************************************************************

// None.



//**************************************************************************************************
// Definitions of global (public) variables
//**************************************************************************************************

// None.



//**************************************************************************************************
// Declarations of local (private) data types
//**************************************************************************************************

//! \name Program module API IDs
//! @{
typedef enum
{
    SPI_API_ID_INNER_FUNC           = (U8)0U,
    SPI_API_ID_INIT                 = (U8)1U,
    SPI_API_ID_DEINIT               = (U8)2U,
    SPI_API_ID_READ                 = (U8)3U,
    SPI_API_ID_WRITE                = (U8)4U,
    SPI_API_ID_PURGE                = (U8)5U,
    SPI_API_ID_GETRXITEMSCOUNT      = (U8)6U,
    SPI_API_ID_SETMODE              = (U8)7U,
    SPI_API_ID_SETBAUDRATE          = (U8)8U,
    SPI_API_ID_SETTRANSFERFORMAT    = (U8)9U,
    SPI_API_ID_SETCALLBACKFUNCTION  = (U8)10U,
    SPI_API_ID_RX_ISR               = (U8)11U,
    SPI_API_ID_TX_ISR               = (U8)12U,
} SPI_API_ID;
//! @}

 

//**************************************************************************************************
// Definitions of local (private) constants
//**************************************************************************************************

#if (ON == SPI_DEVELOPMENT_ERROR_DETECTION)
//! Program module ID ( = program module prefix)
static const U8 SPI_moduleID[] = "SPI_DRV";
//! Program module ID size
static const U8 SPI_nModuleIDSize = SIZE_OF_ARRAY(SPI_pModuleID) - 1U;

//! Dev error function
#define SPI_REPORT_DEV_ERROR(SPI_nAPIID, nErrorID)         \
    ET_ReportDevelopmentError(SPI_pModuleID,               \
                              SPI_nModuleIDSize,           \
                              0U,                          \
                              SPI_nAPIID,                  \
                              nErrorID);
//! Runtime error function
#define SPI_REPORT_RT_ERROR(SPI_nAPIID, nErrorID)          \
    ET_ReportRuntimeError(SPI_pModuleID,                   \
                          SPI_nModuleIDSize,               \
                          0U,                              \
                          SPI_nAPIID,                      \
                          nErrorID);
#endif



//! \name Is GPIO port used
//! @{
#define SPI_CHANNEL_GPIO_PORT_IN_USE(Channel, Port) ( \
    SPI_##Channel##_IN_USE == ON && (      \
    SPI_##Channel##_MOSI_PORT == Port ||   \
    SPI_##Channel##_MISO_PORT == Port ||   \
    SPI_##Channel##_SCLK_PORT == Port ||   \
    SPI_##Channel##_CS_0_PORT == Port ||   \
    SPI_##Channel##_CS_1_PORT == Port ||   \
    SPI_##Channel##_CS_2_PORT == Port ||   \
    SPI_##Channel##_CS_3_PORT == Port) )

#define SPI_GPIO_PORT_IN_USE(Port) (                     \
    SPI_CHANNEL_GPIO_PORT_IN_USE(CHANNEL_0, Port) || \
    SPI_CHANNEL_GPIO_PORT_IN_USE(CHANNEL_1, Port) || \
    SPI_CHANNEL_GPIO_PORT_IN_USE(CHANNEL_2, Port) || \
    SPI_CHANNEL_GPIO_PORT_IN_USE(CHANNEL_3, Port) || \
    SPI_CHANNEL_GPIO_PORT_IN_USE(CHANNEL_4, Port) || \
    SPI_CHANNEL_GPIO_PORT_IN_USE(CHANNEL_5, Port))
//! @}

//! \name PCR register macro
//! @{
#define SPI_CHANNEL_PCTRL_FILL(Channel)                                     \
{                                                                           \
    PCTRL_pPorts[Channel##_MOSI_PORT]->PCR[Channel##_MOSI_PIN].B.PE  =      \
                                       SPI_CHANNEL_0_MOSI_OUTPUT_MODE;      \
    PCTRL_pPorts[Channel##_MOSI_PORT]->PCR[Channel##_MOSI_PIN].B.MUX =      \
                                       SPI_CHANNEL_0_MOSI_ALT_FUNK;         \
    PCTRL_pPorts[Channel##_MOSI_PORT]->PCR[Channel##_MOSI_PIN].B.PS  =      \
                                       SPI_CHANNEL_0_MOSI_PULLUP_MODE;      \
                                                                            \
    PCTRL_pPorts[Channel##_MISO_PORT]->PCR[Channel##_MISO_PIN].B.PE  =      \
                                       SPI_CHANNEL_0_MISO_OUTPUT_MODE;      \
    PCTRL_pPorts[Channel##_MISO_PORT]->PCR[Channel##_MISO_PIN].B.MUX =      \
                                       SPI_CHANNEL_0_MISO_ALT_FUNK;         \
    PCTRL_pPorts[Channel##_MISO_PORT]->PCR[Channel##_MISO_PIN].B.PS  =      \
                                       SPI_CHANNEL_0_MISO_PULLUP_MODE;      \
                                                                            \
    PCTRL_pPorts[Channel##_SCLK_PORT]->PCR[Channel##_SCLK_PIN].B.PE  =      \
                                       SPI_CHANNEL_0_SCLK_OUTPUT_MODE;      \
    PCTRL_pPorts[Channel##_SCLK_PORT]->PCR[Channel##_SCLK_PIN].B.MUX =      \
                                       SPI_CHANNEL_0_SCLK_ALT_FUNK;         \
    PCTRL_pPorts[Channel##_SCLK_PORT]->PCR[Channel##_SCLK_PIN].B.PS  =      \
                                       SPI_CHANNEL_0_SCLK_PULLUP_MODE;      \
                                                                            \
    if (ON == SPI_CHANNEL_0_CS_0_IN_USE)                                    \
    {                                                                       \
        PCTRL_pPorts[Channel##_CS_0_PORT]->PCR[Channel##_CS_0_PIN].B.PE  =  \
                                           SPI_CHANNEL_0_CS_0_OUTPUT_MODE;  \
        PCTRL_pPorts[Channel##_CS_0_PORT]->PCR[Channel##_CS_0_PIN].B.MUX =  \
                                           SPI_CHANNEL_0_CS_0_ALT_FUNK;     \
        PCTRL_pPorts[Channel##_CS_0_PORT]->PCR[Channel##_CS_0_PIN].B.PS  =  \
                                           SPI_CHANNEL_0_CS_0_PULLUP_MODE;  \
                                                                            \
    }                                                                       \
                                                                            \
    if (ON == SPI_CHANNEL_0_CS_1_IN_USE)                                    \
    {                                                                       \
        PCTRL_pPorts[Channel##_CS_1_PORT]->PCR[Channel##_CS_1_PIN].B.PE  =  \
                                           SPI_CHANNEL_0_CS_1_OUTPUT_MODE;  \
        PCTRL_pPorts[Channel##_CS_1_PORT]->PCR[Channel##_CS_1_PIN].B.MUX =  \
                                           SPI_CHANNEL_0_CS_1_ALT_FUNK;     \
        PCTRL_pPorts[Channel##_CS_1_PORT]->PCR[Channel##_CS_1_PIN].B.PS  =  \
                                           SPI_CHANNEL_0_CS_1_PULLUP_MODE;  \
    }                                                                       \
                                                                            \
    if (ON == SPI_CHANNEL_0_CS_2_IN_USE)                                    \
    {                                                                       \
        PCTRL_pPorts[Channel##_CS_2_PORT]->PCR[Channel##_CS_2_PIN].B.PE  =  \
                                           SPI_CHANNEL_0_CS_2_OUTPUT_MODE;  \
        PCTRL_pPorts[Channel##_CS_2_PORT]->PCR[Channel##_CS_2_PIN].B.MUX =  \
                                           SPI_CHANNEL_0_CS_2_ALT_FUNK;     \
        PCTRL_pPorts[Channel##_CS_2_PORT]->PCR[Channel##_CS_2_PIN].B.PS  =  \
                                           SPI_CHANNEL_0_CS_2_PULLUP_MODE;  \
    }                                                                       \
}
//! @}

//! \name Take clock on special port ON
//! @{ 
#define SPI_GPIO_PORT_TAKE_ON_CLK(Port) \
    if (ON != IPC.CTRL[IPC_PCTRL##Port##_INDEX].B.CLKEN) \
    {                                             \
        IPC.CTRL[IPC_PCTRL##Port##_INDEX].B.CLKEN = ON;  \
    }                                             \
//! @}   


//**************************************************************************************************
// Definitions of static global (private) variables
//**************************************************************************************************

//! Initialization flag
static BOOLEAN SPI_bInitialized;

//! Port control registers array
static PCTRL_tag* PCTRL_pPorts[SPI_PORT_MAX + 1U] =
{
    &PCTRLA,
    &PCTRLB,
    &PCTRLC,
    &PCTRLD,
    &PCTRLE,
};

//**************************************************************************************************
// Declarations of local (private) functions
//**************************************************************************************************

// None.



//**************************************************************************************************
//==================================================================================================
// Definitions of global (public) functions
//==================================================================================================
//**************************************************************************************************



//**************************************************************************************************
//! Initializes SW and HW SPI driver resources
//!
//! \note None
//!
//! \param None
//!
//! \return RESULT_OK     - initialization is completed successfully
//! \return RESULT_NOT_OK - initialization is not completed
//**************************************************************************************************
STD_RESULT SPI_Init(void)
{
    STD_RESULT nFuncResult = RESULT_NOT_OK;

    #if (ON == SPI_DEVELOPMENT_ERROR_DETECTION)
    if (TRUE == SPI_bInitialized)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_INIT, DEV_ERROR_ALREADY_INIT);
    }
    else
    #endif
    {
        // GPIO clock enable
        #if (TRUE == SPI_GPIO_PORT_IN_USE(SPI_PORT_A) )
            SPI_GPIO_PORT_TAKE_ON_CLK(A)
        #endif

        #if (TRUE == SPI_GPIO_PORT_IN_USE(SPI_PORT_B) )
            SPI_GPIO_PORT_TAKE_ON_CLK(B)
        #endif

        #if (TRUE == SPI_GPIO_PORT_IN_USE(SPI_PORT_C) )
            SPI_GPIO_PORT_TAKE_ON_CLK(C)
        #endif

        #if (TRUE == SPI_GPIO_PORT_IN_USE(SPI_PORT_D) )
            SPI_GPIO_PORT_TAKE_ON_CLK(D)
        #endif

        #if (TRUE == SPI_GPIO_PORT_IN_USE(SPI_PORT_E) )
            SPI_GPIO_PORT_TAKE_ON_CLK(E)
        #endif
        
        // Setup GPIO MUX and pull
        #if (ON == SPI_CHANNEL_0_IN_USE)
            SPI_CHANNEL_PCTRL_FILL(SPI_CHANNEL_0);
        #endif

        #if (ON == SPI_CHANNEL_1_IN_USE)
            SPI_CHANNEL_PCTRL_FILL(SPI_CHANNEL_1);
        #endif

        #if (ON == SPI_CHANNEL_2_IN_USE)
            SPI_CHANNEL_PCTRL_FILL(SPI_CHANNEL_2);
        #endif

        #if (ON == SPI_CHANNEL_3_IN_USE)
            SPI_CHANNEL_PCTRL_FILL(SPI_CHANNEL_3);
        #endif

        #if (ON == SPI_CHANNEL_4_IN_USE)
            SPI_CHANNEL_PCTRL_FILL(SPI_CHANNEL_4);
        #endif

        #if (ON == SPI_CHANNEL_5_IN_USE)
            SPI_CHANNEL_PCTRL_FILL(SPI_CHANNEL_5);
        #endif
        

        if (OFF == IPC.CTRL[IPC_SPI0_INDEX].B.CLKEN)
        {
            U32 nBusFrequency = MCU_GetBusFrequency(MCU_CLOCK_SOURCE_BUS3); // SLOW BUS clock
            
            IPC.CTRL[IPC_SPI0_INDEX].B.DIV = 0b1001;
            IPC.CTRL[IPC_SPI0_INDEX].B.SRCSEL = 0b101; 
            IPC.CTRL[IPC_SPI0_INDEX].B.CLKEN = ON;
        }


        SPI0.TXCFG.B.PRESCALE = 0b000;

        SPI0.CLK.B.DIV = 0b00U;

        SPI0.CTRL.B.MODE = ON;
        SPI0.CTRL.B.EN = ON;

        while(ON != SPI0.CTRL.B.EN){}

        SPI_bInitialized = TRUE;
    }

    return nFuncResult;
} // end of SPI_Init()



//**************************************************************************************************
//! Deinitializes SW and HW SPI driver resources
//!
//! \note None
//!
//! \param None
//!
//! \return RESULT_OK     - deinitialization is completed successfully
//! \return RESULT_NOT_OK - deinitialization is not completed
//**************************************************************************************************
STD_RESULT SPI_DeInit(void)
{
    STD_RESULT nFuncResult = RESULT_NOT_OK;
    
    // TODO

    return nFuncResult;
} // end of SPI_DeInit()



//**************************************************************************************************
//! Reads data from from the specified SPI module
//!
//! \note None
//!
//! \param[in] nChannelNum   - SPI channel number
//! \param[in] pDataBuffer   - pointer to destination buffer
//! \param[in] nDataFrameQty - quantity of the read data frames
//!
//! \return RESULT_OK     - reading data is completed successfully
//! \return RESULT_NOT_OK - reading data is ended with an error
//**************************************************************************************************
STD_RESULT SPI_Read(const U8    nChannelNum,
                    void* const pDataBuffer,
                    const U8    nDataFrameQty)
{
    STD_RESULT nFuncResult = RESULT_NOT_OK;
    
    // TODO

    return nFuncResult;
} // end of SPI_Read()



//**************************************************************************************************
//! Writes data into the specified SPI module
//!
//! \note None
//!
//! \param[in] nChannelNum   - SPI channel number
//! \param[in] pDataBuffer   - pointer to source buffer
//! \param[in] nDataFrameQty - quantity of the write data frames
//!
//! \return RESULT_OK     - writing data is completed successfully
//! \return RESULT_NOT_OK - writing data is ended with an error
//**************************************************************************************************
STD_RESULT SPI_Write(const U8          nChannelNum,
                     const void* const pDataBuffer,
                     const U8          nDataFrameQty)
{
    STD_RESULT nFuncResult = RESULT_NOT_OK;
    
    if (OFF == SPI0.STS.B.BUSY)
    {
        SPI0.DATA.B.DATA = (U32) 0x6789ABCDU;
        SPI0.DATA.B.DATA;
    }

    return nFuncResult;
} // end of SPI_Write()



//**************************************************************************************************
//! Purges RX and/or TX FIFO data in specified SPI module
//!
//! \note None
//!
//! \param[in] nChannelNum   - SPI channel number
//! \param[in] bPurgeRX      - purge RX request
//! \param[in] bPurgeTX      - purge TX request
//!
//! \return RESULT_OK     - purging FIFO is completed successfully
//! \return RESULT_NOT_OK - purging FIFO is ended with an error
//**************************************************************************************************
STD_RESULT SPI_Purge(const U8      nChannelNum,
                     const BOOLEAN bPurgeRX,
                     const BOOLEAN bPurgeTX)
{
    STD_RESULT nFuncResult = RESULT_NOT_OK;
    
    // TODO

    return nFuncResult;
} // end of SPI_Purge()



//**************************************************************************************************
//! Returns RX FIFO queue length in bytes of the specified module number
//!
//! \note None
//!
//! \param[in] nChannelNum   - SPI channel number
//! \param[out] pBytesCount  - pointer to variable that store the number of RX data frames
//!
//! \return RESULT_OK     - function is completed successfully
//! \return RESULT_NOT_OK - function is ended with an error
//**************************************************************************************************
STD_RESULT SPI_GetRXItemsCount(const U8    nChannelNum,
                               U16*  const pBytesCount)
{
    STD_RESULT nFuncResult = RESULT_NOT_OK;
    
    // TODO

    return nFuncResult;
} // end of SPI_GetRXItemsCount()



//**************************************************************************************************
//! Sets baudrate on the specified SPI module
//!
//! \note None
//!
//! \param[in] nChannelNum   - SPI channel number
//! \param[in] nBaudrate     - transmission speed
//!
//! \return RESULT_OK     - function is completed successfully
//! \return RESULT_NOT_OK - function is ended with an error
//**************************************************************************************************
STD_RESULT SPI_SetBaudrate(const U8  nChannelNum,
                           const U32 nBaudrate)
{
    STD_RESULT nFuncResult = RESULT_NOT_OK;
    
    // TODO

    return nFuncResult;
} // end of SPI_SetBaudrate()



//**************************************************************************************************
//! Sets clock polarity and clock phase on the specified SPI module
//!
//! \note None
//!
//! \param[in] nChannelNum          - SPI channel number
//! \param[in] bActiveClockPolarity - clock line default state
//! \param[in] bClockPhase          - active edge of the clock line
//! \param[in] bBitOrder            - bit order
//! \param[in] nDataFrameSize       - data frame size
//! \param[in] nCSNum               - logical CS number
//!
//! \return RESULT_OK     - function is completed successfully
//! \return RESULT_NOT_OK - function is ended with an error
//**************************************************************************************************
STD_RESULT SPI_SetTransferFormat(const U8      nChannelNum,
                                 const BOOLEAN bActiveClockPolarity,
                                 const BOOLEAN bClockPhase,
                                 const BOOLEAN bBitOrder,
                                 const U8      nDataFrameSize,
                                 const U8      nCSNum)
{
    STD_RESULT nFuncResult = RESULT_NOT_OK;
    
    // TODO

    return nFuncResult;
} // end of SPI_SetTransferFormat()



//**************************************************************************************************
//! Sets callback function pointer for the SPI driver
//!
//! \note None
//!
//! \param[in] nChannelNum       - SPI channel number
//! \param[in] pCallbackFunction - callback function pointer
//!
//! \return RESULT_OK     - function is completed successfully
//! \return RESULT_NOT_OK - function is ended with an error
//**************************************************************************************************
STD_RESULT SPI_SetCallbackFunction(const U8           nChannelNum,
                                   const SPI_CALLBACK pCallbackFunction)
{
    STD_RESULT nFuncResult = RESULT_NOT_OK;
    
    // TODO

    return nFuncResult;
} // end of SPI_SetCallbackFunction()



//**************************************************************************************************
//! RX high-level interrupt service routine for all of the SPI modules
//!
//! \note None
//!
//! \param[in] nChannelNum - SPI channel number
//!
//! \return None
//**************************************************************************************************
void SPI_HighLevel_RX_ISR(const U8 nChannelNum)
{
    // TODO
} // end of SPI_HighLevel_RX_ISR()



//**************************************************************************************************
//! TX high-level interrupt service routine for all of the SPI modules
//!
//! \note None
//!
//! \param[in] nChannelNum - SPI channel number
//!
//! \return None
//**************************************************************************************************
void SPI_HighLevel_TX_ISR(const U8 nChannelNum)
{
    // TODO
} // en of SPI_HighLevel_TX_ISR()



//**************************************************************************************************
//==================================================================================================
// Definitions of local (private) functions
//==================================================================================================
//**************************************************************************************************

// None.



//****************************************** end of file *******************************************