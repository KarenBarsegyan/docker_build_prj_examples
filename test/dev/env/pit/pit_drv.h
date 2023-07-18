//**************************************************************************************************
// @Module        PIT driver
// @Filename      pit_drv.h
//--------------------------------------------------------------------------------------------------
// @Description   Interface of the PIT (Freescale's RTI timer) driver.
//--------------------------------------------------------------------------------------------------
// @Version       2.0.1
//--------------------------------------------------------------------------------------------------
// @Date          31.10.2017
//--------------------------------------------------------------------------------------------------
// @History       Version  Author      Comment
// 21.01.2015     2.0.0    SRM         Second release.
// 31.10.2017     2.0.1    SHA         Parameter has been added in PIT_HighLevel_ISR() function. 
//**************************************************************************************************

#ifndef PIT_DRV_H
#define PIT_DRV_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Define data types
#include "pit_drv_cfg.h"
#include "compiler.h"
#include "general.h"



//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************

// Callback function type
typedef void (*PIT_CALLBACK)(void);



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

// Initializes SW and HW program module resources
extern STD_RESULT PIT_Init(const U8 nTimerNumber);

// Deinitializes SW and HW program module resources
extern STD_RESULT PIT_DeInit(const U8 nTimerNumber);

// Returns current value of the timer counter
extern STD_RESULT PIT_GetTime(const U8 nTimerNumber,
                              PIT_SZ* const pTimerCounter);

// Sets the timer counter value
extern STD_RESULT PIT_SetTime(const U8 nTimerNumber,
                              const PIT_SZ nTimerCounter);

// Sets the timer period and starts the timer
extern STD_RESULT PIT_StartTimer(const U8 nTimerNumber,
                                 const PIT_SZ nTimerPeriod);

// Stops the timer
extern STD_RESULT PIT_StopTimer(const U8 nTimerNumber);

// Returns the timer tick period in nanoseconds
extern STD_RESULT PIT_GetTickPeriod(const U8    nTimerNumber,
                                    U32*  const pTickPeriod);

// Sets callback function pointer for the program module
extern STD_RESULT PIT_SetCallbackFunction(const U8 nTimerNumber,
                                          const PIT_CALLBACK pCallbackFunction);

// High-level interrupt service routine
extern void PIT_HighLevel_ISR(const U8 nTimerNumber);



#endif // #ifndef PIT_DRV_H

//****************************************** end of file *******************************************
