//**************************************************************************************************
// @Module      IRQ driver
//! \file       irq_drv.h
//! \brief      Interface of the IRQ driver.
//!
//! \par        History
//! | Date       | Version | Author  | Comment
//! |:----------:|:-------:|:-------:|--------------------------------------------------------------
//! | 05.05.2023 |  1.1.0  |   FAV   | The new Doxygen standard.
//! | 23.03.2023 |  1.0.1  |   FAV   | Add constant stack pointer.
//! | 25.05.2022 |  1.0.0  |   KPS   | First release.
//**************************************************************************************************

#ifndef IRQ_DRV_H
#define IRQ_DRV_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Get data types
#include "compiler.h"

// Get generic definitions
#include "general.h"

// Get irq configuration
#include "irq_drv_cfg.h"



//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************

// None.



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

// None.



//**************************************************************************************************
// Declarations of global (public) variables
//**************************************************************************************************

//! Constant stack pointer
extern const U32 _estack;



//**************************************************************************************************
// Declarations of global (public) functions
//**************************************************************************************************

//! \brief Set offset vector table
extern void IRQ_Init(void);



#endif // #ifndef IRQ_DRV_H

//******************************************end of file*******************************************
