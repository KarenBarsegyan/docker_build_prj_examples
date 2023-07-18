//**************************************************************************************************
// @Module        Error Tracer
// @Filename      error_tracer.c
//--------------------------------------------------------------------------------------------------
// @Platform      Independent
//--------------------------------------------------------------------------------------------------
// @Compatible    Independent
//--------------------------------------------------------------------------------------------------
// @Description   Implementation of the Error Tracer functionality.
//
//                Abbreviations:
//                  ET - Error Tracer
//
//                Global (public) functions:
//                  ET_ReportDevelopmentError()
//                  ET_ReportRuntimeError()
//                  ET_GetRuntimeErrorsQty()
//                  ET_GetRuntimeError()
//                  ET_GetDevelopmentErrorsQty()
//                  ET_GetDevelopmentError()
//
//                Local (private) functions:
//                  None.
//
//--------------------------------------------------------------------------------------------------
// @Version       0.3.0
//--------------------------------------------------------------------------------------------------
// @Date          24.08.2018
//--------------------------------------------------------------------------------------------------
// @History       Version  Author      Comment
// 07.09.2015     0.2.0    SRM         Pre-release.
// 24.08.2018     0.3.0    SHA         Added functions  ET_GetRuntimeErrorsQty(),
//                                     ET_GetRuntimeError(), ET_GetDevelopmentErrorsQty(),
//                                     ET_GetDevelopmentError()
//**************************************************************************************************



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Native header
#include "error_tracer.h"



//**************************************************************************************************
// Verification of the imported configuration parameters
//**************************************************************************************************

// None.



//**************************************************************************************************
// Definitions of global (public) variables
//**************************************************************************************************

// None.



//**************************************************************************************************
// Declarations of local (private) data types
//**************************************************************************************************

// Traceable error object
typedef struct ET_ERROR_str
{
    U8 strSWModuleID[ET_MODULE_ID_SYMBOLS_QTY];
    U8 nObjectID;
    U8 nAPIID;
    U8 nErrorID;

} ET_ERROR;



//**************************************************************************************************
// Definitions of local (private) constants
//**************************************************************************************************

// Offset for AP ID store
#define ET_AP_ID_OFFSET         (1U)

// Offset for ERROR ID store
#define ET_ERROR_ID_OFFSET      (2U)



//**************************************************************************************************
// Definitions of static global (private) variables
//**************************************************************************************************

// Warning! "static" keyword has been intentionally removed!

// Flag indicating active development errors
BOOLEAN ET_bDevErrosActive;
// Current development errors quantity
volatile U16 ET_nDevErrorsQty;
// Buffer to store development errors
volatile ET_ERROR ET_DevErrorsBuffer[ET_DEV_ERRORS_BUFFER_SIZE];

// Flag indicating active runtime errors
BOOLEAN ET_bRTErrosActive;
// Current runtime errors quantity
volatile U16 ET_nRTErrorsQty;
// Buffer to store runtime errors
volatile ET_ERROR ET_RTErrorsBuffer[ET_RT_ERRORS_BUFFER_SIZE];



//**************************************************************************************************
// Declarations of local (private) functions
//**************************************************************************************************

// None.



//**************************************************************************************************
//==================================================================================================
// Definitions of global (public) functions
//==================================================================================================
//**************************************************************************************************



//**************************************************************************************************
// @Function      ET_ReportDevelopmentError()
//--------------------------------------------------------------------------------------------------
// @Description   Traces development error.
//--------------------------------------------------------------------------------------------------
// @Notes         None.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    pModuleID     - pointer to SW module ID string
//                nModuleIDSize - SW module ID string length in symbols
//                nObjectID     - SW module object ID
//                nAPIID        - SW module API ID
//                nErrorID      - SW module error ID
//**************************************************************************************************
void ET_ReportDevelopmentError(const U8* const pModuleID,
                               const U8  nModuleIDSize,
                               const U8  nObjectID,
                               const U8  nAPIID,
                               const U8  nErrorID)
{
    if (ET_nDevErrorsQty < ET_DEV_ERRORS_BUFFER_SIZE)
    {
        U8 nModuleIDSymbolsToCopy = nModuleIDSize;
        U8 nSymbolNumber   = 0U;
        U8 nNewErrorNumber = 0U;

        // Reserve error buffer cell
        ET_nDevErrorsQty++;
        nNewErrorNumber = ET_nDevErrorsQty - 1U;

        // Limit module ID string length
        if (nModuleIDSize > ET_MODULE_ID_SYMBOLS_QTY)
        {
            nModuleIDSymbolsToCopy = ET_MODULE_ID_SYMBOLS_QTY;
        }

        for (nSymbolNumber = 0U;
             nSymbolNumber < nModuleIDSymbolsToCopy;
             nSymbolNumber++)
        {
            ET_DevErrorsBuffer[nNewErrorNumber].strSWModuleID[nSymbolNumber] = 
                pModuleID[nSymbolNumber];
        }

        ET_DevErrorsBuffer[nNewErrorNumber].nObjectID = nObjectID;
        ET_DevErrorsBuffer[nNewErrorNumber].nAPIID    = nAPIID;
        ET_DevErrorsBuffer[nNewErrorNumber].nErrorID  = nErrorID;
        
        ET_bDevErrosActive = TRUE;
    }
    else
    {
        // Error buffer is full
        DoNothing();
    }

} // end of ET_ReportDevelopmentError()



//**************************************************************************************************
// @Function      ET_ReportRuntimeError()
//--------------------------------------------------------------------------------------------------
// @Description   Traces runtime error.
//--------------------------------------------------------------------------------------------------
// @Notes         None.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    pModuleID     - pointer to SW module ID string
//                nModuleIDSize - SW module ID string length in symbols
//                nObjectID     - SW module object ID
//                nAPIID        - SW module API ID
//                nErrorID      - SW module error ID
//**************************************************************************************************
void ET_ReportRuntimeError(const U8* const pModuleID,
                           const U8  nModuleIDSize,
                           const U8  nObjectID,
                           const U8  nAPIID,
                           const U8  nErrorID)
{
    if (ET_nRTErrorsQty < ET_RT_ERRORS_BUFFER_SIZE)
    {
        U8 nModuleIDSymbolsToCopy = nModuleIDSize;
        U8 nSymbolNumber   = 0U;
        U8 nNewErrorNumber = 0U;

        // Reserve error buffer cell
        ET_nRTErrorsQty++;
        nNewErrorNumber = ET_nRTErrorsQty - 1U;

        // Limit module ID string length
        if (nModuleIDSize > ET_MODULE_ID_SYMBOLS_QTY)
        {
            nModuleIDSymbolsToCopy = ET_MODULE_ID_SYMBOLS_QTY;
        }

        for (nSymbolNumber = 0U;
             nSymbolNumber < nModuleIDSymbolsToCopy;
             nSymbolNumber++)
        {
            ET_RTErrorsBuffer[nNewErrorNumber].strSWModuleID[nSymbolNumber] = 
                pModuleID[nSymbolNumber];
        }

        ET_RTErrorsBuffer[nNewErrorNumber].nObjectID = nObjectID;
        ET_RTErrorsBuffer[nNewErrorNumber].nAPIID    = nAPIID;
        ET_RTErrorsBuffer[nNewErrorNumber].nErrorID  = nErrorID;
        
        ET_bRTErrosActive = TRUE;
    }
    else
    {
        // Error buffer is full
        DoNothing();
    }

} // end of ET_ReportRuntimeError()



//**************************************************************************************************
// @Function      ET_GetRuntimeErrorsQty()
//--------------------------------------------------------------------------------------------------
// @Description   Read of current runtime errors quantity.
//--------------------------------------------------------------------------------------------------
// @Notes         None.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   Current runtime errors quantity.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
U16 ET_GetRuntimeErrorsQty(void)
{
    return ET_nRTErrorsQty;

} // End of function ET_GetRuntimeErrorsQty()



//**************************************************************************************************
// @Function      ET_GetRuntimeError()
//--------------------------------------------------------------------------------------------------
// @Description   Read of buffer to store runtime errors.
//--------------------------------------------------------------------------------------------------
// @Notes         None.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   Current runtime errors quantity.
//--------------------------------------------------------------------------------------------------
// @Parameters    nErrorNumber - number of error
//                pBuffer      - pointer to error structure
//**************************************************************************************************
STD_RESULT ET_GetRuntimeError(const U8  nErrorNumber,
                              U8* const pBuffer)
{
    STD_RESULT nFuncResult = RESULT_OK;

    if (nErrorNumber < ET_RT_ERRORS_BUFFER_SIZE)
    {
        if (pBuffer != NULL_PTR)
        {
            U8 nByteCnt;
            for (nByteCnt = 0U; nByteCnt < ET_MODULE_ID_SYMBOLS_QTY; nByteCnt++)
            {
                pBuffer[nByteCnt] = ET_RTErrorsBuffer[nErrorNumber].strSWModuleID[nByteCnt];
            }
            pBuffer[ET_MODULE_ID_SYMBOLS_QTY] = ET_RTErrorsBuffer[nErrorNumber].nObjectID;
            pBuffer[ET_MODULE_ID_SYMBOLS_QTY + ET_AP_ID_OFFSET] =
                                                ET_RTErrorsBuffer[nErrorNumber].nAPIID;
            pBuffer[ET_MODULE_ID_SYMBOLS_QTY + ET_ERROR_ID_OFFSET] =
                                                ET_RTErrorsBuffer[nErrorNumber].nErrorID;
        }
        else
        {
            nFuncResult = RESULT_NOT_OK;
        }
    }
    else
    {
        nFuncResult = RESULT_NOT_OK;
    }

    return nFuncResult;

} // End of function ET_GetRuntimeError()



//**************************************************************************************************
// @Function      ET_GetDevelopmentErrorsQty()
//--------------------------------------------------------------------------------------------------
// @Description   Read of current development errors quantity.
//--------------------------------------------------------------------------------------------------
// @Notes         None.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   Current runtime errors quantity.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
U16 ET_GetDevelopmentErrorsQty(void)
{
    return ET_nDevErrorsQty;

} // End of function ET_GetDevelopmentErrorsQty()



//**************************************************************************************************
// @Function      ET_GetRuntimeError()
//--------------------------------------------------------------------------------------------------
// @Description   Read of buffer to store runtime errors.
//--------------------------------------------------------------------------------------------------
// @Notes         None.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   Current runtime errors quantity.
//--------------------------------------------------------------------------------------------------
// @Parameters    nErrorNumber - number of error
//                pBuffer      - pointer to error structure
//**************************************************************************************************
STD_RESULT ET_GetDevelopmentError(const U8  nErrorNumber,
                                  U8* const pBuffer)
{
    STD_RESULT nFuncResult = RESULT_OK;

    if (nErrorNumber < ET_DEV_ERRORS_BUFFER_SIZE)
    {
        if (pBuffer != NULL_PTR)
        {
            U8 nByteCnt;
            for (nByteCnt = 0U; nByteCnt < ET_MODULE_ID_SYMBOLS_QTY; nByteCnt++)
            {
                pBuffer[nByteCnt] = ET_DevErrorsBuffer[nErrorNumber].strSWModuleID[nByteCnt];
            }
            pBuffer[ET_MODULE_ID_SYMBOLS_QTY] = ET_DevErrorsBuffer[nErrorNumber].nObjectID;
            pBuffer[ET_MODULE_ID_SYMBOLS_QTY + ET_AP_ID_OFFSET] =
                                                ET_DevErrorsBuffer[nErrorNumber].nAPIID;
            pBuffer[ET_MODULE_ID_SYMBOLS_QTY + ET_ERROR_ID_OFFSET] =
                                                ET_DevErrorsBuffer[nErrorNumber].nErrorID;
        }
        else
        {
            nFuncResult = RESULT_NOT_OK;
        }
    }
    else
    {
        nFuncResult = RESULT_NOT_OK;
    }

    return nFuncResult;

} // End of function ET_GetDevelopmentError()



//**************************************************************************************************
//==================================================================================================
// Definitions of local (private) functions
//==================================================================================================
//**************************************************************************************************



// None.



//****************************************** end of file *******************************************
