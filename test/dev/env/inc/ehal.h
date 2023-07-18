//**************************************************************************************************
// @Module        EHAL
// @Filename      ehal.h
//--------------------------------------------------------------------------------------------------
// @Description   Interface of EHAL.
//
//                Abbreviations:
//                  ADC - Analog to Digital Converter
//                  CAN - Controller Area Network
//                  CCP - CAN Calibration Protocol
//                  COMR - COMmunication Router
//                  CRC - Cyclic Redundancy Check
//                  CS - Checksum
//                  ECU - Electronic Control Unit
//                  EEPROM - Electrically Erasable Programmable Read-Only Memory
//                  ENC - ENCoder
//                  EOL - End Of Line
//                  ESCL - Electrical Steering Column Lock
//                  GPIO - General Purpose Input/Output
//                  I2C - Inter-Integrated Circuit
//                  ICU - Input Capture Unit
//                  INDM - INDuctive loads Manager
//                  IO - Input-Output
//                  LIN - Local Interconnect Network
//                  MCU - Micro Controller Unit
//                  MGR - ManaGeR
//                  PIT - Programmable Interrupt Timer
//                  PWM - Pulse Width Modulator
//                  RTOS - Real-Time Operating System
//                  SA - Security Access
//                  SIGMAN - SIGnal MANager
//                  SPI - Serial Peripheral interface
//                  TRCV - TRansCeiVer
//                  UART - Universal Asynchronous Receiver and Transmitter
//                  WDT - WatchDog Timer
//
//--------------------------------------------------------------------------------------------------
// @Version       2.33.0
//--------------------------------------------------------------------------------------------------
// @Date          19.04.2022
//--------------------------------------------------------------------------------------------------
// @History       Version  Author      Comment
// 18.05.2015     1.0.0    ASD         First release.
// 15.07.2015     1.1.0    SRM         COM Router SW module added.
// 16.07.2015     1.2.0    SRM         IO manager SW module added.
// 05.08.2015     1.2.1    Savochkin   CCPMonitor.h renamed to ccp_monitor.h.
// 25.08.2015     1.3.0    ASD         Software timer SW module added.
// 24.09.2015     1.4.0    SRM         J1939 SW module added.
// 25.09.2015     1.5.0    SRM         EHAL precompiled library support has been added.
// 23.10.2015     1.6.0    SRM         Power Manager interfaces has been added.
// 05.11.2015     1.7.0    SRM         CAN and LIN transceivers interfaces has been added.
// 10.12.2015     1.8.0    ASD         Sorting library has been added.
// 24.12.2015     1.9.0    SHA         Angle Synchronization services has been added.
// 29.01.2016     1.9.1    ASD         Sorting library has been renamed.
// 01.03.2016     2.0.0    SRM         "J1939" program module has been renamed into "J1939-71".
// 15.03.2016     2.1.0    SRM         All of the includes has been framed by "ifdef" and "endif"
//                                     in order to simplify configuration files handling.
// 05.04.2016     2.2.0    SRM         J1939-21 program module has been added.
// 12.04.2016     2.3.0    SRM         J1939-21 interface has been expanded.
// 28.04.2016     2.4.0    POA         LED and PAD interfaces was added.
// 12.05.2016     2.5.0    SHA         IC_DRV8711 interfaces was added.
// 11.07.2016     2.5.1    SHA         Correction synchronization function names.
// 20.07.2016     2.6.0    SRM         New memory interface.
// 22.07.2016     2.7.0    POA         Injection manager interface was added.
// 17.08.2016     2.8.0    SIV         CRC32 interface has been added.
// 04.10.2016     2.9.0    SRM         ISO14229 interface has been added.
// 12.10.2016     2.9.1    POA         Injection manager renamed to Induction loads manager.
// 20.10.2016     2.9.2    SHA         Added ConvertToPtr_xxxbit function interface.
// 11.01.2017     2.9.3    SRM         ISO14229 interface has been expanded.
// 30.01.2017     2.9.4    SIV         CAN direct interfaces has been added.
// 26.04.2017     2.9.5    SHA         IO manager periodic signal interface has been added.
// 05.05.2017     2.9.6    SHA         Knock services and scheduler interfaces has been added.
// 31.05.2017     2.9.7    SHA         Scheduler interface has been changed.
// 15.06.2017     2.10.0   ASD         Deleted ADC, GPIO, PWM and ICU drivers.
// 31.05.2017     2.10.1   SHA         Angle synchronization interface has been changed.
// 20.06.2017     2.11.0   SRM         ISO_14229 EOL software module has been added.
// 21.06.2017     2.11.1   SHA         Sensor emulator interface has been changed and knock services
//                                     interface file has been added.
// 05.07.2017     2.12.0   SRM         ISO_14229 EOL interface has been expanded.
// 05.07.2017     2.13.0   SRM         ECUID software module has been added.
// 07.07.2017     2.14.0   SRM         Bootloader interfaces has been updated.
// 09.07.2017     2.15.0   SRM         ISO_14229 interface has been updated.
// 17.08.2017     2.16.0   SRM         EOL interface has been expanded.
// 10.11.2017     2.17.0   SHA         ENC interface has been added.
// 22.02.2018     2.18.0   SRM         Signal manager interface has been added.
// 07.06.2018     2.19.0   SRM         ISO14229 interface has been expanded.
// 15.06.2018     2.20.0   SIV         Dictionary interface has been added.
// 13.03.2019     2.21.0   SHA         Removed function SPI_SetMode()
// 25.06.2019     2.22.0   ZAO         Added function SCHDL_GetAndResetIdleCounter()
// 27.09.2019     2.23.0   ZAO         Added Immo_mstr & Immo_slv & Randomizer functions
// 07.11.2019     2.24.0   ZAO         Added RCU functions
// 13.11.2019     2.25.0   ZAO         Added Checksum functions
// 17.06.2020     2.26.0   ZAO         Added ISO14229SS functions
// 16.04.2021     2.27.0   SIV         Added Fingerprint storage functions
// 16.04.2021     2.28.0   SIV         Added ESCL functions and ISO14229_WDBIInit()
// 22.04.2021     2.29.0   SIV         Added IC_12XS6_Set/GetChipState() functions
// 16.06.2021     2.30.0   SIV         Added CRC16KB_GetCRC16() function
// 24.06.2021     2.31.0   MAV         Added CRC8AS_GetCRC8() function
// 13.07.2021     2.32.0   SIV         Added MSE_DA_MULTI functions
// 19.04.2022     2.33.0   SHA         Added VBSEC2 functions
//**************************************************************************************************

#ifndef EHAL_H
#define EHAL_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Define data types
#include "compiler.h"
#include "general.h"
#include "ehal_cfg.h"



// Get EHAL library interface
#if (ON == EHAL_USE_PRECOMPILED_LIBRARY)
#include "ehal_lib.h"
#else // #if (ON == EHAL_USE_PRECOMPILED_LIBRARY)

// Get COM Router interface definitions
#ifdef EHAL_COMR_SW_MODULE_ENABLE
#if (ON == EHAL_COMR_SW_MODULE_ENABLE)
#include "com_router.h"
#endif // #if (ON == EHAL_COMR_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_COMR_SW_MODULE_ENABLE

// Get SAE J1939-21 interface definitions
#ifdef EHAL_SAE_J1939_21_SW_MODULE_ENABLE
#if (ON == EHAL_SAE_J1939_21_SW_MODULE_ENABLE)
#include "sae_j1939_21.h"
#endif // #if (ON == EHAL_SAE_J1939_21_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_SAE_J1939_21_SW_MODULE_ENABLE

// Get SAE J1939-71 interface definitions
#ifdef EHAL_SAE_J1939_71_SW_MODULE_ENABLE
#if (ON == EHAL_SAE_J1939_71_SW_MODULE_ENABLE)
#include "sae_j1939_71.h"
#endif // #if (ON == EHAL_SAE_J1939_71_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_SAE_J1939_71_SW_MODULE_ENABLE

// Get CAN driver interface definitions
#ifdef EHAL_CAN_DRV_SW_MODULE_ENABLE
#if (ON == EHAL_CAN_DRV_SW_MODULE_ENABLE)
#include "can_drv.h"
#endif // #if (ON == EHAL_CAN_DRV_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_CAN_DRV_SW_MODULE_ENABLE

// Get CAN transceiver interface definitions
#ifdef EHAL_CAN_TRCV_SW_MODULE_ENABLE
#if (ON == EHAL_CAN_TRCV_SW_MODULE_ENABLE)
#include "can_trcv.h"
#endif // #if (ON == EHAL_CAN_TRCV_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_CAN_TRCV_SW_MODULE_ENABLE

// Get UART driver interface definitions
#ifdef EHAL_UART_DRV_SW_MODULE_ENABLE
#if (ON == EHAL_UART_DRV_SW_MODULE_ENABLE)
#include "uart_drv.h"
#endif // #if (ON == EHAL_UART_DRV_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_UART_DRV_SW_MODULE_ENABLE

// Get SPI driver interface definitions
#ifdef EHAL_SPI_DRV_SW_MODULE_ENABLE
#if (ON == EHAL_SPI_DRV_SW_MODULE_ENABLE)
#include "spi_drv.h"
#endif // #if (ON == EHAL_SPI_DRV_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_SPI_DRV_SW_MODULE_ENABLE

// Get LIN interface definitions
#ifdef EHAL_LIN_SW_MODULE_ENABLE
#if (ON == EHAL_LIN_SW_MODULE_ENABLE)
#include "lin.h"
#endif // #if (ON == EHAL_LIN_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_LIN_SW_MODULE_ENABLE

// Get LIN transceiver interface definitions
#ifdef EHAL_LIN_TRCV_SW_MODULE_ENABLE
#if (ON == EHAL_LIN_TRCV_SW_MODULE_ENABLE)
#include "lin_trcv.h"
#endif // #if (ON == EHAL_LIN_TRCV_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_LIN_TRCV_SW_MODULE_ENABLE

// Get CCP interface definitions
#ifdef EHAL_CCP_SW_MODULE_ENABLE
#if (ON == EHAL_CCP_SW_MODULE_ENABLE)
#include "ccp_monitor.h"
#endif // #if (ON == EHAL_CCP_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_CCP_SW_MODULE_ENABLE

// Get INDM (inductive loads manager) interface definitions
#ifdef EHAL_INDM_SW_MODULE_ENABLE
#if (ON == EHAL_INDM_SW_MODULE_ENABLE)
#include "inductive_loads_manager.h"
#endif // #if (ON == EHAL_INDM_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_INDM_SW_MODULE_ENABLE

// Get IO manager interface definitions
#ifdef EHAL_IO_MGR_SW_MODULE_ENABLE
#if (ON == EHAL_IO_MGR_SW_MODULE_ENABLE)
#include "io_manager.h"
#endif // #if (ON == EHAL_IO_MGR_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_IO_MGR_SW_MODULE_ENABLE

// Get memory manager interface definitions
#ifdef EHAL_MEM_MAN_SW_MODULE_ENABLE
#if (ON == EHAL_MEM_MAN_SW_MODULE_ENABLE)
#include "memory_manager.h"
#endif // #if (ON == EHAL_MEM_MAN_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_MEM_MAN_SW_MODULE_ENABLE

// Get EEPROM interface definitions
// TBD...

// Get Timer driver interface definitions
#ifdef EHAL_TIMER_DRV_SW_MODULE_ENABLE
#if (ON == EHAL_TIMER_DRV_SW_MODULE_ENABLE)
#include "timer_drv.h"
#endif // #if (ON == EHAL_TIMER_DRV_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_TIMER_DRV_SW_MODULE_ENABLE

// Get PIT driver interface definitions
#ifdef EHAL_PIT_DRV_SW_MODULE_ENABLE
#if (ON == EHAL_PIT_DRV_SW_MODULE_ENABLE)
#include "../../System_SW/Driver_PIT/pit_drv.h"
#endif // #if (ON == EHAL_PIT_DRV_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_PIT_DRV_SW_MODULE_ENABLE

// Get WDT driver interface definitions
#ifdef EHAL_WDT_DRV_SW_MODULE_ENABLE
#if (ON == EHAL_WDT_DRV_SW_MODULE_ENABLE)
#include "wdt_drv.h"
#endif // #if (ON == EHAL_WDT_DRV_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_WDT_DRV_SW_MODULE_ENABLE

// Get Software timer interface definitions
#ifdef EHAL_SOFT_TIMER_SW_MODULE_ENABLE
#if (ON == EHAL_SOFT_TIMER_SW_MODULE_ENABLE)
#include "software_timer.h"
#endif // #if (ON == EHAL_SOFT_TIMER_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_SOFT_TIMER_SW_MODULE_ENABLE

// Get OS interface definitions
#ifdef EHAL_SCHEDULER_SW_MODULE_ENABLE
#if (ON == EHAL_SCHEDULER_SW_MODULE_ENABLE)
#include "../../System_SW/OS/scheduler.h"
#endif // #if (ON == EHAL_SCHEDULER_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_SCHEDULER_SW_MODULE_ENABLE

// Get MCU interface definitions
#ifdef EHAL_MCU_DRV_SW_MODULE_ENABLE
#if (ON == EHAL_MCU_DRV_SW_MODULE_ENABLE)
#include "../../System_SW/Driver_MCU/mcu_drv.h"
#endif // #if (ON == EHAL_MCU_DRV_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_MCU_DRV_SW_MODULE_ENABLE

// Get Bootloader interface definitions
#ifdef EHAL_BOOTLOADER_SW_MODULE_ENABLE
#if (ON == EHAL_BOOTLOADER_SW_MODULE_ENABLE)
#include "btldr.h"
#endif // #if (ON == EHAL_BOOTLOADER_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_BOOTLOADER_SW_MODULE_ENABLE

// Get Power manager interfaces definitions
#ifdef EHAL_POWMAN_SW_MODULE_ENABLE
#if (ON == EHAL_POWMAN_SW_MODULE_ENABLE)
#include "power_manager.h"
#endif // #if (ON == EHAL_POWMAN_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_POWMAN_SW_MODULE_ENABLE

// Get Checksum interface definitions
#ifdef EHAL_CHECKSUM_SW_MODULE_ENABLE
#if (ON == EHAL_CHECKSUM_SW_MODULE_ENABLE)
#include "Checksum.h"
#endif // #if (ON == EHAL_CHECKSUM_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_CHECKSUM_SW_MODULE_ENABLE

// Get CRC32 interface definitions
#ifdef EHAL_CRC32_SW_MODULE_ENABLE
#if (ON == EHAL_CRC32_SW_MODULE_ENABLE)
#include "crc32.h"
#endif // #if (ON == EHAL_CRC32_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_CRC32_SW_MODULE_ENABLE

// Get CRC8 dallas interface definitions
#ifdef EHAL_CRC8_SW_MODULE_ENABLE
#if (ON == EHAL_CRC8_SW_MODULE_ENABLE)
#include "crc8_dallas.h"
#endif // #if (ON == EHAL_CRC8_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_CRC8_SW_MODULE_ENABLE

// Dictionary interface
#ifdef EHAL_DICT_SW_MODULE_ENABLE
#if (ON == EHAL_DICT_SW_MODULE_ENABLE)
#include "dictionary.h"
#endif // #if (ON == EHAL_DICT_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_DICT_SW_MODULE_ENABLE

// Get Security Access interface definitions
#ifdef EHAL_SA_SW_MODULE_ENABLE
#if (ON == EHAL_SA_SW_MODULE_ENABLE)
#include "security_access.h"
#endif // #if (ON == EHAL_SA_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_SA_SW_MODULE_ENABLE

// Get ISO 14229 interface definitions
#ifdef EHAL_ISO_14229_SW_MODULE_ENABLE
#if (ON == EHAL_ISO_14229_SW_MODULE_ENABLE)
#include "iso14229.h"
#endif // #if (ON == EHAL_ISO_14229_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_ISO_14229_SW_MODULE_ENABLE

// Get ISO 14229 EOL interface definitions
#ifdef EHAL_ISO_14229EOL_SW_MODULE_ENABLE
#if (ON == EHAL_ISO_14229EOL_SW_MODULE_ENABLE)
#include "iso14229eol.h"
#endif // #if (ON == EHAL_ISO_14229EOL_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_ISO_14229EOL_SW_MODULE_ENABLE

// Get ECUID interface definitions
#ifdef EHAL_ECUID_SW_MODULE_ENABLE
#if (ON == EHAL_ECUID_SW_MODULE_ENABLE)
#include "ecu_id.h"
#endif // #if (ON == EHAL_ECUID_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_ECUID_SW_MODULE_ENABLE

// Get ISO 15765 interface definitions
#ifdef EHAL_ISO_15765_SW_MODULE_ENABLE
#if (ON == EHAL_ISO_15765_SW_MODULE_ENABLE)
#include "API_CAN15765.h"
#endif // #if (ON == EHAL_ISO_15765_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_ISO_15765_SW_MODULE_ENABLE

// Get Random Number interface definitions
#ifdef EHAL_RND_SW_MODULE_ENABLE
#if (ON == EHAL_RND_SW_MODULE_ENABLE)
#include "rand_num.h"
#endif // #if (ON == EHAL_RND_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_RND_SW_MODULE_ENABLE

// Get MSE Data Access interface definitions
#ifdef EHAL_MSE_DA_SW_MODULE_ENABLE
#if (ON == EHAL_MSE_DA_SW_MODULE_ENABLE)
#include "mse_da.h"
#endif // #if (ON == EHAL_MSE_DA_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_MSE_DA_SW_MODULE_ENABLE

// Get Sorting interface definitions
#ifdef EHAL_SORTING_SW_MODULE_ENABLE
#if (ON == EHAL_SORTING_SW_MODULE_ENABLE)
#include "sorting.h"
#endif // #if (ON == EHAL_SORTING_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_SORTING_SW_MODULE_ENABLE

// Get Angle Synchronization interface definitions
#ifdef EHAL_ANG_SYNCH_SW_MODULE_ENABLE
#if (ON == EHAL_ANG_SYNCH_SW_MODULE_ENABLE)
#include "bsync.h"
#include "emul_crk_cam.h"
#endif // #if (ON == EHAL_ANG_SYNCH_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_ANG_SYNCH_SW_MODULE_ENABLE

// Get Knock services interface definitions
#ifdef EHAL_KNOCK_SW_MODULE_ENABLE
#if (ON == EHAL_KNOCK_SW_MODULE_ENABLE)
#include "knock.h"
#endif // #if (ON == EHAL_KNOCK_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_KNOCK_SW_MODULE_ENABLE

// Get PAD (keyboard) interface definitions
#ifdef EHAL_PAD_SW_MODULE_ENABLE
#if (ON == EHAL_PAD_SW_MODULE_ENABLE)
#include "pad_drv.h"
#endif // #if (ON == EHAL_PAD_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_PAD_SW_MODULE_ENABLE

// Get PAD (keyboard) interface definitions
#ifdef EHAL_LED_SW_MODULE_ENABLE
#if (ON == EHAL_LED_SW_MODULE_ENABLE)
#include "led_drv.h"
#endif // #if (ON == EHAL_LED_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_LED_SW_MODULE_ENABLE

// Get ENC interface definitions
#ifdef EHAL_ENC_SW_MODULE_ENABLE
#if (ON == EHAL_ENC_SW_MODULE_ENABLE)
#include "enc_drv.h"
#endif // #if (ON == EHAL_ENC_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_ENC_SW_MODULE_ENABLE

// Get IC_DRV8711 interface definitions
#ifdef EHAL_IC_DRV8711_SW_MODULE_ENABLE
#if (ON == EHAL_IC_DRV8711_SW_MODULE_ENABLE)
#include "IC_DRV8711.h"
#endif // #if (ON == EHAL_IC_DRV8711_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_IC_DRV8711_SW_MODULE_ENABLE

// Get Signal manager interface definitions
#ifdef EHAL_SIGNAL_MGR_SW_MODULE_ENABLE
#if (ON == EHAL_SIGNAL_MGR_SW_MODULE_ENABLE)
#include "sig_man.h"
#endif // #if (ON == EHAL_SIGNAL_MGR_SW_MODULE_ENABLE)
#endif // #ifdef EHAL_SIGNAL_MGR_SW_MODULE_ENABLE

// Get Immobilizer master part interface
#ifdef EHAL_IMMO_MSTR_ENABLE
#if (ON == EHAL_IMMO_MSTR_ENABLE)
#include "immo_mstr.h"
#endif // #if (ON == EHAL_IMMO_MSTR_ENABLE)
#endif // #ifdef EHAL_IMMO_MSTR_ENABLE

// Get Immobilizer slave part interface
#ifdef EHAL_IMMO_SLV_ENABLE
#if (ON == EHAL_IMMO_SLV_ENABLE)
#include "immo_slv.h"
#endif // #if (ON == EHAL_IMMO_SLV_ENABLE)
#endif // #ifdef EHAL_IMMO_SLV_ENABLE

// Get Randomizer interface
#ifdef EHAL_RND_SW_MODULE_ENABLE
#if (ON == EHAL_RND_SW_MODULE_ENABLE)
#include "Random.h"
#endif // #if (ON == EHAL_RANDOMIZER_ENABLE)
#endif // #ifdef EHAL_RANDOMIZER_ENABLE

// Get RCU inteface
#ifdef EHAL_RCU_ENABLE
#if (ON == EHAL_RCU_ENABLE)
#include "RCU.h"
#endif  // #if (ON == EHAL_RCU_ENABLE)
#endif // #ifdef EHAL_RCU_ENABLE

// Get VBSEC2 inteface
#ifdef EHAL_VBSEC2_ENABLE
#if (ON == EHAL_VBSEC2_ENABLE)
#include "vbsec2.h"
#endif  // #if (ON == EHAL_VBSEC2_ENABLE)
#endif // #ifdef EHAL_VBSEC2_ENABLE

#endif // #if (ON == EHAL_USE_PRECOMPILED_LIBRARY)



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

#define EHAL_ISO14229_OBDInit                       ISO14229_OBDInit
#define EHAL_ISO14229_DSCInit                       ISO14229_DSCInit
#define EHAL_ISO14229_ERInit                        ISO14229_ERInit
#define EHAL_ISO14229_CCInit                        ISO14229_CCInit
#define EHAL_ISO14229_TPInit                        ISO14229_TPInit
#define EHAL_ISO14229_RDBIInit                      ISO14229_RDBIInit
#define EHAL_ISO14229_WDBIInit                      ISO14229_WDBIInit
#define EHAL_ISO14229_WMBAInit                      ISO14229_WMBAInit
#define EHAL_ISO14229_CDIInit                       ISO14229_CDIInit
#define EHAL_ISO14229_RDTCIInit                     ISO14229_RDTCIInit
#define EHAL_ISO14229_RDTCIInitExtended             ISO14229_RDTCIInitExtended
#define EHAL_ISO14229_IOCBIInit                     ISO14229_IOCBIInit
#define EHAL_ISO14229_RCInit                        ISO14229_RCInit
#define EHAL_ISO14229_RDInit                        ISO14229_RDInit
#define EHAL_ISO14229_TDInit                        ISO14229_TDInit
#define EHAL_ISO14229_RTEInit                       ISO14229_RTEInit
#define EHAL_ISO14229_CDTCSInit                     ISO14229_CDTCSInit
#define EHAL_ISO14229_SendAsyncResponse             ISO14229_SendAsyncResponse
#define EHAL_ISO14229_GetCurrentSecurityLevel       ISO14229_GetCurrentSecurityLevel
#define EHAL_ISO14229_RequestResetToAppl            ISO14229_RequestResetToAppl

#define EHAL_ISO14229_SESSION_DEFAULT               ISO14229_SESSION_DEFAULT
#define EHAL_ISO14229_SESSION_PROGRAMMING           ISO14229_SESSION_PROGRAMMING
#define EHAL_ISO14229_SESSION_EXT_DIAGNOSTIC        ISO14229_SESSION_EXT_DIAGNOSTIC
#define EHAL_ISO14229_SESSION_EOL_SS                ISO14229_SESSION_EOL_SS
#define EHAL_ISO14229_SESSION_EOL_VM                ISO14229_SESSION_EOL_VM
#define EHAL_ISO14229_SESSION_SEC_AND_SAF           ISO14229_SESSION_SEC_AND_SAF
#define EHAL_ISO14229_SESSION_ENGINEER              ISO14229_SESSION_ENGINEER

#define EHAL_ISO14229_SEC_LEVEL_DEFAULT             ISO14229_SESSION_DEFAULT
#define EHAL_ISO14229_SEC_LEVEL_PROGRAMMING         ISO14229_SESSION_PROGRAMMING
#define EHAL_ISO14229_SEC_LEVEL_EXT_DIAGNOSTIC      ISO14229_SESSION_EXT_DIAGNOSTIC
#define EHAL_ISO14229_SEC_LEVEL_EOL_SS              ISO14229_SESSION_EOL_SS
#define EHAL_ISO14229_SEC_LEVEL_EOL_VM              ISO14229_SESSION_EOL_VM
#define EHAL_ISO14229_SEC_LEVEL_SEC_AND_SAF         ISO14229_SESSION_SEC_AND_SAF
#define EHAL_ISO14229_SEC_LEVEL_ENGINEER            ISO14229_SESSION_ENGINEER

#define EHAL_ISO14229SS_Init                        ISO14229SS_Init
#define EHAL_ISO14229SS_DeInit                      ISO14229SS_DeInit

// EOL
#define EHAL_EOL_Init                               ISO14229EOL_Init
#define EHAL_EOL_DeInit                             ISO14229EOL_DeInit
#define EHAL_EOL_ActivationInit                     ISO14229EOL_ActivationInit
#define EHAL_EOL_CmdInit                            ISO14229EOL_CmdInit

// ECU ID
#define EHAL_ECUID_Init                             ECUID_Init
#define EHAL_ECUID_DeInit                           ECUID_DeInit

// Fingerprint Storage
#define EHAL_FPS_Init                               FPS_Init
#define EHAL_FPS_DeInit                             FPS_DeInit

// SAE J1939-21
#define EHAL_COM_J1939_21_Init                      J1939_21_Init
#define EHAL_COM_J1939_21_DeInit                    J1939_21_DeInit
#define EHAL_COM_J1939_21_SetSyncRXMessage          J1939_21_SetSyncRXMessage
#define EHAL_COM_J1939_21_SetAsyncTXMessage         J1939_21_SetAsyncTXMessage
#define EHAL_COM_J1939_21_SyncReceive               J1939_21_SyncReceive
#define EHAL_COM_J1939_21_AsyncTransmit             J1939_21_AsyncTransmit
#define EHAL_COM_J1939_21_Process                   J1939_21_Process

// SAE J1939-71
#define EHAL_COM_J1939_Receive                      J1939_71_Receive
#define EHAL_COM_J1939_Transmit                     J1939_71_Transmit
#define EHAL_COM_J1939_SetCallbackFunctions         J1939_71_SetCallbackFunctions

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
#define EHAL_COM_CCP_HighLevel_ISR                  CCP_HighLevel_ISR



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
#define EHAL_IO_MGR_P_SetTickResolution             IO_P_SetTickResolution
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
#define APP_LIN_Init                                SIGMAN_Init
#define APP_LIN_DeInit                              SIGMAN_DeInit
#define APP_LIN_GetSignalState                      SIGMAN_GetSignalState
#define APP_LIN_SetSignalState                      SIGMAN_SetSignalState



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
#define EHAL_TMR_TIMER_DeInit                       TIMER_DeInit
#define EHAL_TMR_TIMER_GetTime                      TIMER_GetTime
#define EHAL_TMR_TIMER_GetTimeElapsed               TIMER_GetTimeElapsed
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
#define EHAL_OS_Activate_Level                      SCHDL_StartLevel
#define EHAL_OS_SCHDL_Init                          SCHDL_Init
#define EHAL_OS_SCHDL_DeInit                        SCHDL_DeInit
#define EHAL_OS_SCHDL_Enable                        SCHDL_Enable
#define EHAL_OS_SCHDL_Disable                       SCHDL_Disable
#define EHAL_OS_SCHDL_StartLevel                    SCHDL_StartLevel
#define EHAL_OS_SCHDL_ActivateLevel                 SCHDL_ActivateLevel
#define EHAL_OS_SCHDL_StartSchedule                 SCHDL_StartSchedule
#define EHAL_OS_SCHDL_IncIdleCounter                SCHDL_IncIdleCounter
#define EHAL_OS_SCHDL_GetIdleCounter                SCHDL_GetIdleCounter
#define EHAL_OS_SCHDL_GetAndResetIdleCounter        SCHDL_GetAndResetIdleCounter

// MCU interface
#define EHAL_OS_MCU_Init                            MCU_Init
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

// CRC16 interface
#define EHAL_GLIB_CRC16KB_GetCRC16                  CRC16KB_GetCRC16

// CRC8 dallas interface
#define EHAL_GLIB_Crc8_Dallas                       Crc8_Dallas

// CRC8 AutoSAR interface
#define EHAL_GLIB_CRC8AS_GetCRC8                    CRC8AS_GetCRC8

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

// MSE Data Access interface
#define EHAL_GLIB_MSE_DA_ReadParameter1             MSE_DA_ReadParameter1
#define EHAL_GLIB_MSE_DA_ReadParameter2             MSE_DA_ReadParameter2
#define EHAL_GLIB_MSE_DA_ReadParameter4             MSE_DA_ReadParameter4
#define EHAL_GLIB_MSE_DA_ReadParameter1I            MSE_DA_ReadParameter1I
#define EHAL_GLIB_MSE_DA_ReadParameter2I            MSE_DA_ReadParameter2I
#define EHAL_GLIB_MSE_DA_ReadParameter4I            MSE_DA_ReadParameter4I
#define EHAL_GLIB_MSE_DA_UpdateCoordinate1s         MSE_DA_UpdateCoordinate1s
#define EHAL_GLIB_MSE_DA_UpdateCoordinate1u         MSE_DA_UpdateCoordinate1u
#define EHAL_GLIB_MSE_DA_UpdateCoordinate2s         MSE_DA_UpdateCoordinate2s
#define EHAL_GLIB_MSE_DA_UpdateCoordinate2u         MSE_DA_UpdateCoordinate2u
#define EHAL_GLIB_MSE_DA_UpdateCoordinateRW1s       MSE_DA_UpdateCoordinateRW1s
#define EHAL_GLIB_MSE_DA_UpdateCoordinateRW1u       MSE_DA_UpdateCoordinateRW1u
#define EHAL_GLIB_MSE_DA_UpdateCoordinateRW2s       MSE_DA_UpdateCoordinateRW2s
#define EHAL_GLIB_MSE_DA_UpdateCoordinateRW2u       MSE_DA_UpdateCoordinateRW2u
#define EHAL_GLIB_MSE_DA_WriteVector1               MSE_DA_WriteVector1
#define EHAL_GLIB_MSE_DA_WriteVector1I              MSE_DA_WriteVector1I
#define EHAL_GLIB_MSE_DA_WriteVector2               MSE_DA_WriteVector2
#define EHAL_GLIB_MSE_DA_WriteVector2I              MSE_DA_WriteVector2I
#define EHAL_GLIB_MSE_DA_WriteVector4               MSE_DA_WriteVector4
#define EHAL_GLIB_MSE_DA_WriteVector4I              MSE_DA_WriteVector4I
#define EHAL_GLIB_MSE_DA_Write2DTable1              MSE_DA_Write2DTable1
#define EHAL_GLIB_MSE_DA_Write2DTable1I             MSE_DA_Write2DTable1I
#define EHAL_GLIB_MSE_DA_Write2DTable2              MSE_DA_Write2DTable2
#define EHAL_GLIB_MSE_DA_Write2DTable2I             MSE_DA_Write2DTable2I
#define EHAL_GLIB_MSE_DA_Write2DTable4              MSE_DA_Write2DTable4
#define EHAL_GLIB_MSE_DA_Write2DTable4I             MSE_DA_Write2DTable4I
#define EHAL_GLIB_MSE_DA_ReadVectorNearest1         MSE_DA_ReadVectorNearest1
#define EHAL_GLIB_MSE_DA_ReadVectorNearest1I        MSE_DA_ReadVectorNearest1I
#define EHAL_GLIB_MSE_DA_ReadVectorNearest2         MSE_DA_ReadVectorNearest2
#define EHAL_GLIB_MSE_DA_ReadVectorNearest2I        MSE_DA_ReadVectorNearest2I
#define EHAL_GLIB_MSE_DA_ReadVectorNearest4         MSE_DA_ReadVectorNearest4
#define EHAL_GLIB_MSE_DA_ReadVectorNearest4I        MSE_DA_ReadVectorNearest4I
#define EHAL_GLIB_MSE_DA_Read2DTableNearest1        MSE_DA_Read2DTableNearest1
#define EHAL_GLIB_MSE_DA_Read2DTableNearest1I       MSE_DA_Read2DTableNearest1I
#define EHAL_GLIB_MSE_DA_Read2DTableNearest2        MSE_DA_Read2DTableNearest2
#define EHAL_GLIB_MSE_DA_Read2DTableNearest2I       MSE_DA_Read2DTableNearest2I
#define EHAL_GLIB_MSE_DA_Read2DTableNearest4        MSE_DA_Read2DTableNearest4
#define EHAL_GLIB_MSE_DA_Read2DTableNearest4I       MSE_DA_Read2DTableNearest4I
#define EHAL_GLIB_MSE_DA_GetParameterData1          MSE_DA_GetParameterData1
#define EHAL_GLIB_MSE_DA_GetParameterData2          MSE_DA_GetParameterData2
#define EHAL_GLIB_MSE_DA_GetParameterData4          MSE_DA_GetParameterData4
#define EHAL_GLIB_MSE_DA_ReadExtData1               MSE_DA_ReadExtData1
#define EHAL_GLIB_MSE_DA_ReadExtData1I              MSE_DA_ReadExtData1I
#define EHAL_GLIB_MSE_DA_ReadExtData2               MSE_DA_ReadExtData2
#define EHAL_GLIB_MSE_DA_ReadExtData2I              MSE_DA_ReadExtData2I
#define EHAL_GLIB_MSE_DA_ReadExtData4               MSE_DA_ReadExtData4
#define EHAL_GLIB_MSE_DA_ReadExtData4I              MSE_DA_ReadExtData4I
#define EHAL_GLIB_MSE_DA_ReadExtKey                 MSE_DA_ReadExtKey
#define EHAL_GLIB_MSE_DA_ReadExtKeyI                MSE_DA_ReadExtKeyI
#define EHAL_GLIB_MSE_DA_GetNode2s                  MSE_DA_GetNode2s
#define EHAL_GLIB_MSE_DA_GetNode2u                  MSE_DA_GetNode2u
#define EHAL_GLIB_MSE_DA_GetVectorY_2               MSE_DA_GetVectorY_2
#define EHAL_GLIB_MSE_DA_ParamToParam               MSE_DA_ParamToParam
#define EHAL_GLIB_MSE_DA_ParamToParamDirectROM      MSE_DA_ParamToParamDirectROM
#define EHAL_GLIB_MSE_DA_ParamToParamDirect         MSE_DA_ParamToParamDirect
#define EHAL_GLIB_MSE_DA_ParameterToEEPROM          MSE_DA_ParameterToEEPROM
#define EHAL_GLIB_MSE_DA_ParameterFromEEPROM        MSE_DA_ParameterFromEEPROM
#define EHAL_GLIB_MSE_DA_ParameterToEEPROMDirectROM MSE_DA_ParameterToEEPROMDirectROM
#define EHAL_GLIB_MSE_DA_ParameterToEEPROMDirect    MSE_DA_ParameterToEEPROMDirect
#define EHAL_GLIB_MSE_DA_ParameterFromEEPROMDirect  MSE_DA_ParameterFromEEPROMDirect

// MSE Data Access MULTI interface
#define EHAL_GLIB_MSE_DA_MULTI_ReadParameter1             MSE_DA_MULTI_ReadParameter1
#define EHAL_GLIB_MSE_DA_MULTI_ReadParameter2             MSE_DA_MULTI_ReadParameter2
#define EHAL_GLIB_MSE_DA_MULTI_ReadParameter4             MSE_DA_MULTI_ReadParameter4
#define EHAL_GLIB_MSE_DA_MULTI_ReadParameter1I            MSE_DA_MULTI_ReadParameter1I
#define EHAL_GLIB_MSE_DA_MULTI_ReadParameter2I            MSE_DA_MULTI_ReadParameter2I
#define EHAL_GLIB_MSE_DA_MULTI_ReadParameter4I            MSE_DA_MULTI_ReadParameter4I
#define EHAL_GLIB_MSE_DA_MULTI_UpdateCoordinate1s         MSE_DA_MULTI_UpdateCoordinate1s
#define EHAL_GLIB_MSE_DA_MULTI_UpdateCoordinate1u         MSE_DA_MULTI_UpdateCoordinate1u
#define EHAL_GLIB_MSE_DA_MULTI_UpdateCoordinate2s         MSE_DA_MULTI_UpdateCoordinate2s
#define EHAL_GLIB_MSE_DA_MULTI_UpdateCoordinate2u         MSE_DA_MULTI_UpdateCoordinate2u
#define EHAL_GLIB_MSE_DA_MULTI_UpdateCoordinateRW1s       MSE_DA_MULTI_UpdateCoordinateRW1s
#define EHAL_GLIB_MSE_DA_MULTI_UpdateCoordinateRW1u       MSE_DA_MULTI_UpdateCoordinateRW1u
#define EHAL_GLIB_MSE_DA_MULTI_UpdateCoordinateRW2s       MSE_DA_MULTI_UpdateCoordinateRW2s
#define EHAL_GLIB_MSE_DA_MULTI_UpdateCoordinateRW2u       MSE_DA_MULTI_UpdateCoordinateRW2u
#define EHAL_GLIB_MSE_DA_MULTI_WriteVector1               MSE_DA_MULTI_WriteVector1
#define EHAL_GLIB_MSE_DA_MULTI_WriteVector1I              MSE_DA_MULTI_WriteVector1I
#define EHAL_GLIB_MSE_DA_MULTI_WriteVector2               MSE_DA_MULTI_WriteVector2
#define EHAL_GLIB_MSE_DA_MULTI_WriteVector2I              MSE_DA_MULTI_WriteVector2I
#define EHAL_GLIB_MSE_DA_MULTI_WriteVector4               MSE_DA_MULTI_WriteVector4
#define EHAL_GLIB_MSE_DA_MULTI_WriteVector4I              MSE_DA_MULTI_WriteVector4I
#define EHAL_GLIB_MSE_DA_MULTI_Write2DTable1              MSE_DA_MULTI_Write2DTable1
#define EHAL_GLIB_MSE_DA_MULTI_Write2DTable1I             MSE_DA_MULTI_Write2DTable1I
#define EHAL_GLIB_MSE_DA_MULTI_Write2DTable2              MSE_DA_MULTI_Write2DTable2
#define EHAL_GLIB_MSE_DA_MULTI_Write2DTable2I             MSE_DA_MULTI_Write2DTable2I
#define EHAL_GLIB_MSE_DA_MULTI_Write2DTable4              MSE_DA_MULTI_Write2DTable4
#define EHAL_GLIB_MSE_DA_MULTI_Write2DTable4I             MSE_DA_MULTI_Write2DTable4I
#define EHAL_GLIB_MSE_DA_MULTI_ReadVectorNearest1         MSE_DA_MULTI_ReadVectorNearest1
#define EHAL_GLIB_MSE_DA_MULTI_ReadVectorNearest1I        MSE_DA_MULTI_ReadVectorNearest1I
#define EHAL_GLIB_MSE_DA_MULTI_ReadVectorNearest2         MSE_DA_MULTI_ReadVectorNearest2
#define EHAL_GLIB_MSE_DA_MULTI_ReadVectorNearest2I        MSE_DA_MULTI_ReadVectorNearest2I
#define EHAL_GLIB_MSE_DA_MULTI_ReadVectorNearest4         MSE_DA_MULTI_ReadVectorNearest4
#define EHAL_GLIB_MSE_DA_MULTI_ReadVectorNearest4I        MSE_DA_MULTI_ReadVectorNearest4I
#define EHAL_GLIB_MSE_DA_MULTI_Read2DTableNearest1        MSE_DA_MULTI_Read2DTableNearest1
#define EHAL_GLIB_MSE_DA_MULTI_Read2DTableNearest1I       MSE_DA_MULTI_Read2DTableNearest1I
#define EHAL_GLIB_MSE_DA_MULTI_Read2DTableNearest2        MSE_DA_MULTI_Read2DTableNearest2
#define EHAL_GLIB_MSE_DA_MULTI_Read2DTableNearest2I       MSE_DA_MULTI_Read2DTableNearest2I
#define EHAL_GLIB_MSE_DA_MULTI_Read2DTableNearest4        MSE_DA_MULTI_Read2DTableNearest4
#define EHAL_GLIB_MSE_DA_MULTI_Read2DTableNearest4I       MSE_DA_MULTI_Read2DTableNearest4I
#define EHAL_GLIB_MSE_DA_MULTI_GetParameterData1          MSE_DA_MULTI_GetParameterData1
#define EHAL_GLIB_MSE_DA_MULTI_GetParameterData2          MSE_DA_MULTI_GetParameterData2
#define EHAL_GLIB_MSE_DA_MULTI_GetParameterData4          MSE_DA_MULTI_GetParameterData4
#define EHAL_GLIB_MSE_DA_MULTI_ReadExtData1               MSE_DA_MULTI_ReadExtData1
#define EHAL_GLIB_MSE_DA_MULTI_ReadExtData1I              MSE_DA_MULTI_ReadExtData1I
#define EHAL_GLIB_MSE_DA_MULTI_ReadExtData2               MSE_DA_MULTI_ReadExtData2
#define EHAL_GLIB_MSE_DA_MULTI_ReadExtData2I              MSE_DA_MULTI_ReadExtData2I
#define EHAL_GLIB_MSE_DA_MULTI_ReadExtData4               MSE_DA_MULTI_ReadExtData4
#define EHAL_GLIB_MSE_DA_MULTI_ReadExtData4I              MSE_DA_MULTI_ReadExtData4I
#define EHAL_GLIB_MSE_DA_MULTI_ReadExtKey                 MSE_DA_MULTI_ReadExtKey
#define EHAL_GLIB_MSE_DA_MULTI_ReadExtKeyI                MSE_DA_MULTI_ReadExtKeyI
#define EHAL_GLIB_MSE_DA_MULTI_GetNode2s                  MSE_DA_MULTI_GetNode2s
#define EHAL_GLIB_MSE_DA_MULTI_GetNode2u                  MSE_DA_MULTI_GetNode2u
#define EHAL_GLIB_MSE_DA_MULTI_GetVectorY_2               MSE_DA_MULTI_GetVectorY_2
#define EHAL_GLIB_MSE_DA_MULTI_ParamToParam               MSE_DA_MULTI_ParamToParam
#define EHAL_GLIB_MSE_DA_MULTI_ParamToParamDirectROM      MSE_DA_MULTI_ParamToParamDirectROM
#define EHAL_GLIB_MSE_DA_MULTI_ParamToParamDirect         MSE_DA_MULTI_ParamToParamDirect
#define EHAL_GLIB_MSE_DA_MULTI_ParameterToEEPROM          MSE_DA_MULTI_ParameterToEEPROM
#define EHAL_GLIB_MSE_DA_MULTI_ParameterFromEEPROM        MSE_DA_MULTI_ParameterFromEEPROM
#define EHAL_GLIB_MSE_DA_MULTI_ParameterToEEPROMDirectROM MSE_DA_MULTI_ParameterToEEPROMDirectROM
#define EHAL_GLIB_MSE_DA_MULTI_ParameterToEEPROMDirect    MSE_DA_MULTI_ParameterToEEPROMDirect
#define EHAL_GLIB_MSE_DA_MULTI_ParameterFromEEPROMDirect  MSE_DA_MULTI_ParameterFromEEPROMDirect

// Sorting interface
#define EHAL_GLIB_SORT_Mid3                         SORT_Mid3
#define EHAL_GLIB_SORT_Mid5                         SORT_Mid5
#define EHAL_GLIB_SORT_Mid10                        SORT_Mid10

// Convert input param "addr", that contains address, to arithmetic pointer
#define EHAL_GLIB_ConvertToPtr_8bit                 ConvertToPtr_8bit
#define EHAL_GLIB_ConvertToPtr_S8bit                ConvertToPtr_S8bit
#define EHAL_GLIB_ConvertToPtr_16bit                ConvertToPtr_16bit
#define EHAL_GLIB_ConvertToPtr_S16bit               ConvertToPtr_S16bit
#define EHAL_GLIB_ConvertToPtr_32bit                ConvertToPtr_32bit
#define EHAL_GLIB_ConvertToPtr_S32bit               ConvertToPtr_S32bit

// VBSEC2 interface
#define EHAL_GLIB_VBSEC2_Init                       VBSEC2_Init
#define EHAL_GLIB_VBSEC2_CalcRequest                VBSEC2_CalcRequest
#define EHAL_GLIB_VBSEC2_DecoderResponse            VBSEC2_DecoderResponse
#define EHAL_GLIB_VBSEC2_CalcNewPassword            VBSEC2_CalcNewPassword
#define EHAL_GLIB_VBSEC2_RepeatRequest              VBSEC2_RepeatRequest
#define EHAL_GLIB_VBSEC2_CRC16                      VBSEC2_CRC16



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

// Immobilization system (MASTER part)
#define EHAL_IMMO_MSTR_Init                         IMMO_Init
#define EHAL_IMMO_MSTR_DeInit                       IMMO_DeInit
#define EHAL_IMMO_MSTR_StartKeyfobAuth              IMMO_StartKeyfobAuth
#define EHAL_IMMO_MSTR_GetKeyfobAuthStatus          IMMO_GetKeyfobAuthStatus
#define EHAL_IMMO_MSTR_SetKeyfobAuthEventHandler    IMMO_SetKeyfobAuthEventHandler
#define EHAL_IMMO_MSTR_StartImmoAuth                IMMO_StartImmoAuth
#define EHAL_IMMO_MSTR_GetImmoAuthStatus            IMMO_GetImmoAuthStatus
#define EHAL_IMMO_MSTR_SetImmoAuthEventHandler      IMMO_SetImmoAuthEventHandler
#define EHAL_IMMO_MSTR_SendMasterCommand            IMMO_SendMasterCommand
#define EHAL_IMMO_MSTR_GetSlaveResponse             IMMO_GetSlaveResponse
#define EHAL_IMMO_MSTR_GetDiagState                 IMMO_GetDiagState
#define EHAL_IMMO_MSTR_SetDiagState                 IMMO_SetDiagState
#define EHAL_IMMO_MSTR_GetKL15StateRequest          IMMO_GetKL15StateRequest
#define EHAL_IMMO_MSTR_GetLearnStatus               IMMO_GetLearnStatus
#define EHAL_IMMO_MSTR_HighLevel_ISR                IMMO_HighLevel_ISR

// Immobilization system (SLAVE part)
#define EHAL_IMMO_SLV_Init                          IMMO_Init
#define EHAL_IMMO_SLV_DeInit                        IMMO_DeInit
#define EHAL_IMMO_SLV_StartAuth                     IMMO_StartAuth
#define EHAL_IMMO_SLV_SendSlaveResponse             IMMO_SendSlaveResponse
#define EHAL_IMMO_SLV_GetMasterCommand              IMMO_GetMasterCommand
#define EHAL_IMMO_SLV_GetLearnStatus                IMMO_GetLearnStatus
#define EHAL_IMMO_SLV_GetDiagState                  IMMO_GetDiagState
#define EHAL_IMMO_SLV_SetDiagState                  IMMO_SetDiagState
#define EHAL_IMMO_SLV_HighLevel_ISR                 IMMO_HighLevel_ISR

// Randomizer
#define EHAL_Random_Init                            Random_Init
#define EHAL_Random_GetStatus                       Random_GetStatus
#define EHAL_Random_HighLevelISR                    Random_HighLevelISR

// Remote Control Unit service functions
#define EHAL_RCU_Init                               RCU_Init
#define EHAL_RCU_DeInit                             RCU_DeInit
#define EHAL_RCU_GetRequest                         RCU_GetRequest

// IC 12XS6
#define EHAL_IC_12XS6_SetChipState                  IC_12XS6_SetChipState
#define EHAL_IC_12XS6_GetChipState                  IC_12XS6_GetChipState

// ESCL service functions
#define EHAL_ESCL_Init                              ESCL_Init
#define EHAL_ESCL_DeInit                            ESCL_DeInit
#define EHAL_ESCL_SetCallback                       ESCL_SetCallback
#define EHAL_ESCL_SetSecretKey                      ESCL_SetSecretKey
#define EHAL_ESCL_SetPIN                            ESCL_SetPIN
#define EHAL_ESCL_GetStatus                         ESCL_GetStatus
#define EHAL_ESCL_UpdateStatus                      ESCL_UpdateStatus
#define EHAL_ESCL_Lock                              ESCL_Lock
#define EHAL_ESCL_Unlock                            ESCL_Unlock
#define EHAL_ESCL_ProgramSK                         ESCL_ProgramSK
#define EHAL_ESCL_ResetSK                           ESCL_ResetSK
#define EHAL_ESCL_EnterSession                      ESCL_EnterSession
#define EHAL_ESCL_GetDTC                            ESCL_GetDTC
#define EHAL_ESCL_UpdateDTC                         ESCL_UpdateDTC
#define EHAL_ESCL_GetInfo                           ESCL_GetInfo
#define EHAL_ESCL_UpdateInfo                        ESCL_UpdateInfo
#define EHAL_ESCL_HighLevel_RX_ISR                  ESCL_HighLevel_RX_ISR
#define EHAL_ESCL_HighLevel_TX_ISR                  ESCL_HighLevel_TX_ISR



#endif // #ifndef EHAL_H

//****************************************** end of file *******************************************
