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
//! \file spi_drv_types.h
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
#else
#define SPI_REPORT_DEV_ERROR(SPI_nAPIID, nErrorID)         
#define SPI_REPORT_RT_ERROR(SPI_nAPIID, nErrorID)          
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
                                       Channel##_MOSI_OUTPUT_MODE;          \
    PCTRL_pPorts[Channel##_MOSI_PORT]->PCR[Channel##_MOSI_PIN].B.MUX =      \
                                       Channel##_MOSI_ALT_FUNK;             \
    PCTRL_pPorts[Channel##_MOSI_PORT]->PCR[Channel##_MOSI_PIN].B.PS  =      \
                                       Channel##_MOSI_PULLUP_MODE;          \
                                                                            \
    PCTRL_pPorts[Channel##_MISO_PORT]->PCR[Channel##_MISO_PIN].B.PE  =      \
                                       Channel##_MISO_OUTPUT_MODE;          \
    PCTRL_pPorts[Channel##_MISO_PORT]->PCR[Channel##_MISO_PIN].B.MUX =      \
                                       Channel##_MISO_ALT_FUNK;             \
    PCTRL_pPorts[Channel##_MISO_PORT]->PCR[Channel##_MISO_PIN].B.PS  =      \
                                       Channel##_MISO_PULLUP_MODE;          \
                                                                            \
    PCTRL_pPorts[Channel##_SCLK_PORT]->PCR[Channel##_SCLK_PIN].B.PE  =      \
                                       Channel##_SCLK_OUTPUT_MODE;          \
    PCTRL_pPorts[Channel##_SCLK_PORT]->PCR[Channel##_SCLK_PIN].B.MUX =      \
                                       Channel##_SCLK_ALT_FUNK;             \
    PCTRL_pPorts[Channel##_SCLK_PORT]->PCR[Channel##_SCLK_PIN].B.PS  =      \
                                       Channel##_SCLK_PULLUP_MODE;          \
                                                                            \
    if (ON == Channel##_CS_0_IN_USE)                                        \
    {                                                                       \
        PCTRL_pPorts[Channel##_CS_0_PORT]->PCR[Channel##_CS_0_PIN].B.PE  =  \
                                           Channel##_CS_0_OUTPUT_MODE;      \
        PCTRL_pPorts[Channel##_CS_0_PORT]->PCR[Channel##_CS_0_PIN].B.MUX =  \
                                           Channel##_CS_0_ALT_FUNK;         \
        PCTRL_pPorts[Channel##_CS_0_PORT]->PCR[Channel##_CS_0_PIN].B.PS  =  \
                                           Channel##_CS_0_PULLUP_MODE;      \
                                                                            \
    }                                                                       \
                                                                            \
    if (ON == Channel##_CS_1_IN_USE)                                        \
    {                                                                       \
        PCTRL_pPorts[Channel##_CS_1_PORT]->PCR[Channel##_CS_1_PIN].B.PE  =  \
                                           Channel##_CS_1_OUTPUT_MODE;      \
        PCTRL_pPorts[Channel##_CS_1_PORT]->PCR[Channel##_CS_1_PIN].B.MUX =  \
                                           Channel##_CS_1_ALT_FUNK;         \
        PCTRL_pPorts[Channel##_CS_1_PORT]->PCR[Channel##_CS_1_PIN].B.PS  =  \
                                           Channel##_CS_1_PULLUP_MODE;      \
    }                                                                       \
                                                                            \
    if (ON == Channel##_CS_2_IN_USE)                                        \
    {                                                                       \
        PCTRL_pPorts[Channel##_CS_2_PORT]->PCR[Channel##_CS_2_PIN].B.PE  =  \
                                           Channel##_CS_2_OUTPUT_MODE;      \
        PCTRL_pPorts[Channel##_CS_2_PORT]->PCR[Channel##_CS_2_PIN].B.MUX =  \
                                           Channel##_CS_2_ALT_FUNK;         \
        PCTRL_pPorts[Channel##_CS_2_PORT]->PCR[Channel##_CS_2_PIN].B.PS  =  \
                                           Channel##_CS_2_PULLUP_MODE;      \
    }                                                                       \
}
//! @}

//! \name Take clock on special port ON
//! @{ 
#define SPI_GPIO_PORT_TAKE_ON_CLK(Port) \
    if (ON != IPC.CTRL[Port##_INDEX].B.CLKEN) \
    {                                             \
        IPC.CTRL[Port##_INDEX].B.CLKEN = ON;  \
    }                                             \
//! @}   

//! \name Set up SPI channel settings
//! @{ 
#define SPI_CHANNEL_SET_CLK(Channel)                                  \
{                                                                     \
    IPC.CTRL[IPC_SPI##Channel##_INDEX].B.DIV = IPC_CTRL_DIV_5;        \
    IPC.CTRL[IPC_SPI##Channel##_INDEX].B.SRCSEL = IPC_SRCSEL_PLL;     \
    if (OFF == IPC.CTRL[IPC_SPI##Channel##_INDEX].B.CLKEN)            \
    {                                                                 \
        IPC.CTRL[IPC_SPI##Channel##_INDEX].B.CLKEN = ON;              \
    }                                                                 \
    U32 nDivider = (MCU_GetBusFrequency(MCU_CLOCK_SOURCE_BUS0) / 2) / \
                    (IPC_CTRL_DIV_5 + 1U)    /                        \
                    TXCFG_DIV_VALUE_2        /                        \
                    SPI_stDynamicParams[Channel].nBaudRate;           \
                                                                      \
    U8 nTXCFG_Prescaller = TXCFG_DIV_2;                               \
                                                                      \
    if (nDivider > 128U)                                              \
    {                                                                 \
        nDivider = nDivider/8;                                        \
        nTXCFG_Prescaller = TXCFG_DIV_16;                             \
    }                                                                 \
    if (nDivider > 128U)                                              \
    {                                                                 \
        nDivider = nDivider/8;                                        \
        nTXCFG_Prescaller = TXCFG_DIV_128;                            \
    }                                                                 \
                                                                      \
    SPI##Channel.TXCFG.B.PRESCALE = nTXCFG_Prescaller;                \
    SPI##Channel.CLK.B.DIV = (U8)(nDivider*2U-2U);                    \
}

#define SPI_CHANNEL_SET_CFG(Channel)                                  \
{                                                                     \
    SPI_CHANNEL_SET_CLK(Channel)                                      \
    SPI##Channel.CTRL.B.MODE = !SPI_CHANNEL_##Channel##_MODE;         \
    SPI##Channel.CTRL.B.EN = ON;                                      \
    while(ON != SPI##Channel.CTRL.B.EN){}                             \
}
//! @}

//! \name Set SPI channel Baudrate
//! @{ 
#define SET_SPI_CHANNEL_BAUDRATE(Channel)                       \
    if (nBaudrate <= SPI_MAX_BAUDRATE &&                        \
        nBaudrate >= SPI_MIN_BAUDRATE)                          \
    {                                                           \
        SPI_stDynamicParams[Channel].nBaudRate = nBaudrate;     \
        while(ON == SPI##Channel.STS.B.BUSY){}                  \
        SPI_CHANNEL_SET_CLK(Channel);                           \
    }
    
//! @}

//! \name Enable IRQs
//! @{ 
#define SPI_CHANNEL_SET_IRQ(Channel)  \
{                                     \
    SPI##Channel.INTE.B.RXIE = OFF;   \
    SPI##Channel.INTE.B.TCIE = ON;    \
}
//! @}
                                     

//! \name Disable IRQs
//! @{ 
#define SPI_CHANNEL_DISABLE_IRQ(Channel)  \
{                                         \
    SPI##Channel.INTE.B.RXIE = OFF;       \
}
//! @}

//! \name Disable channel
//! @{ 
#define SPI_CHANNEL_DISABLE(Channel)                                  \
{                                                                     \
    SPI##Channel.CTRL.B.EN = OFF;                                     \
    while(OFF != SPI##Channel.CTRL.B.EN){}                            \
}
//! @}

//! \name Disable channel
//! @{ 
#define SPI_CH_NOT_ENABLED(Channel) \
    !((SPI_CHANNEL_0 == Channel &&    \
       ON == SPI_CHANNEL_0_IN_USE) || \
      (SPI_CHANNEL_1 == Channel &&    \
       ON == SPI_CHANNEL_1_IN_USE) || \
      (SPI_CHANNEL_2 == Channel &&    \
       ON == SPI_CHANNEL_2_IN_USE) || \
      (SPI_CHANNEL_3 == Channel &&    \
       ON == SPI_CHANNEL_3_IN_USE) || \
      (SPI_CHANNEL_4 == Channel &&    \
       ON == SPI_CHANNEL_4_IN_USE) || \
      (SPI_CHANNEL_5 == Channel &&    \
       ON == SPI_CHANNEL_5_IN_USE))

//! @}


//**************************************************************************************************
// Definitions of static global (private) variables
//**************************************************************************************************

//! Initialization flag
static BOOLEAN SPI_bInitialized;

//! Port control registers array
static PCTRL_tag* PCTRL_pPorts[SPI_PORT_QTY] =
{
    &PCTRLA,
    &PCTRLB,
    &PCTRLC,
    &PCTRLD,
    &PCTRLE,
};

//! Port control registers array
static SPI_tag* SPI_pChannels[SPI_CHANNEL_QNT] =
{
    &SPI0,
    &SPI1,
    &SPI2,
    &SPI3,
    &SPI4,
    &SPI5
};

//! Data buffers for Circ Buf module
stCIRCBUF stCircBufferRX [SPI_CHANNEL_QNT];
U32       pCitcBuffDataRX[SPI_CHANNEL_RX_FIFO_SIZE];
stCIRCBUF stCircBufferTX [SPI_CHANNEL_QNT];
U32       pCitcBuffDataTX[SPI_CHANNEL_TX_FIFO_SIZE];

struct stSPIParams 
{
    BOOLEAN bActiveClockPolarity;
    BOOLEAN bClockPhase;
    BOOLEAN bBitOrder;
    U8      nDataFrameSize;
    U8      nCSNum;
    U32     nBaudRate;

} SPI_stDynamicParams[SPI_CHANNEL_QNT];

SPI_CALLBACK SPI_CallBacks[SPI_CHANNEL_QNT];

//**************************************************************************************************
// Declarations of local (private) functions
//**************************************************************************************************

static void SPI_Init_SW(void);
static void SPI_Init_HW(void);
static BOOLEAN SPI_StartTransfer(const U8 nChannelNum);


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

    if (TRUE == SPI_bInitialized)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_INIT, DEV_ERROR_ALREADY_INIT);
    }
    else
    {
        SPI_Init_SW();
        SPI_Init_HW();

        SPI_bInitialized = TRUE;
        nFuncResult = RESULT_OK;
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
    
    if (FALSE == SPI_bInitialized)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_DEINIT, DEV_ERROR_NOT_INIT);
    }
    else
    {
        // If channel X is used, deinit IRQ 
        // And take off enable bit
        #if (ON == SPI_CHANNEL_0_IN_USE)
            SPI_CHANNEL_DISABLE_IRQ(0)
            SPI_CHANNEL_DISABLE(0)
        #endif

        #if (ON == SPI_CHANNEL_1_IN_USE)
            SPI_CHANNEL_DISABLE_IRQ(1)
            SPI_CHANNEL_DISABLE(1)
        #endif

        #if (ON == SPI_CHANNEL_2_IN_USE)
            SPI_CHANNEL_DISABLE_IRQ(2)
            SPI_CHANNEL_DISABLE(2)
        #endif

        #if (ON == SPI_CHANNEL_3_IN_USE)
            SPI_CHANNEL_DISABLE_IRQ(3)
            SPI_CHANNEL_DISABLE(3)
        #endif

        #if (ON == SPI_CHANNEL_4_IN_USE)
            SPI_CHANNEL_DISABLE_IRQ(4)
            SPI_CHANNEL_DISABLE(4)
        #endif

        #if (ON == SPI_CHANNEL_5_IN_USE)
            SPI_CHANNEL_DISABLE_IRQ(5)
            SPI_CHANNEL_DISABLE(5)
        #endif

        nFuncResult = RESULT_OK;

        SPI_bInitialized = FALSE;
    }

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
    
    U32 nLocalData = 0U;
    U8*  pDataBufferU8  = (U8*) pDataBuffer;
    U16* pDataBufferU16 = (U16*)pDataBuffer;
    U32* pDataBufferU32 = (U32*)pDataBuffer;

    if (FALSE == SPI_bInitialized)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_READ, DEV_ERROR_NOT_INIT);
    }
    else if (SPI_CH_NOT_ENABLED(nChannelNum))
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_READ, DEV_ERROR_PARAM_0);
    }
    else if (NULL_PTR == pDataBuffer)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_READ, DEV_ERROR_PARAM_1);
    }
    else if (NULL_PTR == nDataFrameQty)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_READ, DEV_ERROR_PARAM_2);
    }
    else
    {
        if (nDataFrameQty <= CIRCBUF_GetNumberOfItems(&stCircBufferRX[nChannelNum]) &&
            nDataFrameQty > 0U)
        {
            for (U8 nDataCnt = 0U; nDataCnt < nDataFrameQty; nDataCnt++)
            {
                CIRCBUF_GetData((U32*)&nLocalData,
                                &stCircBufferRX[nChannelNum]);
                
                U8 nDataSize = SPI_stDynamicParams[nChannelNum].nDataFrameSize;

                if ((SPI_DATA_SIZE_8 >= nDataSize) && 
                    (0U < nDataSize))
                {
                    pDataBufferU8[nDataCnt] = (U8)nLocalData;
                }
                else if ((SPI_DATA_SIZE_16 >= nDataSize) &&
                         (SPI_DATA_SIZE_8 < nDataSize))
                {
                    pDataBufferU16[nDataCnt] = (U16)nLocalData;
                }
                else if ((SPI_DATA_SIZE_32 >= nDataSize) && 
                         (SPI_DATA_SIZE_16 < nDataSize))
                {
                    pDataBufferU32[nDataCnt] = (U32)nLocalData;
                }
            }
            
            nFuncResult = RESULT_OK;
        }
        else
        {
            // Report runtime error
            SPI_REPORT_RT_ERROR(SPI_API_ID_WRITE, RT_ERROR_RX_OVERRUN);
        }
    }

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

    U32  nLocalData = 0U;
    U8*  pDataBufferU8  = (U8*) pDataBuffer;
    U16* pDataBufferU16 = (U16*)pDataBuffer;
    U32* pDataBufferU32 = (U32*)pDataBuffer;

    if (FALSE == SPI_bInitialized)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_WRITE, DEV_ERROR_NOT_INIT);
    }
    else if (SPI_CH_NOT_ENABLED(nChannelNum))
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_WRITE, DEV_ERROR_PARAM_0);
    }
    else if (NULL_PTR == pDataBuffer)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_WRITE, DEV_ERROR_PARAM_1);
    }
    else if (NULL_PTR == nDataFrameQty)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_WRITE, DEV_ERROR_PARAM_2);
    }
    else
    {
        if (nDataFrameQty <= CIRCBUF_GetFreeSize(&stCircBufferTX[nChannelNum]) && 
            nDataFrameQty > 0U)
        {
            // Put all data in FIFO
            for (U8 nDataCnt = 0U; nDataCnt < nDataFrameQty; nDataCnt++)
            {
                U8 nDataSize = SPI_stDynamicParams[nChannelNum].nDataFrameSize;

                if ((SPI_DATA_SIZE_8 >= nDataSize) && 
                    (0U < nDataSize))
                {
                    nLocalData = (U32)pDataBufferU8[nDataCnt];
                }
                else if ((SPI_DATA_SIZE_16 >= nDataSize) && 
                         (SPI_DATA_SIZE_8 < nDataSize))
                {
                    nLocalData = (U32)pDataBufferU16[nDataCnt];
                }
                else if ((SPI_DATA_SIZE_32 >= nDataSize) &&
                         (SPI_DATA_SIZE_16 < nDataSize))
                {
                    nLocalData = (U32)pDataBufferU32[nDataCnt];
                }

                CIRCBUF_PutData((U32*)&nLocalData,
                                &stCircBufferTX[nChannelNum]);
            }

            if (OFF == SPI_pChannels[nChannelNum]->STS.B.BUSY)
            {
                SPI_StartTransfer(nChannelNum);
            }
            else
            {
                // SPI state is RUN
                DoNothing();
            }

            nFuncResult = RESULT_OK;
        }
        else
        {
            // Report runtime error
            SPI_REPORT_RT_ERROR(SPI_API_ID_WRITE, RT_ERROR_TX_OVERRUN);
        }
    } // else

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
    
    if (FALSE == SPI_bInitialized)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_PURGE, DEV_ERROR_NOT_INIT);
    }
    else if (SPI_CH_NOT_ENABLED(nChannelNum))
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_PURGE, DEV_ERROR_PARAM_0);
    }
    else
    {
        if (TRUE == bPurgeRX)
        {
            CIRCBUF_Purge(&stCircBufferRX[nChannelNum]);
        }
        else
        {
            DoNothing();
        }
        if (TRUE == bPurgeTX)
        {
            CIRCBUF_Purge(&stCircBufferTX[nChannelNum]);
        }
        else
        {
            DoNothing();
        }
        nFuncResult = RESULT_OK;
    }
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
    
    if (SPI_CHANNEL_0 == nChannelNum &&
        ON == SPI_CHANNEL_0_IN_USE)
    {
        SET_SPI_CHANNEL_BAUDRATE(0);
        nFuncResult = RESULT_OK;      
    }
    if (SPI_CHANNEL_1 == nChannelNum &&
        ON == SPI_CHANNEL_1_IN_USE)
    {
        SET_SPI_CHANNEL_BAUDRATE(1);
        nFuncResult = RESULT_OK;      
    }
    if (SPI_CHANNEL_2 == nChannelNum &&
        ON == SPI_CHANNEL_2_IN_USE)
    {
        SET_SPI_CHANNEL_BAUDRATE(2);
        nFuncResult = RESULT_OK;      
    }
    if (SPI_CHANNEL_3 == nChannelNum &&
        ON == SPI_CHANNEL_3_IN_USE)
    {
        SET_SPI_CHANNEL_BAUDRATE(3);
        nFuncResult = RESULT_OK;      
    }
    if (SPI_CHANNEL_4 == nChannelNum &&
        ON == SPI_CHANNEL_4_IN_USE)
    {
        SET_SPI_CHANNEL_BAUDRATE(4);
        nFuncResult = RESULT_OK;      
    }
    if (SPI_CHANNEL_5 == nChannelNum &&
        ON == SPI_CHANNEL_5_IN_USE)
    {
        SET_SPI_CHANNEL_BAUDRATE(5);
        nFuncResult = RESULT_OK;      
    }

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

    SPI_stDynamicParams[nChannelNum].bActiveClockPolarity = bActiveClockPolarity;
    SPI_stDynamicParams[nChannelNum].bClockPhase          = bClockPhase;
    SPI_stDynamicParams[nChannelNum].bBitOrder            = bBitOrder;
    SPI_stDynamicParams[nChannelNum].nDataFrameSize       = nDataFrameSize;
    SPI_stDynamicParams[nChannelNum].nCSNum               = nCSNum;

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
    
    if (FALSE == SPI_bInitialized)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_SETCALLBACKFUNCTION, DEV_ERROR_NOT_INIT);
    }
    else if (SPI_CH_NOT_ENABLED(nChannelNum))
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_SETCALLBACKFUNCTION, DEV_ERROR_PARAM_0);
    }
    else
    {
        if (NULL_PTR != pCallbackFunction)
        {
            SPI_CallBacks[nChannelNum] = pCallbackFunction;

            nFuncResult = RESULT_OK;
        }
        else
        {
            // Report runtime error
            SPI_REPORT_RT_ERROR(SPI_API_ID_SETCALLBACKFUNCTION, RT_ERROR_NULL_PTR);
        }
    }
    return nFuncResult;

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
    U32 nRxData = 0U;

    if (FALSE == SPI_bInitialized)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_RX_ISR, DEV_ERROR_NOT_INIT);
    }
    else if (SPI_CH_NOT_ENABLED(nChannelNum))
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_RX_ISR, DEV_ERROR_PARAM_0);
    }
    else
    {
        nRxData = SPI_pChannels[nChannelNum]->DATA.B.DATA;

        // Put input frame to RX FIFO
        if (CIRCBUF_GetFreeSize(&stCircBufferRX[nChannelNum]) >= 1U)
        {
                CIRCBUF_PutData((U32*)&nRxData,
                                &stCircBufferRX[nChannelNum]);
        }
        else
        {
            // Report RX FIFO overflow.
            SPI_REPORT_RT_ERROR(SPI_API_ID_TX_ISR, RT_ERROR_RX_FIFO_OVERFLOW);
        }

        SPI_pChannels[nChannelNum]->STS.B.FCIF = OFF;
    }
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
    if (FALSE == SPI_bInitialized)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_TX_ISR, DEV_ERROR_NOT_INIT);
    }
    else if (SPI_CH_NOT_ENABLED(nChannelNum))
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_TX_ISR, DEV_ERROR_PARAM_0);
    }
    else
    {
        // Transmit data
        if (FALSE == SPI_StartTransfer(nChannelNum))
        {
            // CALLBACK function execution
            if (NULL_PTR != SPI_CallBacks[nChannelNum])
            {
                SPI_CallBacks[nChannelNum]();
            }
        }
    }
} // en of SPI_HighLevel_TX_ISR()



//**************************************************************************************************
//==================================================================================================
// Definitions of local (private) functions
//==================================================================================================
//**************************************************************************************************

//**************************************************************************************************
//! Initializes bufers and another software modules for SPI
//! \note       None.
//! \param[in]  None.
//! \return     None.
//**************************************************************************************************
static void SPI_Init_SW(void)
{
    for (U8 nChannelNum = 0; nChannelNum < SPI_CHANNEL_QNT; ++nChannelNum)
    {
        stCircBufferRX[nChannelNum].itemSize = sizeof(U32);
        stCircBufferTX[nChannelNum].itemSize = sizeof(U32);

        CIRCBUF_Init(&stCircBufferRX[nChannelNum],
                    pCitcBuffDataRX,
                    SIZE_OF_ARRAY(pCitcBuffDataRX));

        CIRCBUF_Init(&stCircBufferTX[nChannelNum],
                    pCitcBuffDataTX,
                    SIZE_OF_ARRAY(pCitcBuffDataTX));

        CIRCBUF_Purge(&stCircBufferRX[nChannelNum]);
        CIRCBUF_Purge(&stCircBufferTX[nChannelNum]);

        SPI_SetTransferFormat(nChannelNum,              
                              FALSE,                
                              FALSE,                
                              FALSE,                
                              SPI_DATA_SIZE_MAX,    
                              0U); 
    }

} // end of SPI_Init_SW

//**************************************************************************************************
//! Initializes all SPI channels registers
//! \note       None.
//! \param[in]  None.
//! \return     None.
//**************************************************************************************************
static void SPI_Init_HW(void)
{
    // If GPIO clk is not taken on
    if (OFF == IPC.CTRL[IPC_PCTRL_GPIO_INDEX].B.CLKEN)
    {
        // Take on GPIO clk
        IPC.CTRL[IPC_PCTRL_GPIO_INDEX].B.CLKEN = ON;
    }

    // If port X is used, take it's clk on
    #if (TRUE == SPI_GPIO_PORT_IN_USE(SPI_PORT_A) )
        SPI_GPIO_PORT_TAKE_ON_CLK(IPC_PCTRLA)
    #endif

    #if (TRUE == SPI_GPIO_PORT_IN_USE(SPI_PORT_B) )
        SPI_GPIO_PORT_TAKE_ON_CLK(IPC_PCTRLB)
    #endif

    #if (TRUE == SPI_GPIO_PORT_IN_USE(SPI_PORT_C) )
        SPI_GPIO_PORT_TAKE_ON_CLK(IPC_PCTRLC)
    #endif

    #if (TRUE == SPI_GPIO_PORT_IN_USE(SPI_PORT_D) )
        SPI_GPIO_PORT_TAKE_ON_CLK(IPC_PCTRLD)
    #endif

    #if (TRUE == SPI_GPIO_PORT_IN_USE(SPI_PORT_E) )
        SPI_GPIO_PORT_TAKE_ON_CLK(IPC_PCTRLE)
    #endif
    
    // If channel X is used, setup GPIO MUX and 
    // pullup\pulldown for it
    #if (ON == SPI_CHANNEL_0_IN_USE)
        SPI_CHANNEL_PCTRL_FILL(SPI_CHANNEL_0);
        SPI_stDynamicParams[SPI_CHANNEL_0].nBaudRate = SPI_CHANNEL_0_BAUDRATE;
        SPI_CHANNEL_SET_CFG(0)
        SPI_CHANNEL_SET_IRQ(0)
    #endif

    #if (ON == SPI_CHANNEL_1_IN_USE)
        SPI_CHANNEL_PCTRL_FILL(SPI_CHANNEL_1);
        SPI_stDynamicParams[SPI_CHANNEL_1].nBaudRate = SPI_CHANNEL_1_BAUDRATE;
        SPI_CHANNEL_SET_CFG(1)
        SPI_CHANNEL_SET_IRQ(1)
    #endif

    #if (ON == SPI_CHANNEL_2_IN_USE)
        SPI_CHANNEL_PCTRL_FILL(SPI_CHANNEL_2);
        SPI_stDynamicParams[SPI_CHANNEL_2].nBaudRate = SPI_CHANNEL_2_BAUDRATE;
        SPI_CHANNEL_SET_CFG(2)
        SPI_CHANNEL_SET_IRQ(2)
    #endif

    #if (ON == SPI_CHANNEL_3_IN_USE)
        SPI_CHANNEL_PCTRL_FILL(SPI_CHANNEL_3);
        SPI_stDynamicParams[SPI_CHANNEL_3].nBaudRate = SPI_CHANNEL_3_BAUDRATE;
        SPI_CHANNEL_SET_CFG(3)
        SPI_CHANNEL_SET_IRQ(3)
    #endif

    #if (ON == SPI_CHANNEL_4_IN_USE)
        SPI_CHANNEL_PCTRL_FILL(SPI_CHANNEL_4);
        SPI_stDynamicParams[SPI_CHANNEL_4].nBaudRate = SPI_CHANNEL_4_BAUDRATE;
        SPI_CHANNEL_SET_CFG(4)
        SPI_CHANNEL_SET_IRQ(4)
    #endif

    #if (ON == SPI_CHANNEL_5_IN_USE)
        SPI_CHANNEL_PCTRL_FILL(SPI_CHANNEL_5);
        SPI_stDynamicParams[SPI_CHANNEL_5].nBaudRate = SPI_CHANNEL_5_BAUDRATE;
        SPI_CHANNEL_SET_CFG(5)
        SPI_CHANNEL_SET_IRQ(5)
    #endif
} // end of SPI_Init_HW

//**************************************************************************************************
//! Start SPI transfer
//! \note       None.
//! \param[in]  nChannelNum  - SPI channel number
//! \return     TRUE  - Transaction is start successfully
//! \return     FALSE - All transactions is done
//**************************************************************************************************
static BOOLEAN SPI_StartTransfer(const U8 nChannelNum)
{
    BOOLEAN bFuncResult;
    U32 nTxData = 0U;

    // Get number of items in the SPI FIFO
    U8 nTxFifoNumberOfItems = CIRCBUF_GetNumberOfItems(&stCircBufferTX[nChannelNum]);

    if (0U != nTxFifoNumberOfItems)
    {
        // Get TX data from the buffer        
        if (CIRCBUF_NO_ERR == CIRCBUF_GetData(&nTxData, &stCircBufferTX[nChannelNum]))
        {
            // if (OFF == SPI_pChannels[nChannelNum]->STS.B.BUSY)
            {
                SPI_pChannels[nChannelNum]->DATA.B.DATA = nTxData;
                bFuncResult = TRUE;
            }
        }
        else
        {
            // TX Buffer error
            bFuncResult = FALSE;
        }
    }
    else
    {
        // TX Buffer is free
        bFuncResult = FALSE;
    }

    return bFuncResult;
} // end of SPI_StartTransfer()


//****************************************** end of file *******************************************