//**************************************************************************************************
// @Module  SPI driver
//! \file   spi_drv_types.h
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
//! | 11.08.2023 |  1.0.0  |   BKR   | First release.
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

//! \name SPI Parameters
//! @{
typedef struct
{
    BOOLEAN bChannelEnabled;
    BOOLEAN bChannelMode;
    BOOLEAN bActiveClockPolarity;
    BOOLEAN bClockPhase;
    BOOLEAN bBitOrder;
    U8      nDataFrameSize;
    U8      nCSNum;
    U8      nCSAvailble[4U];
    U32     nBaudRate;
} SPI_CHANNEL_PARAMS;
//! @}



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

//! \name SPI FIFO buffer size min\max value
//! @{
#define SPI_FIFO_SIZE_MIN               (1U)
#define SPI_FIFO_SIZE_MAX               (255U)
//! @}



//! \name All possible GPIO port names
//! @{
#define SPI_PORT_A                      (0U)
#define SPI_PORT_B                      (1U)
#define SPI_PORT_C                      (2U)
#define SPI_PORT_D                      (3U)
#define SPI_PORT_E                      (4U)
#define SPI_PORT_MIN                    (SPI_PORT_A)
#define SPI_PORT_MAX                    (SPI_PORT_E)
#define SPI_PORT_NOT_USED               (255U)

#define SPI_PORT_QTY                    (SPI_PORT_MAX + 1U)
//! @}



//! \name IPC Dividers
//! @{
#define SPI_IPC_CTRL_DIV_0              (0U)
#define SPI_IPC_CTRL_DIV_2              (1U)
#define SPI_IPC_CTRL_DIV_3              (2U)
#define SPI_IPC_CTRL_DIV_4              (3U)
#define SPI_IPC_CTRL_DIV_5              (4U)
#define SPI_IPC_CTRL_DIV_6              (5U)
#define SPI_IPC_CTRL_DIV_7              (6U)
#define SPI_IPC_CTRL_DIV_8              (7U)
#define SPI_IPC_CTRL_DIV_9              (8U)
#define SPI_IPC_CTRL_DIV_10             (9U)
#define SPI_IPC_CTRL_DIV_11             (10U)
#define SPI_IPC_CTRL_DIV_12             (11U)
#define SPI_IPC_CTRL_DIV_13             (12U)
#define SPI_IPC_CTRL_DIV_14             (13U)
#define SPI_IPC_CTRL_DIV_15             (14U)
#define SPI_IPC_CTRL_DIV_16             (15U)
//! @}



//! \name IPC Source
//! @{
#define SPI_IPC_SRCSEL_NO_CLOCK         (0U)
#define SPI_IPC_SRCSEL_FIRC             (1U)
#define SPI_IPC_SRCSEL_SIRC             (2U)
#define SPI_IPC_SRCSEL_FXOSC            (3U)
#define SPI_IPC_SRCSEL_SXOSC            (4U)
#define SPI_IPC_SRCSEL_PLL              (5U)
//! @}



//! \name TXCFG Dividers
//! @{
#define SPI_TXCFG_DIV_1                 (0U)
#define SPI_TXCFG_DIV_2                 (1U)
#define SPI_TXCFG_DIV_4                 (2U)
#define SPI_TXCFG_DIV_8                 (3U)
#define SPI_TXCFG_DIV_16                (4U)
#define SPI_TXCFG_DIV_32                (5U)
#define SPI_TXCFG_DIV_64                (6U)
#define SPI_TXCFG_DIV_128               (7U)

#define SPI_TXCFG_DIV_VALUE_1           (1U)
#define SPI_TXCFG_DIV_VALUE_2           (2U)
#define SPI_TXCFG_DIV_VALUE_4           (3U)
#define SPI_TXCFG_DIV_VALUE_8           (8U)
#define SPI_TXCFG_DIV_VALUE_16          (16U)
#define SPI_TXCFG_DIV_VALUE_32          (32U)
#define SPI_TXCFG_DIV_VALUE_64          (64U)
#define SPI_TXCFG_DIV_VALUE_128         (128U)
//! @}



//! \name All possible pin names
//! @{
#define SPI_PIN_0                       (0U)
#define SPI_PIN_1                       (1U)
#define SPI_PIN_2                       (2U)
#define SPI_PIN_3                       (3U)
#define SPI_PIN_4                       (4U)
#define SPI_PIN_5                       (5U)
#define SPI_PIN_6                       (6U)
#define SPI_PIN_7                       (7U)
#define SPI_PIN_8                       (8U)
#define SPI_PIN_9                       (9U)
#define SPI_PIN_10                      (10U)
#define SPI_PIN_11                      (11U)
#define SPI_PIN_12                      (12U)
#define SPI_PIN_13                      (13U)
#define SPI_PIN_14                      (14U)
#define SPI_PIN_15                      (15U)
#define SPI_PIN_16                      (16U)
#define SPI_PIN_17                      (17U)
#define SPI_PIN_18                      (18U)
#define SPI_PIN_19                      (19U)
#define SPI_PIN_20                      (20U)
#define SPI_PIN_21                      (21U)
#define SPI_PIN_22                      (22U)
#define SPI_PIN_23                      (23U)
#define SPI_PIN_24                      (24U)
#define SPI_PIN_25                      (25U)
#define SPI_PIN_26                      (26U)
#define SPI_PIN_27                      (27U)
#define SPI_PIN_28                      (28U)
#define SPI_PIN_29                      (29U)
#define SPI_PIN_30                      (30U)
#define SPI_PIN_31                      (31U)
#define SPI_PIN_MIN                     (SPI_PIN_0)
#define SPI_PIN_MAX                     (SPI_PIN_31)
#define SPI_PIN_NOT_USED                (255U)

#define SPI_PIN_QNT                     (SPI_PIN_MAX + 1U)
//! @}



//! \name Pin pull-up modes
//! @{
#define SPI_PULLUP_MODE_DISABLE         (0U)
#define SPI_PULLUP_MODE_ENABLE          (1U)
//! @}



//! \name Pin output modes
//! @{
#define SPI_OUTPUT_MODE_OPEN_DRAIN      (0U)
#define SPI_OUTPUT_MODE_PUSH_PULL       (1U)
//! @}



//! \name SPI channels definitions
//! @{
#define SPI_CHANNEL_0                   (0U)
#define SPI_CHANNEL_1                   (1U)
#define SPI_CHANNEL_2                   (2U)
#define SPI_CHANNEL_3                   (3U)
#define SPI_CHANNEL_4                   (4U)
#define SPI_CHANNEL_5                   (5U)
#define SPI_CHANNEL_MIN                 (SPI_CHANNEL_0)
#define SPI_CHANNEL_MAX                 (SPI_CHANNEL_5)

#define SPI_CHANNEL_QTY                 (SPI_CHANNEL_MAX + 1U)
//! @}



//! \name CS state
//! @{
#define SPI_CS_ACTIVE                   (LOGIC_0)
#define SPI_CS_INACTIVE                 (LOGIC_1)
//! @}



//! \name Bit states
//! @{
#define SPI_BIT_SET                     (1U)
#define SPI_BIT_CLR                     (0U)
//! @}



//! \name IPC spi control indexes
//! @{
#define SPI_IPC_SPI0_INDEX              (42U)
#define SPI_IPC_SPI1_INDEX              (43U)
#define SPI_IPC_SPI2_INDEX              (44U)
#define SPI_IPC_SPI3_INDEX              (45U)
#define SPI_IPC_SPI4_INDEX              (46U)
#define SPI_IPC_SPI5_INDEX              (47U)

#define SPI_IPC_INDEX_MIN               (SPI_IPC_SPI0_INDEX)
#define SPI_IPC_INDEX_MAX               (SPI_IPC_SPI5_INDEX)
//! @}


//! \name IPC gpio port control indexes
//! @{
#define SPI_IPC_PCTRL_GPIO_INDEX        (17U)
#define SPI_IPC_PCTRLA_INDEX            (18U)
#define SPI_IPC_PCTRLB_INDEX            (19U)
#define SPI_IPC_PCTRLC_INDEX            (20U)
#define SPI_IPC_PCTRLD_INDEX            (21U)
#define SPI_IPC_PCTRLE_INDEX            (22U)
//! @}

//! \name SPI Channel Settings
//! @{
#define SPI_MAX_BAUDRATE                (5000000UL)
#define SPI_MIN_BAUDRATE                (1000UL)
#define SPI_MAX_POLARITY_VALUE          (3U)
#define SPI_MAX_PHASE_VALUE             (3U)
#define SPI_MAX_BIT_ORDER_VALUE         (1U)
//! @}



//! \name Data size
//! @{
#define SPI_DATA_SIZE_4                 (4U)
#define SPI_DATA_SIZE_5                 (5U)
#define SPI_DATA_SIZE_6                 (6U)
#define SPI_DATA_SIZE_7                 (7U)
#define SPI_DATA_SIZE_8                 (8U)
#define SPI_DATA_SIZE_9                 (9U)
#define SPI_DATA_SIZE_10                (10U)
#define SPI_DATA_SIZE_11                (11U)
#define SPI_DATA_SIZE_12                (12U)
#define SPI_DATA_SIZE_13                (13U)
#define SPI_DATA_SIZE_14                (14U)
#define SPI_DATA_SIZE_15                (15U)
#define SPI_DATA_SIZE_16                (16U)
#define SPI_DATA_SIZE_20                (20U)
#define SPI_DATA_SIZE_24                (24U)
#define SPI_DATA_SIZE_32                (32U)

#define SPI_DATA_SIZE_MIN               (SPI_DATA_SIZE_4)
#define SPI_DATA_SIZE_MAX               (SPI_DATA_SIZE_32)
//! @}



//! \name CS pin number
//! @{
#define SPI_CS_NUM_0                    (0U)
#define SPI_CS_NUM_1                    (1U)
#define SPI_CS_NUM_2                    (2U)
#define SPI_CS_NUM_3                    (3U)
#define SPI_CS_AVAILABLE                (254U)
#define SPI_CS_NOT_AVAILABLE            (255U)

#define SPI_CS_NUM_MIN                  (SPI_CS_NUM_0)
#define SPI_CS_NUM_MAX                  (SPI_CS_NUM_3)
#define SPI_CS_QTY                      (SPI_CS_NUM_MAX + 1U)
//! @}



//! \name SPI CLK settings values
//! @{
#define SPI_CLK_SCKPCS_VALUE    (0xFU)
#define SPI_CLK_PCSSCK_VALUE    (0xFU)
#define SPI_CLK_FMDLY_VALUE     (0xFU)
//! @}



//! \name SPI settings values
//! @{
#define SPI_CFG_CPOL_0                  (0U)
#define SPI_CFG_CPOL_1                  (1U)

#define SPI_CFG_CPHA_0                  (0U)
#define SPI_CFG_CPHA_1                  (1U)

#define SPI_CFG_MASTER                  (1U)
#define SPI_CFG_SLAVE                   (0U)

#define SPI_CFG_BIT_ORDER_LSB_FIRST     (1U)
#define SPI_CFG_BIT_ORDER_MSB_FIRST     (0U)
//! @}



#endif  // #ifndef SPI_DRV_TYPES_H

//****************************************** end of file *******************************************
