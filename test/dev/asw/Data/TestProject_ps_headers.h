// *****************************************************************************
// @Module	ps_headers.h
// @Author	MSEpro Code Generator v.3.0.7145.22606 built at 25.07.2019 12:33:33
// @Description	Contains exports for paramset data definitions
// *****************************************************************************

#ifndef __MSE_PS_HEADERS_H__
#define __MSE_PS_HEADERS_H__

#include "ps_types.h"

extern	ROM	COMMONDIAGLISTITEM	XHUGE	CSWL_theCommonDiagList_data[38];

extern	ROM	COMMONDIAGLIST	XHUGE	CSWL_theCommonDiagList_descr;

extern	ROM	PSHEADER	XHUGE	CSWL_PSH_ptr;

extern	ROM	U32	XHUGE	CSWL_PSRT_ptr[11];

#define	DATA_eCSWL_ECUID_FD14_ConfigurationVersion	0

#define	DATA_pCSWL_ECUID_FD07_Application_CS	1

#define	DATA_pCSWL_ECUID_FD06_Application_CS_precalc	2

#define	DATA_qCSWL_UDS_TestTable	3

#define	DATA_qCSWL_UDS_TestU32	4

#define	PLIST_rgCSWL_BlackBox	5

#define	PLIST_rgCSWL_ECUID_CheckSums	6

#define	PLIST_rgCSWL_ECUID_VMCF_Read	7

#define	PLIST_rgCSWL_ECUID_VMCF_Write	8

#define	PLIST_rgCSWL_UDS_TestData	9

#define	CLIST_theCommonDiagList	10

#endif // __MSE_PS_HEADERS_H__
