//**************************************************************************************************
// @Module  SPI driver
//! \file   spi_drv_irq.c
//! \par    Platform
//!             YTM32
//! \par    Compatible
//!             YTM32B1M families
//! \brief  Low-level interrupt service routines for SPI driver.
//!
//! \par    Abbreviations
//!             MCU - MicroController Unit
//!             SPI - Serial Peripheral Interface
//! \par    History
//! | Date       | Version | Author  | Comment
//! |:----------:|:-------:|:-------:|--------------------------------------------------------------
//! | 11.08.2023 |  1.0.0  |   BKR   | First release.
//**************************************************************************************************



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Native header
#include "spi_drv_irq.h"

// SPI interface
#include "spi_drv.h"

// Get program module specific types
#include "spi_drv_types.h"

// Get SFR registers header
#include "ytm32b1m_sfr.h"



//**************************************************************************************************
// Verification of the imported configuration parameters
//**************************************************************************************************

// None.



//**************************************************************************************************
// Definitions of global (public) variables
//**************************************************************************************************

// None.



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

// None



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
//! SPI channel 0 interrupt service routine
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
INTERRUPT void SPI_LowLevel_0_Interrupt(void)
{
#if (TRUE == SPI_CHANNEL_0_IN_USE)
    SPI_HighLevel_RX_ISR(SPI_CHANNEL_0);
    SPI_HighLevel_TX_ISR(SPI_CHANNEL_0);  
#endif
} // end of SPI_LowLevel_0_Interrupt()



//**************************************************************************************************
//! SPI channel 1 interrupt service routine
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
INTERRUPT void SPI_LowLevel_1_Interrupt(void)
{
#if (TRUE == SPI_CHANNEL_1_IN_USE)
    SPI_HighLevel_RX_ISR(SPI_CHANNEL_1);
    SPI_HighLevel_TX_ISR(SPI_CHANNEL_1);
#endif
} // end of SPI_LowLevel_1_Interrupt()



//**************************************************************************************************
//! SPI channel 2 interrupt service routine
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
INTERRUPT void SPI_LowLevel_2_Interrupt(void)
{
#if (TRUE == SPI_CHANNEL_2_IN_USE)
    SPI_HighLevel_RX_ISR(SPI_CHANNEL_2);
    SPI_HighLevel_TX_ISR(SPI_CHANNEL_2);
#endif
} // end of SPI_LowLevel_2_Interrupt()



//**************************************************************************************************
//! SPI channel 3 interrupt service routine
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
INTERRUPT void SPI_LowLevel_3_Interrupt(void)
{
    #if (TRUE == SPI_CHANNEL_3_IN_USE)
    SPI_HighLevel_RX_ISR(SPI_CHANNEL_3);
    SPI_HighLevel_TX_ISR(SPI_CHANNEL_3);
    #endif
} // end of SPI_LowLevel_3_Interrupt()



//**************************************************************************************************
//! SPI channel 4 interrupt service routine
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
INTERRUPT void SPI_LowLevel_4_Interrupt(void)
{
    #if (TRUE == SPI_CHANNEL_4_IN_USE)
    SPI_HighLevel_RX_ISR(SPI_CHANNEL_4);
    SPI_HighLevel_TX_ISR(SPI_CHANNEL_4);
    #endif
} // end of SPI_LowLevel_4_Interrupt()



//**************************************************************************************************
//! SPI channel 5 interrupt service routine
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
INTERRUPT void SPI_LowLevel_5_Interrupt(void)
{
    #if (TRUE == SPI_CHANNEL_5_IN_USE)
    SPI_HighLevel_RX_ISR(SPI_CHANNEL_5);
    SPI_HighLevel_TX_ISR(SPI_CHANNEL_5);
    #endif
} // end of SPI_LowLevel_5_Interrupt()



//**************************************************************************************************
//==================================================================================================
// Definitions of local (private) functions
//==================================================================================================
//**************************************************************************************************

// None.



//****************************************** end of file *******************************************
