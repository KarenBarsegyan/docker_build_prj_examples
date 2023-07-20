// *****************************************************************************
// @Module	ps_ramaseeprom.c
// @Author	MSEpro Code Generator v.3.0.7145.22606 built at 25.07.2019 12:33:33
// @Description	Contains RAM copies of EEPROM variables
// *****************************************************************************

#include "TestProject_ps_ramaseeprom.h"

SEGMENT_BEGIN(DATA_SEG, NEAR_SEG, ps_ramaseeprom)

S32	NEAR	eSignature;
S32	NEAR	eIDent;
S32	NEAR	eCRCBank;

U16	NEAR	PS_RAMASEEPROM_END_ID;

SEGMENT_END(DATA_SEG, NEAR_SEG, ps_ramaseeprom)
