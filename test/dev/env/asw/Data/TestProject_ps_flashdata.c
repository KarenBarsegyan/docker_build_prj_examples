// *****************************************************************************
// @Module	ps_flashdata.c
// @Author	MSEpro Code Generator v.3.0.7145.22606 built at 25.07.2019 12:33:33
// @Description	Contains variables of ROM parameters
// *****************************************************************************

#include "TestProject_ps_flashdata.h"



ROM	U16	XHUGE	PS_FLASHDATA_START_ID = (U16)0x0000;

ROM	U16	XHUGE	rgCSWL_BlackBox_data[16] =
{
0x0000, 0x0001, 0x0002, 0x0003, 0x001B, 0x0007, 0x0022, 
0x0004, 0x0004, 0x001A, 0x0017, 0x0018, 0x001D, 0x001F, 
0x001C, 0x001E
};

ROM	U16	XHUGE	rgCSWL_ECUID_CheckSums_data[8] =
{
0x000A, 0x0009, 0x000C, 0x000B, 0x000F, 0x000E, 0x0025, 
0x0024
};

ROM	U16	XHUGE	rgCSWL_ECUID_VMCF_Read_data[6] =
{
0x0006, 0x0019, 0x0005, 0x0007, 0x0020, 0x0021
};

ROM	U16	XHUGE	rgCSWL_ECUID_VMCF_Write_data[6] =
{
0x0006, 0x0004, 0x0005, 0x0011, 0x0020, 0x0004
};

ROM	U16	XHUGE	rgCSWL_UDS_TestData_data[3] =
{
0x0012, 0x0013, 0x0016
};

ROM	U16	XHUGE	qCSWL_UDS_TestTable_data[4] =
{
0x4142, 0x4344, 0x4546, 0x4748
};

ROM	U32	XHUGE	qCSWL_UDS_TestU32_data = 0x6768696A;

ROM	U8	XHUGE	PS_FLASHDATA_END_ID = (U8)0x00;


