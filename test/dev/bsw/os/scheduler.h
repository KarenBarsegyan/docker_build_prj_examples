//**************************************************************************************************
// @Module        SCHDL
//! \file       scheduler.h
//! \brief      Interface of the task scheduler module.
//! \par        History       
//! Date       | Version | Author  | Comment
//! :---------:|:-------:|:-------:|---------------
//! 30.05.2017 |  1.0.0  |   SHA   | First release.
//! 25.06.2019 |  1.1.0  |   ZAO   | Added function SCHDL_GetAndResetIdleCounter() prototype.
//! 25.07.2019 |  1.2.0  |   SHA   | Added function SCHDL_RunLevelImmed() prototype.
//! 14.04.2023 |  1.2.1  |   PAV   | Refactoring according to Doxygen rules.
//**************************************************************************************************

#ifndef SCHDL_H
#define SCHDL_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Get data types
#include "scheduler_cfg.h"
#include "compiler.h"
#include "general.h"



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

//! The bit map of task requests
extern U16  SCHDL_nTaskQuery[];

//! The bit map of flags of running task
extern U16  SCHDL_nTaskRunning[];

//! Running task counter
extern NEAR U8  SCHDL_nRunningTaskCounter;



//**************************************************************************************************
// Declarations of global (public) functions
//**************************************************************************************************

//! \brief Initializes SW and HW resources for task scheduler
extern void SCHDL_Init(void);

//! \brief Deinitializes SW and HW resources for task scheduler
extern void SCHDL_DeInit(void);

//! \brief Enable of task scheduler functionality
extern void SCHDL_Enable(void);

//! \brief Disable of task scheduler functionality
extern void SCHDL_Disable(void);

//! \brief Launch the specified level
extern U8 SCHDL_StartLevel(U16 nLevelNumber);

//! \brief To activate the level, but do not start
extern U8 SCHDL_ActivateLevel(U16 nLevelNumber);

//! \brief Level Start Immediately
extern void SCHDL_RunLevelImmed(U16 nLevelNumber);

//! \brief Start the scheduler
extern void SCHDL_StartSchedule(void);

//! \brief Increment of idle counter
extern void SCHDL_IncIdleCounter(void);

//! \brief Get of idle counter
extern U32 SCHDL_GetIdleCounter(void);

//! \brief Get and reset idle counter
extern U32 SCHDL_GetAndResetIdleCounter(void);



#endif // #ifndef SCHDL_H

//****************************************** end of file *******************************************
