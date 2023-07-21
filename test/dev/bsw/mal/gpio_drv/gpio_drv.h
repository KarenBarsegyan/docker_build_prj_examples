//**************************************************************************************************
// @Module        GPIO driver
// @Filename      gpio_drv.h
//--------------------------------------------------------------------------------------------------
// @Description   Interface of the GPIO driver.
//--------------------------------------------------------------------------------------------------
// @Version       2.1.1
//--------------------------------------------------------------------------------------------------
// @Date          23.12.2015
//--------------------------------------------------------------------------------------------------
// @History       Version  Author      Comment
// 05.02.2015     2.0.0    SRM         Second release.
// 15.10.2015     2.1.0    SRM         A new wakeup event-driven handler system.
// 23.12.2015     2.1.1    SAM         Modified parameter "pWakeupCallback" by "pWakeupHandler"
//                                     in the function GPIO_SetWakeupEventHandler().
//**************************************************************************************************

#ifndef GPIO_DRV_H
#define GPIO_DRV_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Get data types
#include "compiler.h"

// Get generic definitions
#include "general.h"

// Get configuration of the program module
#include "gpio_drv_cfg.h"



//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************

// Program module wakeup event handler function type
typedef void (*GPIO_WAKEUP_HANDLER)(const U8 nEventID);



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

// Pin value definitions
#define GPIO_PIN_LOW            (LOGIC_0)
#define GPIO_PIN_HIGH           (LOGIC_1)

// Pin direction definitions
#define GPIO_PIN_INPUT          (0U)
#define GPIO_PIN_OUTPUT         (1U)



//**************************************************************************************************
// Declarations of global (public) variables
//**************************************************************************************************

// None.



//**************************************************************************************************
// Declarations of global (public) functions
//**************************************************************************************************

// Initializes SW and HW resources of the program module
extern STD_RESULT GPIO_Init(void);

// Deinitializes SW and HW resources of the program module
extern STD_RESULT GPIO_DeInit(void);

// Returns actual direction of the digital input/output pin
extern STD_RESULT GPIO_GetPinDirection(const U8 nPortNumber,
                                       const U8 nPinNumber,
                                       U8* const pDirection);

// Sets a new direction of the specified digital input/output pin
extern STD_RESULT GPIO_SetPinDirection(const U8 nPortNumber,
                                       const U8 nPinNumber,
                                       const U8 nDirection);

// Returns actual logic state of the digital input/output pin
extern STD_RESULT GPIO_GetPinState(const U8 nPortNumber,
                                   const U8 nPinNumber,
                                   U8* const pLogicState);

// Sets a new logic state of the specified digital input/output pin
extern STD_RESULT GPIO_SetPinState(const U8 nPortNumber,
                                   const U8 nPinNumber,
                                   const U8 nLogicState);

// Enables/disables wakeup on the specified digital input/output pin
extern STD_RESULT GPIO_WakeupEnable(const U8      nPortNumber,
                                    const U8      nPinNumber,
                                    const BOOLEAN bEnable);

// Sets pointer to the wakeup event handler function for the specified digital input/output pin
extern STD_RESULT GPIO_SetWakeupEventHandler(const U8 nPortNumber,
                                             const U8 nPinNumber,
                                             const U8 nEventID,
                                             const GPIO_WAKEUP_HANDLER pWakeupHandler);

// High-level wakeup interrupt service routine for all of the digital input/output pins
extern void GPIO_HighLevel_Wakeup_ISR(const U8 nPortNumber,
                                      const U8 nPinNumber);



#endif // #ifndef GPIO_DRV_H

//****************************************** end of file *******************************************
