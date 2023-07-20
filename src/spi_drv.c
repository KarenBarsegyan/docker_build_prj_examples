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

// Native header
#include "spi_drv.h"

// Get program module specific types
#include "spi_drv_types.h"

// Family dependent interface
#include "spi_drv_hw.h"

// MCU driver header
#include "mcu_drv.h"

// HC32F4A registers
#include "derivative_cfg.h"

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

// None.

 

//**************************************************************************************************
// Definitions of local (private) constants
//**************************************************************************************************

#if (ON == SPI_DEVELOPMENT_ERROR_DETECTION)
//! Program module ID ( = program module prefix)
static const U8 SPI_moduleID[] = "SPI_DRV";
#endif



//**************************************************************************************************
// Definitions of static global (private) variables
//**************************************************************************************************

// None



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
    
    // TODO

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
    
    // TODO

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