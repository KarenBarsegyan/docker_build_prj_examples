//**************************************************************************************************
// @Module  GPIO driver
//! \file    gpio_drv.c
//! \par    Platform
//!             YTM32B1ME05
//! \par    Compatible
//!             YTM32B1ME05G0MLHT, YTM32B1ME05G0MLLT, YTM32B1ME05G0MLQT
//! \brief  Implementation of the GPIO driver functionality.
//!
//! \par    Abbreviations
//!                 GPIO - General Purpose Input/Output
//!
//! \par    History
//! | Date       | Version | Author | Comment
//! |:----------:|:-------:|:------:|---------------------------------------------------------------
//! | 08.05.2023 |  1.0.0  |   CAV  | First release.
//**************************************************************************************************

//**************************************************************************************************
//! \defgroup   GPIO_DRV
//! \brief      Implementation of the GPIO driver functionality
//! \addtogroup GPIO_DRV
//! @{
//! \file gpio_drv.h
//! \file gpio_drv.c
//! \file gpio_drv_wku.h
//! \file gpio_drv_wku.c
//! \file gpio_drv_cfg.h.tmpl
//! @}
//**************************************************************************************************



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

//! Get GPIO module interface
#include "gpio_drv.h"
//! Get GPIO module constants
#include "gpio_drv_types.h"
//! Get GPIO module WKU interface
#include "gpio_drv_wku.h"
//! Get registers definitions
#include "derivative_cfg.h"

//! Get error tracer functions
#include "error_tracer.h"



//**************************************************************************************************
// Verification of the imported configuration parameters
//**************************************************************************************************

// Port enable macro for port with 32 pins
#define GPIO_PORT_ENABLE(PortName)                     \
      ((GPIO_PORT_##PortName##_PIN_0_ENABLE  << 0U)  | \
       (GPIO_PORT_##PortName##_PIN_1_ENABLE  << 1U)  | \
       (GPIO_PORT_##PortName##_PIN_2_ENABLE  << 2U)  | \
       (GPIO_PORT_##PortName##_PIN_3_ENABLE  << 3U)  | \
       (GPIO_PORT_##PortName##_PIN_4_ENABLE  << 4U)  | \
       (GPIO_PORT_##PortName##_PIN_5_ENABLE  << 5U)  | \
       (GPIO_PORT_##PortName##_PIN_6_ENABLE  << 6U)  | \
       (GPIO_PORT_##PortName##_PIN_7_ENABLE  << 7U)  | \
       (GPIO_PORT_##PortName##_PIN_8_ENABLE  << 8U)  | \
       (GPIO_PORT_##PortName##_PIN_9_ENABLE  << 9U)  | \
       (GPIO_PORT_##PortName##_PIN_10_ENABLE << 10U) | \
       (GPIO_PORT_##PortName##_PIN_11_ENABLE << 11U) | \
       (GPIO_PORT_##PortName##_PIN_12_ENABLE << 12U) | \
       (GPIO_PORT_##PortName##_PIN_13_ENABLE << 13U) | \
       (GPIO_PORT_##PortName##_PIN_14_ENABLE << 14U) | \
       (GPIO_PORT_##PortName##_PIN_15_ENABLE << 15U) | \
       (GPIO_PORT_##PortName##_PIN_16_ENABLE << 16U) | \
       (GPIO_PORT_##PortName##_PIN_17_ENABLE << 17U) | \
       (GPIO_PORT_##PortName##_PIN_18_ENABLE << 18U) | \
       (GPIO_PORT_##PortName##_PIN_19_ENABLE << 19U) | \
       (GPIO_PORT_##PortName##_PIN_20_ENABLE << 20U) | \
       (GPIO_PORT_##PortName##_PIN_21_ENABLE << 21U) | \
       (GPIO_PORT_##PortName##_PIN_22_ENABLE << 22U) | \
       (GPIO_PORT_##PortName##_PIN_23_ENABLE << 23U) | \
       (GPIO_PORT_##PortName##_PIN_24_ENABLE << 24U) | \
       (GPIO_PORT_##PortName##_PIN_25_ENABLE << 25U) | \
       (GPIO_PORT_##PortName##_PIN_26_ENABLE << 26U) | \
       (GPIO_PORT_##PortName##_PIN_27_ENABLE << 27U) | \
       (GPIO_PORT_##PortName##_PIN_28_ENABLE << 28U) | \
       (GPIO_PORT_##PortName##_PIN_29_ENABLE << 29U) | \
       (GPIO_PORT_##PortName##_PIN_30_ENABLE << 30U) | \
       (GPIO_PORT_##PortName##_PIN_31_ENABLE << 31U))

// Checking off all pins
#if ((OFF == GPIO_PORT_ENABLE(A)) &&    \
     (OFF == GPIO_PORT_ENABLE(B)) &&    \
     (OFF == GPIO_PORT_ENABLE(C)) &&    \
     (OFF == GPIO_PORT_ENABLE(D)) &&    \
     (OFF == GPIO_PORT_ENABLE(E)))

#error "gpio_drv_cfg.h: no input/output is turned ON"

#endif // end of #if ((OFF == GPIO_PORT_ENABLE(X))

// Valid enable macro
#define GPIO_PORT_CORRECT_ENABLE(PortName)             \
      ((ON < GPIO_PORT_##PortName##_PIN_0_ENABLE)   || \
       (ON < GPIO_PORT_##PortName##_PIN_1_ENABLE)   || \
       (ON < GPIO_PORT_##PortName##_PIN_2_ENABLE)   || \
       (ON < GPIO_PORT_##PortName##_PIN_3_ENABLE)   || \
       (ON < GPIO_PORT_##PortName##_PIN_4_ENABLE)   || \
       (ON < GPIO_PORT_##PortName##_PIN_5_ENABLE)   || \
       (ON < GPIO_PORT_##PortName##_PIN_6_ENABLE)   || \
       (ON < GPIO_PORT_##PortName##_PIN_7_ENABLE)   || \
       (ON < GPIO_PORT_##PortName##_PIN_8_ENABLE)   || \
       (ON < GPIO_PORT_##PortName##_PIN_9_ENABLE)   || \
       (ON < GPIO_PORT_##PortName##_PIN_10_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_11_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_12_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_13_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_14_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_15_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_16_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_17_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_18_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_19_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_20_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_21_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_22_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_23_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_24_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_25_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_26_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_27_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_28_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_29_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_30_ENABLE)  || \
       (ON < GPIO_PORT_##PortName##_PIN_31_ENABLE))

// Checking correct enable parameter all pins
#if ((GPIO_PORT_CORRECT_ENABLE(A)) ||    \
     (GPIO_PORT_CORRECT_ENABLE(B)) ||    \
     (GPIO_PORT_CORRECT_ENABLE(C)) ||    \
     (GPIO_PORT_CORRECT_ENABLE(D)) ||    \
     (GPIO_PORT_CORRECT_ENABLE(E)))

#error "gpio_drv_cfg.h: parameter GPIO_PORT_X_PIN_X_ENABLE does not match (ON) or (OFF)"
#endif // end of #if ((GPIO_PORT_CORRECT_ENABLE(X))

// Valid direction macro
#define GPIO_PORT_CORRECT_DIRECTION(PortName)                             \
      (((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_0_DIRECTION)   &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_0_DIRECTION))  ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_1_DIRECTION)   &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_1_DIRECTION))  ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_2_DIRECTION)   &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_2_DIRECTION))  ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_3_DIRECTION)   &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_3_DIRECTION))  ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_4_DIRECTION)   &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_4_DIRECTION))  ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_5_DIRECTION)   &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_5_DIRECTION))  ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_6_DIRECTION)   &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_6_DIRECTION))  ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_7_DIRECTION)   &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_7_DIRECTION))  ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_8_DIRECTION)   &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_8_DIRECTION))  ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_9_DIRECTION)   &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_9_DIRECTION))  ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_10_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_10_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_11_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_11_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_12_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_12_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_13_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_13_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_14_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_14_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_15_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_15_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_16_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_16_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_17_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_17_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_18_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_18_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_19_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_19_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_20_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_20_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_21_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_21_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_22_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_22_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_23_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_23_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_24_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_24_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_25_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_25_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_26_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_26_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_27_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_27_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_28_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_28_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_29_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_29_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_30_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_30_DIRECTION)) ||   \
       ((GPIO_PIN_INPUT != GPIO_PORT_##PortName##_PIN_31_DIRECTION)  &&   \
       (GPIO_PIN_OUTPUT != GPIO_PORT_##PortName##_PIN_31_DIRECTION)))

// Checking direction all pins
#if ((GPIO_PORT_CORRECT_DIRECTION(A)) ||    \
     (GPIO_PORT_CORRECT_DIRECTION(B)) ||    \
     (GPIO_PORT_CORRECT_DIRECTION(C)) ||    \
     (GPIO_PORT_CORRECT_DIRECTION(D)) ||    \
     (GPIO_PORT_CORRECT_DIRECTION(E)))

#error "gpio_drv_cfg.h: parameter GPIO_PORT_X_PIN_X_DIRECTION does not match GPIO_PIN_INPUT or" \
"GPIO_PIN_OUTPUT"

#endif // end of #if ((GPIO_PORT_CORRECT_DIRECTION(X))

// Valid strength macro
#define GPIO_PORT_CORRECT_STRENGTH_LEVEL(PortName)                                \
     (((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_0_STRENGTH_LEVEL)   &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_0_STRENGTH_LEVEL))  ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_1_STRENGTH_LEVEL)   &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_1_STRENGTH_LEVEL))  ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_2_STRENGTH_LEVEL)   &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_2_STRENGTH_LEVEL))  ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_3_STRENGTH_LEVEL)   &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_3_STRENGTH_LEVEL))  ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_4_STRENGTH_LEVEL)   &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_4_STRENGTH_LEVEL))  ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_5_STRENGTH_LEVEL)   &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_5_STRENGTH_LEVEL))  ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_6_STRENGTH_LEVEL)   &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_6_STRENGTH_LEVEL))  ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_7_STRENGTH_LEVEL)   &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_7_STRENGTH_LEVEL))  ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_8_STRENGTH_LEVEL)   &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_8_STRENGTH_LEVEL))  ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_9_STRENGTH_LEVEL)   &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_9_STRENGTH_LEVEL))  ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_10_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_10_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_11_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_11_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_12_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_12_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_13_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_13_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_14_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_14_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_15_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_15_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_16_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_16_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_17_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_17_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_18_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_18_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_19_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_19_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_20_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_20_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_21_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_21_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_22_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_22_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_23_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_23_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_24_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_24_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_25_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_25_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_26_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_26_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_27_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_27_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_28_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_28_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_29_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_29_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_30_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_30_STRENGTH_LEVEL)) ||   \
      ((GPIO_STRENGTH_HIGH != GPIO_PORT_##PortName##_PIN_31_STRENGTH_LEVEL)  &&   \
       (GPIO_STRENGTH_LOW  != GPIO_PORT_##PortName##_PIN_31_STRENGTH_LEVEL)))

// Checking correct strength level all pins
#if ((GPIO_PORT_CORRECT_STRENGTH_LEVEL(A)) ||    \
     (GPIO_PORT_CORRECT_STRENGTH_LEVEL(B)) ||    \
     (GPIO_PORT_CORRECT_STRENGTH_LEVEL(C)) ||    \
     (GPIO_PORT_CORRECT_STRENGTH_LEVEL(D)) ||    \
     (GPIO_PORT_CORRECT_STRENGTH_LEVEL(E)))

#error "gpio_drv_cfg.h: parameter GPIO_PORT_X_PIN_X_STRENGTH_LEVEL does not match" \
        "GPIO_STRENGTH_HIGH or GPIO_STRENGTH_LOW "
#endif // end of #if ((GPIO_PORT_CORRECT_STRENGTH_LEVEL(X))

// Valid output drive macro
#define GPIO_PORT_CORRECT_PULL_ENABLE(PortName)                            \
      ((GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_0_PULL_ENABLE)   || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_1_PULL_ENABLE)   || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_2_PULL_ENABLE)   || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_3_PULL_ENABLE)   || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_4_PULL_ENABLE)   || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_5_PULL_ENABLE)   || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_6_PULL_ENABLE)   || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_7_PULL_ENABLE)   || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_8_PULL_ENABLE)   || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_9_PULL_ENABLE)   || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_10_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_11_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_12_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_13_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_14_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_15_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_16_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_17_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_18_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_19_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_20_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_21_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_22_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_23_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_24_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_25_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_26_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_27_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_28_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_29_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_30_PULL_ENABLE)  || \
       (GPIO_PULL_ENABLE  < GPIO_PORT_##PortName##_PIN_31_PULL_ENABLE))

// Checking correct output drive all pins
#if ((GPIO_PORT_CORRECT_PULL_ENABLE(A)) ||    \
     (GPIO_PORT_CORRECT_PULL_ENABLE(B)) ||    \
     (GPIO_PORT_CORRECT_PULL_ENABLE(C)) ||    \
     (GPIO_PORT_CORRECT_PULL_ENABLE(D)) ||    \
     (GPIO_PORT_CORRECT_PULL_ENABLE(E)))

#error "gpio_drv_cfg.h: parameter GPIO_PORT_X_PIN_X_PULL_ENABLE does not match GPIO_PUSH_PULL," \
"GPIO_PULL_DISABLE "
#endif // end of #if ((GPIO_PORT_CORRECT_PULL_ENABLE(X))

// Valid pull mode macro
#define GPIO_PORT_CORRECT_PULL_MODE(PortName)                        \
      ((GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_0_PULL_MODE)   || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_1_PULL_MODE)   || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_2_PULL_MODE)   || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_3_PULL_MODE)   || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_4_PULL_MODE)   || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_5_PULL_MODE)   || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_6_PULL_MODE)   || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_7_PULL_MODE)   || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_8_PULL_MODE)   || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_9_PULL_MODE)   || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_10_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_11_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_12_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_13_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_14_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_15_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_16_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_17_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_18_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_19_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_20_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_21_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_22_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_23_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_24_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_25_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_26_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_27_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_28_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_29_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_30_PULL_MODE)  || \
       (GPIO_PULL_UP  < GPIO_PORT_##PortName##_PIN_31_PULL_MODE))

// Checking correct pull mode all pins
#if ((GPIO_PORT_CORRECT_PULL_MODE(A)) ||    \
     (GPIO_PORT_CORRECT_PULL_MODE(B)) ||    \
     (GPIO_PORT_CORRECT_PULL_MODE(C)) ||    \
     (GPIO_PORT_CORRECT_PULL_MODE(D)) ||    \
     (GPIO_PORT_CORRECT_PULL_MODE(E)))

#error "gpio_drv_cfg.h: parameter GPIO_PORT_X_PIN_X_PULL_MODE does not match"  \
"GPIO_PULL_UP or GPIO_PULL_DOWN"
#endif // end of #if ((GPIO_PORT_CORRECT_PULL_MODE(X))

// Valid value macro
#define GPIO_PORT_CORRECT_VALUE(PortName)                             \
      ((GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_0_PULL_VALUE)   || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_1_PULL_VALUE)   || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_2_PULL_VALUE)   || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_3_PULL_VALUE)   || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_4_PULL_VALUE)   || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_5_PULL_VALUE)   || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_6_PULL_VALUE)   || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_7_PULL_VALUE)   || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_8_PULL_VALUE)   || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_9_PULL_VALUE)   || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_10_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_11_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_12_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_13_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_14_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_15_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_16_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_17_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_18_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_19_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_20_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_21_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_22_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_23_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_24_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_25_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_26_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_27_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_28_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_29_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_30_PULL_VALUE)  || \
       (GPIO_PIN_HIGH < GPIO_PORT_##PortName##_PIN_31_PULL_VALUE))

// Checking correct value all pins
#if ((GPIO_PORT_CORRECT_VALUE(A)) ||    \
     (GPIO_PORT_CORRECT_VALUE(B)) ||    \
     (GPIO_PORT_CORRECT_VALUE(C)) ||    \
     (GPIO_PORT_CORRECT_VALUE(D)) ||    \
     (GPIO_PORT_CORRECT_VALUE(E)))

#error "gpio_drv_cfg.h: parameter GPIO_PORT_X_PIN_X_VALUE does not match GPIO_PIN_LOW or"\
"GPIO_PIN_HIGH"
#endif // end of #if ((GPIO_PORT_CORRECT_VALUE(X))



//**************************************************************************************************
// Definitions of global (public) variables
//**************************************************************************************************

// None



//**************************************************************************************************
// Declarations of local (private) data types
//**************************************************************************************************

//! Pin settings
typedef struct
{
    //! Wake UP pin enable
    BOOLEAN bPinEnable;
} GPIO_PIN_CONFIG;

//! WakeUp pin settings
typedef struct
{
    //! Wake Up pin enable
    BOOLEAN bWkUpPinEnable;
    //! Wake Up pin interrupt enable
    BOOLEAN bWkUpIntEnable;
    //! Wake up edge detection type
    U8 nWkUpEdge;
    //! Wake up event id
    U8 nWkUpEventID;
    //! Wake up handler
    GPIO_WAKEUP_HANDLER pPinWakeupHandler;
} GPIO_WAKEUP_CONFIG;

//! Program module API IDs
typedef enum
{
    GPIO_API_ID_INNER_FUNC                 = (U8)0U,
    GPIO_API_ID_INIT                       = (U8)1U,
    GPIO_API_ID_DEINIT                     = (U8)2U,
    GPIO_API_ID_GET_PIN_DIRECTION          = (U8)3U,
    GPIO_API_ID_SET_PIN_DIRECTION          = (U8)4U,
    GPIO_API_ID_GET_PIN_STATE              = (U8)5U,
    GPIO_API_ID_SET_PIN_STATE              = (U8)6U,
    GPIO_API_ID_WAKEUP_ENABLE              = (U8)7U,
    GPIO_API_ID_SET_WAKEUP_EVENT_HANDLER   = (U8)8U,
	GPIO_API_ID_HIGH_LEVEL_WAKEUP_ISR      = (U8)9U,
	GPIO_API_ID_HIGH_LEVEL_ISR      	   = (U8)12U,
} GPIO_API_ID;



//**************************************************************************************************
// Definitions of local (private) constants
//**************************************************************************************************

// Port enable state macro
#define GPIO_PORT_IS_ENABLE(Port)         \
   (GPIO_PORT_##Port##_PIN_0_ENABLE  ||   \
    GPIO_PORT_##Port##_PIN_1_ENABLE  ||   \
    GPIO_PORT_##Port##_PIN_2_ENABLE  ||   \
    GPIO_PORT_##Port##_PIN_3_ENABLE  ||   \
    GPIO_PORT_##Port##_PIN_4_ENABLE  ||   \
    GPIO_PORT_##Port##_PIN_5_ENABLE  ||   \
    GPIO_PORT_##Port##_PIN_6_ENABLE  ||   \
    GPIO_PORT_##Port##_PIN_7_ENABLE  ||   \
    GPIO_PORT_##Port##_PIN_8_ENABLE  ||   \
    GPIO_PORT_##Port##_PIN_9_ENABLE  ||   \
    GPIO_PORT_##Port##_PIN_10_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_11_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_12_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_13_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_14_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_15_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_16_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_17_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_18_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_19_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_20_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_21_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_22_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_23_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_24_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_25_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_26_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_27_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_28_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_29_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_30_ENABLE ||   \
    GPIO_PORT_##Port##_PIN_31_ENABLE)

// Macro for INIT PULL_ENABLE (PCR PE)
#define GPIO_INIT_PULL_ENABLE(Port, Pin)                 \
    ((ON == GPIO_PORT_##Port##_PIN_##Pin##_ENABLE) *     \
     (GPIO_PORT_##Port##_PIN_##Pin##_PULL_ENABLE))

// Macro for INIT STRENGTH
#define GPIO_INIT_PCTRL_DSE(Port, Pin)                                                           \
    ((GPIO_PORT_##Port##_PIN_##Pin##_STRENGTH_LEVEL) * (GPIO_PORT_##Port##_PIN_##Pin##_ENABLE))

// Macro for INIT PULL MODE (PCR PS)
#define GPIO_INIT_PCTRL_PS(Port, Pin)                                                            \
    ((GPIO_PORT_##Port##_PIN_##Pin##_PULL_MODE) * (GPIO_PORT_##Port##_PIN_##Pin##_ENABLE))

// Macro for PDOR init (PORT DATA OUTPUT)
#define GPIO_PORT_PIN_VALUE(Port, Pin)                     \
    ((U32)(ON == GPIO_PORT_##Port##_PIN_##Pin##_ENABLE) *  \
     GPIO_PORT_##Port##_PIN_##Pin##_VALUE )

#define GPIO_PORT_INIT_VALUE(Port)                          \
        ((GPIO_PORT_PIN_VALUE(Port, 0)  << 0U)  |           \
         (GPIO_PORT_PIN_VALUE(Port, 1)  << 1U)  |           \
         (GPIO_PORT_PIN_VALUE(Port, 2)  << 2U)  |           \
         (GPIO_PORT_PIN_VALUE(Port, 3)  << 3U)  |           \
         (GPIO_PORT_PIN_VALUE(Port, 4)  << 4U)  |           \
         (GPIO_PORT_PIN_VALUE(Port, 5)  << 5U)  |           \
         (GPIO_PORT_PIN_VALUE(Port, 6)  << 6U)  |           \
         (GPIO_PORT_PIN_VALUE(Port, 7)  << 7U)  |           \
         (GPIO_PORT_PIN_VALUE(Port, 8)  << 8U)  |           \
         (GPIO_PORT_PIN_VALUE(Port, 9)  << 9U)  |           \
         (GPIO_PORT_PIN_VALUE(Port, 10) << 10U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 11) << 11U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 12) << 12U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 13) << 13U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 14) << 14U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 15) << 15U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 16) << 16U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 17) << 17U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 18) << 18U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 19) << 19U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 20) << 20U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 21) << 21U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 22) << 22U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 23) << 23U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 24) << 24U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 25) << 25U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 26) << 26U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 27) << 27U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 28) << 28U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 29) << 29U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 30) << 30U) |           \
         (GPIO_PORT_PIN_VALUE(Port, 31) << 31U))


// Macro for POER init (PORT OUTPUT ENABLE)

#define GPIO_PORT_PIN_DIRECTION(Port, Pin)                           \
    ((GPIO_PIN_OUTPUT == GPIO_PORT_##Port##_PIN_##Pin##_DIRECTION) * \
    (GPIO_PORT_##Port##_PIN_##Pin##_ENABLE))

#define GPIO_PORT_INIT_OUTPUT(Port)               \
        ((U32)(GPIO_PORT_PIN_DIRECTION(Port, 0)  << 0U)  | \
         (GPIO_PORT_PIN_DIRECTION(Port, 1)  << 1U)  | \
         (GPIO_PORT_PIN_DIRECTION(Port, 2)  << 2U)  | \
         (GPIO_PORT_PIN_DIRECTION(Port, 3)  << 3U)  | \
         (GPIO_PORT_PIN_DIRECTION(Port, 4)  << 4U)  | \
         (GPIO_PORT_PIN_DIRECTION(Port, 5)  << 5U)  | \
         (GPIO_PORT_PIN_DIRECTION(Port, 6)  << 6U)  | \
         (GPIO_PORT_PIN_DIRECTION(Port, 7)  << 7U)  | \
         (GPIO_PORT_PIN_DIRECTION(Port, 8)  << 8U)  | \
         (GPIO_PORT_PIN_DIRECTION(Port, 9)  << 9U)  | \
         (GPIO_PORT_PIN_DIRECTION(Port, 10) << 10U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 11) << 11U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 12) << 12U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 13) << 13U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 14) << 14U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 15) << 15U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 16) << 16U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 17) << 17U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 18) << 18U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 19) << 19U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 20) << 20U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 21) << 21U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 22) << 22U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 23) << 23U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 24) << 24U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 25) << 25U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 26) << 26U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 27) << 27U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 28) << 28U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 29) << 29U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 30) << 30U) | \
         (GPIO_PORT_PIN_DIRECTION(Port, 31) << 31U))

// Filling PCR register macro
#define GPIO_PORTPIN_PCTRL_FILL(PortName, Pin)                      \
    GPIO_aPinCfg[GPIO_PORT_##PortName][Pin].bPinEnable =            \
                        GPIO_PORT_##PortName##_PIN_##Pin##_ENABLE;  \
    if (ON == GPIO_PORT_##PortName##_PIN_##Pin##_ENABLE)            \
    {                                                               \
        PCTRL_pPorts[GPIO_PORT_##PortName]->PCR[Pin].B.MUX = GPIO_MUX_ALT_1;   \
        PCTRL_pPorts[GPIO_PORT_##PortName]->PCR[Pin].B.DSE =        \
            GPIO_PORT_##PortName##_PIN_##Pin##_STRENGTH_LEVEL;      \
        PCTRL_pPorts[GPIO_PORT_##PortName]->PCR[Pin].B.PS =         \
		    GPIO_PORT_##PortName##_PIN_##Pin##_PULL_MODE;           \
		PCTRL_pPorts[GPIO_PORT_##PortName]->PCR[Pin].B.PE =         \
		    GPIO_PORT_##PortName##_PIN_##Pin##_PULL_ENABLE;         \
	}

#define GPIO_PORT_PCTRL_FILL(Port)                 \
{                                                  \
    GPIO_PORTPIN_PCTRL_FILL(Port, 0);              \
    GPIO_PORTPIN_PCTRL_FILL(Port, 1);              \
    GPIO_PORTPIN_PCTRL_FILL(Port, 2);              \
    GPIO_PORTPIN_PCTRL_FILL(Port, 3);              \
    GPIO_PORTPIN_PCTRL_FILL(Port, 4);              \
    GPIO_PORTPIN_PCTRL_FILL(Port, 5);              \
    GPIO_PORTPIN_PCTRL_FILL(Port, 6);              \
    GPIO_PORTPIN_PCTRL_FILL(Port, 7);              \
    GPIO_PORTPIN_PCTRL_FILL(Port, 8);              \
    GPIO_PORTPIN_PCTRL_FILL(Port, 9);              \
    GPIO_PORTPIN_PCTRL_FILL(Port, 10);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 11);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 12);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 13);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 14);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 15);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 16);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 17);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 18);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 19);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 20);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 21);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 22);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 23);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 24);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 25);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 26);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 27);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 28);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 29);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 30);             \
    GPIO_PORTPIN_PCTRL_FILL(Port, 31);             \
}

//! Set zero bit to Value
#define GPIO_SET1BIT(Value) (1U & (Value))

//! Set 2 bits to Value
#define GPIO_SET2BIT(Value) (3U & (Value))

// Wake UP state macro
#define GPIO_PORT_WKU_PINS_ENABLE  \
      (GPIO_WKU_PIN_0_ENABLE || \
       GPIO_WKU_PIN_1_ENABLE || \
       GPIO_WKU_PIN_2_ENABLE || \
       GPIO_WKU_PIN_3_ENABLE || \
       GPIO_WKU_PIN_4_ENABLE || \
       GPIO_WKU_PIN_5_ENABLE || \
       GPIO_WKU_PIN_6_ENABLE || \
       GPIO_WKU_PIN_7_ENABLE || \
       GPIO_WKU_PIN_8_ENABLE || \
       GPIO_WKU_PIN_9_ENABLE || \
       GPIO_WKU_PIN_10_ENABLE || \
       GPIO_WKU_PIN_11_ENABLE || \
       GPIO_WKU_PIN_12_ENABLE || \
       GPIO_WKU_PIN_13_ENABLE || \
       GPIO_WKU_PIN_14_ENABLE || \
       GPIO_WKU_PIN_15_ENABLE || \
       GPIO_WKU_PIN_16_ENABLE || \
       GPIO_WKU_PIN_17_ENABLE || \
       GPIO_WKU_PIN_18_ENABLE || \
       GPIO_WKU_PIN_19_ENABLE || \
       GPIO_WKU_PIN_20_ENABLE || \
       GPIO_WKU_PIN_21_ENABLE || \
       GPIO_WKU_PIN_22_ENABLE || \
       GPIO_WKU_PIN_23_ENABLE || \
       GPIO_WKU_PIN_24_ENABLE || \
       GPIO_WKU_PIN_25_ENABLE || \
       GPIO_WKU_PIN_26_ENABLE || \
       GPIO_WKU_PIN_27_ENABLE || \
       GPIO_WKU_PIN_28_ENABLE || \
       GPIO_WKU_PIN_29_ENABLE || \
       GPIO_WKU_PIN_30_ENABLE || \
       GPIO_WKU_PIN_31_ENABLE)

// Macro for Wake Up Pin Setup
#define GPIO_WKU_PIN_CONFIG(Pin)                     \
    if (ON == GPIO_WKU_PIN_##Pin##_ENABLE)           \
    {                                                \
        GPIO_aWkUpPinCfg[Pin].bWkUpPinEnable = GPIO_WKU_PIN_##Pin##_ENABLE;    \
        GPIO_aWkUpPinCfg[Pin].nWkUpEventID = GPIO_WKU_PIN_##Pin##_EVENT;       \
        GPIO_aWkUpPinCfg[Pin].bWkUpIntEnable = GPIO_WKU_PIN_##Pin##_ENABLE;    \
        GPIO_aWkUpPinCfg[Pin].nWkUpEdge = GPIO_WKU_PIN_##Pin##_WU_ENABLE;      \
        GPIO_aWkUpPinCfg[Pin].pPinWakeupHandler = NULL_PTR;  \
    }
#define GPIO_WAKEUP_PINS_INIT   \
    GPIO_WKU_PIN_CONFIG(0);     \
    GPIO_WKU_PIN_CONFIG(1);     \
    GPIO_WKU_PIN_CONFIG(2);     \
    GPIO_WKU_PIN_CONFIG(3);     \
    GPIO_WKU_PIN_CONFIG(4);     \
    GPIO_WKU_PIN_CONFIG(5);     \
    GPIO_WKU_PIN_CONFIG(6);     \
    GPIO_WKU_PIN_CONFIG(7);     \
    GPIO_WKU_PIN_CONFIG(8);     \
    GPIO_WKU_PIN_CONFIG(9);     \
    GPIO_WKU_PIN_CONFIG(10);    \
    GPIO_WKU_PIN_CONFIG(11);    \
    GPIO_WKU_PIN_CONFIG(12);    \
    GPIO_WKU_PIN_CONFIG(13);    \
    GPIO_WKU_PIN_CONFIG(14);    \
    GPIO_WKU_PIN_CONFIG(15);    \
    GPIO_WKU_PIN_CONFIG(16);    \
    GPIO_WKU_PIN_CONFIG(17);    \
    GPIO_WKU_PIN_CONFIG(18);    \
    GPIO_WKU_PIN_CONFIG(19);    \
    GPIO_WKU_PIN_CONFIG(20);    \
    GPIO_WKU_PIN_CONFIG(21);    \
    GPIO_WKU_PIN_CONFIG(22);    \
    GPIO_WKU_PIN_CONFIG(23);    \
    GPIO_WKU_PIN_CONFIG(24);    \
    GPIO_WKU_PIN_CONFIG(25);    \
    GPIO_WKU_PIN_CONFIG(26);    \
    GPIO_WKU_PIN_CONFIG(27);    \
    GPIO_WKU_PIN_CONFIG(28);    \
    GPIO_WKU_PIN_CONFIG(29);    \
    GPIO_WKU_PIN_CONFIG(30);    \
    GPIO_WKU_PIN_CONFIG(31)


// Filling pin config macro
#if (ON == GPIO_DEVELOPMENT_ERROR_DETECTION)

//! Program module ID
static const U8 GPIO_pModuleID[] = "GPIO";
static const U8 GPIO_nModuleIDSize = SIZE_OF_ARRAY(GPIO_pModuleID) - 1U;

//! Error tracer function
#define GPIO_REPORT_DEV_ERROR(GPIO_nObjectID,        \
                              GPIO_nAPIID,           \
                              nErrorID)              \
    ET_ReportDevelopmentError(GPIO_pModuleID,        \
                              GPIO_nModuleIDSize,    \
                              (GPIO_nObjectID),      \
                              (GPIO_nAPIID),         \
                              (nErrorID))

#define GPIO_HALFBYTE_BIT_QTY (4U)
// Combining the port number and pin into one variable

#define GPIO_COMB_PORT_PIN(Port, Pin)                \
    (U8)(((Port) << GPIO_HALFBYTE_BIT_QTY) | (Pin))

#endif



//**************************************************************************************************
// Definitions of static global (private) variables
//**************************************************************************************************

//! Program module initialization state
static BOOLEAN GPIO_bInitialized = FALSE;

//! Pins config array
static GPIO_PIN_CONFIG GPIO_aPinCfg[GPIO_PORTS_QTY][GPIO_PINS_QTY];

//! Pins registers array
static GPIO_tag* GPIO_pPorts[GPIO_PORTS_QTY] =
{
    &GPIOA,
    &GPIOB,
    &GPIOC,
    &GPIOD,
    &GPIOE,
};

//! Port control registers array
static PCTRL_tag* PCTRL_pPorts[GPIO_PORTS_QTY] =
{
    &PCTRLA,
    &PCTRLB,
    &PCTRLC,
    &PCTRLD,
    &PCTRLE,
};

//! WakeUp pins array
static GPIO_WAKEUP_CONFIG  GPIO_aWkUpPinCfg[GPIO_PINS_QTY];



//**************************************************************************************************
// Declarations of local (private) functions
//**************************************************************************************************

#if (ON == GPIO_DEVELOPMENT_ERROR_DETECTION)
//! \brief Check port and pin input parameters
static BOOLEAN GPIO_IsPortPinValid(const U8 nPortNumber,
                                   const U8 nPinNumber,
                                   const U8 nApiId);
#endif

//! \brief Return Index in Wake Up register
static U8 GPIO_WakeUpPinNumber(const U8 nPortNumber,
                               const U8 nPinNumber);



//**************************************************************************************************
//==================================================================================================
// Definitions of global (public) functions
//==================================================================================================
//**************************************************************************************************

//**************************************************************************************************
//! Initialization SW and HW resources of the program module
//!
//! \note None
//!
//! \param  None.
//!
//! \return RESULT_OK     - function succeeded
//!         RESULT_NOT_OK - function NOT succeeded
//**************************************************************************************************
STD_RESULT GPIO_Init(void)
{
    STD_RESULT nFuncResult = RESULT_OK;
    // GPIO works on the core clock frequency
    // PCTRL works on the SLOW_BUS
    // So we must initialize clocking for both systems

    // IPC CTRL Clock Source Selection NOT PERMITTED FOR PCTRL

	if (FALSE == GPIO_bInitialized)
	{
        // GPIO clock enable
		if (OFF == IPC.CTRL[GPIO_IPC_INDEX].B.CLKEN)
		{
			IPC.CTRL[GPIO_IPC_INDEX].B.CLKEN =  GPIO_SET1BIT(ON);
		}

        #if (TRUE == GPIO_PORT_IS_ENABLE(A))
            // GPIO clock enable
            IPC.CTRL[GPIO_IPC_PCTRLA_INDEX].B.CLKEN = GPIO_SET1BIT(ON);
            // PORT PINs DATA OUTPUT
            GPIOA.PDOR.R |= GPIO_PORT_INIT_VALUE(A);
            // PORT PINs OUTPUT ENABLE
            GPIOA.POER.R |= GPIO_PORT_INIT_OUTPUT(A);
            // PCTRL INIT
            GPIO_PORT_PCTRL_FILL(A);
        #endif

        #if (TRUE == GPIO_PORT_IS_ENABLE(B))
            // GPIO clock enable
            IPC.CTRL[GPIO_IPC_PCTRLB_INDEX].B.CLKEN = GPIO_SET1BIT(ON);
            // PORT PINs DATA OUTPUT
            GPIOB.PDOR.R |= GPIO_PORT_INIT_VALUE(B);
            // PORT PINs OUTPUT ENABLE
            GPIOB.POER.R |= GPIO_PORT_INIT_OUTPUT(B);
            // PCTRL INIT
            GPIO_PORT_PCTRL_FILL(B);
        #endif

        #if (TRUE == GPIO_PORT_IS_ENABLE(C))
            // GPIO clock enable
            IPC.CTRL[GPIO_IPC_PCTRLC_INDEX].B.CLKEN = GPIO_SET1BIT(ON);
            // PORT PINs DATA OUTPUT
            GPIOC.PDOR.R |= GPIO_PORT_INIT_VALUE(C);
            // PORT PINs OUTPUT ENABLE
            GPIOC.POER.R |= GPIO_PORT_INIT_OUTPUT(C);
            // PCTRL INIT
            GPIO_PORT_PCTRL_FILL(C);
        #endif

        #if (TRUE == GPIO_PORT_IS_ENABLE(D))
            // GPIO clock enable
            IPC.CTRL[GPIO_IPC_PCTRLD_INDEX].B.CLKEN =  GPIO_SET1BIT(ON);
            // PORT PINs DATA OUTPUT
            GPIOD.PDOR.R |= GPIO_PORT_INIT_VALUE(D);
            // PORT PINs OUTPUT ENABLE
            GPIOD.POER.R |= GPIO_PORT_INIT_OUTPUT(D);
            // PCTRL INIT
            GPIO_PORT_PCTRL_FILL(D);
        #endif

        #if (TRUE == GPIO_PORT_IS_ENABLE(E))
            // GPIO clock enable
            IPC.CTRL[GPIO_IPC_PCTRLE_INDEX].B.CLKEN =  GPIO_SET1BIT(ON);
            // PORT PINs init value output
            GPIOE.PDOR.R |= GPIO_PORT_INIT_VALUE(E);
            // PORT PINs OUTPUT ENABLE
            GPIOE.POER.R |= GPIO_PORT_INIT_OUTPUT(E);
            // PCTRL INIT
            GPIO_PORT_PCTRL_FILL(E);
        #endif

        #if (GPIO_PORT_WKU_PINS_ENABLE)
            // Wake Up setup
            // WKU clock enable
            IPC.CTRL[GPIO_IPC_WKU_INDEX].B.CLKEN =  GPIO_SET1BIT(ON);
            GPIO_WAKEUP_PINS_INIT;
            for (U8 nPin = 0U; nPin <  GPIO_PINS_QTY; nPin++)
            {
                if (ON == GPIO_aWkUpPinCfg[nPin].bWkUpPinEnable)
                {
                    WKU.PCR[nPin].B.WUPIE = GPIO_SET1BIT(GPIO_aWkUpPinCfg[nPin].bWkUpIntEnable);
                    WKU.PCR[nPin].B.WUPE = GPIO_SET2BIT(GPIO_aWkUpPinCfg[nPin].nWkUpEdge);
                }
            }
        #endif
        GPIO_bInitialized = TRUE;
	}
    else
    {
         nFuncResult = RESULT_NOT_OK;
        #if (ON == GPIO_DEVELOPMENT_ERROR_DETECTION)
        GPIO_REPORT_DEV_ERROR(0U,
                              GPIO_API_ID_INIT,
                              DEV_ERROR_ALREADY_INIT);
        #endif
    }

	return nFuncResult;
} // end of GPIO_Init()



//**************************************************************************************************
//! Deinitialization SW and HW resources of the program module
//!
//! \note None
//!
//! \param   None.
//!
//! \return RESULT_OK     - function succeeded
//!         RESULT_NOT_OK - function NOT succeeded
//**************************************************************************************************
STD_RESULT GPIO_DeInit(void)
{
    STD_RESULT nFuncResult = RESULT_OK;

    if (TRUE == GPIO_bInitialized)
    {
        // Deinitialization all of the GPIO ports

        GPIO_bInitialized = FALSE;
        for (U8 nPin = 0U; nPin < GPIO_PINS_QTY; nPin++)
        {
            // Disable WakeUp interruptions
            if (ON == GPIO_aWkUpPinCfg[nPin].bWkUpPinEnable)
            {
                WKU.PCR[nPin].B.WUPIE = GPIO_SET1BIT(OFF);
                GPIO_aWkUpPinCfg[nPin].bWkUpIntEnable = FALSE;
            }
        }

    }
    else
    {
        nFuncResult = RESULT_NOT_OK;
        #if (ON == GPIO_DEVELOPMENT_ERROR_DETECTION)
        GPIO_REPORT_DEV_ERROR(0U,
                              GPIO_API_ID_DEINIT,
                              DEV_ERROR_NOT_INIT);
        #endif
    }

    return nFuncResult;
} // end of GPIO_DeInit()



//**************************************************************************************************
//! Returns actual direction of the digital input/output pin
//!
//! \note None
//!
//! \param[in]  nPortNumber - port number
//! \param[in]  nPinNumber - pin number
//! \param[out] pDirection - pointer to buffer receiving actual direction of the specified
//!                          digital input/output pin
//!
//! \return RESULT_OK     - function succeeded
//!         RESULT_NOT_OK - function NOT succeeded
//**************************************************************************************************
STD_RESULT GPIO_GetPinDirection(const U8 nPortNumber,
                                const U8 nPinNumber,
                                U8* const pDirection)
{
    STD_RESULT nFuncResult = RESULT_OK;
#if (ON == GPIO_DEVELOPMENT_ERROR_DETECTION)

    if (FALSE == GPIO_IsPortPinValid(nPortNumber,
                                     nPinNumber,
                                     GPIO_API_ID_GET_PIN_DIRECTION))
    {
        GPIO_REPORT_DEV_ERROR(GPIO_COMB_PORT_PIN(nPortNumber, nPinNumber),
                              GPIO_API_ID_GET_PIN_DIRECTION,
                              DEV_ERROR_PARAM_0);
        GPIO_REPORT_DEV_ERROR(GPIO_COMB_PORT_PIN(nPortNumber, nPinNumber),
                              GPIO_API_ID_GET_PIN_DIRECTION,
                              DEV_ERROR_PARAM_1);
    	nFuncResult = RESULT_NOT_OK;
    }
    else if (NULL_PTR == pDirection)
    {
        GPIO_REPORT_DEV_ERROR(GPIO_COMB_PORT_PIN(nPortNumber, nPinNumber),
                              GPIO_API_ID_GET_PIN_DIRECTION,
                              DEV_ERROR_PARAM_2);
        nFuncResult = RESULT_NOT_OK;
    }
#endif
    if (GPIO_PIN_OUTPUT == (GPIO_pPorts[nPortNumber]->POER.R & \
        		(ON << nPinNumber)))
    {
            *pDirection = GPIO_PIN_OUTPUT;
    }
    else
    {
            *pDirection = GPIO_PIN_INPUT;
    }

    return nFuncResult;
} // end of GPIO_GetPinDirection()



//**************************************************************************************************
//! Sets a new direction of the specified digital input/output pin.
//!
//! \note None
//!
//! \param[in]  nPortNumber - port number
//! \param[in]  nPinNumber - pin number
//! \param[in]  nDirection  - a new pin direction: GPIO_PIN_INPUT  - input
//!                                                GPIO_PIN_OUTPUT - output
//!
//! \return RESULT_OK     - function succeeded
//!         RESULT_NOT_OK - function NOT succeeded
//**************************************************************************************************
STD_RESULT GPIO_SetPinDirection(const U8 nPortNumber,
                                const U8 nPinNumber,
                                const U8 nDirection)
{
    STD_RESULT nFuncResult = RESULT_OK;

#if (ON == GPIO_DEVELOPMENT_ERROR_DETECTION)
    if (FALSE == GPIO_IsPortPinValid(nPortNumber,
                                     nPinNumber,
                                     GPIO_API_ID_SET_PIN_DIRECTION))
    {

        GPIO_REPORT_DEV_ERROR(GPIO_COMB_PORT_PIN(nPortNumber, nPinNumber),
                              GPIO_API_ID_SET_PIN_DIRECTION,
                              DEV_ERROR_PARAM_0);
        GPIO_REPORT_DEV_ERROR(GPIO_COMB_PORT_PIN(nPortNumber, nPinNumber),
                              GPIO_API_ID_SET_PIN_DIRECTION,
                              DEV_ERROR_PARAM_1);

        nFuncResult = RESULT_NOT_OK;
    }
    else if ((GPIO_PIN_INPUT != nDirection) && (GPIO_PIN_OUTPUT != nDirection))
    {
        nFuncResult = RESULT_NOT_OK;

        GPIO_REPORT_DEV_ERROR(GPIO_COMB_PORT_PIN(nPortNumber, nPinNumber),
                              GPIO_API_ID_SET_PIN_DIRECTION,
                              DEV_ERROR_PARAM_2);
    }
#endif
    U32 nPinsDirection =  GPIO_pPorts[nPortNumber]->POER.R;
    // Clear pin direction
    nPinsDirection &= (U32)(~(1UL << nPinNumber));
    // Set pin direction
    nPinsDirection |= (U32)nDirection << nPinNumber;
    // Update direction register
    GPIO_pPorts[nPortNumber]->POER.R = nPinsDirection;

    return nFuncResult;
} // end of GPIO_SetPinDirection()



//**************************************************************************************************
//! Returns actual logic state of the digital input/output pin.
//!
//! \note None
//!
//! \param[in]  nPortNumber - port number
//! \param[in]  nPinNumber - pin number
//! \param[out] pLogicState - pointer to buffer receiving actual logic state
//!                           of the specified digital input/output pin
//!
//! \return RESULT_OK     - function succeeded
//!         RESULT_NOT_OK - function NOT succeeded
//**************************************************************************************************
STD_RESULT GPIO_GetPinState(const U8 nPortNumber,
                            const U8 nPinNumber,
                            U8* const pLogicState)
{
    STD_RESULT nFuncResult = RESULT_OK;
#if (ON == GPIO_DEVELOPMENT_ERROR_DETECTION)
    // check both port and pin are valid
    if (FALSE == GPIO_IsPortPinValid(nPortNumber,
                                     nPinNumber,
                                     GPIO_API_ID_GET_PIN_STATE))
    {
        nFuncResult = RESULT_NOT_OK;
    }
    // check output pointer is valid
    else if (NULL_PTR == pLogicState)
    {
        nFuncResult = RESULT_NOT_OK;
        GPIO_REPORT_DEV_ERROR(GPIO_COMB_PORT_PIN(nPortNumber, nPinNumber),
                              GPIO_API_ID_GET_PIN_STATE,
                              DEV_ERROR_PARAM_2);
    }
#endif
    if (OFF != (GPIO_pPorts[nPortNumber]->PDOR.R & (ON << nPinNumber)))
    {
       *pLogicState = GPIO_PIN_HIGH;
    }
    else
    {
       *pLogicState = GPIO_PIN_LOW;
    }

    return nFuncResult;
} // end of GPIO_GetPinState()



//**************************************************************************************************
//! Sets a new logic state of the specified digital input/output pin.
//!
//! \note None
//!
//! \param[in]  nPortNumber - port number
//! \param[in]  nPinNumber - pin number
//! \param[in]  nLogicState - a new pin logical state: LOGIC_0 - sets logical 0
//!                                                    LOGIC_1 - sets logical 1
//!
//! \return RESULT_OK     - function succeeded
//!         RESULT_NOT_OK - function NOT succeeded
//**************************************************************************************************
STD_RESULT GPIO_SetPinState(const U8 nPortNumber,
                            const U8 nPinNumber,
                            const U8 nLogicState)
{
    STD_RESULT nFuncResult = RESULT_OK;

#if (ON == GPIO_DEVELOPMENT_ERROR_DETECTION)
    if (FALSE == GPIO_IsPortPinValid(nPortNumber, nPinNumber,
                                     GPIO_API_ID_SET_PIN_STATE))
    {
        nFuncResult = RESULT_NOT_OK;
    }
    else if ((GPIO_PIN_LOW != nLogicState) && (GPIO_PIN_HIGH != nLogicState))
    {
        nFuncResult = RESULT_NOT_OK;
    }
    else
#endif
    {
        BOOLEAN bPinState = (GPIO_PIN_HIGH == nLogicState);
        if (ON == bPinState)
        {
            // set pin value bit
            GPIO_pPorts[nPortNumber]->PSOR.R |= ON << nPinNumber;
        }
        else
        {
            // clear pin value bit
            GPIO_pPorts[nPortNumber]->PCOR.R |= ON << nPinNumber;
        }
    }
    return nFuncResult;
} // end of GPIO_SetPinState()



//**************************************************************************************************
//! Enables/disables wakeup on the specified digital input/output pin.
//!
//! \note None
//!
//! \param[in]  nPortNumber - port number
//! \param[in]  nPinNumber - pin number
//! \param[in]  bEnable     - enable/disable WakeUp interruption by pin:
//!                                              FALSE - disable WakeUp
//!                                              TRUE  - enable WakeUp
//!
//! \return RESULT_OK     - function succeeded
//!         RESULT_NOT_OK - function NOT succeeded
//**************************************************************************************************
STD_RESULT GPIO_WakeupEnable(const U8 nPortNumber,
                             const U8 nPinNumber,
                             const BOOLEAN bEnable)
{
    STD_RESULT nFuncResult = RESULT_OK;

    U8 nWKUPinNumber = GPIO_WakeUpPinNumber(nPortNumber, nPinNumber);
    if ((GPIO_WKU_INVALID_PIN == nWKUPinNumber) ||
        (FALSE == GPIO_aWkUpPinCfg[nWKUPinNumber].bWkUpPinEnable))
    {
          // This pin can't be WKU pin
          nFuncResult = RESULT_NOT_OK;
    }
    else
    {
          // Change WKU interrupt permission
          WKU.PCR[nWKUPinNumber].B.WUPIE = GPIO_SET1BIT(bEnable);
          GPIO_aWkUpPinCfg[nWKUPinNumber].bWkUpIntEnable = bEnable;
    }

    return nFuncResult;
} // end of GPIO_WakeupEnable()



//**************************************************************************************************
//! Sets pointer to Wake Up event handler function for the specified
//!        digital input/output pin.
//!
//! \note None
//!
//! \param[in]  nPortNumber - port number
//! \param[in]  nPinNumber - pin number
//! \param[in]  nWkUpEventID   - WakeUp event identifier
//! \param[in]  pWakeupHandler - pointer to the WakeUp event handler function, can be NULL_PTR.
//!
//! \return RESULT_OK     - function succeeded
//!         RESULT_NOT_OK - function NOT succeeded
//**************************************************************************************************
STD_RESULT GPIO_SetWakeupEventHandler(const U8 nPortNumber,
                                      const U8 nPinNumber,
                                      const U8 nWkUpEventID,
                                      const GPIO_WAKEUP_HANDLER pWakeupHandler)
{
    STD_RESULT nFuncResult = RESULT_OK;
    U8 nWkUpPin = GPIO_WakeUpPinNumber(nPortNumber, nPinNumber);

    if (GPIO_WKU_INVALID_PIN == nWkUpPin)
    {
        nFuncResult = RESULT_NOT_OK;
    }
    else if (FALSE == GPIO_aWkUpPinCfg[nWkUpPin].bWkUpPinEnable)
    {
        nFuncResult = RESULT_NOT_OK;
    }
    else
    {
        GPIO_aWkUpPinCfg[nWkUpPin].nWkUpEventID = nWkUpEventID;
        GPIO_aWkUpPinCfg[nWkUpPin].pPinWakeupHandler = pWakeupHandler;
    }
    return nFuncResult;
} // end of GPIO_SetWakeupEventHandler()



//**************************************************************************************************
//! High-level Wake Up interrupt service routine for all digital input/output pins.
//!
//! \note None
//!
//! \param[in]  nPortNumber - dummy value for API compatibility
//! \param[in]  nPinNumber  - WKU pin number
//!
//! \return None.
//**************************************************************************************************
void GPIO_HighLevel_Wakeup_ISR(const U8 nPortNumber,
                               const U8 nPinNumber)
{
    (void)nPortNumber;
    if ((NULL_PTR == GPIO_aWkUpPinCfg[nPinNumber].pPinWakeupHandler) ||
        (FALSE == GPIO_aWkUpPinCfg[nPinNumber].bWkUpIntEnable))
    {
        DoNothing();
    }
    else
    {
        GPIO_aWkUpPinCfg[nPinNumber].pPinWakeupHandler(
            GPIO_aWkUpPinCfg[nPinNumber].nWkUpEventID);
    }

} // end of GPIO_HighLevel_Wakeup_ISR()



//**************************************************************************************************
//==================================================================================================
// Definitions of local (private) functions
//==================================================================================================
//**************************************************************************************************



#if (ON == GPIO_DEVELOPMENT_ERROR_DETECTION)
//**************************************************************************************************
//! Check port and pin parameters.
//!
//! \note None
//!
//! \param[in]  nPortNumber - port number
//! \param[in]  nPinNumber  - pin number
//! \param[in]  nApiId      - program module API ID
//!
//! \return TRUE  - port and pin are valid
//!         FALSE - port and pin are invalid
//**************************************************************************************************
static BOOLEAN GPIO_IsPortPinValid(const U8 nPortNumber,
                                   const U8 nPinNumber,
                                   const U8 nApiId)
{
    BOOLEAN bResult = TRUE;

    if (FALSE == GPIO_bInitialized)
    {
        bResult = FALSE;
    }
    else if (nPortNumber > GPIO_PORT_LAST)
    {
        bResult = FALSE;
    }
    else if (nPinNumber > GPIO_PIN_LAST)
    {
        bResult = FALSE;
    }
    else if ((FALSE == GPIO_aPinCfg[nPortNumber][nPinNumber].bPinEnable) ||
             (nPinNumber > GPIO_PIN_LAST))
    {
        bResult = FALSE;
        #if (ON == GPIO_DEVELOPMENT_ERROR_DETECTION)
        GPIO_REPORT_DEV_ERROR(GPIO_COMB_PORT_PIN(nPortNumber, nPinNumber),
                              nApiId,
                              DEV_ERROR_FUNC_NOT_SUPP);
        #endif
    }
    else
    {
        DoNothing();
    }
    return bResult;
} // end of GPIO_IsPortPinValid()
#endif



//**************************************************************************************************
//! Return position in WKU register for pin with given port and pin values
//!
//! \note None
//!
//! \param[in]  nPortNumber - port number
//! \param[in]  nPinNumber  - pin number
//!
//! \return WKUPinNumber  - Wake-up pin number in WKU
//!                       - GPIO_WKU_INVALID_PIN, if port and pin are invalid
//**************************************************************************************************
static U8 GPIO_WakeUpPinNumber(const U8 nPortNumber,
                               const U8 nPinNumber)
{
    U8 nWKUPinNumber = GPIO_WKU_INVALID_PIN;
    switch (nPortNumber)
    {
        case GPIO_PORT_A:
            // valid WKU port A pins 2,3,6,7,12,13
            switch (nPinNumber)
            {
                case GPIO_PIN_2:
                    nWKUPinNumber = GPIO_WKU_25;
                    break;

                case GPIO_PIN_3:
                    nWKUPinNumber = GPIO_WKU_24;
                    break;

                case GPIO_PIN_6:
                    nWKUPinNumber = GPIO_WKU_19;
                    break;

                case GPIO_PIN_7:
                    nWKUPinNumber = GPIO_WKU_18;
                    break;

                case GPIO_PIN_12:
                    nWKUPinNumber = GPIO_WKU_31;
                    break;

                case GPIO_PIN_13:
                    nWKUPinNumber = GPIO_WKU_30;
                    break;

                default:
                    nWKUPinNumber = GPIO_WKU_INVALID_PIN;
                    break;

            }
            break; // port A WKU pins
        case GPIO_PORT_B:
            // valid WKU port B pins 0,1,12,13
            switch (nPinNumber)
            {
                case GPIO_PIN_0:
                    nWKUPinNumber = GPIO_WKU_17;
                    break;

                case GPIO_PIN_1:
                    nWKUPinNumber = GPIO_WKU_16;
                    break;

                case GPIO_PIN_12:
                    nWKUPinNumber = GPIO_WKU_21;
                    break;

                case GPIO_PIN_13:
                    nWKUPinNumber = GPIO_WKU_20;
                    break;

                default:
                    nWKUPinNumber = GPIO_WKU_INVALID_PIN;
                    break;

            }
            break; // port B WKU pins
        case GPIO_PORT_C:
            // valid WKU port C pins 0,1,2,3,6,7,14,15
            switch (nPinNumber)
            {
                case GPIO_PIN_0:
                    nWKUPinNumber = GPIO_WKU_13;
                    break;

                case GPIO_PIN_1:
                    nWKUPinNumber = GPIO_WKU_12;
                    break;

                case GPIO_PIN_2:
                    nWKUPinNumber = GPIO_WKU_10;
                    break;

                case GPIO_PIN_3:
                    nWKUPinNumber = GPIO_WKU_9;
                    break;

                case GPIO_PIN_6:
                    nWKUPinNumber = GPIO_WKU_27;
                    break;

                case GPIO_PIN_7:
                    nWKUPinNumber = GPIO_WKU_26;
                    break;

                case GPIO_PIN_14:
                    nWKUPinNumber = GPIO_WKU_15;
                    break;

                case GPIO_PIN_15:
                    nWKUPinNumber = GPIO_WKU_14;
                    break;

                default:
                    nWKUPinNumber = GPIO_WKU_INVALID_PIN;
                    break;

            }
            break; // port C WKU pins
        case GPIO_PORT_D:
            // valid WKU port D pins 2,3,5
            switch (nPinNumber)
            {
                case GPIO_PIN_2:
                    nWKUPinNumber = GPIO_WKU_23;
                    break;

                case GPIO_PIN_3:
                    nWKUPinNumber = GPIO_WKU_22;
                    break;

                case GPIO_PIN_5:
                    nWKUPinNumber = GPIO_WKU_11;
                    break;

                default:
                    nWKUPinNumber = GPIO_WKU_INVALID_PIN;
                    break;

            }
            break; // port D WKU pins
        case GPIO_PORT_E:
            // valid WKU port E pins 0,1,2,3,4,5,6,8,9,10,11
            switch (nPinNumber)
            {
                case GPIO_PIN_0:
                    nWKUPinNumber = GPIO_WKU_6;
                    break;

                case GPIO_PIN_1:
                    nWKUPinNumber = GPIO_WKU_5;
                    break;

                case GPIO_PIN_2:
                    nWKUPinNumber = GPIO_WKU_29;
                    break;

                case GPIO_PIN_3:
                    nWKUPinNumber = GPIO_WKU_4;
                    break;

                case GPIO_PIN_4:
                    nWKUPinNumber = GPIO_WKU_3;
                    break;

                case GPIO_PIN_5:
                    nWKUPinNumber = GPIO_WKU_2;
                    break;

                case GPIO_PIN_6:
                    nWKUPinNumber = GPIO_WKU_28;
                    break;

                case GPIO_PIN_8:
                    nWKUPinNumber = GPIO_WKU_8;
                    break;

                case GPIO_PIN_9:
                    nWKUPinNumber = GPIO_WKU_7;
                    break;

                case GPIO_PIN_10:
                    nWKUPinNumber = GPIO_WKU_1;
                    break;

                case GPIO_PIN_11:
                    nWKUPinNumber = GPIO_WKU_0;
                    break;

                default:
                    nWKUPinNumber = GPIO_WKU_INVALID_PIN;
                    break;

            }
            break; // port E WKU pins

        default:
            nWKUPinNumber = GPIO_WKU_INVALID_PIN;
            break;

    } // end of switch (nPortNumber)

    return nWKUPinNumber;
} // end of GPIO_WakeUpPinNumber()



//****************************************** end of file *******************************************
