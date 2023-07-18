//**************************************************************************************************
// @Module       IRQ
//! \file        irq_drv_cfg.h.tmpl
//! \brief       Configuration of the required functionality of the IRQ module.
//!
//! \par         History
//! | Date       | Version | Author  | Comment
//! |:----------:|:-------:|:-------:|--------------------------------------------------------------
//! | 05.05.2023 |  1.0.0  |   FAV   | First release.
//**************************************************************************************************

#ifndef IRQ_DRV_CFG_H
#define IRQ_DRV_CFG_H



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

//! Specify a location vector table. \n
//! Valid values: all Flash address ranges.
#define IRQ_VECTOR_TABLE_LOCATION                                      (0x00000000UL)

//! Specify a number of group priorities. \n
//! Valid values: IRQ_QTY_GROUP_PRIORITY_2, IRQ_QTY_GROUP_PRIORITY_4, \n
//!               IRQ_QTY_GROUP_PRIORITY_8, IRQ_QTY_GROUP_PRIORITY_16
#define IRQ_QTY_GROUP_PRIORITIES                                       (IRQ_QTY_GROUP_PRIORITY_4)


//! #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL: \n
//! for IRQ_QTY_GROUP_PRIORITIES == IRQ_QTY_GROUP_PRIORITY_2: \n
//!                              IRQ_GROUP_PRIORITY_LEVEL_MAX, IRQ_GROUP_PRIORITY_LEVEL_MIN \n
//! \n
//! for IRQ_QTY_GROUP_PRIORITIES == IRQ_QTY_GROUP_PRIORITY_4: \n
//!                              IRQ_GROUP_PRIORITY_LEVEL_MAX, IRQ_GROUP_PRIORITY_LEVEL_1, \n
//!                              IRQ_GROUP_PRIORITY_LEVEL_2,   IRQ_GROUP_PRIORITY_LEVEL_MIN \n
//! \n
//! for IRQ_QTY_GROUP_PRIORITIES == IRQ_QTY_GROUP_PRIORITY_8: \n
//!                              IRQ_GROUP_PRIORITY_LEVEL_MAX, IRQ_GROUP_PRIORITY_LEVEL_1 \n
//!                              IRQ_GROUP_PRIORITY_LEVEL_2,   IRQ_GROUP_PRIORITY_LEVEL_3, \n
//!                              IRQ_GROUP_PRIORITY_LEVEL_4,   IRQ_GROUP_PRIORITY_LEVEL_5, \n
//!                              IRQ_GROUP_PRIORITY_LEVEL_6,   IRQ_GROUP_PRIORITY_LEVEL_MIN; \n
//! \n
//! for IRQ_QTY_GROUP_PRIORITIES == IRQ_QTY_GROUP_PRIORITY_16: \n
//!                              IRQ_GROUP_PRIORITY_LEVEL_MAX, IRQ_GROUP_PRIORITY_LEVEL_1, \n
//!                              IRQ_GROUP_PRIORITY_LEVEL_2,   IRQ_GROUP_PRIORITY_LEVEL_3, \n
//!                              IRQ_GROUP_PRIORITY_LEVEL_4,   IRQ_GROUP_PRIORITY_LEVEL_5, \n
//!                              IRQ_GROUP_PRIORITY_LEVEL_6,   IRQ_GROUP_PRIORITY_LEVEL_7; \n
//!                              IRQ_GROUP_PRIORITY_LEVEL_8,   IRQ_GROUP_PRIORITY_LEVEL_9; \n
//!                              IRQ_GROUP_PRIORITY_LEVEL_10,  IRQ_GROUP_PRIORITY_LEVEL_11; \n
//!                              IRQ_GROUP_PRIORITY_LEVEL_12,  IRQ_GROUP_PRIORITY_LEVEL_13; \n
//!                              IRQ_GROUP_PRIORITY_LEVEL_14,  IRQ_GROUP_PRIORITY_LEVEL_MIN; \n
//! \n
//! #valid_values_IRQ_x_SUB_PRIORITY_LEVEL: \n
//! for IRQ_QTY_GROUP_PRIORITIES == IRQ_QTY_GROUP_PRIORITY_2: \n
//!                              IRQ_SUB_PRIORITY_LEVEL_MAX, IRQ_SUB_PRIORITY_LEVEL_1, \n
//!                              IRQ_SUB_PRIORITY_LEVEL_2,   IRQ_SUB_PRIORITY_LEVEL_3, \n
//!                              IRQ_SUB_PRIORITY_LEVEL_4,   IRQ_SUB_PRIORITY_LEVEL_5, \n
//!                              IRQ_SUB_PRIORITY_LEVEL_6,   IRQ_SUB_PRIORITY_LEVEL_MIN; \n
//! \n
//! for IRQ_QTY_GROUP_PRIORITIES == IRQ_QTY_GROUP_PRIORITY_4: \n
//!                              IRQ_SUB_PRIORITY_LEVEL_MAX, IRQ_SUB_PRIORITY_LEVEL_1, \n
//!                              IRQ_SUB_PRIORITY_LEVEL_2,   IRQ_SUB_PRIORITY_LEVEL_MIN; \n
//! \n
//! for IRQ_QTY_GROUP_PRIORITIES == IRQ_QTY_GROUP_PRIORITY_8: \n
//!                              IRQ_SUB_PRIORITY_LEVEL_MAX, IRQ_SUB_PRIORITY_LEVEL_MIN, \n
//! \n
//! for IRQ_QTY_GROUP_PRIORITIES == IRQ_QTY_GROUP_PRIORITY_16: \n
//!                              IRQ_SUB_PRIORITY_LEVEL_MIN \n
//! \n
//! Note: The lower the value, the greater the priority of the corresponding interrupt.



//**************************************************************************************************
// Settings system handler
//**************************************************************************************************

//! Specify an alias for reset handler \n
//! Valid values: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_SYS_HANDLER_RESET_ALIAS                                    STARTUP_Cstart

//! Specify an alias for NMI handler \n
//! Valid values: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_SYS_HANDLER_NMI_ALIAS                                      IRQ_DEFAULT_HANDLER

//! Specify an alias for hard fault handler \n
//! Valid values: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_SYS_HANDLER_HARDFAULT_ALIAS                                IRQ_DEFAULT_HANDLER

//! Enable or disable of MemManage system handler. \n
//! Valid values: ON, OFF.
#define IRQ_SYS_HANDLER_MEM_MANAGE_ENABLE                              (OFF)
//! Specify an alias for the MemManage system handler. \n
//! Valid values: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_SYS_HANDLER_MEM_MANAGE_ALIAS                               IRQ_DEFAULT_HANDLER
//! Specify group priority level for the MemManage system handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_SYS_HANDLER_MEM_MANAGE_GROUP_PRIORITY_LEVEL                (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! Specify sub-priority level for the MemManage system handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_SYS_HANDLER_MEM_MANAGE_SUB_PRIORITY_LEVEL                  (IRQ_SUB_PRIORITY_LEVEL_MIN)


//! Enable or disable of BusFault system handler. \n
//! Valid values: ON, OFF.
#define IRQ_SYS_HANDLER_BUS_FAULT_ENABLE                               (OFF)
//! An alias for the BusFault system handler. \n
//! Valid values: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_SYS_HANDLER_BUS_FAULT_ALIAS                                IRQ_DEFAULT_HANDLER
//! The group priority level for the BusFault system handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_SYS_HANDLER_BUS_FAULT_GROUP_PRIORITY_LEVEL                 (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the BusFault system handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_SYS_HANDLER_BUS_FAULT_SUB_PRIORITY_LEVEL                   (IRQ_SUB_PRIORITY_LEVEL_MIN)


//! Enable or disable of UsageFault system handler. \n
//! Valid values: ON, OFF.
#define IRQ_SYS_HANDLER_USAGE_FAULT_ENABLE                             (OFF)
//! An alias for the UsageFault system handler. \n
//! Valid values: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_SYS_HANDLER_USAGE_FAULT_ALIAS                              IRQ_DEFAULT_HANDLER
//! The group priority level for the UsageFault system handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_SYS_HANDLER_USAGE_FAULT_GROUP_PRIORITY_LEVEL               (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the UsageFault system handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_SYS_HANDLER_USAGE_FAULT_SUB_PRIORITY_LEVEL                 (IRQ_SUB_PRIORITY_LEVEL_MIN)


//! An alias for the SVCall system handler. \n
//! Valid values: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_SYS_HANDLER_SV_CALL_ALIAS                                  SCHDL_SchedulerClose
//! The group priority level for the SVCall system handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_SYS_HANDLER_SV_CALL_GROUP_PRIORITY_LEVEL                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the SVCall system handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_SYS_HANDLER_SV_CALL_SUB_PRIORITY_LEVEL                     (IRQ_SUB_PRIORITY_LEVEL_MIN)


//! An alias for the PendSV system handler. \n
//! Valid values: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_SYS_HANDLER_PEND_SV_ALIAS                                  IRQ_DEFAULT_HANDLER
//! The group priority level for the PendSV handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_SYS_HANDLER_PEND_SV_GROUP_PRIORITY_LEVEL                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the PendSV system handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_SYS_HANDLER_PEND_SV_SUB_PRIORITY_LEVEL                     (IRQ_SUB_PRIORITY_LEVEL_MIN)


//! Enable or disable of Systick system handler. \n
//! Valid values: ON, OFF.
#define IRQ_SYS_HANDLER_SYSTICK_ENABLE                                 (ON)
//! An alias for the Systick system handler. \n
//! Valid values: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_SYS_HANDLER_SYSTICK_ALIAS                                  PIT_HighLevel_ISR
//! The group priority level for the Systick handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_SYS_HANDLER_SYSTICK_GROUP_PRIORITY_LEVEL                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the Systick system handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_SYS_HANDLER_SYSTICK_SUB_PRIORITY_LEVEL                     (IRQ_SUB_PRIORITY_LEVEL_MIN)



//**************************************************************************************************
//----------------------------------Settings peripherals handler------------------------------------
//**************************************************************************************************
//! Enable IRQ_0 \n
//! Valid values: ON, OFF.
#define IRQ_0_ENABLE                                                   (OFF)
//! Aliases for the IRQ_0 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_0_ALIAS_FUN1                                               IRQ_DEFAULT_HANDLER
#define IRQ_0_ALIAS_FUN2                                               IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_0 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_0_GROUP_PRIORITY_LEVEL                                     (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_0 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_0_SUB_PRIORITY_LEVEL                                       (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_1 \n
//! Valid values: ON, OFF.
#define IRQ_1_ENABLE                                                   (OFF)
//! Aliases for the IRQ_1 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_1_ALIAS_FUN1                                               IRQ_DEFAULT_HANDLER
#define IRQ_1_ALIAS_FUN2                                               IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_1 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_1_GROUP_PRIORITY_LEVEL                                     (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_1 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_1_SUB_PRIORITY_LEVEL                                       (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_2 \n
//! Valid values: ON, OFF.
#define IRQ_2_ENABLE                                                   (OFF)
//! Aliases for the IRQ_2 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_2_ALIAS_FUN1                                               IRQ_DEFAULT_HANDLER
#define IRQ_2_ALIAS_FUN2                                               IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_2 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_2_GROUP_PRIORITY_LEVEL                                     (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_2 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_2_SUB_PRIORITY_LEVEL                                       (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_3 \n
//! Valid values: ON, OFF.
#define IRQ_3_ENABLE                                                   (OFF)
//! Aliases for the IRQ_3 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_3_ALIAS_FUN1                                               IRQ_DEFAULT_HANDLER
#define IRQ_3_ALIAS_FUN2                                               IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_3 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_3_GROUP_PRIORITY_LEVEL                                     (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_3 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_3_SUB_PRIORITY_LEVEL                                       (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_4 \n
//! Valid values: ON, OFF.
#define IRQ_4_ENABLE                                                   (OFF)
//! Aliases for the IRQ_4 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_4_ALIAS_FUN1                                               IRQ_DEFAULT_HANDLER
#define IRQ_4_ALIAS_FUN2                                               IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_4 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_4_GROUP_PRIORITY_LEVEL                                     (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_4 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_4_SUB_PRIORITY_LEVEL                                       (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_5 \n
//! Valid values: ON, OFF.
#define IRQ_5_ENABLE                                                   (OFF)
//! Aliases for the IRQ_5 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_5_ALIAS_FUN1                                               IRQ_DEFAULT_HANDLER
#define IRQ_5_ALIAS_FUN2                                               IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_5 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_5_GROUP_PRIORITY_LEVEL                                     (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_5 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_5_SUB_PRIORITY_LEVEL                                       (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_6 \n
//! Valid values: ON, OFF.
#define IRQ_6_ENABLE                                                   (ON)
//! Aliases for the IRQ_6 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_6_ALIAS_FUN1                                               SCHDL_SchedulerProc
#define IRQ_6_ALIAS_FUN2                                               IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_6 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_6_GROUP_PRIORITY_LEVEL                                     (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_6 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_6_SUB_PRIORITY_LEVEL                                       (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_7 \n
//! Valid values: ON, OFF.
#define IRQ_7_ENABLE                                                   (OFF)
//! Aliases for the IRQ_7 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_7_ALIAS_FUN1                                               IRQ_DEFAULT_HANDLER
#define IRQ_7_ALIAS_FUN2                                               IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_7 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_7_GROUP_PRIORITY_LEVEL                                     (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_7 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_7_SUB_PRIORITY_LEVEL                                       (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_8 \n
//! Valid values: ON, OFF.
#define IRQ_8_ENABLE                                                   (OFF)
//! Aliases for the IRQ_8 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_8_ALIAS_FUN1                                               IRQ_DEFAULT_HANDLER
#define IRQ_8_ALIAS_FUN2                                               IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_8 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_8_GROUP_PRIORITY_LEVEL                                     (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_8 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_8_SUB_PRIORITY_LEVEL                                       (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_9 \n
//! Valid values: ON, OFF.
#define IRQ_9_ENABLE                                                   (OFF)
//! Aliases for the IRQ_9 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_9_ALIAS_FUN1                                               IRQ_DEFAULT_HANDLER
#define IRQ_9_ALIAS_FUN2                                               IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_9 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_9_GROUP_PRIORITY_LEVEL                                     (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_9 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_9_SUB_PRIORITY_LEVEL                                       (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_10 \n
//! Valid values: ON, OFF.
#define IRQ_10_ENABLE                                                  (OFF)
//! Aliases for the IRQ_10 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_10_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_10_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_10 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_10_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_10 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_10_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_11 \n
//! Valid values: ON, OFF.
#define IRQ_11_ENABLE                                                  (OFF)
//! Aliases for the IRQ_11 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_11_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_11_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_11 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_11_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_11 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_11_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_12 \n
//! Valid values: ON, OFF.
#define IRQ_12_ENABLE                                                  (OFF)
//! Aliases for the IRQ_12 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_12_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_12_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_12 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_12_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_12 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_12_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_13 \n
//! Valid values: ON, OFF.
#define IRQ_13_ENABLE                                                  (OFF)
//! Aliases for the IRQ_13 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_13_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_13_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_13 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_13_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_13 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_13_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_14 \n
//! Valid values: ON, OFF.
#define IRQ_14_ENABLE                                                  (OFF)
//! Aliases for the IRQ_14 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_14_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_14_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_14 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_14_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_14 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_14_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_15 \n
//! Valid values: ON, OFF.
#define IRQ_15_ENABLE                                                  (OFF)
//! Aliases for the IRQ_15 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_15_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_15_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_15 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_15_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_15 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_15_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_16 \n
//! Valid values: ON, OFF.
#define IRQ_16_ENABLE                                                  (OFF)
//! Aliases for the IRQ_16 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_16_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_16_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_16 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_16_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_16 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_16_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_17 \n
//! Valid values: ON, OFF.
#define IRQ_17_ENABLE                                                  (OFF)
//! Aliases for the IRQ_17 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_17_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_17_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_17 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_17_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_17 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_17_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_18 \n
//! Valid values: ON, OFF.
#define IRQ_18_ENABLE                                                  (OFF)
//! Aliases for the IRQ_18 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_18_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_18_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_18 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_18_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_18 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_18_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_19 \n
//! Valid values: ON, OFF.
#define IRQ_19_ENABLE                                                  (OFF)
//! Aliases for the IRQ_19 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_19_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_19_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_19 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_19_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_19 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_19_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_20 \n
//! Valid values: ON, OFF.
#define IRQ_20_ENABLE                                                  (OFF)
//! Aliases for the IRQ_20 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_20_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_20_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_20 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_20_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_20 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_20_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_21 \n
//! Valid values: ON, OFF.
#define IRQ_21_ENABLE                                                  (OFF)
//! Aliases for the IRQ_21 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_21_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_21_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_21 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_21_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_21 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_21_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_22 \n
//! Valid values: ON, OFF.
#define IRQ_22_ENABLE                                                  (OFF)
//! Aliases for the IRQ_22 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_22_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_22_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_22 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_22_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_22 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_22_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_23 \n
//! Valid values: ON, OFF.
#define IRQ_23_ENABLE                                                  (OFF)
//! Aliases for the IRQ_23 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_23_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_23_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_23 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_23_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_23 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_23_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_24 \n
//! Valid values: ON, OFF.
#define IRQ_24_ENABLE                                                  (OFF)
//! Aliases for the IRQ_24 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_24_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_24_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_24 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_24_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_24 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_24_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_25 \n
//! Valid values: ON, OFF.
#define IRQ_25_ENABLE                                                  (OFF)
//! Aliases for the IRQ_25 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_25_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_25_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_25 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_25_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_25 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_25_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_26 \n
//! Valid values: ON, OFF.
#define IRQ_26_ENABLE                                                  (OFF)
//! Aliases for the IRQ_26 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_26_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_26_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_26 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_26_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_26 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_26_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_27 \n
//! Valid values: ON, OFF.
#define IRQ_27_ENABLE                                                  (OFF)
//! Aliases for the IRQ_27 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_27_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_27_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_27 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_27_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_27 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_27_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_28 \n
//! Valid values: ON, OFF.
#define IRQ_28_ENABLE                                                  (OFF)
//! Aliases for the IRQ_28 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_28_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_28_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_28 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_28_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_28 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_28_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_29 \n
//! Valid values: ON, OFF.
#define IRQ_29_ENABLE                                                  (OFF)
//! Aliases for the IRQ_29 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_29_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_29_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_29 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_29_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_29 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_29_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_30 \n
//! Valid values: ON, OFF.
#define IRQ_30_ENABLE                                                  (OFF)
//! Aliases for the IRQ_30 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_30_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_30_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_30 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_30_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_30 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_30_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_31 \n
//! Valid values: ON, OFF.
#define IRQ_31_ENABLE                                                  (OFF)
//! Aliases for the IRQ_31 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_31_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_31_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_31 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_31_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_31 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_31_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_32 \n
//! Valid values: ON, OFF.
#define IRQ_32_ENABLE                                                  (OFF)
//! Aliases for the IRQ_32 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_32_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_32_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_32 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_32_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_32 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_32_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_33 \n
//! Valid values: ON, OFF.
#define IRQ_33_ENABLE                                                  (OFF)
//! Aliases for the IRQ_33 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_33_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_33_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_33 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_33_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_33 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_33_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_34 \n
//! Valid values: ON, OFF.
#define IRQ_34_ENABLE                                                  (OFF)
//! Aliases for the IRQ_34 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_34_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_34_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_34 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_34_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_34 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_34_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_35 \n
//! Valid values: ON, OFF.
#define IRQ_35_ENABLE                                                  (OFF)
//! Aliases for the IRQ_35 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_35_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_35_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_35 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_35_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_35 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_35_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_36 \n
//! Valid values: ON, OFF.
#define IRQ_36_ENABLE                                                  (OFF)
//! Aliases for the IRQ_36 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_36_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_36_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_36 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_36_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_36 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_36_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_37 \n
//! Valid values: ON, OFF.
#define IRQ_37_ENABLE                                                  (OFF)
//! Aliases for the IRQ_37 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_37_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_37_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_37 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_37_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_37 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_37_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_38 \n
//! Valid values: ON, OFF.
#define IRQ_38_ENABLE                                                  (OFF)
//! Aliases for the IRQ_38 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_38_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_38_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_38 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_38_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_38 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_38_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_39 \n
//! Valid values: ON, OFF.
#define IRQ_39_ENABLE                                                  (OFF)
//! Aliases for the IRQ_39 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_39_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_39_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_39 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_39_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_39 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_39_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_40 \n
//! Valid values: ON, OFF.
#define IRQ_40_ENABLE                                                  (OFF)
//! Aliases for the IRQ_40 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_40_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_40_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_40 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_40_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_40 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_40_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_41 \n
//! Valid values: ON, OFF.
#define IRQ_41_ENABLE                                                  (OFF)
//! Aliases for the IRQ_41 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_41_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_41_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_41 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_41_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_41 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_41_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_42 \n
//! Valid values: ON, OFF.
#define IRQ_42_ENABLE                                                  (OFF)
//! Aliases for the IRQ_42 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_42_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_42_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_42 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_42_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_42 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_42_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_43 \n
//! Valid values: ON, OFF.
#define IRQ_43_ENABLE                                                  (OFF)
//! Aliases for the IRQ_43 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_43_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_43_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_43 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_43_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_43 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_43_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_44 \n
//! Valid values: ON, OFF.
#define IRQ_44_ENABLE                                                  (OFF)
//! Aliases for the IRQ_44 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_44_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_44_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_44 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_44_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_44 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_44_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_45 \n
//! Valid values: ON, OFF.
#define IRQ_45_ENABLE                                                  (OFF)
//! Aliases for the IRQ_45 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_45_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_45_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_45 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_45_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_45 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_45_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_46 \n
//! Valid values: ON, OFF.
#define IRQ_46_ENABLE                                                  (OFF)
//! Aliases for the IRQ_46 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_46_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_46_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_46 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_46_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_46 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_46_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_47 \n
//! Valid values: ON, OFF.
#define IRQ_47_ENABLE                                                  (OFF)
//! Aliases for the IRQ_47 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_47_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_47_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_47 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_47_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_47 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_47_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_48 \n
//! Valid values: ON, OFF.
#define IRQ_48_ENABLE                                                  (OFF)
//! Aliases for the IRQ_48 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_48_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_48_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_48 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_48_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_48 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_48_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_49 \n
//! Valid values: ON, OFF.
#define IRQ_49_ENABLE                                                  (OFF)
//! Aliases for the IRQ_49 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_49_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_49_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_49 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_49_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_49 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_49_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_50 \n
//! Valid values: ON, OFF.
#define IRQ_50_ENABLE                                                  (OFF)
//! Aliases for the IRQ_50 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_50_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_50_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_50 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_50_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_50 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_50_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_51 \n
//! Valid values: ON, OFF.
#define IRQ_51_ENABLE                                                  (OFF)
//! Aliases for the IRQ_51 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_51_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_51_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_51 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_51_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_51 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_51_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_52 \n
//! Valid values: ON, OFF.
#define IRQ_52_ENABLE                                                  (OFF)
//! Aliases for the IRQ_52 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_52_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_52_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_52 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_52_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_52 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_52_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_53 \n
//! Valid values: ON, OFF.
#define IRQ_53_ENABLE                                                  (OFF)
//! Aliases for the IRQ_53 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_53_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_53_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_53 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_53_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_53 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_53_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_54 \n
//! Valid values: ON, OFF.
#define IRQ_54_ENABLE                                                  (OFF)
//! Aliases for the IRQ_54 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_54_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_54_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_54 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_54_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_54 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_54_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_55 \n
//! Valid values: ON, OFF.
#define IRQ_55_ENABLE                                                  (OFF)
//! Aliases for the IRQ_55 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_55_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_55_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_55 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_55_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_55 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_55_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_56 \n
//! Valid values: ON, OFF.
#define IRQ_56_ENABLE                                                  (OFF)
//! Aliases for the IRQ_56 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_56_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_56_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_56 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_56_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_56 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_56_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_57 \n
//! Valid values: ON, OFF.
#define IRQ_57_ENABLE                                                  (OFF)
//! Aliases for the IRQ_57 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_57_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_57_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_57 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_57_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_57 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_57_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_58 \n
//! Valid values: ON, OFF.
#define IRQ_58_ENABLE                                                  (OFF)
//! Aliases for the IRQ_58 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_58_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_58_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_58 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_58_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_58 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_58_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_59 \n
//! Valid values: ON, OFF.
#define IRQ_59_ENABLE                                                  (OFF)
//! Aliases for the IRQ_59 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_59_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_59_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_59 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_59_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_59 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_59_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_60 \n
//! Valid values: ON, OFF.
#define IRQ_60_ENABLE                                                  (OFF)
//! Aliases for the IRQ_60 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_60_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_60_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_60 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_60_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_60 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_60_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_61 \n
//! Valid values: ON, OFF.
#define IRQ_61_ENABLE                                                  (OFF)
//! Aliases for the IRQ_61 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_61_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_61_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_61 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_61_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_61 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_61_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_62 \n
//! Valid values: ON, OFF.
#define IRQ_62_ENABLE                                                  (OFF)
//! Aliases for the IRQ_62 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_62_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_62_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_62 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_62_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_62 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_62_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_63 \n
//! Valid values: ON, OFF.
#define IRQ_63_ENABLE                                                  (OFF)
//! Aliases for the IRQ_63 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_63_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_63_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_63 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_63_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_63 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_63_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_64 \n
//! Valid values: ON, OFF.
#define IRQ_64_ENABLE                                                  (OFF)
//! Aliases for the IRQ_64 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_64_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_64_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_64 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_64_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_64 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_64_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_65 \n
//! Valid values: ON, OFF.
#define IRQ_65_ENABLE                                                  (OFF)
//! Aliases for the IRQ_65 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_65_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_65_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_65 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_65_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_65 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_65_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_66 \n
//! Valid values: ON, OFF.
#define IRQ_66_ENABLE                                                  (OFF)
//! Aliases for the IRQ_66 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_66_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_66_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_66 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_66_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_66 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_66_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_67 \n
//! Valid values: ON, OFF.
#define IRQ_67_ENABLE                                                  (OFF)
//! Aliases for the IRQ_67 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_67_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_67_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_67 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_67_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_67 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_67_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_68 \n
//! Valid values: ON, OFF.
#define IRQ_68_ENABLE                                                  (OFF)
//! Aliases for the IRQ_68 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_68_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_68_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_68 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_68_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_68 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_68_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_69 \n
//! Valid values: ON, OFF.
#define IRQ_69_ENABLE                                                  (OFF)
//! Aliases for the IRQ_69 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_69_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_69_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_69 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_69_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_69 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_69_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_70 \n
//! Valid values: ON, OFF.
#define IRQ_70_ENABLE                                                  (OFF)
//! Aliases for the IRQ_70 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_70_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_70_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_70 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_70_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_70 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_70_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_71 \n
//! Valid values: ON, OFF.
#define IRQ_71_ENABLE                                                  (OFF)
//! Aliases for the IRQ_71 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_71_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_71_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_71 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_71_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_71 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_71_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_72 \n
//! Valid values: ON, OFF.
#define IRQ_72_ENABLE                                                  (OFF)
//! Aliases for the IRQ_72 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_72_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_72_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_72 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_72_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_72 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_72_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_73 \n
//! Valid values: ON, OFF.
#define IRQ_73_ENABLE                                                  (OFF)
//! Aliases for the IRQ_73 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_73_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_73_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_73 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_73_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_73 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_73_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_74 \n
//! Valid values: ON, OFF.
#define IRQ_74_ENABLE                                                  (OFF)
//! Aliases for the IRQ_74 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_74_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_74_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_74 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_74_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_74 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_74_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_75 \n
//! Valid values: ON, OFF.
#define IRQ_75_ENABLE                                                  (OFF)
//! Aliases for the IRQ_75 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_75_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_75_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_75 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_75_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_75 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_75_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_76 \n
//! Valid values: ON, OFF.
#define IRQ_76_ENABLE                                                  (OFF)
//! Aliases for the IRQ_76 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_76_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_76_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_76 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_76_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_76 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_76_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_77 \n
//! Valid values: ON, OFF.
#define IRQ_77_ENABLE                                                  (OFF)
//! Aliases for the IRQ_77 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_77_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_77_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_77 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_77_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_77 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_77_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_78 \n
//! Valid values: ON, OFF.
#define IRQ_78_ENABLE                                                  (OFF)
//! Aliases for the IRQ_78 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_78_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_78_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_78 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_78_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_78 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_78_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_79 \n
//! Valid values: ON, OFF.
#define IRQ_79_ENABLE                                                  (OFF)
//! Aliases for the IRQ_79 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_79_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_79_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_79 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_79_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_79 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_79_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_80 \n
//! Valid values: ON, OFF.
#define IRQ_80_ENABLE                                                  (OFF)
//! Aliases for the IRQ_80 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_80_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_80_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_80 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_80_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_80 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_80_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_81 \n
//! Valid values: ON, OFF.
#define IRQ_81_ENABLE                                                  (OFF)
//! Aliases for the IRQ_81 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_81_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_81_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_81 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_81_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_81 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_81_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_82 \n
//! Valid values: ON, OFF.
#define IRQ_82_ENABLE                                                  (OFF)
//! Aliases for the IRQ_82 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_82_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_82_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_82 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_82_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_82 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_82_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_83 \n
//! Valid values: ON, OFF.
#define IRQ_83_ENABLE                                                  (OFF)
//! Aliases for the IRQ_83 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_83_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_83_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_83 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_83_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_83 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_83_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_84 \n
//! Valid values: ON, OFF.
#define IRQ_84_ENABLE                                                  (OFF)
//! Aliases for the IRQ_84 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_84_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_84_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_84 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_84_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_84 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_84_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_85 \n
//! Valid values: ON, OFF.
#define IRQ_85_ENABLE                                                  (OFF)
//! Aliases for the IRQ_85 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_85_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_85_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_85 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_85_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_85 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_85_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_86 \n
//! Valid values: ON, OFF.
#define IRQ_86_ENABLE                                                  (OFF)
//! Aliases for the IRQ_86 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_86_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_86_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_86 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_86_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_86 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_86_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_87 \n
//! Valid values: ON, OFF.
#define IRQ_87_ENABLE                                                  (OFF)
//! Aliases for the IRQ_87 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_87_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_87_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_87 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_87_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_87 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_87_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_88 \n
//! Valid values: ON, OFF.
#define IRQ_88_ENABLE                                                  (OFF)
//! Aliases for the IRQ_88 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_88_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_88_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_88 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_88_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_88 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_88_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_89 \n
//! Valid values: ON, OFF.
#define IRQ_89_ENABLE                                                  (OFF)
//! Aliases for the IRQ_89 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_89_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_89_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_89 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_89_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_89 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_89_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_90 \n
//! Valid values: ON, OFF.
#define IRQ_90_ENABLE                                                  (OFF)
//! Aliases for the IRQ_90 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_90_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_90_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_90 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_90_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_90 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_90_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_91 \n
//! Valid values: ON, OFF.
#define IRQ_91_ENABLE                                                  (OFF)
//! Aliases for the IRQ_91 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_91_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_91_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_91 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_91_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_91 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_91_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_92 \n
//! Valid values: ON, OFF.
#define IRQ_92_ENABLE                                                  (OFF)
//! Aliases for the IRQ_92 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_92_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_92_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_92 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_92_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_92 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_92_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_93 \n
//! Valid values: ON, OFF.
#define IRQ_93_ENABLE                                                  (OFF)
//! Aliases for the IRQ_93 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_93_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_93_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_93 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_93_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_93 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_93_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_94 \n
//! Valid values: ON, OFF.
#define IRQ_94_ENABLE                                                  (OFF)
//! Aliases for the IRQ_94 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_94_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_94_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_94 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_94_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_94 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_94_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_95 \n
//! Valid values: ON, OFF.
#define IRQ_95_ENABLE                                                  (OFF)
//! Aliases for the IRQ_95 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_95_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_95_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_95 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_95_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_95 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_95_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_96 \n
//! Valid values: ON, OFF.
#define IRQ_96_ENABLE                                                  (OFF)
//! Aliases for the IRQ_96 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_96_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_96_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_96 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_96_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_96 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_96_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_97 \n
//! Valid values: ON, OFF.
#define IRQ_97_ENABLE                                                  (OFF)
//! Aliases for the IRQ_97 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_97_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_97_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_97 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_97_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_97 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_97_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_98 \n
//! Valid values: ON, OFF.
#define IRQ_98_ENABLE                                                  (OFF)
//! Aliases for the IRQ_98 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_98_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_98_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_98 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_98_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_98 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_98_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_99 \n
//! Valid values: ON, OFF.
#define IRQ_99_ENABLE                                                  (OFF)
//! Aliases for the IRQ_99 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_99_ALIAS_FUN1                                              IRQ_DEFAULT_HANDLER
#define IRQ_99_ALIAS_FUN2                                              IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_99 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_99_GROUP_PRIORITY_LEVEL                                    (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_99 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_99_SUB_PRIORITY_LEVEL                                      (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_100 \n
//! Valid values: ON, OFF.
#define IRQ_100_ENABLE                                                 (OFF)
//! Aliases for the IRQ_100 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_100_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_100_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_100 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_100_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_100 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_100_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_101 \n
//! Valid values: ON, OFF.
#define IRQ_101_ENABLE                                                 (OFF)
//! Aliases for the IRQ_101 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_101_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_101_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_101 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_101_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_101 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_101_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_102 \n
//! Valid values: ON, OFF.
#define IRQ_102_ENABLE                                                 (OFF)
//! Aliases for the IRQ_102 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_102_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_102_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_102 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_102_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_102 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_102_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_103 \n
//! Valid values: ON, OFF.
#define IRQ_103_ENABLE                                                 (OFF)
//! Aliases for the IRQ_103 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_103_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_103_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_103 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_103_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_103 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_103_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_104 \n
//! Valid values: ON, OFF.
#define IRQ_104_ENABLE                                                 (OFF)
//! Aliases for the IRQ_104 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_104_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_104_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_104 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_104_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_104 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_104_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_105 \n
//! Valid values: ON, OFF.
#define IRQ_105_ENABLE                                                 (OFF)
//! Aliases for the IRQ_105 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_105_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_105_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_105 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_105_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_105 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_105_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_106 \n
//! Valid values: ON, OFF.
#define IRQ_106_ENABLE                                                 (OFF)
//! Aliases for the IRQ_106 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_106_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_106_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_106 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_106_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_106 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_106_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_107 \n
//! Valid values: ON, OFF.
#define IRQ_107_ENABLE                                                 (OFF)
//! Aliases for the IRQ_107 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_107_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_107_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_107 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_107_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_107 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_107_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_108 \n
//! Valid values: ON, OFF.
#define IRQ_108_ENABLE                                                 (OFF)
//! Aliases for the IRQ_108 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_108_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_108_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_108 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_108_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_108 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_108_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_109 \n
//! Valid values: ON, OFF.
#define IRQ_109_ENABLE                                                 (OFF)
//! Aliases for the IRQ_109 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_109_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_109_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_109 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_109_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_109 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_109_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_110 \n
//! Valid values: ON, OFF.
#define IRQ_110_ENABLE                                                 (OFF)
//! Aliases for the IRQ_110 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_110_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_110_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_110 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_110_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_110 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_110_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_111 \n
//! Valid values: ON, OFF.
#define IRQ_111_ENABLE                                                 (OFF)
//! Aliases for the IRQ_111 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_111_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_111_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_111 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_111_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_111 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_111_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_112 \n
//! Valid values: ON, OFF.
#define IRQ_112_ENABLE                                                 (OFF)
//! Aliases for the IRQ_112 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_112_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_112_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_112 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_112_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_112 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_112_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_113 \n
//! Valid values: ON, OFF.
#define IRQ_113_ENABLE                                                 (OFF)
//! Aliases for the IRQ_113 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_113_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_113_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_113 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_113_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_113 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_113_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_114 \n
//! Valid values: ON, OFF.
#define IRQ_114_ENABLE                                                 (OFF)
//! Aliases for the IRQ_114 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_114_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_114_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_114 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_114_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_114 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_114_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_115 \n
//! Valid values: ON, OFF.
#define IRQ_115_ENABLE                                                 (OFF)
//! Aliases for the IRQ_115 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_115_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_115_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_115 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_115_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_115 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_115_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_116 \n
//! Valid values: ON, OFF.
#define IRQ_116_ENABLE                                                 (OFF)
//! Aliases for the IRQ_116 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_116_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_116_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_116 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_116_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_116 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_116_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_117 \n
//! Valid values: ON, OFF.
#define IRQ_117_ENABLE                                                 (OFF)
//! Aliases for the IRQ_117 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_117_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_117_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_117 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_117_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_117 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_117_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_118 \n
//! Valid values: ON, OFF.
#define IRQ_118_ENABLE                                                 (OFF)
//! Aliases for the IRQ_118 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_118_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_118_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_118 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_118_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_118 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_118_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_119 \n
//! Valid values: ON, OFF.
#define IRQ_119_ENABLE                                                 (OFF)
//! Aliases for the IRQ_119 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_119_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_119_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_119 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_119_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_119 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_119_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_120 \n
//! Valid values: ON, OFF.
#define IRQ_120_ENABLE                                                 (OFF)
//! Aliases for the IRQ_120 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_120_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_120_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_120 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_120_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_120 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_120_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_121 \n
//! Valid values: ON, OFF.
#define IRQ_121_ENABLE                                                 (OFF)
//! Aliases for the IRQ_121 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_121_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_121_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_121 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_121_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_121 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_121_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_122 \n
//! Valid values: ON, OFF.
#define IRQ_122_ENABLE                                                 (OFF)
//! Aliases for the IRQ_122 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_122_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_122_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_122 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_122_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_122 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_122_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_123 \n
//! Valid values: ON, OFF.
#define IRQ_123_ENABLE                                                 (OFF)
//! Aliases for the IRQ_123 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_123_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_123_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_123 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_123_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_123 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_123_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_124 \n
//! Valid values: ON, OFF.
#define IRQ_124_ENABLE                                                 (OFF)
//! Aliases for the IRQ_124 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_124_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_124_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_124 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_124_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_124 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_124_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_125 \n
//! Valid values: ON, OFF.
#define IRQ_125_ENABLE                                                 (OFF)
//! Aliases for the IRQ_125 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_125_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_125_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_125 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_125_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_125 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_125_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_126 \n
//! Valid values: ON, OFF.
#define IRQ_126_ENABLE                                                 (OFF)
//! Aliases for the IRQ_126 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_126_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_126_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_126 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_126_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_126 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_126_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_127 \n
//! Valid values: ON, OFF.
#define IRQ_127_ENABLE                                                 (OFF)
//! Aliases for the IRQ_127 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_127_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_127_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_127 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_127_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_127 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_127_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_128 \n
//! Valid values: ON, OFF.
#define IRQ_128_ENABLE                                                 (OFF)
//! Aliases for the IRQ_128 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_128_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_128_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_128 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_128_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_128 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_128_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_129 \n
//! Valid values: ON, OFF.
#define IRQ_129_ENABLE                                                 (OFF)
//! Aliases for the IRQ_129 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_129_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_129_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_129 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_129_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_129 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_129_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_130 \n
//! Valid values: ON, OFF.
#define IRQ_130_ENABLE                                                 (OFF)
//! Aliases for the IRQ_130 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_130_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_130_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_130 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_130_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_130 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_130_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_131 \n
//! Valid values: ON, OFF.
#define IRQ_131_ENABLE                                                 (OFF)
//! Aliases for the IRQ_131 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_131_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_131_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_131 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_131_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_131 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_131_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_132 \n
//! Valid values: ON, OFF.
#define IRQ_132_ENABLE                                                 (OFF)
//! Aliases for the IRQ_132 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_132_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_132_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_132 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_132_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_132 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_132_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_133 \n
//! Valid values: ON, OFF.
#define IRQ_133_ENABLE                                                 (OFF)
//! Aliases for the IRQ_133 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_133_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_133_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_133 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_133_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_133 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_133_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_134 \n
//! Valid values: ON, OFF.
#define IRQ_134_ENABLE                                                 (OFF)
//! Aliases for the IRQ_134 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_134_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_134_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_134 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_134_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_134 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_134_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_135 \n
//! Valid values: ON, OFF.
#define IRQ_135_ENABLE                                                 (OFF)
//! Aliases for the IRQ_135 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_135_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_135_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_135 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_135_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_135 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_135_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_136 \n
//! Valid values: ON, OFF.
#define IRQ_136_ENABLE                                                 (OFF)
//! Aliases for the IRQ_136 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_136_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_136_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_136 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_136_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_136 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_136_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_137 \n
//! Valid values: ON, OFF.
#define IRQ_137_ENABLE                                                 (OFF)
//! Aliases for the IRQ_137 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_137_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_137_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_137 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_137_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_137 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_137_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_138 \n
//! Valid values: ON, OFF.
#define IRQ_138_ENABLE                                                 (OFF)
//! Aliases for the IRQ_138 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_138_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_138_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_138 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_138_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_138 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_138_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_139 \n
//! Valid values: ON, OFF.
#define IRQ_139_ENABLE                                                 (OFF)
//! Aliases for the IRQ_139 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_139_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_139_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_139 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_139_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_139 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_139_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_140 \n
//! Valid values: ON, OFF.
#define IRQ_140_ENABLE                                                 (OFF)
//! Aliases for the IRQ_140 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_140_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_140_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_140 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_140_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_140 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_140_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_141 \n
//! Valid values: ON, OFF.
#define IRQ_141_ENABLE                                                 (OFF)
//! Aliases for the IRQ_141 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_141_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_141_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_141 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_141_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_141 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_141_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_142 \n
//! Valid values: ON, OFF.
#define IRQ_142_ENABLE                                                 (OFF)
//! Aliases for the IRQ_142 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_142_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_142_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_142 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_142_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_142 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_142_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_143 \n
//! Valid values: ON, OFF.
#define IRQ_143_ENABLE                                                 (OFF)
//! Aliases for the IRQ_143 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_143_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_143_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_143 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_143_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_143 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_143_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_144 \n
//! Valid values: ON, OFF.
#define IRQ_144_ENABLE                                                 (OFF)
//! Aliases for the IRQ_144 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_144_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_144_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_144 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_144_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_144 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_144_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_145 \n
//! Valid values: ON, OFF.
#define IRQ_145_ENABLE                                                 (OFF)
//! Aliases for the IRQ_145 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_145_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_145_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_145 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_145_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_145 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_145_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_146 \n
//! Valid values: ON, OFF.
#define IRQ_146_ENABLE                                                 (OFF)
//! Aliases for the IRQ_146 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_146_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_146_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_146 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_146_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_146 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_146_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_147 \n
//! Valid values: ON, OFF.
#define IRQ_147_ENABLE                                                 (OFF)
//! Aliases for the IRQ_147 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_147_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_147_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_147 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_147_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_147 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_147_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_148 \n
//! Valid values: ON, OFF.
#define IRQ_148_ENABLE                                                 (OFF)
//! Aliases for the IRQ_148 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_148_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_148_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_148 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_148_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_148 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_148_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_149 \n
//! Valid values: ON, OFF.
#define IRQ_149_ENABLE                                                 (OFF)
//! Aliases for the IRQ_149 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_149_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_149_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_149 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_149_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_149 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_149_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_150 \n
//! Valid values: ON, OFF.
#define IRQ_150_ENABLE                                                 (OFF)
//! Aliases for the IRQ_150 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_150_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_150_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_150 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_150_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_150 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_150_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_151 \n
//! Valid values: ON, OFF.
#define IRQ_151_ENABLE                                                 (OFF)
//! Aliases for the IRQ_151 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_151_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_151_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_151 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_151_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_151 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_151_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_152 \n
//! Valid values: ON, OFF.
#define IRQ_152_ENABLE                                                 (OFF)
//! Aliases for the IRQ_152 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_152_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_152_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_152 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_152_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_152 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_152_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_153 \n
//! Valid values: ON, OFF.
#define IRQ_153_ENABLE                                                 (OFF)
//! Aliases for the IRQ_153 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_153_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_153_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_153 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_153_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_153 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_153_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_154 \n
//! Valid values: ON, OFF.
#define IRQ_154_ENABLE                                                 (OFF)
//! Aliases for the IRQ_154 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_154_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_154_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_154 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_154_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_154 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_154_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_155 \n
//! Valid values: ON, OFF.
#define IRQ_155_ENABLE                                                 (OFF)
//! Aliases for the IRQ_155 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_155_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_155_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_155 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_155_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_155 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_155_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_156 \n
//! Valid values: ON, OFF.
#define IRQ_156_ENABLE                                                 (OFF)
//! Aliases for the IRQ_156 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_156_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_156_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_156 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_156_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_156 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_156_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_157 \n
//! Valid values: ON, OFF.
#define IRQ_157_ENABLE                                                 (OFF)
//! Aliases for the IRQ_157 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_157_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_157_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_157 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_157_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_157 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_157_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_158 \n
//! Valid values: ON, OFF.
#define IRQ_158_ENABLE                                                 (OFF)
//! Aliases for the IRQ_158 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_158_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_158_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_158 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_158_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_158 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_158_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_159 \n
//! Valid values: ON, OFF.
#define IRQ_159_ENABLE                                                 (OFF)
//! Aliases for the IRQ_159 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_159_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_159_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_159 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_159_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_159 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_159_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_160 \n
//! Valid values: ON, OFF.
#define IRQ_160_ENABLE                                                 (OFF)
//! Aliases for the IRQ_160 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_160_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_160_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_160 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_160_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_160 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_160_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_161 \n
//! Valid values: ON, OFF.
#define IRQ_161_ENABLE                                                 (OFF)
//! Aliases for the IRQ_161 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_161_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_161_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_161 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_161_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_161 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_161_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_162 \n
//! Valid values: ON, OFF.
#define IRQ_162_ENABLE                                                 (OFF)
//! Aliases for the IRQ_162 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_162_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_162_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_162 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_162_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_162 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_162_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_163 \n
//! Valid values: ON, OFF.
#define IRQ_163_ENABLE                                                 (OFF)
//! Aliases for the IRQ_163 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_163_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_163_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_163 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_163_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_163 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_163_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_164 \n
//! Valid values: ON, OFF.
#define IRQ_164_ENABLE                                                 (OFF)
//! Aliases for the IRQ_164 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_164_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_164_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_164 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_164_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_164 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_164_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_165 \n
//! Valid values: ON, OFF.
#define IRQ_165_ENABLE                                                 (OFF)
//! Aliases for the IRQ_165 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_165_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_165_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_165 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_165_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_165 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_165_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_166 \n
//! Valid values: ON, OFF.
#define IRQ_166_ENABLE                                                 (OFF)
//! Aliases for the IRQ_166 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_166_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_166_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_166 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_166_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_166 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_166_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_167 \n
//! Valid values: ON, OFF.
#define IRQ_167_ENABLE                                                 (OFF)
//! Aliases for the IRQ_167 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_167_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_167_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_167 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_167_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_167 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_167_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_168 \n
//! Valid values: ON, OFF.
#define IRQ_168_ENABLE                                                 (OFF)
//! Aliases for the IRQ_168 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_168_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_168_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_168 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_168_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_168 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_168_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_169 \n
//! Valid values: ON, OFF.
#define IRQ_169_ENABLE                                                 (OFF)
//! Aliases for the IRQ_169 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_169_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_169_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_169 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_169_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_169 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_169_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_170 \n
//! Valid values: ON, OFF.
#define IRQ_170_ENABLE                                                 (OFF)
//! Aliases for the IRQ_170 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_170_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_170_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_170 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_170_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_170 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_170_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_171 \n
//! Valid values: ON, OFF.
#define IRQ_171_ENABLE                                                 (OFF)
//! Aliases for the IRQ_171 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_171_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_171_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_171 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_171_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_171 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_171_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_172 \n
//! Valid values: ON, OFF.
#define IRQ_172_ENABLE                                                 (OFF)
//! Aliases for the IRQ_172 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_172_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_172_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_172 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_172_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_172 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_172_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_173 \n
//! Valid values: ON, OFF.
#define IRQ_173_ENABLE                                                 (OFF)
//! Aliases for the IRQ_173 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_173_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_173_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_173 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_173_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_173 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_173_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_174 \n
//! Valid values: ON, OFF.
#define IRQ_174_ENABLE                                                 (OFF)
//! Aliases for the IRQ_174 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_174_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_174_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_174 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_174_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_174 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_174_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_175 \n
//! Valid values: ON, OFF.
#define IRQ_175_ENABLE                                                 (OFF)
//! Aliases for the IRQ_175 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_175_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_175_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_175 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_175_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_175 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_175_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_176 \n
//! Valid values: ON, OFF.
#define IRQ_176_ENABLE                                                 (OFF)
//! Aliases for the IRQ_176 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_176_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_176_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_176 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_176_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_176 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_176_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_177 \n
//! Valid values: ON, OFF.
#define IRQ_177_ENABLE                                                 (OFF)
//! Aliases for the IRQ_177 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_177_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_177_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_177 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_177_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_177 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_177_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_178 \n
//! Valid values: ON, OFF.
#define IRQ_178_ENABLE                                                 (OFF)
//! Aliases for the IRQ_178 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_178_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_178_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_178 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_178_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_178 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_178_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_179 \n
//! Valid values: ON, OFF.
#define IRQ_179_ENABLE                                                 (OFF)
//! Aliases for the IRQ_179 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_179_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_179_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_179 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_179_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_179 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_179_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_180 \n
//! Valid values: ON, OFF.
#define IRQ_180_ENABLE                                                 (OFF)
//! Aliases for the IRQ_180 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_180_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_180_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_180 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_180_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_180 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_180_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_181 \n
//! Valid values: ON, OFF.
#define IRQ_181_ENABLE                                                 (OFF)
//! Aliases for the IRQ_181 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_181_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_181_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_181 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_181_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_181 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_181_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_182 \n
//! Valid values: ON, OFF.
#define IRQ_182_ENABLE                                                 (OFF)
//! Aliases for the IRQ_182 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_182_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_182_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_182 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_182_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_182 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_182_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_183 \n
//! Valid values: ON, OFF.
#define IRQ_183_ENABLE                                                 (OFF)
//! Aliases for the IRQ_183 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_183_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_183_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_183 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_183_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_183 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_183_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_184 \n
//! Valid values: ON, OFF.
#define IRQ_184_ENABLE                                                 (OFF)
//! Aliases for the IRQ_184 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_184_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_184_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_184 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_184_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_184 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_184_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_185 \n
//! Valid values: ON, OFF.
#define IRQ_185_ENABLE                                                 (OFF)
//! Aliases for the IRQ_185 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_185_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_185_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_185 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_185_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_185 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_185_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_186 \n
//! Valid values: ON, OFF.
#define IRQ_186_ENABLE                                                 (OFF)
//! Aliases for the IRQ_186 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_186_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_186_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_186 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_186_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_186 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_186_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_187 \n
//! Valid values: ON, OFF.
#define IRQ_187_ENABLE                                                 (OFF)
//! Aliases for the IRQ_187 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_187_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_187_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_187 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_187_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_187 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_187_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_188 \n
//! Valid values: ON, OFF.
#define IRQ_188_ENABLE                                                 (OFF)
//! Aliases for the IRQ_188 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_188_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_188_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_188 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_188_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_188 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_188_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_189 \n
//! Valid values: ON, OFF.
#define IRQ_189_ENABLE                                                 (OFF)
//! Aliases for the IRQ_189 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_189_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_189_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_189 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_189_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_189 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_189_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_190 \n
//! Valid values: ON, OFF.
#define IRQ_190_ENABLE                                                 (OFF)
//! Aliases for the IRQ_190 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_190_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_190_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_190 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_190_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_190 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_190_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_191 \n
//! Valid values: ON, OFF.
#define IRQ_191_ENABLE                                                 (OFF)
//! Aliases for the IRQ_191 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_191_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_191_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_191 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_191_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_191 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_191_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_192 \n
//! Valid values: ON, OFF.
#define IRQ_192_ENABLE                                                 (OFF)
//! Aliases for the IRQ_192 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_192_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_192_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_192 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_192_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_192 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_192_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_193 \n
//! Valid values: ON, OFF.
#define IRQ_193_ENABLE                                                 (OFF)
//! Aliases for the IRQ_193 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_193_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_193_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_193 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_193_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_193 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_193_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_194 \n
//! Valid values: ON, OFF.
#define IRQ_194_ENABLE                                                 (OFF)
//! Aliases for the IRQ_194 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_194_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_194_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_194 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_194_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_194 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_194_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_195 \n
//! Valid values: ON, OFF.
#define IRQ_195_ENABLE                                                 (OFF)
//! Aliases for the IRQ_195 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_195_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_195_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_195 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_195_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_195 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_195_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_196 \n
//! Valid values: ON, OFF.
#define IRQ_196_ENABLE                                                 (OFF)
//! Aliases for the IRQ_196 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_196_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_196_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_196 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_196_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_196 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_196_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_197 \n
//! Valid values: ON, OFF.
#define IRQ_197_ENABLE                                                 (OFF)
//! Aliases for the IRQ_197 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_197_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_197_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_197 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_197_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_197 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_197_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_198 \n
//! Valid values: ON, OFF.
#define IRQ_198_ENABLE                                                 (OFF)
//! Aliases for the IRQ_198 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_198_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_198_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_198 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_198_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_198 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_198_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_199 \n
//! Valid values: ON, OFF.
#define IRQ_199_ENABLE                                                 (OFF)
//! Aliases for the IRQ_199 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_199_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_199_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_199 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_199_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_199 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_199_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_200 \n
//! Valid values: ON, OFF.
#define IRQ_200_ENABLE                                                 (OFF)
//! Aliases for the IRQ_200 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_200_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_200_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_200 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_200_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_200 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_200_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_201 \n
//! Valid values: ON, OFF.
#define IRQ_201_ENABLE                                                 (OFF)
//! Aliases for the IRQ_201 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_201_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_201_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_201 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_201_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_201 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_201_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_202 \n
//! Valid values: ON, OFF.
#define IRQ_202_ENABLE                                                 (OFF)
//! Aliases for the IRQ_202 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_202_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_202_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_202 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_202_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_202 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_202_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_203 \n
//! Valid values: ON, OFF.
#define IRQ_203_ENABLE                                                 (OFF)
//! Aliases for the IRQ_203 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_203_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_203_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_203 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_203_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_203 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_203_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_204 \n
//! Valid values: ON, OFF.
#define IRQ_204_ENABLE                                                 (OFF)
//! Aliases for the IRQ_204 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_204_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_204_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_204 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_204_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_204 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_204_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_205 \n
//! Valid values: ON, OFF.
#define IRQ_205_ENABLE                                                 (OFF)
//! Aliases for the IRQ_205 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_205_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_205_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_205 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_205_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_205 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_205_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_206 \n
//! Valid values: ON, OFF.
#define IRQ_206_ENABLE                                                 (OFF)
//! Aliases for the IRQ_206 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_206_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_206_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_206 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_206_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_206 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_206_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_207 \n
//! Valid values: ON, OFF.
#define IRQ_207_ENABLE                                                 (OFF)
//! Aliases for the IRQ_207 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_207_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_207_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_207 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_207_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_207 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_207_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_208 \n
//! Valid values: ON, OFF.
#define IRQ_208_ENABLE                                                 (OFF)
//! Aliases for the IRQ_208 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_208_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_208_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_208 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_208_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_208 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_208_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_209 \n
//! Valid values: ON, OFF.
#define IRQ_209_ENABLE                                                 (OFF)
//! Aliases for the IRQ_209 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_209_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_209_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_209 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_209_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_209 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_209_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_210 \n
//! Valid values: ON, OFF.
#define IRQ_210_ENABLE                                                 (OFF)
//! Aliases for the IRQ_210 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_210_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_210_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_210 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_210_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_210 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_210_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_211 \n
//! Valid values: ON, OFF.
#define IRQ_211_ENABLE                                                 (OFF)
//! Aliases for the IRQ_211 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_211_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_211_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_211 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_211_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_211 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_211_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_212 \n
//! Valid values: ON, OFF.
#define IRQ_212_ENABLE                                                 (OFF)
//! Aliases for the IRQ_212 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_212_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_212_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_212 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_212_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_212 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_212_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_213 \n
//! Valid values: ON, OFF.
#define IRQ_213_ENABLE                                                 (OFF)
//! Aliases for the IRQ_213 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_213_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_213_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_213 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_213_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_213 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_213_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_214 \n
//! Valid values: ON, OFF.
#define IRQ_214_ENABLE                                                 (OFF)
//! Aliases for the IRQ_214 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_214_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_214_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_214 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_214_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_214 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_214_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_215 \n
//! Valid values: ON, OFF.
#define IRQ_215_ENABLE                                                 (OFF)
//! Aliases for the IRQ_215 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_215_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_215_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_215 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_215_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_215 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_215_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_216 \n
//! Valid values: ON, OFF.
#define IRQ_216_ENABLE                                                 (OFF)
//! Aliases for the IRQ_216 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_216_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_216_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_216 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_216_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_216 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_216_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_217 \n
//! Valid values: ON, OFF.
#define IRQ_217_ENABLE                                                 (OFF)
//! Aliases for the IRQ_217 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_217_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_217_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_217 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_217_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_217 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_217_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_218 \n
//! Valid values: ON, OFF.
#define IRQ_218_ENABLE                                                 (OFF)
//! Aliases for the IRQ_218 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_218_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_218_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_218 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_218_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_218 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_218_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_219 \n
//! Valid values: ON, OFF.
#define IRQ_219_ENABLE                                                 (OFF)
//! Aliases for the IRQ_219 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_219_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_219_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_219 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_219_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_219 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_219_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_220 \n
//! Valid values: ON, OFF.
#define IRQ_220_ENABLE                                                 (OFF)
//! Aliases for the IRQ_220 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_220_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_220_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_220 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_220_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_220 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_220_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_221 \n
//! Valid values: ON, OFF.
#define IRQ_221_ENABLE                                                 (OFF)
//! Aliases for the IRQ_221 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_221_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_221_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_221 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_221_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_221 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_221_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_222 \n
//! Valid values: ON, OFF.
#define IRQ_222_ENABLE                                                 (OFF)
//! Aliases for the IRQ_222 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_222_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_222_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_222 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_222_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_222 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_222_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_223 \n
//! Valid values: ON, OFF.
#define IRQ_223_ENABLE                                                 (OFF)
//! Aliases for the IRQ_223 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_223_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_223_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_223 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_223_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_223 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_223_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_224 \n
//! Valid values: ON, OFF.
#define IRQ_224_ENABLE                                                 (OFF)
//! Aliases for the IRQ_224 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_224_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_224_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_224 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_224_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_224 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_224_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_225 \n
//! Valid values: ON, OFF.
#define IRQ_225_ENABLE                                                 (OFF)
//! Aliases for the IRQ_225 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_225_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_225_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_225 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_225_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_225 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_225_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_226 \n
//! Valid values: ON, OFF.
#define IRQ_226_ENABLE                                                 (OFF)
//! Aliases for the IRQ_226 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_226_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_226_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_226 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_226_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_226 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_226_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_227 \n
//! Valid values: ON, OFF.
#define IRQ_227_ENABLE                                                 (OFF)
//! Aliases for the IRQ_227 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_227_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_227_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_227 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_227_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_227 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_227_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_228 \n
//! Valid values: ON, OFF.
#define IRQ_228_ENABLE                                                 (OFF)
//! Aliases for the IRQ_228 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_228_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_228_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_228 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_228_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_228 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_228_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_229 \n
//! Valid values: ON, OFF.
#define IRQ_229_ENABLE                                                 (OFF)
//! Aliases for the IRQ_229 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_229_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_229_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_229 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_229_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_229 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_229_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_230 \n
//! Valid values: ON, OFF.
#define IRQ_230_ENABLE                                                 (OFF)
//! Aliases for the IRQ_230 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_230_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_230_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_230 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_230_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_230 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_230_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_231 \n
//! Valid values: ON, OFF.
#define IRQ_231_ENABLE                                                 (OFF)
//! Aliases for the IRQ_231 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_231_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_231_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_231 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_231_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_231 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_231_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_232 \n
//! Valid values: ON, OFF.
#define IRQ_232_ENABLE                                                 (OFF)
//! Aliases for the IRQ_232 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_232_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_232_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_232 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_232_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_232 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_232_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_233 \n
//! Valid values: ON, OFF.
#define IRQ_233_ENABLE                                                 (OFF)
//! Aliases for the IRQ_233 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_233_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_233_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_233 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_233_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_233 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_233_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_234 \n
//! Valid values: ON, OFF.
#define IRQ_234_ENABLE                                                 (OFF)
//! Aliases for the IRQ_234 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_234_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_234_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_234 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_234_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_234 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_234_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_235 \n
//! Valid values: ON, OFF.
#define IRQ_235_ENABLE                                                 (OFF)
//! Aliases for the IRQ_235 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_235_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_235_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_235 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_235_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_235 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_235_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_236 \n
//! Valid values: ON, OFF.
#define IRQ_236_ENABLE                                                 (OFF)
//! Aliases for the IRQ_236 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_236_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_236_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_236 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_236_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_236 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_236_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_237 \n
//! Valid values: ON, OFF.
#define IRQ_237_ENABLE                                                 (OFF)
//! Aliases for the IRQ_237 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_237_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_237_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_237 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_237_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_237 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_237_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_238 \n
//! Valid values: ON, OFF.
#define IRQ_238_ENABLE                                                 (OFF)
//! Aliases for the IRQ_238 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_238_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_238_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_238 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_238_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_238 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_238_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_239 \n
//! Valid values: ON, OFF.
#define IRQ_239_ENABLE                                                 (OFF)
//! Aliases for the IRQ_239 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_239_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_239_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_239 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_239_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_239 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_239_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_240 \n
//! Valid values: ON, OFF.
#define IRQ_240_ENABLE                                                 (OFF)
//! Aliases for the IRQ_240 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_240_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_240_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_240 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_240_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_240 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_240_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_241 \n
//! Valid values: ON, OFF.
#define IRQ_241_ENABLE                                                 (OFF)
//! Aliases for the IRQ_241 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_241_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_241_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_241 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_241_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_241 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_241_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_242 \n
//! Valid values: ON, OFF.
#define IRQ_242_ENABLE                                                 (OFF)
//! Aliases for the IRQ_242 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_242_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_242_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_242 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_242_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_242 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_242_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_243 \n
//! Valid values: ON, OFF.
#define IRQ_243_ENABLE                                                 (OFF)
//! Aliases for the IRQ_243 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_243_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_243_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_243 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_243_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_243 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_243_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_244 \n
//! Valid values: ON, OFF.
#define IRQ_244_ENABLE                                                 (OFF)
//! Aliases for the IRQ_244 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_244_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_244_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_244 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_244_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_244 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_244_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_245 \n
//! Valid values: ON, OFF.
#define IRQ_245_ENABLE                                                 (OFF)
//! Aliases for the IRQ_245 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_245_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_245_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_245 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_245_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_245 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_245_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_246 \n
//! Valid values: ON, OFF.
#define IRQ_246_ENABLE                                                 (OFF)
//! Aliases for the IRQ_246 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_246_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_246_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_246 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_246_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_246 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_246_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_247 \n
//! Valid values: ON, OFF.
#define IRQ_247_ENABLE                                                 (OFF)
//! Aliases for the IRQ_247 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_247_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_247_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_247 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_247_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_247 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_247_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_248 \n
//! Valid values: ON, OFF.
#define IRQ_248_ENABLE                                                 (OFF)
//! Aliases for the IRQ_248 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_248_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_248_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_248 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_248_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_248 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_248_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_249 \n
//! Valid values: ON, OFF.
#define IRQ_249_ENABLE                                                 (OFF)
//! Aliases for the IRQ_249 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_249_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_249_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_249 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_249_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_249 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_249_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_250 \n
//! Valid values: ON, OFF.
#define IRQ_250_ENABLE                                                 (OFF)
//! Aliases for the IRQ_250 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_250_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_250_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_250 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_250_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_250 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_250_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_251 \n
//! Valid values: ON, OFF.
#define IRQ_251_ENABLE                                                 (OFF)
//! Aliases for the IRQ_251 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_251_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_251_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_251 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_251_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_251 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_251_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_252 \n
//! Valid values: ON, OFF.
#define IRQ_252_ENABLE                                                 (OFF)
//! Aliases for the IRQ_252 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_252_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_252_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_252 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_252_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_252 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_252_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_253 \n
//! Valid values: ON, OFF.
#define IRQ_253_ENABLE                                                 (OFF)
//! Aliases for the IRQ_253 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_253_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_253_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_253 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_253_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_253 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_253_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_254 \n
//! Valid values: ON, OFF.
#define IRQ_254_ENABLE                                                 (OFF)
//! Aliases for the IRQ_254 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_254_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_254_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_254 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_254_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_254 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_254_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_255 \n
//! Valid values: ON, OFF.
#define IRQ_255_ENABLE                                                 (OFF)
//! Aliases for the IRQ_255 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_255_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_255_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_255 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_255_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_255 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_255_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_256 \n
//! Valid values: ON, OFF.
#define IRQ_256_ENABLE                                                 (OFF)
//! Aliases for the IRQ_256 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_256_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_256_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_256 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_256_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_256 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_256_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_257 \n
//! Valid values: ON, OFF.
#define IRQ_257_ENABLE                                                 (OFF)
//! Aliases for the IRQ_257 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_257_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_257_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_257 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_257_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_257 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_257_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_258 \n
//! Valid values: ON, OFF.
#define IRQ_258_ENABLE                                                 (OFF)
//! Aliases for the IRQ_258 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_258_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_258_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_258 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_258_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_258 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_258_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_259 \n
//! Valid values: ON, OFF.
#define IRQ_259_ENABLE                                                 (OFF)
//! Aliases for the IRQ_259 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_259_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_259_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_259 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_259_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_259 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_259_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_260 \n
//! Valid values: ON, OFF.
#define IRQ_260_ENABLE                                                 (OFF)
//! Aliases for the IRQ_260 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_260_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_260_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_260 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_260_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_260 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_260_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_261 \n
//! Valid values: ON, OFF.
#define IRQ_261_ENABLE                                                 (OFF)
//! Aliases for the IRQ_261 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_261_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_261_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_261 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_261_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_261 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_261_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_262 \n
//! Valid values: ON, OFF.
#define IRQ_262_ENABLE                                                 (OFF)
//! Aliases for the IRQ_262 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_262_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_262_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_262 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_262_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_262 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_262_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_263 \n
//! Valid values: ON, OFF.
#define IRQ_263_ENABLE                                                 (OFF)
//! Aliases for the IRQ_263 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_263_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_263_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_263 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_263_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_263 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_263_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_264 \n
//! Valid values: ON, OFF.
#define IRQ_264_ENABLE                                                 (OFF)
//! Aliases for the IRQ_264 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_264_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_264_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_264 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_264_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_264 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_264_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_265 \n
//! Valid values: ON, OFF.
#define IRQ_265_ENABLE                                                 (OFF)
//! Aliases for the IRQ_265 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_265_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_265_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_265 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_265_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_265 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_265_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_266 \n
//! Valid values: ON, OFF.
#define IRQ_266_ENABLE                                                 (OFF)
//! Aliases for the IRQ_266 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_266_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_266_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_266 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_266_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_266 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_266_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_267 \n
//! Valid values: ON, OFF.
#define IRQ_267_ENABLE                                                 (OFF)
//! Aliases for the IRQ_267 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_267_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_267_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_267 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_267_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_267 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_267_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_268 \n
//! Valid values: ON, OFF.
#define IRQ_268_ENABLE                                                 (OFF)
//! Aliases for the IRQ_268 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_268_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_268_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_268 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_268_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_268 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_268_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_269 \n
//! Valid values: ON, OFF.
#define IRQ_269_ENABLE                                                 (OFF)
//! Aliases for the IRQ_269 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_269_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_269_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_269 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_269_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_269 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_269_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_270 \n
//! Valid values: ON, OFF.
#define IRQ_270_ENABLE                                                 (OFF)
//! Aliases for the IRQ_270 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_270_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_270_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_270 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_270_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_270 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_270_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_271 \n
//! Valid values: ON, OFF.
#define IRQ_271_ENABLE                                                 (OFF)
//! Aliases for the IRQ_271 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_271_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_271_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_271 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_271_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_271 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_271_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_272 \n
//! Valid values: ON, OFF.
#define IRQ_272_ENABLE                                                 (OFF)
//! Aliases for the IRQ_272 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_272_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_272_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_272 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_272_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_272 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_272_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_273 \n
//! Valid values: ON, OFF.
#define IRQ_273_ENABLE                                                 (OFF)
//! Aliases for the IRQ_273 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_273_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_273_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_273 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_273_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_273 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_273_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_274 \n
//! Valid values: ON, OFF.
#define IRQ_274_ENABLE                                                 (OFF)
//! Aliases for the IRQ_274 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_274_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_274_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_274 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_274_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_274 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_274_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_275 \n
//! Valid values: ON, OFF.
#define IRQ_275_ENABLE                                                 (OFF)
//! Aliases for the IRQ_275 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_275_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_275_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_275 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_275_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_275 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_275_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_276 \n
//! Valid values: ON, OFF.
#define IRQ_276_ENABLE                                                 (OFF)
//! Aliases for the IRQ_276 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_276_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_276_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_276 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_276_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_276 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_276_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_277 \n
//! Valid values: ON, OFF.
#define IRQ_277_ENABLE                                                 (OFF)
//! Aliases for the IRQ_277 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_277_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_277_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_277 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_277_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_277 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_277_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_278 \n
//! Valid values: ON, OFF.
#define IRQ_278_ENABLE                                                 (OFF)
//! Aliases for the IRQ_278 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_278_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_278_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_278 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_278_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_278 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_278_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_279 \n
//! Valid values: ON, OFF.
#define IRQ_279_ENABLE                                                 (OFF)
//! Aliases for the IRQ_279 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_279_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_279_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_279 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_279_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_279 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_279_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_280 \n
//! Valid values: ON, OFF.
#define IRQ_280_ENABLE                                                 (OFF)
//! Aliases for the IRQ_280 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_280_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_280_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_280 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_280_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_280 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_280_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_281 \n
//! Valid values: ON, OFF.
#define IRQ_281_ENABLE                                                 (OFF)
//! Aliases for the IRQ_281 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_281_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_281_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_281 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_281_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_281 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_281_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_282 \n
//! Valid values: ON, OFF.
#define IRQ_282_ENABLE                                                 (OFF)
//! Aliases for the IRQ_282 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_282_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_282_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_282 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_282_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_282 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_282_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_283 \n
//! Valid values: ON, OFF.
#define IRQ_283_ENABLE                                                 (OFF)
//! Aliases for the IRQ_283 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_283_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_283_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_283 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_283_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_283 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_283_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_284 \n
//! Valid values: ON, OFF.
#define IRQ_284_ENABLE                                                 (OFF)
//! Aliases for the IRQ_284 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_284_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_284_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_284 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_284_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_284 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_284_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_285 \n
//! Valid values: ON, OFF.
#define IRQ_285_ENABLE                                                 (OFF)
//! Aliases for the IRQ_285 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_285_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_285_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_285 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_285_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_285 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_285_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_286 \n
//! Valid values: ON, OFF.
#define IRQ_286_ENABLE                                                 (OFF)
//! Aliases for the IRQ_286 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_286_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_286_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_286 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_286_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_286 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_286_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_287 \n
//! Valid values: ON, OFF.
#define IRQ_287_ENABLE                                                 (OFF)
//! Aliases for the IRQ_287 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_287_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_287_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_287 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_287_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_287 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_287_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_288 \n
//! Valid values: ON, OFF.
#define IRQ_288_ENABLE                                                 (OFF)
//! Aliases for the IRQ_288 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_288_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_288_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_288 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_288_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_288 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_288_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_289 \n
//! Valid values: ON, OFF.
#define IRQ_289_ENABLE                                                 (OFF)
//! Aliases for the IRQ_289 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_289_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_289_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_289 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_289_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_289 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_289_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_290 \n
//! Valid values: ON, OFF.
#define IRQ_290_ENABLE                                                 (OFF)
//! Aliases for the IRQ_290 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_290_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_290_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_290 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_290_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_290 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_290_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_291 \n
//! Valid values: ON, OFF.
#define IRQ_291_ENABLE                                                 (OFF)
//! Aliases for the IRQ_291 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_291_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_291_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_291 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_291_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_291 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_291_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_292 \n
//! Valid values: ON, OFF.
#define IRQ_292_ENABLE                                                 (OFF)
//! Aliases for the IRQ_292 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_292_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_292_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_292 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_292_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_292 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_292_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_293 \n
//! Valid values: ON, OFF.
#define IRQ_293_ENABLE                                                 (OFF)
//! Aliases for the IRQ_293 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_293_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_293_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_293 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_293_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_293 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_293_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_294 \n
//! Valid values: ON, OFF.
#define IRQ_294_ENABLE                                                 (OFF)
//! Aliases for the IRQ_294 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_294_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_294_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_294 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_294_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_294 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_294_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_295 \n
//! Valid values: ON, OFF.
#define IRQ_295_ENABLE                                                 (OFF)
//! Aliases for the IRQ_295 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_295_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_295_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_295 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_295_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_295 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_295_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_296 \n
//! Valid values: ON, OFF.
#define IRQ_296_ENABLE                                                 (OFF)
//! Aliases for the IRQ_296 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_296_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_296_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_296 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_296_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_296 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_296_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_297 \n
//! Valid values: ON, OFF.
#define IRQ_297_ENABLE                                                 (OFF)
//! Aliases for the IRQ_297 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_297_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_297_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_297 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_297_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_297 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_297_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_298 \n
//! Valid values: ON, OFF.
#define IRQ_298_ENABLE                                                 (OFF)
//! Aliases for the IRQ_298 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_298_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_298_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_298 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_298_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_298 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_298_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_299 \n
//! Valid values: ON, OFF.
#define IRQ_299_ENABLE                                                 (OFF)
//! Aliases for the IRQ_299 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_299_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_299_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_299 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_299_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_299 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_299_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_300 \n
//! Valid values: ON, OFF.
#define IRQ_300_ENABLE                                                 (OFF)
//! Aliases for the IRQ_300 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_300_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_300_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_300 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_300_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_300 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_300_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_301 \n
//! Valid values: ON, OFF.
#define IRQ_301_ENABLE                                                 (OFF)
//! Aliases for the IRQ_301 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_301_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_301_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_301 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_301_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_301 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_301_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_302 \n
//! Valid values: ON, OFF.
#define IRQ_302_ENABLE                                                 (OFF)
//! Aliases for the IRQ_302 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_302_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_302_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_302 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_302_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_302 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_302_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_303 \n
//! Valid values: ON, OFF.
#define IRQ_303_ENABLE                                                 (OFF)
//! Aliases for the IRQ_303 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_303_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_303_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_303 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_303_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_303 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_303_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_304 \n
//! Valid values: ON, OFF.
#define IRQ_304_ENABLE                                                 (OFF)
//! Aliases for the IRQ_304 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_304_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_304_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_304 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_304_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_304 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_304_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_305 \n
//! Valid values: ON, OFF.
#define IRQ_305_ENABLE                                                 (OFF)
//! Aliases for the IRQ_305 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_305_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_305_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_305 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_305_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_305 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_305_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_306 \n
//! Valid values: ON, OFF.
#define IRQ_306_ENABLE                                                 (OFF)
//! Aliases for the IRQ_306 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_306_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_306_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_306 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_306_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_306 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_306_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_307 \n
//! Valid values: ON, OFF.
#define IRQ_307_ENABLE                                                 (OFF)
//! Aliases for the IRQ_307 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_307_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_307_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_307 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_307_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_307 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_307_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_308 \n
//! Valid values: ON, OFF.
#define IRQ_308_ENABLE                                                 (OFF)
//! Aliases for the IRQ_308 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_308_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_308_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_308 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_308_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_308 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_308_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_309 \n
//! Valid values: ON, OFF.
#define IRQ_309_ENABLE                                                 (OFF)
//! Aliases for the IRQ_309 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_309_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_309_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_309 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_309_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_309 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_309_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_310 \n
//! Valid values: ON, OFF.
#define IRQ_310_ENABLE                                                 (OFF)
//! Aliases for the IRQ_310 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_310_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_310_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_310 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_310_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_310 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_310_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_311 \n
//! Valid values: ON, OFF.
#define IRQ_311_ENABLE                                                 (OFF)
//! Aliases for the IRQ_311 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_311_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_311_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_311 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_311_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_311 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_311_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_312 \n
//! Valid values: ON, OFF.
#define IRQ_312_ENABLE                                                 (OFF)
//! Aliases for the IRQ_312 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_312_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_312_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_312 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_312_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_312 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_312_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_313 \n
//! Valid values: ON, OFF.
#define IRQ_313_ENABLE                                                 (OFF)
//! Aliases for the IRQ_313 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_313_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_313_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_313 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_313_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_313 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_313_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_314 \n
//! Valid values: ON, OFF.
#define IRQ_314_ENABLE                                                 (OFF)
//! Aliases for the IRQ_314 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_314_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_314_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_314 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_314_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_314 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_314_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_315 \n
//! Valid values: ON, OFF.
#define IRQ_315_ENABLE                                                 (OFF)
//! Aliases for the IRQ_315 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_315_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_315_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_315 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_315_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_315 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_315_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_316 \n
//! Valid values: ON, OFF.
#define IRQ_316_ENABLE                                                 (OFF)
//! Aliases for the IRQ_316 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_316_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_316_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_316 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_316_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_316 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_316_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_317 \n
//! Valid values: ON, OFF.
#define IRQ_317_ENABLE                                                 (OFF)
//! Aliases for the IRQ_317 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_317_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_317_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_317 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_317_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_317 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_317_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_318 \n
//! Valid values: ON, OFF.
#define IRQ_318_ENABLE                                                 (OFF)
//! Aliases for the IRQ_318 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_318_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_318_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_318 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_318_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_318 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_318_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_319 \n
//! Valid values: ON, OFF.
#define IRQ_319_ENABLE                                                 (OFF)
//! Aliases for the IRQ_319 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_319_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_319_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_319 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_319_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_319 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_319_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_320 \n
//! Valid values: ON, OFF.
#define IRQ_320_ENABLE                                                 (OFF)
//! Aliases for the IRQ_320 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_320_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_320_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_320 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_320_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_320 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_320_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_321 \n
//! Valid values: ON, OFF.
#define IRQ_321_ENABLE                                                 (OFF)
//! Aliases for the IRQ_321 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_321_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_321_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_321 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_321_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_321 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_321_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_322 \n
//! Valid values: ON, OFF.
#define IRQ_322_ENABLE                                                 (OFF)
//! Aliases for the IRQ_322 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_322_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_322_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_322 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_322_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_322 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_322_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_323 \n
//! Valid values: ON, OFF.
#define IRQ_323_ENABLE                                                 (OFF)
//! Aliases for the IRQ_323 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_323_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_323_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_323 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_323_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_323 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_323_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_324 \n
//! Valid values: ON, OFF.
#define IRQ_324_ENABLE                                                 (OFF)
//! Aliases for the IRQ_324 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_324_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_324_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_324 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_324_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_324 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_324_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_325 \n
//! Valid values: ON, OFF.
#define IRQ_325_ENABLE                                                 (OFF)
//! Aliases for the IRQ_325 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_325_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_325_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_325 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_325_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_325 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_325_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_326 \n
//! Valid values: ON, OFF.
#define IRQ_326_ENABLE                                                 (OFF)
//! Aliases for the IRQ_326 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_326_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_326_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_326 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_326_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_326 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_326_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_327 \n
//! Valid values: ON, OFF.
#define IRQ_327_ENABLE                                                 (OFF)
//! Aliases for the IRQ_327 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_327_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_327_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_327 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_327_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_327 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_327_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_328 \n
//! Valid values: ON, OFF.
#define IRQ_328_ENABLE                                                 (OFF)
//! Aliases for the IRQ_328 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_328_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_328_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_328 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_328_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_328 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_328_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_329 \n
//! Valid values: ON, OFF.
#define IRQ_329_ENABLE                                                 (OFF)
//! Aliases for the IRQ_329 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_329_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_329_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_329 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_329_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_329 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_329_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_330 \n
//! Valid values: ON, OFF.
#define IRQ_330_ENABLE                                                 (OFF)
//! Aliases for the IRQ_330 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_330_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_330_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_330 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_330_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_330 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_330_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_331 \n
//! Valid values: ON, OFF.
#define IRQ_331_ENABLE                                                 (OFF)
//! Aliases for the IRQ_331 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_331_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_331_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_331 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_331_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_331 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_331_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_332 \n
//! Valid values: ON, OFF.
#define IRQ_332_ENABLE                                                 (OFF)
//! Aliases for the IRQ_332 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_332_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_332_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_332 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_332_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_332 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_332_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_333 \n
//! Valid values: ON, OFF.
#define IRQ_333_ENABLE                                                 (OFF)
//! Aliases for the IRQ_333 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_333_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_333_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_333 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_333_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_333 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_333_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_334 \n
//! Valid values: ON, OFF.
#define IRQ_334_ENABLE                                                 (OFF)
//! Aliases for the IRQ_334 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_334_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_334_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_334 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_334_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_334 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_334_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_335 \n
//! Valid values: ON, OFF.
#define IRQ_335_ENABLE                                                 (OFF)
//! Aliases for the IRQ_335 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_335_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_335_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_335 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_335_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_335 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_335_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_336 \n
//! Valid values: ON, OFF.
#define IRQ_336_ENABLE                                                 (OFF)
//! Aliases for the IRQ_336 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_336_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_336_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_336 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_336_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_336 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_336_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_337 \n
//! Valid values: ON, OFF.
#define IRQ_337_ENABLE                                                 (OFF)
//! Aliases for the IRQ_337 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_337_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_337_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_337 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_337_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_337 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_337_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_338 \n
//! Valid values: ON, OFF.
#define IRQ_338_ENABLE                                                 (OFF)
//! Aliases for the IRQ_338 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_338_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_338_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_338 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_338_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_338 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_338_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_339 \n
//! Valid values: ON, OFF.
#define IRQ_339_ENABLE                                                 (OFF)
//! Aliases for the IRQ_339 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_339_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_339_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_339 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_339_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_339 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_339_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_340 \n
//! Valid values: ON, OFF.
#define IRQ_340_ENABLE                                                 (OFF)
//! Aliases for the IRQ_340 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_340_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_340_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_340 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_340_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_340 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_340_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_341 \n
//! Valid values: ON, OFF.
#define IRQ_341_ENABLE                                                 (OFF)
//! Aliases for the IRQ_341 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_341_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_341_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_341 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_341_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_341 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_341_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_342 \n
//! Valid values: ON, OFF.
#define IRQ_342_ENABLE                                                 (OFF)
//! Aliases for the IRQ_342 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_342_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_342_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_342 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_342_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_342 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_342_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_343 \n
//! Valid values: ON, OFF.
#define IRQ_343_ENABLE                                                 (OFF)
//! Aliases for the IRQ_343 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_343_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_343_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_343 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_343_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_343 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_343_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_344 \n
//! Valid values: ON, OFF.
#define IRQ_344_ENABLE                                                 (OFF)
//! Aliases for the IRQ_344 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_344_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_344_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_344 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_344_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_344 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_344_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_345 \n
//! Valid values: ON, OFF.
#define IRQ_345_ENABLE                                                 (OFF)
//! Aliases for the IRQ_345 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_345_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_345_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_345 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_345_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_345 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_345_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_346 \n
//! Valid values: ON, OFF.
#define IRQ_346_ENABLE                                                 (OFF)
//! Aliases for the IRQ_346 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_346_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_346_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_346 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_346_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_346 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_346_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_347 \n
//! Valid values: ON, OFF.
#define IRQ_347_ENABLE                                                 (OFF)
//! Aliases for the IRQ_347 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_347_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_347_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_347 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_347_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_347 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_347_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_348 \n
//! Valid values: ON, OFF.
#define IRQ_348_ENABLE                                                 (OFF)
//! Aliases for the IRQ_348 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_348_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_348_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_348 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_348_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_348 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_348_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_349 \n
//! Valid values: ON, OFF.
#define IRQ_349_ENABLE                                                 (OFF)
//! Aliases for the IRQ_349 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_349_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_349_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_349 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_349_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_349 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_349_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_350 \n
//! Valid values: ON, OFF.
#define IRQ_350_ENABLE                                                 (OFF)
//! Aliases for the IRQ_350 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_350_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_350_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_350 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_350_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_350 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_350_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_351 \n
//! Valid values: ON, OFF.
#define IRQ_351_ENABLE                                                 (OFF)
//! Aliases for the IRQ_351 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_351_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_351_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_351 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_351_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_351 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_351_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_352 \n
//! Valid values: ON, OFF.
#define IRQ_352_ENABLE                                                 (OFF)
//! Aliases for the IRQ_352 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_352_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_352_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_352 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_352_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_352 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_352_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_353 \n
//! Valid values: ON, OFF.
#define IRQ_353_ENABLE                                                 (OFF)
//! Aliases for the IRQ_353 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_353_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_353_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_353 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_353_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_353 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_353_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_354 \n
//! Valid values: ON, OFF.
#define IRQ_354_ENABLE                                                 (OFF)
//! Aliases for the IRQ_354 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_354_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_354_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_354 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_354_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_354 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_354_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_355 \n
//! Valid values: ON, OFF.
#define IRQ_355_ENABLE                                                 (OFF)
//! Aliases for the IRQ_355 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_355_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_355_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_355 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_355_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_355 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_355_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_356 \n
//! Valid values: ON, OFF.
#define IRQ_356_ENABLE                                                 (OFF)
//! Aliases for the IRQ_356 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_356_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_356_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_356 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_356_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_356 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_356_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_357 \n
//! Valid values: ON, OFF.
#define IRQ_357_ENABLE                                                 (OFF)
//! Aliases for the IRQ_357 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_357_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_357_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_357 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_357_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_357 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_357_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_358 \n
//! Valid values: ON, OFF.
#define IRQ_358_ENABLE                                                 (OFF)
//! Aliases for the IRQ_358 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_358_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_358_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_358 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_358_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_358 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_358_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_359 \n
//! Valid values: ON, OFF.
#define IRQ_359_ENABLE                                                 (OFF)
//! Aliases for the IRQ_359 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_359_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_359_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_359 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_359_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_359 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_359_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_360 \n
//! Valid values: ON, OFF.
#define IRQ_360_ENABLE                                                 (OFF)
//! Aliases for the IRQ_360 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_360_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_360_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_360 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_360_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_360 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_360_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_361 \n
//! Valid values: ON, OFF.
#define IRQ_361_ENABLE                                                 (OFF)
//! Aliases for the IRQ_361 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_361_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_361_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_361 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_361_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_361 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_361_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_362 \n
//! Valid values: ON, OFF.
#define IRQ_362_ENABLE                                                 (OFF)
//! Aliases for the IRQ_362 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_362_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_362_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_362 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_362_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_362 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_362_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_363 \n
//! Valid values: ON, OFF.
#define IRQ_363_ENABLE                                                 (OFF)
//! Aliases for the IRQ_363 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_363_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_363_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_363 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_363_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_363 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_363_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_364 \n
//! Valid values: ON, OFF.
#define IRQ_364_ENABLE                                                 (OFF)
//! Aliases for the IRQ_364 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_364_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_364_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_364 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_364_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_364 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_364_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_365 \n
//! Valid values: ON, OFF.
#define IRQ_365_ENABLE                                                 (OFF)
//! Aliases for the IRQ_365 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_365_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_365_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_365 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_365_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_365 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_365_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_366 \n
//! Valid values: ON, OFF.
#define IRQ_366_ENABLE                                                 (OFF)
//! Aliases for the IRQ_366 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_366_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_366_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_366 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_366_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_366 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_366_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_367 \n
//! Valid values: ON, OFF.
#define IRQ_367_ENABLE                                                 (OFF)
//! Aliases for the IRQ_367 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_367_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_367_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_367 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_367_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_367 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_367_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_368 \n
//! Valid values: ON, OFF.
#define IRQ_368_ENABLE                                                 (OFF)
//! Aliases for the IRQ_368 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_368_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_368_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_368 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_368_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_368 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_368_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_369 \n
//! Valid values: ON, OFF.
#define IRQ_369_ENABLE                                                 (OFF)
//! Aliases for the IRQ_369 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_369_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_369_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_369 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_369_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_369 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_369_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_370 \n
//! Valid values: ON, OFF.
#define IRQ_370_ENABLE                                                 (OFF)
//! Aliases for the IRQ_370 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_370_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_370_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_370 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_370_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_370 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_370_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_371 \n
//! Valid values: ON, OFF.
#define IRQ_371_ENABLE                                                 (OFF)
//! Aliases for the IRQ_371 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_371_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_371_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_371 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_371_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_371 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_371_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_372 \n
//! Valid values: ON, OFF.
#define IRQ_372_ENABLE                                                 (OFF)
//! Aliases for the IRQ_372 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_372_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_372_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_372 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_372_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_372 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_372_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_373 \n
//! Valid values: ON, OFF.
#define IRQ_373_ENABLE                                                 (OFF)
//! Aliases for the IRQ_373 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_373_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_373_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_373 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_373_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_373 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_373_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_374 \n
//! Valid values: ON, OFF.
#define IRQ_374_ENABLE                                                 (OFF)
//! Aliases for the IRQ_374 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_374_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_374_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_374 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_374_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_374 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_374_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_375 \n
//! Valid values: ON, OFF.
#define IRQ_375_ENABLE                                                 (OFF)
//! Aliases for the IRQ_375 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_375_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_375_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_375 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_375_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_375 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_375_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_376 \n
//! Valid values: ON, OFF.
#define IRQ_376_ENABLE                                                 (OFF)
//! Aliases for the IRQ_376 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_376_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_376_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_376 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_376_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_376 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_376_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_377 \n
//! Valid values: ON, OFF.
#define IRQ_377_ENABLE                                                 (OFF)
//! Aliases for the IRQ_377 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_377_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_377_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_377 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_377_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_377 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_377_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_378 \n
//! Valid values: ON, OFF.
#define IRQ_378_ENABLE                                                 (OFF)
//! Aliases for the IRQ_378 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_378_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_378_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_378 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_378_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_378 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_378_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_379 \n
//! Valid values: ON, OFF.
#define IRQ_379_ENABLE                                                 (OFF)
//! Aliases for the IRQ_379 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_379_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_379_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_379 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_379_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_379 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_379_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_380 \n
//! Valid values: ON, OFF.
#define IRQ_380_ENABLE                                                 (OFF)
//! Aliases for the IRQ_380 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_380_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_380_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_380 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_380_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_380 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_380_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_381 \n
//! Valid values: ON, OFF.
#define IRQ_381_ENABLE                                                 (OFF)
//! Aliases for the IRQ_381 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_381_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_381_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_381 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_381_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_381 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_381_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_382 \n
//! Valid values: ON, OFF.
#define IRQ_382_ENABLE                                                 (OFF)
//! Aliases for the IRQ_382 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_382_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_382_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_382 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_382_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_382 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_382_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_383 \n
//! Valid values: ON, OFF.
#define IRQ_383_ENABLE                                                 (OFF)
//! Aliases for the IRQ_383 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_383_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_383_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_383 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_383_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_383 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_383_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_384 \n
//! Valid values: ON, OFF.
#define IRQ_384_ENABLE                                                 (OFF)
//! Aliases for the IRQ_384 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_384_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_384_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_384 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_384_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_384 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_384_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_385 \n
//! Valid values: ON, OFF.
#define IRQ_385_ENABLE                                                 (OFF)
//! Aliases for the IRQ_385 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_385_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_385_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_385 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_385_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_385 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_385_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_386 \n
//! Valid values: ON, OFF.
#define IRQ_386_ENABLE                                                 (OFF)
//! Aliases for the IRQ_386 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_386_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_386_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_386 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_386_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_386 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_386_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_387 \n
//! Valid values: ON, OFF.
#define IRQ_387_ENABLE                                                 (OFF)
//! Aliases for the IRQ_387 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_387_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_387_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_387 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_387_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_387 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_387_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_388 \n
//! Valid values: ON, OFF.
#define IRQ_388_ENABLE                                                 (OFF)
//! Aliases for the IRQ_388 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_388_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_388_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_388 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_388_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_388 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_388_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_389 \n
//! Valid values: ON, OFF.
#define IRQ_389_ENABLE                                                 (OFF)
//! Aliases for the IRQ_389 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_389_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_389_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_389 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_389_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_389 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_389_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_390 \n
//! Valid values: ON, OFF.
#define IRQ_390_ENABLE                                                 (OFF)
//! Aliases for the IRQ_390 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_390_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_390_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_390 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_390_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_390 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_390_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_391 \n
//! Valid values: ON, OFF.
#define IRQ_391_ENABLE                                                 (OFF)
//! Aliases for the IRQ_391 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_391_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_391_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_391 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_391_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_391 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_391_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_392 \n
//! Valid values: ON, OFF.
#define IRQ_392_ENABLE                                                 (OFF)
//! Aliases for the IRQ_392 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_392_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_392_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_392 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_392_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_392 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_392_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_393 \n
//! Valid values: ON, OFF.
#define IRQ_393_ENABLE                                                 (OFF)
//! Aliases for the IRQ_393 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_393_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_393_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_393 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_393_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_393 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_393_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_394 \n
//! Valid values: ON, OFF.
#define IRQ_394_ENABLE                                                 (OFF)
//! Aliases for the IRQ_394 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_394_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_394_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_394 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_394_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_394 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_394_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_395 \n
//! Valid values: ON, OFF.
#define IRQ_395_ENABLE                                                 (OFF)
//! Aliases for the IRQ_395 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_395_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_395_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_395 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_395_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_395 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_395_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_396 \n
//! Valid values: ON, OFF.
#define IRQ_396_ENABLE                                                 (OFF)
//! Aliases for the IRQ_396 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_396_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_396_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_396 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_396_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_396 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_396_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_397 \n
//! Valid values: ON, OFF.
#define IRQ_397_ENABLE                                                 (OFF)
//! Aliases for the IRQ_397 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_397_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_397_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_397 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_397_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_397 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_397_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_398 \n
//! Valid values: ON, OFF.
#define IRQ_398_ENABLE                                                 (OFF)
//! Aliases for the IRQ_398 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_398_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_398_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_398 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_398_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_398 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_398_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_399 \n
//! Valid values: ON, OFF.
#define IRQ_399_ENABLE                                                 (OFF)
//! Aliases for the IRQ_399 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_399_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_399_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_399 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_399_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_399 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_399_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_400 \n
//! Valid values: ON, OFF.
#define IRQ_400_ENABLE                                                 (OFF)
//! Aliases for the IRQ_400 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_400_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_400_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_400 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_400_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_400 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_400_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_401 \n
//! Valid values: ON, OFF.
#define IRQ_401_ENABLE                                                 (OFF)
//! Aliases for the IRQ_401 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_401_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_401_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_401 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_401_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_401 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_401_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_402 \n
//! Valid values: ON, OFF.
#define IRQ_402_ENABLE                                                 (OFF)
//! Aliases for the IRQ_402 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_402_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_402_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_402 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_402_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_402 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_402_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_403 \n
//! Valid values: ON, OFF.
#define IRQ_403_ENABLE                                                 (OFF)
//! Aliases for the IRQ_403 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_403_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_403_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_403 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_403_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_403 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_403_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_404 \n
//! Valid values: ON, OFF.
#define IRQ_404_ENABLE                                                 (OFF)
//! Aliases for the IRQ_404 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_404_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_404_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_404 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_404_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_404 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_404_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_405 \n
//! Valid values: ON, OFF.
#define IRQ_405_ENABLE                                                 (OFF)
//! Aliases for the IRQ_405 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_405_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_405_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_405 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_405_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_405 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_405_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_406 \n
//! Valid values: ON, OFF.
#define IRQ_406_ENABLE                                                 (OFF)
//! Aliases for the IRQ_406 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_406_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_406_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_406 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_406_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_406 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_406_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_407 \n
//! Valid values: ON, OFF.
#define IRQ_407_ENABLE                                                 (OFF)
//! Aliases for the IRQ_407 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_407_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_407_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_407 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_407_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_407 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_407_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_408 \n
//! Valid values: ON, OFF.
#define IRQ_408_ENABLE                                                 (OFF)
//! Aliases for the IRQ_408 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_408_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_408_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_408 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_408_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_408 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_408_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_409 \n
//! Valid values: ON, OFF.
#define IRQ_409_ENABLE                                                 (OFF)
//! Aliases for the IRQ_409 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_409_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_409_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_409 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_409_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_409 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_409_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_410 \n
//! Valid values: ON, OFF.
#define IRQ_410_ENABLE                                                 (OFF)
//! Aliases for the IRQ_410 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_410_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_410_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_410 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_410_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_410 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_410_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_411 \n
//! Valid values: ON, OFF.
#define IRQ_411_ENABLE                                                 (OFF)
//! Aliases for the IRQ_411 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_411_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_411_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_411 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_411_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_411 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_411_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_412 \n
//! Valid values: ON, OFF.
#define IRQ_412_ENABLE                                                 (OFF)
//! Aliases for the IRQ_412 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_412_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_412_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_412 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_412_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_412 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_412_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_413 \n
//! Valid values: ON, OFF.
#define IRQ_413_ENABLE                                                 (OFF)
//! Aliases for the IRQ_413 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_413_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_413_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_413 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_413_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_413 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_413_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_414 \n
//! Valid values: ON, OFF.
#define IRQ_414_ENABLE                                                 (OFF)
//! Aliases for the IRQ_414 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_414_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_414_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_414 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_414_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_414 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_414_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_415 \n
//! Valid values: ON, OFF.
#define IRQ_415_ENABLE                                                 (OFF)
//! Aliases for the IRQ_415 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_415_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_415_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_415 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_415_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_415 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_415_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_416 \n
//! Valid values: ON, OFF.
#define IRQ_416_ENABLE                                                 (OFF)
//! Aliases for the IRQ_416 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_416_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_416_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_416 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_416_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_416 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_416_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_417 \n
//! Valid values: ON, OFF.
#define IRQ_417_ENABLE                                                 (OFF)
//! Aliases for the IRQ_417 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_417_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_417_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_417 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_417_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_417 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_417_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_418 \n
//! Valid values: ON, OFF.
#define IRQ_418_ENABLE                                                 (OFF)
//! Aliases for the IRQ_418 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_418_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_418_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_418 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_418_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_418 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_418_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_419 \n
//! Valid values: ON, OFF.
#define IRQ_419_ENABLE                                                 (OFF)
//! Aliases for the IRQ_419 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_419_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_419_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_419 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_419_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_419 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_419_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_420 \n
//! Valid values: ON, OFF.
#define IRQ_420_ENABLE                                                 (OFF)
//! Aliases for the IRQ_420 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_420_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_420_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_420 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_420_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_420 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_420_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_421 \n
//! Valid values: ON, OFF.
#define IRQ_421_ENABLE                                                 (OFF)
//! Aliases for the IRQ_421 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_421_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_421_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_421 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_421_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_421 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_421_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_422 \n
//! Valid values: ON, OFF.
#define IRQ_422_ENABLE                                                 (OFF)
//! Aliases for the IRQ_422 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_422_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_422_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_422 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_422_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_422 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_422_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_423 \n
//! Valid values: ON, OFF.
#define IRQ_423_ENABLE                                                 (OFF)
//! Aliases for the IRQ_423 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_423_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_423_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_423 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_423_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_423 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_423_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_424 \n
//! Valid values: ON, OFF.
#define IRQ_424_ENABLE                                                 (OFF)
//! Aliases for the IRQ_424 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_424_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_424_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_424 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_424_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_424 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_424_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_425 \n
//! Valid values: ON, OFF.
#define IRQ_425_ENABLE                                                 (OFF)
//! Aliases for the IRQ_425 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_425_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_425_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_425 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_425_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_425 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_425_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_426 \n
//! Valid values: ON, OFF.
#define IRQ_426_ENABLE                                                 (OFF)
//! Aliases for the IRQ_426 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_426_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_426_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_426 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_426_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_426 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_426_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_427 \n
//! Valid values: ON, OFF.
#define IRQ_427_ENABLE                                                 (OFF)
//! Aliases for the IRQ_427 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_427_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_427_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_427 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_427_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_427 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_427_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_428 \n
//! Valid values: ON, OFF.
#define IRQ_428_ENABLE                                                 (OFF)
//! Aliases for the IRQ_428 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_428_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_428_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_428 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_428_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_428 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_428_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_429 \n
//! Valid values: ON, OFF.
#define IRQ_429_ENABLE                                                 (OFF)
//! Aliases for the IRQ_429 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_429_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_429_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_429 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_429_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_429 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_429_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_430 \n
//! Valid values: ON, OFF.
#define IRQ_430_ENABLE                                                 (OFF)
//! Aliases for the IRQ_430 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_430_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_430_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_430 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_430_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_430 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_430_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_431 \n
//! Valid values: ON, OFF.
#define IRQ_431_ENABLE                                                 (OFF)
//! Aliases for the IRQ_431 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_431_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_431_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_431 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_431_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_431 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_431_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_432 \n
//! Valid values: ON, OFF.
#define IRQ_432_ENABLE                                                 (OFF)
//! Aliases for the IRQ_432 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_432_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_432_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_432 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_432_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_432 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_432_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_433 \n
//! Valid values: ON, OFF.
#define IRQ_433_ENABLE                                                 (OFF)
//! Aliases for the IRQ_433 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_433_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_433_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_433 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_433_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_433 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_433_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_434 \n
//! Valid values: ON, OFF.
#define IRQ_434_ENABLE                                                 (OFF)
//! Aliases for the IRQ_434 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_434_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_434_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_434 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_434_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_434 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_434_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_435 \n
//! Valid values: ON, OFF.
#define IRQ_435_ENABLE                                                 (OFF)
//! Aliases for the IRQ_435 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_435_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_435_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_435 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_435_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_435 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_435_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_436 \n
//! Valid values: ON, OFF.
#define IRQ_436_ENABLE                                                 (OFF)
//! Aliases for the IRQ_436 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_436_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_436_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_436 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_436_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_436 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_436_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_437 \n
//! Valid values: ON, OFF.
#define IRQ_437_ENABLE                                                 (OFF)
//! Aliases for the IRQ_437 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_437_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_437_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_437 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_437_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_437 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_437_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_438 \n
//! Valid values: ON, OFF.
#define IRQ_438_ENABLE                                                 (OFF)
//! Aliases for the IRQ_438 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_438_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_438_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_438 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_438_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_438 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_438_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_439 \n
//! Valid values: ON, OFF.
#define IRQ_439_ENABLE                                                 (OFF)
//! Aliases for the IRQ_439 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_439_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_439_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_439 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_439_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_439 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_439_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_440 \n
//! Valid values: ON, OFF.
#define IRQ_440_ENABLE                                                 (OFF)
//! Aliases for the IRQ_440 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_440_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_440_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_440 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_440_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_440 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_440_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_441 \n
//! Valid values: ON, OFF.
#define IRQ_441_ENABLE                                                 (OFF)
//! Aliases for the IRQ_441 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_441_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_441_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_441 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_441_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_441 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_441_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_442 \n
//! Valid values: ON, OFF.
#define IRQ_442_ENABLE                                                 (OFF)
//! Aliases for the IRQ_442 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_442_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_442_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_442 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_442_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_442 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_442_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_443 \n
//! Valid values: ON, OFF.
#define IRQ_443_ENABLE                                                 (OFF)
//! Aliases for the IRQ_443 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_443_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_443_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_443 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_443_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_443 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_443_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_444 \n
//! Valid values: ON, OFF.
#define IRQ_444_ENABLE                                                 (OFF)
//! Aliases for the IRQ_444 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_444_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_444_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_444 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_444_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_444 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_444_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_445 \n
//! Valid values: ON, OFF.
#define IRQ_445_ENABLE                                                 (OFF)
//! Aliases for the IRQ_445 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_445_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_445_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_445 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_445_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_445 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_445_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_446 \n
//! Valid values: ON, OFF.
#define IRQ_446_ENABLE                                                 (OFF)
//! Aliases for the IRQ_446 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_446_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_446_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_446 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_446_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_446 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_446_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_447 \n
//! Valid values: ON, OFF.
#define IRQ_447_ENABLE                                                 (OFF)
//! Aliases for the IRQ_447 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_447_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_447_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_447 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_447_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_447 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_447_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_448 \n
//! Valid values: ON, OFF.
#define IRQ_448_ENABLE                                                 (OFF)
//! Aliases for the IRQ_448 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_448_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_448_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_448 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_448_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_448 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_448_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_449 \n
//! Valid values: ON, OFF.
#define IRQ_449_ENABLE                                                 (OFF)
//! Aliases for the IRQ_449 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_449_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_449_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_449 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_449_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_449 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_449_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_450 \n
//! Valid values: ON, OFF.
#define IRQ_450_ENABLE                                                 (OFF)
//! Aliases for the IRQ_450 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_450_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_450_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_450 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_450_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_450 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_450_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_451 \n
//! Valid values: ON, OFF.
#define IRQ_451_ENABLE                                                 (OFF)
//! Aliases for the IRQ_451 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_451_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_451_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_451 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_451_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_451 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_451_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_452 \n
//! Valid values: ON, OFF.
#define IRQ_452_ENABLE                                                 (OFF)
//! Aliases for the IRQ_452 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_452_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_452_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_452 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_452_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_452 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_452_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_453 \n
//! Valid values: ON, OFF.
#define IRQ_453_ENABLE                                                 (OFF)
//! Aliases for the IRQ_453 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_453_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_453_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_453 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_453_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_453 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_453_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_454 \n
//! Valid values: ON, OFF.
#define IRQ_454_ENABLE                                                 (OFF)
//! Aliases for the IRQ_454 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_454_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_454_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_454 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_454_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_454 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_454_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_455 \n
//! Valid values: ON, OFF.
#define IRQ_455_ENABLE                                                 (OFF)
//! Aliases for the IRQ_455 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_455_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_455_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_455 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_455_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_455 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_455_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_456 \n
//! Valid values: ON, OFF.
#define IRQ_456_ENABLE                                                 (OFF)
//! Aliases for the IRQ_456 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_456_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_456_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_456 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_456_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_456 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_456_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_457 \n
//! Valid values: ON, OFF.
#define IRQ_457_ENABLE                                                 (OFF)
//! Aliases for the IRQ_457 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_457_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_457_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_457 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_457_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_457 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_457_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_458 \n
//! Valid values: ON, OFF.
#define IRQ_458_ENABLE                                                 (OFF)
//! Aliases for the IRQ_458 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_458_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_458_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_458 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_458_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_458 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_458_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_459 \n
//! Valid values: ON, OFF.
#define IRQ_459_ENABLE                                                 (OFF)
//! Aliases for the IRQ_459 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_459_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_459_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_459 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_459_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_459 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_459_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_460 \n
//! Valid values: ON, OFF.
#define IRQ_460_ENABLE                                                 (OFF)
//! Aliases for the IRQ_460 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_460_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_460_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_460 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_460_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_460 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_460_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_461 \n
//! Valid values: ON, OFF.
#define IRQ_461_ENABLE                                                 (OFF)
//! Aliases for the IRQ_461 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_461_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_461_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_461 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_461_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_461 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_461_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_462 \n
//! Valid values: ON, OFF.
#define IRQ_462_ENABLE                                                 (OFF)
//! Aliases for the IRQ_462 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_462_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_462_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_462 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_462_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_462 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_462_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_463 \n
//! Valid values: ON, OFF.
#define IRQ_463_ENABLE                                                 (OFF)
//! Aliases for the IRQ_463 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_463_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_463_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_463 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_463_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_463 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_463_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_464 \n
//! Valid values: ON, OFF.
#define IRQ_464_ENABLE                                                 (OFF)
//! Aliases for the IRQ_464 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_464_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_464_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_464 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_464_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_464 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_464_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_465 \n
//! Valid values: ON, OFF.
#define IRQ_465_ENABLE                                                 (OFF)
//! Aliases for the IRQ_465 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_465_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_465_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_465 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_465_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_465 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_465_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_466 \n
//! Valid values: ON, OFF.
#define IRQ_466_ENABLE                                                 (OFF)
//! Aliases for the IRQ_466 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_466_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_466_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_466 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_466_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_466 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_466_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_467 \n
//! Valid values: ON, OFF.
#define IRQ_467_ENABLE                                                 (OFF)
//! Aliases for the IRQ_467 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_467_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_467_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_467 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_467_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_467 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_467_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_468 \n
//! Valid values: ON, OFF.
#define IRQ_468_ENABLE                                                 (OFF)
//! Aliases for the IRQ_468 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_468_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_468_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_468 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_468_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_468 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_468_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_469 \n
//! Valid values: ON, OFF.
#define IRQ_469_ENABLE                                                 (OFF)
//! Aliases for the IRQ_469 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_469_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_469_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_469 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_469_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_469 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_469_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_470 \n
//! Valid values: ON, OFF.
#define IRQ_470_ENABLE                                                 (OFF)
//! Aliases for the IRQ_470 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_470_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_470_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_470 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_470_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_470 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_470_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_471 \n
//! Valid values: ON, OFF.
#define IRQ_471_ENABLE                                                 (OFF)
//! Aliases for the IRQ_471 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_471_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_471_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_471 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_471_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_471 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_471_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_472 \n
//! Valid values: ON, OFF.
#define IRQ_472_ENABLE                                                 (OFF)
//! Aliases for the IRQ_472 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_472_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_472_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_472 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_472_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_472 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_472_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_473 \n
//! Valid values: ON, OFF.
#define IRQ_473_ENABLE                                                 (OFF)
//! Aliases for the IRQ_473 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_473_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_473_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_473 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_473_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_473 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_473_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_474 \n
//! Valid values: ON, OFF.
#define IRQ_474_ENABLE                                                 (OFF)
//! Aliases for the IRQ_474 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_474_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_474_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_474 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_474_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_474 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_474_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_475 \n
//! Valid values: ON, OFF.
#define IRQ_475_ENABLE                                                 (OFF)
//! Aliases for the IRQ_475 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_475_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_475_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_475 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_475_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_475 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_475_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_476 \n
//! Valid values: ON, OFF.
#define IRQ_476_ENABLE                                                 (OFF)
//! Aliases for the IRQ_476 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_476_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_476_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_476 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_476_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_476 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_476_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_477 \n
//! Valid values: ON, OFF.
#define IRQ_477_ENABLE                                                 (OFF)
//! Aliases for the IRQ_477 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_477_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_477_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_477 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_477_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_477 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_477_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_478 \n
//! Valid values: ON, OFF.
#define IRQ_478_ENABLE                                                 (OFF)
//! Aliases for the IRQ_478 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_478_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_478_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_478 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_478_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_478 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_478_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)

//! Enable IRQ_479 \n
//! Valid values: ON, OFF.
#define IRQ_479_ENABLE                                                 (OFF)
//! Aliases for the IRQ_479 interrupt handler. \n
//! Valid value: IRQ_DEFAULT_HANDLER, handler function address.
#define IRQ_479_ALIAS_FUN1                                             IRQ_DEFAULT_HANDLER
#define IRQ_479_ALIAS_FUN2                                             IRQ_DEFAULT_HANDLER
//! The group priority level for the IRQ_479 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_GROUP_PRIORITY_LEVEL.
#define IRQ_479_GROUP_PRIORITY_LEVEL                                   (IRQ_GROUP_PRIORITY_LEVEL_MIN)
//! The sub-priority level for the IRQ_479 interrupt handler. \n
//! For valid values search for #valid_values_IRQ_x_SUB_PRIORITY_LEVEL.
#define IRQ_479_SUB_PRIORITY_LEVEL                                     (IRQ_SUB_PRIORITY_LEVEL_MIN)



#endif // #ifndef IRQ_DRV_CFG_H

//****************************************** end of file *******************************************
