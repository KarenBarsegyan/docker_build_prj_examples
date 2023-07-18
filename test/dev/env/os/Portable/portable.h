//**************************************************************************************************
// @Module        SCHDL
//! \file       portable.h
//! \par    Platform
//!             Cortex-M4
//! \par    Compatible
//!             STM32F4, APM32F4, AT32F4, HC32F4A families
//! \brief      Interface of the scheduler portable module.
//! \par        History       
//! Date       | Version | Author  | Comment
//! :---------:|:-------:|:-------:|---------------
//! 23.01.2017 |  1.0.0  |   SHA   | First release.
//! 26.11.2018 |  1.1.0  |   SRM   | ISR optimization avoidance has been added.
//! 22.08.2022 |  1.2.0  |   SMM   | Ported to Cortex-M4 core.
//! 06.04.2023 |  1.2.1  |   PAV   | Moved the IRQ number setting for Scheduler handler.
//! 14.04.2023 |  1.2.2  |   PAV   | Refactoring according to Doxygen rules.
//**************************************************************************************************

#ifndef PORTABLE_H
#define PORTABLE_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Get data types
#include "derivative_cfg.h"
#include "general.h"
#include "scheduler.h"



//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************

// None.



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

//! Number software interrupt channel
#define SCHDL_SW_NUM_CH             (2U)

//! Length of bitmap word
#define SCHDL_BITMAP_WORD_LNGTH     (16U)

//! Length of the bitmap
#define _SCHDL_BIT_TAB_LEN          (SCHDL_TASK_COUNT / SCHDL_BITMAP_WORD_LNGTH)
#if((_SCHDL_BIT_TAB_LEN * SCHDL_BITMAP_WORD_LNGTH) < SCHDL_TASK_COUNT)
    #define SCHDL_BIT_TAB_LEN       ((SCHDL_TASK_COUNT / SCHDL_BITMAP_WORD_LNGTH) + 1U)
#else
    #define SCHDL_BIT_TAB_LEN       (SCHDL_TASK_COUNT / SCHDL_BITMAP_WORD_LNGTH)
#endif // #if((_SCHDL_BIT_TAB_LEN * SCHDL_BITMAP_WORD_LNGTH) < SCHDL_TASK_COUNT)

//! IRQ register address macros
#define SCHDL_IRQ_REG               (SCHDL_IRQ_NUMBER / 32U)
#define	SCHDL_IRQ_BITMASK           (1U << (SCHDL_IRQ_NUMBER % 32U))



//**************************************************************************************************
// Declarations of global (public) variables
//**************************************************************************************************

// None.



//**************************************************************************************************
// Declarations of global (public) functions
//**************************************************************************************************

//! Avoids ISR optimization during library building process
extern void SCHDL_AvoidISRLibraryOptimization(void);

//! Interrupt handler for scheduler call
// !!! Must be specified in irq_drv_cfg.h !!!
extern void SCHDL_SchedulerProc(void);

//! Interrupt handler for SVCall
// !!! Must be specified in irq_drv_cfg.h !!!
extern void SCHDL_SchedulerClose(void);

//! Scheduler initialization
INLINE_FUN void SCHDL_InitHW(void)
{
    // Clear interrupt flag
    NVIC.ICPR[SCHDL_IRQ_REG].R = SCHDL_IRQ_BITMASK;
    // Enable Interrupt
    NVIC.ISER[SCHDL_IRQ_REG].R = SCHDL_IRQ_BITMASK;

} // end of SCHDL_DeInitHW()

//! \brief Scheduler deinitialization
INLINE_FUN void SCHDL_DeInitHW(void)
{
    // Clear interrupt flag
    NVIC.ICPR[SCHDL_IRQ_REG].R = SCHDL_IRQ_BITMASK;
    // Disable Interrupt
    NVIC.ICER[SCHDL_IRQ_REG].R = SCHDL_IRQ_BITMASK;
} // end of SCHDL_DeInitHW()

//! \brief Scheduler set interrupt request bit
INLINE_FUN void SCHDL_SchedulStart(void)
{
    // Set interrupt flag
    NVIC.ISPR[SCHDL_IRQ_REG].R = SCHDL_IRQ_BITMASK;
} // end of SCHDL_SchedulStart()

//! \brief Scheduler interrupt enable
INLINE_FUN void SCHDL_SchedulEnable(void)
{
    // Enable Interrupt
    NVIC.ISER[SCHDL_IRQ_REG].R = SCHDL_IRQ_BITMASK;
} // end of SCHDL_SchedulEnable()

//! \brief Scheduler interrupt disable
INLINE_FUN void SCHDL_SchedulDisable(void)
{
    // Disable Interrupt
    NVIC.ICER[SCHDL_IRQ_REG].R = SCHDL_IRQ_BITMASK;
} // end of SCHDL_SchedulDisable()



#endif // #ifndef SCHDL_H

//****************************************** end of file *******************************************
