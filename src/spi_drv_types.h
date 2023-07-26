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

// Get config header
#include "spi_drv_cfg.h"

// Get FIFO buffer functions
#include "circ_buffer.h"

//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************




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
#define SPI_OUTPUT_MODE_OPEN_DRAIN          (0U)
#define SPI_OUTPUT_MODE_PUSH_PULL           (1U)
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

//! \name IPC spi control indexes
//! @{
#define IPC_SPI0_INDEX         (42U)
#define IPC_SPI1_INDEX         (43U)
#define IPC_SPI2_INDEX         (44U)
#define IPC_SPI3_INDEX         (45U)
#define IPC_SPI4_INDEX         (46U)
#define IPC_SPI5_INDEX         (47U)
//! @}

//! \name IPC gpio port control indexes
//! @{
#define IPC_PCTRLA_INDEX       (18U)
#define IPC_PCTRLB_INDEX       (19U)
#define IPC_PCTRLC_INDEX       (20U)
#define IPC_PCTRLD_INDEX       (21U)
#define IPC_PCTRLE_INDEX       (22U)
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

//! Minimal data size
#define SPI_DATA_SIZE_MIN                   (SPI_DATA_SIZE_4)
//! Maximal data size
#define SPI_DATA_SIZE_MAX                   (SPI_DATA_SIZE_32)
//! @}



#endif  // SPI_DRV_TYPES_H

//****************************************** end of file *******************************************
