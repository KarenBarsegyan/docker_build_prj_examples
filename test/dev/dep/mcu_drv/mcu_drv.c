//**************************************************************************************************
// @Module  MCU driver
//! \file       mcu_drv.c
//! \par    Platform
//!             YTM32B1ME05
//! \par    Compatible
//!             YTM32B1ME05G0MLHT, YTM32B1ME05G0MLLT, YTM32B1ME05G0MLQT
//! \brief  Implementation of the MCU driver functionality.
//!
//! \par    Abbreviations
//!                 CMU     - Clock Monitor Unit
//!                 FIRC    - Fast Internal RC Oscillator
//!                 FXOSC   - Fast Crystal Oscillator
//!                 HXTAL   - Fast Crystal Oscillator
//!                 LXTAL   - Slow Crystal Oscillator
//!                 MCU     - Micro Controller Unit
//!                 PLL     - Phase-Locked Loop
//!                 RTC     - Real Time Clock
//!                 SCU     - System Clock Unit
//!                 SIRC    - Slow Internal RC oscillator
//!                 SXOSC   - Slow Crystal Oscillator
//!
//! \par    History
//! | Date       | Version | Author | Comment
//! |:----------:|:-------:|:------:|---------------------------------------------------------------
//! | 10.05.2023 |  1.0.0  |   CAV  | First release.
//**************************************************************************************************



//**************************************************************************************************
//! \defgroup   MCU_DRV MCU Driver
//! \brief      Implementation of the MCU driver functionality
//! \addtogroup MCU_DRV
//! @{
//! \file mcu_drv.h
//! \file mcu_drv.c
//! \file mcu_drv_cfg.h.tmpl
//! \file mcu_drv_types.h
//! @}
//**************************************************************************************************



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// MCU header
#include "mcu_drv.h"

// Get of MCU constants definition
#include "mcu_drv_types.h"

// Get register definitions
#include "derivative_cfg.h"



//**************************************************************************************************
// Verification of the imported configuration parameters
//**************************************************************************************************

// Check SYSCLK
#if (120000000UL < MCU_SYSCLK)
    #error "mcu_drv_cfg.h: MCU_SYSCLK must be less 120 MHz"
#endif // #if (MCU_SYSCLK>120MHz)

// Check FXOSC  (HXTAL)
#if ((ON == MCU_HXTAL_ENB) && (ON == MCU_HXTAL_BYPASS))
    #if (( 4000000UL > MCU_HXTAL) || (40000000UL < MCU_HXTAL ))
    #error "mcu_drv_cfg.h: MCU_HXTAL must be in the range from 4 MHz to 40 MHz"
    #endif
#endif // #if ((ON == MCU_HXTAL_ENB) && (ON == MCU_HXTAL_BYPASS))

// Check PLL setup
#if (ON == MCU_PLL_ENB)
    #if ((100000000UL > MCU_PLL) || (120000000UL < MCU_PLL))
        #error "mcu_drv_cfg.h: MCU_PLL must be from 100 to 120 MHz"
    #endif
    #if(MCU_PLL_REF_FXOSC_CLK == MCU_PLL_REF_SELECTION)
        #if (OFF == MCU_HXTAL_ENB)
            #error "mcu_drv_cfg.h: MCU_HXTAL as PLL reference clock is OFF"
        #endif
    #endif
    // Desired frequency multiplier
    #define MCU_PLL_DESIRED_MULT   ((2 * MCU_PLL) / MCU_PLL_REF_FREQUENCY)
    // Check hardware possibility
    #if ((MCU_VCO_MIN_MULT > MCU_PLL_DESIRED_MULT) || (MCU_VCO_MAX_MULT < MCU_PLL_DESIRED_MULT))
        #error "mcu_drv_cfg.h: Impossible PLL frequency!"
    #endif
    //! reference Clock Divider Value
    #define MCU_PLL_REFDIV (63U / (MCU_PLL_DESIRED_MULT + 1U))
    #if (16U < MCU_PLL_REFDIV)
        // Extra loop for low desired multiplier
        #undef MCU_PLL_REFDIV
        #define MCU_PLL_REFDIV (16U)
    #endif
    //! PLL feedback divider value.
    #define MCU_PLL_FBDIV  ((MCU_PLL_REFDIV * 2U * MCU_PLL) / MCU_PLL_REF_FREQUENCY)
    #if (64U < MCU_PLL_FBDIV)
        #error "MCU_PLL_FBDIV wrong"
    #endif
#else
    #define MCU_PLL_REFDIV (1U)
    #define MCU_PLL_FBDIV (1U)
#endif // #if ((ON == MCU_PLL_ENB) && (ON == MCU_PLL_BYPASS))

// Check CLKOUT setup
#if (ON == MCU_CLKOUT_ENABLE)
    // Check CLKOUT pin setup
    // Valid values are: (PB5 ALT5), (PD10 ALT6), (PD14 ALT7), (PE10 ALT2)
    #if (MCU_PORT_A == MCU_CLKOUT_PORT)
        #error "Port/pin/mux of CLKOUT configured wrong!"
    #endif
    #if (MCU_PORT_B == MCU_CLKOUT_PORT)
        #if (5U == MCU_CLKOUT_PIN)
            #define MCU_CLKOUT_MUX MCU_MUX_ALT_5
        #else
            #error "Port/pin/mux of CLKOUT configured wrong!"
        #endif
    #endif
    #if (MCU_PORT_C == MCU_CLKOUT_PORT)
        #error "Port/pin/mux of CLKOUT configured wrong!"
    #endif
    #if (MCU_PORT_D == MCU_CLKOUT_PORT)
        #if (10U == MCU_CLKOUT_PIN)
            #define MCU_CLKOUT_MUX MCU_MUX_ALT_6
        #elif (14U == MCU_CLKOUT_PIN)
            #define MCU_CLKOUT_MUX MCU_MUX_ALT_7
        #else
             #error "Port/pin/mux of CLKOUT configured wrong!"
        #endif
    #endif
    #if (MCU_PORT_E == MCU_CLKOUT_PORT)
        #if (10U == MCU_CLKOUT_PIN)
            #define MCU_CLKOUT_MUX MCU_MUX_ALT_2
        #else
            #error "Port/pin/mux of CLKOUT configured wrong!"
        #endif
    #endif
    // Select CLKOUT pin control registers
    #if (MCU_PORT_A == MCU_CLKOUT_PORT)
        #define MCU_CLKOUT_GPIO     (&GPIOA)
        #define MCU_CLKOUT_PCTRL    (&PCTRLA)
    #elif (MCU_PORT_B == MCU_CLKOUT_PORT)
        #define MCU_CLKOUT_GPIO     (&GPIOB)
        #define MCU_CLKOUT_PCTRL    (&PCTRLB)
    #elif (MCU_PORT_C == MCU_CLKOUT_PORT)
        #define MCU_CLKOUT_GPIO     (&GPIOC)
        #define MCU_CLKOUT_PCTRL    (&PCTRLC)
    #elif (MCU_PORT_D == MCU_CLKOUT_PORT)
        #define MCU_CLKOUT_GPIO     (&GPIOD)
        #define MCU_CLKOUT_PCTRL    (&PCTRLD)
    #elif (MCU_PORT_E == MCU_CLKOUT_PORT)
        #define MCU_CLKOUT_GPIO     (&GPIOE)
        #define MCU_CLKOUT_PCTRL    (&PCTRLE)
    #endif

    // Check CLOCKOUT clock source
    // Valid values: MCU_CLKOUT_SEL_DISABLE, MCU_CLKOUT_SEL_FIRC_CLK, MCU_CLKOUT_SEL_SIRC_CLK,
    // MCU_CLKOUT_SEL_FXOSC_CLK, MCU_CLKOUT_SEL_LXTAL_CLK, MCU_CLKOUT_SEL_PLL_CLK,
    // MCU_CLKOUT_SEL_SYSCLK
    #if (MCU_CLKOUT_SEL_SYSCLK < MCU_CLKOUT_SOURCE)
        #error "CLKOUT source wrong!"
    #endif
    #if (MCU_CLKOUT_SEL_DISABLE == MCU_CLKOUT_SOURCE)
        #error "CLKOUT source wrong!"
    #endif
    #if ((MCU_CLKOUT_SEL_PLL_CLK == MCU_CLKOUT_SOURCE) && (OFF == MCU_PLL_ENB))
        #error "Use PLL when MCU_PLL_ENB == OFF"
    #endif

#else
    #define MCU_CLKOUT_GPIO     (&GPIOB)
    #define MCU_CLKOUT_PCTRL    (&PCTRLB)
    #define MCU_CLKOUT_MUX      (0U)
#endif



//**************************************************************************************************
// Definitions of global (public) variables
//**************************************************************************************************

// None.



//**************************************************************************************************
// Declarations of local (private) data types
//**************************************************************************************************

//! \brief Function type to perform code execution jump
typedef void (*MCU_JUMP_ADDRESS)(void);

//! \brief Implements HXTAL configuration
typedef struct
{
    U32     frequency;      //!< HXTAL frequency
    BOOLEAN enable;         //!< HXTAL enable
    BOOLEAN bypassMode;     //!< HXTAL bypass mode
    U8 		gainSelection;  //!< HXTAL gain selection
} MCU_HXTAL_CONFIG;

//! \brief Implements LXTAL configuration
typedef struct
{
    U32     frequency;      //!< SXOSC frequency
    BOOLEAN enable;         //!< SXOSC enable
    BOOLEAN gainSelection;  //!< SXOSC gain selection
    BOOLEAN bypassMode;     //!< SXOSC bypass mode
    BOOLEAN deepsleepEnable;//!< SXOSC deep sleep enable
    BOOLEAN standbyEnable;  //!< SXOSC standby enable
    BOOLEAN powerdownEnable;//!< SXOSC power down enable
} MCU_LXTAL_CONFIG;

//! \brief Implements PLL setup description structure
typedef struct
{
    BOOLEAN enable;     //!< PLL enable or not
    U8 pllRefClock; 	//!< PLL reference clock source
    U8 pllFeedBackDiv;  //!< PLL Feedback clock divider
    U8 pllRefClkDiv;    //!< PLL Reference clock divider
} MCU_PLL_CONFIG;

//! \brief Implements output clock control type
typedef struct
{
    BOOLEAN enable; //!< SCU ClockOut enable or not.
    U8 divider;     //!< SCU ClockOut divider
    U8 source;      //!< SCU ClockOut source select.
    U8 port;        //!< SCU ClockOut GPIO port select
    U8 pin;         //!< SCU ClockOut GPIO pin  select
    U8 mux;         //!< SCU ClockOut GPIO mux  select
} MCU_CLOCK_OUT_CONFIG;

//! \brief Implements frequency control parameters for CMU
typedef struct
{
    U16 compareHigh;    //!< CMU counter compare high threshold
    U16 compareLow;     //!< CMU counter compare low threshold
    BOOLEAN enable;     //!< Specifies whether the channel is enabled or disabled
    BOOLEAN resetEnable;//!< Specifies whether the channel clock error reset enable
    BOOLEAN refClock;   //!< CMU reference clock selection
} MCU_CLK_CHECK;

//! \brief MCU CMU setup description type
typedef struct
{
    MCU_CLK_CHECK slowBusMonitor;      //!< Clock monitor for slow bus clock
    MCU_CLK_CHECK fircClockMonitor;    //!< Clock monitor for FIRC clock
    MCU_CLK_CHECK pllClockMonitor;     //!< Clock monitor for PLL clock
    MCU_CLK_CHECK hxtalClockMonitor;   //!< Clock monitor for HXTAL clock
} MCU_CMU_CONFIG;

//! \brief MCU clocks configure structure
typedef struct
{
    BOOLEAN sircDeepSleepEnable;         //!< SIRC deep sleep enable
    BOOLEAN sircStandbyEnable;           //!< SIRC standby enable
    BOOLEAN sircPowerDownEnable;         //!< SIRC power down enable
    BOOLEAN fircEnable;                  //!< FIRC enable
    BOOLEAN fircDeepSleepEnable;         //!< FIRC deep sleep enable
    U8 sysClkSrc;                        //!< Core clock selection
    U8 sysDiv;                           //!< system clock divider
    U8 fastBusDiv;                       //!< IPS Fast Bus clock divider
    U8 slowBusDiv;                       //!< IPS Slow Bus clock divider
    MCU_PLL_CONFIG pllConfig;            //!< PLL configuration.
    MCU_LXTAL_CONFIG lxtalConfig;        //!< External slow oscillator configuration.
    MCU_HXTAL_CONFIG hxtalConfig;        //!< External fast oscillator configuration.
    MCU_CLOCK_OUT_CONFIG clockOutConfig; //!< Clock Out configuration.
    MCU_CMU_CONFIG clockCheckConfig;     //!< CMU parameters
    U8 flashDiv;                         //!< Flash Clock divider
    U8 flashPrs;                         //!< Flash clock prescaler
} MCU_CLOCK_CONFIG;



//**************************************************************************************************
// Definitions of local (private) constants
//**************************************************************************************************

//! Flash memory wait state calculate constant. One tick per 50 MHz
#define MCU_FLASH_WAIT_STATE_BOUND  (50000000UL)

//! Timeout of stabilized lock timeout loop count
#define MCU_CLOCK_TIMEOUT_LOOP_CNT                    (0x1FFFFUL)

//! \name MCU pins setup values
//! @{
//! GPIO strength enable
#define MCU_STRENGTH_LOW       (0U)
#define MCU_STRENGTH_HIGH      (1U)
//! GPIO passive filter
#define MCU_PFE_ENABLE         (1U)
#define MCU_PFE_DISABLE        (0U)
//! GPIO slew rate
#define MCU_FAST_SLEW_RATE     (0U)
#define MCU_SLOW_SLEW_RATE     (1U)
//! Types of GPIO PULL_ENABLE
#define MCU_PULL_ENABLE        (1U)
#define MCU_PULL_DISABLE       (0U)
//! Types of GPIO PULL_MODE
#define MCU_PULL_DOWN          (0U)
#define MCU_PULL_UP            (1U)
//! @}

//! \name MCU Reset register constants
//! @{
//! Key for AIRCR register
#define MCU_AIRCR_VECTKEY    (0x5FU)
//! Key for AIRCR position in register
#define MCU_SCB_AIRCR_VECTKEY_POS             (16U)
//! Position of System reset request bit
#define MCU_SCB_AIRCR_SYSRESETREQ_POS         (2U)
//! SCB AIRCR: PRIGROUP Position
#define MCU_SCB_AIRCR_PRIGROUP_POS            (8U)
//! SCB AIRCR: PRIGROUP Mask
#define MCU_SCB_AIRCR_PRIGROUP_MSK            (7UL << MCU_SCB_AIRCR_PRIGROUP_POS)
//! SCB AIRCR: SYSRESETREQ Mask
#define MCU_SCB_AIRCR_SYSRESETREQ_MSK         (1UL << MCU_SCB_AIRCR_SYSRESETREQ_POS)
//! @}

//! \name IPC pin control indexes
//! @{
#define MCU_IPC_GPIO_INDEX   (17U)
#define MCU_IPC_PCTRLA_INDEX (18U)
#define MCU_IPC_PCTRLB_INDEX (19U)
#define MCU_IPC_PCTRLC_INDEX (20U)
#define MCU_IPC_PCTRLD_INDEX (21U)
#define MCU_IPC_PCTRLE_INDEX (22U)
//! @}

//! Set zero bit to Value
#define MCU_Set1Bit(Value) (1U & (Value))

//! Set 2 bits to Value
#define MCU_Set2Bits(Value) (3U & (Value))

//! Set 3 bits to Value
#define MCU_Set3Bits(Value) (7U & (Value))

//! Set 4 bits to Value
#define MCU_Set4Bits(Value) (15U & (Value))

//! Set 4 bits to Value
#define MCU_Set6Bits(Value) (63U & (Value))



//**************************************************************************************************
// Definitions of static global (private) variables
//**************************************************************************************************

static MCU_CLOCK_CONFIG MCU_Config = {
    .fircEnable = TRUE,
    .sircDeepSleepEnable = TRUE,
    .sircPowerDownEnable = TRUE,
    .sysClkSrc = MCU_SYSCLK_SELECTION,
    .hxtalConfig =
    {
        .enable = MCU_HXTAL_ENB,
        .bypassMode = MCU_HXTAL_BYPASS,
        .gainSelection = MCU_HXTAL_GAIN_SEL,
        .frequency = MCU_HXTAL
    },
    .lxtalConfig =
    {
        .enable = MCU_LXTAL_ENB,
        .bypassMode = MCU_LXTAL_BYPASS,
        .gainSelection = MCU_LXTAL_GAIN_SEL,
        .deepsleepEnable = TRUE,
        .standbyEnable = TRUE,
        .powerdownEnable = TRUE,
        .frequency = MCU_LXTAL
    },
    .pllConfig =
    {
        .enable = MCU_PLL_ENB,
        .pllRefClock = MCU_PLL_REF_SELECTION,
        .pllFeedBackDiv = MCU_PLL_FBDIV,
        .pllRefClkDiv = MCU_PLL_REFDIV,
    },
    .sysDiv = MCU_SYSCLK_DIVIDER,
    .fastBusDiv = MCU_FAST_BUS_DIVIDER,
    .slowBusDiv = MCU_SLOW_BUS_DIVIDER,
    .flashDiv = MCU_FREQUENCY_DIV_BY_3,
    .clockOutConfig =
    {
        .enable = MCU_CLKOUT_ENABLE,
        .source = MCU_CLKOUT_SOURCE,
        .divider = MCU_CLKOUT_DIVIDER,
        .port = MCU_CLKOUT_PORT,
        .pin = MCU_CLKOUT_PIN,
        .mux = MCU_CLKOUT_MUX,
    },
    .clockCheckConfig =
    {
        // Check Slow Bus Clock
        .slowBusMonitor = {
            .enable = MCU_CMU_SLOW_BUS_CHECK_ENABLE,
            .resetEnable = MCU_CMU_SLOW_BUS_RESET,
            .refClock = MCU_CMU_SLOW_BUS_REF,
            .compareHigh = MCU_CMU_SLOW_BUS_COMPAREHIGH,
            .compareLow = MCU_CMU_SLOW_BUS_COMPARELOW,
        },
        // Check FIRC Clock
        .fircClockMonitor = {
            .enable = MCU_CMU_FIRC_CHECK_ENABLE,
            .resetEnable = MCU_CMU_FIRC_RESET,
            .refClock = MCU_CMU_FIRC_REF,
            .compareHigh = MCU_CMU_FIRC_COMPAREHIGH,
            .compareLow = MCU_CMU_FIRC_COMPARELOW,
        },
        // Check PLL Clock
        .pllClockMonitor = {
            .enable = MCU_CMU_PLL_CHECK_ENABLE,
            .resetEnable = MCU_CMU_PLL_RESET,
            .refClock = MCU_CMU_PLL_REF,
            .compareHigh = MCU_CMU_PLL_COMPAREHIGH,
            .compareLow = MCU_CMU_PLL_COMPARELOW,
        },
        // Check HXTAL Clock.
        .hxtalClockMonitor = {
            .enable = MCU_CMU_HXTAL_CHECK_ENABLE,
            .resetEnable = MCU_CMU_HXTAL_RESET,
            .refClock = MCU_CMU_HXTAL_REF,
            .compareHigh = MCU_CMU_HXTAL_COMPAREHIGH,
            .compareLow = MCU_CMU_HXTAL_COMPARELOW,
        },

    },
}; // end MCU_Config setup



//**************************************************************************************************
//==================================================================================================
// Declarations of local (private) functions
//==================================================================================================
//**************************************************************************************************

//! \brief Calculate PLL frequency
static U32 MCU_GetPllFreq(void);

//! \brief Calculate SYSClk frequency
static U32 MCU_GetSYSClkFreq(void);

//! \brief Calculate CLKOUT frequency
static U32 MCU_GetClockOutFrequency(void);

//! \brief Memory barrier function
static void MCU_DSB(void);



//**************************************************************************************************
//==================================================================================================
// Definitions of global (public) functions
//==================================================================================================
//**************************************************************************************************



//**************************************************************************************************
//! This function is used to select the external crystal, configure the system frequency,
//!     peripheral frequency, hardware interrupt, output clock and change MCU operating mode
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
void MCU_Init(void)
{
    U32 timeoutLoopCnt = 0UL;

    // Disable interrupts Global
    MCU_DisableInterrupts();
    // Disable CMU before updating the SCU registers.
    SCU.CMU_CTRL.R = 0x0UL;

    // Set SYSCLK procedure
    // First switch to SIRC clock
    SCU.CLKS.B.CLKSRCSEL = MCU_SYSCLK_SEL_SIRC;
    for (timeoutLoopCnt = 0UL;
        (timeoutLoopCnt < MCU_CLOCK_TIMEOUT_LOOP_CNT)
            && (MCU_SYSCLK_SEL_SIRC != SCU.STS.B.CLKST);)
    {
        timeoutLoopCnt++;
    }
    if (MCU_SYSCLK_SEL_SIRC != SCU.STS.B.CLKST)
    {
        // Error STATUS_SCU_CLK_SWITCH_TIMEOUT
        while (TRUE)
        {
            DoNothing();
        }
    }
    // Configure flash Read Wait State
    if (MCU_FLASH_WAIT_STATE_BOUND > MCU_SYSCLK)
    {
       EFM.CTRL.B.RWS = 0U;
    }
    else if ((2U * MCU_FLASH_WAIT_STATE_BOUND) > MCU_SYSCLK)
    {
       EFM.CTRL.B.RWS = 1U;
    }
    else
    {
       EFM.CTRL.B.RWS = 2U;
    }
    // SIRC low power mode enable configuration
    SCU.SIRC_CTRL.B.SIRC_DS_EN = MCU_Set1Bit(MCU_Config.sircDeepSleepEnable);
    SCU.SIRC_CTRL.B.SIRC_STB_EN = MCU_Set1Bit(MCU_Config.sircStandbyEnable);
    SCU.SIRC_CTRL.B.SIRC_PD_EN = MCU_Set1Bit(MCU_Config.sircPowerDownEnable);
    // FIRC configuration
    SCU.FIRC_CTRL.B.FIRC_EN = MCU_Set1Bit(MCU_Config.fircEnable);
    SCU.FIRC_CTRL.B.FIRC_DS_EN = MCU_Set1Bit(MCU_Config.fircDeepSleepEnable);
    // HXTAL configuration
    if (MCU_Config.hxtalConfig.enable)
    {
        SCU.FXOSC_CTRL.B.GMSEL = MCU_Set4Bits(MCU_Config.hxtalConfig.gainSelection);
        SCU.FXOSC_CTRL.B.FXOSC_MODE = MCU_Set1Bit(MCU_Config.hxtalConfig.bypassMode);
        SCU.FXOSC_CTRL.B.COMPEN = MCU_Set1Bit(MCU_Config.hxtalConfig.bypassMode);
        SCU.FXOSC_CTRL.B.FXOSC_EN = MCU_Set1Bit(MCU_Config.hxtalConfig.enable);
        for (timeoutLoopCnt = 0UL;
            (timeoutLoopCnt < MCU_CLOCK_TIMEOUT_LOOP_CNT);)
        {
            if (FALSE != SCU.STS.B.FXOSC_VALID)
            {
            	break;
            }
        	timeoutLoopCnt++;
        }
        if (FALSE == SCU.STS.B.FXOSC_VALID)
        {
            // Error STATUS_SCU_FXOSC_READY_TIMEOUT;
            while (TRUE)
            {
                DoNothing();
            }
        }
    }
    else
    {
        // HXTAL configuration
        SCU.FXOSC_CTRL.B.FXOSC_EN = OFF;
    }
    if (MCU_Config.lxtalConfig.enable)
    {
        SCU.SXOSC_CTRL.B.GMSEL = MCU_Set1Bit(MCU_Config.lxtalConfig.gainSelection);
        SCU.SXOSC_CTRL.B.SXOSC_MODE = MCU_Set1Bit(MCU_Config.lxtalConfig.bypassMode);
        SCU.SXOSC_CTRL.B.SXOSC_DS_EN = MCU_Set1Bit(MCU_Config.lxtalConfig.deepsleepEnable);
        SCU.SXOSC_CTRL.B.SXOSC_STB_EN = MCU_Set1Bit(MCU_Config.lxtalConfig.standbyEnable);
        SCU.SXOSC_CTRL.B.SXOSC_PD_EN = MCU_Set1Bit(MCU_Config.lxtalConfig.powerdownEnable);
        SCU.SXOSC_CTRL.B.SXOSC_EN = MCU_Set1Bit(MCU_Config.lxtalConfig.enable);
        for (timeoutLoopCnt = 0;
            timeoutLoopCnt < MCU_CLOCK_TIMEOUT_LOOP_CNT && ( FALSE == SCU.STS.B.SXOSC_VALID);)
        {
            timeoutLoopCnt++;
        }
        if (FALSE == SCU.STS.B.FXOSC_VALID)
        {
            // Error STATUS_SCU_SXOSC_READY_TIMEOUT;
            while (TRUE)
            {
                DoNothing();
            }
        }
    }
    else
    {
        // SXOSC disable
        SCU.SXOSC_CTRL.B.SXOSC_EN = OFF;
    }
    // PLL configuration
    SCU.PLL_CTRL.B.PLL_EN = OFF;
    if (MCU_Config.pllConfig.enable)
    {
        SCU.PLL_CTRL.B.REFCLKSRCSEL = MCU_Set1Bit(MCU_Config.pllConfig.pllRefClock);
        SCU.PLL_CTRL.B.FBDIV = MCU_Set6Bits(MCU_Config.pllConfig.pllFeedBackDiv - 1U);
        SCU.PLL_CTRL.B.REFDIV = MCU_Set4Bits(MCU_Config.pllConfig.pllRefClkDiv - 1U);
        SCU.PLL_CTRL.B.PLL_EN = MCU_Set1Bit(MCU_Config.pllConfig.enable);
        // Wait PLL lock
        for (timeoutLoopCnt = 0UL;
            (timeoutLoopCnt < MCU_CLOCK_TIMEOUT_LOOP_CNT);)
        {
        	if (FALSE != SCU.STS.B.PLL_LOCK)
        	{
        		break;
        	}
            timeoutLoopCnt++;
        }
        if (FALSE == SCU.STS.B.PLL_LOCK)
        {
            // Error STATUS_PLL_LOCK_READY_TIMEOUT;
            while (TRUE)
            {
                DoNothing();
            }
        }
    }
    // Update System clock divider
    SCU.DIV.B.CPDIVS = MCU_Set4Bits(MCU_Config.sysDiv);
    // Fast bus clock divider
    SCU.DIV.B.FBDIVS = MCU_Set4Bits(MCU_Config.fastBusDiv);
    // Slow bus divider
    SCU.DIV.B.SBDIVS = MCU_Set4Bits(MCU_Config.slowBusDiv);
    for (timeoutLoopCnt = 0UL;
        (timeoutLoopCnt < MCU_CLOCK_TIMEOUT_LOOP_CNT) && (SCU.DIVSTS.R != SCU.DIV.R); )
    {
        timeoutLoopCnt++;
    }
    if (SCU.DIVSTS.R != SCU.DIV.R)
    {
        // Error STATUS_CLOCK_DIVIDER_NOT_STABLE_TIMEOUT;
        while (TRUE)
        {
            DoNothing();
        }
    }
    // Switch to target clock
    SCU.CLKS.B.CLKSRCSEL = MCU_Set2Bits(MCU_Config.sysClkSrc);
    // Wait stable SysClk
    for (timeoutLoopCnt = 0UL;
        (timeoutLoopCnt < MCU_CLOCK_TIMEOUT_LOOP_CNT) &&
        (MCU_Config.sysClkSrc != SCU.STS.B.CLKST); )
    {
        timeoutLoopCnt++;
    }
    if ((timeoutLoopCnt >= MCU_CLOCK_TIMEOUT_LOOP_CNT)
        && (MCU_Config.sysClkSrc != SCU.STS.B.CLKST))
    {
        // Error STATUS_SCU_CLK_SWITCH_TIMEOUT
        while (TRUE)
        {
            DoNothing();
        }
    }
    // Setup clock output pin
    if (MCU_Config.clockOutConfig.enable)
    {
        GPIO_tag* pGPIOreg = MCU_CLKOUT_GPIO;
        PCTRL_tag* pPCTRLreg = MCU_CLKOUT_PCTRL;
        // Set CLKOUT divider. Accepts only even divider more than two.
        SCU.CLKO.B.CLKODIV = (MCU_Config.clockOutConfig.divider / 2U) << 1U ;
        // Select Clock Out source
        SCU.CLKO.B.CLKOSEL = MCU_Set3Bits(MCU_Config.clockOutConfig.source);

        // ClockOut pin
        U8 nPin = MCU_Config.clockOutConfig.pin;
        // Turn ON GPIO port clock
        IPC.CTRL[MCU_IPC_GPIO_INDEX].B.CLKEN = ON;
        // Enable clocking for CLKOUT pin port
        switch (MCU_Config.clockOutConfig.port)
        {
            case MCU_PORT_A:
                // PORT_A
                IPC.CTRL[MCU_IPC_PCTRLA_INDEX].B.CLKEN = ON;
                break;

            case MCU_PORT_B:
                // PORT_B
                IPC.CTRL[MCU_IPC_PCTRLB_INDEX].B.CLKEN = ON;
                break;

            case MCU_PORT_C:
                // PORT_C
                IPC.CTRL[MCU_IPC_PCTRLC_INDEX].B.CLKEN = ON;
                break;

            case MCU_PORT_D:
                // PORT_D
                IPC.CTRL[MCU_IPC_PCTRLD_INDEX].B.CLKEN = ON;
                break;

            case MCU_PORT_E:
                // PORT_E
                IPC.CTRL[MCU_IPC_PCTRLE_INDEX].B.CLKEN = ON;
                break;

            default:
                // Wrong port error
                break;
        } // end of switch (MCU_CLKOUT_PORT)

        // Setup pin for clock output
        // ClockOut pin strength HIGH
        pPCTRLreg->PCR[ nPin ].B.DSE = MCU_STRENGTH_HIGH;
        // ClockOut pin Slew rate to Fast mode
        pPCTRLreg->PCR[nPin ].B.SRE = MCU_FAST_SLEW_RATE;
        // Pull up mode ON, pull down OFF
        pPCTRLreg->PCR[nPin ].B.PS = ON;
        // ClockOut pin Pull Enable
        pPCTRLreg->PCR[nPin ].B.PE = MCU_PULL_ENABLE;
        // ClockOut pin multiplexer
        pPCTRLreg->PCR[ nPin ].B.MUX = MCU_Set3Bits(MCU_Config.clockOutConfig.mux);
        // ClockOut pin Output
        pGPIOreg->POER.R |= (U32)1UL<< nPin;
    }
    else
    {
        // Clock out disabled
        SCU.CLKO.B.CLKOSEL = MCU_CLKOUT_SEL_DISABLE;
    }
    // Configure the SCU CMU blocks
    if (ON == MCU_CMU_ENABLE)
    {
        // Configure SLOW Bus CMU block
        if (TRUE == MCU_Config.clockCheckConfig.slowBusMonitor.enable)
        {
            SCU.CMU_CTRL.B.CMU0_RE =
                MCU_Set1Bit(MCU_Config.clockCheckConfig.slowBusMonitor.resetEnable);
            SCU.CMU_CTRL.B.CMU0_REF =
                MCU_Set1Bit(MCU_Config.clockCheckConfig.slowBusMonitor.refClock);
            SCU.CMUCMP[0].HIGH.B.VAL =
                    MCU_Config.clockCheckConfig.slowBusMonitor.compareHigh;
            SCU.CMUCMP[0].LOW.B.VAL =
                    MCU_Config.clockCheckConfig.slowBusMonitor.compareLow;
            SCU.CMU_CTRL.B.CMU0_EN =
                MCU_Set1Bit(MCU_Config.clockCheckConfig.slowBusMonitor.enable);
        }
        // Configure FIRC CMU block
        if (TRUE == MCU_Config.clockCheckConfig.fircClockMonitor.enable)
        {
            SCU.CMU_CTRL.B.CMU1_RE =
                MCU_Set1Bit(MCU_Config.clockCheckConfig.fircClockMonitor.resetEnable);
            SCU.CMU_CTRL.B.CMU1_REF =
                MCU_Set1Bit(MCU_Config.clockCheckConfig.fircClockMonitor.refClock);
            SCU.CMUCMP[1].HIGH.B.VAL =
                    MCU_Config.clockCheckConfig.fircClockMonitor.compareHigh;
            SCU.CMUCMP[1].LOW.B.VAL =
                    MCU_Config.clockCheckConfig.fircClockMonitor.compareLow;
            SCU.CMU_CTRL.B.CMU1_EN =
                MCU_Set1Bit(MCU_Config.clockCheckConfig.fircClockMonitor.enable);
        }
        // Configure PLL CMU block
        if ((TRUE == MCU_Config.clockCheckConfig.pllClockMonitor.enable) &&
            (TRUE == MCU_Config.pllConfig.enable))
        {
            SCU.CMU_CTRL.B.CMU2_RE =
                MCU_Set1Bit(MCU_Config.clockCheckConfig.pllClockMonitor.resetEnable);
            SCU.CMU_CTRL.B.CMU2_REF =
                MCU_Set1Bit(MCU_Config.clockCheckConfig.pllClockMonitor.refClock);
            SCU.CMUCMP[2].HIGH.B.VAL =
                    MCU_Config.clockCheckConfig.pllClockMonitor.compareHigh;
            SCU.CMUCMP[2].LOW.B.VAL =
                    MCU_Config.clockCheckConfig.pllClockMonitor.compareLow;
            SCU.CMU_CTRL.B.CMU2_EN =
                MCU_Set1Bit(MCU_Config.clockCheckConfig.pllClockMonitor.enable);
        }
        // Configure HXTAL CMU block
        if ((TRUE == MCU_Config.clockCheckConfig.hxtalClockMonitor.enable) &&
            (TRUE == MCU_Config.hxtalConfig.enable))
        {
            SCU.CMU_CTRL.B.CMU3_RE =
                MCU_Set1Bit(MCU_Config.clockCheckConfig.hxtalClockMonitor.resetEnable);
            SCU.CMUCMP[3].HIGH.B.VAL =
                    MCU_Config.clockCheckConfig.hxtalClockMonitor.compareHigh;
            SCU.CMUCMP[3].LOW.B.VAL =
                    MCU_Config.clockCheckConfig.hxtalClockMonitor.compareLow;
            SCU.CMU_CTRL.B.CMU3_EN =
                MCU_Set1Bit(MCU_Config.clockCheckConfig.hxtalClockMonitor.enable);
        }
    }

    // Enable Interrupts Global
    MCU_EnableInterrupts();
} // end of MCU_Init()



//**************************************************************************************************
//! Enable interrupts Global
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
void MCU_EnableInterrupts(void)
{
    INTERRUPT_ENABLE();
} // end of MCU_EnableInterrupts()



//**************************************************************************************************
//! Disable interrupts Global
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
void MCU_DisableInterrupts(void)
{
    INTERRUPT_DISABLE();
} // end of MCU_DisableInterrupts()



//**************************************************************************************************
//! This is intended to force a large system reset of all major components except for debug
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
void MCU_Reset(void)
{
    // Reset MCU
	MCU_DSB();
	SCB.AIRCR.R  = (U32)((MCU_AIRCR_VECTKEY << MCU_SCB_AIRCR_VECTKEY_POS) |
	                           (SCB.AIRCR.R & MCU_SCB_AIRCR_PRIGROUP_MSK) |
	                            MCU_SCB_AIRCR_SYSRESETREQ_MSK);
	MCU_DSB();
} // end of MCU_Reset()



//**************************************************************************************************
//! Return bus clock source frequency
//!
//! \note   For the YTM32B1ME05 bus order means sources as below
//!         MCU_CLOCK_SOURCE_EXTERNAL       - HXTAL
//!         MCU_CLOCK_SOURCE_INTERNAL       - FIRC
//!         MCU_CLOCK_SOURCE_LOW_POWER      - Low power clock source
//!         MCU_CLOCK_SOURCE_BUS0           - PLL
//!         MCU_CLOCK_SOURCE_BUS1           - SYSCLK
//!         MCU_CLOCK_SOURCE_BUS2           - FAST BUS
//!         MCU_CLOCK_SOURCE_BUS3           - SLOW BUS
//!         MCU_CLOCK_SOURCE_BUS4           - HXTAL
//!         MCU_CLOCK_SOURCE_BUS5           - FIRC
//!         MCU_CLOCK_SOURCE_BUS6           - SIRC
//!         MCU_CLOCK_SOURCE_BUS7           - SXOSC
//!         MCU_CLOCK_SOURCE_BUS8           - CLKOUT
//!
//! \param[in] nBusNumber - conventional number of bus.
//!
//! \return The bus frequency in Hz
//**************************************************************************************************
U32 MCU_GetBusFrequency(const U8 nBusNumber)
{
    U32 nBusFrequency = 0UL;
    switch (nBusNumber)
    {
        case MCU_CLOCK_SOURCE_EXTERNAL:
            if (MCU_HXTAL_BYPASS == MCU_XTAL_BYPASS)
            {
                nBusFrequency = MCU_HXTAL;
            }
            else
            {
                nBusFrequency = 0UL;
            }
            break;

        case MCU_CLOCK_SOURCE_INTERNAL:
            // Sysclk source frequency
            switch (MCU_Config.sysClkSrc) {
                case MCU_SYSCLK_SEL_FIRC:
                    nBusFrequency = MCU_FIRC;
                    break;

                case MCU_SYSCLK_SEL_PLL:
                    nBusFrequency = MCU_GetPllFreq();
                    break;

                case MCU_SYSCLK_SEL_HXTAL:
                    nBusFrequency = MCU_HXTAL;
                    break;

                case MCU_SYSCLK_SEL_SIRC:
                    nBusFrequency = MCU_SIRC;
                    break;

                default:
                    // Any wrong request
                    DoNothing();
                    break;
            } // end of case MCU_CLOCK_SOURCE_INTERNAL
            break;
        case MCU_CLOCK_SOURCE_LOW_POWER:
            break;

        case MCU_CLOCK_SOURCE_BUS0:
            // PLL
            nBusFrequency = MCU_GetPllFreq();
            break;

        case MCU_CLOCK_SOURCE_BUS1:
            // SYSCLK
            nBusFrequency = MCU_GetSYSClkFreq();
            break;

        case MCU_CLOCK_SOURCE_BUS2:
            // FAST BUS
            nBusFrequency =  MCU_GetSYSClkFreq() / (SCU.DIVSTS.B.FBDIVST + 1UL);
            break;

        case MCU_CLOCK_SOURCE_BUS3:
            // SLOW BUS clock
            nBusFrequency =  MCU_GetSYSClkFreq() / (SCU.DIVSTS.B.FBDIVST + 1UL)
                             / (SCU.DIVSTS.B.SBDIVST + 1UL);
            break;

        case MCU_CLOCK_SOURCE_BUS4:
            // HXTAL
            nBusFrequency = MCU_HXTAL;
            break;

        case MCU_CLOCK_SOURCE_BUS5:
            // FIRC
            nBusFrequency = MCU_FIRC;
            break;

        case MCU_CLOCK_SOURCE_BUS6:
            // SIRC
            nBusFrequency = MCU_SIRC;
            break;

        case MCU_CLOCK_SOURCE_BUS7:
            // SXOSC
            nBusFrequency = MCU_LXTAL;
            break;

        case MCU_CLOCK_SOURCE_BUS8:
            // CLKOUT
            nBusFrequency = MCU_GetClockOutFrequency();
            break;

        default:
            // Any wrong request
            DoNothing();
            break;
       } // end of switch(nBusNumber)

    return nBusFrequency;
} // end of MCU_GetBusFrequency()



//**************************************************************************************************
//! Returns the last reset cause number
//!
//! \note None
//!
//! \param None
//!
//! \return Last reset cause number
//**************************************************************************************************
U8 MCU_GetResetCause(void)
{
    U8 nRstCause = MCU_RESET_CAUSE_UNKNOWN;
    if (ON == RCU.RSSR.B.CMU)
    {
        // Clock Monitor Reset
        nRstCause = MCU_RESET_CAUSE_CLOCK_MONITOR;
    }
    else if (ON == RCU.RSSR.B.LVD)
    {
        // Low Voltage Detect Reset
        nRstCause = MCU_RESET_CAUSE_LOW_VOLTAGE;
    }
    else if (ON == RCU.RSSR.B.PIN)
    {
        // Pin Reset
        nRstCause = MCU_RESET_CAUSE_RESET_PIN;
    }
    else if (ON == RCU.RSSR.B.SW)
    {
        // Software reset flag
        nRstCause = MCU_RESET_CAUSE_SOFTWARE;
    }
    else if (ON == RCU.RSSR.B.DBG)
    {
        // Debug reset flag
        nRstCause = MCU_RESET_CAUSE_DEBUG;
    }
    else if (ON == RCU.RSSR.B.LOCKUP)
    {
        // ARM Lockup reset flag
        nRstCause = MCU_RESET_CAUSE_CPU_ERROR;
    }
    else if (ON == RCU.RSSR.B.WTDG)
    {
        // WATCHDOG reset generated
        nRstCause = MCU_RESET_CAUSE_WATCHDOG;
    }
    else if (ON == RCU.RSSR.B.DEEPSLEEPACK)
    {
        // Timeout Deep sleep/Standby/Power Down mode entry reset
        nRstCause = MCU_RESET_CAUSE_DEEPSLEEPACK;
    }
    else if (ON == RCU.RSSR.B.HVD)
    {
        // High Voltage Detect Reset
        nRstCause = MCU_RESET_CAUSE_HIGH_VOLTAGE;
    }
    return nRstCause;
} // end of MCU_GetResetCause()



//**************************************************************************************************
//! Jumps code execution (program counter, instruction pointer) to the specified address
//!
//! \note None
//!
//! \param[in] nAddress - address of the code to execute.
//!
//! \return None
//**************************************************************************************************
void MCU_JumpToAddress(const U32 nAddress)
{
    // Set pointer to address
    MCU_JUMP_ADDRESS pAddressToFunc = (MCU_JUMP_ADDRESS)nAddress;

    // Goto address
    pAddressToFunc();
} // end of MCU_JumpToAddress()



//**************************************************************************************************
//! Jumps code execution (program counter, instruction pointer) to the specified vector
//!
//! \note None
//!
//! \param[in] nAddress - address of the vector to execute.
//!
//! \return None
//**************************************************************************************************
void MCU_JumpToVector(const U32 nAddress)
{
    // Goto vector
    MCU_JumpToAddress(nAddress);
} // end of MCU_JumpToVector()



//**************************************************************************************************
//==================================================================================================
// Definitions of local (private) functions
//==================================================================================================
//**************************************************************************************************



//**************************************************************************************************
//! Data Synchronization Barrier.It completes when all explicit memory accesses before this
//! instruction complete. Acts as a special kind of Data Memory Barrier
//!
//! \note It's a part of NVIC
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
static void MCU_DSB(void)
{
  asm volatile ("dsb 0xF":::"memory");
}



//**************************************************************************************************
//! Calculate PLL frequency
//!
//! \note None
//!
//! \param None
//!
//! \return PLL frequency
//**************************************************************************************************
static U32 MCU_GetPllFreq(void)
{
    U32 nBusFrequency = 0UL;
    // Check if PLL is locked
    if (ON == SCU.STS.B.PLL_LOCK)
    {
        // Get PLL reference
        if (MCU_PLL_REF_FIRC_CLK == SCU.PLL_CTRL.B.REFCLKSRCSEL)
        {
            // FIRC as reference clock
            nBusFrequency = MCU_FIRC;
        }
        else
        {
            // HXTAL as reference clock
            nBusFrequency = MCU_HXTAL;
        }
        // Calculate PLL frequency
        nBusFrequency *= (SCU.PLL_CTRL.B.FBDIV + 1UL) / (2UL * (SCU.PLL_CTRL.B.REFDIV + 1UL));
    }
    return nBusFrequency;
} // end of MCU_GetPllFreq()



//**************************************************************************************************
//! Calculate SYSCLK frequency
//!
//! \note None
//!
//! \param None
//!
//! \return SYSCLK frequency
//**************************************************************************************************
static U32 MCU_GetSYSClkFreq(void)
{
    U32 nBusFrequency = 0UL;
    switch (SCU.STS.B.CLKST)
    {
        case MCU_SYSCLK_SEL_FIRC:
            nBusFrequency = MCU_FIRC;
            break;

        case MCU_SYSCLK_SEL_PLL:
            nBusFrequency = MCU_GetPllFreq();
            break;

        case MCU_SYSCLK_SEL_HXTAL:
            nBusFrequency = MCU_HXTAL;
            break;

        case MCU_SYSCLK_SEL_SIRC:
            nBusFrequency = MCU_SIRC;
            break;

        default:
            nBusFrequency = 0UL;
            break;
    }
    // Calculate core clock frequency
    nBusFrequency /= (SCU.DIVSTS.B.CPDIVST + 1UL);
    return nBusFrequency;
} // end of MCU_GetSYSClkFreq()



//**************************************************************************************************
//! Calculate CLKOUT frequency
//!
//! \note CLKOUT divider always odd. It mean that 5 works as 4, 7 as 6, 9 as 8 ...
//!
//! \param None
//!
//! \return CLKOUT frequency
//**************************************************************************************************
static U32 MCU_GetClockOutFrequency(void)
{
    U32 nBusFrequency = 0UL;
    switch (SCU.CLKO.B.CLKOSEL)
    {
        case MCU_CLKOUT_SEL_FIRC_CLK:
            nBusFrequency = MCU_FIRC;
            break;

        case MCU_CLKOUT_SEL_SIRC_CLK:
            nBusFrequency = MCU_SIRC;
            break;

        case MCU_CLKOUT_SEL_FXOSC_CLK:
            nBusFrequency = MCU_HXTAL;
            break;

        case MCU_CLKOUT_SEL_LXTAL_CLK:
            nBusFrequency = MCU_LXTAL;
            break;

        case MCU_CLKOUT_SEL_PLL_CLK:
            nBusFrequency = MCU_GetPllFreq();
            break;

        case MCU_CLKOUT_SEL_SYSCLK:
            nBusFrequency = MCU_GetSYSClkFreq();
            break;

        default:
            nBusFrequency = 0UL;
            break;
    }

    return nBusFrequency /= (SCU.CLKO.B.CLKODIV / 2U ) << 1U;
}  // end of MCU_GetClockOutFrequency()



//****************************************** end of file *******************************************
