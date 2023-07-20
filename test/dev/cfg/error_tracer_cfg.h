//**************************************************************************************************
// @Module        Error Tracer
// @Filename      error_tracer_cfg.h
//--------------------------------------------------------------------------------------------------
// @Description   Configuration of the required functionality of the Error Tracer.
//--------------------------------------------------------------------------------------------------
// @Version       0.0.1
//--------------------------------------------------------------------------------------------------
// @Date          18.08.2015
//--------------------------------------------------------------------------------------------------
// @History       Version  Author      Comment
// 18.08.2015     0.0.1    SRM         Pre-release.
//**************************************************************************************************

#ifndef ERROR_TRACER_CFG_H
#define ERROR_TRACER_CFG_H



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

// Specify size of the development errors buffer
#define ET_DEV_ERRORS_BUFFER_SIZE      (50U)

// Specify size of the runtime errors buffer
#define ET_RT_ERRORS_BUFFER_SIZE       (10U)

// Specify a number of symbols in SW module ID
#define ET_MODULE_ID_SYMBOLS_QTY    (4U)



#endif // #ifndef ERROR_TRACER_CFG_H

//****************************************** end of file *******************************************
