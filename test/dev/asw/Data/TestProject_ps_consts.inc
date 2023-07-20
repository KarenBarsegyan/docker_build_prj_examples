; *****************************************************************************
; @Module	ps_consts.inc
; @Author	MSEpro Code Generator v.3.0.7145.22606 built at 25.07.2019 12:33:33
; @Description	Contains constants declarations
; *****************************************************************************

CONST_cNOK	.equ	FFh	; U8 mU8 (1 [-])

CONST_cOFF	.equ	00h	; U8 mU8 (1 [-])

CONST_cOK	.equ	00h	; U8 mU8 (1 [-])

CONST_cON	.equ	01h	; U8 mU8 (1 [-])

CONST_cFault	.equ	02h	; U8 mBool2 (1 [-+fu])

CONST_cNULL_POINTER	.equ	00000000h	; U32 mAddress (1 [addr])

CONST_cEHAL_POWMAN_PowerLevel_Full	.equ	00h	; U8 mU8 (1 [-])

CONST_cEHAL_POWMAN_PowerLevel_Sleep	.equ	04h	; U8 mU8 (1 [-])

CONST_cOS_UsedPIT_Number	.equ	00h	; U8 mU8 (1 [-])

CONST_cDiagSt_AboveNormal	.equ	0Ch	; U8 mDiagStatus (1 [])

CONST_cDiagSt_BelowNormal	.equ	06h	; U8 mDiagStatus (1 [])

CONST_cDiagSt_Busy	.equ	07h	; U8 mDiagStatus (1 [])

CONST_cDiagSt_CauseUnknown	.equ	04h	; U8 mDiagStatus (1 [])

CONST_cDiagSt_ConfigError	.equ	0Bh	; U8 mDiagStatus (1 [])

CONST_cDiagSt_InvalidRange	.equ	02h	; U8 mDiagStatus (1 [])

CONST_cDiagSt_NetDataErr	.equ	0Eh	; U8 mDiagStatus (1 [])

CONST_cDiagSt_NotAvalable	.equ	01h	; U8 mDiagStatus (1 [])

CONST_cDiagSt_Ok	.equ	00h	; U8 mDiagStatus (1 [])

CONST_cDiagSt_OpenLoad	.equ	0Ah	; U8 mDiagStatus (1 [])

CONST_cDiagSt_OutError	.equ	03h	; U8 mDiagStatus (1 [])

CONST_cDiagSt_Overload	.equ	0Dh	; U8 mDiagStatus (1 [])

CONST_cDiagSt_ShortToHigh	.equ	09h	; U8 mDiagStatus (1 [])

CONST_cDiagSt_ShortToLow	.equ	08h	; U8 mDiagStatus (1 [])

CONST_cDiagSt_Timeout	.equ	05h	; U8 mDiagStatus (1 [])

CONST_cMEM_JOB_CALLBACK_LOAD	.equ	00h	; U8 mU8 (1 [-])

CONST_cMEM_JOB_CALLBACK_STORE	.equ	01h	; U8 mU8 (1 [-])

CONST_cMEM_JOB_RESULT_NOT_OK	.equ	01h	; U8 mU8 (1 [-])

CONST_cMEM_JOB_RESULT_OK	.equ	00h	; U8 mU8 (1 [-])

CONST_cMEM_JOB_RESULT_PENDING	.equ	02h	; U8 mU8 (1 [-])

CONST_cMEM_STATUS_ERASE_ERR_MASK	.equ	00000004h	; U32 mU32 (1 [-])

CONST_cMEM_STATUS_READ_ERR_MASK	.equ	00000001h	; U32 mU32 (1 [-])

CONST_cMEM_STATUS_WEAR_THRS_1_WARN_MASK	.equ	00000020h	; U32 mU32 (1 [-])

CONST_cMEM_STATUS_WEAR_THRS_2_ERR_MASK	.equ	00000040h	; U32 mU32 (1 [-])

CONST_cMEM_STATUS_WRITE_ERR_MASK	.equ	00000002h	; U32 mU32 (1 [-])

CONST_cISO14229_Session_Default	.equ	01h	; U8 mU8 (1 [-])

CONST_cISO14229_Session_ExtendedDiag	.equ	03h	; U8 mU8 (1 [-])

CONST_cISO14229_Session_Programming	.equ	02h	; U8 mU8 (1 [-])

CONST_cTrue	.equ	01h	; U8 mBoolean (1 [boolean])

CONST_cFalse	.equ	00h	; U8 mBoolean (1 [boolean])

CONST_cDIAG_NM_size	.equ	06h	; U8 mU8 (1 [-])

CONST_cCSWL_DIAG_MAX_STORED_FAULTS	.equ	0Fh	; U8 mU8 (1 [-])

CONST_cISO14229_CDTCS_SF_ON	.equ	01h	; U8 mU8 (1 [-])

CONST_cTYP_ECUID	.equ	01h	; U8 mBoolean (1 [boolean])

CONST_cCSWL_EOL_ChCtrlSet_SetQty	.equ	04h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_ChCtrlSet_CmdMaxLng	.equ	32h	; U8 mU8 (1 [-])

CONST_cCSWL_DIAG_J1939_DM_max_length	.equ	003Eh	; U16 mU16 (1 [-])

CONST_cTYP_DIAG	.equ	01h	; U8 mU8 (1 [-])

CONST_cTYP_EEPROM	.equ	01h	; U8 mBoolean (1 [boolean])

CONST_cTYP_EOL	.equ	00h	; U8 mU8 (1 [-])

CONST_cTYP_MonOS	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_AI_Qty	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_DI_Qty	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_FO_Qty	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_set_ChannelTypeDir	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_set_Length	.equ	02h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_set_ListType	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_ChNum_Size	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_RID_ACTKIT	.equ	04h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_RID_CFG	.equ	05h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_RID_CTRL	.equ	02h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_RID_DIAG	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_RID_READ	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_RID_SVKIT	.equ	03h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_RO_CFG_GET	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_RO_CFG_SET	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_RO_DIAG_CRR	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_RO_DIAG_DST	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_RO_READ_FST	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_RO_READ_RAW	.equ	00h	; U8 mU8 (1 [-])

CONST_cTYP_BTLDR	.equ	01h	; U8 mBoolean (1 [boolean])

CONST_cTYP_CANTRCV	.equ	00h	; U8 mBoolean (1 [boolean])

CONST_cTYP_MEMMAN	.equ	01h	; U8 mBoolean (1 [boolean])

CONST_cISO14229_CDTCS_SF_OFF	.equ	02h	; U8 mU8 (1 [-])

CONST_cEHAL_EEPROM_BufferSize	.equ	0FF4h	; U16 mU16 (1 [-])

CONST_cEHAL_EEPROM_BankID	.equ	03h	; U8 mU8 (1 [-])

CONST_cEHAL_EEPROM_BankOffset	.equ	0000h	; U16 mU16 (1 [-])

CONST_cJ1939_Rsp_Priority	.equ	06h	; U8 mU8 (1 [-])

CONST_cTYP_SyMM	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_SysMM_AppStopTime	.equ	000Ah	; U16 mTime1ms_U16 (1 [ms])

CONST_cCSWL_CANMAN_Net_Qty	.equ	01h	; U8 mU8 (1 [-])

CONST_cTYP_J1939	.equ	00h	; U8 mBoolean (1 [boolean])

CONST_cEHAL_IOMGR_DiagSt__NoFailure	.equ	01h	; U8 mU8 (1 [-])

CONST_cDiagSt_NotExist	.equ	0Fh	; U8 mDiagStatus (1 [])

CONST_cCSWL_EOL_RID_PWRDWN	.equ	0Eh	; U8 mU8 (1 [-])

CONST_cCSWL_DO_Qty	.equ	01h	; U8 mU8 (1 [-])

CONST_cPolarity_VBAT	.equ	01h	; U8 mPolarity (1 [off / VBAT / GND / both])

CONST_cPolarity_GND	.equ	02h	; U8 mPolarity (1 [off / VBAT / GND / both])

CONST_cPolarity_OFF	.equ	00h	; U8 mPolarity (1 [off / VBAT / GND / both])

CONST_cCSWL_AO_Qty	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_FI_Qty	.equ	01h	; U8 mU8 (1 [-])

CONST_cJ1939_2bit_UNDEF	.equ	03h	; U8 mU8 (1 [-])

CONST_cSAEJ1939_ErrorIndicator_1byte	.equ	FEh	; U8 mU8 (1 [-])

CONST_cSAEJ1939_NotAvailable_1byte	.equ	FFh	; U8 mU8 (1 [-])

CONST_cSAEJ1939_ValidSignalMax_1byte	.equ	FAh	; U8 mU8 (1 [-])

CONST_cRequest_OFF	.equ	02h	; U8 mRequest (1 [-/ON/OFF/SW])

CONST_cRequest_ON	.equ	01h	; U8 mRequest (1 [-/ON/OFF/SW])

CONST_cRequest_Standby	.equ	00h	; U8 mRequest (1 [-/ON/OFF/SW])

CONST_cCSWL_CANMAN_RxMsg_Qty	.equ	1Eh	; U8 mU8 (1 [-])

CONST_cCSWL_CANMAN_TxMsg_Qty	.equ	0Fh	; U8 mU8 (1 [-])

CONST_cEHAL_CANdrv_TxBuffer_length	.equ	05h	; U8 mU8 (1 [-])

CONST_cCSWL_CANMAN_RTxMsg_Qty	.equ	01h	; U8 mU8 (1 [-])

CONST_cTYP_CS	.equ	01h	; U8 mBoolean (1 [boolean])

CONST_cEHAL_CS_MemoryBlock_Qty	.equ	03h	; U8 mU8 (1 [-])

CONST_cCANMAN_MsgBuffer_InitValue	.equ	00h	; S8 mS8 (1 [])

CONST_cTYP_CANMAN_TxDisp_OSlv	.equ	00h	; U8 mU8 (1 [-])

CONST_cTYP_CANMAN_RxDisp_OSlv	.equ	00h	; U8 mU8 (1 [-])

CONST_cTYP_CANMAN_TxBSW_OSlv	.equ	00h	; U8 mU8 (1 [-])

CONST_cTYP_CANMAN_RxBSW_OSlv	.equ	00h	; U8 mU8 (1 [-])

CONST_cTYP_AI	.equ	01h	; U8 mU8 (1 [-])

CONST_cTYP_AO	.equ	00h	; U8 mU8 (1 [-])

CONST_cTYP_DI	.equ	01h	; U8 mU8 (1 [-])

CONST_cTYP_DO	.equ	01h	; U8 mU8 (1 [-])

CONST_cTYP_EI	.equ	00h	; U8 mU8 (1 [-])

CONST_cTYP_FI	.equ	00h	; U8 mU8 (1 [-])

CONST_cTYP_FO	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_EI_Qty	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_BRDC_IOMGRA_Qty	.equ	64h	; U8 mU8 (1 [-])

CONST_cCSWL_BRDC_IOMGRD_Qty	.equ	64h	; U8 mU8 (1 [-])

CONST_cPolarity_BOTH	.equ	03h	; U8 mPolarity (1 [off / VBAT / GND / both])

CONST_cCSWL_PWRI_Qty	.equ	01h	; U8 mU8 (1 [-])

CONST_cEHAL_Timers_Start_Idx	.equ	02h	; U8 mU8 (1 [-])

CONST_cEHAL_Timers_Total_Qty	.equ	46h	; U8 mU8 (1 [-])

CONST_cEHAL_OS_Timer_Period	.equ	FFFFFFFFh	; U32 mU32 (1 [-])

CONST_cEHAL_RTOS_TICK_TIMER_PERIOD_NS	.equ	000F4240h	; U32 mTime1ns_U32 (1 [ns])

CONST_cCSWL_BRDC_PCBT_Qty	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_BRDC_IOMGRP_Qty	.equ	01h	; U8 mU8 (1 [-])

CONST_cEHAL_RCU_RequestLength	.equ	04h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_RO_READ_SPC	.equ	02h	; U8 mU8 (1 [-])

CONST_cCSWL_BRDC_InnerD_Qty	.equ	01h	; U8 mU8 (1 [-])

CONST_cTYP_IOMGRA_SORT	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_AO_DAC_AdjustStepsQty	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_BRDC_InnerA_Qty	.equ	01h	; U8 mU8 (1 [-])

CONST_cDIAG_DS_size	.equ	09h	; U8 mU8 (1 [-])

CONST_cCANMAN_RxMsg_Faults_Qty	.equ	02h	; U8 mU8 (1 [-])

CONST_cTYP_LIN	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_UDS_RC_Qty	.equ	0Ah	; U8 mU8 (1 [-])

CONST_cProcessSt_Success	.equ	03h	; U8 mProcessStatus (1 [idle / pending / fail / success])

CONST_cProcessSt_Fail	.equ	02h	; U8 mProcessStatus (1 [idle / pending / fail / success])

CONST_cProcessSt_Pending	.equ	01h	; U8 mProcessStatus (1 [idle / pending / fail / success])

CONST_cProcessSt_Idle	.equ	00h	; U8 mProcessStatus (1 [idle / pending / fail / success])

CONST_cCSWL_BRDC_IOMGRA_Sel_Qty	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_BRDC_IOMGRA_Selector_FirstNum	.equ	C8h	; U8 mU8 (1 [-])

CONST_cRequest_SW	.equ	03h	; U8 mRequest (1 [-/ON/OFF/SW])

CONST_cCSWL_EEPROM_mrk_BlackBox_reserv	.equ	01C0h	; U16 mU16 (1 [-])

CONST_cCSWL_EEPROM_mrk_DIAG_reserv	.equ	0200h	; U16 mU16 (1 [-])

CONST_cCSWL_EEPROM_mrk_Qty	.equ	0Ah	; U8 mU8 (1 [-])

CONST_cCSWL_TestApp_Load_StepQty	.equ	3Dh	; U8 mU8 (1 [-])

CONST_cU16_UNDEF	.equ	FFFFh	; U16 mU16 (1 [-])

CONST_cMSE_noData	.equ	FFFFh	; U16 mMSE_Data_ID (1 [MSE_ID])

CONST_cCSWL_UDS_RWC_Qty	.equ	14h	; U8 mU8 (1 [-])

CONST_cCANMAN_RxSig_IV_FF	.equ	01h	; U8 mU8 (1 [-])

CONST_cCANMAN_RxSig_IV_NotAvailable	.equ	FFh	; U8 mU8 (1 [-])

CONST_cCANMAN_RxSig_IV_Zero	.equ	00h	; U8 mU8 (1 [-])

CONST_cCANMAN_RxMsg_DiagByDM13	.equ	20h	; U8 mU8 (1 [-])

CONST_cCANMAN_RxMsg_DiagByT15	.equ	10h	; U8 mU8 (1 [-])

CONST_cCANMAN_RxMsg_SinceGet	.equ	04h	; U8 mU8 (1 [-])

CONST_cCANMAN_RxMsg_StopDiagTrig	.equ	40h	; U8 mU8 (1 [-])

CONST_cCANMAN_RxMsg_defaults	.equ	80h	; U8 mU8 (1 [-])

CONST_cCANMAN_RxMsg_ThisCycle	.equ	08h	; U8 mU8 (1 [-])

CONST_cCANMAN_RxMsg_ThisDiagStep	.equ	02h	; U8 mU8 (1 [-])

CONST_cCANMAN_RxMsg_ThisStep	.equ	01h	; U8 mU8 (1 [-])

CONST_cCANMAN_TxMsg_State_Ready	.equ	04h	; U8 mU8 (1 [-])

CONST_cCANMAN_TxMsg_State_Request	.equ	01h	; U8 mU8 (1 [-])

CONST_cCANMAN_TxMsg_State_Update	.equ	02h	; U8 mU8 (1 [-])

CONST_cJ1939_CANIDmask_PGN	.equ	03FFFF00h	; U32 mU32 (1 [-])

CONST_cJ1939_CANIDmask_Priority	.equ	1C000000h	; U32 mU32 (1 [-])

CONST_cJ1939_CANIDshift_PGN	.equ	08h	; U8 mU8 (1 [-])

CONST_cJ1939_CANIDshift_Priority	.equ	1Ah	; U8 mU8 (1 [-])

CONST_cJ1939_21_AccessDenied	.equ	02h	; U8 mU8 (1 [-])

CONST_cJ1939_21_CannotRespond	.equ	03h	; U8 mU8 (1 [-])

CONST_cJ1939_21_NegativeACK	.equ	01h	; U8 mU8 (1 [-])

CONST_cJ1939_21_PositiveACK	.equ	00h	; U8 mU8 (1 [-])

CONST_cJ1939_73_Priority	.equ	06h	; U8 mU8 (1 [-])

CONST_cJ1939_MSG_READY	.equ	FFh	; U8 mU8 (1 [-])

CONST_cJ1939_1byteUNDEF	.equ	FFh	; U8 mU8 (1 [-])

CONST_cJ1939_BrcAddress	.equ	FFh	; U8 mU8 (1 [-])

CONST_cJ1939_21_Acknowledgment_PGN	.equ	0000E8FFh	; U32 mU32 (1 [-])

CONST_cJ1939_21_Request_PGN	.equ	0000EA00h	; U32 mU32 (1 [-])

CONST_cJ1939_21_PGNInitValue	.equ	FFFFFFFFh	; U32 mU32 (1 [-])

CONST_cJ1939_73_DM1_PGN	.equ	0000FECAh	; U32 mU32 (1 [-])

CONST_cJ1939_73_DM1_TxPeriod	.equ	03E8h	; U16 mTime1ms_U16 (1 [ms])

CONST_cJ1939_73_DM13_PGN	.equ	0000DFFFh	; U32 mU32 (1 [-])

CONST_cJ1939_73_DM13_priority	.equ	03h	; U8 mU8 (1 [-])

CONST_cJ1939_73_DM2_PGN	.equ	0000FECBh	; U32 mU32 (1 [-])

CONST_cJ1939_73_DM3_PGN	.equ	0000FECCh	; U32 mU32 (1 [-])

CONST_cJ1939_DM_priority	.equ	06h	; U8 mU8 (1 [-])

CONST_cUndef	.equ	03h	; U8 mBool2 (1 [-+fu])

CONST_cBRDC_AI_4modes__32V	.equ	01h	; U8 mBRDC_AI_Mode (1 [])

CONST_cBRDC_AI_4modes__5V	.equ	00h	; U8 mBRDC_AI_Mode (1 [])

CONST_cBRDC_AI_4modes__R500	.equ	03h	; U8 mBRDC_AI_Mode (1 [])

CONST_cBRDC_AI_4modes__R50K	.equ	02h	; U8 mBRDC_AI_Mode (1 [])

CONST_cBRDC_AI_InOut_modes__IN	.equ	00h	; U8 mBRDC_AI_Mode (1 [])

CONST_cBRDC_AI_InOut_modes__OUT	.equ	01h	; U8 mBRDC_AI_Mode (1 [])

CONST_cBRDC_AI_OnOff_modes__OFF	.equ	00h	; U8 mBRDC_AI_Mode (1 [])

CONST_cBRDC_AI_OnOff_modes__ON	.equ	01h	; U8 mBRDC_AI_Mode (1 [])

CONST_cBRDC_cfg_NA	.equ	FFh	; U8 mU8 (1 [-])

CONST_cBlackBox_syncTime	.equ	03E8h	; U16 mTime1ms_U16 (1 [ms])

CONST_cCSWL_EEPROM_mrk_SrvSize	.equ	02h	; U8 mU8 (1 [-])

CONST_cCSWL_EEPROM_RecoverEventID	.equ	01h	; U8 mU8 (1 [-])

CONST_cEEPROM_RecoverTimeout	.equ	0003h	; U16 mTime10ms_U16 (10 [ms])

CONST_cCSWL_EEPROM_SaveEventID	.equ	02h	; U8 mU8 (1 [-])

CONST_cEEPROM_SaveTimeout	.equ	0064h	; U16 mTime10ms_U16 (10 [ms])

CONST_cCSWL_SyMM_State_Active	.equ	03h	; U8 mU8 (1 [-])

CONST_cCSWL_SyMM_State_DataLoad	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_SyMM_State_DataStore	.equ	05h	; U8 mU8 (1 [-])

CONST_cCSWL_SyMM_State_EOL	.equ	04h	; U8 mU8 (1 [-])

CONST_cCSWL_SyMM_State_Reset	.equ	07h	; U8 mU8 (1 [-])

CONST_cCSWL_SyMM_State_Sleep	.equ	06h	; U8 mU8 (1 [-])

CONST_cCSWL_SyMM_State_StartUp	.equ	02h	; U8 mU8 (1 [-])

CONST_cCSWL_UDS_IOC_Option__ControlBan	.equ	08h	; U8 mU8 (1 [-])

CONST_cCSWL_UDS_IOC_Option__ControlBanClear	.equ	04h	; U8 mU8 (1 [-])

CONST_cUDS_IOC_Option_FreezeCurrentState	.equ	02h	; U8 mU8 (1 [-])

CONST_cUDS_IOC_Option_ResetToDefault	.equ	01h	; U8 mU8 (1 [-])

CONST_cUDS_IOC_Option_ReturnControlToECU	.equ	00h	; U8 mU8 (1 [-])

CONST_cUDS_IOC_Option_ShortTermAdjust	.equ	03h	; U8 mU8 (1 [-])

CONST_cUDS_RWC_1DIDforCell	.equ	02h	; U8 mUDS_RWC_method (1 [])

CONST_cUDS_RWC_1DIDforList	.equ	10h	; U8 mUDS_RWC_method (1 [])

CONST_cUDS_RWC_1DIDforParam	.equ	01h	; U8 mUDS_RWC_method (1 [])

CONST_cUDS_RWC_1DIDforParamInList	.equ	11h	; U8 mUDS_RWC_method (1 [])

CONST_cUDS_NRC_CNC	.equ	22h	; U8 mU8 (1 [-])

CONST_cUDS_NRC_GR	.equ	10h	; U8 mU8 (1 [-])

CONST_cUDS_NRC_IMLOIF	.equ	13h	; U8 mU8 (1 [-])

CONST_cUDS_NRC_ROOR	.equ	31h	; U8 mU8 (1 [-])

CONST_cUDS_NRC_RSE	.equ	24h	; U8 mU8 (1 [-])

CONST_cUDS_NRC_RTL	.equ	14h	; U8 mU8 (1 [-])

CONST_cUDS_NRC_SAD	.equ	33h	; U8 mU8 (1 [-])

CONST_cUDS_NRC_SFNS	.equ	12h	; U8 mU8 (1 [-])

CONST_cUDS_NRC_SNS	.equ	11h	; U8 mU8 (1 [-])

CONST_cUDS_NRC_SNSIAS	.equ	7Fh	; U8 mU8 (1 [-])

CONST_cUDS_PositiveResponse	.equ	00h	; U8 mU8 (1 [-])

CONST_cEHAL_CS_APPLICATION	.equ	01h	; U8 mU8 (1 [-])

CONST_cEHAL_CS_BOOTLOADER	.equ	00h	; U8 mU8 (1 [-])

CONST_cEHAL_CS_CALIBRATION	.equ	02h	; U8 mU8 (1 [-])

CONST_cEHAL_CS_CONFIGURATION	.equ	03h	; U8 mU8 (1 [-])

CONST_cU8_undef	.equ	FFh	; U8 mU8 (1 [-])

CONST_cTYP_TestApp	.equ	00h	; U8 mU8 (1 [-])

CONST_cSAEJ1939_ValidSignalMax_2byte	.equ	FAFFh	; U16 mU16 (1 [-])

CONST_cCSWL_DTCs_ASW_FaultsQty	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_AI_FaultsQty	.equ	04h	; U8 mU8 (1 [-])

CONST_cCSWL_BRDC_PWR_FaultsQty	.equ	02h	; U8 mU8 (1 [-])

CONST_cCSWL_AO_Faults_Overload	.equ	02h	; U8 mU8 (1 [-])

CONST_cCSWL_AO_Faults_Qty	.equ	03h	; U8 mU8 (1 [-])

CONST_cCSWL_AO_Faults_ShortGND	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_AO_Faults_ShortVBAT	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_AO_DAC_SupplyType_FullBattery	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_AO_DAC_SupplyType_HalfBattery	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_AO_DAC_TuneDir__Down	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_AO_DAC_TuneDir__Up	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_DO_Protect__Clear	.equ	40h	; U8 mU8 (1 [-])

CONST_cCSWL_DO_Protect__T15	.equ	20h	; U8 mU8 (1 [-])

CONST_cBRDC_PowerOut_Faults_Qty	.equ	04h	; U8 mU8 (1 [-])

CONST_cDIAG_NM_POS_BLINKhi	.equ	00h	; U8 mU8 (1 [-])

CONST_cDIAG_NM_POS_BLINKlow	.equ	01h	; U8 mU8 (1 [-])

CONST_cDIAG_NM_POS_ISO14229_DTChi	.equ	00h	; U8 mU8 (1 [-])

CONST_cDIAG_NM_POS_ISO14229_DTClow	.equ	01h	; U8 mU8 (1 [-])

CONST_cDIAG_NM_POS_ISO14229_Symp	.equ	02h	; U8 mU8 (1 [-])

CONST_cDIAG_NM_POS_SAEJ1939_FMI	.equ	02h	; U8 mU8 (1 [-])

CONST_cDIAG_NM_POS_SAEJ1939_SPNlow	.equ	00h	; U8 mU8 (1 [-])

CONST_cDIAG_NM_POS_SAEJ1939_SPNmid	.equ	01h	; U8 mU8 (1 [-])

CONST_cDTCst_confirmedDTC	.equ	08h	; U8 mDTCstatus (1 [])

CONST_cDTCst_pendingDTC	.equ	04h	; U8 mDTCstatus (1 [])

CONST_cDTCst_testFailed	.equ	01h	; U8 mDTCstatus (1 [])

CONST_cDTCst_testFailedSinceLastClear	.equ	20h	; U8 mDTCstatus (1 [])

CONST_cDTCst_testFailedThisOperationCycle	.equ	02h	; U8 mDTCstatus (1 [])

CONST_cDTCst_testNotCompletedSinceLastClear	.equ	10h	; U8 mDTCstatus (1 [])

CONST_cDTCst_testNotCompletedThisOperationCycle	.equ	40h	; U8 mDTCstatus (1 [])

CONST_cDTCst_warningIndicatorRequested	.equ	80h	; U8 mDTCstatus (1 [])

CONST_cMonResult_Fail	.equ	04h	; U8 mMonResult (1 [])

CONST_cMonResult_Pass	.equ	03h	; U8 mMonResult (1 [])

CONST_cMonResult_Prefail	.equ	02h	; U8 mMonResult (1 [])

CONST_cMonResult_Prepass	.equ	01h	; U8 mMonResult (1 [])

CONST_cMonResult_RestartOperation	.equ	06h	; U8 mMonResult (1 [])

CONST_cMonResult_Stop	.equ	05h	; U8 mMonResult (1 [])

CONST_cMonResult_undef	.equ	00h	; U8 mMonResult (1 [])

CONST_cDIAG_Object_AllFaults	.equ	FFh	; U8 mU8 (1 [-])

CONST_cDIAG_DTCformat_ISO_11992_4	.equ	03h	; U8 mU8 (1 [-])

CONST_cDIAG_DTCformat_ISO_14229_1	.equ	01h	; U8 mU8 (1 [-])

CONST_cDIAG_DTCformat_SAE_J1939_73	.equ	02h	; U8 mU8 (1 [-])

CONST_cDIAG_DTCformat_SAE_J2012_DA00	.equ	00h	; U8 mU8 (1 [-])

CONST_cDIAG_DTCformat_SAE_J2012_DA04	.equ	04h	; U8 mU8 (1 [-])

CONST_cCSWL_DIAG_MAX_MONITOR_SWC	.equ	14h	; U8 mU8 (1 [-])

CONST_cCSWL_MonOS_SeqID_CSW10	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_MonOS_SeqID_CSW100	.equ	01h	; U8 mU8 (1 [-])

CONST_cEHAL_OS_Time_Scale_Channel_Idx	.equ	44h	; U8 mU8 (1 [-])

CONST_cCSWL_MonOS_Levels_Qty	.equ	08h	; U8 mU8 (1 [-])

CONST_cCSWL_MonOS_Sequence_Qty	.equ	03h	; U8 mU8 (1 [-])

CONST_cmMonOS_Gen_ConfigCS	.equ	20h	; U8 mDIAG_ObjectPack (1 [])

CONST_cmMonOS_Gen_EEPROM	.equ	02h	; U8 mDIAG_ObjectPack (1 [])

CONST_cmCSWL_MonOS_Gen_IdleStuck	.equ	10h	; U8 mDIAG_ObjectPack (1 [])

CONST_cmMonOS_Gen_Reset_byMarker	.equ	04h	; U8 mDIAG_ObjectPack (1 [])

CONST_cmCSWL_MonOS_Gen_Reset_byReason	.equ	08h	; U8 mDIAG_ObjectPack (1 [])

CONST_cmMonOS_Gen_ROM	.equ	01h	; U8 mDIAG_ObjectPack (1 [])

CONST_cmCSWL_MonOS_Lv_Commission	.equ	02h	; U8 mDIAG_ObjectPack (1 [])

CONST_cmCSWL_MonOS_Lv_Entry	.equ	08h	; U8 mDIAG_ObjectPack (1 [])

CONST_cmCSWL_MonOS_Lv_Exit	.equ	10h	; U8 mDIAG_ObjectPack (1 [])

CONST_cmCSWL_MonOS_Lv_Omission	.equ	04h	; U8 mDIAG_ObjectPack (1 [])

CONST_cmCSWL_MonOS_Lv_Stuck	.equ	20h	; U8 mDIAG_ObjectPack (1 [])

CONST_cmCSWL_MonOS_Lv_Timing	.equ	01h	; U8 mDIAG_ObjectPack (1 [])

CONST_cmCSWL_MonOS_Seq_Restart	.equ	02h	; U8 mDIAG_ObjectPack (1 [])

CONST_cmCSWL_MonOS_Seq_Violation	.equ	01h	; U8 mDIAG_ObjectPack (1 [])

CONST_cUDS_NRC_SFNSIAS	.equ	7Eh	; U8 mU8 (1 [-])

CONST_cCSWL_EEPROM_mrk_ASWBlackBox_reserv	.equ	0064h	; U16 mU16 (1 [-])

CONST_cTYP_FPS	.equ	01h	; U8 mBoolean (1 [boolean])

CONST_cmUDS_RWC_prm_ReadSession	.equ	03h	; U8 mUDS_RWC_permissions (1 [])

CONST_cmUDS_RWC_prm_ControlSession	.equ	0Ch	; U8 mUDS_RWC_permissions (1 [])

CONST_cmUDS_RWC_prm_Secure	.equ	C0h	; U8 mUDS_RWC_permissions (1 [])

CONST_cCSWL_ECUID_DID_Test_DID	.equ	FD30h	; U16 mU16 (1 [-])

CONST_cTYP_ResetCause	.equ	01h	; U8 mBoolean (1 [boolean])

CONST_cCSWL_CANMAN_RxBSW_period	.equ	000Ah	; U16 mTime1ms_U16 (1 [ms])

CONST_cCSWL_CANMAN_RxDisp_period	.equ	000Ah	; U16 mTime1ms_U16 (1 [ms])

CONST_cCSWL_CANMAN_TxDisp_period	.equ	000Ah	; U16 mTime1ms_U16 (1 [ms])

CONST_cCSWL_CANMAN_TxBSW_period	.equ	000Ah	; U16 mTime1ms_U16 (1 [ms])

CONST_cWorkMode_Sleep	.equ	00h	; U8 mWorkMode (1 [WorkMode enum])

CONST_cWorkMode_Silent	.equ	01h	; U8 mWorkMode (1 [WorkMode enum])

CONST_cWorkMode_Active	.equ	02h	; U8 mWorkMode (1 [WorkMode enum])

CONST_cOS_1msLevel_ID	.equ	02h	; U8 mU8 (1 [-])

CONST_c_MonUnit_Type	.equ	01h	; U8 mU8 (1 [-])

CONST_cRTOS_FastestLevelPeriod	.equ	000F4240h	; U32 mTime1ns_U32 (1 [ns])

CONST_cTYP_Processor	.equ	01h	; U8 mU8 (1 [-])

CONST_cTYP_POWMAN	.equ	00h	; U8 mBoolean (1 [boolean])

CONST_cCSWL_SyMM_FakeWakeUp_Qty	.equ	01h	; U8 mU8 (1 [-])

CONST_cUDS_RWC_1DIDforParamInList_fromArray	.equ	21h	; U8 mUDS_RWC_method (1 [])

CONST_cTYP_MSEDA	.equ	01h	; U8 mU8 (1 [-])

CONST_cEHAL_IOMGR_DiagSt__Undef	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_IMPL_RF_Qty	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_IMPL_PRCD_Qty	.equ	01h	; U8 mU8 (1 [-])

CONST_cTYP_J1939_21	.equ	00h	; U8 mBoolean (1 [boolean])

CONST_cTYP_CANMAN	.equ	00h	; U8 mBoolean (1 [boolean])

CONST_cTYP_CANdrv	.equ	00h	; U8 mBoolean (1 [boolean])

CONST_cUDS_resetType_keyOffOnReset	.equ	02h	; U8 mU8 (1 [-])

CONST_cUDS_resetType_hardReset	.equ	01h	; U8 mU8 (1 [-])

CONST_cUDS_resetType_softReset	.equ	03h	; U8 mU8 (1 [-])

CONST_cUDS_resetType_enableRapidPowerShutDown	.equ	04h	; U8 mU8 (1 [-])

CONST_cUDS_resetType_disableRapidPowerShutDown	.equ	05h	; U8 mU8 (1 [-])

CONST_cWorkMode_undef	.equ	03h	; U8 mWorkMode (1 [WorkMode enum])

CONST_cUDS_controlType_enableRxAndTx	.equ	00h	; U8 mU8 (1 [-])

CONST_cUDS_controlType_enableRxAndDisableTx	.equ	01h	; U8 mU8 (1 [-])

CONST_cUDS_communicationType_normalCommunicationMessages_AllNetworks	.equ	01h	; U8 mU8 (1 [-])

CONST_cmUDS_RWC_prm_RoutineA	.equ	10h	; U8 mUDS_RWC_permissions (1 [])

CONST_cTYP_BRDC	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_TestApp_Load_SF_Qty	.equ	01h	; U8 mU8 (1 [-])

CONST_cmUDS_Cnd_0x81_rpmTooHigh	.equ	00000002h	; U32 mUDS_Conditions (1 [])

CONST_cmUDS_Cnd_0x22_conditionsNotCorrect	.equ	00000001h	; U32 mUDS_Conditions (1 [])

CONST_cmUDS_Cnd_0x82_rpmTooLow	.equ	00000004h	; U32 mUDS_Conditions (1 [])

CONST_cmUDS_Cnd_0x83_engineIsRunning	.equ	00000008h	; U32 mUDS_Conditions (1 [])

CONST_cmUDS_Cnd_0x84_engineIsNotRunning	.equ	00000010h	; U32 mUDS_Conditions (1 [])

CONST_cmUDS_Cnd_0x85_engineRunTimeTooLow	.equ	00000020h	; U32 mUDS_Conditions (1 [])

CONST_cmUDS_Cnd_0x86_temperatureTooHigh	.equ	00000040h	; U32 mUDS_Conditions (1 [])

CONST_cmUDS_Cnd_0x87_temperatureTooLow	.equ	00000080h	; U32 mUDS_Conditions (1 [])

CONST_cmUDS_Cnd_0x88_vehicleSpeedTooHigh	.equ	00000100h	; U32 mUDS_Conditions (1 [])

CONST_cmUDS_Cnd_0x89_vehicleSpeedTooLow	.equ	00000200h	; U32 mUDS_Conditions (1 [])

CONST_cmUDS_Cnd_0x8A_throttlePedalTooHigh	.equ	00000400h	; U32 mUDS_Conditions (1 [])

CONST_cmUDS_Cnd_0x8B_throttlePedalTooLow	.equ	00000800h	; U32 mUDS_Conditions (1 [])

CONST_cmUDS_Cnd_0x8C_transmissionRangeNotInNeutral	.equ	00001000h	; U32 mUDS_Conditions (1 [])

CONST_cmUDS_Cnd_0x8D_transmissionRangeNotInGear	.equ	00002000h	; U32 mUDS_Conditions (1 [])

CONST_cmUDS_Cnd_0x8F_brakeSwitchNotClosed	.equ	00008000h	; U32 mUDS_Conditions (1 [])

CONST_cmUDS_Cnd_0x90_shifterLeverNotInPark	.equ	00010000h	; U32 mUDS_Conditions (1 [])

CONST_cmUDS_Cnd_0x91_torqueConverterClutchLocked	.equ	00020000h	; U32 mUDS_Conditions (1 [])

CONST_cmUDS_Cnd_0x92_voltageTooHigh	.equ	00040000h	; U32 mUDS_Conditions (1 [])

CONST_cmUDS_Cnd_0x93_voltageTooLow	.equ	00080000h	; U32 mUDS_Conditions (1 [])

CONST_cUDS_NRC_BRR	.equ	21h	; U8 mU8 (1 [-])

CONST_cUDS_NRC_RCRRP	.equ	78h	; U8 mU8 (1 [-])

CONST_cUDS_SID_RDBI	.equ	22h	; U8 mU8 (1 [-])

CONST_cUDS_SID_WDBI	.equ	2Eh	; U8 mU8 (1 [-])

CONST_cTYP_UDS	.equ	01h	; U8 mU8 (1 [-])

CONST_cIC_12XS6_DEVID_RegN	.equ	0Eh	; U8 mU8 (1 [-])

CONST_cIC_12XS6_MC08XS6421	.equ	42h	; U8 mU8 (1 [-])

CONST_cIC_12XS6_MC10XS6200	.equ	46h	; U8 mU8 (1 [-])

CONST_cIC_12XS6_MC10XS6325	.equ	44h	; U8 mU8 (1 [-])

CONST_cIC_12XS6_MC17XS6400	.equ	43h	; U8 mU8 (1 [-])

CONST_cIC_12XS6_MC17XS6500	.equ	41h	; U8 mU8 (1 [-])

CONST_cTYP_12XS6_SW_configuration	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_IC_12XS6_ChipType_DID	.equ	FD38h	; U16 mU16 (1 [-])

CONST_cUDS_SuppressResponse	.equ	FFh	; U8 mU8 (1 [-])

CONST_cTYP_UDS_AsyncResponse	.equ	00h	; U8 mBoolean (1 [boolean])

CONST_cCSWL_DO_Forbidden_By_PWRI	.equ	10h	; U8 mU8 (1 [-])

CONST_cCSWL_DO_Protect__ReplaceECU	.equ	80h	; U8 mU8 (1 [-])

CONST_cmMonOS_Gen_BRDC_Shorts	.equ	40h	; U8 mDIAG_ObjectPack (1 [])

CONST_cCSWL_UDS_ECUID_VMCF_Qty	.equ	06h	; U8 mU8 (1 [-])

CONST_cCSWL_EEPROM_filler	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_EEPROM_mrk_ECUID_reserv	.equ	0040h	; U16 mU16 (1 [-])

CONST_cTYP_UDS_OBD	.equ	00h	; U8 mU8 (1 [-])

CONST_cEHAL_ISO14229_BufferSize	.equ	00FAh	; U16 mU16 (1 [-])

CONST_cCSWL_FI_TMR_Idx	.equ	44h	; U8 mU8 (1 [-])

CONST_cCSWL_FI_bit_IOMGRP	.equ	02h	; U8 mU8 (1 [-])

CONST_cCSWL_FI_bit_TMR	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_FI_bit_1ms	.equ	04h	; U8 mU8 (1 [-])

CONST_cTYP_IOMGRA_SEL	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_CANMAN_TxEventByListSettings	.equ	00h	; U8 mU8 (1 [-])

CONST_cTYP_ISO14229_RDTC	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_UDS_IOC_OptionMask	.equ	000Fh	; U16 mU16 (1 [-])

CONST_cTYP_KNK	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_EOL_PRCD_KNK_Idx	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_ISO17356_CtrlField_Offset	.equ	01h	; U8 mU8 (1 [-])

CONST_cCSWL_ISO17356_DA_Offset	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_ISO17356_NM_Msg_Size	.equ	08h	; U8 mU8 (1 [-])

CONST_cmCSWL_ISO17356_Alive	.equ	01h	; U8 mU8 (1 [-])

CONST_cmCSWL_ISO17356_Limphome	.equ	04h	; U8 mU8 (1 [-])

CONST_cmCSWL_ISO17356_Ring	.equ	02h	; U8 mU8 (1 [-])

CONST_cmCSWL_ISO17356_SleepAck	.equ	20h	; U8 mU8 (1 [-])

CONST_cmCSWL_ISO17356_SleepInd	.equ	10h	; U8 mU8 (1 [-])

CONST_cISO17356_NM_Mode_Active	.equ	03h	; U8 mU8 (1 [-])

CONST_cISO17356_NM_Mode_Init	.equ	01h	; U8 mU8 (1 [-])

CONST_cISO17356_NM_Mode_Limphome	.equ	05h	; U8 mU8 (1 [-])

CONST_cISO17356_NM_Mode_Reset	.equ	02h	; U8 mU8 (1 [-])

CONST_cISO17356_NM_Mode_Silent	.equ	04h	; U8 mU8 (1 [-])

CONST_cCSWL_ISO17356_SyncPeriod	.equ	000Ah	; U16 mTime1ms_U16 (1 [ms])

CONST_cCSWL_ISO17356_ECU_MaxQty	.equ	01h	; U8 mU8 (1 [-])

CONST_cTYP_ISO17356	.equ	00h	; U8 mBoolean (1 [boolean])

CONST_cEHAL_GLIB_CRC32_AreasQuantity	.equ	0001h	; U16 mU16 (1 [-])

CONST_cTYP_IOMGRD_ShiftReg	.equ	00h	; U8 mU8 (1 [-])

CONST_cBRDC_ShiftReg_FirstIOMGRnum	.equ	C8h	; U8 mU8 (1 [-])

CONST_cTYP_IOMGR_DBG	.equ	01h	; U8 mBoolean (1 [boolean])

CONST_cTYP_DO_MON_CURRENT	.equ	01h	; U8 mU8 (1 [-])

CONST_cTYP_DO_MON_READBACK	.equ	01h	; U8 mU8 (1 [-])

CONST_cTYP_DO_MON_DRV	.equ	01h	; U8 mU8 (1 [-])

CONST_cTYP_DO_MON_REPORT	.equ	01h	; U8 mU8 (1 [-])

CONST_cTYP_FO_MON_REPORT	.equ	00h	; U8 mU8 (1 [-])

CONST_cTYP_FO_MON_DRV	.equ	00h	; U8 mU8 (1 [-])

CONST_cTYP_FO_MON_READBACK	.equ	00h	; U8 mU8 (1 [-])

CONST_cTYP_FO_MON_CURRENT	.equ	00h	; U8 mU8 (1 [-])

CONST_cTYP_UDS_WDBI	.equ	01h	; U8 mU8 (1 [-])

CONST_cTYP_UDS_IOC	.equ	01h	; U8 mU8 (1 [-])

CONST_cTYP_UDS_RC	.equ	01h	; U8 mU8 (1 [-])

CONST_cTYP_UDS_VMEOL	.equ	00h	; U8 mU8 (1 [-])

CONST_cTYP_UDS__ER_CC	.equ	00h	; U8 mU8 (1 [-])

CONST_cCSWL_ECUID_VIN_DID	.equ	F190h	; U16 mU16 (1 [-])

CONST_cSL3_FaultsQty	.equ	0Ah	; U8 mU8 (1 [-])

