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
//! | 11.08.2023 |  1.0.0  |   BKR   | First release.
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
//! \file spi_drv_cfg_verif.h
//! @}
//**************************************************************************************************



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Get Native header
#include "spi_drv.h"

// Get irq header
#include "spi_drv_irq.h"

// Get config verification header
#include "spi_drv_cfg_verif.h"

// Get program module specific types
#include "spi_drv_types.h"

// Get MCU driver header
#include "mcu_drv.h"

// Get SFR registers header
#include "derivative_cfg.h"

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
    SPI_API_ID_INNER_FUNC,
    SPI_API_ID_INIT,
    SPI_API_ID_DEINIT,
    SPI_API_ID_READ,
    SPI_API_ID_WRITE,
    SPI_API_ID_PURGE,
    SPI_API_ID_GETRXITEMSCOUNT,
    SPI_API_ID_SETMODE,
    SPI_API_ID_SETBAUDRATE,
    SPI_API_ID_SETTRANSFERFORMAT,
    SPI_API_ID_SETCALLBACKFUNCTION,
    SPI_API_ID_RX_ISR,
    SPI_API_ID_TX_ISR             
} SPI_API_ID;
//! @}

 

//**************************************************************************************************
// Definitions of local (private) constants
//**************************************************************************************************

#if (ON == SPI_DEVELOPMENT_ERROR_DETECTION)
//! Program module ID ( = program module prefix)
static const U8 SPI_moduleID[] = "SPI_DRV";
//! Program module ID size
static const U8 SPI_nModuleIDSize = SIZE_OF_ARRAY(SPI_moduleID) - 1U;

//! Dev error function
#define SPI_REPORT_DEV_ERROR(SPI_nAPIID, nErrorID)         \
    ET_ReportDevelopmentError(SPI_moduleID,                \
                              SPI_nModuleIDSize,           \
                              0U,                          \
                              SPI_nAPIID,                  \
                              nErrorID);
//! Runtime error function
#define SPI_REPORT_RT_ERROR(SPI_nAPIID, nErrorID)          \
    ET_ReportRuntimeError(SPI_moduleID,                    \
                          SPI_nModuleIDSize,               \
                          0U,                              \
                          SPI_nAPIID,                      \
                          nErrorID);
#else
#define SPI_REPORT_DEV_ERROR(SPI_nAPIID, nErrorID)         
#define SPI_REPORT_RT_ERROR(SPI_nAPIID, nErrorID)          
#endif

#if (OFF == SPI_CHANNEL_0_IN_USE && \
     OFF == SPI_CHANNEL_1_IN_USE && \
     OFF == SPI_CHANNEL_2_IN_USE && \
     OFF == SPI_CHANNEL_3_IN_USE && \
     OFF == SPI_CHANNEL_4_IN_USE && \
     OFF == SPI_CHANNEL_5_IN_USE)
    
    #define SPI_NO_ONE_IN_USE
#endif



//! \name Is GPIO port used
//! @{
#define SPI_CHANNEL_GPIO_PORT_IN_USE(Channel, Port) ( \
    SPI_##Channel##_IN_USE == ON && (        \
    SPI_##Channel##_MOSI_PORT == (Port) ||   \
    SPI_##Channel##_MISO_PORT == (Port) ||   \
    SPI_##Channel##_SCLK_PORT == (Port) ||   \
    SPI_##Channel##_CS_0_PORT == (Port) ||   \
    SPI_##Channel##_CS_1_PORT == (Port) ||   \
    SPI_##Channel##_CS_2_PORT == (Port) ||   \
    SPI_##Channel##_CS_3_PORT == (Port)) )

#define SPI_GPIO_PORT_IN_USE(Port) (                 \
    SPI_CHANNEL_GPIO_PORT_IN_USE(CHANNEL_0, Port) || \
    SPI_CHANNEL_GPIO_PORT_IN_USE(CHANNEL_1, Port) || \
    SPI_CHANNEL_GPIO_PORT_IN_USE(CHANNEL_2, Port) || \
    SPI_CHANNEL_GPIO_PORT_IN_USE(CHANNEL_3, Port) || \
    SPI_CHANNEL_GPIO_PORT_IN_USE(CHANNEL_4, Port) || \
    SPI_CHANNEL_GPIO_PORT_IN_USE(CHANNEL_5, Port))
//! @}

//! \name PCR register macro
//! @{
#define SPI_CHANNEL_PCTRL_FILL(Channel)                                         \
{                                                                               \
    SPI_PCTRL_pPorts[Channel##_MOSI_PORT]->PCR[Channel##_MOSI_PIN].B.PE  =      \
                                       Channel##_MOSI_OUTPUT_MODE;              \
    SPI_PCTRL_pPorts[Channel##_MOSI_PORT]->PCR[Channel##_MOSI_PIN].B.MUX =      \
                                       Channel##_MOSI_ALT_FUNC;                 \
    SPI_PCTRL_pPorts[Channel##_MOSI_PORT]->PCR[Channel##_MOSI_PIN].B.PS  =      \
                                       Channel##_MOSI_PULLUP_MODE;              \
                                                                                \
    SPI_PCTRL_pPorts[Channel##_MISO_PORT]->PCR[Channel##_MISO_PIN].B.PE  =      \
                                       Channel##_MISO_OUTPUT_MODE;              \
    SPI_PCTRL_pPorts[Channel##_MISO_PORT]->PCR[Channel##_MISO_PIN].B.MUX =      \
                                       Channel##_MISO_ALT_FUNC;                 \
    SPI_PCTRL_pPorts[Channel##_MISO_PORT]->PCR[Channel##_MISO_PIN].B.PS  =      \
                                       Channel##_MISO_PULLUP_MODE;              \
                                                                                \
    SPI_PCTRL_pPorts[Channel##_SCLK_PORT]->PCR[Channel##_SCLK_PIN].B.PE  =      \
                                       Channel##_SCLK_OUTPUT_MODE;              \
    SPI_PCTRL_pPorts[Channel##_SCLK_PORT]->PCR[Channel##_SCLK_PIN].B.MUX =      \
                                       Channel##_SCLK_ALT_FUNC;                 \
    SPI_PCTRL_pPorts[Channel##_SCLK_PORT]->PCR[Channel##_SCLK_PIN].B.PS  =      \
                                       Channel##_SCLK_PULLUP_MODE;              \
                                                                                \
    if (ON == Channel##_CS_0_IN_USE)                                            \
    {                                                                           \
        SPI_PCTRL_pPorts[Channel##_CS_0_PORT]->PCR[Channel##_CS_0_PIN].B.PE  =  \
                                           Channel##_CS_0_OUTPUT_MODE;          \
        SPI_PCTRL_pPorts[Channel##_CS_0_PORT]->PCR[Channel##_CS_0_PIN].B.MUX =  \
                                           Channel##_CS_0_ALT_FUNC;             \
        SPI_PCTRL_pPorts[Channel##_CS_0_PORT]->PCR[Channel##_CS_0_PIN].B.PS  =  \
                                           Channel##_CS_0_PULLUP_MODE;          \
    }                                                                           \
                                                                                \
    if (ON == Channel##_CS_1_IN_USE)                                            \
    {                                                                           \
        SPI_PCTRL_pPorts[Channel##_CS_1_PORT]->PCR[Channel##_CS_1_PIN].B.PE  =  \
                                           Channel##_CS_1_OUTPUT_MODE;          \
        SPI_PCTRL_pPorts[Channel##_CS_1_PORT]->PCR[Channel##_CS_1_PIN].B.MUX =  \
                                           Channel##_CS_1_ALT_FUNC;             \
        SPI_PCTRL_pPorts[Channel##_CS_1_PORT]->PCR[Channel##_CS_1_PIN].B.PS  =  \
                                           Channel##_CS_1_PULLUP_MODE;          \
    }                                                                           \
                                                                                \
    if (ON == Channel##_CS_2_IN_USE)                                            \
    {                                                                           \
        SPI_PCTRL_pPorts[Channel##_CS_2_PORT]->PCR[Channel##_CS_2_PIN].B.PE  =  \
                                           Channel##_CS_2_OUTPUT_MODE;          \
        SPI_PCTRL_pPorts[Channel##_CS_2_PORT]->PCR[Channel##_CS_2_PIN].B.MUX =  \
                                           Channel##_CS_2_ALT_FUNC;             \
        SPI_PCTRL_pPorts[Channel##_CS_2_PORT]->PCR[Channel##_CS_2_PIN].B.PS  =  \
                                           Channel##_CS_2_PULLUP_MODE;          \
    }                                                                           \
                                                                                \
    if (ON == Channel##_CS_3_IN_USE)                                            \
    {                                                                           \
        SPI_PCTRL_pPorts[Channel##_CS_3_PORT]->PCR[Channel##_CS_3_PIN].B.PE  =  \
                                           Channel##_CS_3_OUTPUT_MODE;          \
        SPI_PCTRL_pPorts[Channel##_CS_3_PORT]->PCR[Channel##_CS_3_PIN].B.MUX =  \
                                           Channel##_CS_3_ALT_FUNC;             \
        SPI_PCTRL_pPorts[Channel##_CS_3_PORT]->PCR[Channel##_CS_3_PIN].B.PS  =  \
                                           Channel##_CS_3_PULLUP_MODE;          \
    }                                                                           \
}
//! @}

//! Divider setup parameters
#define SPI_DIVIDER_OVERFLOW_VALUE (128U)
#define SPI_DIVIDER_COEFF_VALUE    (8U)

//**************************************************************************************************
// Definitions of static global (private) variables
//**************************************************************************************************

//! SPI Initialized Flag
static BOOLEAN SPI_bInitialized;

#ifndef SPI_NO_ONE_IN_USE
//! Port control registers array
static PCTRL_tag* SPI_PCTRL_pPorts[SPI_PORT_QTY] =
{
    &PCTRLA,
    &PCTRLB,
    &PCTRLC,
    &PCTRLD,
    &PCTRLE,
};
#endif

//! Port control registers array
static SPI_tag* SPI_pChannels[SPI_CHANNEL_QTY] =
{
    &SPI0,
    &SPI1,
    &SPI2,
    &SPI3,
    &SPI4,
    &SPI5
};

//! RX circ buffer structure
static stCIRCBUF SPI_stCircBufferRX [SPI_CHANNEL_QTY];
//! RX data buffer for Circ Buf module
static U32       SPI_pCircBuffDataRX[SPI_CHANNEL_QTY][SPI_CHANNEL_RX_FIFO_SIZE];
//! TX circ buffer structure
static stCIRCBUF SPI_stCircBufferTX [SPI_CHANNEL_QTY];
//! TX data buffer for Circ Buf module
static U32       SPI_pCircBuffDataTX[SPI_CHANNEL_QTY][SPI_CHANNEL_TX_FIFO_SIZE];

//! Static and dynamic params of all channels
static SPI_CHANNEL_PARAMS SPI_stChannelsParams[SPI_CHANNEL_QTY];

//! Links to callback functions
static SPI_CALLBACK SPI_callbacks[SPI_CHANNEL_QTY];



//**************************************************************************************************
// Declarations of local (private) functions
//**************************************************************************************************

static void SPI_InitParams(void);
static void SPI_InitSW(void);
static void SPI_InitHW(void);
static void SPI_DeInitSW(void);
static void SPI_DeInitHW(void);
static BOOLEAN SPI_StartTransfer(const U8 nChannelNum);
static void SPI_SetupChannelClk(U8 nChannelNum);
static void SPI_SetupChannelParams(U8 nChannelNum);

#ifndef SPI_NO_ONE_IN_USE
static void SPI_ConfigureChannel(U8 nChannelNum);
static void SPI_TakeOnPortClk(U8 nPortNum);
static void SPI_DisableChannel(U8 nChannelNum);
#endif // end of SPI_NO_ONE_IN_USE 

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
//! \return RESULT_OK     - initialization is completed successfully \n
//!         RESULT_NOT_OK - initialization is not completed
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
        SPI_InitParams();
        SPI_InitSW();
        SPI_InitHW();

        SPI_bInitialized = TRUE;
        nFuncResult = RESULT_OK;
    } 

    return nFuncResult;
} // end of SPI_Init()



//**************************************************************************************************
//! Deinitializes SW and HW SPI driver resources
//!
//! \note None.
//!
//! \param None.
//!
//! \return RESULT_OK     - deinitialization is completed successfully \n
//!         RESULT_NOT_OK - deinitialization is not completed
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
        SPI_DeInitHW();
        SPI_DeInitSW();

        SPI_bInitialized = FALSE;
        nFuncResult = RESULT_OK;
    }

    return nFuncResult;
} // end of SPI_DeInit()



//**************************************************************************************************
//! Reads data from from the specified SPI module (channel)
//!
//! \note None
//!
//! \param[in]  nChannelNum   - SPI channel number
//! \param[out] pDataBuffer   - pointer to destination buffer
//! \param[in]  nDataFrameQty - quantity of the read data frames
//!
//! \return RESULT_OK     - reading data is completed successfully \n
//!         RESULT_NOT_OK - reading data is ended with an error
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
    else if (SPI_CHANNEL_MIN > nChannelNum ||
             SPI_CHANNEL_MAX < nChannelNum ||
             FALSE == SPI_stChannelsParams[nChannelNum].bChannelEnabled)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_READ, DEV_ERROR_PARAM_0);
    }
    else if (NULL_PTR == pDataBuffer)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_READ, DEV_ERROR_PARAM_1);
    }
    else if (0U                       > nDataFrameQty ||
             SPI_CHANNEL_RX_FIFO_SIZE < nDataFrameQty)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_READ, DEV_ERROR_PARAM_2);
    }
    else
    {
        if (nDataFrameQty <= CIRCBUF_GetNumberOfItems(&SPI_stCircBufferRX[nChannelNum]) &&
            nDataFrameQty > 0U)
        {
            for (U8 nDataCnt = 0U; nDataCnt < nDataFrameQty; nDataCnt++)
            {
                CIRCBUF_GetData((U32*)&nLocalData,
                                &SPI_stCircBufferRX[nChannelNum]);
                
                U8 nDataSize = SPI_stChannelsParams[nChannelNum].nDataFrameSize;

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
//! Writes data into the specified SPI module (channel)
//!
//! \note None
//!
//! \param[in] nChannelNum   - SPI channel number
//! \param[in] pDataBuffer   - pointer to source buffer
//! \param[in] nDataFrameQty - quantity of the write data frames
//!
//! \return RESULT_OK     - writing data is completed successfully \n
//!         RESULT_NOT_OK - writing data is ended with an error
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
    else if (SPI_CHANNEL_MIN > nChannelNum ||
             SPI_CHANNEL_MAX < nChannelNum ||
             FALSE == SPI_stChannelsParams[nChannelNum].bChannelEnabled)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_WRITE, DEV_ERROR_PARAM_0);
    }
    else if (NULL_PTR == pDataBuffer)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_WRITE, DEV_ERROR_PARAM_1);
    }
    else if (0U                       > nDataFrameQty ||
             SPI_CHANNEL_TX_FIFO_SIZE < nDataFrameQty)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_WRITE, DEV_ERROR_PARAM_2);
    }
    else
    {
        if (nDataFrameQty <= CIRCBUF_GetFreeSize(&SPI_stCircBufferTX[nChannelNum]) && 
            nDataFrameQty > 0U)
        {
            // Put all data in FIFO
            for (U8 nDataCnt = 0U; nDataCnt < nDataFrameQty; nDataCnt++)
            {
                U8 nDataSize = SPI_stChannelsParams[nChannelNum].nDataFrameSize;

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
                                &SPI_stCircBufferTX[nChannelNum]);
            }

            SPI_StartTransfer(nChannelNum);

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
//! Purges RX and/or TX FIFO data in specified SPI module (channel)
//!
//! \note None
//!
//! \param[in] nChannelNum   - SPI channel number
//! \param[in] bPurgeRX      - purge RX request
//! \param[in] bPurgeTX      - purge TX request
//!
//! \return RESULT_OK     - purging FIFO is completed successfully \n
//!         RESULT_NOT_OK - purging FIFO is ended with an error
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
    else if (SPI_CHANNEL_MIN > nChannelNum ||
             SPI_CHANNEL_MAX < nChannelNum ||
             FALSE == SPI_stChannelsParams[nChannelNum].bChannelEnabled)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_PURGE, DEV_ERROR_PARAM_0);
    }
    else
    {
        if (TRUE == bPurgeRX)
        {
            CIRCBUF_Purge(&SPI_stCircBufferRX[nChannelNum]);
            SPI_pChannels[nChannelNum]->RXFIFO.B.RESET = ON;
        }
        else
        {
            DoNothing();
        }

        if (TRUE == bPurgeTX)
        {
            CIRCBUF_Purge(&SPI_stCircBufferTX[nChannelNum]);
            SPI_pChannels[nChannelNum]->TXFIFO.B.RESET = ON;
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
//! Returns RX FIFO queue length in bytes of the specified module (channel)
//!
//! \note None
//!
//! \param[in]  nChannelNum   - SPI channel number
//! \param[out] pBytesCount  - pointer to variable that store the number of RX data frames
//!
//! \return RESULT_OK     - function is completed successfully \n
//!         RESULT_NOT_OK - function is ended with an error
//**************************************************************************************************
STD_RESULT SPI_GetRXItemsCount(const U8   nChannelNum,
                               U16* const pBytesCount)
{
    STD_RESULT nFuncResult = RESULT_NOT_OK;
    
    if (FALSE == SPI_bInitialized)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_GETRXITEMSCOUNT, DEV_ERROR_NOT_INIT);
    }
    else if (SPI_CHANNEL_MIN > nChannelNum ||
             SPI_CHANNEL_MAX < nChannelNum ||
             FALSE == SPI_stChannelsParams[nChannelNum].bChannelEnabled)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_GETRXITEMSCOUNT, DEV_ERROR_PARAM_0);
    }
    else
    {
        if (NULL_PTR != pBytesCount)
        {
            *pBytesCount =(U16)(CIRCBUF_GetNumberOfItems(&SPI_stCircBufferRX[nChannelNum]));
            
            nFuncResult = RESULT_OK;
        }
        else
        {
            // Report runtime error
            SPI_REPORT_RT_ERROR(SPI_API_ID_GETRXITEMSCOUNT, RT_ERROR_NULL_PTR);
        }
    }

    return nFuncResult;
} // end of SPI_GetRXItemsCount()



//**************************************************************************************************
//! Sets baudrate on the specified SPI module (channel)
//!
//! \note None
//!
//! \param[in] nChannelNum   - SPI channel number
//! \param[in] nBaudrate     - transmission speed
//!
//! \return RESULT_OK     - function is completed successfully \n
//!         RESULT_NOT_OK - function is ended with an error
//**************************************************************************************************
STD_RESULT SPI_SetBaudrate(const U8  nChannelNum,
                           const U32 nBaudrate)
{
    STD_RESULT nFuncResult = RESULT_NOT_OK;
    
    if (FALSE == SPI_bInitialized)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_SETBAUDRATE, DEV_ERROR_NOT_INIT);
    }
    else if (SPI_CHANNEL_MIN > nChannelNum ||
             SPI_CHANNEL_MAX < nChannelNum ||
             FALSE == SPI_stChannelsParams[nChannelNum].bChannelEnabled)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_SETBAUDRATE, DEV_ERROR_PARAM_0);
    }
    else if (SPI_MIN_BAUDRATE > nBaudrate ||
             SPI_MAX_BAUDRATE < nBaudrate)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_SETBAUDRATE, DEV_ERROR_PARAM_1);
    }
    else
    {
        SPI_stChannelsParams[nChannelNum].nBaudRate = nBaudrate;
        while (ON == SPI_pChannels[nChannelNum]->STS.B.BUSY)
        {
            DoNothing();
        }

        SPI_SetupChannelClk(nChannelNum);
        
        nFuncResult = RESULT_OK;
    }

    return nFuncResult;
} // end of SPI_SetBaudrate()



//**************************************************************************************************
//! Sets clock polarity, clock phase, bit order, data frame size and number of used CS pin
//! on the specified SPI module (channel)
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
//! \return RESULT_OK     - function is completed successfully \n
//!         RESULT_NOT_OK - function is ended with an error
//**************************************************************************************************
STD_RESULT SPI_SetTransferFormat(const U8      nChannelNum,
                                 const BOOLEAN bActiveClockPolarity,
                                 const BOOLEAN bClockPhase,
                                 const BOOLEAN bBitOrder,
                                 const U8      nDataFrameSize,
                                 const U8      nCSNum)
{
    STD_RESULT nFuncResult = RESULT_NOT_OK;
    
    if (FALSE == SPI_bInitialized)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_SETTRANSFERFORMAT, DEV_ERROR_NOT_INIT);
    }
    else if (SPI_CHANNEL_MIN > nChannelNum ||
             SPI_CHANNEL_MAX < nChannelNum ||
             FALSE == SPI_stChannelsParams[nChannelNum].bChannelEnabled)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_SETTRANSFERFORMAT, DEV_ERROR_PARAM_0);
    }
    else
    {
        nFuncResult = RESULT_OK;

        // Setup clock polarity
        if (SPI_CLOCK_POL_LOW == bActiveClockPolarity ||
            SPI_CPOL_0        == bActiveClockPolarity)
        {
            SPI_stChannelsParams[nChannelNum].bActiveClockPolarity = SPI_CFG_CPOL_0;
        }
        else if (SPI_CLOCK_POL_HIGH == bActiveClockPolarity ||
                 SPI_CPOL_1         == bActiveClockPolarity)
        {
            SPI_stChannelsParams[nChannelNum].bActiveClockPolarity = SPI_CFG_CPOL_1;
        }
        else
        {
            nFuncResult = RESULT_NOT_OK;
            SPI_REPORT_DEV_ERROR(SPI_API_ID_SETTRANSFERFORMAT, DEV_ERROR_PARAM_1);
        }

        // Setup clock phase
        if (SPI_PHASE_RISING == bClockPhase ||
            SPI_CPHA_0       == bClockPhase)
        {
            SPI_stChannelsParams[nChannelNum].bClockPhase = SPI_CFG_CPHA_0;
        }
        else if (SPI_PHASE_FALLING == bClockPhase ||
                 SPI_CPHA_1        == bClockPhase)
        {
            SPI_stChannelsParams[nChannelNum].bClockPhase = SPI_CFG_CPHA_1;
        }
        else
        {
            nFuncResult = RESULT_NOT_OK;
            SPI_REPORT_DEV_ERROR(SPI_API_ID_SETTRANSFERFORMAT, DEV_ERROR_PARAM_2);
        }

        // Setup bit order
        if (SPI_BIT_ORDER_LSB_FIRST == bBitOrder)
        {
            SPI_stChannelsParams[nChannelNum].bBitOrder = SPI_CFG_BIT_ORDER_LSB_FIRST;
        }
        else if (SPI_BIT_ORDER_MSB_FIRST == bBitOrder)
        {
            SPI_stChannelsParams[nChannelNum].bBitOrder = SPI_CFG_BIT_ORDER_MSB_FIRST;
        }
        else
        {
            nFuncResult = RESULT_NOT_OK;
            SPI_REPORT_DEV_ERROR(SPI_API_ID_SETTRANSFERFORMAT, DEV_ERROR_PARAM_3);
        }

        // Setup frame size
        if ((SPI_DATA_SIZE_MIN > nDataFrameSize) ||
            (SPI_DATA_SIZE_MAX < nDataFrameSize))
        {
            SPI_stChannelsParams[nChannelNum].nDataFrameSize = nDataFrameSize;
        }
        else
        {
            nFuncResult = RESULT_NOT_OK;
            SPI_REPORT_DEV_ERROR(SPI_API_ID_SETTRANSFERFORMAT, DEV_ERROR_PARAM_4);
        }
        
        // Setup CS num
        if (SPI_CS_NUM_MIN <= nCSNum &&
            SPI_CS_NUM_MAX >= nCSNum &&
            SPI_CS_AVAILABLE == SPI_stChannelsParams[nChannelNum].nCSAvailble[nCSNum])
        {
            SPI_stChannelsParams[nChannelNum].nCSNum = nCSNum;
        }
        else
        {
            nFuncResult = RESULT_NOT_OK;
            SPI_REPORT_DEV_ERROR(SPI_API_ID_SETTRANSFERFORMAT, DEV_ERROR_PARAM_5);
        }

        // Apply changes 
        while (ON == SPI_pChannels[nChannelNum]->STS.B.BUSY)
        {
            DoNothing();
        }

        SPI_SetupChannelParams(nChannelNum);
    }

    return nFuncResult;
} // end of SPI_SetTransferFormat()



//**************************************************************************************************
//! Sets callback function pointer for the specified SPI module (channel)
//!
//! \note None
//!
//! \param[in] nChannelNum       - SPI channel number
//! \param[in] pCallbackFunction - callback function pointer
//!
//! \return RESULT_OK     - function is completed successfully \n
//!         RESULT_NOT_OK - function is ended with an error
//**************************************************************************************************
STD_RESULT SPI_SetCallbackFunction(const U8           nChannelNum,
                                   const SPI_CALLBACK pCallbackFunction)
{
    STD_RESULT nFuncResult = RESULT_NOT_OK;
    
    if (FALSE == SPI_bInitialized)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_SETCALLBACKFUNCTION, DEV_ERROR_NOT_INIT);
    }
    else if (SPI_CHANNEL_MIN > nChannelNum ||
             SPI_CHANNEL_MAX < nChannelNum ||
             FALSE == SPI_stChannelsParams[nChannelNum].bChannelEnabled)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_SETCALLBACKFUNCTION, DEV_ERROR_PARAM_0);
    }
    else
    {
        if (NULL_PTR != pCallbackFunction)
        {
            SPI_callbacks[nChannelNum] = pCallbackFunction;

            nFuncResult = RESULT_OK;
        }
        else
        {
            // Report runtime error
            SPI_REPORT_RT_ERROR(SPI_API_ID_SETCALLBACKFUNCTION, RT_ERROR_NULL_PTR);
        }
    }

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
    if (FALSE == SPI_bInitialized)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_RX_ISR, DEV_ERROR_NOT_INIT);
    }
    else if (SPI_CHANNEL_MIN > nChannelNum ||
             SPI_CHANNEL_MAX < nChannelNum ||
             FALSE == SPI_stChannelsParams[nChannelNum].bChannelEnabled)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_RX_ISR, DEV_ERROR_PARAM_0);
    }
    else
    {
        U32 nRxData = SPI_pChannels[nChannelNum]->DATA.B.DATA;

        // Put input frame to RX FIFO
        if (CIRCBUF_GetFreeSize(&SPI_stCircBufferRX[nChannelNum]) >= 1U)
        {
                CIRCBUF_PutData((U32*)&nRxData,
                                &SPI_stCircBufferRX[nChannelNum]);
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
    else if (SPI_CHANNEL_MIN > nChannelNum ||
             SPI_CHANNEL_MAX < nChannelNum ||
             FALSE == SPI_stChannelsParams[nChannelNum].bChannelEnabled)
    {
        SPI_REPORT_DEV_ERROR(SPI_API_ID_TX_ISR, DEV_ERROR_PARAM_0);
    }
    else
    {
        // Transmit data
        if (FALSE == SPI_StartTransfer(nChannelNum))
        {
            // Callback function execution
            if (NULL_PTR != SPI_callbacks[nChannelNum])
            {
                SPI_callbacks[nChannelNum]();
            }
        }
    }
} // end of SPI_HighLevel_TX_ISR()



//**************************************************************************************************
//==================================================================================================
// Definitions of local (private) functions
//==================================================================================================
//**************************************************************************************************

//**************************************************************************************************
//! Initialize channels params struct
//! \note       None.
//! \param[in]  None.
//! \return     None.
//**************************************************************************************************
static void SPI_InitParams(void)
{
    // Fill SPI0 param structure
    #if (ON == SPI_CHANNEL_0_IN_USE)
        SPI_stChannelsParams[SPI_CHANNEL_0].bChannelEnabled      = TRUE;

        #if (SPI_MODE_MASTER == SPI_CHANNEL_0_MODE)
            SPI_stChannelsParams[SPI_CHANNEL_0].bChannelMode     = SPI_CFG_MASTER;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_0].bChannelMode     = SPI_CFG_SLAVE;
        #endif

        SPI_stChannelsParams[SPI_CHANNEL_0].bActiveClockPolarity = FALSE;
        SPI_stChannelsParams[SPI_CHANNEL_0].bClockPhase          = FALSE;
        SPI_stChannelsParams[SPI_CHANNEL_0].bBitOrder            = FALSE;
        SPI_stChannelsParams[SPI_CHANNEL_0].nDataFrameSize       = SPI_DATA_SIZE_MAX;
        SPI_stChannelsParams[SPI_CHANNEL_0].nBaudRate            = SPI_CHANNEL_0_BAUDRATE;
        
        #if (ON == SPI_CHANNEL_0_CS_3_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_0].nCSNum = SPI_CS_NUM_3;
            SPI_stChannelsParams[SPI_CHANNEL_0].nCSAvailble[SPI_CS_NUM_3] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_0].nCSAvailble[SPI_CS_NUM_3] = SPI_CS_NOT_AVAILABLE;
        #endif

        #if (ON == SPI_CHANNEL_0_CS_2_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_0].nCSNum = SPI_CS_NUM_2;
            SPI_stChannelsParams[SPI_CHANNEL_0].nCSAvailble[SPI_CS_NUM_2] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_0].nCSAvailble[SPI_CS_NUM_2] = SPI_CS_NOT_AVAILABLE;
        #endif

        #if (ON == SPI_CHANNEL_0_CS_1_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_0].nCSNum = SPI_CS_NUM_1;
            SPI_stChannelsParams[SPI_CHANNEL_0].nCSAvailble[SPI_CS_NUM_1] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_0].nCSAvailble[SPI_CS_NUM_1] = SPI_CS_NOT_AVAILABLE;
        #endif

        #if (ON == SPI_CHANNEL_0_CS_0_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_0].nCSNum = SPI_CS_NUM_0;
            SPI_stChannelsParams[SPI_CHANNEL_0].nCSAvailble[SPI_CS_NUM_0] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_0].nCSAvailble[SPI_CS_NUM_0] = SPI_CS_NOT_AVAILABLE;
        #endif
    #else
        SPI_stChannelsParams[SPI_CHANNEL_0].bChannelEnabled = FALSE; 
    #endif

    // Fill SPI1 param structure
    #if (ON == SPI_CHANNEL_1_IN_USE)
        SPI_stChannelsParams[SPI_CHANNEL_1].bChannelEnabled      = TRUE;
        
        #if (SPI_MODE_MASTER == SPI_CHANNEL_1_MODE)
            SPI_stChannelsParams[SPI_CHANNEL_1].bChannelMode     = SPI_CFG_MASTER;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_1].bChannelMode     = SPI_CFG_SLAVE;
        #endif

        SPI_stChannelsParams[SPI_CHANNEL_1].bActiveClockPolarity = FALSE;
        SPI_stChannelsParams[SPI_CHANNEL_1].bClockPhase          = FALSE;
        SPI_stChannelsParams[SPI_CHANNEL_1].bBitOrder            = FALSE;
        SPI_stChannelsParams[SPI_CHANNEL_1].nDataFrameSize       = SPI_DATA_SIZE_MAX;
        SPI_stChannelsParams[SPI_CHANNEL_1].nBaudRate            = SPI_CHANNEL_1_BAUDRATE;
        
        #if (ON == SPI_CHANNEL_1_CS_3_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_1].nCSNum = SPI_CS_NUM_3;
            SPI_stChannelsParams[SPI_CHANNEL_1].nCSAvailble[SPI_CS_NUM_3] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_1].nCSAvailble[SPI_CS_NUM_3] = SPI_CS_NOT_AVAILABLE;
        #endif

        #if (ON == SPI_CHANNEL_1_CS_2_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_1].nCSNum = SPI_CS_NUM_2;
            SPI_stChannelsParams[SPI_CHANNEL_1].nCSAvailble[SPI_CS_NUM_2] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_1].nCSAvailble[SPI_CS_NUM_2] = SPI_CS_NOT_AVAILABLE;
        #endif

        #if (ON == SPI_CHANNEL_1_CS_1_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_1].nCSNum = SPI_CS_NUM_1;
            SPI_stChannelsParams[SPI_CHANNEL_1].nCSAvailble[SPI_CS_NUM_1] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_1].nCSAvailble[SPI_CS_NUM_1] = SPI_CS_NOT_AVAILABLE;
        #endif

        #if (ON == SPI_CHANNEL_1_CS_0_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_1].nCSNum = SPI_CS_NUM_0;
            SPI_stChannelsParams[SPI_CHANNEL_1].nCSAvailble[SPI_CS_NUM_0] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_1].nCSAvailble[SPI_CS_NUM_0] = SPI_CS_NOT_AVAILABLE;
        #endif
    #else
        SPI_stChannelsParams[SPI_CHANNEL_1].bChannelEnabled = FALSE; 
    #endif

    // Fill SPI2 param structure
    #if (ON == SPI_CHANNEL_2_IN_USE)
        SPI_stChannelsParams[SPI_CHANNEL_2].bChannelEnabled      = TRUE;
        
        #if (SPI_MODE_MASTER == SPI_CHANNEL_2_MODE)
            SPI_stChannelsParams[SPI_CHANNEL_2].bChannelMode     = SPI_CFG_MASTER;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_2].bChannelMode     = SPI_CFG_SLAVE;
        #endif

        SPI_stChannelsParams[SPI_CHANNEL_2].bActiveClockPolarity = FALSE;
        SPI_stChannelsParams[SPI_CHANNEL_2].bClockPhase          = FALSE;
        SPI_stChannelsParams[SPI_CHANNEL_2].bBitOrder            = FALSE;
        SPI_stChannelsParams[SPI_CHANNEL_2].nDataFrameSize       = SPI_DATA_SIZE_MAX;
        SPI_stChannelsParams[SPI_CHANNEL_2].nBaudRate            = SPI_CHANNEL_2_BAUDRATE;
        
        #if (ON == SPI_CHANNEL_2_CS_3_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_2].nCSNum = SPI_CS_NUM_3;
            SPI_stChannelsParams[SPI_CHANNEL_2].nCSAvailble[SPI_CS_NUM_3] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_2].nCSAvailble[SPI_CS_NUM_3] = SPI_CS_NOT_AVAILABLE;
        #endif

        #if (ON == SPI_CHANNEL_2_CS_2_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_2].nCSNum = SPI_CS_NUM_2;
            SPI_stChannelsParams[SPI_CHANNEL_2].nCSAvailble[SPI_CS_NUM_2] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_2].nCSAvailble[SPI_CS_NUM_2] = SPI_CS_NOT_AVAILABLE;
        #endif

        #if (ON == SPI_CHANNEL_2_CS_1_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_2].nCSNum = SPI_CS_NUM_1;
            SPI_stChannelsParams[SPI_CHANNEL_2].nCSAvailble[SPI_CS_NUM_1] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_2].nCSAvailble[SPI_CS_NUM_1] = SPI_CS_NOT_AVAILABLE;
        #endif

        #if (ON == SPI_CHANNEL_2_CS_0_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_2].nCSNum = SPI_CS_NUM_0;
            SPI_stChannelsParams[SPI_CHANNEL_2].nCSAvailble[SPI_CS_NUM_0] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_2].nCSAvailble[SPI_CS_NUM_0] = SPI_CS_NOT_AVAILABLE;
        #endif
    #else
        SPI_stChannelsParams[SPI_CHANNEL_2].bChannelEnabled = FALSE; 
    #endif

    // Fill SPI3 param structure
    #if (ON == SPI_CHANNEL_3_IN_USE)
        SPI_stChannelsParams[SPI_CHANNEL_3].bChannelEnabled      = TRUE;
        
        #if (SPI_MODE_MASTER == SPI_CHANNEL_3_MODE)
            SPI_stChannelsParams[SPI_CHANNEL_3].bChannelMode     = SPI_CFG_MASTER;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_3].bChannelMode     = SPI_CFG_SLAVE;
        #endif

        SPI_stChannelsParams[SPI_CHANNEL_3].bActiveClockPolarity = FALSE;
        SPI_stChannelsParams[SPI_CHANNEL_3].bClockPhase          = FALSE;
        SPI_stChannelsParams[SPI_CHANNEL_3].bBitOrder            = FALSE;
        SPI_stChannelsParams[SPI_CHANNEL_3].nDataFrameSize       = SPI_DATA_SIZE_MAX;
        SPI_stChannelsParams[SPI_CHANNEL_3].nBaudRate            = SPI_CHANNEL_3_BAUDRATE;
        
        #if (ON == SPI_CHANNEL_3_CS_3_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_3].nCSNum = SPI_CS_NUM_3;
            SPI_stChannelsParams[SPI_CHANNEL_3].nCSAvailble[SPI_CS_NUM_3] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_3].nCSAvailble[SPI_CS_NUM_3] = SPI_CS_NOT_AVAILABLE;
        #endif

        #if (ON == SPI_CHANNEL_3_CS_2_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_3].nCSNum = SPI_CS_NUM_2;
            SPI_stChannelsParams[SPI_CHANNEL_3].nCSAvailble[SPI_CS_NUM_2] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_3].nCSAvailble[SPI_CS_NUM_2] = SPI_CS_NOT_AVAILABLE;
        #endif

        #if (ON == SPI_CHANNEL_3_CS_1_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_3].nCSNum = SPI_CS_NUM_1;
            SPI_stChannelsParams[SPI_CHANNEL_3].nCSAvailble[SPI_CS_NUM_1] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_3].nCSAvailble[SPI_CS_NUM_1] = SPI_CS_NOT_AVAILABLE;
        #endif

        #if (ON == SPI_CHANNEL_3_CS_0_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_3].nCSNum = SPI_CS_NUM_0;
            SPI_stChannelsParams[SPI_CHANNEL_3].nCSAvailble[SPI_CS_NUM_0] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_3].nCSAvailble[SPI_CS_NUM_0] = SPI_CS_NOT_AVAILABLE;
        #endif
    #else
        SPI_stChannelsParams[SPI_CHANNEL_3].bChannelEnabled = FALSE; 
    #endif

    // Fill SPI4 param structure
    #if (ON == SPI_CHANNEL_4_IN_USE)
        SPI_stChannelsParams[SPI_CHANNEL_4].bChannelEnabled      = TRUE;
        
        #if (SPI_MODE_MASTER == SPI_CHANNEL_4_MODE)
            SPI_stChannelsParams[SPI_CHANNEL_4].bChannelMode     = SPI_CFG_MASTER;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_4].bChannelMode     = SPI_CFG_SLAVE;
        #endif

        SPI_stChannelsParams[SPI_CHANNEL_4].bActiveClockPolarity = FALSE;
        SPI_stChannelsParams[SPI_CHANNEL_4].bClockPhase          = FALSE;
        SPI_stChannelsParams[SPI_CHANNEL_4].bBitOrder            = FALSE;
        SPI_stChannelsParams[SPI_CHANNEL_4].nDataFrameSize       = SPI_DATA_SIZE_MAX;
        SPI_stChannelsParams[SPI_CHANNEL_4].nBaudRate            = SPI_CHANNEL_4_BAUDRATE;
        
        #if (ON == SPI_CHANNEL_4_CS_3_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_4].nCSNum = SPI_CS_NUM_3;
            SPI_stChannelsParams[SPI_CHANNEL_4].nCSAvailble[SPI_CS_NUM_3] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_4].nCSAvailble[SPI_CS_NUM_3] = SPI_CS_NOT_AVAILABLE;
        #endif

        #if (ON == SPI_CHANNEL_4_CS_2_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_4].nCSNum = SPI_CS_NUM_2;
            SPI_stChannelsParams[SPI_CHANNEL_4].nCSAvailble[SPI_CS_NUM_2] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_4].nCSAvailble[SPI_CS_NUM_2] = SPI_CS_NOT_AVAILABLE;
        #endif

        #if (ON == SPI_CHANNEL_4_CS_1_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_4].nCSNum = SPI_CS_NUM_1;
            SPI_stChannelsParams[SPI_CHANNEL_4].nCSAvailble[SPI_CS_NUM_1] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_4].nCSAvailble[SPI_CS_NUM_1] = SPI_CS_NOT_AVAILABLE;
        #endif

        #if (ON == SPI_CHANNEL_4_CS_0_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_4].nCSNum = SPI_CS_NUM_0;
            SPI_stChannelsParams[SPI_CHANNEL_4].nCSAvailble[SPI_CS_NUM_0] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_4].nCSAvailble[SPI_CS_NUM_0] = SPI_CS_NOT_AVAILABLE;
        #endif
    #else
        SPI_stChannelsParams[SPI_CHANNEL_4].bChannelEnabled = FALSE; 
    #endif

    // Fill SPI5 param structure
    #if (ON == SPI_CHANNEL_5_IN_USE)
        SPI_stChannelsParams[SPI_CHANNEL_5].bChannelEnabled      = TRUE;
        
        #if (SPI_MODE_MASTER == SPI_CHANNEL_5_MODE)
            SPI_stChannelsParams[SPI_CHANNEL_5].bChannelMode     = SPI_CFG_MASTER;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_5].bChannelMode     = SPI_CFG_SLAVE;
        #endif

        SPI_stChannelsParams[SPI_CHANNEL_5].bActiveClockPolarity = FALSE;
        SPI_stChannelsParams[SPI_CHANNEL_5].bClockPhase          = FALSE;
        SPI_stChannelsParams[SPI_CHANNEL_5].bBitOrder            = FALSE;
        SPI_stChannelsParams[SPI_CHANNEL_5].nDataFrameSize       = SPI_DATA_SIZE_MAX;
        SPI_stChannelsParams[SPI_CHANNEL_5].nBaudRate            = SPI_CHANNEL_5_BAUDRATE;
        
        #if (ON == SPI_CHANNEL_5_CS_3_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_5].nCSNum = SPI_CS_NUM_3;
            SPI_stChannelsParams[SPI_CHANNEL_5].nCSAvailble[SPI_CS_NUM_3] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_5].nCSAvailble[SPI_CS_NUM_3] = SPI_CS_NOT_AVAILABLE;
        #endif

        #if (ON == SPI_CHANNEL_5_CS_2_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_5].nCSNum = SPI_CS_NUM_2;
            SPI_stChannelsParams[SPI_CHANNEL_5].nCSAvailble[SPI_CS_NUM_2] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_5].nCSAvailble[SPI_CS_NUM_2] = SPI_CS_NOT_AVAILABLE;
        #endif

        #if (ON == SPI_CHANNEL_5_CS_1_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_5].nCSNum = SPI_CS_NUM_1;
            SPI_stChannelsParams[SPI_CHANNEL_5].nCSAvailble[SPI_CS_NUM_1] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_5].nCSAvailble[SPI_CS_NUM_1] = SPI_CS_NOT_AVAILABLE;
        #endif

        #if (ON == SPI_CHANNEL_5_CS_0_IN_USE)
            SPI_stChannelsParams[SPI_CHANNEL_5].nCSNum = SPI_CS_NUM_0;
            SPI_stChannelsParams[SPI_CHANNEL_5].nCSAvailble[SPI_CS_NUM_0] = SPI_CS_AVAILABLE;
        #else
            SPI_stChannelsParams[SPI_CHANNEL_5].nCSAvailble[SPI_CS_NUM_0] = SPI_CS_NOT_AVAILABLE;
        #endif
    #else
        SPI_stChannelsParams[SPI_CHANNEL_5].bChannelEnabled = FALSE; 
    #endif
   
} // end of SPI_InitParams()



//**************************************************************************************************
//! Initializes bufers and another software modules for SPI
//! \note       None.
//! \param[in]  None.
//! \return     None.
//**************************************************************************************************
static void SPI_InitSW(void)
{
    for (U8 nChannelNum = 0U; nChannelNum < SPI_CHANNEL_QTY; nChannelNum++)
    {
        SPI_stCircBufferRX[nChannelNum].itemSize = sizeof(U32);
        SPI_stCircBufferTX[nChannelNum].itemSize = sizeof(U32);

        CIRCBUF_Init(&SPI_stCircBufferRX[nChannelNum],
                     SPI_pCircBuffDataRX[nChannelNum],
                     SIZE_OF_ARRAY(SPI_pCircBuffDataRX[nChannelNum]));

        CIRCBUF_Init(&SPI_stCircBufferTX[nChannelNum],
                     SPI_pCircBuffDataTX[nChannelNum],
                     SIZE_OF_ARRAY(SPI_pCircBuffDataTX[nChannelNum]));

        CIRCBUF_Purge(&SPI_stCircBufferRX[nChannelNum]);
        CIRCBUF_Purge(&SPI_stCircBufferTX[nChannelNum]);
    }

} // end of SPI_InitSW()



//**************************************************************************************************
//! Initializes all SPI channels registers
//! \note       None.
//! \param[in]  None.
//! \return     None.
//**************************************************************************************************
static void SPI_InitHW(void)
{
    // If GPIO clk is not taken on
    if (OFF == IPC.CTRL[SPI_IPC_PCTRL_GPIO_INDEX].B.CLKEN)
    {
        // Take on GPIO clk
        IPC.CTRL[SPI_IPC_PCTRL_GPIO_INDEX].B.CLKEN = ON;
    }

    // If port X is used, take it's clk on
    #if (TRUE == SPI_GPIO_PORT_IN_USE(SPI_PORT_A) )
        SPI_TakeOnPortClk(SPI_IPC_PCTRLA_INDEX);
    #endif

    #if (TRUE == SPI_GPIO_PORT_IN_USE(SPI_PORT_B) )
        SPI_TakeOnPortClk(SPI_IPC_PCTRLB_INDEX);
    #endif

    #if (TRUE == SPI_GPIO_PORT_IN_USE(SPI_PORT_C) )
        SPI_TakeOnPortClk(SPI_IPC_PCTRLC_INDEX);
    #endif

    #if (TRUE == SPI_GPIO_PORT_IN_USE(SPI_PORT_D) )
        SPI_TakeOnPortClk(SPI_IPC_PCTRLD_INDEX);
    #endif

    #if (TRUE == SPI_GPIO_PORT_IN_USE(SPI_PORT_E) )
        SPI_TakeOnPortClk(SPI_IPC_PCTRLE_INDEX);
    #endif

    // If channel X is used, setup GPIO MUX and 
    // pullup\pulldown for it
    #if (ON == SPI_CHANNEL_0_IN_USE)
        SPI_CHANNEL_PCTRL_FILL(SPI_CHANNEL_0);
        SPI_ConfigureChannel(SPI_CHANNEL_0);
    #endif

    #if (ON == SPI_CHANNEL_1_IN_USE)
        SPI_CHANNEL_PCTRL_FILL(SPI_CHANNEL_1);
        SPI_ConfigureChannel(SPI_CHANNEL_1);
    #endif

    #if (ON == SPI_CHANNEL_2_IN_USE)
        SPI_CHANNEL_PCTRL_FILL(SPI_CHANNEL_2);
        SPI_ConfigureChannel(SPI_CHANNEL_2);
    #endif

    #if (ON == SPI_CHANNEL_3_IN_USE)
        SPI_CHANNEL_PCTRL_FILL(SPI_CHANNEL_3);
        SPI_ConfigureChannel(SPI_CHANNEL_3);
    #endif

    #if (ON == SPI_CHANNEL_4_IN_USE)
        SPI_CHANNEL_PCTRL_FILL(SPI_CHANNEL_4);
        SPI_ConfigureChannel(SPI_CHANNEL_4);
    #endif

    #if (ON == SPI_CHANNEL_5_IN_USE)
        SPI_CHANNEL_PCTRL_FILL(SPI_CHANNEL_5);
        SPI_ConfigureChannel(SPI_CHANNEL_5);
    #endif

} // end of SPI_InitHW()



//**************************************************************************************************
//! DeInitializes all bufers and another software modules for SPI
//! \note       None.
//! \param[in]  None.
//! \return     None.
//**************************************************************************************************
static void SPI_DeInitSW(void)
{   
    for (U8 nChannelNum = 0U; nChannelNum < SPI_CHANNEL_QTY; ++nChannelNum)
    {
        SPI_Purge(nChannelNum,
                  TRUE,
                  TRUE);
    }
} // end of SPI_DeInitSW()



//**************************************************************************************************
//! DeInitializes all SPI channels registers
//! \note       None.
//! \param[in]  None.
//! \return     None.
//**************************************************************************************************
static void SPI_DeInitHW(void)
{
    // If channel X is used, deinit IRQ 
    // And take off enable bit
    #if (ON == SPI_CHANNEL_0_IN_USE)
        SPI_DisableChannel(SPI_CHANNEL_0);
    #endif

    #if (ON == SPI_CHANNEL_1_IN_USE)
        SPI_DisableChannel(SPI_CHANNEL_1);
    #endif

    #if (ON == SPI_CHANNEL_2_IN_USE)
        SPI_DisableChannel(SPI_CHANNEL_2);
    #endif

    #if (ON == SPI_CHANNEL_3_IN_USE)
        SPI_DisableChannel(SPI_CHANNEL_3);
    #endif

    #if (ON == SPI_CHANNEL_4_IN_USE)
        SPI_DisableChannel(SPI_CHANNEL_4);
    #endif

    #if (ON == SPI_CHANNEL_5_IN_USE)
        SPI_DisableChannel(SPI_CHANNEL_5);
    #endif
      
} // end of SPI_DeInitHW()



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
    U8 nTxFifoNumberOfItems = CIRCBUF_GetNumberOfItems(&SPI_stCircBufferTX[nChannelNum]);

    if (0U != nTxFifoNumberOfItems)
    {
        // Get TX data from the buffer        
        if (CIRCBUF_NO_ERR == CIRCBUF_GetData(&nTxData, &SPI_stCircBufferTX[nChannelNum]))
        {
            while (ON == SPI_pChannels[nChannelNum]->STS.B.BUSY)
            {
                DoNothing();
            }
            
            SPI_pChannels[nChannelNum]->DATA.B.DATA = nTxData;
            bFuncResult = TRUE;
            
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



#ifndef SPI_NO_ONE_IN_USE 
//**************************************************************************************************
//! Take on clock for specific port
//! \note       None.
//! \param[in]  nPortNum  - IPC port number
//! \return     None.
//**************************************************************************************************
static void SPI_TakeOnPortClk(U8 nPortNum)
{
    if (ON != IPC.CTRL[nPortNum].B.CLKEN)
    {
        IPC.CTRL[nPortNum].B.CLKEN = ON;
    } 
} // end of SPI_TakeOnPortClk()
#endif // end of SPI_NO_ONE_IN_USE 



//**************************************************************************************************
//! Setup all dividers and clock parameters
//! \note       None.
//! \param[in]  nChannelNum  - SPI channel number
//! \return     None.
//**************************************************************************************************
static void SPI_SetupChannelClk(U8 nChannelNum)
{ 
    U32 nDivider = (MCU_GetBusFrequency(MCU_CLOCK_SOURCE_BUS0) / 2) / 
                    (SPI_IPC_CTRL_DIV_5 + 1U)    /                        
                    SPI_TXCFG_DIV_VALUE_2        /                        
                    SPI_stChannelsParams[nChannelNum].nBaudRate;           
                                                                      
    U8 nTxcfgPrescaler = SPI_TXCFG_DIV_2;                               
                                                                      
    if (nDivider > SPI_DIVIDER_OVERFLOW_VALUE)                                              
    {                                                                 
        nDivider = nDivider / SPI_DIVIDER_COEFF_VALUE;                                        
        nTxcfgPrescaler = SPI_TXCFG_DIV_16;                             
    }                                                                 
    if (nDivider > SPI_DIVIDER_OVERFLOW_VALUE)                                              
    {                                                                 
        nDivider = nDivider / SPI_DIVIDER_COEFF_VALUE;                                        
        nTxcfgPrescaler = SPI_TXCFG_DIV_128;                            
    }                                                                 

    SPI_pChannels[nChannelNum]->TXCFG.B.PRESCALE = nTxcfgPrescaler;                
    SPI_pChannels[nChannelNum]->CLK.B.DIV = (U8)(nDivider * 2U - 2U); 

} // end of SPI_SetupChannelClk()



//**************************************************************************************************
//! Setup all transmit\receive params
//! \note       None.
//! \param[in]  nChannelNum  - SPI channel number
//! \return     None.
//**************************************************************************************************
static void SPI_SetupChannelParams(U8 nChannelNum)
{
    SPI_pChannels[nChannelNum]->TXCFG.B.CPOL = 
            SPI_stChannelsParams[nChannelNum].bActiveClockPolarity;

    SPI_pChannels[nChannelNum]->TXCFG.B.CPHA = 
            SPI_stChannelsParams[nChannelNum].bClockPhase;

    SPI_pChannels[nChannelNum]->TXCFG.B.LSBF = 
            SPI_stChannelsParams[nChannelNum].bBitOrder;

    SPI_pChannels[nChannelNum]->TXCFG.B.FRAMESZ = 
            SPI_stChannelsParams[nChannelNum].nDataFrameSize - 1U;
            
    SPI_pChannels[nChannelNum]->TXCFG.B.PCS = 
            SPI_stChannelsParams[nChannelNum].nCSNum;

} // end of SPI_SetupChannelParams()



#ifndef SPI_NO_ONE_IN_USE 
//**************************************************************************************************
//! Configure channel
//! \note       None.
//! \param[in]  nChannelNum  - SPI channel number
//! \return     None.
//**************************************************************************************************
static void SPI_ConfigureChannel(U8 nChannelNum)
{
    static U8 SPI_IpcSpiIndexes[] = {SPI_IPC_SPI0_INDEX, SPI_IPC_SPI1_INDEX, 
                                     SPI_IPC_SPI2_INDEX, SPI_IPC_SPI3_INDEX, 
                                     SPI_IPC_SPI4_INDEX, SPI_IPC_SPI5_INDEX};

    IPC.CTRL[SPI_IpcSpiIndexes[nChannelNum]].B.DIV = SPI_IPC_CTRL_DIV_5;        
    IPC.CTRL[SPI_IpcSpiIndexes[nChannelNum]].B.SRCSEL = SPI_IPC_SRCSEL_PLL;  

    if (OFF == IPC.CTRL[SPI_IpcSpiIndexes[nChannelNum]].B.CLKEN)            
    {                                                                 
        IPC.CTRL[SPI_IpcSpiIndexes[nChannelNum]].B.CLKEN = ON;              
    } 

    SPI_SetupChannelClk(nChannelNum); 

    SPI_pChannels[nChannelNum]->CTRL.B.MODE = SPI_stChannelsParams[nChannelNum].bChannelMode;         
    SPI_pChannels[nChannelNum]->CTRL.B.EN = ON;           

    while (ON != SPI_pChannels[nChannelNum]->CTRL.B.EN)
    {
        DoNothing();
    }       

    SPI_pChannels[nChannelNum]->CLK.B.SCKPCS = SPI_CLK_SCKPCS_VALUE;
    SPI_pChannels[nChannelNum]->CLK.B.PCSSCK = SPI_CLK_PCSSCK_VALUE;
    SPI_pChannels[nChannelNum]->CLK.B.FMDLY  = SPI_CLK_FMDLY_VALUE;

    SPI_SetupChannelParams(nChannelNum); 

    SPI_pChannels[nChannelNum]->INTE.B.RXIE = ON;
    SPI_pChannels[nChannelNum]->INTE.B.TCIE = ON;

} // end of SPI_ConfigureChannel()
#endif // end of SPI_NO_ONE_IN_USE 



#ifndef SPI_NO_ONE_IN_USE 
//**************************************************************************************************
//! Take off channel
//! \note       None.
//! \param[in]  nChannelNum  - SPI channel number
//! \return     None.
//**************************************************************************************************
static void SPI_DisableChannel(U8 nChannelNum)
{
    SPI_pChannels[nChannelNum]->INTE.B.RXIE = OFF;
    SPI_pChannels[nChannelNum]->INTE.B.TCIE = OFF;

    SPI_pChannels[nChannelNum]->CTRL.B.EN = OFF;           

    while (OFF != SPI_pChannels[nChannelNum]->CTRL.B.EN)
    {
        DoNothing();
    }   
} // end of SPI_DisableChannel()
#endif // end of SPI_NO_ONE_IN_USE 



//****************************************** end of file *******************************************
