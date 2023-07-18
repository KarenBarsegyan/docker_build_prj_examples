//**************************************************************************************************
// @Filename      ehal_lib.h
//--------------------------------------------------------------------------------------------------
// @Description   Interface of the EHAL library
//--------------------------------------------------------------------------------------------------
// @Version       1.1.0
//--------------------------------------------------------------------------------------------------
// @Date          08.10.2019
//--------------------------------------------------------------------------------------------------
// @History       Version  Author  Comment
// 27.05.2019     1.0.0    SHA     First release
// 08.10.2019     1.1.0    SRM     1) CAN driver interfaces added.
//                                 2) BTLDR service interfaces added.
//**************************************************************************************************

#ifndef EHAL_LIB
#define EHAL_LIB



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

#include "compiler.h"
#include "general.h"



//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************

// Timer counter size
typedef U32 TIMER_SZ;

// PIT counter size
typedef U32 PIT_SZ;

// Timer callback function type
typedef void (*TIMER_CALLBACK)(void);

// Callback function type
typedef void (*PIT_CALLBACK)(void);

// INDM callback function type
typedef void (*INDM_CALLBACK)(const U8 nInductorNum);

// Type of callback function pointer for camshaft
typedef void (*FAR BSYNC_CAM_CALLBACK)(U8 nTypeEvent);

// Inductor current curve parameters structure type
typedef struct INDM_INDUCTOR_CURVE_PHASE_DURATIONS_str
{
    U16 ShortTime;
    U16 ChargeTime;
    U16 BoostTime;
    U16 PeakTime;
    U16 Drop1Time;
    U16 Hold1Time;
    U16 Drop2Time;
} INDM_INDUCTOR_CURVE_PHASE_DURATIONS;

// Curve current levels type
typedef struct INDM_INJECTOR_CURRENT_LEVELS_str
{
    U16 ShortHighCurrent;
    U16 ShortLowCurrent;
    U16 ChargeHighCurrent;
    U16 ChargeLowCurrent;
    U16 BoostHighCurrent;
    U16 BoostLowCurrent;
    U16 PeakHighCurrent;
    U16 PeakLowCurrent;
    U16 Drop1HighCurrent;
    U16 Drop1LowCurrent;
    U16 Hold1HighCurrent;
    U16 Hold1LowCurrent;
    U16 Drop2HighCurrent;
    U16 Drop2LowCurrent;
    U16 Hold2HighCurrent;
    U16 Hold2LowCurrent;
} INDM_INJECTOR_CURRENT_LEVELS;

// Curve modulation parameters type
typedef struct INDM_INDUCTOR_PWM_PARAMS_str
{
    U16 ChargePeriod;
    U16 ChargeDuty;
    U16 Hold1Period;
    U16 Hold1Duty;
    U16 Hold2Period;
    U16 Hold2Duty;
} INDM_INDUCTOR_PWM_PARAMS;

// Diagnostic limits type
typedef struct INDM_DIAG_LIMITS_str
{
    U16 ShortMaxTime;
    U16 ShortMinTime;
    U16 ChargeMaxTime;
    U16 ChargeMinTime;
    U16 BoostMaxTime;
    U16 BoostMinTime;
    U16 PeakMaxTime;
    U16 PeakMinTime;
    U16 Drop1MaxTime;
    U16 Drop1MinTime;
    U16 Hold1MaxTime;
    U16 Hold1MinTime;
    U16 Drop2MaxTime;
    U16 Drop2MinTime;
    U16 Hold2MaxTime;
    U16 Hold2MinTime;
} INDM_DIAG_LIMITS;

// Inductive load status type
typedef enum INDM_STATUS_str
{
    INDM_STATUS_NOT_APPLICABLE      = (U8)0,    // Inductive load status is not applicable
    INDM_STATUS_NO_FAILURE          = (U8)1,    // Inductive load state is OK
    INDM_STATUS_FAULT_UNKNOWN       = (U8)2,    // Inductive load state is unknown fault
    INDM_STATUS_SHRT_CIRC_BAT       = (U8)3,    // Short circuit to bat
    INDM_STATUS_OPEN_LOAD           = (U8)4,    // Open load
    INDM_STATUS_SHRT_CIRC_GND       = (U8)5,    // Short circuit to ground in on
    INDM_STATUS_OVER_VOLTAGE        = (U8)6,    // Over voltage
    INDM_STATUS_UNDER_VOLTAGE       = (U8)7,    // Under voltage
    INDM_STATUS_OVER_CURRENT        = (U8)8,    // Over current
    INDM_STATUS_UNDER_CURRENT       = (U8)9,    // Under current
    INDM_STATUS_OVER_TEMPERATURE    = (U8)10,   // Over temperature
    INDM_STATUS_TIMEOUT             = (U8)11,   //
} INDM_STATUS;



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

//**************************************************************************************************
// Communication interfaces
//**************************************************************************************************

// COM Router
#define EHAL_COM_Router_Init                        COMR_Init
#define EHAL_COM_Router_DeInit                      COMR_DeInit

// ISO 14229
#define EHAL_ISO14229_Init                          ISO14229_Init
#define EHAL_ISO14229_DeInit                        ISO14229_DeInit
#define EHAL_ISO14229_Process                       ISO14229_Process

#define EHAL_ISO14229_DSCInit                       ISO14229_DSCInit
#define EHAL_ISO14229_RDBIInit                      ISO14229_RDBIInit
#define EHAL_ISO14229_WMBAInit                      ISO14229_WMBAInit
#define EHAL_ISO14229_CDIInit                       ISO14229_CDIInit
#define EHAL_ISO14229_CCInit                        ISO14229_CCInit
#define EHAL_ISO14229_RDTCIInit                     ISO14229_RDTCIInit
#define EHAL_ISO14229_IOCBIInit                     ISO14229_IOCBIInit
#define EHAL_ISO14229_RCInit                        ISO14229_RCInit
#define EHAL_ISO14229_RDInit                        ISO14229_RDInit
#define EHAL_ISO14229_TDInit                        ISO14229_TDInit
#define EHAL_ISO14229_RTEInit                       ISO14229_RTEInit
#define EHAL_ISO14229_CDTCSInit                     ISO14229_CDTCSInit
#define EHAL_ISO14229_WDBIInit                      ISO14229_WDBIInit
#define EHAL_ISO14229_ERInit                        ISO14229_ERInit
#define EHAL_ISO14229_OBDInit                       ISO14229_OBDInit
#define EHAL_ISO14229_GetCurrentSecurityLevel       ISO14229_GetCurrentSecurityLevel

#define EHAL_ISO14229_SESSION_DEFAULT               ISO14229_SESSION_DEFAULT
#define EHAL_ISO14229_SESSION_PROGRAMMING           ISO14229_SESSION_PROGRAMMING
#define EHAL_ISO14229_SESSION_EXT_DIAGNOSTIC        ISO14229_SESSION_EXT_DIAGNOSTIC
#define EHAL_ISO14229_SESSION_EOL_SS                ISO14229_SESSION_EOL_SS
#define EHAL_ISO14229_SESSION_EOL_VM                ISO14229_SESSION_EOL_VM

#define EHAL_ISO14229_SEC_LEVEL_DEFAULT             ISO14229_SESSION_DEFAULT
#define EHAL_ISO14229_SEC_LEVEL_PROGRAMMING         ISO14229_SESSION_PROGRAMMING
#define EHAL_ISO14229_SEC_LEVEL_EXT_DIAGNOSTIC      ISO14229_SESSION_EXT_DIAGNOSTIC
#define EHAL_ISO14229_SEC_LEVEL_END_OF_LINE         ISO14229_SESSION_END_OF_LINE

// EOL
#define EHAL_EOL_Init                               ISO14229EOL_Init
#define EHAL_EOL_DeInit                             ISO14229EOL_DeInit
#define EHAL_EOL_ActivationInit                     ISO14229EOL_ActivationInit
#define EHAL_EOL_CmdInit                            ISO14229EOL_CmdInit

// ISO 14229 SS
#define EHAL_ISO14229SS_Init                        ISO14229SS_Init

// ECU ID
#define EHAL_ECUID_Init                             ECUID_Init
#define EHAL_ECUID_DeInit                           ECUID_DeInit
#define EHAL_ECUID_SetJobCallback                   ECUID_SetJobCallback
#define EHAL_ECUID_Load                             ECUID_Load
#define EHAL_ECUID_Store                            ECUID_Store

// Fingerprint Storage
#define EHAL_FPS_Init                               FPS_Init

// CAN driver interface
#define EHAL_COM_CAN_Init                           CAN_Init
#define EHAL_COM_CAN_DeInit                         CAN_DeInit
#define EHAL_COM_CAN_Read                           CAN_Read
#define EHAL_COM_CAN_Write                          CAN_Write
#define EHAL_COM_CAN_WriteDirect                    CAN_WriteDirect
#define EHAL_COM_CAN_WakeUpEnable                   CAN_WakeUpEnable
#define EHAL_COM_CAN_SetRXCallback                  CAN_SetRXCallback
#define EHAL_COM_CAN_SetTXCallback                  CAN_SetTXCallback
#define EHAL_COM_CAN_SetDirectRXCallback            CAN_SetDirectRXCallback
#define EHAL_COM_CAN_SetDirectTXCallback            CAN_SetDirectTXCallback

// CAN transceiver interface
#define EHAL_COM_CANTRCV_Init                       CANTRCV_Init
#define EHAL_COM_CANTRCV_DeInit                     CANTRCV_DeInit
#define EHAL_COM_CANTRCV_PowerDown                  CANTRCV_PowerDown
#define EHAL_COM_CANTRCV_PowerUp                    CANTRCV_PowerUp
#define EHAL_COM_CANTRCV_GetPowerState              CANTRCV_GetPowerState

// UART interface
#define EHAL_COM_UART_Init                          UART_Init
#define EHAL_COM_UART_DeInit                        UART_DeInit
#define EHAL_COM_UART_Read                          UART_Read
#define EHAL_COM_UART_Write                         UART_Write
#define EHAL_COM_UART_Purge                         UART_Purge
#define EHAL_COM_UART_GetRXBytesCount               UART_GetRXBytesCount
#define EHAL_COM_UART_SetBaudrate                   UART_SetBaudrate
#define EHAL_COM_UART_SetCallbackFunction           UART_SetCallbackFunction

// SPI interface
#define EHAL_COM_SPI_Init                           SPI_Init
#define EHAL_COM_SPI_DeInit                         SPI_DeInit
#define EHAL_COM_SPI_Read                           SPI_Read
#define EHAL_COM_SPI_Write                          SPI_Write
#define EHAL_COM_SPI_Purge                          SPI_Purge
#define EHAL_COM_SPI_GetRXItemsCount                SPI_GetRXItemsCount
#define EHAL_COM_SPI_SetMode                        SPI_SetMode
#define EHAL_COM_SPI_SetBaudrate                    SPI_SetBaudrate
#define EHAL_COM_SPI_SetTransferFormat              SPI_SetTransferFormat
#define EHAL_COM_SPI_SetCallbackFunction            SPI_SetCallbackFunction

// LIN interface
#define EHAL_COM_LIN_Init                           LIN_Init
#define EHAL_COM_LIN_DeInit                         LIN_DeInit
#define EHAL_COM_LIN_Read                           LIN_Read
#define EHAL_COM_LIN_Write                          LIN_Write
#define EHAL_COM_LIN_SetRXCallback                  LIN_SetRXCallback
#define EHAL_COM_LIN_SetTXCallback                  LIN_SetTXCallback
#define EHAL_COM_LIN_PowerDown                      LIN_PowerDown
#define EHAL_COM_LIN_PowerUp                        LIN_PowerUp
#define EHAL_COM_LIN_GetPowerState                  LIN_GetPowerState
#define EHAL_COM_LIN_WakeupEnable                   LIN_WakeupEnable
#define EHAL_COM_LIN_SetWakeupEventHandler          LIN_SetWakeupEventHandler

// LIN transceiver interface
#define EHAL_COM_LINTRCV_Init                       LINTRCV_Init
#define EHAL_COM_LINTRCV_DeInit                     LINTRCV_DeInit
#define EHAL_COM_LINTRCV_PowerDown                  LINTRCV_PowerDown
#define EHAL_COM_LINTRCV_PowerUp                    LINTRCV_PowerUp
#define EHAL_COM_LINTRCV_GetPowerState              LINTRCV_GetPowerState

// CCP interface
#define EHAL_COM_CCP_Init                           CCP_Init
#define EHAL_COM_CCP_ProcessCmd                     CCP_ProcessCmd
#define EHAL_COM_CCP_ProcessDAQ                     CCP_ProcessDAQ
#define EHAL_COM_CCP_SaveCalibrationData            CCP_SaveCalibrationData



//**************************************************************************************************
// Input/output interfaces
//**************************************************************************************************

// IO manager interface
#define EHAL_IO_MGR_Init                            IO_Init
#define EHAL_IO_MGR_DeInit                          IO_DeInit
#define EHAL_IO_MGR_D_GetChannelDirection           IO_D_GetChannelDirection
#define EHAL_IO_MGR_D_SetChannelDirection           IO_D_SetChannelDirection
#define EHAL_IO_MGR_D_GetChannelState               IO_D_GetChannelState
#define EHAL_IO_MGR_D_SetChannelState               IO_D_SetChannelState
#define EHAL_IO_MGR_D_GetChannelStatus              IO_D_GetChannelStatus
#define EHAL_IO_MGR_D_SetChannelStatus              IO_D_SetChannelStatus
#define EHAL_IO_MGR_A_GetChannelValue               IO_A_GetChannelValue
#define EHAL_IO_MGR_A_SetChannelValue               IO_A_SetChannelValue

#define EHAL_IO_MGR_P_StartChannel                  IO_P_StartChannel
#define EHAL_IO_MGR_P_StopChannel                   IO_P_StopChannel
#define EHAL_IO_MGR_P_GetChannelTime                IO_P_GetChannelTime
#define EHAL_IO_MGR_P_SetChannelTime                IO_P_SetChannelTime
#define EHAL_IO_MGR_P_SetChannelPolarity            IO_P_SetChannelPolarity
#define EHAL_IO_MGR_P_SetCallbackFunction           IO_P_SetCallbackFunction

// PAD interface
#define EHAL_IO_PAD_Init                            PAD_Init
#define EHAL_IO_PAD_DeInit                          PAD_DeInit
#define EHAL_IO_PAD_GetKeyState                     PAD_GetKeyState
#define EHAL_IO_PAD_SetKeyEventHandler              PAD_SetKeyEventHandler

// LED interface
#define EHAL_IO_LED_Init                            LED_Init
#define EHAL_IO_LED_DeInit                          LED_DeInit
#define EHAL_IO_LED_SetState                        LED_SetState

// ENC interface
#define EHAL_IO_ENC_Init                            ENC_Init
#define EHAL_IO_ENC_DeInit                          ENC_DeInit
#define EHAL_IO_ENC_GetPinState                     ENC_GetPinState
#define EHAL_IO_ENC_GetCurPosition                  ENC_GetCurPosition
#define EHAL_IO_ENC_SetCurPosition                  ENC_SetCurPosition
#define EHAL_IO_ENC_SetScale                        ENC_SetScale
#define EHAL_IO_ENC_SetCallbackFunction             ENC_SetCallbackFunction

// Signal manager interface
#define EHAL_IO_SIGMAN_Init                         SIGMAN_Init
#define EHAL_IO_SIGMAN_DeInit                       SIGMAN_DeInit
#define EHAL_IO_SIGMAN_GetSignalState               SIGMAN_GetSignalState
#define EHAL_IO_SIGMAN_SetSignalState               SIGMAN_SetSignalState



//**************************************************************************************************
// Memory interfaces
//**************************************************************************************************

// Memory manager interface
#define EHAL_MEMMAN_Init                            MEMMAN_Init
#define EHAL_MEMMAN_DeInit                          MEMMAN_DeInit
#define EHAL_MEMMAN_SetJobCallback                  MEMMAN_SetJobCallback
#define EHAL_MEMMAN_Load                            MEMMAN_Load
#define EHAL_MEMMAN_Store                           MEMMAN_Store
#define EHAL_MEMMAN_GetJobResult                    MEMMAN_GetJobResult
#define EHAL_MEMMAN_GetMemoryStatus                 MEMMAN_GetMemoryStatus
#define EHAL_MEMMAN_SetMemoryStatus                 MEMMAN_SetMemoryStatus



//**************************************************************************************************
// Timer interfaces
//**************************************************************************************************

// General timer interface
#define EHAL_TMR_TIMER_Init                         TIMER_Init
#define EHAL_TMR_TIMER_GetTime                      TIMER_GetTime
#define EHAL_TMR_TIMER_SetTime                      TIMER_SetTime
#define EHAL_TMR_TIMER_StartTimer                   TIMER_StartTimer
#define EHAL_TMR_TIMER_StopTimer                    TIMER_StopTimer
#define EHAL_TMR_TIMER_GetTickPeriod                TIMER_GetTickPeriod
#define EHAL_TMR_TIMER_SetCallbackFunction          TIMER_SetCallbackFunction

// PIT timer interface
#define EHAL_TMR_PIT_Init                           PIT_Init
#define EHAL_TMR_PIT_DeInit                         PIT_DeInit
#define EHAL_TMR_PIT_GetTime                        PIT_GetTime
#define EHAL_TMR_PIT_SetTime                        PIT_SetTime
#define EHAL_TMR_PIT_StartTimer                     PIT_StartTimer
#define EHAL_TMR_PIT_StopTimer                      PIT_StopTimer
#define EHAL_TMR_PIT_GetTickPeriod                  PIT_GetTickPeriod
#define EHAL_TMR_PIT_SetCallbackFunction            PIT_SetCallbackFunction

// WDT timer interface
#define EHAL_TMR_WDT_Enable                         WDT_Enable
#define EHAL_TMR_WDT_Disable                        WDT_Disable
#define EHAL_TMR_WDT_Arm                            WDT_Arm
#define EHAL_TMR_WDT_ResetMCU                       WDT_ResetMCU

// Software timer interface
#define EHAL_TMR_SW_TickTimer                       SOFTTIMER_HighLevel_ISR



//**************************************************************************************************
// OS interfaces
//**************************************************************************************************

// RTOS kernel interface
#define EHAL_OS_SCHDL_Init                          SCHDL_Init
#define EHAL_OS_SCHDL_DeInit                        SCHDL_DeInit
#define EHAL_OS_SCHDL_Enable                        SCHDL_Enable
#define EHAL_OS_SCHDL_Disable                       SCHDL_Disable
#define EHAL_OS_SCHDL_StartLevel                    SCHDL_StartLevel
#define EHAL_OS_SCHDL_ActivateLevel                 SCHDL_ActivateLevel
#define EHAL_OS_SCHDL_RunLevelImmed                 SCHDL_RunLevelImmed
#define EHAL_OS_SCHDL_StartSchedule                 SCHDL_StartSchedule
#define EHAL_OS_SCHDL_IncIdleCounter                SCHDL_IncIdleCounter
#define EHAL_OS_SCHDL_GetIdleCounter                SCHDL_GetIdleCounter
#define EHAL_OS_SCHDL_GetAndResetIdleCounter        SCHDL_GetAndResetIdleCounter

// MCU interface
#define EHAL_OS_MCU_EnableInterrupts                MCU_EnableInterrupts
#define EHAL_OS_MCU_DisableInterrupts               MCU_DisableInterrupts
#define EHAL_OS_MCU_Sleep                           MCU_Sleep
#define EHAL_OS_MCU_Reset                           MCU_Reset
#define EHAL_OS_MCU_GetBusFrequency                 MCU_GetBusFrequency
#define EHAL_OS_MCU_GetResetCause                   MCU_GetResetCause

// Bootloader interface
#define EHAL_OS_BTLDR_GetROMMarkerType              BTLDR_GetROMMarkerType
#define EHAL_OS_BTLDR_SetROMMarkerType              BTLDR_SetROMMarkerType
#define EHAL_OS_BTLDR_MARKER_BTLDR                  BTLDR_MARKER_BTLDR
#define EHAL_OS_BTLDR_MARKER_APPL                   BTLDR_MARKER_APPL

// Power manager interfaces
#define EHAL_OS_POWMAN_Init                         POWMAN_Init
#define EHAL_OS_POWMAN_DeInit                       POWMAN_DeInit
#define EHAL_OS_POWMAN_SetPowerLevel                POWMAN_SetPowerLevel
#define EHAL_OS_POWMAN_SetEventHandler              POWMAN_SetEventHandler
#define EHAL_OS_POWMAN_WakeupEnable                 POWMAN_WakeupEnable



//**************************************************************************************************
// General Libraries interfaces
//**************************************************************************************************

// Checksum interface
#define EHAL_GLIB_CHECKSUM_Init                     CS_Init
#define EHAL_GLIB_CHECKSUM_Calc                     CS_Calc
#define EHAL_GLIB_CHECKSUM_GetCalculatedChecksum    CS_GetCalculatedChecksum
#define EHAL_GLIB_CHECKSUM_GetPreCalculatedChecksum CS_GetPreCalculatedChecksum
#define EHAL_GLIB_CHECKSUM_IsCalculated             CS_IsCalculated

// CRC32 interface
#define EHAL_GLIB_CRC32_Init                        CRC32_Init
#define EHAL_GLIB_CRC32_Calc                        CRC32_Calc
#define EHAL_GLIB_CRC32_GetCalculatedCRC            CRC32_GetCalculatedCRC
#define EHAL_GLIB_CRC32_GetPreCalculatedCRC         CRC32_GetPreCalculatedCRC
#define EHAL_GLIB_CRC32_IsCalculated                CRC32_IsCalculated

// CRC8 interface
#define EHAL_GLIB_Crc8_Dallas                       Crc8_Dallas

// Dictionary interface
#define EHAL_GLIB_DICT_Init                         DICT_Init
#define EHAL_GLIB_DICT_PutData                      DICT_PutData
#define EHAL_GLIB_DICT_GetData                      DICT_GetData
#define EHAL_GLIB_DICT_Purge                        DICT_Purge
#define EHAL_GLIB_DICT_GetKeySize                   DICT_GetKeySize
#define EHAL_GLIB_DICT_GetFreeItemsNum              DICT_GetFreeItemsNum
#define EHAL_GLIB_DICT_GetCollisionsNum             DICT_GetCollisionsNum
#define EHAL_GLIB_DICT_GetCollisionsMaxLen          DICT_GetCollisionsMaxLen

// Security Access interface
#define EHAL_GLIB_SA_CalculateKey                   SA_CalculateKey

// ISO 15765 interface
#define EHAL_GLIB_ISO15765_SegmentMsg               API_CAN15765_Segment_Msg

// Array interface
#define EHAL_GLIB_ARRAY_Merge                       API_Buffer_Merge16

// Random Number interface
#define EHAL_GLIB_RND_GetRandomNum                  Rand_Num

// MSE Data Access MULTI interface
#define EHAL_GLIB_MSE_DA_MULTI_ReadParameter1               MSE_DA_MULTI_ReadParameter1
#define EHAL_GLIB_MSE_DA_MULTI_ReadParameter2               MSE_DA_MULTI_ReadParameter2
#define EHAL_GLIB_MSE_DA_MULTI_ReadParameter4               MSE_DA_MULTI_ReadParameter4
#define EHAL_GLIB_MSE_DA_MULTI_ReadParameter1I              MSE_DA_MULTI_ReadParameter1I
#define EHAL_GLIB_MSE_DA_MULTI_ReadParameter2I              MSE_DA_MULTI_ReadParameter2I
#define EHAL_GLIB_MSE_DA_MULTI_ReadParameter4I              MSE_DA_MULTI_ReadParameter4I
#define EHAL_GLIB_MSE_DA_MULTI_UpdateCoordinate1s           MSE_DA_MULTI_UpdateCoordinate1s
#define EHAL_GLIB_MSE_DA_MULTI_UpdateCoordinate1u           MSE_DA_MULTI_UpdateCoordinate1u
#define EHAL_GLIB_MSE_DA_MULTI_UpdateCoordinate2s           MSE_DA_MULTI_UpdateCoordinate2s
#define EHAL_GLIB_MSE_DA_MULTI_UpdateCoordinate2u           MSE_DA_MULTI_UpdateCoordinate2u
#define EHAL_GLIB_MSE_DA_MULTI_UpdateCoordinateRW1s         MSE_DA_MULTI_UpdateCoordinateRW1s
#define EHAL_GLIB_MSE_DA_MULTI_UpdateCoordinateRW1u         MSE_DA_MULTI_UpdateCoordinateRW1u
#define EHAL_GLIB_MSE_DA_MULTI_UpdateCoordinateRW2s         MSE_DA_MULTI_UpdateCoordinateRW2s
#define EHAL_GLIB_MSE_DA_MULTI_UpdateCoordinateRW2u         MSE_DA_MULTI_UpdateCoordinateRW2u
#define EHAL_GLIB_MSE_DA_MULTI_WriteVector1                 MSE_DA_MULTI_WriteVector1
#define EHAL_GLIB_MSE_DA_MULTI_WriteVector1I                MSE_DA_MULTI_WriteVector1I
#define EHAL_GLIB_MSE_DA_MULTI_WriteVector2                 MSE_DA_MULTI_WriteVector2
#define EHAL_GLIB_MSE_DA_MULTI_WriteVector2I                MSE_DA_MULTI_WriteVector2I
#define EHAL_GLIB_MSE_DA_MULTI_WriteVector4                 MSE_DA_MULTI_WriteVector4
#define EHAL_GLIB_MSE_DA_MULTI_WriteVector4I                MSE_DA_MULTI_WriteVector4I
#define EHAL_GLIB_MSE_DA_MULTI_Write2DTable1                MSE_DA_MULTI_Write2DTable1
#define EHAL_GLIB_MSE_DA_MULTI_Write2DTable1I               MSE_DA_MULTI_Write2DTable1I
#define EHAL_GLIB_MSE_DA_MULTI_Write2DTable2                MSE_DA_MULTI_Write2DTable2
#define EHAL_GLIB_MSE_DA_MULTI_Write2DTable2I               MSE_DA_MULTI_Write2DTable2I
#define EHAL_GLIB_MSE_DA_MULTI_Write2DTable4                MSE_DA_MULTI_Write2DTable4
#define EHAL_GLIB_MSE_DA_MULTI_Write2DTable4I               MSE_DA_MULTI_Write2DTable4I
#define EHAL_GLIB_MSE_DA_MULTI_ReadVectorNearest1           MSE_DA_MULTI_ReadVectorNearest1
#define EHAL_GLIB_MSE_DA_MULTI_ReadVectorNearest1I          MSE_DA_MULTI_ReadVectorNearest1I
#define EHAL_GLIB_MSE_DA_MULTI_ReadVectorNearest2           MSE_DA_MULTI_ReadVectorNearest2
#define EHAL_GLIB_MSE_DA_MULTI_ReadVectorNearest2I          MSE_DA_MULTI_ReadVectorNearest2I
#define EHAL_GLIB_MSE_DA_MULTI_ReadVectorNearest4           MSE_DA_MULTI_ReadVectorNearest4
#define EHAL_GLIB_MSE_DA_MULTI_ReadVectorNearest4I          MSE_DA_MULTI_ReadVectorNearest4I
#define EHAL_GLIB_MSE_DA_MULTI_Read2DTableNearest1          MSE_DA_MULTI_Read2DTableNearest1
#define EHAL_GLIB_MSE_DA_MULTI_Read2DTableNearest1I         MSE_DA_MULTI_Read2DTableNearest1I
#define EHAL_GLIB_MSE_DA_MULTI_Read2DTableNearest2          MSE_DA_MULTI_Read2DTableNearest2
#define EHAL_GLIB_MSE_DA_MULTI_Read2DTableNearest2I         MSE_DA_MULTI_Read2DTableNearest2I
#define EHAL_GLIB_MSE_DA_MULTI_Read2DTableNearest4          MSE_DA_MULTI_Read2DTableNearest4
#define EHAL_GLIB_MSE_DA_MULTI_Read2DTableNearest4I         MSE_DA_MULTI_Read2DTableNearest4I
#define EHAL_GLIB_MSE_DA_MULTI_GetParameterData1            MSE_DA_MULTI_GetParameterData1
#define EHAL_GLIB_MSE_DA_MULTI_GetParameterData2            MSE_DA_MULTI_GetParameterData2
#define EHAL_GLIB_MSE_DA_MULTI_GetParameterData4            MSE_DA_MULTI_GetParameterData4
#define EHAL_GLIB_MSE_DA_MULTI_ReadExtData1                 MSE_DA_MULTI_ReadExtData1
#define EHAL_GLIB_MSE_DA_MULTI_ReadExtData1I                MSE_DA_MULTI_ReadExtData1I
#define EHAL_GLIB_MSE_DA_MULTI_ReadExtData2                 MSE_DA_MULTI_ReadExtData2
#define EHAL_GLIB_MSE_DA_MULTI_ReadExtData2I                MSE_DA_MULTI_ReadExtData2I
#define EHAL_GLIB_MSE_DA_MULTI_ReadExtData4                 MSE_DA_MULTI_ReadExtData4
#define EHAL_GLIB_MSE_DA_MULTI_ReadExtData4I                MSE_DA_MULTI_ReadExtData4I
#define EHAL_GLIB_MSE_DA_MULTI_ReadExtKey                   MSE_DA_MULTI_ReadExtKey
#define EHAL_GLIB_MSE_DA_MULTI_ReadExtKeyI                  MSE_DA_MULTI_ReadExtKeyI
#define EHAL_GLIB_MSE_DA_MULTI_GetNode2s                    MSE_DA_MULTI_GetNode2s
#define EHAL_GLIB_MSE_DA_MULTI_GetNode2u                    MSE_DA_MULTI_GetNode2u
#define EHAL_GLIB_MSE_DA_MULTI_GetVectorY_2                 MSE_DA_MULTI_GetVectorY_2
#define EHAL_GLIB_MSE_DA_MULTI_ParamToParam                 MSE_DA_MULTI_ParamToParam
#define EHAL_GLIB_MSE_DA_MULTI_ParamToParamDirectROM        MSE_DA_MULTI_ParamToParamDirectROM
#define EHAL_GLIB_MSE_DA_MULTI_ParamToParamDirect           MSE_DA_MULTI_ParamToParamDirect
#define EHAL_GLIB_MSE_DA_MULTI_ParameterToEEPROM            MSE_DA_MULTI_ParameterToEEPROM
#define EHAL_GLIB_MSE_DA_MULTI_ParameterFromEEPROM          MSE_DA_MULTI_ParameterFromEEPROM
#define EHAL_GLIB_MSE_DA_MULTI_ParameterToEEPROMDirectROM   MSE_DA_MULTI_ParameterToEEPROMDirectROM
#define EHAL_GLIB_MSE_DA_MULTI_ParameterToEEPROMDirect      MSE_DA_MULTI_ParameterToEEPROMDirect
#define EHAL_GLIB_MSE_DA_MULTI_ParameterFromEEPROMDirect    MSE_DA_MULTI_ParameterFromEEPROMDirect

// Sorting interface
#define EHAL_GLIB_SORT_Mid3                         SORT_Mid3
#define EHAL_GLIB_SORT_Mid5                         SORT_Mid5
#define EHAL_GLIB_SORT_Mid10                        SORT_Mid10
#define EHAL_GLIB_SORT_DfrMid32                     SORT_DfrMid32
#define EHAL_GLIB_SORT_DfrMid42                     SORT_DfrMid42
#define EHAL_GLIB_SORT_DfrMid53                     SORT_DfrMid53
#define EHAL_GLIB_SORT_DfrMid63                     SORT_DfrMid63
#define EHAL_GLIB_SORT_DfrMid74                     SORT_DfrMid74
#define EHAL_GLIB_SORT_DfrMid84                     SORT_DfrMid84

// Convert input param "addr", that contains address, to arithmetic pointer
#define EHAL_GLIB_ConvertToPtr_8bit                 ConvertToPtr_8bit
#define EHAL_GLIB_ConvertToPtr_S8bit                ConvertToPtr_S8bit
#define EHAL_GLIB_ConvertToPtr_16bit                ConvertToPtr_16bit
#define EHAL_GLIB_ConvertToPtr_S16bit               ConvertToPtr_S16bit
#define EHAL_GLIB_ConvertToPtr_32bit                ConvertToPtr_32bit
#define EHAL_GLIB_ConvertToPtr_S32bit               ConvertToPtr_S32bit

// Functions for writing into dynamic tables and vectors with smoothing (filter)
#define EHAL_GLIB_DYN_TBL_Filter1Ds1                DYN_TBL_Filter1Ds1
#define EHAL_GLIB_DYN_TBL_Filter1Du1                DYN_TBL_Filter1Du1
#define EHAL_GLIB_DYN_TBL_Filter1Ds2                DYN_TBL_Filter1Ds2
#define EHAL_GLIB_DYN_TBL_Filter1Du2                DYN_TBL_Filter1Du2
#define EHAL_GLIB_DYN_TBL_Filter1Ds4                DYN_TBL_Filter1Ds4
#define EHAL_GLIB_DYN_TBL_Filter1Du4                DYN_TBL_Filter1Du4
#define EHAL_GLIB_DYN_TBL_Filter2Ds1                DYN_TBL_Filter2Ds1
#define EHAL_GLIB_DYN_TBL_Filter2Du1                DYN_TBL_Filter2Du1
#define EHAL_GLIB_DYN_TBL_Filter2Ds2                DYN_TBL_Filter2Ds2
#define EHAL_GLIB_DYN_TBL_Filter2Du2                DYN_TBL_Filter2Du2
#define EHAL_GLIB_DYN_TBL_Filter2Ds4                DYN_TBL_Filter2Ds4
#define EHAL_GLIB_DYN_TBL_Filter2Du4                DYN_TBL_Filter2Du4

// VBSEC2 interface
#define EHAL_GLIB_VBSEC2_Init                       VBSEC2_Init
#define EHAL_GLIB_VBSEC2_CalcRequest                VBSEC2_CalcRequest
#define EHAL_GLIB_VBSEC2_DecoderResponse            VBSEC2_DecoderResponse
#define EHAL_GLIB_VBSEC2_CalcNewPassword            VBSEC2_CalcNewPassword
#define EHAL_GLIB_VBSEC2_RepeatRequest              VBSEC2_RepeatRequest
#define EHAL_GLIB_VBSEC2_CRC16                      VBSEC2_CRC16



//**************************************************************************************************
// Services Libraries interfaces
//**************************************************************************************************

// Random number generator
#define EHAL_SRV_Random_Init                        Random_Init
#define EHAL_SRV_Random_GetStatus                   Random_GetStatus
#define EHAL_SRV_Random_GetData                     Random_GetData
#define EHAL_SRV_Random_HighLevelISR                Random_HighLevelISR



//**************************************************************************************************
// Special Libraries interfaces
//**************************************************************************************************


// Angle Synchronization interface
#define EHAL_SLIB_ANG_SYN_Crk_InitAcquisit          BSYNC_CrshSA_Init_Acquisit
#define EHAL_SLIB_ANG_SYN_Crk_EnableAcquisit        BSYNC_CrshSA_Enable_Acquisit
#define EHAL_SLIB_ANG_SYN_Crk_GetEventTime          BSYNC_CrshSA_Get_EventTime
#define EHAL_SLIB_ANG_SYN_Crk_GetEventTime32        BSYNC_CrshSA_Get_EventTime32
#define EHAL_SLIB_ANG_SYN_Crk_GetEventType          BSYNC_CrshSA_Get_EventType
#define EHAL_SLIB_ANG_SYN_Crk_GetEdgePer            BSYNC_CrshSA_Get_EdgePer
#define EHAL_SLIB_ANG_SYN_Crk_GetEdgeAngCounter     BSYNC_CrshSA_Get_EdgeAngCounter
#define EHAL_SLIB_ANG_SYN_Crk_GetAngCounter         BSYNC_CrshSA_Get_AngCounter
#define EHAL_SLIB_ANG_SYN_Crk_GetEdgeTimeMonitor    BSYNC_CrshSA_Get_EdgeTimeMonitor
#define EHAL_SLIB_ANG_SYN_Crk_GetGlobToothTime      BSYNC_CrshSA_Get_GlobToothTime
#define EHAL_SLIB_ANG_SYN_Crk_GetTimeOut            BSYNC_CrshSA_Get_TimeOut
#define EHAL_SLIB_ANG_SYN_Crk_GetSignalLevel        BSYNC_CrshSA_Get_SignalLevel
#define EHAL_SLIB_ANG_SYN_Crk_GetGlitchState        BSYNC_CrshSA_Get_GlitchState
#define EHAL_SLIB_ANG_SYN_Crk_GetSpikeState         BSYNC_CrshSA_Get_SpikeState
#define EHAL_SLIB_ANG_SYN_Crk_ResetGlitchState      BSYNC_CrshSA_Reset_GlitchState
#define EHAL_SLIB_ANG_SYN_Crk_ResetSpikeState       BSYNC_CrshSA_Reset_SpikeState
#define EHAL_SLIB_ANG_SYN_Crk_SetEdgeType           BSYNC_CrshSA_Set_EdgeType
#define EHAL_SLIB_ANG_SYN_Crk_SetEventType          BSYNC_CrshSA_Set_EventType
#define EHAL_SLIB_ANG_SYN_Crk_SetStartDelay         BSYNC_CrshSA_Set_StartDelay
#define EHAL_SLIB_ANG_SYN_Crk_SetFilterTime         BSYNC_CrshSA_Set_FilterTime
#define EHAL_SLIB_ANG_SYN_Crk_SetEdgeFilterTime     BSYNC_CrshSA_Set_EdgeFilterTime
#define EHAL_SLIB_ANG_SYN_Crk_SetEdgeFilterDir      BSYNC_CrshSA_Set_EdgeFilterMode
#define EHAL_SLIB_ANG_SYN_Crk_SetTimeOut            BSYNC_CrshSA_Set_TimeOut
#define EHAL_SLIB_ANG_SYN_Crk_SetEdgePer            BSYNC_CrshSA_Set_EdgePer
#define EHAL_SLIB_ANG_SYN_Crk_SetDebugRegister      BSYNC_CrshSA_Set_DebugRegister
#define EHAL_SLIB_ANG_SYN_Crk_SetCallbackFunction   BSYNC_CrshSA_Set_CallbackFunction
#define EHAL_SLIB_ANG_SYN_Crk_LatchEventData        BSYNC_CrshSA_Latch_EventData

#define EHAL_SLIB_ANG_SYN_Cam_Init                  BSYNC_CamSA_Init
#define EHAL_SLIB_ANG_SYN_Cam_InitAcquisit          BSYNC_CamSA_Init_Acquisit
#define EHAL_SLIB_ANG_SYN_Cam_EnableAcquisit        BSYNC_CamSA_Enable_Acquisit
#define EHAL_SLIB_ANG_SYN_Cam_GetEdgeTime           BSYNC_CamSA_Get_EdgeTime
#define EHAL_SLIB_ANG_SYN_Cam_GetEdgeTime32         BSYNC_CamSA_Get_EdgeTime32
#define EHAL_SLIB_ANG_SYN_Cam_GetCrkEventTime       BSYNC_CamSA_Get_CrshEventTime
#define EHAL_SLIB_ANG_SYN_Cam_GetCrkEventTime32     BSYNC_CamSA_Get_CrshEventTime32
#define EHAL_SLIB_ANG_SYN_Cam_GetEventType          BSYNC_CamSA_Get_EventType
#define EHAL_SLIB_ANG_SYN_Cam_GetEdgeType           BSYNC_CamSA_Get_EdgeType
#define EHAL_SLIB_ANG_SYN_Cam_GetSignalLevel        BSYNC_CamSA_Get_SignalLevel
#define EHAL_SLIB_ANG_SYN_Cam_GetValidEdgeType      BSYNC_CamSA_Get_ValidEdgeType
#define EHAL_SLIB_ANG_SYN_Cam_GetReqstIdx           BSYNC_CamSA_Get_ReqstIdx
#define EHAL_SLIB_ANG_SYN_Cam_SetEdgeType           BSYNC_CamSA_Set_EdgeType
#define EHAL_SLIB_ANG_SYN_Cam_SetStartDelay         BSYNC_CamSA_Set_StartDelay
#define EHAL_SLIB_ANG_SYN_Cam_SetFilterTime         BSYNC_CamSA_Set_FilterTime
#define EHAL_SLIB_ANG_SYN_Cam_SetEdgeFilterTime     BSYNC_CamSA_Set_EdgeFilterTime
#define EHAL_SLIB_ANG_SYN_Cam_SetTimeOut            BSYNC_CamSA_Set_TimeOut
#define EHAL_SLIB_ANG_SYN_Cam_SetTaskLevel          BSYNC_CamSA_Set_TaskLevel
#define EHAL_SLIB_ANG_SYN_Cam_SetEventType          BSYNC_CamSA_Set_EventType
#define EHAL_SLIB_ANG_SYN_Cam_SetCallbackFunction   BSYNC_CamSA_Set_CallbackFunction
#define EHAL_SLIB_ANG_SYN_Cam_StartTaskLevel        BSYNC_CamSA_StartTaskLevel
#define EHAL_SLIB_ANG_SYN_Cam_CheckQueue            BSYNC_CamSA_Check_Queue

#define EHAL_SLIB_ANG_SYN_EngSE_EmulInit            EMUL_Disable
#define EHAL_SLIB_ANG_SYN_EngSE_EnableEmul          EMUL_Enable
#define EHAL_SLIB_ANG_SYN_EngSE_DisableEmul         EMUL_Disable
#define EHAL_SLIB_ANG_SYN_EngSE_SetCrkEdgePer       EMUL_SetCrshEdgePer
#define EHAL_SLIB_ANG_SYN_EngSE_SetCamEdgeShift     EMUL_SetCamEdgeShift
#define EHAL_SLIB_ANG_SYN_EngSE_CrkLoadConfig       EMUL_CrkLoadConfig
#define EHAL_SLIB_ANG_SYN_EngSE_CamLoadConfig       EMUL_CamLoadConfig

// Knock services interface
#define EHAL_SLIB_KNOCK_Init                        KNOCK_Init
#define EHAL_SLIB_KNOCK_StartSampling               KNOCK_StartSampling
#define EHAL_SLIB_KNOCK_StartInspectMid             KNOCK_StartInspectMid
#define EHAL_SLIB_KNOCK_SetupSamplParameters        KNOCK_SetupSamplParameters
#define EHAL_SLIB_KNOCK_SetupAdcRef                 KNOCK_SetupAdcRef
#define EHAL_SLIB_KNOCK_SetupDSPCoef                KNOCK_SetupDSPCoef
#define EHAL_SLIB_KNOCK_StartDSP                    KNOCK_StartDSP
#define EHAL_SLIB_KNOCK_GetChannelState             KNOCK_GetChannelState
#define EHAL_SLIB_KNOCK_SetChannelState             KNOCK_SetChannelState
#define EHAL_SLIB_KNOCK_SetCallbackFunction         KNOCK_SetCallbackFunction

// Inductive loads manager interface
#define EHAL_SLIB_INDM_Init                         INDM_Init
#define EHAL_SLIB_INDM_DeInit                       INDM_DeInit
#define EHAL_SLIB_INDM_StartChargeCoil              INDM_StartChargeCoil
#define EHAL_SLIB_INDM_StartGenerating              INDM_StartGenerating
#define EHAL_SLIB_INDM_StopGenerating               INDM_StopGenerating
#define EHAL_SLIB_INDM_ForceStartDiag               INDM_ForceStartDiag
#define EHAL_SLIB_INDM_StopAllCurves                INDM_StopAllCurves
#define EHAL_SLIB_INDM_GetInductorDiagStatus        INDM_GetInductorDiagStatus
#define EHAL_SLIB_INDM_SetCurveDurationTable        INDM_SetCurveDurationTable
#define EHAL_SLIB_INDM_SetPhaseDurationTable        INDM_SetPhaseDurationTable
#define EHAL_SLIB_INDM_SetCurrentEdgesTable         INDM_SetCurrentEdgesTable
#define EHAL_SLIB_INDM_SetPWMParametersTable        INDM_SetPWMParametersTable
#define EHAL_SLIB_INDM_SetDiagLimitsTable           INDM_SetDiagLimitsTable
#define EHAL_SLIB_INDM_SetCallbackFunction          INDM_SetCallbackFunction

// Engine Management System
#define EHAL_IC_EMS_Init                            IC_EMS_Init
#define EHAL_IC_EMS_DeInit                          IC_EMS_DeInit
#define EHAL_IC_EMS_GetDirection                    IC_EMS_GetDirection
#define EHAL_IC_EMS_SetDirection                    IC_EMS_SetDirection
#define EHAL_IC_EMS_GetChannelStatus                IC_EMS_GetChannelStatus
#define EHAL_IC_EMS_GetChannelState                 IC_EMS_GetChannelState
#define EHAL_IC_EMS_SetChannelState                 IC_EMS_SetChannelState
#define EHAL_IC_EMS_GetChipState                    IC_EMS_GetChipState
#define EHAL_IC_EMS_SetChipState                    IC_EMS_SetChipState
#define EHAL_IC_EMS_GetICStatus                     IC_EMS_GetICStatus
#define EHAL_IC_EMS_WWDArm                          IC_EMS_WWDArm
#define EHAL_IC_EMS_FWDArm                          IC_EMS_FWDArm
#define EHAL_IC_EMS_SPICallback                     IC_EMS_SPICallback
#define EHAL_IC_EMS_HighLevelISR                    IC_EMS_HighLevelISR
#define EHAL_IC_EMS_GetWDCounters                   IC_EMS_GetWDCounters

// Electronic Throttle Control
#define EHAL_IC_ETC_Init                            IC_ETC_Init
#define EHAL_IC_ETC_SetChannelStatus                IC_ETC_SetChannelStatus
#define EHAL_IC_ETC_GetChannelStatus                IC_ETC_GetChannelStatus
#define EHAL_IC_ETC_EnableIC                        IC_ETC_EnableIC
#define EHAL_IC_ETC_GetSafetyStatus                 IC_ETC_GetSafetyStatus
#define EHAL_IC_ETC_SetParameters                   IC_ETC_SetParameters

// Randomizer
#define EHAL_Random_Init                            Random_Init
#define EHAL_Random_GetStatus                       Random_GetStatus
#define EHAL_Random_HighLevelISR                    Random_HighLevelISR

// Car access service functions
#define EHAL_CARACC_Init                            CARACC_Init
#define EHAL_CARACC_IsInitialized                   CARACC_IsInitialized
#define EHAL_CARACC_GetLearnStatus                  CALRN_GetLearnStatus
#define EHAL_CARACC_HighLevel_TimeRaster_1ms        CARACC_HighLevel_TimeRaster_1ms
#define EHAL_CARACC_HighLevel_TimeRaster_10ms       CARACC_HighLevel_TimeRaster_10ms
#define EHAL_CARACC_HighLevel_TimeRaster_100ms      CARACC_HighLevel_TimeRaster_100ms
#define EHAL_CARACC_HighLevel_TimeRaster_1s         CARACC_HighLevel_TimeRaster_1s

// Remote Control Unit service functions
#define EHAL_RCU_StartAuth                          RCU_StartAuth
#define EHAL_RCU_GetAuthState                       RCU_GetAuthState
#define EHAL_RCU_GetRkeRequest                      RCU_GetRkeRequest

// Car access service EOL functions
#define EHAL_CARACC_EOL_SendRequest                 CARACC_EOL_SendRequest
#define EHAL_CARACC_EOL_GetResponse                 CARACC_EOL_GetResponse



//**************************************************************************************************
// Declarations of global (public) variables
//**************************************************************************************************

// None.



//**************************************************************************************************
// Definitions of IO manager functions
//**************************************************************************************************

// Initializes SW and HW resources of the program module
extern STD_RESULT IO_Init(void);

// Deinitializes SW and HW resources of the program module
extern STD_RESULT IO_DeInit(void);

// Returns actual direction of the digital input/output board channel
extern STD_RESULT IO_D_GetChannelDirection(const U16 nNumber,
                                           U8* const pDirection);

// Sets direction of the specified digital input/output board channel
extern STD_RESULT IO_D_SetChannelDirection(const U16 nNumber,
                                           const U8  nDirection);

// Returns actual logic state of the digital input/output board channel
extern STD_RESULT IO_D_GetChannelState(const U16 nNumber,
                                       U8* const pLogicState);

// Sets logic state of the specified digital input/output board channel
extern STD_RESULT IO_D_SetChannelState(const U16 nNumber,
                                       const U8  nLogicState);

// Returns actual status of the digital input/output board channel
extern STD_RESULT IO_D_GetChannelStatus(const U16 nNumber,
                                        U8* const pStatus);

// Sets status of the specified digital input/output board channel
extern STD_RESULT IO_D_SetChannelStatus(const U16 nNumber,
                                        const U8  nStatus);

// Returns actual value of the specified analog input/output board channel
extern STD_RESULT IO_A_GetChannelValue(const U16  nNumber,
                                       U16* const pValue);

// Sets value of the specified analog input/output board channel
extern STD_RESULT IO_A_SetChannelValue(const U16 nNumber,
                                       const U16 nValue);



// Generate periodical signals and capture input signals
// Start the functionality of the channel
extern void IO_P_StartChannel(const U16 nNumber);

// Stop the functionality of the channel
extern void IO_P_StopChannel(const U16 nNumber);

// Get timestamp from input channels
extern U16 IO_P_GetChannelTime(const U16 nNumber);

// Set period and duty for output channels
extern void IO_P_SetChannelTime(const U16 nNumber,
                                const U16 nPeriod,
                                const U16 nActiveDuty);

// Set active level for output channels or active edge for input channels
extern void IO_P_SetChannelPolarity(const U16 nNumber,
                                    const U8 nActivePolarity);

// Set channel tick resolution in ns
extern void IO_P_SetTickResolution(const U16  nNumber,
                                   const U32 nTickResolution);

// Set callback function pointer
extern void IO_P_SetCallbackFunction(const U16 nNumber,
                                     const _FUNC_ pCallbackFunction);



//**************************************************************************************************
// Definitions of Signal manager module functions
//**************************************************************************************************

// Initializes SW and HW resources of the program module
extern void SIGMAN_Init(void);

// Deinitializes SW and HW resources of the program module
extern void SIGMAN_DeInit(void);



// Returns the specified signal value
extern void SIGMAN_GetSignalState(void* const pValue,
                                  const U8    nBufferSize,
                                  const U8    nSignalNumber);

// Sets the specified signal value
extern void SIGMAN_SetSignalState(const void* const pValue,
                                  const U8    nSignalNumber);



//**************************************************************************************************
// Definitions of WDT module functions
//**************************************************************************************************

// Enables WDT
extern void WDT_Enable(void);

// Arms WDT
extern void WDT_Arm(void);

// Initiates hardware reset through WDT
extern void WDT_ResetMCU(void);



//**************************************************************************************************
// Definitions of CCP module functions
//**************************************************************************************************

// Initializes SW and HW program module resources
extern void CCP_Init(void);

// Executes DAQ process
extern void CCP_ProcessDAQ(const U32 uwEventChannel);

// Returns CCP state: whether it's connected or not
extern BOOLEAN CCP_GetConnectState(void);



//**************************************************************************************************
// Definitions of CAN module functions
//**************************************************************************************************

// Initializes SW and HW program module resources
extern STD_RESULT CAN_Init(void);

// Deinitializes SW and HW program module resources
extern STD_RESULT CAN_DeInit(void);



//**************************************************************************************************
// Definitions of Init MAL modules functions
//**************************************************************************************************

// Initializes SW and HW SPI driver resources
extern STD_RESULT SPI_Init(void);

// Initializes SW and HW timer driver resources for all timer moduls
extern STD_RESULT TIMER_Init(const U8 nTimerNumber);



//**************************************************************************************************
// Definitions of WDT module functions
//**************************************************************************************************

// Initializes program module resources
extern STD_RESULT COMR_Init(void);

// Deinitializes program module resources
extern STD_RESULT COMR_DeInit(void);



//**************************************************************************************************
// Definitions of SOFTTIMER module functions
//**************************************************************************************************
// High-level Software Timer program module interrupt service routine
extern void SOFTTIMER_HighLevel_ISR(void);



//**************************************************************************************************
// Definitions of SPI scheduler module functions
//**************************************************************************************************

// Initializes SPI scheduler
extern STD_RESULT SPISCH_Init(void);



//**************************************************************************************************
// Definitions of MC33816 module functions
//**************************************************************************************************
// Enable/disable output.
extern STD_RESULT IC_MC33816_OutputEnable(const U8 nICNum,
                                          const BOOLEAN bEnable);

// Initializes SW and HW resources of the program module
extern STD_RESULT FPC_MC33816_Init(void);

// Deinitializes SW and HW resources of the program module
extern STD_RESULT FPC_MC33816_DeInit(void);

// Sets new value of the specified current analog channel
extern STD_RESULT FPC_MC33816_SetChannelValue(const U8 nChannelNumber,
                                              const U16 nValue);

// Returns actual status of the specified current analog channel
extern STD_RESULT FPC_MC33816_GetChannelStatus(const U8 nChannelNumber,
                                               U8* const pStatus);

// Sets new status of the specified current analog channel
extern STD_RESULT FPC_MC33816_SetChannelStatus(const U8 nChannelNumber,
                                               const U8  nStatus);



//**************************************************************************************************
// Definitions of MSE_DA_MULTI module functions
//**************************************************************************************************

// Read parameters
extern S8 MSE_DA_MULTI_ReadParameter1(const U32* const PSRT_Ptr,
                                      const U16 ParamID);

extern S16 MSE_DA_MULTI_ReadParameter2(const U32* const PSRT_Ptr,
                                       const U16 ParamID);

extern S32 MSE_DA_MULTI_ReadParameter4(const U32* const PSRT_Ptr,
                                       const U16 ParamID);

// Read indexed parameters
extern S8 MSE_DA_MULTI_ReadParameter1I(const U32* const PSRT_Ptr,
                                       const U16 ParamID,
                                       const U16 Index);

extern S16 MSE_DA_MULTI_ReadParameter2I(const U32* const PSRT_Ptr,
                                        const U16 ParamID,
                                        const U16 Index);

extern S32 MSE_DA_MULTI_ReadParameter4I(const U32* const PSRT_Ptr,
                                        const U16 ParamID,
                                        const U16 Index);

// Update coordinate vectors' interpolate data
extern void MSE_DA_MULTI_UpdateCoordinate1s(const U32* const PSRT_Ptr,
                                            const U16 ParamID,
                                            const S8 Value,
                                            const U8 Status);

extern void MSE_DA_MULTI_UpdateCoordinate1u(const U32* const PSRT_Ptr,
                                            const U16 ParamID,
                                            const U8 Value,
                                            const U8 Status);

extern void MSE_DA_MULTI_UpdateCoordinate2s(const U32* const PSRT_Ptr,
                                            const U16 ParamID,
                                            const S16 Value,
                                            const U8 Status);

extern void MSE_DA_MULTI_UpdateCoordinate2u(const U32* const PSRT_Ptr,
                                            const U16 ParamID,
                                            const U16 Value,
                                            const U8 Status);

// Update coordinate vectors' interpolate data
// without using CDelta and IdxData[]
extern void MSE_DA_MULTI_UpdateCoordinateRW1s(const U32* const PSRT_Ptr,
                                              const U16 ParamID,
                                              const S8 Value,
                                              const U8 Status);

extern void MSE_DA_MULTI_UpdateCoordinateRW1u(const U32* const PSRT_Ptr,
                                              const U16 ParamID,
                                              const U8 Value,
                                              const U8 Status);

extern void MSE_DA_MULTI_UpdateCoordinateRW2s(const U32* const PSRT_Ptr,
                                              const U16 ParamID,
                                              const S16 Value,
                                              const U8 Status);

extern void MSE_DA_MULTI_UpdateCoordinateRW2u(const U32* const PSRT_Ptr,
                                              const U16 ParamID,
                                              const U16 Value,
                                              const U8 Status);

// Write vector data
extern void MSE_DA_MULTI_WriteVector1(const U32* const PSRT_Ptr,
                                      const U16 ParamID,
                                      const S8 Value);

extern void MSE_DA_MULTI_WriteVector1I(const U32* const PSRT_Ptr,
                                       const U16 ParamID,
                                       const U16 Index,
                                       const S8 Value);

extern void MSE_DA_MULTI_WriteVector2(const U32* const PSRT_Ptr,
                                      const U16 ParamID,
                                      const S16 Value);

extern void MSE_DA_MULTI_WriteVector2I(const U32* const PSRT_Ptr,
                                       const U16 ParamID,
                                       const U16 Index,
                                       const S16 Value);

extern void MSE_DA_MULTI_WriteVector4(const U32* const PSRT_Ptr,
                                      const U16 ParamID,
                                      const S32 Value);

extern void MSE_DA_MULTI_WriteVector4I(const U32* const PSRT_Ptr,
                                       const U16 ParamID,
                                       const U16 Index,
                                       const S32 Value);

// Write table data
extern void MSE_DA_MULTI_Write2DTable1(const U32* const PSRT_Ptr,
                                       const U16 ParamID,
                                       const S8 Value);

extern void MSE_DA_MULTI_Write2DTable1I(const U32* const PSRT_Ptr,
                                        const U16 ParamID,
                                        const U16 Index,
                                        const S8 Value);

extern void MSE_DA_MULTI_Write2DTable2(const U32* const PSRT_Ptr,
                                       const U16 ParamID,
                                       const S16 Value);

extern void MSE_DA_MULTI_Write2DTable2I(const U32* const PSRT_Ptr,
                                        const U16 ParamID,
                                        const U16 Index,
                                        const S16 Value);

extern void MSE_DA_MULTI_Write2DTable4(const U32* const PSRT_Ptr,
                                       const U16 ParamID,
                                       const S32 Value);

extern void MSE_DA_MULTI_Write2DTable4I(const U32* const PSRT_Ptr,
                                        const U16 ParamID,
                                        const U16 Index,
                                        const S32 Value);

// Read vector data without interpolation
extern S8 MSE_DA_MULTI_ReadVectorNearest1(const U32* const PSRT_Ptr,
                                          const U16 ParamID);

extern S8 MSE_DA_MULTI_ReadVectorNearest1I(const U32* const PSRT_Ptr,
                                           const U16 ParamID,
                                           const U16 Index);

extern S16 MSE_DA_MULTI_ReadVectorNearest2(const U32* const PSRT_Ptr,
                                           const U16 ParamID);

extern S16 MSE_DA_MULTI_ReadVectorNearest2I(const U32* const PSRT_Ptr,
                                            const U16 ParamID,
                                            const U16 Index);

extern S32 MSE_DA_MULTI_ReadVectorNearest4(const U32* const PSRT_Ptr,
                                           const U16 ParamID);

extern S32 MSE_DA_MULTI_ReadVectorNearest4I(const U32* const PSRT_Ptr,
                                            const U16 ParamID,
                                            const U16 Index);

// Read table data without interpolation
extern S8 MSE_DA_MULTI_Read2DTableNearest1(const U32* const PSRT_Ptr,
                                           const U16 ParamID);

extern S8 MSE_DA_MULTI_Read2DTableNearest1I(const U32* const PSRT_Ptr,
                                            const U16 ParamID,
                                            const U16 Index);

extern S16 MSE_DA_MULTI_Read2DTableNearest2(const U32* const PSRT_Ptr,
                                            const U16 ParamID);

extern S16 MSE_DA_MULTI_Read2DTableNearest2I(const U32* const PSRT_Ptr,
                                             const U16 ParamID,
                                             const U16 Index);

extern S32 MSE_DA_MULTI_Read2DTableNearest4(const U32* const PSRT_Ptr,
                                            const U16 ParamID);

extern S32 MSE_DA_MULTI_Read2DTableNearest4I(const U32* const PSRT_Ptr,
                                             const U16 ParamID,
                                             const U16 Index);

// Read data as parameterAddress[offset]
extern S8 MSE_DA_MULTI_GetParameterData1(const U32* const PSRT_Ptr,
                                         const U16 ParamID,
                                         const U16 Offset);

extern S16 MSE_DA_MULTI_GetParameterData2(const U32* const PSRT_Ptr,
                                          const U16 ParamID,
                                          const U16 Offset);

extern S32 MSE_DA_MULTI_GetParameterData4(const U32* const PSRT_Ptr,
                                          const U16 ParamID,
                                          const U16 Offset);

// Read data from external copy
extern S8 MSE_DA_MULTI_ReadExtData1(const U32* const PSRT_Ptr,
                                    const U16 ParamID);

extern S8 MSE_DA_MULTI_ReadExtData1I(const U32* const PSRT_Ptr,
                                     const U16 ParamID,
                                     const U16 Index);

extern S16 MSE_DA_MULTI_ReadExtData2(const U32* const PSRT_Ptr,
                                     const U16 ParamID);

extern S16 MSE_DA_MULTI_ReadExtData2I(const U32* const PSRT_Ptr,
                                      const U16 ParamID,
                                      const U16 Index);

extern S32 MSE_DA_MULTI_ReadExtData4(const U32* const PSRT_Ptr,
                                     const U16 ParamID);

extern S32 MSE_DA_MULTI_ReadExtData4I(const U32* const PSRT_Ptr,
                                      const U16 ParamID,
                                      const U16 Index);

// Read key data
extern S8 MSE_DA_MULTI_ReadExtKey(const U32* const PSRT_Ptr,
                                  const U16 ParamID);

extern S8 MSE_DA_MULTI_ReadExtKeyI(const U32* const PSRT_Ptr,
                                   const U16 ParamID,
                                   const U16 Index);

// Get index of nearest table node
extern S8 MSE_DA_MULTI_GetNode2s(const U32* const PSRT_Ptr,
                                 const U16 ParamID,
                                 const S16 Value);

extern S8 MSE_DA_MULTI_GetNode2u(const U32* const PSRT_Ptr,
                                 const U16 ParamID,
                                 const U16 Value);

// Find Y-coordinate using table data value and X-coordinate
extern S16 MSE_DA_MULTI_GetVectorY_2(const U32* const PSRT_Ptr,
                                     const U16 ParamID,
                                     const S16 Value,
                                     const U8 Index);

// Copy parameter 1 data to parameter 2
extern void MSE_DA_MULTI_ParamToParam(const U32* const PSRT_Ptr,
                                      const U16 ParamID_Src,
                                      const U16 ParamID_Dest);

extern void MSE_DA_MULTI_ParamToParamDirectROM(const void* pDataAddressSrc,
                                               volatile void* pDataAddressDest,
                                               const U16 Size);

extern void MSE_DA_MULTI_ParamToParamDirect(const void* pDataAddressSrc,
                                            volatile void* pDataAddressDest,
                                            const U16 Size);

extern U8 MSE_DA_MULTI_ParameterToEEPROM(const U32* const PSRT_Ptr,
                                         const U16 EEPROMParamID,
                                         const U16 RAMParamID);

extern U8 MSE_DA_MULTI_ParameterFromEEPROM(const U32* const PSRT_Ptr,
                                           const U16 EEPROMParamID,
                                           const U16 RAMParamID);

extern U8 MSE_DA_MULTI_ParameterToEEPROMDirectROM(volatile void* pDestEEPROM,
                                                  const void* pSource,
                                                  const U16 Size,
                                                  volatile void* pCRCAddress);

extern U8 MSE_DA_MULTI_ParameterToEEPROMDirect(volatile void* pDestEEPROM,
                                               volatile void* pSource,
                                               const U16 Size,
                                               volatile void* pCRCAddress);

extern U8 MSE_DA_MULTI_ParameterFromEEPROMDirect(volatile void* pSourceEEPROM,
                                                 volatile void* pDest,
                                                 const U16 Size,
                                                 volatile void* pCRCAddress);



//**************************************************************************************************
// Definitions of Dyn_Tables module functions
//**************************************************************************************************

#define filter1Ds1              DYN_TBL_Filter1Ds1
#define filter1Du1              DYN_TBL_Filter1Du1
#define filter1Ds2              DYN_TBL_Filter1Ds2
#define filter1Du2              DYN_TBL_Filter1Du2
#define filter1Ds4              DYN_TBL_Filter1Ds4
#define filter1Du4              DYN_TBL_Filter1Du4
#define filter2Ds1              DYN_TBL_Filter2Ds1
#define filter2Du1              DYN_TBL_Filter2Du1
#define filter2Ds2              DYN_TBL_Filter2Ds2
#define filter2Du2              DYN_TBL_Filter2Du2
#define filter2Ds4              DYN_TBL_Filter2Ds4
#define filter2Du4              DYN_TBL_Filter2Du4

extern void DYN_TBL_Filter1Ds1(S8 NewVal,
                               S8 gradient,
                               S8 *DataPtr,
                               U8 x,
                               U8 xSize );

extern void DYN_TBL_Filter1Du1(U8 NewVal,
                               U8 gradient,
                               U8 *DataPtr,
                               U8 x,
                               U8 xSize );

extern void DYN_TBL_Filter1Ds2(S16 NewVal,
                               S16 gradient,
                               S16 *DataPtr,
                               U8 x,
                               U8 xSize );

extern void DYN_TBL_Filter1Du2(U16 NewVal,
                               U16 gradient,
                               U16 *DataPtr,
                               U8 x,
                               U8 xSize );

extern void DYN_TBL_Filter1Ds4(S32 NewVal,
                               S32 gradient,
                               S32 *DataPtr,
                               U8 x,
                               U8 xSize );

extern void DYN_TBL_Filter1Du4(U32 NewVal,
                               U32 gradient,
                               U32 *DataPtr,
                               U8 x,
                               U8 xSize );

extern void DYN_TBL_Filter2Ds1(S8 NewVal,
                               S8 gradient,
                               S8 *DataPtr,
                               U8 x,
                               U8 y,
                               U8 xSize,
                               U8 ySize );

extern void DYN_TBL_Filter2Du1(U8 NewVal,
                               U8 gradient,
                               U8 *DataPtr,
                               U8 x,
                               U8 y,
                               U8 xSize,
                               U8 ySize );

extern void DYN_TBL_Filter2Ds2(S16 NewVal,
                               S16 gradient,
                               volatile S16 *DataPtr,
                               U8 x,
                               U8 y,
                               U8 xSize,
                               U8 ySize );

extern void DYN_TBL_Filter2Du2(U16 NewVal,
                               U16 gradient,
                               U16 *DataPtr,
                               U8 x,
                               U8 y,
                               U8 xSize,
                               U8 ySize );

extern void DYN_TBL_Filter2Ds4(S32 NewVal,
                               S32 gradient,
                               S32 *DataPtr,
                               U8 x,
                               U8 y,
                               U8 xSize,
                               U8 ySize );

extern void DYN_TBL_Filter2Du4(U32 NewVal,
                               U32 gradient,
                               U32 *DataPtr,
                               U8 x,
                               U8 y,
                               U8 xSize,
                               U8 ySize );



//**************************************************************************************************
// Definitions of TIMER module functions
//**************************************************************************************************

// Returns current value of timer counter
extern STD_RESULT TIMER_GetTime(const U8 nTimerNumber,
                                TIMER_SZ* const pTimerCounter);

// Returns the time from the moment of start the timer
extern STD_RESULT TIMER_GetTimeElapsed(const U8 nTimerNumber,
                                       TIMER_SZ* const pTimeElapsed);

// Sets timer counter value
extern STD_RESULT TIMER_SetTime(const U8 nTimerNumber,
                                const TIMER_SZ nTimerCounter);

// Starts timer and sets timer period
extern STD_RESULT TIMER_StartTimer(const U8 nTimerNumber,
                                   const TIMER_SZ nTimerPeriod);

// Stops timer
extern STD_RESULT TIMER_StopTimer(const U8 nTimerNumber);

// Returns the tick period in nanoseconds
extern STD_RESULT TIMER_GetTickPeriod(const U8 nTimerNumber,
                                      U32*  const pTickPeriod);

// Sets callback function pointer for the TIMER driver
extern STD_RESULT TIMER_SetCallbackFunction(const U8 nTimerNumber,
                                            const TIMER_CALLBACK pCallbackFunction);



//**************************************************************************************************
// Definitions of SORT module functions
//**************************************************************************************************

// Founds median value of input sequence of 3 numbers.
extern S16 SORT_Mid3(S16 nVal_1,
                     S16 nVal_2,
                     S16 nVal_3);

// Founds median value of input sequence of 5 numbers.
extern S16 SORT_Mid5(S16 nVal_1,
                     S16 nVal_2,
                     S16 nVal_3,
                     S16 nVal_4,
                     S16 nVal_5);

// Founds median value of input sequence of 10 numbers.
extern S16 SORT_Mid10(S16 nVal_1,
                      S16 nVal_2,
                      S16 nVal_3,
                      S16 nVal_4,
                      S16 nVal_5,
                      S16 nVal_6,
                      S16 nVal_7,
                      S16 nVal_8,
                      S16 nVal_9,
                      S16 nVal_10);

// Selecting the second largest number from the three inputs.
extern U8 SORT_DfrMid32(S32 nVal_1,
                        S32 nVal_2,
                        S32 nVal_3);

// Selecting the second largest number from the four inputs.
extern U8 SORT_DfrMid42(S32 nVal_1,
                        S32 nVal_2,
                        S32 nVal_3,
                        S32 nVal_4);

// Selecting the 3rd largest number out of 5 inputs.
extern U8 SORT_DfrMid53(S32 nVal_1,
                        S32 nVal_2,
                        S32 nVal_3,
                        S32 nVal_4,
                        S32 nVal_5);

// Selecting the 3rd largest number out of 6 inputs.
extern U8 SORT_DfrMid63(S32 nVal_1,
                        S32 nVal_2,
                        S32 nVal_3,
                        S32 nVal_4,
                        S32 nVal_5,
                        S32 nVal_6);

// Selecting the 4rd largest number out of 7 inputs.
extern U8 SORT_DfrMid74(S32 nVal_1,
                        S32 nVal_2,
                        S32 nVal_3,
                        S32 nVal_4,
                        S32 nVal_5,
                        S32 nVal_6,
                        S32 nVal_7);

// Selecting the 4rd largest number out of 8 inputs.
extern U8 SORT_DfrMid84(S32 nVal_1,
                        S32 nVal_2,
                        S32 nVal_3,
                        S32 nVal_4,
                        S32 nVal_5,
                        S32 nVal_6,
                        S32 nVal_7,
                        S32 nVal_8);



//**************************************************************************************************
// Definitions of INDM module functions
//**************************************************************************************************

// INDM service initialization function
extern STD_RESULT INDM_Init(void);

// INDM service deinitialization function
extern STD_RESULT INDM_DeInit(void);

// Starts prepare to generating the current curve
extern STD_RESULT INDM_StartChargeCoil(const U8 nInductorNum);

// Starts generating the current curve by the selected inductor
extern STD_RESULT INDM_StartGenerating(const U8 nInductorNum,
                                       const U8 nCurveNum);
// Stop generating of selected inductor
extern STD_RESULT INDM_StopGenerating(const U8 nInductorNum);

// Starts the selected inductor hardware diagnostic procedure during its downtime
extern STD_RESULT INDM_ForceStartDiag(const U8 nInductorNum);

// Stops all active current curves.
extern STD_RESULT INDM_StopAllCurves(void);

// Gets the actual diagnostic status of the selected inductor.
extern STD_RESULT INDM_GetInductorDiagStatus(const U8 nInductorNum,
                                             U16* const pDiagStatus);

// Sets the current curves duration table pointer
extern STD_RESULT INDM_SetCurveDurationTable(const U8 nInductorNum,
                                             const U32* const pCurveDurationTable,
                                             const U8 nCurvesQty);

// Sets pointer to the phase duration table for the selected inductor
extern STD_RESULT INDM_SetPhaseDurationTable(const U8 nInductorNum,
                                             const U16* const pPhaseDurationTable);

// Sets pointer to the current edges table for the selected inductor
extern STD_RESULT INDM_SetCurrentEdgesTable(const U8 nInductorNum,
                                            const U16* const pCurrentEdgesTable);

// Sets pointer to the PWM parameters table for the selected inductor
extern STD_RESULT INDM_SetPWMParametersTable(const U8 nInductorNum,
                                             const U16* const pPWMParametersTable);

// Sets pointer to the diagnostic limits table for the selected inductor
extern STD_RESULT INDM_SetDiagLimitsTable(const U8 nInductorNum,
                                          const U16* const pDiagLimitsTable);

// Sets end generating event callback function
extern STD_RESULT INDM_SetCallbackFunction(const U8 nInductorNum,
                                           const INDM_CALLBACK pCallbackFunction);



//**************************************************************************************************
// Definitions of CRC module functions
//**************************************************************************************************

// Initializes crc32 service
extern void CRC32_Init(const U32* const startAreaAddreses,
                       const U32* const areaSizes,
                       const U16 areaNumber);

// Calculates crc32 for the specified area
extern void CRC32_Calc(void);

// Returns calculated crc32 value
extern U32 CRC32_GetCalculatedCRC(void);

// Returns precalculated crc32 value
extern U32 CRC32_GetPreCalculatedCRC(void);

// Returns current crc32 value status
extern BOOLEAN CRC32_IsCalculated(void);



//**************************************************************************************************
// Definitions of Checksum module functions
//**************************************************************************************************

// Initializes SW resources of the program module
extern void CS_Init(void);

// Calculates CS for the specified memory block
extern void CS_Calc(const U8 nBlockNumber);

// Returns calculated CS value
extern U32 CS_GetCalculatedChecksum(const U8 nBlockNumber);

// Returns precalculated CS value
extern U32 CS_GetPreCalculatedChecksum(const U8 nBlockNumber);

// Returns current CS value status
extern BOOLEAN CS_IsCalculated(const U8 nBlockNumber);



//**************************************************************************************************
// Definitions of CRC8 module functions
//**************************************************************************************************

extern U8 Crc8_Dallas(const U8 *pcBlock,
                      U16 length);



//**************************************************************************************************
// Definitions of PIT module functions
//**************************************************************************************************

// Initializes SW and HW timer driver resources for all timer moduls
extern STD_RESULT PIT_Init(const U8 nTimerNumber);

// Returns current value of the timer counter
extern STD_RESULT PIT_GetTime(const U8 nTimerNumber,
                              PIT_SZ* const pTimerCounter);

// Sets the timer counter value
extern STD_RESULT PIT_SetTime(const U8 nTimerNumber,
                              const PIT_SZ nTimerCounter);

// Sets the timer period and starts the timer
extern STD_RESULT PIT_StartTimer(const U8 nTimerNumber,
                                 const PIT_SZ nTimerPeriod);

// Stops the timer
extern STD_RESULT PIT_StopTimer(const U8 nTimerNumber);

// Returns the timer tick period in nanoseconds
extern STD_RESULT PIT_GetTickPeriod(const U8    nTimerNumber,
                                    U32*  const pTickPeriod);

// Sets callback function pointer for the program module
extern STD_RESULT PIT_SetCallbackFunction(const U8 nTimerNumber,
                                          const PIT_CALLBACK pCallbackFunction);



//**************************************************************************************************
// Definitions of scheduler module functions
//**************************************************************************************************

// Initializes SW and HW resources for task scheduler
extern void SCHDL_Init(void);

// Deinitializes SW and HW resources for task scheduler
extern void SCHDL_DeInit(void);

// Enable of task scheduler functionality
extern void SCHDL_Enable(void);

// Disable of task scheduler functionality
extern void SCHDL_Disable(void);

// Launch the specified level
extern U8 SCHDL_StartLevel(U16 nLevelNumber);

// To activate the level, but do not start
extern U8 SCHDL_ActivateLevel(U16 nLevelNumber);

// Level Start Immediately
extern void SCHDL_RunLevelImmed(U16 nLevelNumber);

// Start the scheduler
extern void SCHDL_StartSchedule(void);

// Increment of idle counter
extern void SCHDL_IncIdleCounter(void);

// Get of idle counter
extern U32 SCHDL_GetIdleCounter(void);

// Returns idle counter value and reset it
extern U32 SCHDL_GetAndResetIdleCounter(void);

// Interface for MSE
#define ENABLE_SCHEDULE         SCHDL_Enable();
#define DISABLE_SCHEDULE        SCHDL_Disable();



//**************************************************************************************************
//  Definitions of MCU module functions
//**************************************************************************************************

// MCU's reset causes
#define MCU_RESET_CAUSE_POWER_ON        (0U)
#define MCU_RESET_CAUSE_RESET_PIN       (1U)
#define MCU_RESET_CAUSE_LOW_VOLTAGE     (2U)
#define MCU_RESET_CAUSE_HIGH_VOLTAGE    (3U)
#define MCU_RESET_CAUSE_ILLEGAL_ADDR    (4U)
#define MCU_RESET_CAUSE_ILLEGAL_INSTR   (5U)
#define MCU_RESET_CAUSE_WATCHDOG        (6U)
#define MCU_RESET_CAUSE_UNIMPL_INTERR   (7U)
#define MCU_RESET_CAUSE_SOFTWARE        (8U)
#define MCU_RESET_CAUSE_CLOCK_MONITOR   (9U)
#define MCU_RESET_CAUSE_UNKNOWN         (10U)
#define MCU_RESET_CAUSE_UNKNOWN_INTERR  (11U)
#define MCU_RESET_CAUSE_CPU_ERROR       (12U)
#define MCU_RESET_CAUSE_MEMORY_PARITY   (13U)

// Returns the last reset cause number
extern U8 MCU_GetResetCause(void);



//**************************************************************************************************
//  Definitions of IC_EMS module functions
//**************************************************************************************************

// IC_EMS service initialization function
extern STD_RESULT IC_EMS_Init(void);

// IC_EMS service deinitialization function
extern STD_RESULT IC_EMS_DeInit(void);

// Arms window watchdog inside the IC
extern STD_RESULT IC_EMS_WWDArm(const U8 nICNum,
                                const U8 nJobNum);

// Arms functional watchdog inside the IC
extern STD_RESULT IC_EMS_FWDArm(const U8 nICNum,
                                const U8 nJobNum);

// Cyclic event handler
extern STD_RESULT IC_EMS_HighLevelISR(const U8 nICNum,
                                      const U8 nJobNum);

// Get EMS status
extern STD_RESULT IC_EMS_GetICStatus(const U8 nICNum);


// Returns actual state of the chip
extern STD_RESULT IC_EMS_GetChipState(const U8  nICNum,
                                      U8* const pState);

// Sets a new state of the chip
extern STD_RESULT IC_EMS_SetChipState(const U8  nICNum,
                                      U8* const pState);

// Returns WD counters
extern STD_RESULT IC_EMS_GetWDCounters(const U8 nICNum,
                                       U8* const pCounter);



//**************************************************************************************************
//  Definitions of IC_ETC module functions
//**************************************************************************************************

// IC_ETC service initialization function
extern STD_RESULT IC_ETC_Init(void);

// Sets the state of the channel, if possible
extern STD_RESULT IC_ETC_SetChannelStatus(const U8        nICNumber,
                                          const U8        nChannelNumber,
                                          const IO_STATUS nDiagStatus);
// Returns channel diagnostic information
extern STD_RESULT IC_ETC_GetChannelStatus(const      U8    nICNum,
                                          const      U8    nChannelNumber,
                                          IO_STATUS* const pDiagStatus);
// Enables/disables IC
extern STD_RESULT IC_ETC_EnableIC(const U8      nICNum,
                                  const BOOLEAN bEnable);
// Returns safety status (IC_ETC_READY/IC_ETC_NOT_READY)
extern STD_RESULT IC_ETC_GetSafetyStatus(const    U8    nICNum,
                                         BOOLEAN* const pSafetyStatus);
// PWM and direction parameters setting
extern STD_RESULT IC_ETC_SetParameters(const U8  nICNumber,
                                       const U16 nPwmPeriod,
                                       const U16 nPwmDuty,
                                       const U8  nDirection);



//**************************************************************************************************
// Definitions of Angle_Synchronization functions
//**************************************************************************************************

//--------------------------------------------------------------------------------------------------
// Crankshaft Synchronization
//--------------------------------------------------------------------------------------------------

// Initialization crankshaft driver
extern void BSYNC_CrshSA_Init_Acquisit(void);

// Enables processing of the crankshaft signal
extern void BSYNC_CrshSA_Enable_Acquisit(void);

// To get the absolute 16-bit time of crankshaft edge
extern U16 BSYNC_CrshSA_Get_EventTime(void);

// To get the absolute 32-bit time of crankshaft edge
extern U32 BSYNC_CrshSA_Get_EventTime32(void);

// To take the type of the generated event crankshaft
extern U8 BSYNC_CrshSA_Get_EventType(void);

// To take the tooth period of the crankshaft signal
extern U16 BSYNC_CrshSA_Get_EdgePer(void);

// To take the latch angle counter on the crankshaft edge
extern U16 BSYNC_CrshSA_Get_EdgeAngCounter(void);

// To take the current counter of angle timer
extern U16 BSYNC_CrshSA_Get_AngCounter(void);

// To take the latch absolute time active edge from timer monitoring
extern U32 BSYNC_CrshSA_Get_EdgeTimeMonitor(void);

// To take the buffer the summation of lengths teeth (global time)
extern U32 BSYNC_CrshSA_Get_GlobToothTime(void);

// To take the timeout value
extern U16 BSYNC_CrshSA_Get_TimeOut(void);

// To take the level of the input signal CRK
extern U8 BSYNC_CrshSA_Get_SignalLevel(void);

// To take the glitch indicator
extern U8 BSYNC_CrshSA_Get_GlitchState(void);

// To take the spike indicator
extern U8 BSYNC_CrshSA_Get_SpikeState(void);

// Reset of the glitch counter
extern void BSYNC_CrshSA_Reset_GlitchState(void);

// Reset of the spike counter
extern void BSYNC_CrshSA_Reset_SpikeState(void);

// Set the type of front for CRK signal
extern void BSYNC_CrshSA_Set_EdgeType(const U8 nCrkEdgeType);

// Set the type of event for CRK signal
extern void BSYNC_CrshSA_Set_EventType(const U8 nCrkEventType);

// Setting of start delay
extern void BSYNC_CrshSA_Set_StartDelay(const U32 nCrkStartDelay);

// Setting of window filter of CRK
extern void BSYNC_CrshSA_Set_FilterTime(const U16 nCrkFilterTime);

// Setting time of the impulse noise filter of CRK
extern void BSYNC_CrshSA_Set_EdgeFilterTime(const U16 nCrkEdgeFilterTime);

// Setting the operating mode of the impulse noise filter
extern void BSYNC_CrshSA_Set_EdgeFilterMode(const U8 nCrkEdgeFilterMode);

// Setting of timeout of CRK
extern void BSYNC_CrshSA_Set_TimeOut(const U16 nCrkTimeout);

// Forced set the length of a CRK edge period
extern void BSYNC_CrshSA_Set_EdgePer(const U16 nCrkEdgePeriod);

// For debugging
extern void BSYNC_CrshSA_Set_DebugRegister(void);

// Sets callback function pointer
extern void BSYNC_CrshSA_Set_CallbackFunction(const _FUNC_ pCallbackFunction);

// Latch of CRK event data (absolute time of edge, tooth period, event type)
extern void BSYNC_CrshSA_Latch_EventData(void);



//--------------------------------------------------------------------------------------------------
// Camshaft Synchronization
//--------------------------------------------------------------------------------------------------

// Initialization of common variables for all camshafts
extern void BSYNC_CamSA_Init(void);

// Initialization of individual variables for synchronization of the camshaft
extern void BSYNC_CamSA_Init_Acquisit(const U8 nCamPrmIdx);

// Enables processing of the signal DPRV
extern void BSYNC_CamSA_Enable_Acquisit(const U8 nCamPrmIdx);

// To take absolute 16-bit edge time of the signal DPRV
extern U16 BSYNC_CamSA_Get_EdgeTime(const U8 nCamPrmIdx);

// To take absolute 32-bit edge time of the signal DPRV
extern U32 BSYNC_CamSA_Get_EdgeTime32(const U8 nCamPrmIdx);

// To take absolute 16-bit time of the last signal edge of crankshaft in front of camshaft signal
extern U16 BSYNC_CamSA_Get_CrshEventTime(const U8 nCamPrmIdx);

// To take absolute 32-bit time of the last signal edge of crankshaft in front of camshaft signal
extern U32 BSYNC_CamSA_Get_CrshEventTime32(const U8 nCamPrmIdx);

// To take the type of the generated event DPRV
extern U8 BSYNC_CamSA_Get_EventType(const U8 nCamPrmIdx);

// To take the type of the edge DPRV
extern U8 BSYNC_CamSA_Get_EdgeType(const U8 nCamPrmIdx);

// The reading level of the input signal
extern U8 BSYNC_CamSA_Get_SignalLevel(const U8 nCamPrmIdx);

// Reading validated front DPRV
extern U8 BSYNC_CamSA_Get_ValidEdgeType(const U8 nCamPrmIdx);

// Returns the index of the camshaft, the requested BIOS synchronization for subsequent processing
extern U8 BSYNC_CamSA_Get_ReqstIdx(void);

// Setting the active edge of the input signal
extern void BSYNC_CamSA_Set_EdgeType( const U8 nCamPrmIdx,
                                      const U8 nCamEdgeType);

// Setting the start delay and start
extern void BSYNC_CamSA_Set_StartDelay(const U8  nCamPrmIdx,
                                       const U32 nCamStartDelay);

// Setting of window filter
extern void BSYNC_CamSA_Set_FilterTime(const U8  nCamPrmIdx,
                                       const U32 nCamFilterTime);

// The setting of the filter impulse noise
extern void BSYNC_CamSA_Set_EdgeFilterTime(const U8  nCamPrmIdx,
                                           const U16 nCamEdgeFilterTime);

// Setting the timeout and run it
extern void BSYNC_CamSA_Set_TimeOut(const U8  nCamPrmIdx,
                                    const U32 nCamTimeOut);

// Set the OS level for signal processing DPRV
extern void BSYNC_CamSA_Set_TaskLevel( const U8  nCamPrmIdx,
                                       const U16 nCamTaskLevel);

// Set the type of event for CAM signal
extern void BSYNC_CamSA_Set_EventType(const U8 nCamPrmIdx,
                                      const U8 nCamEventType);

// Sets callback function pointer for the BSYNC driver
extern void BSYNC_CamSA_Set_CallbackFunction(const U8 nCamPrmIdx,
                                             const BSYNC_CAM_CALLBACK pCallbackFunction);

// Start CAM level
extern void BSYNC_CamSA_StartTaskLevel(const U8 nCamPrmIdx);

// Checking the queue of requests for processing
extern void BSYNC_CamSA_Check_Queue(void);



//**************************************************************************************************
// Definition of Sens_Emul functions
//**************************************************************************************************

// Enable emulation
extern void EMUL_Enable(void);

// Disable emulation
extern void EMUL_Disable(void);

// Setting the tooth period of crankshaft
extern void EMUL_SetCrshEdgePer(const U16 nEdgePer);

// Setting the offset camshaft
extern void EMUL_SetCamEdgeShift(const S8 nCamEdgeShift);

// Load configuration of crankshaft emulator
extern void EMUL_CrkLoadConfig(const U8 nToothNumber,
                               const U8 nCrkActiveLevel,
                               const U8* const pCrshSkipPos,
                               const U8* const pCrshSkipLev);

// Load configuration of camshaft emulator
extern void EMUL_CamLoadConfig(const U8 nCamNumber,
                               const U8 nCamActiveLevel,
                               const U8* const pCamEdgePos);



//**************************************************************************************************
// Declarations of KNOCK functions
//**************************************************************************************************

// Initializes SW and HW program module resources
extern STD_RESULT KNOCK_Init(const U8 nChannelNumber);

// Start sampling at a certain point
extern STD_RESULT KNOCK_StartSampling(const U8  nChannelNumber,
                                      const U8  nCylNumber,
                                      const U16 nSamplesQty,
                                      const U16 nStartSamplingMoment);

// Start sampling for inspection midpoint
extern STD_RESULT KNOCK_StartInspectMid(const U8  nChannelNumber,
                                        const U16 nMidValMin,
                                        const U16 nMidValMax);

// Set sampling parameter
extern STD_RESULT KNOCK_SetupSamplParameters(const U8  nChannelNumber,
                                             const U8  nDataReductionMode,
                                             const U8  nInputGain,
                                             const U8  nOffset,
                                             const U32 nSampleRate);

// Set source of voltage reference
extern STD_RESULT KNOCK_SetupAdcRef(const U8  nChannelNumber,
                                    const U8  nRefType,
                                    const U16 nRefDuty);

// Setting the coefficients and type of filters
extern STD_RESULT KNOCK_SetupDSPCoef(const U8  nChannelNumber,
                                     const U8 nTypeKnockFilter,
                                     const S16 nIirK1,
                                     const S16 nIirK2,
                                     NEAR S16* const pFirCoefArray);

// Start of digital signal processing
extern STD_RESULT KNOCK_StartDSP(const U8  nChannelNumber);

// Get state of knock channel
extern STD_RESULT KNOCK_GetChannelState(const U8   nChannelNumber,
                                        U32* const pChannelState);

// Set state of knock channel
extern STD_RESULT KNOCK_SetChannelState(const U8 nChannelNumber,
                                        const U8 nChannelState);

// Sets callback function pointer for the program module
extern STD_RESULT KNOCK_SetCallbackFunction(const U8      nChannelNumber,
                                            const _FUNC_  pCallbackFunction);



//**************************************************************************************************
// Declarations of MEMMAN functions
//**************************************************************************************************

// End of memory job callback
typedef void (*MEM_END_OF_JOB_CALLBACK)(const U8 nEventID,
                                        const U8 nJobResult);

// Initializes SW and HW resources of the program module
extern void MEMMAN_Init(void);

// Deinitializes SW and HW resources of the program module
extern void MEMMAN_DeInit(void);

// Sets "end of job" callback function pointer(s) for the specified job type
// (Load / Store)
extern STD_RESULT MEMMAN_SetJobCallback(const U8 nJobType,
                                        const U8 nEventID,
                                        const MEM_END_OF_JOB_CALLBACK pCallback);

// Loads data from the specified logical memory bank
extern STD_RESULT MEMMAN_Load(const U8  nMemoryBank,
                              const U32 nAddressOffset,
                              U8* const pDataBuffer,
                              const U32 nDataQty);

// Stores data to the specified logical memory bank
extern STD_RESULT MEMMAN_Store(const U8  nMemoryBank,
                               const U32 nAddressOffset,
                               const U8* const pDataBuffer,
                               const U32 nDataQty);

// Returns the last job result
extern U8 MEMMAN_GetJobResult(void);

// Returns memory status mask of the specified memory bank
extern U32 MEMMAN_GetMemoryStatus(const U8 nMemoryBank);

// Sets a new memory status mask of the specified memory bank
extern void MEMMAN_SetMemoryStatus(const U8  nMemoryBank,
                                   const U32 nStatusMask);



//**************************************************************************************************
// Declarations of ISO 14229 functions
//**************************************************************************************************

// "DiagSessionControl" request callback interface function prototype
typedef U8 (*ISO14229_DSC_CALLBACK)(const U8 nRequestedSession);

// "ReadDataByIdentifier" callback interface function prototype
typedef U8 (*ISO14229_RDBI_CALLBACK)(const U16 nDID,
                                     const U32 pDataBuffer,
                                     const U32 pDataSize,
                                     const U16 nBufferSize);

// "WriteMemoryByAddress" callback interface function prototype
typedef U8 (*ISO14229_WMBA_CALLBACK)(const U32 nMemoryAddress,
                                     const U16 nMemorySize,
                                     const U8* const pDataBuffer);

// "ClearDiagnosticInformation" callback interface function prototype
typedef U8 (*ISO14229_CDI_CALLBACK)(const U32 nGroupOfDTC);

// "ReadDTCInformation" callback interface function prototype
typedef U16 (*ISO14229_RDTCI_CALLBACK)(const U8 nDTCStatusMask);

// "InputOutputControlByIdentifier" callback interface function prototype
typedef U8 (*ISO14229_IOCBI_CALLBACK)(const U16 nDataID,
                                      const U8  nRequstedIOControl,
                                      const U32 pRequestedControlState,
                                      const U32 pControlStateSize,
                                      const U32 pAcceptedControlState);

// "RoutineControl" callback interface function prototype
typedef U8 (*ISO14229_RC_CALLBACK)(const U8  nSubFunction,
                                   const U16 nRoutineID,
                                   const U8* const pRCOptionRec,
                                   const U16 nRCOptionRecSize,
                                   U8*  const pRoutineStatusRecBuffer,
                                   const U16  nRoutineStatusRecBufferSize,
                                   U16* const pRoutineStatusRecSize);

// "RequestDownload" callback interface function prototype
typedef U8 (*ISO14229_RD_CALLBACK)(const U32 nDownloadAddress,
                                   const U32 nDownloadSize);

// "TransferData" DownLoad callback interface function prototype
typedef U8 (*ISO14229_TD_DL_CALLBACK)(const U8  nBlockNumber,
                                      const U16 nBlockSize,
                                      const U8* const pBlockData);

// "TransferData" UpLoad callback interface function prototype
typedef U8 (*ISO14229_TD_UL_CALLBACK)(void);

// "RequestTransferExit" callback interface function prototype
typedef U8 (*ISO14229_RTE_CALLBACK)(void);

// "ControlDTCSetting" callback interface function prototype
typedef U8 (*ISO14229_CDTCS_CALLBACK)(const U8 nDTCSettingType,
                                      const U32 pDTCSettingControlOptionRec,
                                      const U8 nDTCSettingControlOptionRecSize);

// "CommunicationControl" callback interface function prototype
typedef U8 (*ISO14229_CC_CALLBACK)(const U8  nControlType,
                                   const U8  nCommunicationType,
                                   const U16 nNodeIdentificationNumber);

// "WriteDataByIdentifier" callback interface function prototype
typedef U8 (*ISO14229_WDBI_CALLBACK)(const U16 nDID,
                                     const U32 pDataBuffer,
                                     const U16 nDataSize);

// "ECUReset" request callback interface function prototype
typedef U8 (*ISO14229_ER_CALLBACK)(const U8  nResetType,
                                   const U32 pPowerDownTime);

// OBD services callback interface function prototype
typedef U8 (*ISO14229_OBD_CALLBACK)(const U8  nServiceID,
                                    const U32 pRequestDataBuffer,
                                    const U16 nRequestDataSize,
                                    const U32 pResponseDataBuffer,
                                    const U32 pResponseDataSize);



// Initializes SW and HW program module resources
extern void ISO14229_Init(void);

// Deinitializes SW and HW program module resources
extern void ISO14229_DeInit(void);

// Processes all of the requested ISO 14229 services from the client
extern STD_RESULT ISO14229_Process(void);

// Initializes "DiagnosticSessionControl" service handler
extern STD_RESULT ISO14229_DSCInit(const ISO14229_DSC_CALLBACK pCallback,
                                   const U8 nDiagSessionType);

// Initializes "ReadDataByIdentifier" service handler
extern STD_RESULT ISO14229_RDBIInit(const ISO14229_RDBI_CALLBACK pCallback,
                                    const U8 nDiagSessionType);

// Initializes "WriteMemoryByAddress" service handler
extern STD_RESULT ISO14229_WMBAInit(const ISO14229_WMBA_CALLBACK pCallback,
                                    const U8 nDiagSessionType);

// Initializes "ClearDiagnosticInformation" service handler
extern STD_RESULT ISO14229_CDIInit(const ISO14229_CDI_CALLBACK pCallback,
                                   const U8 nDiagSessionType);

// Initializes "ControlDTCSetting" service handler
extern STD_RESULT ISO14229_CDTCSInit(const ISO14229_CDTCS_CALLBACK pCallback,
                                     const U8 nDiagSessionType);

// Initializes "ReadDTCInformation" service handler
extern STD_RESULT ISO14229_RDTCIInit(const ISO14229_RDTCI_CALLBACK pCallback,
                                     const U8*  const pDTCStatusList,
                                     const U32* const pDTCCodeList,
                                     const U16* const pDTCIndexList,
                                     const U8   nDiagSessionType);

// Initializes "InputOutputControlByIdentifier" service handler
extern STD_RESULT ISO14229_IOCBIInit(const ISO14229_IOCBI_CALLBACK pCallback,
                                     const U8   nDiagSessionType);

// Initializes "RoutineControl" service handler
extern STD_RESULT ISO14229_RCInit(const ISO14229_RC_CALLBACK pCallback,
                                  const U8 nDiagSessionType);

// Initializes "RequestDownload" service handler
extern STD_RESULT ISO14229_RDInit(const ISO14229_RD_CALLBACK pCallback,
                                  const U8 nDiagSessionType);

// Initializes "TransferData" service handler
extern STD_RESULT ISO14229_TDInit(const ISO14229_TD_DL_CALLBACK pDLCallback,
                                  const ISO14229_TD_UL_CALLBACK pULCallback,
                                  const U8 nDiagSessionType);

// Initializes "RequestTransferExit" service handler
extern STD_RESULT ISO14229_RTEInit(const ISO14229_RTE_CALLBACK pCallback,
                                   const U8 nDiagSessionType);

// Initializes "CommunicationControl" service handler
extern STD_RESULT ISO14229_CCInit(const ISO14229_CC_CALLBACK pCallback,
                                  const U8 nDiagSessionType);

// Initializes "WriteDataByIdentifier" service handler
extern STD_RESULT ISO14229_WDBIInit(const ISO14229_WDBI_CALLBACK pCallback,
                                    const U8 nDiagSessionType);

// Initializes "ECUReset" service handler
extern STD_RESULT ISO14229_ERInit(const ISO14229_ER_CALLBACK pCallback,
                                  const U8 nDiagSessionType);

// Initializes OBD services handler
extern STD_RESULT ISO14229_OBDInit(const ISO14229_OBD_CALLBACK pCallback,
                                   const U8 nDiagSessionType);

// Returns current security level
extern U8 ISO14229_GetCurrentSecurityLevel(void);

// Supported diagnostic sessions definition list
#define ISO14229_SESSION_DEFAULT            (0x00U)
#define ISO14229_SESSION_PROGRAMMING        (0x01U)
#define ISO14229_SESSION_EXT_DIAGNOSTIC     (0x02U)
#define ISO14229_SESSION_EOL_SS             (0x03U)
#define ISO14229_SESSION_EOL_VM             (0x04U)



//**************************************************************************************************
// Declarations of EOL functions
//**************************************************************************************************

// EOL command callback interface function prototype
typedef U8 (*ISO14229EOL_CMD_CALLBACK)(const U8  nCommand,
                                       const U8  nChannelsType,
                                       const U8  nChannelsDirection,
                                       const U8  nCommandOption,
                                       const U8  nChannelsListType,
                                       const U32 pChannelsListIn,
                                       const U16 nChannelsListSize,
                                       const U16 nChannelsDataBufferSize,
                                       const U32 pChannelsDataOut,
                                       const U32 pChannelsDataSize);

// EOL activation callback interface function prototype
typedef U8 (*ISO14229EOL_ACTIVATION_CALLBACK)(const BOOLEAN bActivation);

// Initializes SW and HW program module resources
extern void ISO14229EOL_Init(void);

// Deinitializes SW and HW program module resources
extern void ISO14229EOL_DeInit(void);

// Initializes EOL activation event handler
extern void ISO14229EOL_ActivationInit(const ISO14229EOL_ACTIVATION_CALLBACK pCallback);

// Initializes EOL command handler
extern void ISO14229EOL_CmdInit(const ISO14229EOL_CMD_CALLBACK pCallback);



//**************************************************************************************************
// Declarations of ISO 14229 SS functions
//**************************************************************************************************

// Initializes SW and HW program module resources
extern void ISO14229SS_Init(void);



//**************************************************************************************************
// Declarations of ECU ID functions
//**************************************************************************************************

// Initializes SW and HW resources of the program module
extern void ECUID_Init(void);

// Deinitializes SW and HW resources of the program module
extern void ECUID_DeInit(void);

// Sets "end of job" callback function pointer(s) for the specified job type (Load / Store)
extern STD_RESULT ECUID_SetJobCallback(const U8 nJobType,
                                       const U8 nEventID,
                                       const MEM_END_OF_JOB_CALLBACK pCallback);

// Loads data for the specified DataIDentifier
extern STD_RESULT ECUID_Load(const U16 nDataID,
                             U8* const pDataBuffer,
                             const U16 nBufferSize,
                             U16* const pDIDSize);

// Stores the specified data for the specified DataIDentifier
extern STD_RESULT ECUID_Store(const U16 nDataID,
                              const U8* const pDataBuffer,
                              const U16 nDIDSize);



//**************************************************************************************************
// Declarations of Fingerprint Storage ID functions
//**************************************************************************************************

// Initializes SW and HW resources of the program module
extern void FPS_Init(void);



//**************************************************************************************************
// Declarations of LIN functions
//**************************************************************************************************

// Initializes SW and HW resources of the program module
extern STD_RESULT LIN_Init(void);





//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************

// Represents one CAN data frame
#define CAN_FRAME_MAX_DATA_LENGTH   (8U)
typedef struct CAN_FRAME_str
{
    U32 nID;
    U8  nDataLength;
    U8  pDataBuffer[CAN_FRAME_MAX_DATA_LENGTH];

} CAN_FRAME;

// RX callback function prototype
typedef void (*CAN_RX_CALLBACK)(const U16 nPDUID,
                                const U8* const pDataBuffer,
                                const U8  nDataLength);

// TX callback function prototype
typedef void (*CAN_TX_CALLBACK)(const U16 nPDUID);

// Direct RX callback function prototype
typedef void (*CAN_DIRECT_RX_CALLBACK)(const CAN_FRAME* const receivedFrame,
                                       const U8 nBusNumber);

// Direct TX callback function prototype
typedef void (*CAN_DIRECT_TX_CALLBACK)(const U8 nBusNumber);

// Program module wake-up event handler function type
typedef void (*CAN_WAKEUP_HANDLER)(const U8 nEventID);



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

// None.



//**************************************************************************************************
// Declarations of global (public) variables
//**************************************************************************************************

// None.



//**************************************************************************************************
// Declarations of global (public) functions
//**************************************************************************************************

// Initializes SW and HW program module resources
extern STD_RESULT CAN_Init(void);

// Deinitializes SW and HW program module resources
extern STD_RESULT CAN_DeInit(void);

// Reads received message from the specified PDU ID buffer
extern STD_RESULT CAN_Read(const U16 nPDUID,
                           U8* const pDataBuffer,
                           const U8  nDataLength);

// Writes the message to the specified PDU ID buffer
extern STD_RESULT CAN_Write(const U16 nPDUID,
                            const U8* const pDataBuffer,
                            const U8  nDataLength);

// Purges RX and/or TX FIFO data in specified PDU ID buffer
extern STD_RESULT CAN_Purge(const U16     nPDUID,
                            const BOOLEAN bPurgeRX,
                            const BOOLEAN bPurgeTX);

// Writes a number of CAN frames with a real network ID
extern STD_RESULT CAN_WriteDirect(const CAN_FRAME* pFrames,
                                  const U8 nFramesQty,
                                  const U8 nBusNumber);

// Enables or disables CAN wake-up capability
extern STD_RESULT CAN_WakeupEnable(const U8 nBusNumber,
                                   const BOOLEAN bEnable);

// Sets pointer to the wake-up event handler function for the specified CAN bus
extern STD_RESULT CAN_SetWakeupEventHandler(const U8 nBusNumber,
                                            const U8 nEventID,
                                            const CAN_WAKEUP_HANDLER pWakeupHandler);

// Sets new baud rate for selected CAN bus
extern STD_RESULT CAN_SetBaudRate(const U8 nBusNumber,
                                  const U32 nBaudRate);

// Sets RX callback function pointer
extern STD_RESULT CAN_SetRXCallback(const CAN_RX_CALLBACK pCallback);

// Sets TX callback function pointer
extern STD_RESULT CAN_SetTXCallback(const CAN_TX_CALLBACK pCallback);

// Sets Direct RX callback function pointer for received messages with a real network ID
extern STD_RESULT CAN_SetDirectRXCallback(const CAN_DIRECT_RX_CALLBACK pCallback,
                                          const U8 nBusNumber);

// Sets Direct TX callback function pointer for transmitted messages with a real network ID
extern STD_RESULT CAN_SetDirectTXCallback(const CAN_DIRECT_TX_CALLBACK pCallback,
                                          const U8 nBusNumber);

// RX high-level interrupt service routine for all of the CAN buses
extern void CAN_HighLevel_RX_ISR(const U8 nBusNumber);

// TX high-level interrupt service routine for all of the CAN buses
extern void CAN_HighLevel_TX_ISR(const U8 nBusNumber);

// Wake-up high-level interrupt service routine for all of the CAN buses
extern void CAN_HighLevel_Wakeup_ISR(const U8 nBusNumber);

// Error high-level interrupt service routine for all of the CAN buses
extern void CAN_HighLevel_Error_ISR(const U8 nBusNumber);




// End of bootloader job callback
typedef void (*BTLDR_END_OF_JOB_CALLBACK)(const U8 nEventID,
                                          const U8 nJobResult);



// Bootloader markers
#define BTLDR_MARKER_BTLDR             (0U)
#define BTLDR_MARKER_APPL              (1U)
#define BTLDR_MARKER_UNKNOWN           (2U)

// Bootloader job types
#define BTLDR_JOB_SET_ROM_MARKER       (0U)

// Bootloader job possible results
#define BTLDR_JOB_RESULT_OK            (0U)
#define BTLDR_JOB_RESULT_NOT_OK        (1U)

// Execution sessions
#define BTLDR_SESSION_PERM_BTLDR       (0U)
#define BTLDR_SESSION_PERM_APPL        (1U)
#define BTLDR_SESSION_TEMP_BTLDR       (2U)
#define BTLDR_SESSION_TEMP_APPL        (3U)


// Executes the bootloader or a main application depending of the boot marker value
extern void BTLDR_Startup(void);

// Returns bootloader version value
extern U16 BTLDR_GetVersion(void);

// Identifies current ROM boot marker type
extern U8 BTLDR_GetROMMarkerType(void);

// Sets a new ROM boot marker type
extern void BTLDR_SetROMMarkerType(const U8 nMarkerType);

// Sets "end of job" callback function pointer(s) for the BTLDR_SetROMMarkerType()
// function job
extern void BTLDR_SetJobCallback(const U8 nJobType,
                                 const U8 nEventID,
                                 const BTLDR_END_OF_JOB_CALLBACK pCallback);

// Checks, whether specified address value puts in the bootloader address range
extern BOOLEAN BTLDR_IsAddressInBootloaderArea(const U32 nAddressToCheck);

// Executes bootloader through the software reset
extern void BTLDR_ResetToBtldr(void);

// Executes application through the software reset
extern void BTLDR_ResetToAppl(void);

// Returns current execution session: bootloader or application
extern U8 BTLDR_GetCurrentSession(void);



//**************************************************************************************************
// Declarations of Randomize functions
//**************************************************************************************************

// Start generating random
extern STD_RESULT Random_Init(void);

// Returns if random data is available
extern BOOLEAN Random_GetStatus(void);

// Get random bytes
extern STD_RESULT Random_GetData(U8* dataBuffer,
                                 U16 length);

// Should be called periodically to collect entropy
extern void Random_HighLevelISR(void);



//**************************************************************************************************
// Declarations of VBSEC2 functions
//**************************************************************************************************

//errors of decoder of the immobilizer response:
// not errors
#define VBSEC2_NO_ERROR                        (0U)
// received packet checksum error
#define VBSEC2_ERROR_CRC16                     (1U)
// the protocol discriminator does not match
#define VBSEC2_ERROR_PROTOCOL_DISCRIMINATOR    (2U)
// protocol version does not match
#define VBSEC2_ERROR_PROTOCOL_VERSION          (3U)

// initialization of immobilizer variables
extern void VBSEC2_Init(U16 protocolDiscriminator,
                        U32 shifratorDiscriminator,
                        U16 protocolVersion);

// calculating the request to the immobilizer controller
extern void VBSEC2_CalcRequest(const U8* const pSystemPassword,
                               const U8* const pRandom,
                               U8* const pCanRequest);

// decoder of the immobilizer controller response
extern U8 VBSEC2_DecoderResponse(U8* const pCanResponse,
                                 U8* const pImmoState);

// formation of sending a new system password
extern void VBSEC2_CalcNewPassword(const U8* const pSystemPassword,
                                   U8* const pCanRequest);

// formation of a repeated request
extern void VBSEC2_RepeatRequest(U8* const pCanRequest);

// calculation of the checksum of the U8 array
extern U16 VBSEC2_CRC16(const U8* const massiv,
                        U8 length);



//**************************************************************************************************
// Declarations of RAnd_Num function
//**************************************************************************************************

// Calculates KEY value from SEED value
extern U32 Rand_Num(const U32 num_time);



//**************************************************************************************************
// Declarations of Car Access service functions
//**************************************************************************************************

// Initializes SW and HW stack resources
extern void CARACC_Init(void);

extern U8 CARACC_IsInitialized(void);

extern U8 CALRN_GetLearnStatus(void);

// Periodical routines which should call in corresponding time machine levels
extern void CARACC_HighLevel_TimeRaster_1ms(void);
extern void CARACC_HighLevel_TimeRaster_10ms(void);
extern void CARACC_HighLevel_TimeRaster_100ms(void);
extern void CARACC_HighLevel_TimeRaster_1s(void);



//**************************************************************************************************
// Declarations of Remote Control Unit service functions
//**************************************************************************************************

// Starts authentication process
extern void RCU_StartAuth(const U8 nChannelType,
                          const U8 nAntNumMask,
                          const U8 nKeyfobNum);

// Returns result of authentication process
extern U8 RCU_GetAuthState(void);

// Returns received RCU's requests
extern STD_RESULT RCU_GetRkeRequest(U8* const pKeyNumber,
                                    U8* const pKeyActBtnMask,
                                    U8* const pKeyBatteryStatus);
                                    
                                    
                                    
//**************************************************************************************************
// Declarations of Car Access service EOL functions
//**************************************************************************************************                                    

// Sends request by LF
extern STD_RESULT CARACC_EOL_SendRequest(const U8 nAntennaSelectionMask);

// Gets RSSI values of the RF signals
extern STD_RESULT CARACC_EOL_GetResponse(U8* const pAntennaNumber,
                                         U8* const pRSSI_RCU,
                                         U8* const pRSSI_ECU);
                                         
                                         
                                         
#endif // #ifndef EHAL_LIB
