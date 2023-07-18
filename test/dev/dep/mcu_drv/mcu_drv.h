//**************************************************************************************************
// @Module      MCU driver
//! \file       mcu_drv.h
//! \brief      Interface of the MCU driver.
//!
//! \par        History
//! | Date       | Version | Author  | Comment
//! |:----------:|:-------:|:-------:|---------------
//! | 30.05.2023 | 2.5.0   | CAV     | Added MCU_RESET_CAUSE_DEBUG, MCU_RESET_CAUSE_DEEPSLEEPACK
//! | 07.04.2023 | 2.4.0   | FAV     | 1) BUS9...BUS15 has been added to MCU clock sources.
//! |            |         |         | 2) The new Doxygen standard.
//! | 18.08.2021 | 2.3.2   | SHA     | BUS8 has been added to MCU clock sources.
//! | 26.09.2017 | 2.3.1   | SHA     | BUS5...BUS7 has been added to MCU clock sources.
//! | 09.02.2017 | 2.3.0   | SRM     | 1) MCU_Jump() renamed into MCU_JumpToAddress().
//! |            |         |         | 2) MCU_JumpToVector() function has been added.
//! | 08.11.2016 | 2.2.0   | SRM     | MCU_Jump() function has been added.
//! | 20.03.2015 | 2.1.0   | SHA     | Added MCU_RESET_CAUSE_MEMORY_PARITY
//! | 04.02.2015 | 2.0.0   | SRM     | Second release.
//**************************************************************************************************

#ifndef MCU_DRV_H
#define MCU_DRV_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Get data types
#include "compiler.h"

// Get generic definitions
#include "general.h"

// Get configuration of the program module
#include "mcu_drv_cfg.h"



//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************

// None.



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

//! \name MCU's reset causes
//! @{
#define MCU_RESET_CAUSE_FIRST                               (0U)
#define MCU_RESET_CAUSE_POWER_ON                            (0U)
#define MCU_RESET_CAUSE_RESET_PIN                           (1U)
#define MCU_RESET_CAUSE_LOW_VOLTAGE                         (2U)
#define MCU_RESET_CAUSE_HIGH_VOLTAGE                        (3U)
#define MCU_RESET_CAUSE_ILLEGAL_ADDR                        (4U)
#define MCU_RESET_CAUSE_ILLEGAL_INSTR                       (5U)
#define MCU_RESET_CAUSE_WATCHDOG                            (6U)
#define MCU_RESET_CAUSE_UNIMPL_INTERR                       (7U)
#define MCU_RESET_CAUSE_SOFTWARE                            (8U)
#define MCU_RESET_CAUSE_CLOCK_MONITOR                       (9U)
#define MCU_RESET_CAUSE_UNKNOWN                             (10U)
#define MCU_RESET_CAUSE_UNKNOWN_INTERR                      (11U)
#define MCU_RESET_CAUSE_CPU_ERROR                           (12U)
#define MCU_RESET_CAUSE_MEMORY_PARITY                       (13U)
#define MCU_RESET_CAUSE_STANDBY_WAKEUP                      (14U)
#define MCU_RESET_CAUSE_DEBUG                               (15U)
#define MCU_RESET_CAUSE_DEEPSLEEPACK                        (16U)
#define MCU_RESET_CAUSE_LAST                                (16U)
//! @}

//! \name MCU clock sources
//! @{
#define MCU_CLOCK_SOURCE_EXTERNAL                           (0U)
#define MCU_CLOCK_SOURCE_INTERNAL                           (1U)
#define MCU_CLOCK_SOURCE_LOW_POWER                          (2U)
#define MCU_CLOCK_SOURCE_BUS0                               (3U)
#define MCU_CLOCK_SOURCE_BUS1                               (4U)
#define MCU_CLOCK_SOURCE_BUS2                               (5U)
#define MCU_CLOCK_SOURCE_BUS3                               (6U)
#define MCU_CLOCK_SOURCE_BUS4                               (7U)
#define MCU_CLOCK_SOURCE_BUS5                               (8U)
#define MCU_CLOCK_SOURCE_BUS6                               (9U)
#define MCU_CLOCK_SOURCE_BUS7                               (10U)
#define MCU_CLOCK_SOURCE_BUS8                               (11U)
#define MCU_CLOCK_SOURCE_BUS9                               (12U)
#define MCU_CLOCK_SOURCE_BUS10                              (13U)
#define MCU_CLOCK_SOURCE_BUS11                              (14U)
#define MCU_CLOCK_SOURCE_BUS12                              (15U)
#define MCU_CLOCK_SOURCE_BUS13                              (16U)
#define MCU_CLOCK_SOURCE_BUS14                              (17U)
#define MCU_CLOCK_SOURCE_BUS15                              (18U)
//! @}



//**************************************************************************************************
// Declarations of global (public) variables
//**************************************************************************************************

// None.



//**************************************************************************************************
// Declarations of global (public) functions
//**************************************************************************************************

//! \brief Initializes all of the system clocks
extern void MCU_Init(void);

//! \brief Enables MCU interrupts
extern void MCU_EnableInterrupts(void);

//! \brief Disables MCU interrupts
extern void MCU_DisableInterrupts(void);

//! \brief Puts MCU into sleep mode
extern void MCU_Sleep(void);

//! \brief Initiates MCU hardware reset
extern void MCU_Reset(void);

//! \brief Returns the specified bus frequency in Hz
extern U32 MCU_GetBusFrequency(const U8 nBusNumber);

//! \brief Returns the last reset cause number
extern U8 MCU_GetResetCause(void);

//! \brief Jumps code execution (program counter, instruction pointer)
//!        to the specified address
extern void MCU_JumpToAddress(const U32 nAddress);

//! \brief Jumps code execution (program counter, instruction pointer)
//!        to the specified vector
extern void MCU_JumpToVector(const U32 nAddress);



#endif // #ifndef MCU_DRV_H

//****************************************** end of file *******************************************
