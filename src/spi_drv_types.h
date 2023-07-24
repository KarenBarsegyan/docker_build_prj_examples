//**************************************************************************************************
// @Module  SPI driver
//! \file   spi_drv.c
//! \par    Platform
//!             YTM32
//! \par    Compatible
//!             YTM32B1M families
//! \brief  Constants for SPI driver configuration
//!
//! \par    Abbreviations
//!             MCU - MicroController Unit
//!             SPI - Serial Peripheral Interface
//! \par    History
//! | Date       | Version | Author  | Comment
//! |:----------:|:-------:|:-------:|--------------------------------------------------------------
//! | 00.00.2023 |  1.0.0  |   BKR   | First release.
//**************************************************************************************************


#ifndef SPI_DRV_TYPES_H
#define SPI_DRV_TYPES_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Native header
#include "spi_drv.h" 

// Get FIFO buffer functions
#include "circ_buffer.h"

//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************


//! SPI channel configuration
typedef struct
{
    //! Channel enable flag
    BOOLEAN bChannelEnable;
} SPI_CHANNEL_CONFIG;

//! Buffer structure
typedef struct
{
    //! RX FIFO structure
    stCIRCBUF stRXfifo;
    //! TX FIFO structure
    stCIRCBUF stTXfifo;
    //! RX buffer
    U32       pRXbuffer[SPI_CHANNEL_RX_FIFO_SIZE];
    //! TX buffer
    U32       pTXbuffer[SPI_CHANNEL_TX_FIFO_SIZE];
} SPI_CHANNEL_FIFO_BUF;

//! Parameters for the SPI channel
typedef struct
{
    //! SPI Callback
    SPI_CALLBACK pCallback;
    //! SPI current state
    U8 nSpiState;
    //! RX and TX FIFO
    SPI_CHANNEL_FIFO_BUF stFIFO;
    //! Frame size
    U8 nFrameSize;
} SPI_CHANNEL_PARAMS;

//! SPI low-level channel configuration
typedef struct
{
    //! SPI mode
    U8 nSPImode;
    //! SPI data baudrate
    U32 nBaudrate;
    //! RX FIFO size
    U8 nRxFifoSize;
    //! TX FIFO size
    U8 nTxFifoSize;
    //! MOSI port
    U8 nMOSIport;
    //! MOSI pin
    U8 nMOSIpin;
    //! MOSI pin output mode
    U8 nMOSIoutMode;
    //! MOSI pin pull mode
    U8 nMOSIpullMode;
    //! MISO port
    U8 nMISOport;
    //! MISO pin
    U8 nMISOpin;
    //! MISO pin output mode
    U8 nMISOoutMode;
    //! MISO pin pull mode
    U8 nMISOpullMode;
    //! SCLK port
    U8 nSCLKport;
    //! SCLK pin
    U8 nSCLKpin;
    //! SCLK pin output mode
    U8 nSCLKoutMode;
    //! SCLK pin pull mode
    U8 nSCLKpullMode;
    //! CS pin output mode
    U8 nCSoutMode;
    //! CS pin pull mode
    U8 nCSpullMode;
} SPI_HW_CHANNEL_CONFIG;

//! Low-level parameters for the SPI channel
typedef struct
{
    //! Function number of the MOSI pin
    U8 nMOSIfunc;
    //! Function number of the MISO pin
    U8 nMISOfunc;
    //! Function number of the SCLK pin
    U8 nSCLKfunc;
    //! Function number of the CS pin
    U8 nCSfunc;
    //! CS sequence number in one channel
    U8 nCSseqNum;
    //! CS port
    U8 nCSport;
    //! CS pin
    U8 nCSpin;
    //! CS number
    U8 nCSnum;
} SPI_HW_CHANNEL_PARAMS;



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

//! \name All possible port names
//! @{
#define SPI_PORT_A                          (0U)
#define SPI_PORT_B                          (1U)
#define SPI_PORT_C                          (2U)
#define SPI_PORT_D                          (3U)
#define SPI_PORT_E                          (4U)
#define SPI_PORT_MIN                        (SPI_PORT_A)
#define SPI_PORT_MAX                        (SPI_PORT_E)
#define SPI_PORT_NOT_USED                   (255U)
//! @}

//! Port quantity
#define SPI_PORT_QNT                        (SPI_PORT_MAX + 1U)

//! \name All possible pin names
//! @{
#define SPI_PIN_0                           (0U)
#define SPI_PIN_1                           (1U)
#define SPI_PIN_2                           (2U)
#define SPI_PIN_3                           (3U)
#define SPI_PIN_4                           (4U)
#define SPI_PIN_5                           (5U)
#define SPI_PIN_6                           (6U)
#define SPI_PIN_7                           (7U)
#define SPI_PIN_8                           (8U)
#define SPI_PIN_9                           (9U)
#define SPI_PIN_10                          (10U)
#define SPI_PIN_11                          (11U)
#define SPI_PIN_12                          (12U)
#define SPI_PIN_13                          (13U)
#define SPI_PIN_14                          (14U)
#define SPI_PIN_15                          (15U)
#define SPI_PIN_16                          (16U)
#define SPI_PIN_17                          (17U)
#define SPI_PIN_18                          (18U)
#define SPI_PIN_19                          (19U)
#define SPI_PIN_20                          (20U)
#define SPI_PIN_21                          (21U)
#define SPI_PIN_22                          (22U)
#define SPI_PIN_23                          (23U)
#define SPI_PIN_24                          (24U)
#define SPI_PIN_25                          (25U)
#define SPI_PIN_26                          (26U)
#define SPI_PIN_27                          (27U)
#define SPI_PIN_28                          (28U)
#define SPI_PIN_29                          (29U)
#define SPI_PIN_30                          (30U)
#define SPI_PIN_31                          (31U)
#define SPI_PIN_MIN                         (SPI_PIN_0)
#define SPI_PIN_MAX                         (SPI_PIN_31)
#define SPI_PIN_NOT_USED                    (255U)
//! @}

//! Pin quantity
#define SPI_PIN_QNT                         (SPI_PIN_MAX + 1U)

//! \name Pin pull-up modes
//! @{
#define SPI_PULLUP_MODE_DISABLE             (0U)
#define SPI_PULLUP_MODE_ENABLE              (1U)
//! @}

//! \name Pin output modes
//! @{
#define SPI_OUTPUT_MODE_PUSH_PULL           (0U)
#define SPI_OUTPUT_MODE_OPEN_DRAIN          (1U)
//! @}

//! \name SPI channels definitions
//! @{
#define SPI_CHANNEL_0                       (0U)
#define SPI_CHANNEL_1                       (1U)
#define SPI_CHANNEL_2                       (2U)
#define SPI_CHANNEL_3                       (3U)
#define SPI_CHANNEL_4                       (4U)
#define SPI_CHANNEL_5                       (5U)
#define SPI_CHANNEL_MIN                     (SPI_CHANNEL_0)
#define SPI_CHANNEL_MAX                     (SPI_CHANNEL_5)
//! @}

//! Channel quantity
#define SPI_CHANNEL_QNT                     (SPI_CHANNEL_MAX + 1U)

//! \name CS state
//! @{
#define SPI_CS_ACTIVE                       (LOGIC_0)
#define SPI_CS_INACTIVE                     (LOGIC_1)
//! @}

//! \name Bit states
//! @{
#define SPI_BIT_SET                         (1U)
#define SPI_BIT_CLR                         (0U)
//! @}

//! MAX BAUDRATE value
#define SPI_MAX_BAUDRATE                    (20000000UL)

//! MIN BAUDRATE value
#define SPI_MIN_BAUDRATE                    (1000UL)

//! MAX clock polarity value
#define SPI_MAX_POLARITY_VALUE              (3U)

//! MAX clock phase value
#define SPI_MAX_PHASE_VALUE                 (3U)

//! MAX bit order value
#define SPI_MAX_BIT_ORDER_VALUE             (1U)

//! \name Data size
//! @{
#define SPI_DATA_SIZE_4                     (4U)
#define SPI_DATA_SIZE_5                     (5U)
#define SPI_DATA_SIZE_6                     (6U)
#define SPI_DATA_SIZE_7                     (7U)
#define SPI_DATA_SIZE_8                     (8U)
#define SPI_DATA_SIZE_9                     (9U)
#define SPI_DATA_SIZE_10                    (10U)
#define SPI_DATA_SIZE_11                    (11U)
#define SPI_DATA_SIZE_12                    (12U)
#define SPI_DATA_SIZE_13                    (13U)
#define SPI_DATA_SIZE_14                    (14U)
#define SPI_DATA_SIZE_15                    (15U)
#define SPI_DATA_SIZE_16                    (16U)
#define SPI_DATA_SIZE_20                    (20U)
#define SPI_DATA_SIZE_24                    (24U)
#define SPI_DATA_SIZE_32                    (32U)
//! @}

//! Minimal data size
#define SPI_DATA_SIZE_MIN                   (SPI_DATA_SIZE_4)
//! Maximal data size
#define SPI_DATA_SIZE_MAX                   (SPI_DATA_SIZE_32)



#endif  // SPI_DRV_TYPES_H

//****************************************** end of file *******************************************
