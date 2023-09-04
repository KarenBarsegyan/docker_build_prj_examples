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

//! \brief SPI0 interrupt handler
extern INTERRUPT void SPI_LowLevel_0_Interrupt(void);

//! \brief SPI1 interrupt handler
extern INTERRUPT void SPI_LowLevel_1_Interrupt(void);

//! \brief SPI2 interrupt handler
extern INTERRUPT void SPI_LowLevel_2_Interrupt(void);

//! \brief SPI3 interrupt handler
extern INTERRUPT void SPI_LowLevel_3_Interrupt(void);

//! \brief SPI4 interrupt handler
extern INTERRUPT void SPI_LowLevel_4_Interrupt(void);

//! \brief SPI5 interrupt handler
extern INTERRUPT void SPI_LowLevel_5_Interrupt(void);



#endif  // #ifndef SPI_DRV_IRQ_H

//****************************************** end of file *******************************************
