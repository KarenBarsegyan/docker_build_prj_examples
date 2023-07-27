//**************************************************************************************************
// @Module  GPIO driver
//! \file   gpio_drv_wku.c
//! \brief  Implementation of the GPIO driver WKU functionality.
//!
//! \par    History
//! | Date       | Version | Author | Comment
//! |:----------:|:-------:|:------:|---------------------------------------------------------------
//! | 14.07.2023 |  1.0.0  |   CAV  | First release.
//**************************************************************************************************

#ifndef GPIO_DRV_WKU_H
#define GPIO_DRV_WKU_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Define data types
#include "compiler.h"



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

// None.



//**************************************************************************************************
// Declarations of global (public) functions
//**************************************************************************************************

//! WakeUp interrupt service routine
extern INTERRUPT void GPIO_WKU_Handler(void);



#endif // #ifndef GPIO_DRV_WKU_H

//****************************************** end of file *******************************************
