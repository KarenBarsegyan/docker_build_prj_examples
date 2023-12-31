//**************************************************************************************************
// @Module      STARTUP
//! \file       cstart.c
//! \par        Platform
//!                 YTM32B1M
//! \par        Compatible
//!                 YTM32B1ME0 families
//! \brief      Implementation of the start program after reset.
//!
//! \par        History
//! Date       | Version | Author  | Comment
//! :---------:|:-------:|:-------:|---------------
//! 26.04.2023 | 1.0.0   | FAV     | First release.
//**************************************************************************************************



//**************************************************************************************************
//! \defgroup   STARTUP_DRV STARTUP
//! \brief      Implements system work after reset.
//! \addtogroup STARTUP_DRV
//! @{
//! \file cstart.h
//! \file cstart.c
//! \file cstart.h.tmpl
//! @}
//**************************************************************************************************



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Native header
#include "cstart.h"



//**************************************************************************************************
// Verification of the imported configuration parameters
//**************************************************************************************************

// None.



//**************************************************************************************************
// Definitions of global (public) variables
//**************************************************************************************************

// Pointer to Cstart function.
__attribute__((section(".pCstart"), used))
void (*STARTUP_pCstart)(void) = STARTUP_Cstart;



//**************************************************************************************************
// Declarations of local (private) data types
//**************************************************************************************************

// None.



//**************************************************************************************************
// Definitions of local (private) constants
//**************************************************************************************************

// None.



//**************************************************************************************************
// Definitions of static global (private) variables
//**************************************************************************************************

// None.



//**************************************************************************************************
// Declarations of local (private) functions
//**************************************************************************************************

// None.



//**************************************************************************************************
//==================================================================================================
// Definitions of global (public) functions
//==================================================================================================
//**************************************************************************************************



//**************************************************************************************************
//! This is the first code which is executed after reset it initializes stack, RAM
//! and calls main()
//!
//! \note None.
//!
//! \param None.
//!
//! \return None.
//**************************************************************************************************
void __attribute ((section(".cstart"), naked, used)) STARTUP_Cstart(void)
{
    __asm__ (
    ".syntax unified\n\t"
    ".thumb\n\t"
    // Initializes main stack pointer
    "ldr sp, =_estack\n\t"

    // Zero fill the registers
    "ldr r1, = 0\n\t"
    "ldr r2, = 0\n\t"
    "ldr r3, = 0\n\t"
    "ldr r4, = 0\n\t"
    "ldr r5, = 0\n\t"
    "ldr r6, = 0\n\t"
    "ldr r7, = 0\n\t"
    "mov r8, r7\n\t"
    "mov r9, r7\n\t"
    "mov r10, r7\n\t"
    "mov r11, r7\n\t"
    "mov r12, r7\n\t"

    // Zero fill the RAM
    "ldr r2, =_sRAM\n\t"
    "ldr r4, =_eRAM\n\t"
    "movs r3, #0\n\t"
    "b LoopFillZeroRAM\n\t"

    "FillZeroRAM:\n\t"
    "str  r3, [r2]\n\t"
    "adds r2, r2, #4\n\t"

    "LoopFillZeroRAM:\n\t"
    "cmp r2, r4\n\t"
    "bcc FillZeroRAM\n\t"

    // Copy the data segment initializers from flash to SRAM
    "ldr r0, =_sdata\n\t"
    "ldr r1, =_edata\n\t"
    "ldr r2, =_sidata\n\t"
    "movs r3, #0\n\t"
    "b LoopCopyDataInit\n\t"

    "CopyDataInit:\n\t"
    "ldr r4, [r2, r3]\n\t"
    "str r4, [r0, r3]\n\t"
    "adds r3, r3, #4\n\t"

    "LoopCopyDataInit:\n\t"
    "adds r4, r0, r3\n\t"
    "cmp r4, r1\n\t"
    "bcc CopyDataInit\n\t"

    // Branch to main
    "bl  main\n\t"
    "bx  lr    \n\t"
    );
} // end of STARTUP_Cstart()



//**************************************************************************************************
//==================================================================================================
// Definitions of local (private) functions
//==================================================================================================
//**************************************************************************************************

// None.



//****************************************** end of file *******************************************
