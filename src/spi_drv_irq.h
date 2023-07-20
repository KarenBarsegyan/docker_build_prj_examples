//**************************************************************************************************
// @Module  SPI driver
//! \file   spi_drv.h
//! \par    Platform
//!             YTM32
//! \par    Compatible
//!             YTM32B1M families
//! \brief  Interface of the SPI IRQ module.
//!
//! \par    Abbreviations
//!             SPI - Serial Peripheral Interface
//! \par    History
//! | Date       | Version | Author  | Comment
//! |:----------:|:-------:|:-------:|--------------------------------------------------------------
//! | 00.00.2023 |  1.0.0  |   BKR   | First release.
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

#if(ON == SPI_CHANNEL_1_IN_USE)
extern INTERRUPT void SPI_LowLevel_1_Interrupt(void);
#endif

#if(ON == SPI_CHANNEL_2_IN_USE)
extern INTERRUPT void SPI_LowLevel_2_Interrupt(void);
#endif

#if(ON == SPI_CHANNEL_3_IN_USE)
extern INTERRUPT void SPI_LowLevel_3_Interrupt(void);
#endif

#if(ON == SPI_CHANNEL_4_IN_USE)
extern INTERRUPT void SPI_LowLevel_4_Interrupt(void);
#endif

#if(ON == SPI_CHANNEL_5_IN_USE)
extern INTERRUPT void SPI_LowLevel_5_Interrupt(void);
#endif

#if(ON == SPI_CHANNEL_6_IN_USE)
extern INTERRUPT void SPI_LowLevel_6_Interrupt(void);
#endif



#endif  // SPI_DRV_IRQ_H

//****************************************** end of file *******************************************