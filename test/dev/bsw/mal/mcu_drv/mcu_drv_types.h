//**************************************************************************************************
// @Module      MCU driver
//! \file       mcu_drv_types.h
//! \brief      This file contains configuration of the MCU_driver required functionality
//!
//! \par        History
//! |Date       | Version | Author  | Comment
//! |:---------:|:-------:|:-------:|---------------------------------------------------------------
//! |17.05.2023 |  1.0.0  |   CAV   | First release.
//**************************************************************************************************

#ifndef MCU_DRV_TYPES_H
#define MCU_DRV_TYPES_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************



//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************

// None.



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

// Platform Clock Divider Value
//! \name Bus frequency dividers
//! @{
//! Divide by 1
#define MCU_FREQUENCY_DIV_BY_1 (0U)
//! Divide by 2
#define MCU_FREQUENCY_DIV_BY_2 (1U)
//! Divide by 3
#define MCU_FREQUENCY_DIV_BY_3 (2U)
//! Divide by 4
#define MCU_FREQUENCY_DIV_BY_4 (3U)
//! Divide by 5
#define MCU_FREQUENCY_DIV_BY_5 (4U)
//! Divide by 6
#define MCU_FREQUENCY_DIV_BY_6 (5U)
//! Divide by 7
#define MCU_FREQUENCY_DIV_BY_7 (6U)
//! Divide by 8
#define MCU_FREQUENCY_DIV_BY_8 (7U)
//! Divide by 9
#define MCU_FREQUENCY_DIV_BY_9 (8U)
//! Divide by 10
#define MCU_FREQUENCY_DIV_BY_10 (9U)
//! Divide by 11
#define MCU_FREQUENCY_DIV_BY_11 (10U)
//! Divide by 12
#define MCU_FREQUENCY_DIV_BY_12 (11U)
//! Divide by 13
#define MCU_FREQUENCY_DIV_BY_13 (12U)
//! Divide by 14
#define MCU_FREQUENCY_DIV_BY_14 (13U)
//! Divide by 15
#define MCU_FREQUENCY_DIV_BY_15 (14U)
//! Divide by 16
#define MCU_FREQUENCY_DIV_BY_16 (15U)
//! @}

//! \name GPIO ports name definitions
//! @{
#define MCU_PORT_A                                 (0U)
#define MCU_PORT_B                                 (1U)
#define MCU_PORT_C                                 (2U)
#define MCU_PORT_D                                 (3U)
#define MCU_PORT_E                                 (4U)
#define MCU_PORT_LAST                              (MCU_PORT_E)
//! Quantity of ports
#define MCU_PORTS_QTY                              (MCU_PORT_LAST + 1U)
// @}

//! \name Pins names definitions
//! @{
#define MCU_PIN_FIRST           (MCU_PIN_0)
#define MCU_PIN_0               (0U)
#define MCU_PIN_1               (1U)
#define MCU_PIN_2               (2U)
#define MCU_PIN_3               (3U)
#define MCU_PIN_4               (4U)
#define MCU_PIN_5               (5U)
#define MCU_PIN_6               (6U)
#define MCU_PIN_7               (7U)
#define MCU_PIN_8               (8U)
#define MCU_PIN_9               (9U)
#define MCU_PIN_10              (10U)
#define MCU_PIN_11              (11U)
#define MCU_PIN_12              (12U)
#define MCU_PIN_13              (13U)
#define MCU_PIN_14              (14U)
#define MCU_PIN_15              (15U)
#define MCU_PIN_24              (24U)
#define MCU_PIN_17              (17U)
#define MCU_PIN_18              (18U)
#define MCU_PIN_19              (19U)
#define MCU_PIN_20              (20U)
#define MCU_PIN_21              (21U)
#define MCU_PIN_22              (22U)
#define MCU_PIN_23              (23U)
#define MCU_PIN_24              (24U)
#define MCU_PIN_25              (25U)
#define MCU_PIN_26              (26U)
#define MCU_PIN_27              (27U)
#define MCU_PIN_28              (28U)
#define MCU_PIN_29              (29U)
#define MCU_PIN_30              (30U)
#define MCU_PIN_31              (31U)
#define MCU_PIN_LAST            (MCU_PIN_31)
//! Quantity of pins
#define MCU_PINS_QTY            (MCU_PIN_LAST + 1U)
//! @}

//! \name Pin multiplexer constants
//! @{
#define MCU_MUX_ALT_0           (0U)
#define MCU_MUX_ALT_1           (1U)
#define MCU_MUX_ALT_2           (2U)
#define MCU_MUX_ALT_3           (3U)
#define MCU_MUX_ALT_4           (4U)
#define MCU_MUX_ALT_5           (5U)
#define MCU_MUX_ALT_6           (6U)
#define MCU_MUX_ALT_7           (7U)
//! @}

//! \name System clock sources
//! @{
// FIRC as system clock source
#define MCU_SYSCLK_SEL_FIRC  (0x0U)
// PLL as system clock source
#define MCU_SYSCLK_SEL_PLL   (0x1U)
// HXTAL as system clock source
#define MCU_SYSCLK_SEL_HXTAL (0x2U)
// SIRC as system clock source
#define MCU_SYSCLK_SEL_SIRC  (0x3U)
//! @}

//! \name External or Internal XTAL selection
//! @{
//! MCU_XTAL_BYPASS - use external external input clocking
#define MCU_XTAL_BYPASS         (OFF)
//! MCU_XTAL_CRYSTAL - use internal clock generator
#define MCU_XTAL_CRYSTAL		(ON)
//! @}

//! \name PLL reference clock sources
//! @{ PLL use HXTAL as reference clock
#define MCU_PLL_REF_FXOSC_CLK   (0U)
//! SCU PLL use FIRC as reference clock
#define MCU_PLL_REF_FIRC_CLK    (1U)
//! @}

//! PLL reference frequency
#if (MCU_PLL_REF_FIRC_CLK == MCU_PLL_REF_SELECTION)
    #define MCU_PLL_REF_FREQUENCY   MCU_FIRC
#else
    #define MCU_PLL_REF_FREQUENCY   MCU_HXTAL
#endif

//! Minimum VCO PLL frequency
#define MCU_DRV_PLL_VCO_MIN_FREQUENCY (200000000UL)

//! Maximum VCO PLL frequency
#define MCU_DRV_PLL_VCO_MAX_FREQUENCY (400000000UL)

//! Minimum PLL VCO multiplier
#define MCU_VCO_MIN_MULT (MCU_DRV_PLL_VCO_MIN_FREQUENCY / MCU_PLL_REF_FREQUENCY)

//! Maximum PLL VCO multiplier
#define MCU_VCO_MAX_MULT (MCU_DRV_PLL_VCO_MAX_FREQUENCY / MCU_PLL_REF_FREQUENCY)

//! SIRC frequency
#define MCU_SIRC                (12000000UL)

//! \name LXTAL setup
//! @{
//! Crystal frequency
#define MCU_LXTAL               (32768UL)
//! @}

//! \name SMU reference clock source
//! @{
//! Use SIRC as CMU clock reference clock source
#define MCU_CMU_REF_SIRC_CLOCK    (0U)
//! Use FXOSC as CMU clock reference clock source
#define MCU_CMU_REF_FXOSC_CLOCK   (1U)
//! @}

//! \name CLKOUT sources
//! @{
//! SCU CLKOUT Disable
#define MCU_CLKOUT_SEL_DISABLE      (0U)
//! SCU CLKOUT Select FIRC CLK
#define MCU_CLKOUT_SEL_FIRC_CLK     (1U)
//! SCU CLKOUT Select SIRC CLK
#define MCU_CLKOUT_SEL_SIRC_CLK     (2U)
//! SCU CLKOUT Select HXTAL CLK
#define MCU_CLKOUT_SEL_FXOSC_CLK    (3U)
//! SCU CLKOUT Select LXTAL CLK
#define MCU_CLKOUT_SEL_LXTAL_CLK    (4U)
//! SCU CLKOUT Select PLL CLK
#define MCU_CLKOUT_SEL_PLL_CLK      (5U)
//! SCU CLKOUT Select TRNG ring oscillator output
#define MCU_CLKOUT_SEL_TRNG_CLK     (6U)
//! SCU CLKOUT Select SYSCLK
#define MCU_CLKOUT_SEL_SYSCLK       (7U)
//! @}

//! Define FIRC frequency
#define MCU_FIRC                (96000000UL)

// Calculate BUS0 source frequency for verification
#if (MCU_SYSCLK_SEL_PLL == MCU_SYSCLK_SELECTION)
    #if (OFF == MCU_PLL_ENB)
        #error "Use PLL when MCU_PLL_ENB == OFF"
    #endif
    #define  MCU_CLOCK_BUS0         MCU_PLL
#elif (MCU_SYSCLK_SEL_FIRC == MCU_SYSCLK_SELECTION)
    #define  MCU_CLOCK_BUS0         MCU_FIRC
#elif (MCU_SYSCLK_SEL_SIRC == MCU_SYSCLK_SELECTION)
    #define  MCU_CLOCK_BUS0         MCU_SIRC
#elif (MCU_SYSCLK_SEL_HXTAL == MCU_SYSCLK_SELECTION)
    #define  MCU_CLOCK_BUS0         MCU_HXTAL
#endif

// Calculate Bus Clocks
//! Calculate System Clock    MCU_CLOCK_SOURCE_BUS1
#define MCU_SYSCLK                  (MCU_CLOCK_BUS0/(MCU_SYSCLK_DIVIDER+1UL))
//! Calculate Fast Bus Clock  MCU_CLOCK_SOURCE_BUS2
#define MCU_FASTCLK                 (MCU_SYSCLK/(MCU_FAST_BUS_DIVIDER+1UL))
//! Calculate Slow Bus Clock MCU_CLOCK_SOURCE_BUS4
#define MCU_SLOWCLK                 (MCU_CLOCK_BUS2/(MCU_SLOW_BUS_DIVIDER+1UL))
// Define BUS names
#define MCU_CLOCK_BUS1              MCU_SYSCLK
#define MCU_CLOCK_BUS2              MCU_FASTCLK
#define MCU_CLOCK_BUS3              MCU_SLOWCLK

// Check CMU config
// Enable control of the clock unit working
#if (MCU_CMU_ENABLE)
    // CMU0: check Slow Bus Clock
    #if (MCU_CMU_SLOW_BUS_CHECK_ENABLE)
        #if (MCU_CMU_REF_SIRC_CLOCK == MCU_CMU_SLOW_BUS_REF)
            #if (0UL == MCU_SIRC)
                #error "CMU_SLOW_BUS_REF configured wrong!"
            #endif
            // Calculate CMU register values
            #define MCU_CMU_SLOW_BUS_COMPAREHIGH    (((MCU_CMU_SLOW_HIGH_BOUND / 1000U) * 128U) / \
                                                     (MCU_SIRC / 1000UL))
            #define MCU_CMU_SLOW_BUS_COMPARELOW     (((MCU_CMU_SLOW_LOW_BOUND / 1000U) * 128U) /  \
                                                     (MCU_SIRC / 1000UL))
        #else
            #if (0UL == MCU_HXTAL)
                #error "CMU_SLOW_BUS_REF configured wrong!"
            #endif
            // Calculate CMU register values
            #define MCU_CMU_SLOW_BUS_COMPAREHIGH    (((MCU_CMU_SLOW_HIGH_BOUND / 1000U) * 128U) / \
                                                     (MCU_HXTAL / 1000UL))
            #define MCU_CMU_SLOW_BUS_COMPARELOW     (((MCU_CMU_SLOW_LOW_BOUND / 1000U) * 128U) /  \
                                                     (MCU_HXTAL / 1000UL))
        #endif
    #else
        #define MCU_CMU_SLOW_BUS_COMPAREHIGH    (0U)
        #define MCU_CMU_SLOW_BUS_COMPARELOW     (0U)
    #endif
    // CMU1: check FIRC Clock
    #if (MCU_CMU_FIRC_CHECK_ENABLE)
        #if (MCU_CMU_REF_SIRC_CLOCK == MCU_CMU_FIRC_REF)
            #if (0UL == MCU_SIRC)
                #error "CMU_FIRC_REF configured wrong!"
            #endif
            #define MCU_CMU_FIRC_COMPAREHIGH    (((MCU_CMU_FIRC_HIGH_BOUND / 1000U) * 128U) / \
                                                 (MCU_SIRC / 1000UL))
            #define MCU_CMU_FIRC_COMPARELOW     (((MCU_CMU_FIRC_LOW_BOUND / 1000U) * 128U) /  \
                                                 (MCU_SIRC / 1000UL))
        #else
            #if (0UL == MCU_HXTAL)
                #error "CMU_SLOW_BUS_REF configured wrong!"
            #endif
            // Calculate CMU register values
            #define MCU_CMU_FIRC_COMPAREHIGH    (((MCU_CMU_FIRC_HIGH_BOUND / 1000U) * 128U) / \
                                                 (MCU_HXTAL / 1000UL))
            #define MCU_CMU_FIRC_COMPARELOW     (((MCU_CMU_FIRC_LOW_BOUND / 1000U) * 128U) / \
                                                 (MCU_HXTAL / 1000UL))
        #endif
    #else
        #define MCU_CMU_FIRC_COMPAREHIGH        (0U)
        #define MCU_CMU_FIRC_COMPARELOW         (0U)
    #endif
    // CMU2: check PLL Clock
    #if (MCU_CMU_PLL_CHECK_ENABLE)
        #if (MCU_CMU_REF_SIRC_CLOCK == MCU_CMU_PLL_REF)
            #if (0UL == MCU_SIRC)
                #error "CMU_PLL_REF configured wrong!"
            #endif
            #define MCU_CMU_PLL_COMPAREHIGH     (((MCU_CMU_PLL_HIGH_BOUND / 1000U) * 128U) / \
                                                 (MCU_SIRC / 1000UL))
            #define MCU_CMU_PLL_COMPARELOW      (((MCU_CMU_PLL_LOW_BOUND / 1000U) * 128U) / \
                                                 (MCU_SIRC / 1000UL))
        #else
            #if (0UL == MCU_HXTAL)
                #error "CMU_PLL_REF configured wrong!"
            #endif
            // Calculate CMU register values
            #define MCU_CMU_PLL_COMPAREHIGH     (((MCU_CMU_PLL_HIGH_BOUND / 1000U) * 128U) / \
                                                 (MCU_HXTAL / 1000UL))
            #define MCU_CMU_PLL_COMPARELOW      (((MCU_CMU_PLL_LOW_BOUND / 1000U) * 128U) / \
                                                 (MCU_HXTAL / 1000UL))
        #endif
    #else
        #define MCU_CMU_PLL_COMPAREHIGH         (0U)
        #define MCU_CMU_PLL_COMPARELOW          (0U)
    #endif
    // CMU3: check HXTAL Clock.
    #if (MCU_CMU_HXTAL_CHECK_ENABLE)
        #if (MCU_CMU_REF_SIRC_CLOCK == MCU_CMU_HXTAL_REF)
            #if (0UL == MCU_SIRC)
                #error "CMU_HXTAL_REF configured wrong!"
            #endif
        #else
                #error "CMU_HXTAL_REF configured wrong!"
        #endif
        #define MCU_CMU_HXTAL_COMPAREHIGH   (((MCU_CMU_HXTAL_HIGH_BOUND / 1000U) * 128U) / \
                                             (MCU_SIRC / 1000UL))
        #define MCU_CMU_HXTAL_COMPARELOW    (((MCU_CMU_HXTAL_LOW_BOUND / 1000U) * 128U) / \
                                             (MCU_SIRC / 1000UL))
    #else
        #define MCU_CMU_HXTAL_COMPAREHIGH       (0U)
        #define MCU_CMU_HXTAL_COMPARELOW        (0U)
    #endif
#else
    #define MCU_CMU_SLOW_BUS_COMPAREHIGH    (0U)
    #define MCU_CMU_SLOW_BUS_COMPARELOW     (0U)
    #define MCU_CMU_FIRC_COMPAREHIGH        (0U)
    #define MCU_CMU_FIRC_COMPARELOW         (0U)
    #define MCU_CMU_PLL_COMPAREHIGH         (0U)
    #define MCU_CMU_PLL_COMPARELOW          (0U)
    #define MCU_CMU_HXTAL_COMPAREHIGH       (0U)
    #define MCU_CMU_HXTAL_COMPARELOW        (0U)
#endif



//**************************************************************************************************
// Declarations of global (public) variables
//**************************************************************************************************

// None.



//**************************************************************************************************
// Declarations of global (public) functions
//**************************************************************************************************

// None.



#endif  // end #ifndef MCU_DRV_TYPES_H

//****************************************** end of file *******************************************

