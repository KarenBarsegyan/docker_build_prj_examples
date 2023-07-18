// *****************************************************************************
// @Module	ps_consts.h
// @Author	MSEpro Code Generator v.3.0.7145.22606 built at 25.07.2019 12:33:33
// @Description	Contains constants declarations
// *****************************************************************************

#ifndef __MSE_PS_CONSTS_H__
#define __MSE_PS_CONSTS_H__

#define	CONST_cNOK	0xFF	// U8 mU8 (1 [-])

#define	CONST_cOFF	0x00	// U8 mU8 (1 [-])

#define	CONST_cOK	0x00	// U8 mU8 (1 [-])

#define	CONST_cON	0x01	// U8 mU8 (1 [-])

#define	CONST_cFault	0x02	// U8 mBool2 (1 [-+fu])

#define	CONST_cNULL_POINTER	0x00000000	// U32 mAddress (1 [addr])

#define	CONST_cEHAL_POWMAN_PowerLevel_Full	0x00	// U8 mU8 (1 [-])

#define	CONST_cEHAL_POWMAN_PowerLevel_Sleep	0x04	// U8 mU8 (1 [-])

#define	CONST_cOS_UsedPIT_Number	0x00	// U8 mU8 (1 [-])

#define	CONST_cDiagSt_AboveNormal	0x0C	// U8 mDiagStatus (1 [])

#define	CONST_cDiagSt_BelowNormal	0x06	// U8 mDiagStatus (1 [])

#define	CONST_cDiagSt_Busy	0x07	// U8 mDiagStatus (1 [])

#define	CONST_cDiagSt_CauseUnknown	0x04	// U8 mDiagStatus (1 [])

#define	CONST_cDiagSt_ConfigError	0x0B	// U8 mDiagStatus (1 [])

#define	CONST_cDiagSt_InvalidRange	0x02	// U8 mDiagStatus (1 [])

#define	CONST_cDiagSt_NetDataErr	0x0E	// U8 mDiagStatus (1 [])

#define	CONST_cDiagSt_NotAvalable	0x01	// U8 mDiagStatus (1 [])

#define	CONST_cDiagSt_Ok	0x00	// U8 mDiagStatus (1 [])

#define	CONST_cDiagSt_OpenLoad	0x0A	// U8 mDiagStatus (1 [])

#define	CONST_cDiagSt_OutError	0x03	// U8 mDiagStatus (1 [])

#define	CONST_cDiagSt_Overload	0x0D	// U8 mDiagStatus (1 [])

#define	CONST_cDiagSt_ShortToHigh	0x09	// U8 mDiagStatus (1 [])

#define	CONST_cDiagSt_ShortToLow	0x08	// U8 mDiagStatus (1 [])

#define	CONST_cDiagSt_Timeout	0x05	// U8 mDiagStatus (1 [])

#define	CONST_cMEM_JOB_CALLBACK_LOAD	0x00	// U8 mU8 (1 [-])

#define	CONST_cMEM_JOB_CALLBACK_STORE	0x01	// U8 mU8 (1 [-])

#define	CONST_cMEM_JOB_RESULT_NOT_OK	0x01	// U8 mU8 (1 [-])

#define	CONST_cMEM_JOB_RESULT_OK	0x00	// U8 mU8 (1 [-])

#define	CONST_cMEM_JOB_RESULT_PENDING	0x02	// U8 mU8 (1 [-])

#define	CONST_cMEM_STATUS_ERASE_ERR_MASK	0x00000004	// U32 mU32 (1 [-])

#define	CONST_cMEM_STATUS_READ_ERR_MASK	0x00000001	// U32 mU32 (1 [-])

#define	CONST_cMEM_STATUS_WEAR_THRS_1_WARN_MASK	0x00000020	// U32 mU32 (1 [-])

#define	CONST_cMEM_STATUS_WEAR_THRS_2_ERR_MASK	0x00000040	// U32 mU32 (1 [-])

#define	CONST_cMEM_STATUS_WRITE_ERR_MASK	0x00000002	// U32 mU32 (1 [-])

#define	CONST_cISO14229_Session_Default	0x01	// U8 mU8 (1 [-])

#define	CONST_cISO14229_Session_ExtendedDiag	0x03	// U8 mU8 (1 [-])

#define	CONST_cISO14229_Session_Programming	0x02	// U8 mU8 (1 [-])

#define	CONST_cTrue	0x01	// U8 mBoolean (1 [boolean])

#define	CONST_cFalse	0x00	// U8 mBoolean (1 [boolean])

#define	CONST_cDIAG_NM_size	0x06	// U8 mU8 (1 [-])

#define	CONST_cCSWL_DIAG_MAX_STORED_FAULTS	0x0F	// U8 mU8 (1 [-])

#define	CONST_cISO14229_CDTCS_SF_ON	0x01	// U8 mU8 (1 [-])

#define	CONST_cTYP_ECUID	0x01	// U8 mBoolean (1 [boolean])

#define	CONST_cCSWL_EOL_ChCtrlSet_SetQty	0x04	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_ChCtrlSet_CmdMaxLng	0x32	// U8 mU8 (1 [-])

#define	CONST_cCSWL_DIAG_J1939_DM_max_length	0x003E	// U16 mU16 (1 [-])

#define	CONST_cTYP_DIAG	0x01	// U8 mU8 (1 [-])

#define	CONST_cTYP_EEPROM	0x01	// U8 mBoolean (1 [boolean])

#define	CONST_cTYP_EOL	0x00	// U8 mU8 (1 [-])

#define	CONST_cTYP_MonOS	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_AI_Qty	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_DI_Qty	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_FO_Qty	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_set_ChannelTypeDir	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_set_Length	0x02	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_set_ListType	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_ChNum_Size	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_RID_ACTKIT	0x04	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_RID_CFG	0x05	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_RID_CTRL	0x02	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_RID_DIAG	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_RID_READ	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_RID_SVKIT	0x03	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_RO_CFG_GET	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_RO_CFG_SET	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_RO_DIAG_CRR	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_RO_DIAG_DST	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_RO_READ_FST	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_RO_READ_RAW	0x00	// U8 mU8 (1 [-])

#define	CONST_cTYP_BTLDR	0x01	// U8 mBoolean (1 [boolean])

#define	CONST_cTYP_CANTRCV	0x00	// U8 mBoolean (1 [boolean])

#define	CONST_cTYP_MEMMAN	0x01	// U8 mBoolean (1 [boolean])

#define	CONST_cISO14229_CDTCS_SF_OFF	0x02	// U8 mU8 (1 [-])

#define	CONST_cEHAL_EEPROM_BufferSize	0x0FF4	// U16 mU16 (1 [-])

#define	CONST_cEHAL_EEPROM_BankID	0x03	// U8 mU8 (1 [-])

#define	CONST_cEHAL_EEPROM_BankOffset	0x0000	// U16 mU16 (1 [-])

#define	CONST_cJ1939_Rsp_Priority	0x06	// U8 mU8 (1 [-])

#define	CONST_cTYP_SyMM	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_SysMM_AppStopTime	0x000A	// U16 mTime1ms_U16 (1 [ms])

#define	CONST_cCSWL_CANMAN_Net_Qty	0x01	// U8 mU8 (1 [-])

#define	CONST_cTYP_J1939	0x00	// U8 mBoolean (1 [boolean])

#define	CONST_cEHAL_IOMGR_DiagSt__NoFailure	0x01	// U8 mU8 (1 [-])

#define	CONST_cDiagSt_NotExist	0x0F	// U8 mDiagStatus (1 [])

#define	CONST_cCSWL_EOL_RID_PWRDWN	0x0E	// U8 mU8 (1 [-])

#define	CONST_cCSWL_DO_Qty	0x01	// U8 mU8 (1 [-])

#define	CONST_cPolarity_VBAT	0x01	// U8 mPolarity (1 [off / VBAT / GND / both])

#define	CONST_cPolarity_GND	0x02	// U8 mPolarity (1 [off / VBAT / GND / both])

#define	CONST_cPolarity_OFF	0x00	// U8 mPolarity (1 [off / VBAT / GND / both])

#define	CONST_cCSWL_AO_Qty	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_FI_Qty	0x01	// U8 mU8 (1 [-])

#define	CONST_cJ1939_2bit_UNDEF	0x03	// U8 mU8 (1 [-])

#define	CONST_cSAEJ1939_ErrorIndicator_1byte	0xFE	// U8 mU8 (1 [-])

#define	CONST_cSAEJ1939_NotAvailable_1byte	0xFF	// U8 mU8 (1 [-])

#define	CONST_cSAEJ1939_ValidSignalMax_1byte	0xFA	// U8 mU8 (1 [-])

#define	CONST_cRequest_OFF	0x02	// U8 mRequest (1 [-/ON/OFF/SW])

#define	CONST_cRequest_ON	0x01	// U8 mRequest (1 [-/ON/OFF/SW])

#define	CONST_cRequest_Standby	0x00	// U8 mRequest (1 [-/ON/OFF/SW])

#define	CONST_cCSWL_CANMAN_RxMsg_Qty	0x1E	// U8 mU8 (1 [-])

#define	CONST_cCSWL_CANMAN_TxMsg_Qty	0x0F	// U8 mU8 (1 [-])

#define	CONST_cEHAL_CANdrv_TxBuffer_length	0x05	// U8 mU8 (1 [-])

#define	CONST_cCSWL_CANMAN_RTxMsg_Qty	0x01	// U8 mU8 (1 [-])

#define	CONST_cTYP_CS	0x01	// U8 mBoolean (1 [boolean])

#define	CONST_cEHAL_CS_MemoryBlock_Qty	0x03	// U8 mU8 (1 [-])

#define	CONST_cCANMAN_MsgBuffer_InitValue	0x00	// S8 mS8 (1 [])

#define	CONST_cTYP_CANMAN_TxDisp_OSlv	0x00	// U8 mU8 (1 [-])

#define	CONST_cTYP_CANMAN_RxDisp_OSlv	0x00	// U8 mU8 (1 [-])

#define	CONST_cTYP_CANMAN_TxBSW_OSlv	0x00	// U8 mU8 (1 [-])

#define	CONST_cTYP_CANMAN_RxBSW_OSlv	0x00	// U8 mU8 (1 [-])

#define	CONST_cTYP_AI	0x01	// U8 mU8 (1 [-])

#define	CONST_cTYP_AO	0x00	// U8 mU8 (1 [-])

#define	CONST_cTYP_DI	0x01	// U8 mU8 (1 [-])

#define	CONST_cTYP_DO	0x01	// U8 mU8 (1 [-])

#define	CONST_cTYP_EI	0x00	// U8 mU8 (1 [-])

#define	CONST_cTYP_FI	0x00	// U8 mU8 (1 [-])

#define	CONST_cTYP_FO	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EI_Qty	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_BRDC_IOMGRA_Qty	0x64	// U8 mU8 (1 [-])

#define	CONST_cCSWL_BRDC_IOMGRD_Qty	0x64	// U8 mU8 (1 [-])

#define	CONST_cPolarity_BOTH	0x03	// U8 mPolarity (1 [off / VBAT / GND / both])

#define	CONST_cCSWL_PWRI_Qty	0x01	// U8 mU8 (1 [-])

#define	CONST_cEHAL_Timers_Start_Idx	0x02	// U8 mU8 (1 [-])

#define	CONST_cEHAL_Timers_Total_Qty	0x46	// U8 mU8 (1 [-])

#define	CONST_cEHAL_OS_Timer_Period	0xFFFFFFFF	// U32 mU32 (1 [-])

#define	CONST_cEHAL_RTOS_TICK_TIMER_PERIOD_NS	0x000F4240	// U32 mTime1ns_U32 (1 [ns])

#define	CONST_cCSWL_BRDC_PCBT_Qty	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_BRDC_IOMGRP_Qty	0x01	// U8 mU8 (1 [-])

#define	CONST_cEHAL_RCU_RequestLength	0x04	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_RO_READ_SPC	0x02	// U8 mU8 (1 [-])

#define	CONST_cCSWL_BRDC_InnerD_Qty	0x01	// U8 mU8 (1 [-])

#define	CONST_cTYP_IOMGRA_SORT	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_AO_DAC_AdjustStepsQty	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_BRDC_InnerA_Qty	0x01	// U8 mU8 (1 [-])

#define	CONST_cDIAG_DS_size	0x09	// U8 mU8 (1 [-])

#define	CONST_cCANMAN_RxMsg_Faults_Qty	0x02	// U8 mU8 (1 [-])

#define	CONST_cTYP_LIN	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_UDS_RC_Qty	0x0A	// U8 mU8 (1 [-])

#define	CONST_cProcessSt_Success	0x03	// U8 mProcessStatus (1 [idle / pending / fail / success])

#define	CONST_cProcessSt_Fail	0x02	// U8 mProcessStatus (1 [idle / pending / fail / success])

#define	CONST_cProcessSt_Pending	0x01	// U8 mProcessStatus (1 [idle / pending / fail / success])

#define	CONST_cProcessSt_Idle	0x00	// U8 mProcessStatus (1 [idle / pending / fail / success])

#define	CONST_cCSWL_BRDC_IOMGRA_Sel_Qty	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_BRDC_IOMGRA_Selector_FirstNum	0xC8	// U8 mU8 (1 [-])

#define	CONST_cRequest_SW	0x03	// U8 mRequest (1 [-/ON/OFF/SW])

#define	CONST_cCSWL_EEPROM_mrk_BlackBox_reserv	0x01C0	// U16 mU16 (1 [-])

#define	CONST_cCSWL_EEPROM_mrk_DIAG_reserv	0x0200	// U16 mU16 (1 [-])

#define	CONST_cCSWL_EEPROM_mrk_Qty	0x0A	// U8 mU8 (1 [-])

#define	CONST_cCSWL_TestApp_Load_StepQty	0x3D	// U8 mU8 (1 [-])

#define	CONST_cU16_UNDEF	0xFFFF	// U16 mU16 (1 [-])

#define	CONST_cMSE_noData	0xFFFF	// U16 mMSE_Data_ID (1 [MSE_ID])

#define	CONST_cCSWL_UDS_RWC_Qty	0x14	// U8 mU8 (1 [-])

#define	CONST_cCANMAN_RxSig_IV_FF	0x01	// U8 mU8 (1 [-])

#define	CONST_cCANMAN_RxSig_IV_NotAvailable	0xFF	// U8 mU8 (1 [-])

#define	CONST_cCANMAN_RxSig_IV_Zero	0x00	// U8 mU8 (1 [-])

#define	CONST_cCANMAN_RxMsg_DiagByDM13	0x20	// U8 mU8 (1 [-])

#define	CONST_cCANMAN_RxMsg_DiagByT15	0x10	// U8 mU8 (1 [-])

#define	CONST_cCANMAN_RxMsg_SinceGet	0x04	// U8 mU8 (1 [-])

#define	CONST_cCANMAN_RxMsg_StopDiagTrig	0x40	// U8 mU8 (1 [-])

#define	CONST_cCANMAN_RxMsg_defaults	0x80	// U8 mU8 (1 [-])

#define	CONST_cCANMAN_RxMsg_ThisCycle	0x08	// U8 mU8 (1 [-])

#define	CONST_cCANMAN_RxMsg_ThisDiagStep	0x02	// U8 mU8 (1 [-])

#define	CONST_cCANMAN_RxMsg_ThisStep	0x01	// U8 mU8 (1 [-])

#define	CONST_cCANMAN_TxMsg_State_Ready	0x04	// U8 mU8 (1 [-])

#define	CONST_cCANMAN_TxMsg_State_Request	0x01	// U8 mU8 (1 [-])

#define	CONST_cCANMAN_TxMsg_State_Update	0x02	// U8 mU8 (1 [-])

#define	CONST_cJ1939_CANIDmask_PGN	0x03FFFF00	// U32 mU32 (1 [-])

#define	CONST_cJ1939_CANIDmask_Priority	0x1C000000	// U32 mU32 (1 [-])

#define	CONST_cJ1939_CANIDshift_PGN	0x08	// U8 mU8 (1 [-])

#define	CONST_cJ1939_CANIDshift_Priority	0x1A	// U8 mU8 (1 [-])

#define	CONST_cJ1939_21_AccessDenied	0x02	// U8 mU8 (1 [-])

#define	CONST_cJ1939_21_CannotRespond	0x03	// U8 mU8 (1 [-])

#define	CONST_cJ1939_21_NegativeACK	0x01	// U8 mU8 (1 [-])

#define	CONST_cJ1939_21_PositiveACK	0x00	// U8 mU8 (1 [-])

#define	CONST_cJ1939_73_Priority	0x06	// U8 mU8 (1 [-])

#define	CONST_cJ1939_MSG_READY	0xFF	// U8 mU8 (1 [-])

#define	CONST_cJ1939_1byteUNDEF	0xFF	// U8 mU8 (1 [-])

#define	CONST_cJ1939_BrcAddress	0xFF	// U8 mU8 (1 [-])

#define	CONST_cJ1939_21_Acknowledgment_PGN	0x0000E8FF	// U32 mU32 (1 [-])

#define	CONST_cJ1939_21_Request_PGN	0x0000EA00	// U32 mU32 (1 [-])

#define	CONST_cJ1939_21_PGNInitValue	0xFFFFFFFF	// U32 mU32 (1 [-])

#define	CONST_cJ1939_73_DM1_PGN	0x0000FECA	// U32 mU32 (1 [-])

#define	CONST_cJ1939_73_DM1_TxPeriod	0x03E8	// U16 mTime1ms_U16 (1 [ms])

#define	CONST_cJ1939_73_DM13_PGN	0x0000DFFF	// U32 mU32 (1 [-])

#define	CONST_cJ1939_73_DM13_priority	0x03	// U8 mU8 (1 [-])

#define	CONST_cJ1939_73_DM2_PGN	0x0000FECB	// U32 mU32 (1 [-])

#define	CONST_cJ1939_73_DM3_PGN	0x0000FECC	// U32 mU32 (1 [-])

#define	CONST_cJ1939_DM_priority	0x06	// U8 mU8 (1 [-])

#define	CONST_cUndef	0x03	// U8 mBool2 (1 [-+fu])

#define	CONST_cBRDC_AI_4modes__32V	0x01	// U8 mBRDC_AI_Mode (1 [])

#define	CONST_cBRDC_AI_4modes__5V	0x00	// U8 mBRDC_AI_Mode (1 [])

#define	CONST_cBRDC_AI_4modes__R500	0x03	// U8 mBRDC_AI_Mode (1 [])

#define	CONST_cBRDC_AI_4modes__R50K	0x02	// U8 mBRDC_AI_Mode (1 [])

#define	CONST_cBRDC_AI_InOut_modes__IN	0x00	// U8 mBRDC_AI_Mode (1 [])

#define	CONST_cBRDC_AI_InOut_modes__OUT	0x01	// U8 mBRDC_AI_Mode (1 [])

#define	CONST_cBRDC_AI_OnOff_modes__OFF	0x00	// U8 mBRDC_AI_Mode (1 [])

#define	CONST_cBRDC_AI_OnOff_modes__ON	0x01	// U8 mBRDC_AI_Mode (1 [])

#define	CONST_cBRDC_cfg_NA	0xFF	// U8 mU8 (1 [-])

#define	CONST_cBlackBox_syncTime	0x03E8	// U16 mTime1ms_U16 (1 [ms])

#define	CONST_cCSWL_EEPROM_mrk_SrvSize	0x02	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EEPROM_RecoverEventID	0x01	// U8 mU8 (1 [-])

#define	CONST_cEEPROM_RecoverTimeout	0x0003	// U16 mTime10ms_U16 (10 [ms])

#define	CONST_cCSWL_EEPROM_SaveEventID	0x02	// U8 mU8 (1 [-])

#define	CONST_cEEPROM_SaveTimeout	0x0064	// U16 mTime10ms_U16 (10 [ms])

#define	CONST_cCSWL_SyMM_State_Active	0x03	// U8 mU8 (1 [-])

#define	CONST_cCSWL_SyMM_State_DataLoad	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_SyMM_State_DataStore	0x05	// U8 mU8 (1 [-])

#define	CONST_cCSWL_SyMM_State_EOL	0x04	// U8 mU8 (1 [-])

#define	CONST_cCSWL_SyMM_State_Reset	0x07	// U8 mU8 (1 [-])

#define	CONST_cCSWL_SyMM_State_Sleep	0x06	// U8 mU8 (1 [-])

#define	CONST_cCSWL_SyMM_State_StartUp	0x02	// U8 mU8 (1 [-])

#define	CONST_cCSWL_UDS_IOC_Option__ControlBan	0x08	// U8 mU8 (1 [-])

#define	CONST_cCSWL_UDS_IOC_Option__ControlBanClear	0x04	// U8 mU8 (1 [-])

#define	CONST_cUDS_IOC_Option_FreezeCurrentState	0x02	// U8 mU8 (1 [-])

#define	CONST_cUDS_IOC_Option_ResetToDefault	0x01	// U8 mU8 (1 [-])

#define	CONST_cUDS_IOC_Option_ReturnControlToECU	0x00	// U8 mU8 (1 [-])

#define	CONST_cUDS_IOC_Option_ShortTermAdjust	0x03	// U8 mU8 (1 [-])

#define	CONST_cUDS_RWC_1DIDforCell	0x02	// U8 mUDS_RWC_method (1 [])

#define	CONST_cUDS_RWC_1DIDforList	0x10	// U8 mUDS_RWC_method (1 [])

#define	CONST_cUDS_RWC_1DIDforParam	0x01	// U8 mUDS_RWC_method (1 [])

#define	CONST_cUDS_RWC_1DIDforParamInList	0x11	// U8 mUDS_RWC_method (1 [])

#define	CONST_cUDS_NRC_CNC	0x22	// U8 mU8 (1 [-])

#define	CONST_cUDS_NRC_GR	0x10	// U8 mU8 (1 [-])

#define	CONST_cUDS_NRC_IMLOIF	0x13	// U8 mU8 (1 [-])

#define	CONST_cUDS_NRC_ROOR	0x31	// U8 mU8 (1 [-])

#define	CONST_cUDS_NRC_RSE	0x24	// U8 mU8 (1 [-])

#define	CONST_cUDS_NRC_RTL	0x14	// U8 mU8 (1 [-])

#define	CONST_cUDS_NRC_SAD	0x33	// U8 mU8 (1 [-])

#define	CONST_cUDS_NRC_SFNS	0x12	// U8 mU8 (1 [-])

#define	CONST_cUDS_NRC_SNS	0x11	// U8 mU8 (1 [-])

#define	CONST_cUDS_NRC_SNSIAS	0x7F	// U8 mU8 (1 [-])

#define	CONST_cUDS_PositiveResponse	0x00	// U8 mU8 (1 [-])

#define	CONST_cEHAL_CS_APPLICATION	0x01	// U8 mU8 (1 [-])

#define	CONST_cEHAL_CS_BOOTLOADER	0x00	// U8 mU8 (1 [-])

#define	CONST_cEHAL_CS_CALIBRATION	0x02	// U8 mU8 (1 [-])

#define	CONST_cEHAL_CS_CONFIGURATION	0x03	// U8 mU8 (1 [-])

#define	CONST_cU8_undef	0xFF	// U8 mU8 (1 [-])

#define	CONST_cTYP_TestApp	0x00	// U8 mU8 (1 [-])

#define	CONST_cSAEJ1939_ValidSignalMax_2byte	0xFAFF	// U16 mU16 (1 [-])

#define	CONST_cCSWL_DTCs_ASW_FaultsQty	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_AI_FaultsQty	0x04	// U8 mU8 (1 [-])

#define	CONST_cCSWL_BRDC_PWR_FaultsQty	0x02	// U8 mU8 (1 [-])

#define	CONST_cCSWL_AO_Faults_Overload	0x02	// U8 mU8 (1 [-])

#define	CONST_cCSWL_AO_Faults_Qty	0x03	// U8 mU8 (1 [-])

#define	CONST_cCSWL_AO_Faults_ShortGND	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_AO_Faults_ShortVBAT	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_AO_DAC_SupplyType_FullBattery	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_AO_DAC_SupplyType_HalfBattery	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_AO_DAC_TuneDir__Down	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_AO_DAC_TuneDir__Up	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_DO_Protect__Clear	0x40	// U8 mU8 (1 [-])

#define	CONST_cCSWL_DO_Protect__T15	0x20	// U8 mU8 (1 [-])

#define	CONST_cBRDC_PowerOut_Faults_Qty	0x04	// U8 mU8 (1 [-])

#define	CONST_cDIAG_NM_POS_BLINKhi	0x00	// U8 mU8 (1 [-])

#define	CONST_cDIAG_NM_POS_BLINKlow	0x01	// U8 mU8 (1 [-])

#define	CONST_cDIAG_NM_POS_ISO14229_DTChi	0x00	// U8 mU8 (1 [-])

#define	CONST_cDIAG_NM_POS_ISO14229_DTClow	0x01	// U8 mU8 (1 [-])

#define	CONST_cDIAG_NM_POS_ISO14229_Symp	0x02	// U8 mU8 (1 [-])

#define	CONST_cDIAG_NM_POS_SAEJ1939_FMI	0x02	// U8 mU8 (1 [-])

#define	CONST_cDIAG_NM_POS_SAEJ1939_SPNlow	0x00	// U8 mU8 (1 [-])

#define	CONST_cDIAG_NM_POS_SAEJ1939_SPNmid	0x01	// U8 mU8 (1 [-])

#define	CONST_cDTCst_confirmedDTC	0x08	// U8 mDTCstatus (1 [])

#define	CONST_cDTCst_pendingDTC	0x04	// U8 mDTCstatus (1 [])

#define	CONST_cDTCst_testFailed	0x01	// U8 mDTCstatus (1 [])

#define	CONST_cDTCst_testFailedSinceLastClear	0x20	// U8 mDTCstatus (1 [])

#define	CONST_cDTCst_testFailedThisOperationCycle	0x02	// U8 mDTCstatus (1 [])

#define	CONST_cDTCst_testNotCompletedSinceLastClear	0x10	// U8 mDTCstatus (1 [])

#define	CONST_cDTCst_testNotCompletedThisOperationCycle	0x40	// U8 mDTCstatus (1 [])

#define	CONST_cDTCst_warningIndicatorRequested	0x80	// U8 mDTCstatus (1 [])

#define	CONST_cMonResult_Fail	0x04	// U8 mMonResult (1 [])

#define	CONST_cMonResult_Pass	0x03	// U8 mMonResult (1 [])

#define	CONST_cMonResult_Prefail	0x02	// U8 mMonResult (1 [])

#define	CONST_cMonResult_Prepass	0x01	// U8 mMonResult (1 [])

#define	CONST_cMonResult_RestartOperation	0x06	// U8 mMonResult (1 [])

#define	CONST_cMonResult_Stop	0x05	// U8 mMonResult (1 [])

#define	CONST_cMonResult_undef	0x00	// U8 mMonResult (1 [])

#define	CONST_cDIAG_Object_AllFaults	0xFF	// U8 mU8 (1 [-])

#define	CONST_cDIAG_DTCformat_ISO_11992_4	0x03	// U8 mU8 (1 [-])

#define	CONST_cDIAG_DTCformat_ISO_14229_1	0x01	// U8 mU8 (1 [-])

#define	CONST_cDIAG_DTCformat_SAE_J1939_73	0x02	// U8 mU8 (1 [-])

#define	CONST_cDIAG_DTCformat_SAE_J2012_DA00	0x00	// U8 mU8 (1 [-])

#define	CONST_cDIAG_DTCformat_SAE_J2012_DA04	0x04	// U8 mU8 (1 [-])

#define	CONST_cCSWL_DIAG_MAX_MONITOR_SWC	0x14	// U8 mU8 (1 [-])

#define	CONST_cCSWL_MonOS_SeqID_CSW10	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_MonOS_SeqID_CSW100	0x01	// U8 mU8 (1 [-])

#define	CONST_cEHAL_OS_Time_Scale_Channel_Idx	0x44	// U8 mU8 (1 [-])

#define	CONST_cCSWL_MonOS_Levels_Qty	0x08	// U8 mU8 (1 [-])

#define	CONST_cCSWL_MonOS_Sequence_Qty	0x03	// U8 mU8 (1 [-])

#define	CONST_cmMonOS_Gen_ConfigCS	0x20	// U8 mDIAG_ObjectPack (1 [])

#define	CONST_cmMonOS_Gen_EEPROM	0x02	// U8 mDIAG_ObjectPack (1 [])

#define	CONST_cmCSWL_MonOS_Gen_IdleStuck	0x10	// U8 mDIAG_ObjectPack (1 [])

#define	CONST_cmMonOS_Gen_Reset_byMarker	0x04	// U8 mDIAG_ObjectPack (1 [])

#define	CONST_cmCSWL_MonOS_Gen_Reset_byReason	0x08	// U8 mDIAG_ObjectPack (1 [])

#define	CONST_cmMonOS_Gen_ROM	0x01	// U8 mDIAG_ObjectPack (1 [])

#define	CONST_cmCSWL_MonOS_Lv_Commission	0x02	// U8 mDIAG_ObjectPack (1 [])

#define	CONST_cmCSWL_MonOS_Lv_Entry	0x08	// U8 mDIAG_ObjectPack (1 [])

#define	CONST_cmCSWL_MonOS_Lv_Exit	0x10	// U8 mDIAG_ObjectPack (1 [])

#define	CONST_cmCSWL_MonOS_Lv_Omission	0x04	// U8 mDIAG_ObjectPack (1 [])

#define	CONST_cmCSWL_MonOS_Lv_Stuck	0x20	// U8 mDIAG_ObjectPack (1 [])

#define	CONST_cmCSWL_MonOS_Lv_Timing	0x01	// U8 mDIAG_ObjectPack (1 [])

#define	CONST_cmCSWL_MonOS_Seq_Restart	0x02	// U8 mDIAG_ObjectPack (1 [])

#define	CONST_cmCSWL_MonOS_Seq_Violation	0x01	// U8 mDIAG_ObjectPack (1 [])

#define	CONST_cUDS_NRC_SFNSIAS	0x7E	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EEPROM_mrk_ASWBlackBox_reserv	0x0064	// U16 mU16 (1 [-])

#define	CONST_cTYP_FPS	0x01	// U8 mBoolean (1 [boolean])

#define	CONST_cmUDS_RWC_prm_ReadSession	0x03	// U8 mUDS_RWC_permissions (1 [])

#define	CONST_cmUDS_RWC_prm_ControlSession	0x0C	// U8 mUDS_RWC_permissions (1 [])

#define	CONST_cmUDS_RWC_prm_Secure	0xC0	// U8 mUDS_RWC_permissions (1 [])

#define	CONST_cCSWL_ECUID_DID_Test_DID	0xFD30	// U16 mU16 (1 [-])

#define	CONST_cTYP_ResetCause	0x01	// U8 mBoolean (1 [boolean])

#define	CONST_cCSWL_CANMAN_RxBSW_period	0x000A	// U16 mTime1ms_U16 (1 [ms])

#define	CONST_cCSWL_CANMAN_RxDisp_period	0x000A	// U16 mTime1ms_U16 (1 [ms])

#define	CONST_cCSWL_CANMAN_TxDisp_period	0x000A	// U16 mTime1ms_U16 (1 [ms])

#define	CONST_cCSWL_CANMAN_TxBSW_period	0x000A	// U16 mTime1ms_U16 (1 [ms])

#define	CONST_cWorkMode_Sleep	0x00	// U8 mWorkMode (1 [WorkMode enum])

#define	CONST_cWorkMode_Silent	0x01	// U8 mWorkMode (1 [WorkMode enum])

#define	CONST_cWorkMode_Active	0x02	// U8 mWorkMode (1 [WorkMode enum])

#define	CONST_cOS_1msLevel_ID	0x02	// U8 mU8 (1 [-])

#define	CONST_c_MonUnit_Type	0x01	// U8 mU8 (1 [-])

#define	CONST_cRTOS_FastestLevelPeriod	0x000F4240	// U32 mTime1ns_U32 (1 [ns])

#define	CONST_cTYP_Processor	0x01	// U8 mU8 (1 [-])

#define	CONST_cTYP_POWMAN	0x00	// U8 mBoolean (1 [boolean])

#define	CONST_cCSWL_SyMM_FakeWakeUp_Qty	0x01	// U8 mU8 (1 [-])

#define	CONST_cUDS_RWC_1DIDforParamInList_fromArray	0x21	// U8 mUDS_RWC_method (1 [])

#define	CONST_cTYP_MSEDA	0x01	// U8 mU8 (1 [-])

#define	CONST_cEHAL_IOMGR_DiagSt__Undef	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_IMPL_RF_Qty	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_IMPL_PRCD_Qty	0x01	// U8 mU8 (1 [-])

#define	CONST_cTYP_J1939_21	0x00	// U8 mBoolean (1 [boolean])

#define	CONST_cTYP_CANMAN	0x00	// U8 mBoolean (1 [boolean])

#define	CONST_cTYP_CANdrv	0x00	// U8 mBoolean (1 [boolean])

#define	CONST_cUDS_resetType_keyOffOnReset	0x02	// U8 mU8 (1 [-])

#define	CONST_cUDS_resetType_hardReset	0x01	// U8 mU8 (1 [-])

#define	CONST_cUDS_resetType_softReset	0x03	// U8 mU8 (1 [-])

#define	CONST_cUDS_resetType_enableRapidPowerShutDown	0x04	// U8 mU8 (1 [-])

#define	CONST_cUDS_resetType_disableRapidPowerShutDown	0x05	// U8 mU8 (1 [-])

#define	CONST_cWorkMode_undef	0x03	// U8 mWorkMode (1 [WorkMode enum])

#define	CONST_cUDS_controlType_enableRxAndTx	0x00	// U8 mU8 (1 [-])

#define	CONST_cUDS_controlType_enableRxAndDisableTx	0x01	// U8 mU8 (1 [-])

#define	CONST_cUDS_communicationType_normalCommunicationMessages_AllNetworks	0x01	// U8 mU8 (1 [-])

#define	CONST_cmUDS_RWC_prm_RoutineA	0x10	// U8 mUDS_RWC_permissions (1 [])

#define	CONST_cTYP_BRDC	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_TestApp_Load_SF_Qty	0x01	// U8 mU8 (1 [-])

#define	CONST_cmUDS_Cnd_0x81_rpmTooHigh	0x00000002	// U32 mUDS_Conditions (1 [])

#define	CONST_cmUDS_Cnd_0x22_conditionsNotCorrect	0x00000001	// U32 mUDS_Conditions (1 [])

#define	CONST_cmUDS_Cnd_0x82_rpmTooLow	0x00000004	// U32 mUDS_Conditions (1 [])

#define	CONST_cmUDS_Cnd_0x83_engineIsRunning	0x00000008	// U32 mUDS_Conditions (1 [])

#define	CONST_cmUDS_Cnd_0x84_engineIsNotRunning	0x00000010	// U32 mUDS_Conditions (1 [])

#define	CONST_cmUDS_Cnd_0x85_engineRunTimeTooLow	0x00000020	// U32 mUDS_Conditions (1 [])

#define	CONST_cmUDS_Cnd_0x86_temperatureTooHigh	0x00000040	// U32 mUDS_Conditions (1 [])

#define	CONST_cmUDS_Cnd_0x87_temperatureTooLow	0x00000080	// U32 mUDS_Conditions (1 [])

#define	CONST_cmUDS_Cnd_0x88_vehicleSpeedTooHigh	0x00000100	// U32 mUDS_Conditions (1 [])

#define	CONST_cmUDS_Cnd_0x89_vehicleSpeedTooLow	0x00000200	// U32 mUDS_Conditions (1 [])

#define	CONST_cmUDS_Cnd_0x8A_throttlePedalTooHigh	0x00000400	// U32 mUDS_Conditions (1 [])

#define	CONST_cmUDS_Cnd_0x8B_throttlePedalTooLow	0x00000800	// U32 mUDS_Conditions (1 [])

#define	CONST_cmUDS_Cnd_0x8C_transmissionRangeNotInNeutral	0x00001000	// U32 mUDS_Conditions (1 [])

#define	CONST_cmUDS_Cnd_0x8D_transmissionRangeNotInGear	0x00002000	// U32 mUDS_Conditions (1 [])

#define	CONST_cmUDS_Cnd_0x8F_brakeSwitchNotClosed	0x00008000	// U32 mUDS_Conditions (1 [])

#define	CONST_cmUDS_Cnd_0x90_shifterLeverNotInPark	0x00010000	// U32 mUDS_Conditions (1 [])

#define	CONST_cmUDS_Cnd_0x91_torqueConverterClutchLocked	0x00020000	// U32 mUDS_Conditions (1 [])

#define	CONST_cmUDS_Cnd_0x92_voltageTooHigh	0x00040000	// U32 mUDS_Conditions (1 [])

#define	CONST_cmUDS_Cnd_0x93_voltageTooLow	0x00080000	// U32 mUDS_Conditions (1 [])

#define	CONST_cUDS_NRC_BRR	0x21	// U8 mU8 (1 [-])

#define	CONST_cUDS_NRC_RCRRP	0x78	// U8 mU8 (1 [-])

#define	CONST_cUDS_SID_RDBI	0x22	// U8 mU8 (1 [-])

#define	CONST_cUDS_SID_WDBI	0x2E	// U8 mU8 (1 [-])

#define	CONST_cTYP_UDS	0x01	// U8 mU8 (1 [-])

#define	CONST_cIC_12XS6_DEVID_RegN	0x0E	// U8 mU8 (1 [-])

#define	CONST_cIC_12XS6_MC08XS6421	0x42	// U8 mU8 (1 [-])

#define	CONST_cIC_12XS6_MC10XS6200	0x46	// U8 mU8 (1 [-])

#define	CONST_cIC_12XS6_MC10XS6325	0x44	// U8 mU8 (1 [-])

#define	CONST_cIC_12XS6_MC17XS6400	0x43	// U8 mU8 (1 [-])

#define	CONST_cIC_12XS6_MC17XS6500	0x41	// U8 mU8 (1 [-])

#define	CONST_cTYP_12XS6_SW_configuration	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_IC_12XS6_ChipType_DID	0xFD38	// U16 mU16 (1 [-])

#define	CONST_cUDS_SuppressResponse	0xFF	// U8 mU8 (1 [-])

#define	CONST_cTYP_UDS_AsyncResponse	0x00	// U8 mBoolean (1 [boolean])

#define	CONST_cCSWL_DO_Forbidden_By_PWRI	0x10	// U8 mU8 (1 [-])

#define	CONST_cCSWL_DO_Protect__ReplaceECU	0x80	// U8 mU8 (1 [-])

#define	CONST_cmMonOS_Gen_BRDC_Shorts	0x40	// U8 mDIAG_ObjectPack (1 [])

#define	CONST_cCSWL_UDS_ECUID_VMCF_Qty	0x06	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EEPROM_filler	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EEPROM_mrk_ECUID_reserv	0x0040	// U16 mU16 (1 [-])

#define	CONST_cTYP_UDS_OBD	0x00	// U8 mU8 (1 [-])

#define	CONST_cEHAL_ISO14229_BufferSize	0x00FA	// U16 mU16 (1 [-])

#define	CONST_cCSWL_FI_TMR_Idx	0x44	// U8 mU8 (1 [-])

#define	CONST_cCSWL_FI_bit_IOMGRP	0x02	// U8 mU8 (1 [-])

#define	CONST_cCSWL_FI_bit_TMR	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_FI_bit_1ms	0x04	// U8 mU8 (1 [-])

#define	CONST_cTYP_IOMGRA_SEL	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_CANMAN_TxEventByListSettings	0x00	// U8 mU8 (1 [-])

#define	CONST_cTYP_ISO14229_RDTC	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_UDS_IOC_OptionMask	0x000F	// U16 mU16 (1 [-])

#define	CONST_cTYP_KNK	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_EOL_PRCD_KNK_Idx	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_ISO17356_CtrlField_Offset	0x01	// U8 mU8 (1 [-])

#define	CONST_cCSWL_ISO17356_DA_Offset	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_ISO17356_NM_Msg_Size	0x08	// U8 mU8 (1 [-])

#define	CONST_cmCSWL_ISO17356_Alive	0x01	// U8 mU8 (1 [-])

#define	CONST_cmCSWL_ISO17356_Limphome	0x04	// U8 mU8 (1 [-])

#define	CONST_cmCSWL_ISO17356_Ring	0x02	// U8 mU8 (1 [-])

#define	CONST_cmCSWL_ISO17356_SleepAck	0x20	// U8 mU8 (1 [-])

#define	CONST_cmCSWL_ISO17356_SleepInd	0x10	// U8 mU8 (1 [-])

#define	CONST_cISO17356_NM_Mode_Active	0x03	// U8 mU8 (1 [-])

#define	CONST_cISO17356_NM_Mode_Init	0x01	// U8 mU8 (1 [-])

#define	CONST_cISO17356_NM_Mode_Limphome	0x05	// U8 mU8 (1 [-])

#define	CONST_cISO17356_NM_Mode_Reset	0x02	// U8 mU8 (1 [-])

#define	CONST_cISO17356_NM_Mode_Silent	0x04	// U8 mU8 (1 [-])

#define	CONST_cCSWL_ISO17356_SyncPeriod	0x000A	// U16 mTime1ms_U16 (1 [ms])

#define	CONST_cCSWL_ISO17356_ECU_MaxQty	0x01	// U8 mU8 (1 [-])

#define	CONST_cTYP_ISO17356	0x00	// U8 mBoolean (1 [boolean])

#define	CONST_cEHAL_GLIB_CRC32_AreasQuantity	0x0001	// U16 mU16 (1 [-])

#define	CONST_cTYP_IOMGRD_ShiftReg	0x00	// U8 mU8 (1 [-])

#define	CONST_cBRDC_ShiftReg_FirstIOMGRnum	0xC8	// U8 mU8 (1 [-])

#define	CONST_cTYP_IOMGR_DBG	0x01	// U8 mBoolean (1 [boolean])

#define	CONST_cTYP_DO_MON_CURRENT	0x01	// U8 mU8 (1 [-])

#define	CONST_cTYP_DO_MON_READBACK	0x01	// U8 mU8 (1 [-])

#define	CONST_cTYP_DO_MON_DRV	0x01	// U8 mU8 (1 [-])

#define	CONST_cTYP_DO_MON_REPORT	0x01	// U8 mU8 (1 [-])

#define	CONST_cTYP_FO_MON_REPORT	0x00	// U8 mU8 (1 [-])

#define	CONST_cTYP_FO_MON_DRV	0x00	// U8 mU8 (1 [-])

#define	CONST_cTYP_FO_MON_READBACK	0x00	// U8 mU8 (1 [-])

#define	CONST_cTYP_FO_MON_CURRENT	0x00	// U8 mU8 (1 [-])

#define	CONST_cTYP_UDS_WDBI	0x01	// U8 mU8 (1 [-])

#define	CONST_cTYP_UDS_IOC	0x01	// U8 mU8 (1 [-])

#define	CONST_cTYP_UDS_RC	0x01	// U8 mU8 (1 [-])

#define	CONST_cTYP_UDS_VMEOL	0x00	// U8 mU8 (1 [-])

#define	CONST_cTYP_UDS__ER_CC	0x00	// U8 mU8 (1 [-])

#define	CONST_cCSWL_ECUID_VIN_DID	0xF190	// U16 mU16 (1 [-])

#define	CONST_cSL3_FaultsQty	0x0A	// U8 mU8 (1 [-])

#endif // __MSE_PS_CONSTS_H__
