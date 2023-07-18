//**************************************************************************************************
// @Module        Error Tracer
// @Filename      error_tracer.h
//--------------------------------------------------------------------------------------------------
// @Description   Interface of the Error Tracer module.
//--------------------------------------------------------------------------------------------------
// @Version       0.1.1
//--------------------------------------------------------------------------------------------------
// @Date          15.03.2016
//--------------------------------------------------------------------------------------------------
// @History       Version  Author      Comment
// 15.03.2016     0.1.1    SRM         Pre-release.
//**************************************************************************************************

#ifndef ERROR_TRACER_H
#define ERROR_TRACER_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Get data types
#include "error_tracer_cfg.h"
#include "compiler.h"
#include "general.h"



//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************

// None.



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

// Use this constant during error report to specify that corrected object ID can not be reported
#define ET_OBJECT_NUMBER_UNKNOWN    (0xFFU)



//**************************************************************************************************
// Declarations of global (public) variables
//**************************************************************************************************

// None.



//**************************************************************************************************
// Declarations of global (public) functions
//**************************************************************************************************

// Traces development error
extern void ET_ReportDevelopmentError(const U8* const pModuleID,
                                      const U8  nModuleIDSize,
                                      const U8  nObjectID,
                                      const U8  nAPIID,
                                      const U8  nErrorID);

// Traces runtime error
extern void ET_ReportRuntimeError(const U8* const pModuleID,
                                  const U8  nModuleIDSize,
                                  const U8  nObjectID,
                                  const U8  nAPIID,
                                  const U8  nErrorID);

// Read of current runtime errors quantity
extern U16 ET_GetRuntimeErrorsQty(void);

// Read of buffer to store runtime errors
extern STD_RESULT ET_GetRuntimeError(const U8  nErrorNumber,
                                     U8* const pBuffer);

// Read of current development errors quantity
extern U16 ET_GetDevelopmentErrorsQty(void);

// Read of buffer to store runtime errors
extern STD_RESULT ET_GetDevelopmentError(const U8  nErrorNumber,
                                         U8* const pBuffer);



#endif // #ifndef ERROR_TRACER_H

//****************************************** end of file *******************************************
