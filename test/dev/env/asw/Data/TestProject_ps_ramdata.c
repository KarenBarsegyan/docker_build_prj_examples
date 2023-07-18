// *****************************************************************************
// @Module	ps_ramdata.c
// @Author	MSEpro Code Generator v.3.0.7145.22606 built at 25.07.2019 12:33:33
// @Description	Contains variables of RAM parameters
// *****************************************************************************

#include "TestProject_ps_ramdata.h"

SEGMENT_BEGIN(DATA_SEG, FAR_SEG, ps_ramdata)

U8	NEAR	pCSWL_Stub_data;

U32	NEAR	eCSWL_BlackBox_Odometer_data;

U32	NEAR	eCSWL_BlackBox_Overtemperature_Dur_data;

U32	NEAR	eCSWL_BlackBox_Overvoltage_Dur_data;

U32	NEAR	eCSWL_BlackBox_Worktime_data;

U8	NEAR	eCSWL_EEPROM_stub_data;

U8	NEAR	eCSWL_ECUID_FD14_ConfigurationVersion_data[15];

U32	NEAR	pCSWL_ECUID_stub_data;

U32	NEAR	pCSWL_ECUID_FD07_Application_CS_data;

U32	NEAR	pCSWL_ECUID_FD06_Application_CS_precalc_data;

U32	NEAR	pCSWL_ECUID_FD0B_Bootloader_CS_data;

U32	NEAR	pCSWL_ECUID_FD0A_Bootloader_CS_precalc_data;

U32	NEAR	pCSWL_ECUID_FD0F_Calibration_CS_data;

U32	NEAR	pCSWL_ECUID_FD0E_Calibration_CS_precalc_data;

U32	NEAR	pCSWL_ECUID_FD13_Configuration_CS_data;

U32	NEAR	eCSWL_ECUID_FD12_Configuration_CS_precalc_data;

U8	NEAR	pCSWL_UDS_WDBI_Flag_data[20];

U8	NEAR	eCSWL_ECUID_FD15_VMEOL_Ready_data;

U8	NEAR	pCSWL_ECUID_FD15_VMEOL_srvWrite_data;

U32	NEAR	pCSWL_ECUID_ROM_CS_data;

U32	NEAR	pCSWL_ECUID_ROM_CS_precalc_data;

U8	NEAR	pCSWL_DO_ShortsCnt_data;

U8	NEAR	pCSWL_FO_ShortsCnt_data;

U32	NEAR	pRTOS_TimerTickPeriod_data;

U16	NEAR	pTimeM_1000msLv_Timer_data;

U16	NEAR	pTimeM_100msLv_Timer_data;

U16	NEAR	pTimeM_10msLv_Timer_data;

U8	NEAR	pCSWL_MonOS_MCU_ResetCnt_data;

U32	NEAR	eCSWL_BlackBox_Fault_Dur_data;

U8	NEAR	pCSWL_FO_Protection_MissionRestarts_cnt_data;

U8	NEAR	pCSWL_FO_Protection_AfterSales_cnt_data;

U8	NEAR	pCSWL_BRDC_Protection_AfterSalesClear_Write_data;

U8	NEAR	pCSWL_DO_Protection_AfterSales_cnt_data;

U8	NEAR	pCSWL_DO_Protection_MissionRestarts_cnt_data;

U8	NEAR	pCSWL_BRDC_Protection_ReplaceECU_data;

U8	NEAR	eCSWL_UDS_CDTCS_state_data;

U8	NEAR	pCSWL_UDS_CDTCS_state_data;

SEGMENT_END(DATA_SEG, FAR_SEG, ps_ramdata)
