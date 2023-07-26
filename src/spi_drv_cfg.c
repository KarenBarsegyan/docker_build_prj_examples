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

//-------------------------------------------- MOSI ------------------------------------------------
#if   (SPI_CHANNEL_0_MOSI_PORT == SPI_PORT_A && SPI_CHANNEL_0_MOSI_PIN == SPI_PIN_30)
    #define SPI_CHANNEL_0_MOSI_ALT_FUNK (4U)
#elif (SPI_CHANNEL_0_MOSI_PORT == SPI_PORT_B && SPI_CHANNEL_0_MOSI_PIN == SPI_PIN_1 )
    #define SPI_CHANNEL_0_MOSI_ALT_FUNK (3U)
#elif (SPI_CHANNEL_0_MOSI_PORT == SPI_PORT_B && SPI_CHANNEL_0_MOSI_PIN == SPI_PIN_4 )
    #define SPI_CHANNEL_0_MOSI_ALT_FUNK (3U)
#elif (SPI_CHANNEL_0_MOSI_PORT == SPI_PORT_E && SPI_CHANNEL_0_MOSI_PIN == SPI_PIN_2 )
    #define SPI_CHANNEL_0_MOSI_ALT_FUNK (2U)
#elif
    #error "SPI_CHANNEL_0_MOSI_PORT configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_0_MOSI_OUTPUT_MODE
    #error "SPI_CHANNEL_0_MOSI_OUTPUT_MODE not defined!"
#endif
#if (!( (SPI_CHANNEL_0_MOSI_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
        (SPI_CHANNEL_0_MOSI_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
    #error "SPI_CHANNEL_0_MOSI_OUTPUT_MODE configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_0_MOSI_PULLUP_MODE
    #error "SPI_CHANNEL_0_MOSI_PULLUP_MODE not defined!"
#endif
#if (!( SPI_CHANNEL_0_MOSI_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
        SPI_CHANNEL_0_MOSI_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
    #error "SPI_CHANNEL_0_MOSI_PULLUP_MODE configuration value is not valid!"
#endif

//-------------------------------------------- MISO ------------------------------------------------
#if   (SPI_CHANNEL_0_MISO_PORT == SPI_PORT_B && SPI_CHANNEL_0_MISO_PIN == SPI_PIN_3 )
    #define SPI_CHANNEL_0_MISO_ALT_FUNK (3U)
#elif (SPI_CHANNEL_0_MISO_PORT == SPI_PORT_D && SPI_CHANNEL_0_MISO_PIN == SPI_PIN_16)
    #define SPI_CHANNEL_0_MISO_ALT_FUNK (4U)
#elif (SPI_CHANNEL_0_MISO_PORT == SPI_PORT_E && SPI_CHANNEL_0_MISO_PIN == SPI_PIN_1 )
    #define SPI_CHANNEL_0_MISO_ALT_FUNK (2U)
#else
    #error "SPI_CHANNEL_0_MISO_PORT configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_0_MISO_OUTPUT_MODE
    #error "SPI_CHANNEL_0_MISO_OUTPUT_MODE not defined!"
#endif
#if (!( (SPI_CHANNEL_0_MISO_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
        (SPI_CHANNEL_0_MISO_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
    #error "SPI_CHANNEL_0_MISO_OUTPUT_MODE configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_0_MISO_PULLUP_MODE
    #error "SPI_CHANNEL_0_MISO_PULLUP_MODE not defined!"
#endif
#if (!( SPI_CHANNEL_0_MISO_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
        SPI_CHANNEL_0_MISO_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
    #error "SPI_CHANNEL_0_MISO_PULLUP_MODE configuration value is not valid!"
#endif

//-------------------------------------------- SCLK ------------------------------------------------
#if   (SPI_CHANNEL_0_SCLK_PORT == SPI_PORT_B && SPI_CHANNEL_0_SCLK_PIN == SPI_PIN_2 )
    #define SPI_CHANNEL_0_SCLK_ALT_FUNK (3U)
#elif (SPI_CHANNEL_0_SCLK_PORT == SPI_PORT_C && SPI_CHANNEL_0_SCLK_PIN == SPI_PIN_23)
    #define SPI_CHANNEL_0_SCLK_ALT_FUNK (2U)
#elif (SPI_CHANNEL_0_SCLK_PORT == SPI_PORT_D && SPI_CHANNEL_0_SCLK_PIN == SPI_PIN_15)
    #define SPI_CHANNEL_0_SCLK_ALT_FUNK (4U)
#elif (SPI_CHANNEL_0_SCLK_PORT == SPI_PORT_E && SPI_CHANNEL_0_SCLK_PIN == SPI_PIN_0 )
    #define SPI_CHANNEL_0_SCLK_ALT_FUNK (2U)
#else
    #error "SPI_CHANNEL_0_SCLK_PORT configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_0_SCLK_OUTPUT_MODE
    #error "SPI_CHANNEL_0_SCLK_OUTPUT_MODE not defined!"
#endif
#if (!( (SPI_CHANNEL_0_SCLK_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
        (SPI_CHANNEL_0_SCLK_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
    #error "SPI_CHANNEL_0_SCLK_OUTPUT_MODE configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_0_SCLK_PULLUP_MODE
    #error "SPI_CHANNEL_0_SCLK_PULLUP_MODE not defined!"
#endif
#if (!( SPI_CHANNEL_0_SCLK_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
        SPI_CHANNEL_0_SCLK_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
    #error "SPI_CHANNEL_0_SCLK_PULLUP_MODE configuration value is not valid!"
#endif

//-------------------------------------------- CS0 ------------------------------------------------
#if (SPI_CHANNEL_0_CS_0_IN_USE == ON)
    #if   (SPI_CHANNEL_0_CS_0_PORT == SPI_PORT_A && SPI_CHANNEL_0_CS_0_PIN == SPI_PIN_26)
        #define SPI_CHANNEL_0_CS_0_ALT_FUNK (4U)
    #elif (SPI_CHANNEL_0_CS_0_PORT == SPI_PORT_B && SPI_CHANNEL_0_CS_0_PIN == SPI_PIN_0 )
        #define SPI_CHANNEL_0_CS_0_ALT_FUNK (3U)
    #elif (SPI_CHANNEL_0_CS_0_PORT == SPI_PORT_B && SPI_CHANNEL_0_CS_0_PIN == SPI_PIN_5 )
        #define SPI_CHANNEL_0_CS_0_ALT_FUNK (4U)
    #else
        #error "SPI_CHANNEL_0_CS_0_PORT configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_0_CS_0_OUTPUT_MODE
        #error "SPI_CHANNEL_0_CS_0_OUTPUT_MODE not defined!"
    #endif
    #if (!( (SPI_CHANNEL_0_CS_0_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
            (SPI_CHANNEL_0_CS_0_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
        #error "SPI_CHANNEL_0_CS_0_OUTPUT_MODE configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_0_CS_0_PULLUP_MODE
        #error "SPI_CHANNEL_0_CS_0_PULLUP_MODE not defined!"
    #endif
    #if (!( SPI_CHANNEL_0_CS_0_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
            SPI_CHANNEL_0_CS_0_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
        #error "SPI_CHANNEL_0_CS_0_PULLUP_MODE configuration value is not valid!"
    #endif
#endif

//-------------------------------------------- CS1 ------------------------------------------------
#if (SPI_CHANNEL_0_CS_1_IN_USE == ON)
    #if   (SPI_CHANNEL_0_CS_1_PORT == SPI_PORT_A && SPI_CHANNEL_0_CS_1_PIN == SPI_PIN_31)
         #define SPI_CHANNEL_0_CS_1_ALT_FUNK (4U)
    #elif (SPI_CHANNEL_0_CS_1_PORT == SPI_PORT_B && SPI_CHANNEL_0_CS_1_PIN == SPI_PIN_5 )
         #define SPI_CHANNEL_0_CS_1_ALT_FUNK (3U)
    #else
        #error "SPI_CHANNEL_0_CS_1_PORT configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_0_CS_1_OUTPUT_MODE
        #error "SPI_CHANNEL_0_CS_1_OUTPUT_MODE not defined!"
    #endif
    #if (!( (SPI_CHANNEL_0_CS_1_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
            (SPI_CHANNEL_0_CS_1_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
        #error "SPI_CHANNEL_0_CS_1_OUTPUT_MODE configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_0_CS_1_PULLUP_MODE
        #error "SPI_CHANNEL_0_CS_1_PULLUP_MODE not defined!"
    #endif
    #if (!( SPI_CHANNEL_0_CS_1_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
            SPI_CHANNEL_0_CS_1_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
        #error "SPI_CHANNEL_0_CS_1_PULLUP_MODE configuration value is not valid!"
    #endif
#endif

//-------------------------------------------- CS2 ------------------------------------------------
#if (SPI_CHANNEL_0_CS_2_IN_USE == ON)
    #if   (SPI_CHANNEL_0_CS_2_PORT == SPI_PORT_E && SPI_CHANNEL_0_CS_2_PIN == SPI_PIN_6 )
        #define SPI_CHANNEL_0_CS_2_ALT_FUNK (2U)
    #else
        #error "SPI_CHANNEL_0_CS_2_PORT configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_0_CS_2_OUTPUT_MODE
        #error "SPI_CHANNEL_0_CS_2_OUTPUT_MODE not defined!"
    #endif
    #if (!( (SPI_CHANNEL_0_CS_2_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
            (SPI_CHANNEL_0_CS_2_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
        #error "SPI_CHANNEL_0_CS_2_OUTPUT_MODE configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_0_CS_2_PULLUP_MODE
        #error "SPI_CHANNEL_0_CS_2_PULLUP_MODE not defined!"
    #endif
    #if (!( SPI_CHANNEL_0_CS_2_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
            SPI_CHANNEL_0_CS_2_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
        #error "SPI_CHANNEL_0_CS_2_PULLUP_MODE configuration value is not valid!"
    #endif
#endif

//-------------------------------------------- CS3 ------------------------------------------------
#if (SPI_CHANNEL_0_CS_3_IN_USE == ON)
    #if   (SPI_CHANNEL_0_CS_3_PORT == SPI_PORT_A && SPI_CHANNEL_0_CS_3_PIN == SPI_PIN_15)
        #define SPI_CHANNEL_0_CS_3_ALT_FUNK (3U)
    #else
        #error "SPI_CHANNEL_0_CS_3_PORT configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_0_CS_3_OUTPUT_MODE
        #error "SPI_CHANNEL_0_CS_3_OUTPUT_MODE not defined!"
    #endif
    #if (!( (SPI_CHANNEL_0_CS_3_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
            (SPI_CHANNEL_0_CS_3_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
        #error "SPI_CHANNEL_0_CS_3_OUTPUT_MODE configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_0_CS_3_PULLUP_MODE
        #error "SPI_CHANNEL_0_CS_3_PULLUP_MODE not defined!"
    #endif
    #if (!( SPI_CHANNEL_0_CS_3_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
            SPI_CHANNEL_0_CS_3_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
        #error "SPI_CHANNEL_0_CS_3_PULLUP_MODE configuration value is not valid!"
    #endif
#endif

#endif // end of SPI_CHANNEL_0_IN_USE



//--------------------------------------------------------------------------------------------------
//-------------------------------------------- SPI1 ------------------------------------------------
//--------------------------------------------------------------------------------------------------

#if (ON == SPI_CHANNEL_1_IN_USE)

#if (SPI_CHANNEL_1_MODE != SPI_MODE_MASTER && \
     SPI_CHANNEL_1_MODE != SPI_MODE_SLAVE)
    #error "SPI_CHANNEL_1_MODE configuration value is not valid!"
#endif

#if (SPI_CHANNEL_1_BAUDRATE < SPI_MIN_BAUDRATE || \
     SPI_CHANNEL_1_BAUDRATE > SPI_MAX_BAUDRATE)
    #error "SPI_CHANNEL_1_BAUDRATE configuration value is not valid!"
#endif

//-------------------------------------------- MOSI ------------------------------------------------
#if   (SPI_CHANNEL_1_MOSI_PORT == SPI_PORT_A && SPI_CHANNEL_1_MOSI_PIN == SPI_PIN_27)
    #define SPI_CHANNEL_1_MOSI_ALT_FUNK (3U)    
#elif (SPI_CHANNEL_1_MOSI_PORT == SPI_PORT_B && SPI_CHANNEL_1_MOSI_PIN == SPI_PIN_16)
    #define SPI_CHANNEL_1_MOSI_ALT_FUNK (3U) 
#elif (SPI_CHANNEL_1_MOSI_PORT == SPI_PORT_D && SPI_CHANNEL_1_MOSI_PIN == SPI_PIN_2 )
    #define SPI_CHANNEL_1_MOSI_ALT_FUNK (3U) 
#elif (SPI_CHANNEL_1_MOSI_PORT == SPI_PORT_E && SPI_CHANNEL_1_MOSI_PIN == SPI_PIN_0 )
    #define SPI_CHANNEL_1_MOSI_ALT_FUNK (5U) 
#else
    #error "SPI_CHANNEL_1_MOSI_PORT configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_1_MOSI_OUTPUT_MODE
    #error "SPI_CHANNEL_1_MOSI_OUTPUT_MODE not defined!"
#endif
#if (!( (SPI_CHANNEL_1_MOSI_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
        (SPI_CHANNEL_1_MOSI_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
    #error "SPI_CHANNEL_1_MOSI_OUTPUT_MODE configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_1_MOSI_PULLUP_MODE
    #error "SPI_CHANNEL_1_MOSI_PULLUP_MODE not defined!"
#endif
#if (!( SPI_CHANNEL_1_MOSI_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
        SPI_CHANNEL_1_MOSI_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
    #error "SPI_CHANNEL_1_MOSI_PULLUP_MODE configuration value is not valid!"
#endif

//-------------------------------------------- MISO ------------------------------------------------
#if   (SPI_CHANNEL_1_MISO_PORT == SPI_PORT_A && SPI_CHANNEL_1_MISO_PIN == SPI_PIN_29)
    #define SPI_CHANNEL_1_MISO_ALT_FUNK (5U)    
#elif (SPI_CHANNEL_1_MISO_PORT == SPI_PORT_B && SPI_CHANNEL_1_MISO_PIN == SPI_PIN_15)
    #define SPI_CHANNEL_1_MISO_ALT_FUNK (3U)    
#elif (SPI_CHANNEL_1_MISO_PORT == SPI_PORT_E && SPI_CHANNEL_1_MISO_PIN == SPI_PIN_3 )
    #define SPI_CHANNEL_1_MISO_ALT_FUNK (3U)    
#else
    #error "SPI_CHANNEL_1_MISO_PORT configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_1_MISO_OUTPUT_MODE
    #error "SPI_CHANNEL_1_MISO_OUTPUT_MODE not defined!"
#endif
#if (!( (SPI_CHANNEL_1_MISO_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
        (SPI_CHANNEL_1_MISO_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
    #error "SPI_CHANNEL_1_MISO_OUTPUT_MODE configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_1_MISO_PULLUP_MODE
    #error "SPI_CHANNEL_1_MISO_PULLUP_MODE not defined!"
#endif
#if (!( SPI_CHANNEL_1_MISO_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
        SPI_CHANNEL_1_MISO_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
    #error "SPI_CHANNEL_1_MISO_PULLUP_MODE configuration value is not valid!"
#endif

//-------------------------------------------- SCLK ------------------------------------------------
#if   (SPI_CHANNEL_1_SCLK_PORT == SPI_PORT_A && SPI_CHANNEL_1_SCLK_PIN == SPI_PIN_28) 
    #define SPI_CHANNEL_1_SCLK_ALT_FUNK (3U) 
#elif (SPI_CHANNEL_1_SCLK_PORT == SPI_PORT_B && SPI_CHANNEL_1_SCLK_PIN == SPI_PIN_14) 
    #define SPI_CHANNEL_1_SCLK_ALT_FUNK (3U) 
#elif (SPI_CHANNEL_1_SCLK_PORT == SPI_PORT_E && SPI_CHANNEL_1_SCLK_PIN == SPI_PIN_9 ) 
    #define SPI_CHANNEL_1_SCLK_ALT_FUNK (3U) 
#else
    #error "SPI_CHANNEL_1_SCLK_PORT configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_1_SCLK_OUTPUT_MODE
    #error "SPI_CHANNEL_1_SCLK_OUTPUT_MODE not defined!"
#endif
#if (!( (SPI_CHANNEL_1_SCLK_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
        (SPI_CHANNEL_1_SCLK_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
    #error "SPI_CHANNEL_1_SCLK_OUTPUT_MODE configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_1_SCLK_PULLUP_MODE
    #error "SPI_CHANNEL_1_SCLK_PULLUP_MODE not defined!"
#endif
#if (!( SPI_CHANNEL_1_SCLK_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
        SPI_CHANNEL_1_SCLK_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
    #error "SPI_CHANNEL_1_SCLK_PULLUP_MODE configuration value is not valid!"
#endif

//-------------------------------------------- CS0 ------------------------------------------------
#if (SPI_CHANNEL_1_CS_0_IN_USE == ON)
    #if   (SPI_CHANNEL_1_CS_0_PORT == SPI_PORT_A && SPI_CHANNEL_1_CS_0_PIN == SPI_PIN_26)
        #define SPI_CHANNEL_1_CS_0_ALT_FUNK (3U)
    #elif (SPI_CHANNEL_1_CS_0_PORT == SPI_PORT_D && SPI_CHANNEL_1_CS_0_PIN == SPI_PIN_3 ) 
        #define SPI_CHANNEL_1_CS_0_ALT_FUNK (3U)
    #elif (SPI_CHANNEL_1_CS_0_PORT == SPI_PORT_E && SPI_CHANNEL_1_CS_0_PIN == SPI_PIN_1 ) 
        #define SPI_CHANNEL_1_CS_0_ALT_FUNK (5U)
    #else
        #error "SPI_CHANNEL_1_CS_0_PORT configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_1_CS_0_OUTPUT_MODE
        #error "SPI_CHANNEL_1_CS_0_OUTPUT_MODE not defined!"
    #endif
    #if (!( (SPI_CHANNEL_1_CS_0_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
            (SPI_CHANNEL_1_CS_0_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
        #error "SPI_CHANNEL_1_CS_0_OUTPUT_MODE configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_1_CS_0_PULLUP_MODE
        #error "SPI_CHANNEL_1_CS_0_PULLUP_MODE not defined!"
    #endif
    #if (!( SPI_CHANNEL_1_CS_0_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
            SPI_CHANNEL_1_CS_0_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
        #error "SPI_CHANNEL_1_CS_0_PULLUP_MODE configuration value is not valid!"
    #endif
#endif

//-------------------------------------------- CS1 ------------------------------------------------
#if (SPI_CHANNEL_1_CS_1_IN_USE == ON)
    #if   (SPI_CHANNEL_1_CS_1_PORT == SPI_PORT_A && SPI_CHANNEL_1_CS_1_PIN == SPI_PIN_6 )
        #define SPI_CHANNEL_1_CS_1_ALT_FUNK (3U)
    #elif (SPI_CHANNEL_1_CS_1_PORT == SPI_PORT_B && SPI_CHANNEL_1_CS_1_PIN == SPI_PIN_18)
        #define SPI_CHANNEL_1_CS_1_ALT_FUNK (4U)
    #else
        #error "SPI_CHANNEL_1_CS_1_PORT configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_1_CS_1_OUTPUT_MODE
        #error "SPI_CHANNEL_1_CS_1_OUTPUT_MODE not defined!"
    #endif
    #if (!( (SPI_CHANNEL_1_CS_1_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
            (SPI_CHANNEL_1_CS_1_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
        #error "SPI_CHANNEL_1_CS_1_OUTPUT_MODE configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_1_CS_1_PULLUP_MODE
        #error "SPI_CHANNEL_1_CS_1_PULLUP_MODE not defined!"
    #endif
    #if (!( SPI_CHANNEL_1_CS_1_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
            SPI_CHANNEL_1_CS_1_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
        #error "SPI_CHANNEL_1_CS_1_PULLUP_MODE configuration value is not valid!"
    #endif
#endif

//-------------------------------------------- CS2 ------------------------------------------------
#if (SPI_CHANNEL_1_CS_2_IN_USE == ON)
    #if   (SPI_CHANNEL_1_CS_2_PORT == SPI_PORT_A && SPI_CHANNEL_1_CS_2_PIN == SPI_PIN_16)
        #define SPI_CHANNEL_1_CS_2_ALT_FUNK (3U)
    #else
        #error "SPI_CHANNEL_1_CS_2_PORT configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_1_CS_2_OUTPUT_MODE
        #error "SPI_CHANNEL_1_CS_2_OUTPUT_MODE not defined!"
    #endif
    #if (!( (SPI_CHANNEL_1_CS_2_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
            (SPI_CHANNEL_1_CS_2_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
        #error "SPI_CHANNEL_1_CS_2_OUTPUT_MODE configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_1_CS_2_PULLUP_MODE
        #error "SPI_CHANNEL_1_CS_2_PULLUP_MODE not defined!"
    #endif
    #if (!( SPI_CHANNEL_1_CS_2_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
            SPI_CHANNEL_1_CS_2_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
        #error "SPI_CHANNEL_1_CS_2_PULLUP_MODE configuration value is not valid!"
    #endif
#endif

//-------------------------------------------- CS3 ------------------------------------------------
#if (SPI_CHANNEL_1_CS_3_IN_USE == ON)
    #if   (SPI_CHANNEL_1_CS_3_PORT == SPI_PORT_B && SPI_CHANNEL_1_CS_3_PIN == SPI_PIN_17)
        #define SPI_CHANNEL_1_CS_2_ALT_FUNK (3U)
    #else
        #error "SPI_CHANNEL_1_CS_3_PORT configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_1_CS_3_OUTPUT_MODE
        #error "SPI_CHANNEL_1_CS_3_OUTPUT_MODE not defined!"
    #endif
    #if (!( (SPI_CHANNEL_1_CS_3_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
            (SPI_CHANNEL_1_CS_3_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
        #error "SPI_CHANNEL_1_CS_3_OUTPUT_MODE configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_1_CS_3_PULLUP_MODE
        #error "SPI_CHANNEL_1_CS_3_PULLUP_MODE not defined!"
    #endif
    #if (!( SPI_CHANNEL_1_CS_3_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
            SPI_CHANNEL_1_CS_3_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
        #error "SPI_CHANNEL_1_CS_3_PULLUP_MODE configuration value is not valid!"
    #endif
#endif

#endif // end of SPI_CHANNEL_1_IN_USE



//--------------------------------------------------------------------------------------------------
//-------------------------------------------- SPI2 ------------------------------------------------
//--------------------------------------------------------------------------------------------------

#if (ON == SPI_CHANNEL_2_IN_USE)

#if (SPI_CHANNEL_2_MODE != SPI_MODE_MASTER && \
     SPI_CHANNEL_2_MODE != SPI_MODE_SLAVE)
    #error "SPI_CHANNEL_2_MODE configuration value is not valid!"
#endif

#if (SPI_CHANNEL_2_BAUDRATE < SPI_MIN_BAUDRATE || \
     SPI_CHANNEL_2_BAUDRATE > SPI_MAX_BAUDRATE)
    #error "SPI_CHANNEL_2_BAUDRATE configuration value is not valid!"
#endif

//-------------------------------------------- MOSI ------------------------------------------------
#if   (SPI_CHANNEL_2_MOSI_PORT == SPI_PORT_A && SPI_CHANNEL_2_MOSI_PIN == SPI_PIN_8 )
    #define SPI_CHANNEL_2_MOSI_ALT_FUNK (3U)
#elif (SPI_CHANNEL_2_MOSI_PORT == SPI_PORT_B && SPI_CHANNEL_2_MOSI_PIN == SPI_PIN_27)
    #define SPI_CHANNEL_2_MOSI_ALT_FUNK (5U)
#elif (SPI_CHANNEL_2_MOSI_PORT == SPI_PORT_C && SPI_CHANNEL_2_MOSI_PIN == SPI_PIN_1 )
    #define SPI_CHANNEL_2_MOSI_ALT_FUNK (3U)
#else
    #error "SPI_CHANNEL_2_MOSI_PORT configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_2_MOSI_OUTPUT_MODE
    #error "SPI_CHANNEL_2_MOSI_OUTPUT_MODE not defined!"
#endif
#if (!( (SPI_CHANNEL_2_MOSI_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
        (SPI_CHANNEL_2_MOSI_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
    #error "SPI_CHANNEL_2_MOSI_OUTPUT_MODE configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_2_MOSI_PULLUP_MODE
    #error "SPI_CHANNEL_2_MOSI_PULLUP_MODE not defined!"
#endif
#if (!( SPI_CHANNEL_2_MOSI_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
        SPI_CHANNEL_2_MOSI_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
    #error "SPI_CHANNEL_2_MOSI_PULLUP_MODE configuration value is not valid!"
#endif

//-------------------------------------------- MISO ------------------------------------------------
#if   (SPI_CHANNEL_2_MISO_PORT == SPI_PORT_B && SPI_CHANNEL_2_MISO_PIN == SPI_PIN_28)
    #define SPI_CHANNEL_2_MISO_ALT_FUNK (5U)
#elif (SPI_CHANNEL_2_MISO_PORT == SPI_PORT_C && SPI_CHANNEL_2_MISO_PIN == SPI_PIN_0 )
    #define SPI_CHANNEL_2_MISO_ALT_FUNK (3U)    
#elif (SPI_CHANNEL_2_MISO_PORT == SPI_PORT_E && SPI_CHANNEL_2_MISO_PIN == SPI_PIN_16)
    #define SPI_CHANNEL_2_MISO_ALT_FUNK (3U)
#else
    #error "SPI_CHANNEL_2_MISO_PORT configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_2_MISO_OUTPUT_MODE
    #error "SPI_CHANNEL_2_MISO_OUTPUT_MODE not defined!"
#endif
#if (!( (SPI_CHANNEL_2_MISO_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
        (SPI_CHANNEL_2_MISO_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
    #error "SPI_CHANNEL_2_MISO_OUTPUT_MODE configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_2_MISO_PULLUP_MODE
    #error "SPI_CHANNEL_2_MISO_PULLUP_MODE not defined!"
#endif
#if (!( SPI_CHANNEL_2_MISO_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
        SPI_CHANNEL_2_MISO_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
    #error "SPI_CHANNEL_2_MISO_PULLUP_MODE configuration value is not valid!"
#endif

//-------------------------------------------- SCLK ------------------------------------------------
#if   (SPI_CHANNEL_2_SCLK_PORT == SPI_PORT_B && SPI_CHANNEL_2_SCLK_PIN == SPI_PIN_29)
    #define SPI_CHANNEL_2_SCLK_ALT_FUNK (5U)
#elif (SPI_CHANNEL_2_SCLK_PORT == SPI_PORT_C && SPI_CHANNEL_2_SCLK_PIN == SPI_PIN_15)
    #define SPI_CHANNEL_2_SCLK_ALT_FUNK (3U)
#elif (SPI_CHANNEL_2_SCLK_PORT == SPI_PORT_E && SPI_CHANNEL_2_SCLK_PIN == SPI_PIN_15)
    #define SPI_CHANNEL_2_SCLK_ALT_FUNK (3U)
#else
    #error "SPI_CHANNEL_2_SCLK_PORT configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_2_SCLK_OUTPUT_MODE
    #error "SPI_CHANNEL_2_SCLK_OUTPUT_MODE not defined!"
#endif
#if (!( (SPI_CHANNEL_2_SCLK_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
        (SPI_CHANNEL_2_SCLK_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
    #error "SPI_CHANNEL_2_SCLK_OUTPUT_MODE configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_2_SCLK_PULLUP_MODE
    #error "SPI_CHANNEL_2_SCLK_PULLUP_MODE not defined!"
#endif
#if (!( SPI_CHANNEL_2_SCLK_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
        SPI_CHANNEL_2_SCLK_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
    #error "SPI_CHANNEL_2_SCLK_PULLUP_MODE configuration value is not valid!"
#endif

//-------------------------------------------- CS0 ------------------------------------------------
#if (SPI_CHANNEL_2_CS_0_IN_USE == ON)
    #if   (SPI_CHANNEL_2_CS_0_PORT == SPI_PORT_A && SPI_CHANNEL_2_CS_0_PIN == SPI_PIN_9 )
        #define SPI_CHANNEL_2_CS_0_ALT_FUNK (3U)
    #elif (SPI_CHANNEL_2_CS_0_PORT == SPI_PORT_B && SPI_CHANNEL_2_CS_0_PIN == SPI_PIN_25)
        #define SPI_CHANNEL_2_CS_0_ALT_FUNK (5U)
    #elif (SPI_CHANNEL_2_CS_0_PORT == SPI_PORT_C && SPI_CHANNEL_2_CS_0_PIN == SPI_PIN_14)
        #define SPI_CHANNEL_2_CS_0_ALT_FUNK (3U)
    #elif (SPI_CHANNEL_2_CS_0_PORT == SPI_PORT_E && SPI_CHANNEL_2_CS_0_PIN == SPI_PIN_11)
        #define SPI_CHANNEL_2_CS_0_ALT_FUNK (2U)
    #else
        #error "SPI_CHANNEL_2_CS_0_PORT configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_2_CS_0_OUTPUT_MODE
        #error "SPI_CHANNEL_2_CS_0_OUTPUT_MODE not defined!"
    #endif
    #if (!( (SPI_CHANNEL_2_CS_0_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
            (SPI_CHANNEL_2_CS_0_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
        #error "SPI_CHANNEL_2_CS_0_OUTPUT_MODE configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_2_CS_0_PULLUP_MODE
        #error "SPI_CHANNEL_2_CS_0_PULLUP_MODE not defined!"
    #endif
    #if (!( SPI_CHANNEL_2_CS_0_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
            SPI_CHANNEL_2_CS_0_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
        #error "SPI_CHANNEL_2_CS_0_PULLUP_MODE configuration value is not valid!"
    #endif
#endif

//-------------------------------------------- CS1 ------------------------------------------------
#if (SPI_CHANNEL_2_CS_1_IN_USE == ON)
    #if   (SPI_CHANNEL_2_CS_1_PORT == SPI_PORT_C && SPI_CHANNEL_2_CS_1_PIN == SPI_PIN_19)
        #define SPI_CHANNEL_2_CS_1_ALT_FUNK (5U)
    #elif (SPI_CHANNEL_2_CS_1_PORT == SPI_PORT_E && SPI_CHANNEL_2_CS_1_PIN == SPI_PIN_10)
        #define SPI_CHANNEL_2_CS_1_ALT_FUNK (3U)
    #else
        #error "SPI_CHANNEL_2_CS_1_PORT configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_2_CS_1_OUTPUT_MODE
        #error "SPI_CHANNEL_2_CS_1_OUTPUT_MODE not defined!"
    #endif
    #if (!( (SPI_CHANNEL_2_CS_1_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
            (SPI_CHANNEL_2_CS_1_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
        #error "SPI_CHANNEL_2_CS_1_OUTPUT_MODE configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_2_CS_1_PULLUP_MODE
        #error "SPI_CHANNEL_2_CS_1_PULLUP_MODE not defined!"
    #endif
    #if (!( SPI_CHANNEL_2_CS_1_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
            SPI_CHANNEL_2_CS_1_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
        #error "SPI_CHANNEL_2_CS_1_PULLUP_MODE configuration value is not valid!"
    #endif
#endif

//-------------------------------------------- CS2 ------------------------------------------------
#if (SPI_CHANNEL_2_CS_2_IN_USE == ON)
    #if   (SPI_CHANNEL_2_CS_2_PORT == SPI_PORT_E && SPI_CHANNEL_2_CS_2_PIN == SPI_PIN_13)
        #define SPI_CHANNEL_2_CS_0_ALT_FUNK (3U)
    #else
        #error "SPI_CHANNEL_2_CS_2_PORT configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_2_CS_2_OUTPUT_MODE
        #error "SPI_CHANNEL_2_CS_2_OUTPUT_MODE not defined!"
    #endif
    #if (!( (SPI_CHANNEL_2_CS_2_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
            (SPI_CHANNEL_2_CS_2_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
        #error "SPI_CHANNEL_2_CS_2_OUTPUT_MODE configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_2_CS_2_PULLUP_MODE
        #error "SPI_CHANNEL_2_CS_2_PULLUP_MODE not defined!"
    #endif
    #if (!( SPI_CHANNEL_2_CS_2_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
            SPI_CHANNEL_2_CS_2_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
        #error "SPI_CHANNEL_2_CS_2_PULLUP_MODE configuration value is not valid!"
    #endif
#endif

//-------------------------------------------- CS3 ------------------------------------------------
#if (SPI_CHANNEL_2_CS_3_IN_USE == ON)
    #if   (SPI_CHANNEL_2_CS_3_PORT == SPI_PORT_A && SPI_CHANNEL_2_CS_3_PIN == SPI_PIN_15)
        #define SPI_CHANNEL_2_CS_3_ALT_FUNK (4U)
    #else    
        #error "SPI_CHANNEL_2_CS_3_PORT configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_2_CS_3_OUTPUT_MODE
        #error "SPI_CHANNEL_2_CS_3_OUTPUT_MODE not defined!"
    #endif
    #if (!( (SPI_CHANNEL_2_CS_3_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
            (SPI_CHANNEL_2_CS_3_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
        #error "SPI_CHANNEL_2_CS_3_OUTPUT_MODE configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_2_CS_3_PULLUP_MODE
        #error "SPI_CHANNEL_2_CS_3_PULLUP_MODE not defined!"
    #endif
    #if (!( SPI_CHANNEL_2_CS_3_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
            SPI_CHANNEL_2_CS_3_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
        #error "SPI_CHANNEL_2_CS_3_PULLUP_MODE configuration value is not valid!"
    #endif
#endif

#endif // end of SPI_CHANNEL_2_IN_USE



//--------------------------------------------------------------------------------------------------
//-------------------------------------------- SPI3 ------------------------------------------------
//--------------------------------------------------------------------------------------------------

#if (ON == SPI_CHANNEL_3_IN_USE)

#if (SPI_CHANNEL_3_MODE != SPI_MODE_MASTER && \
     SPI_CHANNEL_3_MODE != SPI_MODE_SLAVE)
    #error "SPI_CHANNEL_3_MODE configuration value is not valid!"
#endif

#if (SPI_CHANNEL_3_BAUDRATE < SPI_MIN_BAUDRATE || \
     SPI_CHANNEL_3_BAUDRATE > SPI_MAX_BAUDRATE)
    #error "SPI_CHANNEL_3_BAUDRATE configuration value is not valid!"
#endif

//-------------------------------------------- MOSI ------------------------------------------------
#if   (SPI_CHANNEL_3_MOSI_PORT == SPI_PORT_A && SPI_CHANNEL_3_MOSI_PIN == SPI_PIN_10)
    #define SPI_CHANNEL_3_MOSI_ALT_FUNK (4U)
#elif (SPI_CHANNEL_3_MOSI_PORT == SPI_PORT_E && SPI_CHANNEL_3_MOSI_PIN == SPI_PIN_3 )
    #define SPI_CHANNEL_3_MOSI_ALT_FUNK (5U)
#else
    #error "SPI_CHANNEL_3_MOSI_PORT configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_3_MOSI_OUTPUT_MODE
    #error "SPI_CHANNEL_3_MOSI_OUTPUT_MODE not defined!"
#endif
#if (!( (SPI_CHANNEL_3_MOSI_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
        (SPI_CHANNEL_3_MOSI_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
    #error "SPI_CHANNEL_3_MOSI_OUTPUT_MODE configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_3_MOSI_PULLUP_MODE
    #error "SPI_CHANNEL_3_MOSI_PULLUP_MODE not defined!"
#endif
#if (!( SPI_CHANNEL_3_MOSI_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
        SPI_CHANNEL_3_MOSI_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
    #error "SPI_CHANNEL_3_MOSI_PULLUP_MODE configuration value is not valid!"
#endif

//-------------------------------------------- MISO ------------------------------------------------
#if   (SPI_CHANNEL_3_MISO_PORT == SPI_PORT_A && SPI_CHANNEL_3_MISO_PIN == SPI_PIN_11)
    #define SPI_CHANNEL_3_MISO_ALT_FUNK (4U)
#elif (SPI_CHANNEL_3_MISO_PORT == SPI_PORT_B && SPI_CHANNEL_3_MISO_PIN == SPI_PIN_6 )
    #define SPI_CHANNEL_3_MISO_ALT_FUNK (4U)
#else
    #error "SPI_CHANNEL_3_MISO_PORT configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_3_MISO_OUTPUT_MODE
    #error "SPI_CHANNEL_3_MISO_OUTPUT_MODE not defined!"
#endif
#if (!( (SPI_CHANNEL_3_MISO_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
        (SPI_CHANNEL_3_MISO_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
    #error "SPI_CHANNEL_3_MISO_OUTPUT_MODE configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_3_MISO_PULLUP_MODE
    #error "SPI_CHANNEL_3_MISO_PULLUP_MODE not defined!"
#endif
#if (!( SPI_CHANNEL_3_MISO_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
        SPI_CHANNEL_3_MISO_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
    #error "SPI_CHANNEL_3_MISO_PULLUP_MODE configuration value is not valid!"
#endif

//-------------------------------------------- SCLK ------------------------------------------------
#if   (SPI_CHANNEL_3_SCLK_PORT == SPI_PORT_A && SPI_CHANNEL_3_SCLK_PIN == SPI_PIN_12)
    #define SPI_CHANNEL_3_SCLK_ALT_FUNK (4U)
#elif (SPI_CHANNEL_3_SCLK_PORT == SPI_PORT_B && SPI_CHANNEL_3_SCLK_PIN == SPI_PIN_7 )
    #define SPI_CHANNEL_3_SCLK_ALT_FUNK (4U)
#else
    #error "SPI_CHANNEL_3_SCLK_PORT configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_3_SCLK_OUTPUT_MODE
    #error "SPI_CHANNEL_3_SCLK_OUTPUT_MODE not defined!"
#endif
#if (!( (SPI_CHANNEL_3_SCLK_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
        (SPI_CHANNEL_3_SCLK_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
    #error "SPI_CHANNEL_3_SCLK_OUTPUT_MODE configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_3_SCLK_PULLUP_MODE
    #error "SPI_CHANNEL_3_SCLK_PULLUP_MODE not defined!"
#endif
#if (!( SPI_CHANNEL_3_SCLK_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
        SPI_CHANNEL_3_SCLK_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
    #error "SPI_CHANNEL_3_SCLK_PULLUP_MODE configuration value is not valid!"
#endif

//-------------------------------------------- CS0 ------------------------------------------------
#if (SPI_CHANNEL_3_CS_0_IN_USE == ON)
    #if   (SPI_CHANNEL_3_CS_0_PORT == SPI_PORT_A && SPI_CHANNEL_3_CS_0_PIN == SPI_PIN_13)
        #define SPI_CHANNEL_3_CS_0_ALT_FUNK (4U)
    #elif (SPI_CHANNEL_3_CS_0_PORT == SPI_PORT_E && SPI_CHANNEL_3_CS_0_PIN == SPI_PIN_12) 
        #define SPI_CHANNEL_3_CS_0_ALT_FUNK (5U)
    #else
        #error "SPI_CHANNEL_3_CS_0_PORT configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_3_CS_0_OUTPUT_MODE
        #error "SPI_CHANNEL_3_CS_0_OUTPUT_MODE not defined!"
    #endif
    #if (!( (SPI_CHANNEL_3_CS_0_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
            (SPI_CHANNEL_3_CS_0_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
        #error "SPI_CHANNEL_3_CS_0_OUTPUT_MODE configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_3_CS_0_PULLUP_MODE
        #error "SPI_CHANNEL_3_CS_0_PULLUP_MODE not defined!"
    #endif
    #if (!( SPI_CHANNEL_3_CS_0_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
            SPI_CHANNEL_3_CS_0_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
        #error "SPI_CHANNEL_3_CS_0_PULLUP_MODE configuration value is not valid!"
    #endif
#endif

//-------------------------------------------- CS1 ------------------------------------------------
#if (SPI_CHANNEL_3_CS_1_IN_USE == ON)
    #if   (SPI_CHANNEL_3_CS_1_PORT == SPI_PORT_C && SPI_CHANNEL_3_CS_1_PIN == SPI_PIN_5 )
        #define SPI_CHANNEL_3_CS_1_ALT_FUNK (4U)
    #elif (SPI_CHANNEL_3_CS_1_PORT == SPI_PORT_E && SPI_CHANNEL_3_CS_1_PIN == SPI_PIN_8 )
        #define SPI_CHANNEL_3_CS_1_ALT_FUNK (5U)
    #else
        #error "SPI_CHANNEL_3_CS_1_PORT configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_3_CS_1_OUTPUT_MODE
        #error "SPI_CHANNEL_3_CS_1_OUTPUT_MODE not defined!"
    #endif
    #if (!( (SPI_CHANNEL_3_CS_1_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
            (SPI_CHANNEL_3_CS_1_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
        #error "SPI_CHANNEL_3_CS_1_OUTPUT_MODE configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_3_CS_1_PULLUP_MODE
        #error "SPI_CHANNEL_3_CS_1_PULLUP_MODE not defined!"
    #endif
    #if (!( SPI_CHANNEL_3_CS_1_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
            SPI_CHANNEL_3_CS_1_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
        #error "SPI_CHANNEL_3_CS_1_PULLUP_MODE configuration value is not valid!"
    #endif
#endif

#endif // end of SPI_CHANNEL_3_IN_USE



//--------------------------------------------------------------------------------------------------
//-------------------------------------------- SPI4 ------------------------------------------------
//--------------------------------------------------------------------------------------------------

#if (ON == SPI_CHANNEL_4_IN_USE)

#if (SPI_CHANNEL_4_MODE != SPI_MODE_MASTER && \
     SPI_CHANNEL_4_MODE != SPI_MODE_SLAVE)
    #error "SPI_CHANNEL_4_MODE configuration value is not valid!"
#endif

#if (SPI_CHANNEL_4_BAUDRATE < SPI_MIN_BAUDRATE || \
     SPI_CHANNEL_4_BAUDRATE > SPI_MAX_BAUDRATE)
    #error "SPI_CHANNEL_4_BAUDRATE configuration value is not valid!"
#endif

//-------------------------------------------- MOSI ------------------------------------------------
#if   (SPI_CHANNEL_4_MOSI_PORT == SPI_PORT_C && SPI_CHANNEL_4_MOSI_PIN == SPI_PIN_14)
    #define SPI_CHANNEL_4_MOSI_ALT_FUNK (4U)
#elif (SPI_CHANNEL_4_MOSI_PORT == SPI_PORT_D && SPI_CHANNEL_4_MOSI_PIN == SPI_PIN_6 )
    #define SPI_CHANNEL_4_MOSI_ALT_FUNK (5U)
#else
    #error "SPI_CHANNEL_4_MOSI_PORT configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_4_MOSI_OUTPUT_MODE
    #error "SPI_CHANNEL_4_MOSI_OUTPUT_MODE not defined!"
#endif
#if (!( (SPI_CHANNEL_4_MOSI_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
        (SPI_CHANNEL_4_MOSI_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
    #error "SPI_CHANNEL_4_MOSI_OUTPUT_MODE configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_4_MOSI_PULLUP_MODE
    #error "SPI_CHANNEL_4_MOSI_PULLUP_MODE not defined!"
#endif
#if (!( SPI_CHANNEL_4_MOSI_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
        SPI_CHANNEL_4_MOSI_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
    #error "SPI_CHANNEL_4_MOSI_PULLUP_MODE configuration value is not valid!"
#endif

//-------------------------------------------- MISO ------------------------------------------------
#if   (SPI_CHANNEL_4_MISO_PORT == SPI_PORT_D && SPI_CHANNEL_4_MISO_PIN == SPI_PIN_15)
    #define SPI_CHANNEL_4_MISO_ALT_FUNK (4U)
#elif (SPI_CHANNEL_4_MISO_PORT == SPI_PORT_C && SPI_CHANNEL_4_MISO_PIN == SPI_PIN_7 )
    #define SPI_CHANNEL_4_MISO_ALT_FUNK (5U)
#else
    #error "SPI_CHANNEL_4_MISO_PORT configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_4_MISO_OUTPUT_MODE
    #error "SPI_CHANNEL_4_MISO_OUTPUT_MODE not defined!"
#endif
#if (!( (SPI_CHANNEL_4_MISO_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
        (SPI_CHANNEL_4_MISO_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
    #error "SPI_CHANNEL_4_MISO_OUTPUT_MODE configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_4_MISO_PULLUP_MODE
    #error "SPI_CHANNEL_4_MISO_PULLUP_MODE not defined!"
#endif
#if (!( SPI_CHANNEL_4_MISO_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
        SPI_CHANNEL_4_MISO_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
    #error "SPI_CHANNEL_4_MISO_PULLUP_MODE configuration value is not valid!"
#endif

//-------------------------------------------- SCLK ------------------------------------------------
#if   (SPI_CHANNEL_4_SCLK_PORT == SPI_PORT_C && SPI_CHANNEL_4_SCLK_PIN == SPI_PIN_2 )
     #define SPI_CHANNEL_4_SCLK_ALT_FUNK (5U)    
#elif (SPI_CHANNEL_4_SCLK_PORT == SPI_PORT_C && SPI_CHANNEL_4_SCLK_PIN == SPI_PIN_16)
     #define SPI_CHANNEL_4_SCLK_ALT_FUNK (4U)
#else
    #error "SPI_CHANNEL_4_SCLK_PORT configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_4_SCLK_OUTPUT_MODE
    #error "SPI_CHANNEL_4_SCLK_OUTPUT_MODE not defined!"
#endif
#if (!( (SPI_CHANNEL_4_SCLK_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
        (SPI_CHANNEL_4_SCLK_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
    #error "SPI_CHANNEL_4_SCLK_OUTPUT_MODE configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_4_SCLK_PULLUP_MODE
    #error "SPI_CHANNEL_4_SCLK_PULLUP_MODE not defined!"
#endif
#if (!( SPI_CHANNEL_4_SCLK_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
        SPI_CHANNEL_4_SCLK_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
    #error "SPI_CHANNEL_4_SCLK_PULLUP_MODE configuration value is not valid!"
#endif

//-------------------------------------------- CS0 ------------------------------------------------
#if (SPI_CHANNEL_4_CS_0_IN_USE == ON)
    #if   (SPI_CHANNEL_4_CS_0_PORT == SPI_PORT_C && SPI_CHANNEL_4_CS_0_PIN == SPI_PIN_3 )
        #define SPI_CHANNEL_4_CS_0_ALT_FUNK (5U)
    #elif (SPI_CHANNEL_4_CS_0_PORT == SPI_PORT_C && SPI_CHANNEL_4_CS_0_PIN == SPI_PIN_17)   
        #define SPI_CHANNEL_4_CS_0_ALT_FUNK (4U)
    #else
        #error "SPI_CHANNEL_4_CS_0_PORT configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_4_CS_0_OUTPUT_MODE
        #error "SPI_CHANNEL_4_CS_0_OUTPUT_MODE not defined!"
    #endif
    #if (!( (SPI_CHANNEL_4_CS_0_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
            (SPI_CHANNEL_4_CS_0_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
        #error "SPI_CHANNEL_4_CS_0_OUTPUT_MODE configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_4_CS_0_PULLUP_MODE
        #error "SPI_CHANNEL_4_CS_0_PULLUP_MODE not defined!"
    #endif
    #if (!( SPI_CHANNEL_4_CS_0_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
            SPI_CHANNEL_4_CS_0_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
        #error "SPI_CHANNEL_4_CS_0_PULLUP_MODE configuration value is not valid!"
    #endif
#endif

//-------------------------------------------- CS1 ------------------------------------------------
#if (SPI_CHANNEL_4_CS_1_IN_USE == ON)
    #if   (SPI_CHANNEL_4_CS_1_PORT == SPI_PORT_B && SPI_CHANNEL_4_CS_1_PIN == SPI_PIN_25)
        #define SPI_CHANNEL_4_CS_1_ALT_FUNK (4U)
    #elif (SPI_CHANNEL_4_CS_1_PORT == SPI_PORT_D && SPI_CHANNEL_4_CS_1_PIN == SPI_PIN_5 )
        #define SPI_CHANNEL_4_CS_1_ALT_FUNK (5U)
    #else
        #error "SPI_CHANNEL_4_CS_1_PORT configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_4_CS_1_OUTPUT_MODE
        #error "SPI_CHANNEL_4_CS_1_OUTPUT_MODE not defined!"
    #endif
    #if (!( (SPI_CHANNEL_4_CS_1_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
            (SPI_CHANNEL_4_CS_1_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
        #error "SPI_CHANNEL_4_CS_1_OUTPUT_MODE configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_4_CS_1_PULLUP_MODE
        #error "SPI_CHANNEL_4_CS_1_PULLUP_MODE not defined!"
    #endif
    #if (!( SPI_CHANNEL_4_CS_1_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
            SPI_CHANNEL_4_CS_1_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
        #error "SPI_CHANNEL_4_CS_1_PULLUP_MODE configuration value is not valid!"
    #endif
#endif

#endif // end of SPI_CHANNEL_4_IN_USE



//--------------------------------------------------------------------------------------------------
//-------------------------------------------- SPI5 ------------------------------------------------
//--------------------------------------------------------------------------------------------------

#if (ON == SPI_CHANNEL_5_IN_USE)

#if (SPI_CHANNEL_5_MODE != SPI_MODE_MASTER && \
     SPI_CHANNEL_5_MODE != SPI_MODE_SLAVE)
    #error "SPI_CHANNEL_5_MODE configuration value is not valid!"
#endif

#if (SPI_CHANNEL_5_BAUDRATE < SPI_MIN_BAUDRATE || \
     SPI_CHANNEL_5_BAUDRATE > SPI_MAX_BAUDRATE)
    #error "SPI_CHANNEL_5_BAUDRATE configuration value is not valid!"
#endif

//-------------------------------------------- MOSI ------------------------------------------------
#if   (SPI_CHANNEL_5_MOSI_PORT == SPI_PORT_D && SPI_CHANNEL_5_MOSI_PIN == SPI_PIN_11)
    #define SPI_CHANNEL_5_MOSI_ALT_FUNK (5U)
#elif (SPI_CHANNEL_5_MOSI_PORT == SPI_PORT_E && SPI_CHANNEL_5_MOSI_PIN == SPI_PIN_7 )
    #define SPI_CHANNEL_5_MOSI_ALT_FUNK (6U)
#else
    #error "SPI_CHANNEL_5_MOSI_PORT configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_5_MOSI_OUTPUT_MODE
    #error "SPI_CHANNEL_5_MOSI_OUTPUT_MODE not defined!"
#endif
#if (!( (SPI_CHANNEL_5_MOSI_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
        (SPI_CHANNEL_5_MOSI_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
    #error "SPI_CHANNEL_5_MOSI_OUTPUT_MODE configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_5_MOSI_PULLUP_MODE
    #error "SPI_CHANNEL_5_MOSI_PULLUP_MODE not defined!"
#endif
#if (!( SPI_CHANNEL_5_MOSI_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
        SPI_CHANNEL_5_MOSI_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
    #error "SPI_CHANNEL_5_MOSI_PULLUP_MODE configuration value is not valid!"
#endif

//-------------------------------------------- MISO ------------------------------------------------
#if   (SPI_CHANNEL_5_MISO_PORT == SPI_PORT_A && SPI_CHANNEL_5_MISO_PIN == SPI_PIN_6 )
    #define SPI_CHANNEL_5_MISO_ALT_FUNK (6U)
#elif (SPI_CHANNEL_5_MISO_PORT == SPI_PORT_D && SPI_CHANNEL_5_MISO_PIN == SPI_PIN_12)
    #define SPI_CHANNEL_5_MISO_ALT_FUNK (5U)
#else
    #error "SPI_CHANNEL_5_MISO_PORT configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_5_MISO_OUTPUT_MODE
    #error "SPI_CHANNEL_5_MISO_OUTPUT_MODE not defined!"
#endif
#if (!( (SPI_CHANNEL_5_MISO_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
        (SPI_CHANNEL_5_MISO_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
    #error "SPI_CHANNEL_5_MISO_OUTPUT_MODE configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_5_MISO_PULLUP_MODE
    #error "SPI_CHANNEL_5_MISO_PULLUP_MODE not defined!"
#endif
#if (!( SPI_CHANNEL_5_MISO_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
        SPI_CHANNEL_5_MISO_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
    #error "SPI_CHANNEL_5_MISO_PULLUP_MODE configuration value is not valid!"
#endif

//-------------------------------------------- SCLK ------------------------------------------------
#if   (SPI_CHANNEL_5_SCLK_PORT == SPI_PORT_A && SPI_CHANNEL_5_SCLK_PIN == SPI_PIN_7 )
     #define SPI_CHANNEL_5_SCLK_ALT_FUNK (6U)    
#elif (SPI_CHANNEL_5_SCLK_PORT == SPI_PORT_D && SPI_CHANNEL_5_SCLK_PIN == SPI_PIN_10)
     #define SPI_CHANNEL_5_SCLK_ALT_FUNK (5U)
#else
    #error "SPI_CHANNEL_5_SCLK_PORT configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_5_SCLK_OUTPUT_MODE
    #error "SPI_CHANNEL_5_SCLK_OUTPUT_MODE not defined!"
#endif
#if (!( (SPI_CHANNEL_5_SCLK_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
        (SPI_CHANNEL_5_SCLK_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
    #error "SPI_CHANNEL_5_SCLK_OUTPUT_MODE configuration value is not valid!"
#endif

#ifndef SPI_CHANNEL_5_SCLK_PULLUP_MODE
    #error "SPI_CHANNEL_5_SCLK_PULLUP_MODE not defined!"
#endif
#if (!( SPI_CHANNEL_5_SCLK_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
        SPI_CHANNEL_5_SCLK_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
    #error "SPI_CHANNEL_5_SCLK_PULLUP_MODE configuration value is not valid!"
#endif

//-------------------------------------------- CS0 ------------------------------------------------
#if (SPI_CHANNEL_5_CS_0_IN_USE == ON)
    #if   (SPI_CHANNEL_5_CS_0_PORT == SPI_PORT_C && SPI_CHANNEL_5_CS_0_PIN == SPI_PIN_8 )
        #define SPI_CHANNEL_5_CS_0_ALT_FUNK (6U)
    #else
        #error "SPI_CHANNEL_5_CS_0_PORT configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_5_CS_0_OUTPUT_MODE
        #error "SPI_CHANNEL_5_CS_0_OUTPUT_MODE not defined!"
    #endif
    #if (!( (SPI_CHANNEL_5_CS_0_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
            (SPI_CHANNEL_5_CS_0_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
        #error "SPI_CHANNEL_5_CS_0_OUTPUT_MODE configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_5_CS_0_PULLUP_MODE
        #error "SPI_CHANNEL_5_CS_0_PULLUP_MODE not defined!"
    #endif
    #if (!( SPI_CHANNEL_5_CS_0_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
            SPI_CHANNEL_5_CS_0_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
        #error "SPI_CHANNEL_5_CS_0_PULLUP_MODE configuration value is not valid!"
    #endif
#endif

//-------------------------------------------- CS1 ------------------------------------------------
#if (SPI_CHANNEL_5_CS_1_IN_USE == ON)
    #if   (SPI_CHANNEL_5_CS_1_PORT == SPI_PORT_C && SPI_CHANNEL_5_CS_1_PIN == SPI_PIN_9 )
        #define SPI_CHANNEL_5_CS_1_ALT_FUNK (6U)
    #else
        #error "SPI_CHANNEL_5_CS_1_PORT configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_5_CS_1_OUTPUT_MODE
        #error "SPI_CHANNEL_5_CS_1_OUTPUT_MODE not defined!"
    #endif
    #if (!( (SPI_CHANNEL_5_CS_1_OUTPUT_MODE == SPI_OUTPUT_MODE_PUSH_PULL) || \
            (SPI_CHANNEL_5_CS_1_OUTPUT_MODE == SPI_OUTPUT_MODE_OPEN_DRAIN) ) )
        #error "SPI_CHANNEL_5_CS_1_OUTPUT_MODE configuration value is not valid!"
    #endif

    #ifndef SPI_CHANNEL_5_CS_1_PULLUP_MODE
        #error "SPI_CHANNEL_5_CS_1_PULLUP_MODE not defined!"
    #endif
    #if (!( SPI_CHANNEL_5_CS_1_PULLUP_MODE == SPI_PULLUP_MODE_DISABLE || \
            SPI_CHANNEL_5_CS_1_PULLUP_MODE == SPI_PULLUP_MODE_ENABLE ) )
        #error "SPI_CHANNEL_5_CS_1_PULLUP_MODE configuration value is not valid!"
    #endif
#endif

#endif // end of SPI_CHANNEL_5_IN_USE



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
/* #define SPI_HW_GET_PIN_FUNC(nChannel) \
    .nMOSIfunc = SPI_HW_CHANNEL_##nChannel##_MOSI_FUNC, \
    .nMISOfunc = SPI_HW_CHANNEL_##nChannel##_MISO_FUNC, \
    .nSCLKfunc = SPI_HW_CHANNEL_##nChannel##_SCLK_FUNC, \
    .nCSfunc   = SPI_HW_CHANNEL_##nChannel##_CS_FUNC*/

//! SPI low-level parameters for channel 0
#if (ON == SPI_CHANNEL_0_IN_USE)
static SPI_HW_CHANNEL_PARAMS SPI_HW_stParamsChannel_0 = 
{
    // SPI_HW_GET_PIN_FUNC(0)
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