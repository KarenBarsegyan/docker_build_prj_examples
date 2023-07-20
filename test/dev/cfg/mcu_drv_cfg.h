//**************************************************************************************************
// @Module      MCU driver
//! \file       mcu_drv_cfg.h
//! \brief      This file contains configuration for the MCU driver required functionality
//!
//! \par        History
//! | Date       | Version | Author  | Comment
//! |:----------:|:-------:|:-------:|--------------------------------------------------------------
//! | 10.05.2023 |  1.0.0  |   CAV   | First release.
//**************************************************************************************************

#ifndef MCU_DRV_CFG_H
#define MCU_DRV_CFG_H

//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************



//--------------------------------------------------------------------------------------------------
// High speed crystal oscillator HXTAL enables, frequency HXTAL (FXOSC)
//--------------------------------------------------------------------------------------------------

//! HXTAL enable
//! Valid values: ON / OFF
#define MCU_HXTAL_ENB           (ON)

//! Set HXTAL bypass mode enable (external input clocking)
//! Valid values: MCU_XTAL_BYPASS, MCU_XTAL_CRYSTAL
#define MCU_HXTAL_BYPASS        MCU_XTAL_CRYSTAL
//! Specify crystal or external input(bypass mode) frequency
//! Valid values: [4000000; 40000000] Hz
#define MCU_HXTAL               (24000000UL)

//! Set crystal amplifier gain
//! Valid values: [0; 15]
#define MCU_HXTAL_GAIN_SEL      (5U)

//--------------------------------------------------------------------------------------------------
// PLL setup
//--------------------------------------------------------------------------------------------------

//! \name PLL setup
//! @{
//! \def MCU_PLL_ENB
//! \brief PLL enable
//! Valid values: ON / OFF
#define MCU_PLL_ENB             (ON)

//! Select PLL reference clock
//! Valid values: MCU_PLL_REF_FXOSC_CLK, MCU_PLL_REF_FIRC_CLK
#define MCU_PLL_REF_SELECTION   MCU_PLL_REF_FXOSC_CLK

//! \def MCU_PLL
//! \brief Desired PLL clock frequency.
//! Valid values: [100000000; 120000000]
#define MCU_PLL                 (120000000UL)
//! @}

//--------------------------------------------------------------------------------------------------
// System clock selector (SYSCLK)
//--------------------------------------------------------------------------------------------------

//! Select system clock source:
//!     SIRC    - 12 MHz,
//!     FIRC    - 96 MHZ,
//!     HXTAL   - [4; 40] MHz,
//!     PLL     - [100; 120] MHz.
//! Valid values: MCU_SYSCLK_SEL_FIRC, MCU_SYSCLK_SEL_PLL,
//!              MCU_SYSCLK_SEL_HXTAL, MCU_SYSCLK_SEL_SIRC
#define MCU_SYSCLK_SELECTION    MCU_SYSCLK_SEL_PLL

//! \name Bus clock dividers
//! @{
//! Maximum bus friquency
//! \brief SYSCLK divider set core bus friquency. It must be less than 120 MHz
//! Valid values: [MCU_FREQUENCY_DIV_BY_1; MCU_FREQUENCY_DIV_BY_16]
#define MCU_SYSCLK_DIVIDER      MCU_FREQUENCY_DIV_BY_1
//! \brief FAST bus divider set Fast bus friquency. It must be less than 120 MHz
//! Valid values: [MCU_FREQUENCY_DIV_BY_1; MCU_FREQUENCY_DIV_BY_16]
#define MCU_FAST_BUS_DIVIDER    MCU_FREQUENCY_DIV_BY_1
//! \brief SLOW bus divider set core bus friquency. It must be less than 40 MHz
//! Valid values: [MCU_FREQUENCY_DIV_BY_1; MCU_FREQUENCY_DIV_BY_16]
#define MCU_SLOW_BUS_DIVIDER    MCU_FREQUENCY_DIV_BY_3
//! @}

//--------------------------------------------------------------------------------------------------
// Low speed crystal oscillator LXTAL enables, frequency LXTAL (SXOSC)
//--------------------------------------------------------------------------------------------------

//! \name LXTAL setup
//! @{
//! LXTAL enable
//! Valid values: ON / OFF
#define MCU_LXTAL_ENB           (OFF)
//! LXTAL bypass mode enable
//! Valid values: ON / OFF
#define MCU_LXTAL_BYPASS        MCU_XTAL_CRYSTAL
//! Specify LXTAL amplifier power
//! Valid values: ON / OFF
#define MCU_LXTAL_GAIN_SEL      (OFF)
//! @}

//--------------------------------------------------------------------------------------------------
// Setup MCU CMU
//--------------------------------------------------------------------------------------------------

//! Enable CMU (clock control unit) working
#define MCU_CMU_ENABLE              (OFF)

//! CMU0: check Slow Bus Clock
#define MCU_CMU_SLOW_BUS_CHECK_ENABLE       (OFF)
//! Reset due to SLOW bus malfunction
#define MCU_CMU_SLOW_BUS_RESET              (OFF)
//! CMU clock reference clock source
//! Valid selections MCU_CMU_REF_SIRC_CLOCK or MCU_CMU_REF_FXOSC_CLOCK
#define MCU_CMU_SLOW_BUS_REF           MCU_CMU_REF_SIRC_CLOCK
//! High bound frequency deviation
//! \brief High bound acceptable frequency deviation from MCU_SLOWCLK for project. Usually 110%.
//! Valid value: (MCU_SLOWCLK * 110) / 100    
#define MCU_CMU_SLOW_HIGH_BOUND             (44000000UL)
//! Low bound frequency deviation
//! \brief Low bound acceptable frequency deviation from MCU_FIRC for project. Usually 90%.
//! Valid value: (MCU_SLOWCLK * 90) / 100    
#define MCU_CMU_SLOW_LOW_BOUND              (36000000UL)

//! CMU1: check FIRC Clock
#define MCU_CMU_FIRC_CHECK_ENABLE       (OFF)
//! Reset due to FIRC malfunction
#define MCU_CMU_FIRC_RESET              (OFF)
//! CMU clock reference clock source
//! Valid selections MCU_CMU_REF_SIRC_CLOCK or MCU_CMU_REF_FXOSC_CLOCK
#define MCU_CMU_FIRC_REF           MCU_CMU_REF_SIRC_CLOCK
//! High bound frequency deviation
//! \brief High bound acceptable frequency deviation from MCU_FIRC for project. Usually 110%.
//! Valid value: (MCU_FIRC * 110) / 100    
#define MCU_CMU_FIRC_HIGH_BOUND             (100000000UL)
//! Low bound frequency deviation
//! \brief Low bound acceptable frequency deviation from MCU_FIRC for project. Usually 90%.
//! Valid value: (MCU_FIRC * 90) / 100    
#define MCU_CMU_FIRC_LOW_BOUND              (90000000UL)

//! CMU2: check PLL Clock
#define MCU_CMU_PLL_CHECK_ENABLE        (OFF)
//! Reset due to PLL malfunction
#define MCU_CMU_PLL_RESET               (OFF)
//! CMU clock reference clock source
//! Valid selections MCU_CMU_REF_SIRC_CLOCK or MCU_CMU_REF_FXOSC_CLOCK
#define MCU_CMU_PLL_REF            MCU_CMU_REF_SIRC_CLOCK
//! High bound frequency deviation
//! \brief High bound acceptable frequency deviation from MCU_PLL for project. Usually 110%.
//! Valid value: (MCU_PLL * 110) / 100    
#define MCU_CMU_PLL_HIGH_BOUND              (130000000UL)
//! Low bound frequency deviation
//! \brief Low bound acceptable frequency deviation from MCU_PLL for project. Usually 90%.
//! Valid value: (MCU_PLL * 90) / 100    
#define MCU_CMU_PLL_LOW_BOUND               (95000000UL)

//! CMU3: check HXTAL Clock.
#define MCU_CMU_HXTAL_CHECK_ENABLE      (OFF)
//! Reset due to HXTAL malfunction
#define MCU_CMU_HXTAL_RESET             (OFF)
//! Valid selections MCU_CMU_REF_SIRC_CLOCK
#define MCU_CMU_HXTAL_REF          MCU_CMU_REF_SIRC_CLOCK
//! High bound frequency deviation
//! \brief High bound acceptable frequency deviation from MCU_HXTAL for project. Usually 105%.
//! Valid value: (MCU_HXTAL * 105) / 100    
#define MCU_CMU_HXTAL_HIGH_BOUND            (40000000UL)
//! Low bound frequency deviation
//! \brief Low bound acceptable frequency deviation from MCU_HXTAL for project. Usually 95%.
//! Valid value: (MCU_HXTAL * 95) / 100    
#define MCU_CMU_HXTAL_LOW_BOUND             (4000000UL)

//--------------------------------------------------------------------------------------------------
// Setup MCU ClockOut
//--------------------------------------------------------------------------------------------------

//! \name CLKOUT parameters
//! @{
//!  \brief CLKOUT source implements only an even divisor for CLKOUT source friquency. In this case,
//! the odd MCU_CLKOUT_DIVIDER works as reduced by 1. If it is 1U or 0U, then there is no signal.
//!
//! CLOCKOUT enable
//! Valid values: ON / OFF
#define MCU_CLKOUT_ENABLE   (OFF)
//! CLOCKOUT clock source
//! Valid values: MCU_CLKOUT_SEL_DISABLE, MCU_CLKOUT_SEL_FIRC_CLK, MCU_CLKOUT_SEL_SIRC_CLK, \n
//! MCU_CLKOUT_SEL_FXOSC_CLK, MCU_CLKOUT_SEL_LXTAL_CLK, MCU_CLKOUT_SEL_PLL_CLK, \n
//!	MCU_CLKOUT_SEL_TRNG_CLK, MCU_CLKOUT_SEL_SYSCLK
#define MCU_CLKOUT_SOURCE   MCU_CLKOUT_SEL_FIRC_CLK
//! CLKOUT divider
//! It implements only an even divisor. The odd one works as reduced by 1.
//! Valid values: [2; 255]
#define MCU_CLKOUT_DIVIDER  (2U)
//! \name CLKOUT pin setup
//! @{
//! Valid values are: (PE10 ALT2), (PD14 ALT7), (PB5 ALT5), (PD10 ALT6)
#define MCU_CLKOUT_PORT     MCU_PORT_D
#define MCU_CLKOUT_PIN      MCU_PIN_10
//! @}
//! @}



#endif  // end #ifndef MCU_DRV_CFG_H

//****************************************** end of file *******************************************
