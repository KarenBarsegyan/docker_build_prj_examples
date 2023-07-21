//**************************************************************************************************
//! @Module GPIO driver
//! \file   gpio_drv_irq.c
//! \par    Platform
//!             YTM32B1ME05
//! \par    Compatible
//!             YTM32B1ME05G0MLHT, YTM32B1ME05G0MLLT, YTM32B1ME05G0MLQT
//! \brief  This file contains interrupt service routines for GPIO driver.
//!
//! \par    Abbreviations
//!                 GPIO - General Purpose Input/Output
//!
//!
//! \par    History
//! | Date       | Version | Author | Comment
//! |:----------:|:-------:|:------:|---------------------------------------------------------------
//! | 08.05.2023 |  1.0.0  |  CAV   | First release.
//**************************************************************************************************



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

//! Native header
#include "gpio_drv.h"

//! GPIO IRQ realization
// #include "gpio_drv_irq.h"

//! Get MCU registers definitions
#include "derivative_cfg.h"



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

// PORT interrupt enable state macro
#define GPIO_PORT_IT_TRIGGER_ENABLE(PortName)                                         \
      ((GPIO_PORT_##PortName##_PIN_0_ENABLE  * GPIO_PORT_##PortName##_PIN_0_IT_TRIGGER) || \
       (GPIO_PORT_##PortName##_PIN_1_ENABLE  * GPIO_PORT_##PortName##_PIN_1_IT_TRIGGER) || \
       (GPIO_PORT_##PortName##_PIN_2_ENABLE  * GPIO_PORT_##PortName##_PIN_2_IT_TRIGGER) || \
       (GPIO_PORT_##PortName##_PIN_3_ENABLE  * GPIO_PORT_##PortName##_PIN_3_IT_TRIGGER) || \
       (GPIO_PORT_##PortName##_PIN_4_ENABLE  * GPIO_PORT_##PortName##_PIN_4_IT_TRIGGER) || \
       (GPIO_PORT_##PortName##_PIN_5_ENABLE  * GPIO_PORT_##PortName##_PIN_5_IT_TRIGGER) || \
       (GPIO_PORT_##PortName##_PIN_6_ENABLE  * GPIO_PORT_##PortName##_PIN_6_IT_TRIGGER) || \
       (GPIO_PORT_##PortName##_PIN_7_ENABLE  * GPIO_PORT_##PortName##_PIN_7_IT_TRIGGER) || \
       (GPIO_PORT_##PortName##_PIN_8_ENABLE  * GPIO_PORT_##PortName##_PIN_8_IT_TRIGGER) || \
       (GPIO_PORT_##PortName##_PIN_9_ENABLE  * GPIO_PORT_##PortName##_PIN_9_IT_TRIGGER) || \
       (GPIO_PORT_##PortName##_PIN_10_ENABLE * GPIO_PORT_##PortName##_PIN_10_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_11_ENABLE * GPIO_PORT_##PortName##_PIN_11_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_12_ENABLE * GPIO_PORT_##PortName##_PIN_12_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_13_ENABLE * GPIO_PORT_##PortName##_PIN_13_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_14_ENABLE * GPIO_PORT_##PortName##_PIN_14_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_15_ENABLE * GPIO_PORT_##PortName##_PIN_15_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_16_ENABLE * GPIO_PORT_##PortName##_PIN_16_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_17_ENABLE * GPIO_PORT_##PortName##_PIN_17_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_18_ENABLE * GPIO_PORT_##PortName##_PIN_18_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_19_ENABLE * GPIO_PORT_##PortName##_PIN_19_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_20_ENABLE * GPIO_PORT_##PortName##_PIN_20_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_21_ENABLE * GPIO_PORT_##PortName##_PIN_21_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_22_ENABLE * GPIO_PORT_##PortName##_PIN_22_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_23_ENABLE * GPIO_PORT_##PortName##_PIN_23_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_24_ENABLE * GPIO_PORT_##PortName##_PIN_24_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_25_ENABLE * GPIO_PORT_##PortName##_PIN_25_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_26_ENABLE * GPIO_PORT_##PortName##_PIN_26_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_27_ENABLE * GPIO_PORT_##PortName##_PIN_27_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_28_ENABLE * GPIO_PORT_##PortName##_PIN_28_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_29_ENABLE * GPIO_PORT_##PortName##_PIN_29_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_30_ENABLE * GPIO_PORT_##PortName##_PIN_30_IT_TRIGGER)|| \
       (GPIO_PORT_##PortName##_PIN_31_ENABLE * GPIO_PORT_##PortName##_PIN_31_IT_TRIGGER))



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
//! GPIO port A low level interrupt service routine
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
INTERRUPT void GPIO_PORT_A_Interrupt(void)
{
    // U8 nPinNumber = 0;
	#if (TRUE == GPIO_PORT_IT_TRIGGER_ENABLE(A))
    if (ON == GPIOA.PIFR.R)
    {
        // Find interrupt pin
    	while (FALSE == (GPIOA.PIFR.R & (1 << nPinNumber)))
    	{
    	    nPinNumber++;
    	}
    	// Clear pin interrupt flag
    	GPIOA.PIFR.R &= ~(1 << nPinNumber);
        // Call high-level ISR
        GPIO_HighLevel_ISR(GPIO_PORT_A, nPinNumber);
    }
    #endif
} // end of GPIO_PORT_A_Interrupt()

//**************************************************************************************************
//! GPIO port B low level interrupt service routine
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
INTERRUPT void GPIO_PORT_B_Interrupt(void)
{
    // U8 nPinNumber = 0;
	#if (TRUE == GPIO_PORT_IT_TRIGGER_ENABLE(B))
    if (ON == GPIOB.PIFR.R)
    {
        // Find interrupt pin
    	while (FALSE == (GPIOB.PIFR.R & (1 << nPinNumber)))
    	{
    	    nPinNumber++;
   	    }
    	// Clear pin interrupt flag
    	GPIOB.PIFR.R &= ~(1 << nPinNumber);
        // Call high-level ISR
        GPIO_HighLevel_ISR(GPIO_PORT_B, nPinNumber);
    }
    #endif
} // end of GPIO_PORT_B_Interrupt()

//**************************************************************************************************
//! GPIO port C low level interrupt service routine
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
INTERRUPT void GPIO_PORT_C_Interrupt(void)
{
    // U8 nPinNumber = 0;
	#if (TRUE == GPIO_PORT_IT_TRIGGER_ENABLE(C))
    if (ON == GPIOC.PIFR.R)
    {
        // Find interrupt pin
    	while (FALSE == (GPIOC.PIFR.R & (1 << nPinNumber)))
    	{
    	    nPinNumber++;
    	}
    	// Clear the interrupt flag
    	GPIOC.PIFR.R &= ~(1 << nPinNumber);
        // Call high-level ISR
        GPIO_HighLevel_ISR(GPIO_PORT_C, nPinNumber);
    }
    #endif
} // end of GPIO_PORT_C_Interrupt()

//**************************************************************************************************
//! GPIO port D low level interrupt service routine
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
INTERRUPT void GPIO_PORT_D_Interrupt(void)
{
    // U8 nPinNumber = 0;
	#if (TRUE == GPIO_PORT_IT_TRIGGER_ENABLE(D))
    if (ON == GPIOD.PIFR.R)
    {
        // Find interrupt pin
    	while (FALSE == (GPIOD.PIFR.R & (1 << nPinNumber)))
    	{
    	    nPinNumber++;
    	}
    	// Clear pin interrupt flag
    	GPIOD.PIFR.R &= ~(1 << nPinNumber);
        // Call high-level ISR
        GPIO_HighLevel_ISR(GPIO_PORT_D, nPinNumber);
    }
    #endif
} // end of GPIO_PORT_D_Interrupt()

//**************************************************************************************************
//! GPIO port E low level interrupt service routine
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
INTERRUPT void GPIO_PORT_E_Interrupt(void)
{
    // U8 nPinNumber = 0;
	#if (TRUE == GPIO_PORT_IT_TRIGGER_ENABLE(E))
    if (ON == GPIOE.PIFR.R)
    {
        // Find interrupt pin
    	while (FALSE == (GPIOE.PIFR.R & (1 << nPinNumber)))
    	{
    	    nPinNumber++;
    	}
    	// Clear pin interrupt flag
    	GPIOE.PIFR.R &= ~(1 << nPinNumber);
        // Call high-level ISR
        GPIO_HighLevel_ISR(GPIO_PORT_E, nPinNumber);
    }
    #endif
} // end of GPIO_PORT_E_Interrupt()

//**************************************************************************************************
//==================================================================================================
// Definitions of local (private) functions
//==================================================================================================
//**************************************************************************************************

// None



//****************************************** end of file *******************************************
