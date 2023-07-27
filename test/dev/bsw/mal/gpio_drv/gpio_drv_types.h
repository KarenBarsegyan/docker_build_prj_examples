//**************************************************************************************************
// @Module  GPIO
//! \file   gpio_drv_types.h
//! \brief  Constants for GPIO module configuration
//!
//! \par    History
//! | Date       | Version | Author  | Comment
//! |:----------:|:-------:|:-------:|--------------------------------------------------------------
//! | 18.05.2023 |  1.0.0  |   CAV   | First release.
//**************************************************************************************************

#ifndef GPIO_DRV_TYPES_H
#define GPIO_DRV_TYPES_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// None



//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************

// None



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

//! \name Pins names definitions
//! @{
#define GPIO_PIN_FIRST                              (GPIO_PIN_0)
#define GPIO_PIN_0                                  (0U)
#define GPIO_PIN_1                                  (1U)
#define GPIO_PIN_2                                  (2U)
#define GPIO_PIN_3                                  (3U)
#define GPIO_PIN_4                                  (4U)
#define GPIO_PIN_5                                  (5U)
#define GPIO_PIN_6                                  (6U)
#define GPIO_PIN_7                                  (7U)
#define GPIO_PIN_8                                  (8U)
#define GPIO_PIN_9                                  (9U)
#define GPIO_PIN_10                                 (10U)
#define GPIO_PIN_11                                 (11U)
#define GPIO_PIN_12                                 (12U)
#define GPIO_PIN_13                                 (13U)
#define GPIO_PIN_14                                 (14U)
#define GPIO_PIN_15                                 (15U)
#define GPIO_PIN_16                                 (16U)
#define GPIO_PIN_17                                 (17U)
#define GPIO_PIN_18                                 (18U)
#define GPIO_PIN_19                                 (19U)
#define GPIO_PIN_20                                 (20U)
#define GPIO_PIN_21                                 (21U)
#define GPIO_PIN_22                                 (22U)
#define GPIO_PIN_23                                 (23U)
#define GPIO_PIN_24                                 (24U)
#define GPIO_PIN_25                                 (25U)
#define GPIO_PIN_26                                 (26U)
#define GPIO_PIN_27                                 (27U)
#define GPIO_PIN_28                                 (28U)
#define GPIO_PIN_29                                 (29U)
#define GPIO_PIN_30                                 (30U)
#define GPIO_PIN_31                                 (31U)
#define GPIO_PIN_LAST                               (GPIO_PIN_31)
//! Quantity of pins
#define GPIO_PINS_QTY                               (GPIO_PIN_LAST + 1U)
//! @}

//! \name Pin multiplexer constants
//! @{
//! Analog function, digital function is disabled
#define GPIO_MUX_ALT_0                             (0U)
//! GPIO function
#define GPIO_MUX_ALT_1                             (1U)
#define GPIO_MUX_ALT_2                             (2U)
#define GPIO_MUX_ALT_3                             (3U)
#define GPIO_MUX_ALT_4                             (4U)
#define GPIO_MUX_ALT_5                             (5U)
#define GPIO_MUX_ALT_6                             (6U)
#define GPIO_MUX_ALT_7                             (7U)
//! @}

//! \name GPIO setup constants
//! @{
//! GPIO strength enable
#define GPIO_STRENGTH_LOW                          (0U)
#define GPIO_STRENGTH_HIGH                         (1U)
//! GPIO passive filter
#define GPIO_PFE_ENABLE                            (1U)
#define GPIO_PFE_DISABLE                           (0U)
//! GPIO slew rate
#define GPIO_FAST_SLEW_RATE                        (0U)
#define GPIO_SLOW_SLEW_RATE                        (1U)
//! GPIO pull enable
#define GPIO_PULL_ENABLE                           (1U)
#define GPIO_PULL_DISABLE                          (0U)
//! GPIO pull mode
#define GPIO_PULL_DOWN                              (0U)
#define GPIO_PULL_UP                                (1U)
//! @}

//! WakeUp enable
#define GPIO_WKU_ENABLE                             (1U)
//! WakeUp disable
#define GPIO_WKU_DISABLE                            (0U)

#define GPIO_WKU_0                                  (0U)
#define GPIO_WKU_1                                  (1U)
#define GPIO_WKU_2                                  (2U)
#define GPIO_WKU_3                                  (3U)
#define GPIO_WKU_4                                  (4U)
#define GPIO_WKU_5                                  (5U)
#define GPIO_WKU_6                                  (6U)
#define GPIO_WKU_7                                  (7U)
#define GPIO_WKU_8                                  (8U)
#define GPIO_WKU_9                                  (9U)
#define GPIO_WKU_10                                 (10U)
#define GPIO_WKU_11                                 (11U)
#define GPIO_WKU_12                                 (12U)
#define GPIO_WKU_13                                 (13U)
#define GPIO_WKU_14                                 (14U)
#define GPIO_WKU_15                                 (15U)
#define GPIO_WKU_16                                 (16U)
#define GPIO_WKU_17                                 (17U)
#define GPIO_WKU_18                                 (18U)
#define GPIO_WKU_19                                 (19U)
#define GPIO_WKU_20                                 (20U)
#define GPIO_WKU_21                                 (21U)
#define GPIO_WKU_22                                 (22U)
#define GPIO_WKU_23                                 (23U)
#define GPIO_WKU_24                                 (24U)
#define GPIO_WKU_25                                 (25U)
#define GPIO_WKU_26                                 (26U)
#define GPIO_WKU_27                                 (27U)
#define GPIO_WKU_28                                 (28U)
#define GPIO_WKU_29                                 (29U)
#define GPIO_WKU_30                                 (30U)
#define GPIO_WKU_31                                 (31U)
//! Special value for wrong WKU pin
#define GPIO_WKU_INVALID_PIN                            (255U)


//! \name GPIO port name of the WakeUp pin
//! @{
#define GPIO_WKU_0_PORT          GPIO_PORT_E
#define GPIO_WKU_1_PORT          GPIO_PORT_E
#define GPIO_WKU_2_PORT          GPIO_PORT_E
#define GPIO_WKU_3_PORT          GPIO_PORT_E
#define GPIO_WKU_4_PORT          GPIO_PORT_E
#define GPIO_WKU_5_PORT          GPIO_PORT_E
#define GPIO_WKU_6_PORT          GPIO_PORT_E
#define GPIO_WKU_7_PORT          GPIO_PORT_E
#define GPIO_WKU_8_PORT          GPIO_PORT_E
#define GPIO_WKU_9_PORT          GPIO_PORT_C
#define GPIO_WKU_10_PORT          GPIO_PORT_C
#define GPIO_WKU_11_PORT          GPIO_PORT_D
#define GPIO_WKU_12_PORT          GPIO_PORT_C
#define GPIO_WKU_13_PORT          GPIO_PORT_C
#define GPIO_WKU_14_PORT          GPIO_PORT_C
#define GPIO_WKU_15_PORT          GPIO_PORT_C
#define GPIO_WKU_16_PORT          GPIO_PORT_B
#define GPIO_WKU_17_PORT          GPIO_PORT_B
#define GPIO_WKU_18_PORT          GPIO_PORT_A
#define GPIO_WKU_19_PORT          GPIO_PORT_A
#define GPIO_WKU_20_PORT          GPIO_PORT_B
#define GPIO_WKU_21_PORT          GPIO_PORT_B
#define GPIO_WKU_22_PORT          GPIO_PORT_D
#define GPIO_WKU_23_PORT          GPIO_PORT_D
#define GPIO_WKU_24_PORT          GPIO_PORT_A
#define GPIO_WKU_25_PORT          GPIO_PORT_A
#define GPIO_WKU_26_PORT          GPIO_PORT_C
#define GPIO_WKU_27_PORT          GPIO_PORT_C
#define GPIO_WKU_28_PORT          GPIO_PORT_E
#define GPIO_WKU_29_PORT          GPIO_PORT_E
#define GPIO_WKU_30_PORT          GPIO_PORT_A
#define GPIO_WKU_31_PORT          GPIO_PORT_A
//! @}

//! \name GPIO pin number of the WakeUp pin
//! @{
#define GPIO_WKU_0_PIN           GPIO_PIN_11
#define GPIO_WKU_1_PIN           GPIO_PIN_10
#define GPIO_WKU_2_PIN           GPIO_PIN_5
#define GPIO_WKU_3_PIN           GPIO_PIN_4
#define GPIO_WKU_4_PIN           GPIO_PIN_3
#define GPIO_WKU_5_PIN           GPIO_PIN_1
#define GPIO_WKU_6_PIN           GPIO_PIN_0
#define GPIO_WKU_7_PIN           GPIO_PIN_9
#define GPIO_WKU_8_PIN           GPIO_PIN_8
#define GPIO_WKU_9_PIN           GPIO_PIN_3
#define GPIO_WKU_10_PIN           GPIO_PIN_2
#define GPIO_WKU_11_PIN           GPIO_PIN_5
#define GPIO_WKU_12_PIN           GPIO_PIN_1
#define GPIO_WKU_13_PIN           GPIO_PIN_0
#define GPIO_WKU_14_PIN           GPIO_PIN_15
#define GPIO_WKU_15_PIN           GPIO_PIN_14
#define GPIO_WKU_16_PIN           GPIO_PIN_1
#define GPIO_WKU_17_PIN           GPIO_PIN_0
#define GPIO_WKU_18_PIN           GPIO_PIN_7
#define GPIO_WKU_19_PIN           GPIO_PIN_6
#define GPIO_WKU_20_PIN           GPIO_PIN_13
#define GPIO_WKU_21_PIN           GPIO_PIN_12
#define GPIO_WKU_22_PIN           GPIO_PIN_3
#define GPIO_WKU_23_PIN           GPIO_PIN_2
#define GPIO_WKU_24_PIN           GPIO_PIN_3
#define GPIO_WKU_25_PIN           GPIO_PIN_2
#define GPIO_WKU_26_PIN           GPIO_PIN_7
#define GPIO_WKU_27_PIN           GPIO_PIN_6
#define GPIO_WKU_28_PIN           GPIO_PIN_6
#define GPIO_WKU_29_PIN           GPIO_PIN_2
#define GPIO_WKU_30_PIN           GPIO_PIN_13
#define GPIO_WKU_31_PIN           GPIO_PIN_12
//! @}
//! \name WakeUp event conditions
//! @{
#define GPIO_WU_DISABLE                 (0U)
#define GPIO_WU_RISING_EDGE             (1U)
#define GPIO_WU_FALLING_EDGE            (2U)
#define GPIO_WU_RISING_OR_FALLING_EDGE  (3U)
//! @}

//! \name IPC pin control indexes
//! @{
#define GPIO_IPC_INDEX              (17U)
#define GPIO_IPC_PCTRLA_INDEX       (18U)
#define GPIO_IPC_PCTRLB_INDEX       (19U)
#define GPIO_IPC_PCTRLC_INDEX       (20U)
#define GPIO_IPC_PCTRLD_INDEX       (21U)
#define GPIO_IPC_PCTRLE_INDEX       (22U)
#define GPIO_IPC_WKU_INDEX          (98U)
//! @}

//! \name GPIO registers reset value
//! @{
#define GPIO_PDOR_RESET_VALUE         (0x00000000UL)
#define GPIO_PSOR_RESET_VALUE         (0x00000000UL)
#define GPIO_PDIR_RESET_VALUE         (0x00000000UL)
#define GPIO_POER_RESET_VALUE         (0x00000000UL)
#define GPIO_PIER_RESET_VALUE         (0xFFFFFFFFUL)
#define GPIO_PIFR_RESET_VALUE         (0x00000000UL)
#define GPIO_PCR_RESET_VALUE          (0x00000000UL)
//! @}

//! PCTRL registers value after reset (MUX=1, FAST)
#define PCTRL_PCR_RESET_VALUE        (0x00000100UL)



//**************************************************************************************************
// Declarations of global (public) variables
//**************************************************************************************************

// None



//**************************************************************************************************
// Declarations of global (public) functions
//**************************************************************************************************

// None



#endif // #ifndef GPIO_DRV_TYPES_H

//****************************************** end of file *******************************************
