/*
 * File: Generic.h
 *
 * Real-Time Workshop code generated for Simulink model Generic.
 *
 * Model version                        : 1.2002
 * Real-Time Workshop file version      : 6.2.1  (R14SP2+)  03-May-2005
 * Real-Time Workshop file generated on : Thu Jun 30 11:30:44 2022
 * TLC version                          : 6.2 (Jan 16 2005)
 * C source code generated on           : Thu Jun 30 11:30:45 2022
 *
 * You can customize this banner by specifying a different template.
 */
#ifndef _RTW_HEADER_Generic_h_
#define _RTW_HEADER_Generic_h_
/*
 * MSEpro Code Generator v.3.0.7145.22606 built at 25.07.2019 12:33:33
 * Target Platform: STM32Fxxx family
 */
#include "compiler.h"
#ifndef _Generic_COMMON_INCLUDES_
# define _Generic_COMMON_INCLUDES_
#include <math.h>
#include <float.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtlibsrc.h"
#endif                                  /* _Generic_COMMON_INCLUDES_ */
#include "Generic_types.h"
#define LEVELS_COUNT                    8
/* Macros for accessing real-time model data structure  */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm) ((void*) 0)
#endif
#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val) ((void) 0)
#endif
/* Block signals (auto storage) */
/* Model entry point functions */
extern void Generic_initialize(boolean_T firstTime);
extern void Generic_step(void);
extern void Project_Init();
extern void Project_Final();
extern const _FUNC_ XHUGE TaskTable[LEVELS_COUNT];
extern const unsigned char PriorsTable[LEVELS_COUNT];
extern const uint16_T CseTypeCodeTable[LEVELS_COUNT];
extern const uint16_T CseValueTable[LEVELS_COUNT];
/* 
 * The generated code includes comments that allow you to trace directly 
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : Generic
 * '<S1>'   : Generic/LvStart
 * '<S2>'   : Generic/LvStop
 * '<S3>'   : Generic/OS Scheduler
 * '<S4>'   : Generic/Project init
 * '<S5>'   : Generic/Reset init
 * '<S6>'   : Generic/Time Machine  1 ms
 * '<S7>'   : Generic/Time Machine  10 ms
 * '<S8>'   : Generic/Time Machine  100 ms
 * '<S9>'   : Generic/Time Machine 1 sec
 * '<S10>'  : Generic/Reset init/MCU Initialization1
 * '<S11>'  : Generic/Reset init/MCU Initialization3
 * '<S12>'  : Generic/Reset init/MCU Initialization1/Action Definition
 * '<S13>'  : Generic/Reset init/MCU Initialization1/Action Definition/Content
 * '<S14>'  : Generic/Reset init/MCU Initialization1/Action Definition/Content/Function Definition
 * '<S15>'  : Generic/Time Machine  1 ms/Subsystem
 * '<S16>'  : Generic/Time Machine  1 ms/Subsystem/Task counter1
 * '<S17>'  : Generic/Time Machine  1 ms/Subsystem/Task counter2
 * '<S18>'  : Generic/Time Machine  1 ms/Subsystem/Task counter3
 * '<S19>'  : Generic/Time Machine  1 ms/Subsystem/periodic timer
 * '<S20>'  : Generic/Time Machine  1 ms/Subsystem/periodic timer1
 * '<S21>'  : Generic/Time Machine  1 ms/Subsystem/periodic timer2
 */
#endif                                  /* _RTW_HEADER_Generic_h_ */
/* File trailer for Real-Time Workshop generated code.
 *
 * You can customize this file trailer by specifying a different template.
 *
 * [EOF]
 */
