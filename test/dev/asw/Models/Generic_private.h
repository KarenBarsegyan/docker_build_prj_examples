/*
 * File: Generic_private.h
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

#ifndef _RTW_HEADER_Generic_private_h_
#define _RTW_HEADER_Generic_private_h_

#include "rtwtypes.h"

/*
 * MSEpro Code Generator v.3.0.7145.22606 built at 25.07.2019 12:33:33
 * Target Platform: STM32Fxxx family
 */

#define DISABLE_OPTIMIZATION
#define ENABLE_OPTIMIZATION
#include "TestProject_ps_consts.h"

#include "TestProject_ps_headers.h"

#include "TestProject_ps_flashdata.h"

#include "TestProject_ps_tec_romdata.h"

#include "TestProject_ps_ramdata.h"

#include "TestProject_ps_ramdata_no_init.h"

#include "TestProject_ps_ramaseeprom.h"

#include "ECU_SystemSW.h"

#include "levels.h"
#include "variant.h"

/* Private macros used by the generated code to access rtModel */

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else
/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                  /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                  /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                  /* __RTWTYPES_H__ */

extern void PIT_CallbackHandler(void);

#endif                                  /* _RTW_HEADER_Generic_private_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * You can customize this file trailer by specifying a different template.
 *
 * [EOF]
 */
