//**************************************************************************************************
// @Module  SPI driver
//! \file   spi_drv_irq.h
//! \par    Platform
//!             YTM32
//! \par    Compatible
//!             YTM32B1M families
//! \brief  Interface of the SPI IRQ module.
//!
//! \par    Abbreviations
//!             MCU - MicroController Unit
//!             SPI - Serial Peripheral Interface
//! \par    History
//! | Date       | Version | Author  | Comment
//! |:----------:|:-------:|:-------:|--------------------------------------------------------------
//! | 11.08.2023 |  1.0.0  |   BKR   | First release.
//**************************************************************************************************

#ifndef SPI_DRV_IRQ_H
#define SPI_DRV_IRQ_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Get SPI_HighLevel_ISR()
#include "spi_drv.h"



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

// None.



//**************************************************************************************************
// Declarations of interrupt service routines
//**************************************************************************************************

extern INTERRUPT void SPI_LowLevel_0_Interrupt(void);

extern INTERRUPT void SPI_LowLevel_1_Interrupt(void);

extern INTERRUPT void SPI_LowLevel_2_Interrupt(void);

extern INTERRUPT void SPI_LowLevel_3_Interrupt(void);

extern INTERRUPT void SPI_LowLevel_4_Interrupt(void);

extern INTERRUPT void SPI_LowLevel_5_Interrupt(void);



#endif  // SPI_DRV_IRQ_H

//****************************************** end of file *******************************************
