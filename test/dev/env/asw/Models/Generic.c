/*
 * File: Generic.c
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

/*
 * MSEpro Code Generator v.3.0.7145.22606 built at 25.07.2019 12:33:33
 * Target Platform: STM32Fxxx family
 */

#include "Generic.h"
#include "Generic.prm"

#include "Generic_private.h"
#include "test_spi.h"

void PIT_CallbackHandler(void)
{

  /* Output and update for function-call system: '<S12>/Content' */

  /* Generic/Reset init/MCU Initialization1/Action Definition/Content/Function Definition/Read System Variable */

  

  // Generic/Reset init/MCU Initialization1/Action Definition/Content/Function Definition/Action Call1  

  EHAL_OS_SCHDL_StartLevel(( LvCtrlSW1ms)); // Action Call
}

/*-------------------------------------------------------------------------
 * This is an empty function 
 *-----------------------------------------------------------------------*/
void _Empty(void)
{
}                                       /* _Empty */

/*-------------------------------------------------------------------------
 * Reset Initialization Level 
 *-----------------------------------------------------------------------*/
void _LvReset(void)
{

  /* Output and update for function-call system: '<Root>/Reset init' */

  /* Output and update for atomic system: '<S5>/MCU Initialization1' */

  // Generic/Reset init/MCU Initialization1/Action Call2  

  EHAL_TMR_PIT_Init(CONST_cOS_UsedPIT_Number); // Action Call

  // Generic/Reset init/MCU Initialization1/Action Call  

  EHAL_TMR_PIT_StopTimer(CONST_cOS_UsedPIT_Number); // Action Call

  /* Generic/Reset init/MCU Initialization1/Get Parameter Handle */

  

  // Generic/Reset init/MCU Initialization1/Action Call1  

  EHAL_TMR_PIT_SetCallbackFunction(CONST_cOS_UsedPIT_Number,
   ( PIT_CallbackHandler));     // Action Call

  /* Output and update for atomic system: '<S5>/MCU Initialization3' */

  /* Generic/Reset init/MCU Initialization3/Get Parameter Handle */

  

  // Generic/Reset init/MCU Initialization3/Action Call  

   // Action Call 

  // Generic/Reset init/MCU Initialization3/Action Call1  

  EHAL_TMR_PIT_GetTickPeriod(CONST_cOS_UsedPIT_Number, ( ConvertToPtr_32bit(( (uint32_T) &pRTOS_TimerTickPeriod_data)))); // Action Call

  /* Generic/Reset init/MCU Initialization3/Read Parameter */
  

  // Generic/Reset init/MCU Initialization3/Add Bit Description Info

  // Generic/Reset init/MCU Initialization3/Divide

  TEST_Init();

  // Generic/Reset init/MCU Initialization3/Action Call2  

  EHAL_TMR_PIT_StartTimer(CONST_cOS_UsedPIT_Number, ( (uint32_T)CONST_cRTOS_FastestLevelPeriod /
    (uint32_T)( pRTOS_TimerTickPeriod_data))); // Action Call
}                                       /* _LvReset */

static U64 nCnt;
/*-------------------------------------------------------------------------
 * TimeMachine 1 ms Level CSW 
 *-----------------------------------------------------------------------*/
void _LvCtrlSW1ms(void)
{
   TEST_1ms();

   nCnt = SCHDL_GetAndResetIdleCounter();
	 uint16_T Generic_B_ReadParameter_g;
	 uint16_T Generic_B_Saturation;
	 uint16_T Generic_B_Add;
	 uint16_T Generic_B_MultiportSwitch;
	 uint16_T Generic_B_ReadParameter1;
	 uint16_T Generic_B_Saturation_f;
	 uint16_T Generic_B_Add_e;
	 uint16_T Generic_B_MultiportSwitch_b;
	 uint16_T Generic_B_ReadParameter2;
	 uint16_T Generic_B_Saturation_h;
	 uint16_T Generic_B_Add_d;
	 uint16_T Generic_B_MultiportSwitch_o;

  /* Output and update for function-call system: '<Root>/Time Machine  1 ms' */

  // Generic/Time Machine  1 ms/Subsystem/periodic timer/Constant with Bit Description1

  // Generic/Time Machine  1 ms/Subsystem/Constant with Bit Description

  /* Generic/Time Machine  1 ms/Subsystem/Read Parameter */
  Generic_B_ReadParameter_g = pTimeM_10msLv_Timer_data;

  // "Generic/Time Machine  1 ms/Subsystem/periodic timer/Saturation"

  if (Generic_B_ReadParameter_g > 10U) Generic_B_Saturation = 10U;

  else Generic_B_Saturation = Generic_B_ReadParameter_g;

  // Generic/Time Machine  1 ms/Subsystem/periodic timer/Constant with Bit Description

  // Generic/Time Machine  1 ms/Subsystem/periodic timer/Add 

  Generic_B_Add = Generic_B_Saturation + 1U;

  // Generic/Time Machine  1 ms/Subsystem/periodic timer/If

  

  // Generic/Time Machine  1 ms/Subsystem/periodic timer/Multiport Switch

  if (0 == ( (Generic_B_Add >= 10U) ? 1 : 0))
  {
    Generic_B_MultiportSwitch = Generic_B_Add;
  }
  else
  {
    Generic_B_MultiportSwitch = 0U;
  }

  /* Generic/Time Machine  1 ms/Subsystem/Write & Read Parameter */

  pTimeM_10msLv_Timer_data = Generic_B_MultiportSwitch;

  // Generic/Time Machine  1 ms/Subsystem/Not

  

  // Generic/Time Machine  1 ms/Subsystem/Conditional Function Call1

  if (( pTimeM_10msLv_Timer_data ? 0 : 1) != 0)
  {

    /* Output and update for function-call system: '<S15>/Task counter1' */

    /* Generic/Time Machine  1 ms/Subsystem/Task counter1/Read System Variable1 */

    

    // Generic/Time Machine  1 ms/Subsystem/Task counter1/Action Call  

    EHAL_OS_SCHDL_ActivateLevel(( LvCtrlSW10ms)); // Action Call
  }

  // Generic/Time Machine  1 ms/Subsystem/periodic timer1/Constant with Bit Description1

  // Generic/Time Machine  1 ms/Subsystem/Constant with Bit Description1

  /* Generic/Time Machine  1 ms/Subsystem/Read Parameter1 */
  Generic_B_ReadParameter1 = pTimeM_100msLv_Timer_data;

  // "Generic/Time Machine  1 ms/Subsystem/periodic timer1/Saturation"

  if (Generic_B_ReadParameter1 > 100U) Generic_B_Saturation_f = 100U;

  else Generic_B_Saturation_f = Generic_B_ReadParameter1;

  // Generic/Time Machine  1 ms/Subsystem/periodic timer1/Constant with Bit Description

  // Generic/Time Machine  1 ms/Subsystem/periodic timer1/Add 

  Generic_B_Add_e = Generic_B_Saturation_f + 1U;

  // Generic/Time Machine  1 ms/Subsystem/periodic timer1/If

  

  // Generic/Time Machine  1 ms/Subsystem/periodic timer1/Multiport Switch

  if (0 == ( (Generic_B_Add_e >= 100U) ? 1 : 0))
  {
    Generic_B_MultiportSwitch_b = Generic_B_Add_e;
  }
  else
  {
    Generic_B_MultiportSwitch_b = 0U;
  }

  /* Generic/Time Machine  1 ms/Subsystem/Write & Read Parameter1 */

  pTimeM_100msLv_Timer_data = Generic_B_MultiportSwitch_b;

  // Generic/Time Machine  1 ms/Subsystem/Not1

  

  // Generic/Time Machine  1 ms/Subsystem/Conditional Function Call2

  if (( pTimeM_100msLv_Timer_data ? 0 : 1) != 0)
  {

    /* Output and update for function-call system: '<S15>/Task counter2' */

    /* Generic/Time Machine  1 ms/Subsystem/Task counter2/Read System Variable */

    

    // Generic/Time Machine  1 ms/Subsystem/Task counter2/Action Call  

    EHAL_OS_SCHDL_ActivateLevel(( LvCtrlSW100ms)); // Action Call
  }

  // Generic/Time Machine  1 ms/Subsystem/periodic timer2/Constant with Bit Description1

  // Generic/Time Machine  1 ms/Subsystem/Constant with Bit Description2

  /* Generic/Time Machine  1 ms/Subsystem/Read Parameter2 */
  Generic_B_ReadParameter2 = pTimeM_1000msLv_Timer_data;

  // "Generic/Time Machine  1 ms/Subsystem/periodic timer2/Saturation"

  if (Generic_B_ReadParameter2 > 1000U) Generic_B_Saturation_h = 1000U;

  else Generic_B_Saturation_h = Generic_B_ReadParameter2;

  // Generic/Time Machine  1 ms/Subsystem/periodic timer2/Constant with Bit Description

  // Generic/Time Machine  1 ms/Subsystem/periodic timer2/Add 

  Generic_B_Add_d = Generic_B_Saturation_h + 1U;

  // Generic/Time Machine  1 ms/Subsystem/periodic timer2/If

  

  // Generic/Time Machine  1 ms/Subsystem/periodic timer2/Multiport Switch

  if (0 == ( (Generic_B_Add_d >= 1000U) ? 1 : 0))
  {
    Generic_B_MultiportSwitch_o = Generic_B_Add_d;
  }
  else
  {
    Generic_B_MultiportSwitch_o = 0U;
  }

  /* Generic/Time Machine  1 ms/Subsystem/Write & Read Parameter2 */

  pTimeM_1000msLv_Timer_data = Generic_B_MultiportSwitch_o;

  // Generic/Time Machine  1 ms/Subsystem/Not2

  

  // Generic/Time Machine  1 ms/Subsystem/Conditional Function Call4

  if (( pTimeM_1000msLv_Timer_data ? 0 : 1) != 0)
  {

    /* Output and update for function-call system: '<S15>/Task counter3' */

    /* Generic/Time Machine  1 ms/Subsystem/Task counter3/Read System Variable */

    

    // Generic/Time Machine  1 ms/Subsystem/Task counter3/Action Call  

    EHAL_OS_SCHDL_ActivateLevel(( LvCtrlSW1sec)); // Action Call
  }
}                                       /* _LvCtrlSW1ms */

/*-------------------------------------------------------------------------
 * TimeMachine 10 ms Level CSW 
 *-----------------------------------------------------------------------*/
void _LvCtrlSW10ms(void)
{
    TEST_10ms();

}                                       /* _LvCtrlSW10ms */

/*-------------------------------------------------------------------------
 * TimeMachine 100 ms Level CSW 
 *-----------------------------------------------------------------------*/
void _LvCtrlSW100ms(void)
{
    TEST_100ms();

}                                       /* _LvCtrlSW100ms */

/*-------------------------------------------------------------------------
 * TimeMachine 1 sec Level CSW 
 *-----------------------------------------------------------------------*/
void _LvCtrlSW1sec(void)
{
    TEST_1sec();

}                                       /* _LvCtrlSW1sec */

/*-------------------------------------------------------------------------
 * Start Level (Data loaded) 
 *-----------------------------------------------------------------------*/
void _LvStart(void)
{
}                                       /* _LvStart */

/*-------------------------------------------------------------------------
 * Stop Level (prepare Data) 
 *-----------------------------------------------------------------------*/
void _LvStop(void)
{
}                                       /* _LvStop */

/*-----------------------------------------------------------------------*/
void Project_Init()
{
  /* models initialization */

  Generic_initialize(1);

  /* functions initialization */
}                                       /* Project_Init */

/*-----------------------------------------------------------------------*/
void Project_Final()
{
  /* functions finalization */
}                                       /* Project_Final */

/*-----------------------------------------------------------------------*/

/* Functions array */

const _FUNC_ XHUGE TaskTable[LEVELS_COUNT] =
  {
  _Empty, _LvReset, _LvCtrlSW1ms, _LvCtrlSW10ms,
  _LvCtrlSW100ms, _LvCtrlSW1sec, _LvStart, _LvStop
};

/* Priorities table */

const unsigned char PriorsTable[LEVELS_COUNT] =
  {
  0x00, 0x00, 0x01, 0x02,
  0x03, 0x04, 0x04, 0x04
};

/* CSE type codes 
 * 
 * 0:	1 �sec 		Time	
 * 1:	10 �sec		Time	
 * 2:	100 �sec	Time	
 * 3:	1 msec		Time	
 * 4:	10 msec		Time	
 * 5:	100 msec	Time	
 * 6:	1 sec		Time	
 * 7:	10 sec		Time	
 * 8:	1 min		Time	
 * 9:	1 h			Time	
 * 10:	1 d			Time	
 * 
 * 100:	Angular degrees				Angle	
 * 101:	Revolutions 360 degrees		Angle	
 * 102:	Cycle 720 degrees			Angle	e.g. in case of IC engines
 * 103:	Cylinder segment			Combustion	e.g. in case of IC engines
 *
 * 999:	Always
 * 1000:	Non deterministic	Without fixed scaling
 *
 */

const uint16_T CseTypeCodeTable[LEVELS_COUNT] =
  {
  999, 1000, 3, 4,
  5, 6, 1000, 1000
};

/* CSE values */

const uint16_T CseValueTable[LEVELS_COUNT] =
  {
  1, 0, 1, 1,
  1, 1, 0, 0
};

/* Model step function */
void Generic_step(void)
{

  /* (no output code required) */

  /* (no update code required) */
}

/* Model initialize function */
void Generic_initialize(boolean_T firstTime)
{
  /* (no initialization code required) */
}

/* File trailer for Real-Time Workshop generated code.
 *
 * You can customize this file trailer by specifying a different template.
 *
 * [EOF]
 */
