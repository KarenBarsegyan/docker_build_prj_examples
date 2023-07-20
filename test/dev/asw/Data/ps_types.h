// *****************************************************************************
// @Module	ps_types.h
// @Author	MSEpro Code Generator v.3.0.7145.22606 built at 25.07.2019 12:33:33
// @Description	Contains types and structures definitions for parameter variables
// *****************************************************************************

#ifndef __MSE_PS_TYPES_H__
#define __MSE_PS_TYPES_H__


// Include platform specific types
#include "platform.h"
#include "compiler.h"


#define	ROM	const


// Date Type

typedef	char	TPSDate[11];

// Paramset Header Definition

typedef	struct	tagPSHEADER
{
U32	pdSignature;
U16	psVMajor;
U16	psVMinor;
TPSDate	psDMajor;
TPSDate	psDMinor;
U32	PSRTItemCount;
} PSHEADER, *LPPSHEADER;

// Paramset Initialization List Definition

typedef struct tagPARAM_PSRTIL
{
U8	cPSRT;
LPPSHEADER	hdrs[1];
} PARAM_PSRTIL, *LPPARAM_PSRTIL;
// Parameter List Definition

typedef	struct	tagPLIST
{
U16	pdCount;
U16	pdSize;
void	*pData;	// Common Parameter List Index Table
} PLIST_DATA, *LPPLIST_DATA;

// Common Parameter List Item Definition

typedef	struct	tagCOMMONDIAGLISTITEM
{
U32	pdAddr;	// Parameter Data
U8	pdSize;	// Parameter Data Size
} COMMONDIAGLISTITEM;

// Common Parameter List Definition

typedef	struct	tagCOMMONDIAGLIST
{
U16	pdCount;	// List item count
COMMONDIAGLISTITEM	*pdItems;
} COMMONDIAGLIST;

// Read Only Axis Definition

typedef	struct	tagCV_DATA
{
U8	pdType;
void	*pdIBuffer;
U16	pdCDelta;
U16	pdCLastIdx;
void	*pdVBuffer;
void	*pCData;
void	*pdIdxData;
} CV_DATA, *LPCV_DATA;

// Axis Definition

typedef	struct	tagCV_DATA_c
{
U8	pdType;
void	*pdIBuffer;
U16	pdCDelta;
U16	pdCLastIdx;
void	*pdVBuffer;
void	*pCData;
} CV_DATA_c, *LPCV_DATA_c;

// Scalar Parameter Definition

typedef	struct	tagPARAM_DATA_s
{
U8	pdType;
U8	UNALIGNED	pdDimension;
U8	UNALIGNED	pdFlags;	// 0x01 - EA, 0x02 - DA, 0x04 - ROM, 0x08 - Indexed, 0x10 - String, 0x20 - Implicitly Indexed
U16	pdSize[1];
void	*pData;
} PARAM_DATA_s, *LPPARAM_DATA_s;

// External Access Scalar Parameter Definition

typedef	struct	tagPARAM_DATA_EA_s
{
U8	pdType;
U8	UNALIGNED	pdDimension;
U8	UNALIGNED	pdFlags;	// 0x01 - EA, 0x02 - DA, 0x04 - ROM, 0x08 - Indexed, 0x10 - String, 0x20 - Implicitly Indexed
U16	pdSize[1];
void	*pData;
void	*pExtData;
void	*pKeyData;
} PARAM_DATA_EA_s, *LPPARAM_DATA_EA_s;

// EEPROM Scalar Parameter Definition

typedef	struct	tagPARAM_EEPROM_s
{
U8	pdType;
U8	UNALIGNED	pdDimension;
U8	UNALIGNED	pdFlags;	// 0x01 - EA, 0x02 - DA, 0x04 - ROM, 0x08 - Indexed, 0x10 - String, 0x20 - Implicitly Indexed
U16	pdSize[1];
void	*pData;
void	*pCRC;
} PARAM_EEPROM_s, *LPPARAM_EEPROM_s;

// Vector Parameter Definition

typedef	struct	tagPARAM_DATA_v
{
U8	pdType;
U8	UNALIGNED	pdDimension;
U8	UNALIGNED	pdFlags;	// 0x01 - EA, 0x02 - DA, 0x04 - ROM, 0x08 - Indexed, 0x10 - String, 0x20 - Implicitly Indexed
U16	pdSize[2];
void	*pCVector[1];
void	*pData;
} PARAM_DATA_v, *LPPARAM_DATA_v;

// EEPROM Vector Parameter Definition

typedef	struct	tagPARAM_EEPROM_v
{
U8	pdType;
U8	UNALIGNED	pdDimension;
U8	UNALIGNED	pdFlags;	// 0x01 - EA, 0x02 - DA, 0x04 - ROM, 0x08 - Indexed, 0x10 - String, 0x20 - Implicitly Indexed
U16	pdSize[2];
void	*pCVector[1];
void	*pData;
void	*pCRC;
} PARAM_EEPROM_v, *LPPARAM_EEPROM_v;

// Table Parameter Definition

typedef	struct	tagPARAM_DATA_t
{
U8	pdType;
U8	UNALIGNED	pdDimension;
U8	UNALIGNED	pdFlags;	// 0x01 - EA, 0x02 - DA, 0x04 - ROM, 0x08 - Indexed, 0x10 - String, 0x20 - Implicitly Indexed
U16	pdSize[3];
void	*pCVector[2];
void	*pData;
} PARAM_DATA_t, *LPPARAM_DATA_t;

// EEPROM Table Parameter Definition

typedef	struct	tagPARAM_EEPROM_t
{
U8	pdType;
U8	UNALIGNED	pdDimension;
U8	UNALIGNED	pdFlags;	// 0x01 - EA, 0x02 - DA, 0x04 - ROM, 0x08 - Indexed, 0x10 - String, 0x20 - Implicitly Indexed
U16	pdSize[3];
void	*pCVector[2];
void	*pData;
void	*pCRC;
} PARAM_EEPROM_t, *LPPARAM_EEPROM_t;

#endif // __MSE_PS_TYPES_H__
