//**************************************************************************************************
// @Module  TODO
//! \file   gpio_drv_types.h
//! \brief  Constants for GPIO driver configuration
//!
//! \par    History
//! | Date       | Version | Author  | Comment
//! |:----------:|:-------:|:-------:|--------------------------------------------------------------
//! | 18.05.2023 |  1.0.0  |   XXX   | First release.
//**************************************************************************************************

#ifndef GPIO_DRV_TYPES_H
#define GPIO_DRV_TYPES_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Get data types
#include "compiler.h"

// Get generic definitions
#include "general.h"

// Get configuration of the program module
#include "gpio_drv.h"



//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************

typedef void (*GPIO_ISR_HANDLER)(const U8 nEventID);



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

#ifndef ON
    #define ON                          (1U)
#endif
#ifndef OFF
    #define OFF                         (0U)
#endif

//! \name GPIO ports name definitions
//! @{
#define GPIO_PORT_FIRST                             (GPIO_PORT_A)
#define GPIO_PORT_A                                 (0U)
#define GPIO_PORT_B                                 (1U)
#define GPIO_PORT_C                                 (2U)
#define GPIO_PORT_D                                 (3U)
#define GPIO_PORT_E                                 (4U)
#define GPIO_PORT_LAST                              (GPIO_PORT_E)
//! Quantity of ports
#define GPIO_PORTS_QTY                              (GPIO_PORT_LAST + 1U)
// @}

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

//! Do not modify this constants!
//! \name Pin multiplexer constants
//! @{
#define GPIO_MUX_ALT_0                             (0U)
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

//! \name GPIO interrupt events
//! @{
#define GPIO_IT_DISABLE                             (0U)
#define GPIO_IT_DMA_RISING                          (1U)
#define GPIO_IT_DMA_FALLING                         (2U)
#define GPIO_IT_DMA_EITHER                          (3U)
#define GPIO_IT_LOW                                 (8U)
#define GPIO_IT_RISING                              (9U)
#define GPIO_IT_FALLING                             (10U)
#define GPIO_IT_EITHER                              (11U)
#define GPIO_IT_HIGH                                (12U)
//! @}

//! WakeUp enable
#define GPIO_WKU_ENABLE                             (1U)
//! WakeUp disable
#define GPIO_WKU_DISABLE                            (0U)

// Do not modify this constants!
//! \name GPIO Wake Up Pin names
//! @{
#define GPIO_WKU_PIN_0                                  (0U)
#define GPIO_WKU_PIN_1                                  (1U)
#define GPIO_WKU_PIN_2                                  (2U)
#define GPIO_WKU_PIN_3                                  (3U)
#define GPIO_WKU_PIN_4                                  (4U)
#define GPIO_WKU_PIN_5                                  (5U)
#define GPIO_WKU_PIN_6                                  (6U)
#define GPIO_WKU_PIN_7                                  (7U)
#define GPIO_WKU_PIN_8                                  (8U)
#define GPIO_WKU_PIN_9                                  (9U)
#define GPIO_WKU_PIN_10                                 (10U)
#define GPIO_WKU_PIN_11                                 (11U)
#define GPIO_WKU_PIN_12                                 (12U)
#define GPIO_WKU_PIN_13                                 (13U)
#define GPIO_WKU_PIN_14                                 (14U)
#define GPIO_WKU_PIN_15                                 (15U)
#define GPIO_WKU_PIN_16                                 (16U)
#define GPIO_WKU_PIN_17                                 (17U)
#define GPIO_WKU_PIN_18                                 (18U)
#define GPIO_WKU_PIN_19                                 (19U)
#define GPIO_WKU_PIN_20                                 (20U)
#define GPIO_WKU_PIN_21                                 (21U)
#define GPIO_WKU_PIN_22                                 (22U)
#define GPIO_WKU_PIN_23                                 (23U)
#define GPIO_WKU_PIN_24                                 (24U)
#define GPIO_WKU_PIN_25                                 (25U)
#define GPIO_WKU_PIN_26                                 (26U)
#define GPIO_WKU_PIN_27                                 (27U)
#define GPIO_WKU_PIN_28                                 (28U)
#define GPIO_WKU_PIN_29                                 (29U)
#define GPIO_WKU_PIN_30                                 (30U)
#define GPIO_WKU_PIN_31                                 (31U)
//! Special value for wrong WKU pin
#define GPIO_WKU_INVALID_PIN                            (255U)
//! @}



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
