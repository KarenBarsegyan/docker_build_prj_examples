//**************************************************************************************************
// @Module  SPI driver
//! \file   spi_drv_cfg.c
//! \par    Platform
//!             YTM32
//! \par    Compatible
//!             YTM32B1M families
//! \brief  Implementation of the SPI driver configuration
//!
//! \par    Abbreviations
//!             MCU - MicroController Unit
//!             SPI - Serial Peripheral Interface
//! \par    History
//! | Date       | Version | Author  | Comment
//! |:----------:|:-------:|:-------:|--------------------------------------------------------------
//! | 00.00.2023 |  1.0.0  |   BKR   | First release.
//**************************************************************************************************



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Native header
#include "spi_drv.h"

// Get program module specific types
#include "spi_drv_types.h"

// HC32F4A registers
#include "derivative_cfg.h"



//**************************************************************************************************
// Verification of the imported configuration parameters
//**************************************************************************************************

//--------------------------------------------------------------------------------------------------
//-------------------------------------------- SPI0 ------------------------------------------------
//--------------------------------------------------------------------------------------------------

#if (ON == SPI_CHANNEL_0_IN_USE)
    #if (SPI_CHANNEL_0_MODE != SPI_MODE_MASTER && \
         SPI_CHANNEL_0_MODE != SPI_MODE_SLAVE)
        #error "SPI_CHANNEL_0_MODE configuration value is not valid!"
    #endif

    #if (SPI_CHANNEL_0_BAUDRATE < SPI_MIN_BAUDRATE || \
         SPI_CHANNEL_0_BAUDRATE > SPI_MAX_BAUDRATE)
        #error "SPI_CHANNEL_0_BAUDRATE configuration value is not valid!"
    #endif

    #if (SPI_CHANNEL_0_MOSI_PORT != SPI_PORT_A && \
         SPI_CHANNEL_0_MOSI_PORT != SPI_PORT_B && \
         SPI_CHANNEL_0_MOSI_PORT != SPI_PORT_E)
        #error "SPI_CHANNEL_0_MOSI_PORT configuration value is not valid!"
    #endif

    #if (SPI_CHANNEL_0_MISO_PORT != SPI_PORT_B && \
         SPI_CHANNEL_0_MISO_PORT != SPI_PORT_D && \
         SPI_CHANNEL_0_MISO_PORT != SPI_PORT_E)
        #error "SPI_CHANNEL_0_MOSI_PORT configuration value is not valid!"
    #endif
    
    #if (SPI_CHANNEL_0_SCLK_PORT != SPI_PORT_B && \
         SPI_CHANNEL_0_SCLK_PORT != SPI_PORT_C && \
         SPI_CHANNEL_0_SCLK_PORT != SPI_PORT_D && \
         SPI_CHANNEL_0_SCLK_PORT != SPI_PORT_E)
        #error "SPI_CHANNEL_0_MOSI_PORT configuration value is not valid!"
    #endif

    #if (ON == SPI_CHANNEL_0_CS_0_IN_USE)
        #if (SPI_CHANNEL_0_CS_0_PORT != SPI_PORT_A && \
            SPI_CHANNEL_0_CS_0_PORT != SPI_PORT_B)
            #error "SPI_CHANNEL_0_MOSI_PORT configuration value is not valid!"
        #endif
    #endif

    #if (ON == SPI_CHANNEL_0_CS_1_IN_USE)
        #if (SPI_CHANNEL_0_CS_1_PORT != SPI_PORT_A && \
            SPI_CHANNEL_0_CS_1_PORT != SPI_PORT_B)
            #error "SPI_CHANNEL_0_MOSI_PORT configuration value is not valid!"
        #endif
    #endif

    #if (ON == SPI_CHANNEL_0_CS_2_IN_USE)
        #if (SPI_CHANNEL_0_CS_2_PORT != SPI_PORT_E)
            #error "SPI_CHANNEL_0_MOSI_PORT configuration value is not valid!"
        #endif
    #endif

    #if (ON == SPI_CHANNEL_0_CS_3_IN_USE)
        #if (SPI_CHANNEL_0_CS_3_PORT != SPI_PORT_A)
            #error "SPI_CHANNEL_0_MOSI_PORT configuration value is not valid!"
        #endif
    #endif  

#endif

//**************************************************************************************************
// Definitions of global (public) variables
//**************************************************************************************************

// None.



//**************************************************************************************************
// Declarations of local (private) data types
//**************************************************************************************************

// None.

 

//**************************************************************************************************
// Definitions of local (private) constants
//**************************************************************************************************

//! Macro for filling of the low-level parameters of the channel structure
#define SPI_HW_GET_PIN_FUNC(nChannel) \
    .nMOSIfunc = SPI_HW_CHANNEL_##nChannel##_MOSI_FUNC, \
    .nMISOfunc = SPI_HW_CHANNEL_##nChannel##_MISO_FUNC, \
    .nSCLKfunc = SPI_HW_CHANNEL_##nChannel##_SCLK_FUNC, \
    .nCSfunc   = SPI_HW_CHANNEL_##nChannel##_CS_FUNC

//! SPI low-level parameters for channel 0
#if (ON == SPI_CHANNEL_0_IN_USE)
static SPI_HW_CHANNEL_PARAMS SPI_HW_stParamsChannel_0 = 
{
    SPI_HW_GET_PIN_FUNC(0)
};
#endif

//! SPI low-level parameters for channel 1
#if (ON == SPI_CHANNEL_1_IN_USE)
static SPI_HW_CHANNEL_PARAMS SPI_HW_stParamsChannel_1 = 
{
    SPI_HW_GET_PIN_FUNC(1)
};
#endif

//! SPI low-level parameters for channel 2
#if (ON == SPI_CHANNEL_2_IN_USE)
static SPI_HW_CHANNEL_PARAMS SPI_HW_stParamsChannel_2 = 
{
    SPI_HW_GET_PIN_FUNC(2)
};
#endif

//! SPI low-level parameters for channel 3
#if (ON == SPI_CHANNEL_3_IN_USE)
static SPI_HW_CHANNEL_PARAMS SPI_HW_stParamsChannel_3 = 
{
    SPI_HW_GET_PIN_FUNC(3)
};
#endif

//! SPI low-level parameters for channel 4
#if (ON == SPI_CHANNEL_4_IN_USE)
static SPI_HW_CHANNEL_PARAMS SPI_HW_stParamsChannel_4 = 
{
    SPI_HW_GET_PIN_FUNC(4)
};
#endif

//! SPI low-level parameters for channel 5
#if (ON == SPI_CHANNEL_5_IN_USE)
static SPI_HW_CHANNEL_PARAMS SPI_HW_stParamsChannel_5 = 
{
    SPI_HW_GET_PIN_FUNC(5)
};
#endif

//! SPI low-level parameters for all channels
SPI_HW_CHANNEL_PARAMS* const SPI_HW_AllChannelsParams[SPI_CHANNEL_QNT] =
{
    // Channel 0
    #if (ON == SPI_CHANNEL_0_IN_USE)
        (SPI_HW_CHANNEL_PARAMS*)(&SPI_HW_stParamsChannel_0),
    #else
        (SPI_HW_CHANNEL_PARAMS*)(NULL_PTR),
    #endif
    // Channel 1
    #if (ON == SPI_CHANNEL_1_IN_USE)
        (SPI_HW_CHANNEL_PARAMS*)(&SPI_HW_stParamsChannel_1),
    #else
        (SPI_HW_CHANNEL_PARAMS*)(NULL_PTR),
    #endif
    // Channel 2
    #if (ON == SPI_CHANNEL_2_IN_USE)
        (SPI_HW_CHANNEL_PARAMS*)(&SPI_HW_stParamsChannel_2),
    #else
        (SPI_HW_CHANNEL_PARAMS*)(NULL_PTR),
    #endif
    // Channel 3
    #if (ON == SPI_CHANNEL_3_IN_USE)
        (SPI_HW_CHANNEL_PARAMS*)(&SPI_HW_stParamsChannel_3),
    #else
        (SPI_HW_CHANNEL_PARAMS*)(NULL_PTR),
    #endif
    // Channel 4
    #if (ON == SPI_CHANNEL_4_IN_USE)
        (SPI_HW_CHANNEL_PARAMS*)(&SPI_HW_stParamsChannel_4),
    #else
        (SPI_HW_CHANNEL_PARAMS*)(NULL_PTR),
    #endif
    // Channel 5
    #if (ON == SPI_CHANNEL_5_IN_USE)
        (SPI_HW_CHANNEL_PARAMS*)(&SPI_HW_stParamsChannel_5),
    #else
        (SPI_HW_CHANNEL_PARAMS*)(NULL_PTR),
    #endif
};



//**************************************************************************************************
// Definitions of static global (private) variables
//**************************************************************************************************

// None



//**************************************************************************************************
// Declarations of local (private) functions
//**************************************************************************************************

// None.



//**************************************************************************************************
//==================================================================================================
// Definitions of global (public) functions
//==================================================================================================
//**************************************************************************************************

// None.



//**************************************************************************************************
//==================================================================================================
// Definitions of local (private) functions
//==================================================================================================
//**************************************************************************************************

// None.



//****************************************** end of file *******************************************