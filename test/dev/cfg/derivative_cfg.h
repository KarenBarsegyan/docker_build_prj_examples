//**************************************************************************************************
// @Module        MCU derivative description
// @Filename      derivative_cfg.h
//--------------------------------------------------------------------------------------------------
// @Description   Configuration of MCU derivative.
//--------------------------------------------------------------------------------------------------
// @Version       1.0.0
//--------------------------------------------------------------------------------------------------
// @Date          23.06.2022
//--------------------------------------------------------------------------------------------------
// @History       Version  Author      Comment
// 23.06.2022     1.0.0    KPS         First release.
//**************************************************************************************************

#ifndef DERIVATIVE_CFG_H
#define DERIVATIVE_CFG_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

#include "ytm32b1m_sfr.h"

#include "cortex_m33_core_sfr.h"

//#include "at32f43x_sfr.h"


//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

#define MCUID_FAM_STM32F4       (1U)
#define MCUID_FAM_GD32F4        (2U)
#define MCUID_FAM_APM32F4       (3U)
#define MCUID_FAM_AT32F4        (4U)
#define MCUID_FAM_YTM32B1M      (5U)

#define MCUID_SUBFAM_STM_401    (1U)
#define MCUID_SUBFAM_STM_405    (2U)
#define MCUID_SUBFAM_STM_407    (3U)
#define MCUID_SUBFAM_STM_410    (4U)
#define MCUID_SUBFAM_STM_411    (5U)
#define MCUID_SUBFAM_STM_412    (6U)
#define MCUID_SUBFAM_STM_413    (7U)
#define MCUID_SUBFAM_STM_415    (8U)
#define MCUID_SUBFAM_STM_417    (9U)
#define MCUID_SUBFAM_STM_423    (10U)
#define MCUID_SUBFAM_STM_427    (11U)
#define MCUID_SUBFAM_STM_429    (12U)
#define MCUID_SUBFAM_STM_437    (13U)
#define MCUID_SUBFAM_STM_439    (14U)
#define MCUID_SUBFAM_STM_446    (15U)
#define MCUID_SUBFAM_STM_469    (16U)
#define MCUID_SUBFAM_STM_479    (17U)

#define MCUID_SUBFAM_GD_405     (19U)
#define MCUID_SUBFAM_GD_407     (20U)
#define MCUID_SUBFAM_GD_450     (21U)

#define MCUID_SUBFAM_AMP_405     (22U)
#define MCUID_SUBFAM_AMP_407     (23U)
#define MCUID_SUBFAM_AMP_415     (24U)
#define MCUID_SUBFAM_AMP_417     (25U)

#define MCUID_SUBFAM_AT_435      (26U)
#define MCUID_SUBFAM_AT_437      (27U)

#define MCUID_SUBFAM_YTM_ME0     (28U)


// Specify MCU family identifier
// Valid values: MCUID_FAM_STM32F4, MCUID_FAM_GD32F4, MCUID_FAM_APM32F4, MCUID_FAM_AT32F4, MCUID_FAM_YTM32B1
#define MCUID_FAM                   (MCUID_FAM_YTM32B1M)

// Specify MCU subfamily identifier
// Valid values:
// MCUID_FAM_STM32F4: MCUID_SUBFAM_STM_401, MCUID_SUBFAM_STM_405, MCUID_SUBFAM_STM_407, MCUID_SUBFAM_STM_410,
//                    MCUID_SUBFAM_STM_411, MCUID_SUBFAM_STM_412, MCUID_SUBFAM_STM_413, MCUID_SUBFAM_STM_415,
//                    MCUID_SUBFAM_STM_417, MCUID_SUBFAM_STM_423, MCUID_SUBFAM_STM_427, MCUID_SUBFAM_STM_429,
//                    MCUID_SUBFAM_STM_437, MCUID_SUBFAM_STM_439, MCUID_SUBFAM_STM_446, MCUID_SUBFAM_STM_469,
//                    MCUID_SUBFAM_STM_479
//
// MCUID_FAM_GD32F4:  MCUID_SUBFAM_GD_405, MCUID_SUBFAM_GD_407, MCUID_SUBFAM_GD_450
//
// MCUID_FAM_AMP_32F4:  MCUID_SUBFAM_AMP_405, MCUID_SUBFAM_AMP_407, MCUID_SUBFAM_AMP_415, MCUID_SUBFAM_AMP_417
//
// MCUID_FAM_AT32F4:  MCUID_SUBFAM_AT_435, MCUID_SUBFAM_AT_437
//
// MCUID_FAM_YTM32B1: MCUID_SUBFAM_YTM_ME0

#define MCUID_SUBFAM               (MCUID_SUBFAM_YTM_ME0)



#endif // #ifndef DERIVATIVE_CFG_H

//****************************************** end of file *******************************************
