//**************************************************************************************************
// @Module        SCHDL
//! \file   portable.c
//! \par    Platform
//!             Cortex-M4
//! \par    Compatible
//!             STM32F4, APM32F4, AT32F4, HC32F4 families
//! \brief  This file contains interrupt of scheduler.
//!
//! \par    History
//! Date       | Version | Author  | Comment
//! :---------:|:-------:|:-------:|---------------
//! 25.01.2017 |  1.0.0  |   SHA   | First release.
//! 26.11.2018 |  1.1.0  |   SRM   | ISR optimization avoidance has been added.
//! 22.08.2022 |  1.2.0  |   SMM   | Ported to Cortex-M4 core.
//! 13.04.2023 |  1.2.1  |   PAV   | Fixed bug with lost tasks.
//! 14.04.2023 |  1.2.2  |   PAV   | Refactoring according to Doxygen rules.
//**************************************************************************************************



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Native header
#include "portable.h"



//**************************************************************************************************
// Verification of the imported configuration parameters
//**************************************************************************************************

// None.



//**************************************************************************************************
// Definitions of global (public) variables
//**************************************************************************************************

//! Functions array
extern _FUNC_   TaskTable[];

//! Priorities table
extern U8       PriorsTable[];



//**************************************************************************************************
// Declarations of local (private) data types
//**************************************************************************************************

// None



//**************************************************************************************************
// Definitions of local (private) constants
//**************************************************************************************************

//! Zero current priority indicates that no task is running
#define SCHDL_PRIOR_NOT_TASK      0U



//**************************************************************************************************
// Definitions of static global (private) variables
//**************************************************************************************************

//! Priority of current task. 0 - not task, 255 - smallest
static volatile U8 SCHDL_nCurrentPrior = SCHDL_PRIOR_NOT_TASK;

//! Pointer to task function
static volatile _FUNC_ SCHDL_pTaskFuncAddress = NULL_PTR;

//! Number of task
static volatile U8 SCHDL_nCurrentNumTask;

#if(ON == SCHDL_INTERNAL_DIAGNOSTICS)
//! Debug counter of running tasks
static U16     SCHDL_nTasksStartRunningCounter[SCHDL_TASK_COUNT] = {0};
#endif // #if(ON == SCHDL_INTERNAL_DIAGNOSTICS)



//**************************************************************************************************
// Declarations of local (private) functions
//**************************************************************************************************

//! \brief Jump to TaskTable function
static void SCHDL_TaskTableJump(void);

//! \brief Handler for finished tasks
static void SCHDL_TaskFinisher(void);

//! \brief Clear scheduler interrupt request
static inline void SCHDL_ClearIntReq(void);



//**************************************************************************************************
//==================================================================================================
// Definitions of global (public) functions
//==================================================================================================
//**************************************************************************************************



//**************************************************************************************************
//! Avoids ISR optimization during library building process.
//!
//! \note None
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
void SCHDL_AvoidISRLibraryOptimization(void)
{
    DoNothing();

} // end of SCHDL_AvoidISRLibraryOptimization()



//**************************************************************************************************
//! Interrupt of scheduler.
//!
//! \note View the map query, to identify the most priority request and, if necessary,
//!       changes the state of a task at a higher priority.
//!       Should be assigned to any unused IRQ (see SCHDL_IRQ_NUMBER)
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
INTERRUPT void SCHDL_SchedulerProc(void)
{
    // Number task
    U8 nNumTask;
    // For full scanning of task query array
    U8 nEmptyTaskQuery = ON;

    // Clear interrupt flag
    SCHDL_ClearIntReq();

    while(nEmptyTaskQuery == ON)
    {
        // Analyze bitmaps
        for(nNumTask = 0; nNumTask < SCHDL_TASK_COUNT; nNumTask++)
        {
            if(SCHDL_nTaskQuery[nNumTask] != 0)
            {
                nEmptyTaskQuery = ON;
                break;
            }
            else
            {
                nEmptyTaskQuery = OFF;
            }
        }

        if(nEmptyTaskQuery == ON)
        {
            if((SCHDL_nCurrentPrior == 0) || (SCHDL_nCurrentPrior > PriorsTable[nNumTask]))
            {
                // Calculation of the number of tasks
                SCHDL_nCurrentNumTask = nNumTask;

                if(SCHDL_nTaskRunning[SCHDL_nCurrentNumTask] == OFF)
                {
                    // Increment task counter
                    SCHDL_nRunningTaskCounter++;
                    if(SCHDL_nRunningTaskCounter < SCHDL_MAX_RUN_TASK)
                    {
                        // Store task priority
                        SCHDL_nCurrentPrior = PriorsTable[SCHDL_nCurrentNumTask];
                        // Set flag of task running
                        SCHDL_nTaskRunning[SCHDL_nCurrentNumTask] = ON;
                        // Set address of task function
                        SCHDL_pTaskFuncAddress = TaskTable[SCHDL_nCurrentNumTask];
                        #if(ON == SCHDL_INTERNAL_DIAGNOSTICS)
                        // Increment of running counter
                        SCHDL_nTasksStartRunningCounter[SCHDL_nCurrentNumTask]++;
                        #endif // #if(ON == SCHDL_INTERNAL_DIAGNOSTICS)

                        // Jump to task function
                        SCHDL_TaskTableJump();

                        // Clear flag in the bitmap array
                        SCHDL_nTaskQuery[SCHDL_nCurrentNumTask] = OFF;
                        // Clear flag of task running
                        SCHDL_nTaskRunning[SCHDL_nCurrentNumTask] = OFF;
                        // Clear current priority
                        SCHDL_nCurrentPrior = SCHDL_PRIOR_NOT_TASK;
                        // Rescanning task query array
                        nEmptyTaskQuery = ON;
                        // Decrement task counter
                        SCHDL_nRunningTaskCounter--;

                    } // End of if(SCHDL_nRunningTaskCounter < SCHDL_MAX_RUN_TASK)
                    else
                    {
                        SCHDL_nRunningTaskCounter = SCHDL_MAX_RUN_TASK - 1;
                        // Stop scanning task query array because maximum number of task is running
                        nEmptyTaskQuery = OFF;
                    }
                } // End of if((SCHDL_nTaskRunning[] == OFF)
                else
                {
                    // Restore task priority
                    SCHDL_nCurrentPrior = PriorsTable[SCHDL_nCurrentNumTask];
                    // Stop scanning task query array because resume to the pending task
                    nEmptyTaskQuery = OFF;
                }
            } // End of if((SCHDL_nCurrentPrior==0)||(SCHDL_nCurrentPrior<PriorsTable[nNumTask]))
            else
            {
                // End scanning task query array
                nEmptyTaskQuery = OFF;
            }
        } // End of if(i < SCHDL_BIT_TAB_LEN)
        else
        {  // Not request - clear variable
            SCHDL_nCurrentPrior = 0;
            // End scanning task query array
            nEmptyTaskQuery = OFF;
        }
    } // while(nEmptyTaskQuery)
} // end of SCHDL_SchedulerProc()



//**************************************************************************************************
//! Finisher sequence of the Scheduler.
//!
//! \note Closes task stack frame, updates global Scheduler variables and sets
//!       Scheduler Request bit.
//!       Should be assigned to SVCall_Handler
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
INTERRUPT void __attribute__((naked)) SCHDL_SchedulerClose(void)
{
    // Discard stack frame of the finished task and pop return address to PC
    __asm volatile
    (
            "       add     sp,sp,#((8+1)*4)                    \n"
            "       pop     {pc}                                \n"
    );
} // end of SCHDL_SchedulerClose()



//**************************************************************************************************
//==================================================================================================
// Definitions of local (private) functions
//==================================================================================================
//**************************************************************************************************



//**************************************************************************************************
//! Jump to address from TaskTable[].
//!
//! \note The address is transmitted via pointer SCHDL_pTaskFuncAddress.
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
static void __attribute__((naked)) SCHDL_TaskTableJump(void)
{
    __asm volatile
    (
            // Pushing link register value to the stack
            "       push    {lr}                                                \n"
            // r1 stores future LR value: SCHDL_TaskFinisher address
            "       ldr     r1, SCHDL_TaskFinisher_addr                         \n"
            // Load SCHDL_pTaskFuncAddress address
            "       ldr     r2, SCHDL_pTaskFuncAddress_addr                     \n"
            // r2 stores future PC value: new task entry point address
            "       ldr     r2, [r2]                                            \n"
            // r3 stores future xPSR value
            "       ldr     r3, = 1 << 24                                       \n"
            // Decrement SP by size of context stored 
            // and +1 word for align SP address (by default bit CCR.STKALIGN=1)
            "       sub     sp, sp, #(8+1)*4                                    \n"
            // Move to r0 SP shifted by
            "       add     r0, sp, #5*4                                        \n"
            // Store new LR, PC and x PSR to new context frame
            "       stm     r0!, {r1-r3}                                        \n"
            // Substitute LR value
            "       mov     lr, 0xFFFFFFF9                                      \n"
            // Restore our faked context!
            "       bx      lr                                                  \n"
            // Global variables
            "       .align 4                                                    \n"
            "SCHDL_TaskFinisher_addr:        .word SCHDL_TaskFinisher           \n"
            "SCHDL_pTaskFuncAddress_addr:    .word SCHDL_pTaskFuncAddress       \n"
    );
} // end of SCHDL_TaskTableJump()



//**************************************************************************************************
//! Function used as a return address. Invokes Supervisor Call that restores context.
//!
//! \note None.
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
static void __attribute__((naked, used)) SCHDL_TaskFinisher(void)
{
    // Invoking Supervisor Call
    __asm volatile
    (
            "       svc #0                         \n"
    );
} // end of SCHDL_TaskFinisher()



//**************************************************************************************************
//! Clear scheduler interrupt request.
//!
//! \note None.
//!
//! \param None
//!
//! \return None
//**************************************************************************************************
static inline void SCHDL_ClearIntReq(void)
{
    NVIC.ICPR[SCHDL_IRQ_REG].R = SCHDL_IRQ_BITMASK;
}



//****************************************** end of file *******************************************
