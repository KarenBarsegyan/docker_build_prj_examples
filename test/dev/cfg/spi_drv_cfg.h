//**************************************************************************************************
// @Module  SPI driver
//! \file   spi_drv_cfg.h
//! \par    Platform
//!             YTM32
//! \par    Compatible
//!             YTM32B1M families
//! \brief  This file contains configuration of the SPI module.
//!
//! \par    Abbreviations
//!             SPI - Serial Peripheral Interface
//! \par    History
//! | Date       | Version | Author  | Comment
//! |:----------:|:-------:|:-------:|--------------------------------------------------------------
//! | 00.00.2023 |  1.0.0  |   BKR   | First release.
//**************************************************************************************************

#ifndef SPI_DRV_CFG_H
#define SPI_DRV_CFG_H



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

//! Enable/disable the development error detection feature of the SPI module.
//! Used only for debug purposes and should be disabled in the final release.
//! Valid values: ON / OFF
#define SPI_DEVELOPMENT_ERROR_DETECTION                 (OFF)

//! Sizes of the FIFO buffers.
//! Valid values: 1...255
#define SPI_CHANNEL_RX_FIFO_SIZE                        (32U)
#define SPI_CHANNEL_TX_FIFO_SIZE                        (32U)



//--------------------------------------------------------------------------------------------------
//----------------------------- Example SPI_CHANNEL_x settings -------------------------------------
//--------------------------------------------------------------------------------------------------

//! Enable or Disable SPI channel X
//! Valid values: ON / OFF
//! #define SPI_CHANNEL_X_IN_USE                            (OFF)

//! Specify SPI channel X mode
//! Valid values: SPI_MODE_MASTER, SPI_MODE_SLAVE
//! #define SPI_CHANNEL_X_MODE                              (SPI_MODE_MASTER)

//! Specify SPI channel X boudrate
//! Valid values: 0...120_000_000
//! #define SPI_CHANNEL_X_BAUDRATE                          (500000UL)

//--------------------------------------------------------------------------------------------------

//! Specify MOSI port
//! Valid values: SPI_PORT_A...SPI_PORT_E
//! #define SPI_CHANNEL_X_MOSI_PORT                         (SPI_PORT_A)

//! Specify MOSI pin
//! Valid values: 0...15
//! #define SPI_CHANNEL_X_MOSI_PIN                          (0U)

//! Specify MOSI pin type
//! Valid values: SPI_OUTPUT_MODE_PUSH_PULL,
//!               SPI_OUTPUT_MODE_OPEN_DRAIN
//! #define SPI_CHANNEL_X_MOSI_OUTPUT_MODE                  (SPI_OUTPUT_MODE_PUSH_PULL)

//! Specify MOSI pin pull-up
//! Valid values: SPI_PULLUP_MODE_DISABLE,
//!               SPI_PULLUP_MODE_ENABLE
//! #define SPI_CHANNEL_X_MOSI_PULLUP_MODE                  (SPI_PULLUP_MODE_DISABLE)

//--------------------------------------------------------------------------------------------------

//! Specify MISO port
//! Valid values: SPI_PORT_A...SPI_PORT_E
//! #define SPI_CHANNEL_X_MISO_PORT                         (SPI_PORT_A)

//! Specify MISO pin
//! Valid values: 0...15
//! #define SPI_CHANNEL_X_MISO_PIN                          (0U)

//! Specify MISO pin type
//! Valid values: SPI_OUTPUT_MODE_PUSH_PULL,
//!               SPI_OUTPUT_MODE_OPEN_DRAIN
//! #define SPI_CHANNEL_X_MISO_OUTPUT_MODE                  (SPI_OUTPUT_MODE_PUSH_PULL)

//! Specify MISO pin pull-up
//! Valid values: SPI_PULLUP_MODE_DISABLE,
//!               SPI_PULLUP_MODE_ENABLE
//! #define SPI_CHANNEL_X_MISO_PULLUP_MODE                  (SPI_PULLUP_MODE_DISABLE)

//--------------------------------------------------------------------------------------------------

//! Specify SCLK port
//! Valid values: SPI_PORT_A...SPI_PORT_E
//! #define SPI_CHANNEL_X_SCLK_PORT                         (SPI_PORT_A)

//! Specify SCLK pin
//! Valid values: 0...15
//! #define SPI_CHANNEL_X_SCLK_PIN                          (0U)

//! Specify SCLK pin type
//! Valid values: SPI_OUTPUT_MODE_PUSH_PULL,
//!               SPI_OUTPUT_MODE_OPEN_DRAIN
//! #define SPI_CHANNEL_X_SCLK_OUTPUT_MODE                  (SPI_OUTPUT_MODE_PUSH_PULL)

//! Specify SCLK pin pull-up
//! Valid values: SPI_PULLUP_MODE_DISABLE,
//!               SPI_PULLUP_MODE_ENABLE
//! #define SPI_CHANNEL_X_SCLK_PULLUP_MODE                  (SPI_PULLUP_MODE_DISABLE)

//--------------------------------------------------------------------------------------------------

//! Specify CS port
//! Valid values: SPI_PORT_A...SPI_PORT_E
//! #define SPI_CHANNEL_X_SCLK_PORT                         (SPI_PORT_A)

//! Specify CS pin
//! Valid values: 0...15
//! #define SPI_CHANNEL_X_SCLK_PIN                          (0U)

//! Specify CS pin type
//! Valid values: SPI_OUTPUT_MODE_PUSH_PULL,
//!               SPI_OUTPUT_MODE_OPEN_DRAIN
//! #define SPI_CHANNEL_X_SCLK_OUTPUT_MODE                  (SPI_OUTPUT_MODE_PUSH_PULL)

//! Specify CS pin pull-up
//! Valid values: SPI_PULLUP_MODE_DISABLE,
//!               SPI_PULLUP_MODE_ENABLE
//! #define SPI_CHANNEL_X_SCLK_PULLUP_MODE                  (SPI_PULLUP_MODE_DISABLE)



//--------------------------------------------------------------------------------------------------
//-------------------------------------------- SPI0 ------------------------------------------------
//--------------------------------------------------------------------------------------------------
#define SPI_CHANNEL_0_IN_USE                    (ON)
#define SPI_CHANNEL_0_MODE                      (SPI_MODE_MASTER)
#define SPI_CHANNEL_0_BAUDRATE                  (5000UL)

// MOSI - Port and Pin settings
// Valid Ports and Pins:
// PTA_30, PTB_1, PTB_4, PTE_2
#define SPI_CHANNEL_0_MOSI_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_0_MOSI_PIN                  (30U)
#define SPI_CHANNEL_0_MOSI_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_0_MOSI_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// MISO - Port and Pin settings
// Valid Ports and Pins:
// PTB_3, PTD_16, PTE_1
#define SPI_CHANNEL_0_MISO_PORT                 (SPI_PORT_D)
#define SPI_CHANNEL_0_MISO_PIN                  (16U)
#define SPI_CHANNEL_0_MISO_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_0_MISO_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// SCLK - Port and Pin settings
// Valid Ports and Pins:
// PTB_2, PTC_23, PTD_15, PTE_0
#define SPI_CHANNEL_0_SCLK_PORT                 (SPI_PORT_D)
#define SPI_CHANNEL_0_SCLK_PIN                  (15U)
#define SPI_CHANNEL_0_SCLK_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_0_SCLK_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// Hardware SPI CS 0 Port and Pin settings
// Valid Ports and Pins:
// PTA_26, PTB_0, PTB_5
#define SPI_CHANNEL_0_CS_0_IN_USE               (ON)
#define SPI_CHANNEL_0_CS_0_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_0_CS_0_PIN                  (26U)
#define SPI_CHANNEL_0_CS_0_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_0_CS_0_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// Hardware SPI CS 1 Port and Pin settings
// Valid Ports and Pins:
// PTA_31, PTB_5
#define SPI_CHANNEL_0_CS_1_IN_USE               (OFF)
#define SPI_CHANNEL_0_CS_1_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_0_CS_1_PIN                  (31U)
#define SPI_CHANNEL_0_CS_1_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_0_CS_1_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// Hardware SPI CS 2 Port and Pin settings
// Valid Ports and Pins:
// PTE_6
#define SPI_CHANNEL_0_CS_2_IN_USE               (OFF)
#define SPI_CHANNEL_0_CS_2_PORT                 (SPI_PORT_E)
#define SPI_CHANNEL_0_CS_2_PIN                  (6U)
#define SPI_CHANNEL_0_CS_2_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_0_CS_2_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// Hardware SPI CS 3 Port and Pin settings
// Valid Ports and Pins:
// PTA_15
#define SPI_CHANNEL_0_CS_3_IN_USE               (OFF)
#define SPI_CHANNEL_0_CS_3_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_0_CS_3_PIN                  (15U)
#define SPI_CHANNEL_0_CS_3_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_0_CS_3_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)



//--------------------------------------------------------------------------------------------------
//-------------------------------------------- SPI1 ------------------------------------------------
//--------------------------------------------------------------------------------------------------
#define SPI_CHANNEL_1_IN_USE                    (ON)
#define SPI_CHANNEL_1_MODE                      (SPI_MODE_SLAVE)
#define SPI_CHANNEL_1_BAUDRATE                  (10000UL)

// MOSI - Port and Pin settings
// Valid Ports and Pins:
// PTA_27, PTB_16, PTD_2, PTE_0
#define SPI_CHANNEL_1_MOSI_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_1_MOSI_PIN                  (27U)
#define SPI_CHANNEL_1_MOSI_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_1_MOSI_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// MISO - Port and Pin settings
// Valid Ports and Pins:
// PTA_29, PTB_15, PTE_3
#define SPI_CHANNEL_1_MISO_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_1_MISO_PIN                  (29U)
#define SPI_CHANNEL_1_MISO_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_1_MISO_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// SCLK - Port and Pin settings
// Valid Ports and Pins:
// PTA_28, PTB_14, PTE_9
#define SPI_CHANNEL_1_SCLK_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_1_SCLK_PIN                  (28U)
#define SPI_CHANNEL_1_SCLK_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_1_SCLK_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// Hardware SPI CS 0 Port and Pin settings
// Valid Ports and Pins:
// PTA_26, PTD_3, PTE_1
#define SPI_CHANNEL_1_CS_0_IN_USE               (ON)
#define SPI_CHANNEL_1_CS_0_PORT                 (SPI_PORT_E)
#define SPI_CHANNEL_1_CS_0_PIN                  (1U)
#define SPI_CHANNEL_1_CS_0_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_1_CS_0_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// Hardware SPI CS 1 Port and Pin settings
// Valid Ports and Pins:
// PTA_6, PTB_18
#define SPI_CHANNEL_1_CS_1_IN_USE               (OFF)
#define SPI_CHANNEL_1_CS_1_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_1_CS_1_PIN                  (0U)
#define SPI_CHANNEL_1_CS_1_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_1_CS_1_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// Hardware SPI CS 2 Port and Pin settings
// Valid Ports and Pins:
// PTA_16 
#define SPI_CHANNEL_1_CS_2_IN_USE               (OFF)
#define SPI_CHANNEL_1_CS_2_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_1_CS_2_PIN                  (0U)
#define SPI_CHANNEL_1_CS_2_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_1_CS_2_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// Hardware SPI CS 3 Port and Pin settings
// Valid Ports and Pins:
// PTB_17
#define SPI_CHANNEL_1_CS_3_IN_USE               (OFF)
#define SPI_CHANNEL_1_CS_3_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_1_CS_3_PIN                  (0U)
#define SPI_CHANNEL_1_CS_3_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_1_CS_3_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)



//--------------------------------------------------------------------------------------------------
//-------------------------------------------- SPI2 ------------------------------------------------
//--------------------------------------------------------------------------------------------------
#define SPI_CHANNEL_2_IN_USE                    (OFF)
#define SPI_CHANNEL_2_MODE                      (SPI_MODE_MASTER)
#define SPI_CHANNEL_2_BAUDRATE                  (500000UL)

// MOSI - Port and Pin settings
// Valid Ports and Pins:
// PTA_8, PTB_27, PTC_1
#define SPI_CHANNEL_2_MOSI_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_2_MOSI_PIN                  (0U)
#define SPI_CHANNEL_2_MOSI_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_2_MOSI_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// MISO - Port and Pin settings
// Valid Ports and Pins:
// PTB_28, PTC_0, PTE_16
#define SPI_CHANNEL_2_MISO_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_2_MISO_PIN                  (0U)
#define SPI_CHANNEL_2_MISO_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_2_MISO_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// SCLK - Port and Pin settings
// Valid Ports and Pins:
// PTB_29, PTC_15, PTE_15
#define SPI_CHANNEL_2_SCLK_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_2_SCLK_PIN                  (0U)
#define SPI_CHANNEL_2_SCLK_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_2_SCLK_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// Hardware SPI CS 0 Port and Pin settings
// Valid Ports and Pins:
// PTA_9, PTB_25, PTC_14, PTE_11
#define SPI_CHANNEL_2_CS_0_IN_USE               (OFF)
#define SPI_CHANNEL_2_CS_0_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_2_CS_0_PIN                  (0U)
#define SPI_CHANNEL_2_CS_0_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_2_CS_0_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// Hardware SPI CS 1 Port and Pin settings
// Valid Ports and Pins:
// PTC_19, PTE_10
#define SPI_CHANNEL_2_CS_1_IN_USE               (OFF)
#define SPI_CHANNEL_2_CS_1_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_2_CS_1_PIN                  (0U)
#define SPI_CHANNEL_2_CS_1_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_2_CS_1_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// Hardware SPI CS 2 Port and Pin settings
// Valid Ports and Pins:
// PTE_13
#define SPI_CHANNEL_2_CS_2_IN_USE               (OFF)
#define SPI_CHANNEL_2_CS_2_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_2_CS_2_PIN                  (0U)
#define SPI_CHANNEL_2_CS_2_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_2_CS_2_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// Hardware SPI CS 3 Port and Pin settings
// Valid Ports and Pins:
// PTA_15
#define SPI_CHANNEL_2_CS_3_IN_USE               (OFF)
#define SPI_CHANNEL_2_CS_3_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_2_CS_3_PIN                  (0U)
#define SPI_CHANNEL_2_CS_3_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_2_CS_3_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)



//--------------------------------------------------------------------------------------------------
//-------------------------------------------- SPI3 ------------------------------------------------
//--------------------------------------------------------------------------------------------------
#define SPI_CHANNEL_3_IN_USE                    (OFF)
#define SPI_CHANNEL_3_MODE                      (SPI_MODE_MASTER)
#define SPI_CHANNEL_3_BAUDRATE                  (500000UL)

// MOSI - Port and Pin settings
// Valid Ports and Pins:
// PTA_10, PTE_3
#define SPI_CHANNEL_3_MOSI_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_3_MOSI_PIN                  (0U)
#define SPI_CHANNEL_3_MOSI_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_3_MOSI_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// MISO - Port and Pin settings
// Valid Ports and Pins:
// PTA_11, PTB_6
#define SPI_CHANNEL_3_MISO_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_3_MISO_PIN                  (0U)
#define SPI_CHANNEL_3_MISO_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_3_MISO_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// SCLK - Port and Pin settings
// Valid Ports and Pins:
// PTA_12, PTB_7
#define SPI_CHANNEL_3_SCLK_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_3_SCLK_PIN                  (0U)
#define SPI_CHANNEL_3_SCLK_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_3_SCLK_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// Hardware SPI CS 0 Port and Pin settings
// Valid Ports and Pins:
// PTA_13, PTE_12
#define SPI_CHANNEL_3_CS_0_IN_USE               (OFF)
#define SPI_CHANNEL_3_CS_0_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_3_CS_0_PIN                  (0U)
#define SPI_CHANNEL_3_CS_0_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_3_CS_0_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// Hardware SPI CS 1 Port and Pin settings
// Valid Ports and Pins:
// PTC_5, PTE_8
#define SPI_CHANNEL_3_CS_1_IN_USE               (OFF)
#define SPI_CHANNEL_3_CS_1_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_3_CS_1_PIN                  (0U)
#define SPI_CHANNEL_3_CS_1_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_3_CS_1_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)



//--------------------------------------------------------------------------------------------------
//-------------------------------------------- SPI4 ------------------------------------------------
//--------------------------------------------------------------------------------------------------
#define SPI_CHANNEL_4_IN_USE                    (OFF)
#define SPI_CHANNEL_4_MODE                      (SPI_MODE_MASTER)
#define SPI_CHANNEL_4_BAUDRATE                  (500000UL)

// MOSI - Port and Pin settings
// Valid Ports and Pins:
// PTC_14, PTD_6
#define SPI_CHANNEL_4_MOSI_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_4_MOSI_PIN                  (0U)
#define SPI_CHANNEL_4_MOSI_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_4_MOSI_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// MISO - Port and Pin settings
// Valid Ports and Pins:
// PTC_15, PTD_7
#define SPI_CHANNEL_4_MISO_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_4_MISO_PIN                  (0U)
#define SPI_CHANNEL_4_MISO_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_4_MISO_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// SCLK - Port and Pin settings
// Valid Ports and Pins:
// PTC_2, PTC_16
#define SPI_CHANNEL_4_SCLK_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_4_SCLK_PIN                  (0U)
#define SPI_CHANNEL_4_SCLK_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_4_SCLK_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// Hardware SPI CS 0 Port and Pin settings
// Valid Ports and Pins:
// PTC_3, PTC_17
#define SPI_CHANNEL_4_CS_0_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_4_CS_0_PIN                  (0U)
#define SPI_CHANNEL_4_CS_0_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_4_CS_0_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// Hardware SPI CS 1 Port and Pin settings
// Valid Ports and Pins:
// PTB_25, PTD_5
#define SPI_CHANNEL_4_CS_1_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_4_CS_1_PIN                  (0U)
#define SPI_CHANNEL_4_CS_1_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_4_CS_1_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)



//--------------------------------------------------------------------------------------------------
//-------------------------------------------- SPI5 ------------------------------------------------
//--------------------------------------------------------------------------------------------------
#define SPI_CHANNEL_5_IN_USE                    (OFF)
#define SPI_CHANNEL_5_MODE                      (SPI_MODE_MASTER)
#define SPI_CHANNEL_5_BAUDRATE                  (500000UL)

// MOSI - Port and Pin settings
// Valid Ports and Pins:
// PTD_11, PTE_7
#define SPI_CHANNEL_5_MOSI_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_5_MOSI_PIN                  (0U)
#define SPI_CHANNEL_5_MOSI_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_5_MOSI_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// MISO - Port and Pin settings
// Valid Ports and Pins:
// PTA_6, PTD_12
#define SPI_CHANNEL_5_MISO_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_5_MISO_PIN                  (0U)
#define SPI_CHANNEL_5_MISO_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_5_MISO_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// SCLK - Port and Pin settings
// Valid Ports and Pins:
// PTA_7, PTD_10
#define SPI_CHANNEL_5_SCLK_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_5_SCLK_PIN                  (0U)
#define SPI_CHANNEL_5_SCLK_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_5_SCLK_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// Hardware SPI CS 0 Port and Pin settings
// Valid Ports and Pins:
// PTC_8
#define SPI_CHANNEL_3_CS_0_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_3_CS_0_PIN                  (0U)
#define SPI_CHANNEL_3_CS_0_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_3_CS_0_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)

// Hardware SPI CS 1 Port and Pin settings
// Valid Ports and Pins:
// PTC_9
#define SPI_CHANNEL_3_CS_1_PORT                 (SPI_PORT_A)
#define SPI_CHANNEL_3_CS_1_PIN                  (0U)
#define SPI_CHANNEL_3_CS_1_OUTPUT_MODE          (SPI_OUTPUT_MODE_PUSH_PULL)
#define SPI_CHANNEL_3_CS_1_PULLUP_MODE          (SPI_PULLUP_MODE_DISABLE)



#endif // #ifndef SPI_DRV_CFG_H

//****************************************** end of file *******************************************