// *****************************************************************************
// @Module	ps_headers.c
// @Author	MSEpro Code Generator v.3.0.7145.22606 built at 25.07.2019 12:33:33
// @Description	Contains paramset data definitions
// *****************************************************************************


#include "TestProject_ps_headers.h"

#include "TestProject_ps_cbuffers.h"
#include "TestProject_ps_flashdata.h"
#include "TestProject_ps_ramaseeprom.h"
#include "TestProject_ps_ramdata.h"
#include "TestProject_ps_ramdata_no_init.h"
#include "TestProject_ps_tec_romdata.h"

SEGMENT_BEGIN(CONST_SEG, FAR_SEG, ps_headers)

ROM	PARAM_DATA_s	XHUGE	eCSWL_ECUID_FD14_ConfigurationVersion_descr =
{
1,	// U8
0,	// Dimension
0x0010,	// Flags
{ 15 },	// DataSize
(void *)&eCSWL_ECUID_FD14_ConfigurationVersion_data
};

ROM	PARAM_DATA_s	XHUGE	pCSWL_ECUID_FD07_Application_CS_descr =
{
5,	// U32
0,	// Dimension
0x00,	// Flags
{ 1 },
(void *)&pCSWL_ECUID_FD07_Application_CS_data
};

ROM	PARAM_DATA_s	XHUGE	pCSWL_ECUID_FD06_Application_CS_precalc_descr =
{
5,	// U32
0,	// Dimension
0x00,	// Flags
{ 1 },
(void *)&pCSWL_ECUID_FD06_Application_CS_precalc_data
};

ROM	PARAM_DATA_s	XHUGE	qCSWL_UDS_TestTable_descr =
{
3,	// U16
0,	// Dimension
0x2C,	// Flags
{ 4 },
(void *)&qCSWL_UDS_TestTable_data
};

ROM	PARAM_DATA_s	XHUGE	qCSWL_UDS_TestU32_descr =
{
5,	// U32
0,	// Dimension
0x06,	// Flags
{ 1 },
(void *)&qCSWL_UDS_TestU32_data
};

#define	rgCSWL_BlackBox_DATASIZE \
4 /* eCSWL_BlackBox_Worktime, selected indexes: 1 */ + \
4 /* eCSWL_BlackBox_Overvoltage_Dur, selected indexes: 1 */ + \
4 /* eCSWL_BlackBox_Overtemperature_Dur, selected indexes: 1 */ + \
4 /* eCSWL_BlackBox_Odometer, selected indexes: 1 */ + \
4 /* eCSWL_BlackBox_Fault_Dur, selected indexes: 1 */ + \
1 /* eCSWL_ECUID_FD15_VMEOL_Ready, selected indexes: 1 */ + \
1 /* eCSWL_UDS_CDTCS_state, selected indexes: 1 */ + \
1 /* eCSWL_EEPROM_stub, selected indexes: 1 */ + \
1 /* eCSWL_EEPROM_stub, selected indexes: 1 */ + \
1 /* pCSWL_MonOS_MCU_ResetCnt, selected indexes: 1 */ + \
1 /* pCSWL_DO_ShortsCnt, selected indexes: 1 */ + \
1 /* pCSWL_FO_ShortsCnt, selected indexes: 1 */ + \
1 /* pCSWL_DO_Protection_MissionRestarts_cnt, selected indexes: 1 */ + \
1 /* pCSWL_FO_Protection_MissionRestarts_cnt, selected indexes: 1 */ + \
1 /* pCSWL_DO_Protection_AfterSales_cnt, selected indexes: 1 */ + \
1 /* pCSWL_FO_Protection_AfterSales_cnt, selected indexes: 1 */

ROM	PLIST_DATA	XHUGE	rgCSWL_BlackBox_descr =
{
16,
rgCSWL_BlackBox_DATASIZE,
(void *)&rgCSWL_BlackBox_data
};

#define	rgCSWL_ECUID_CheckSums_DATASIZE \
4 /* pCSWL_ECUID_FD06_Application_CS_precalc, selected indexes: 1 */ + \
4 /* pCSWL_ECUID_FD07_Application_CS, selected indexes: 1 */ + \
4 /* pCSWL_ECUID_FD0A_Bootloader_CS_precalc, selected indexes: 1 */ + \
4 /* pCSWL_ECUID_FD0B_Bootloader_CS, selected indexes: 1 */ + \
4 /* pCSWL_ECUID_FD0E_Calibration_CS_precalc, selected indexes: 1 */ + \
4 /* pCSWL_ECUID_FD0F_Calibration_CS, selected indexes: 1 */ + \
4 /* pCSWL_ECUID_ROM_CS_precalc, selected indexes: 1 */ + \
4 /* pCSWL_ECUID_ROM_CS, selected indexes: 1 */

ROM	PLIST_DATA	XHUGE	rgCSWL_ECUID_CheckSums_descr =
{
8,
rgCSWL_ECUID_CheckSums_DATASIZE,
(void *)&rgCSWL_ECUID_CheckSums_data
};

#define	rgCSWL_ECUID_VMCF_Read_DATASIZE \
4 /* eCSWL_ECUID_FD12_Configuration_CS_precalc, selected indexes: 1 */ + \
4 /* pCSWL_ECUID_FD13_Configuration_CS, selected indexes: 1 */ + \
15 /* eCSWL_ECUID_FD14_ConfigurationVersion, selected indexes: 1 */ + \
1 /* eCSWL_ECUID_FD15_VMEOL_Ready, selected indexes: 1 */ + \
1 /* pCSWL_BRDC_Protection_AfterSalesClear_Write, selected indexes: 1 */ + \
1 /* pCSWL_BRDC_Protection_ReplaceECU, selected indexes: 1 */

ROM	PLIST_DATA	XHUGE	rgCSWL_ECUID_VMCF_Read_descr =
{
6,
rgCSWL_ECUID_VMCF_Read_DATASIZE,
(void *)&rgCSWL_ECUID_VMCF_Read_data
};

#define	rgCSWL_ECUID_VMCF_Write_DATASIZE \
4 /* eCSWL_ECUID_FD12_Configuration_CS_precalc, selected indexes: 1 */ + \
1 /* eCSWL_EEPROM_stub, selected indexes: 1 */ + \
15 /* eCSWL_ECUID_FD14_ConfigurationVersion, selected indexes: 1 */ + \
1 /* pCSWL_ECUID_FD15_VMEOL_srvWrite, selected indexes: 1 */ + \
1 /* pCSWL_BRDC_Protection_AfterSalesClear_Write, selected indexes: 1 */ + \
1 /* eCSWL_EEPROM_stub, selected indexes: 1 */

ROM	PLIST_DATA	XHUGE	rgCSWL_ECUID_VMCF_Write_descr =
{
6,
rgCSWL_ECUID_VMCF_Write_DATASIZE,
(void *)&rgCSWL_ECUID_VMCF_Write_data
};

#define	rgCSWL_UDS_TestData_DATASIZE \
4 /* qCSWL_UDS_TestTable, selected indexes: 2 */ + \
4 /* qCSWL_UDS_TestU32, selected indexes: 1 */

ROM	PLIST_DATA	XHUGE	rgCSWL_UDS_TestData_descr =
{
3,
rgCSWL_UDS_TestData_DATASIZE,
(void *)&rgCSWL_UDS_TestData_data
};

ROM	COMMONDIAGLISTITEM	XHUGE	CSWL_theCommonDiagList_data[38] =
{
{ (S32)&eCSWL_BlackBox_Worktime_data, sizeof(eCSWL_BlackBox_Worktime_data) }, 
{ (S32)&eCSWL_BlackBox_Overvoltage_Dur_data, sizeof(eCSWL_BlackBox_Overvoltage_Dur_data) }, 
{ (S32)&eCSWL_BlackBox_Overtemperature_Dur_data, sizeof(eCSWL_BlackBox_Overtemperature_Dur_data) }, 
{ (S32)&eCSWL_BlackBox_Odometer_data, sizeof(eCSWL_BlackBox_Odometer_data) }, 
{ (S32)&eCSWL_EEPROM_stub_data, sizeof(eCSWL_EEPROM_stub_data) }, 
{ (S32)&eCSWL_ECUID_FD14_ConfigurationVersion_data, sizeof(eCSWL_ECUID_FD14_ConfigurationVersion_data) }, 
{ (S32)&eCSWL_ECUID_FD12_Configuration_CS_precalc_data, sizeof(eCSWL_ECUID_FD12_Configuration_CS_precalc_data) }, 
{ (S32)&eCSWL_ECUID_FD15_VMEOL_Ready_data, sizeof(eCSWL_ECUID_FD15_VMEOL_Ready_data) }, 
{ (S32)&pCSWL_UDS_WDBI_Flag_data[0], sizeof(pCSWL_UDS_WDBI_Flag_data[0]) * 1 }, 
{ (S32)&pCSWL_ECUID_FD07_Application_CS_data, sizeof(pCSWL_ECUID_FD07_Application_CS_data) }, 
{ (S32)&pCSWL_ECUID_FD06_Application_CS_precalc_data, sizeof(pCSWL_ECUID_FD06_Application_CS_precalc_data) }, 
{ (S32)&pCSWL_ECUID_FD0B_Bootloader_CS_data, sizeof(pCSWL_ECUID_FD0B_Bootloader_CS_data) }, 
{ (S32)&pCSWL_ECUID_FD0A_Bootloader_CS_precalc_data, sizeof(pCSWL_ECUID_FD0A_Bootloader_CS_precalc_data) }, 
{ (S32)&pCSWL_ECUID_stub_data, sizeof(pCSWL_ECUID_stub_data) }, 
{ (S32)&pCSWL_ECUID_FD0F_Calibration_CS_data, sizeof(pCSWL_ECUID_FD0F_Calibration_CS_data) }, 
{ (S32)&pCSWL_ECUID_FD0E_Calibration_CS_precalc_data, sizeof(pCSWL_ECUID_FD0E_Calibration_CS_precalc_data) }, 
{ (S32)&pCSWL_Stub_data, sizeof(pCSWL_Stub_data) }, 
{ (S32)&pCSWL_ECUID_FD15_VMEOL_srvWrite_data, sizeof(pCSWL_ECUID_FD15_VMEOL_srvWrite_data) }, 
{ (S32)&qCSWL_UDS_TestTable_data[0], sizeof(qCSWL_UDS_TestTable_data[0]) * 1 }, 
{ (S32)&qCSWL_UDS_TestTable_data[1], sizeof(qCSWL_UDS_TestTable_data[1]) * 1 }, 
{ (S32)&qCSWL_UDS_TestTable_data[1], sizeof(qCSWL_UDS_TestTable_data[1]) * 1 }, 
{ (S32)&qCSWL_UDS_TestTable_data[1], sizeof(qCSWL_UDS_TestTable_data[1]) * 1 }, 
{ (S32)&qCSWL_UDS_TestU32_data, sizeof(qCSWL_UDS_TestU32_data) }, 
{ (S32)&pCSWL_DO_ShortsCnt_data, sizeof(pCSWL_DO_ShortsCnt_data) }, 
{ (S32)&pCSWL_FO_ShortsCnt_data, sizeof(pCSWL_FO_ShortsCnt_data) }, 
{ (S32)&pCSWL_ECUID_FD13_Configuration_CS_data, sizeof(pCSWL_ECUID_FD13_Configuration_CS_data) }, 
{ (S32)&pCSWL_MonOS_MCU_ResetCnt_data, sizeof(pCSWL_MonOS_MCU_ResetCnt_data) }, 
{ (S32)&eCSWL_BlackBox_Fault_Dur_data, sizeof(eCSWL_BlackBox_Fault_Dur_data) }, 
{ (S32)&pCSWL_DO_Protection_AfterSales_cnt_data, sizeof(pCSWL_DO_Protection_AfterSales_cnt_data) }, 
{ (S32)&pCSWL_DO_Protection_MissionRestarts_cnt_data, sizeof(pCSWL_DO_Protection_MissionRestarts_cnt_data) }, 
{ (S32)&pCSWL_FO_Protection_AfterSales_cnt_data, sizeof(pCSWL_FO_Protection_AfterSales_cnt_data) }, 
{ (S32)&pCSWL_FO_Protection_MissionRestarts_cnt_data, sizeof(pCSWL_FO_Protection_MissionRestarts_cnt_data) }, 
{ (S32)&pCSWL_BRDC_Protection_AfterSalesClear_Write_data, sizeof(pCSWL_BRDC_Protection_AfterSalesClear_Write_data) }, 
{ (S32)&pCSWL_BRDC_Protection_ReplaceECU_data, sizeof(pCSWL_BRDC_Protection_ReplaceECU_data) }, 
{ (S32)&eCSWL_UDS_CDTCS_state_data, sizeof(eCSWL_UDS_CDTCS_state_data) }, 
{ (S32)&pCSWL_UDS_CDTCS_state_data, sizeof(pCSWL_UDS_CDTCS_state_data) }, 
{ (S32)&pCSWL_ECUID_ROM_CS_data, sizeof(pCSWL_ECUID_ROM_CS_data) }, 
{ (S32)&pCSWL_ECUID_ROM_CS_precalc_data, sizeof(pCSWL_ECUID_ROM_CS_precalc_data) }
};

ROM	COMMONDIAGLIST	XHUGE	CSWL_theCommonDiagList_descr =
{
38,
(COMMONDIAGLISTITEM	XHUGE	*)CSWL_theCommonDiagList_data
};

ROM	PSHEADER	XHUGE	CSWL_PSH_ptr =
{
0x52444850,
0x0000,
0x0001,
"15.01.2015",
"30.06.2022",
11
};

ROM	U32	XHUGE	CSWL_PSRT_ptr[11] =
{
(S32)&eCSWL_ECUID_FD14_ConfigurationVersion_descr, (S32)&pCSWL_ECUID_FD07_Application_CS_descr, (S32)&pCSWL_ECUID_FD06_Application_CS_precalc_descr, (S32)&qCSWL_UDS_TestTable_descr, (S32)&qCSWL_UDS_TestU32_descr, 
(S32)&rgCSWL_BlackBox_descr, (S32)&rgCSWL_ECUID_CheckSums_descr, (S32)&rgCSWL_ECUID_VMCF_Read_descr, (S32)&rgCSWL_ECUID_VMCF_Write_descr, (S32)&rgCSWL_UDS_TestData_descr, 
(S32)&CSWL_theCommonDiagList_descr
};

SEGMENT_END(CONST_SEG, FAR_SEG, ps_headers)
