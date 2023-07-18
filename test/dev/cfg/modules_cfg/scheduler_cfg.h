//**************************************************************************************************
// @Module        SCHDL
//! \file       scheduler_cfg.h
//! \par    Platform
//!             Cortex-M4
//! \par    Compatible
//!             STM32F4, APM32F4, AT32F4, HC32F4A families
//! \brief      Configuration of the required functionality of the task scheduler module.
//! \par        History       
//! Date       | Version | Author  | Comment
//! :---------:|:-------:|:-------:|---------------
//! 18.01.2017 |  1.0.0  |   SHA   | First release.
//! 06.04.2023 |  1.0.1  |   PAV   | Added Scheduler handler IRQ number (for Cortex cores).
//**************************************************************************************************

#ifndef SCHDL_CFG_H
#define SCHDL_CFG_H



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

//! Enable/disable the development error detection feature of the program module.
//! Used only for debug purposes and should be disabled in the final release.
//! Valid values: ON / OFF
#define SCHDL_DEVELOPMENT_ERROR_DETECTION      (OFF)

//! User can enable/disable the internal diagnostic of the program module.
//! Used only for debug purposes and should be disabled in the final release.
//! Valid values: ON / OFF
#define SCHDL_INTERNAL_DIAGNOSTICS             (ON)



//! The number of tasks in the system
// !!! Attention for XC2000!!!
//! This constant must be equal to SCHDL_TASK_COUNT from scheduler_cfg.inc
#define SCHDL_TASK_COUNT        (32U)

//! The maximum number of running tasks (must be even)
#define SCHDL_MAX_RUN_TASK      (20U)

//! Select IRQ number for Scheduler handler
//! !!! Must be specified in irq_drv_cfg.h !!!
#define SCHDL_IRQ_NUMBER        (6U)



#endif // #ifndef SCHDL_CFG_H

//****************************************** end of file *******************************************
