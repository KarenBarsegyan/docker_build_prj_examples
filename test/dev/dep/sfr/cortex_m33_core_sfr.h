//**************************************************************************************************
//  @Module     CORTEX_M33_CORE_SFR_FILE
//! \file   cortex_m33_core_sfr.h
//! \brief  Cortex-M33 core register definitions. Based on PM0264 Rev 3
//! \par    Platform
//!             Yuntu YTM32B1M
//! \par    Compatible
//!             Independent
//! \par    Abbreviations
//!             None
//! \par    History
//! | Date       | Version | Author | Comment
//! |:----------:|:-------:|:------:|---------------------------------------------------------------
//! | 10.05.2023 |  1.3.0  |  MAV   | Fixed size of the SHCSR.SECUREFAULTACT bit. Renamed SysTick
//! |            |         |        | timer registers same as Cortex-M4 names
//! | 03.05.2023 |  1.2.0  |  MAV   | Fixed SCB.CCR register and other errors
//! | 18.04.2023 |  1.1.0  |  MAV   | Added Doxygen comments. Fixed some errors. Added SAU module
//! | 07.06.2022 |  1.0.0  |  CAV   | First version.
//**************************************************************************************************

#ifndef CORTEX_M33_CORE_SFR_H
#define CORTEX_M33_CORE_SFR_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Get data types
#include "compiler.h"



//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************

//**************************************************************************************************
//! Floating point unit (FPU) memory map
//**************************************************************************************************
typedef volatile struct FPU_struct {
    U32 FPU_Reserved0[1U];

    union {
        U32 R;
        struct {
            U32 LSPACT    :1;
            U32 USER      :1;
            U32           :1;
            U32 THREAD    :1;
            U32 HFRDY     :1;
            U32 MMRDY     :1;
            U32 BFRDY     :1;
            U32 SFRDY     :1;
            U32 MONRDY    :1;
            U32 SPLIMVIOL :1;
            U32 UFRDY     :1;
            U32           :15;
            U32 TS        :1;
            U32 CLRONRETS :1;
            U32 CLRONRET  :1;
            U32 LSPENS    :1;
            U32 LSPEN     :1;
            U32 ASPEN     :1;
        } B;
    } FPCCR; //!< Floating-point context control register (Offset: 0x04; Reset: 0xC000.0000)

    union {
        U32 R;
        struct {
            U32         :3;
            U32 ADDRESS :29;            //!< Location of unpopulated floating-point register space allocated on an exception stack frame
        } B;
    } FPCAR; //!< Floating-point context address register (Offset: 0x08; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32       :22;
            U32 RMode :2;               //!< Default value for FPSCR.RMode
            U32 FZ    :1;               //!< Default value for FPSCR.FZ
            U32 DN    :1;               //!< Default value for FPSCR.DN
            U32 AHP   :1;               //!< Default value for FPSCR.AHP
            U32       :5;
        } B;
    } FPDSCR; //!< Floating-point default status control register (Offset: 0x0C; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 IOC   :1;               //!< Invalid operation cumulative exception bit
            U32 DZC   :1;               //!< Division by zero cumulative exception bit
            U32 OFC   :1;               //!< Overflow cumulative exception bit
            U32 UFC   :1;               //!< Underflow cumulative exception bit
            U32 IXC   :1;               //!< Inexact cumulative exception bit
            U32       :2;
            U32 IDC   :1;               //!< Input denormal cumulative exception bit
            U32       :14;
            U32 RMode :2;               //!< Rounding Mode control field
            U32 FZ    :1;               //!< Flush-to-zero mode control bit:
            U32 DN    :1;               //!< Default NaN mode control bit:
            U32 AHP   :1;               //!< Alternative half-precision control bit:
            U32       :1;
            U32 V     :1;               //!< Overflow condition code flag
            U32 C     :1;               //!< Carry condition code flag
            U32 Z     :1;               //!< Zero condition code flag
            U32 N     :1;               //!< Negative condition code flag
        } B;
    } FPSCR; //!< Floating-point status control register (Offset: not mapped; Reset: 0x0000.0000)

} FPU_tag; // end of FPU_tag



//**************************************************************************************************
//! Memory protection unit (MPU) memory map
//**************************************************************************************************
typedef volatile struct MPU_struct {
    union {
        volatile U32 R;
        struct {
            U32 SEPARATE :1;            //!< Separate flag
            U32          :7;
            U32 DREGION  :8;            //!< Number of MPU data regions
            U32          :16;
        } B;
    } TYPE; //!< Type register (Offset: 0x00; Reset: 0xXXXX.XXXX)

    union {
        volatile U32 R;
        struct {
            U32 ENABLE     :1;          //!< Enables the MPU
            U32 HFNMIENA   :1;          //!< Enables the operation of MPU during hard fault, NMI, and FAULTMASK handlers
            U32 PRIVDEFENA :1;          //!< Enable priviliged software access to default memory map
            U32            :29;
        } B;
    } CTRL; //!< Control register (Offset: 0x04; Reset: 0x0000.0000)

    union {
        volatile U32 R;
        struct {
            U32 REGION :8;              //!< MPU region
            U32        :24;
        } B;
    } RNR; //!< Region number register (Offset: 0x08; Reset: 0xXXXX.XXXX)

    union {
        volatile U32 R;
        struct {
            U32 XN   :1;                //!< Execute never
            U32 AP   :2;                //!< Access permissions
            U32 SH   :2;                //!< Shareability
            U32 BASE :27;               //!< Bits[31:5] of the lower inclusive limit of the selected MPU memory region
        } B;
    } RBAR; //!< Region base address register (Offset: 0x0C; Reset: 0xXXXX.XXXX)

    union {
        volatile U32 R;
        struct {
            U32 EN       :1;            //!< Region enable
            U32 ATTRINDX :3;            //!< Attribute index
            U32          :1;
            U32 LIMIT    :27;           //!< Limit address
        } B;
    } RLAR; //!< Region limit address register (Offset: 0x10; Reset: 0xXXXX.XXXX)

    union {
        U32 R;
        struct {
            U32 XN   :1;                //!< Execute never
            U32 AP   :2;                //!< Access permissions
            U32 SH   :2;                //!< Shareability
            U32 BASE :27;               //!< Bits[31:5] of the lower inclusive limit of the selected MPU memory region
        } B;
    } RBAR_A1; //!< Region base address register alias 1 (Offset: 0x14; Reset: 0xXXXX.XXXX)

    union {
        U32 R;
        struct {
            U32 EN       :1;            //!< Region enable
            U32 ATTRINDX :3;            //!< Attribute index
            U32          :1;
            U32 LIMIT    :27;           //!< Limit address
        } B;
    } RLAR_A1; //!< Region limit address register alias 1 (Offset: 0x18; Reset: 0xXXXX.XXXX)

    union {
        U32 R;
        struct {
            U32 XN   :1;                //!< Execute never
            U32 AP   :2;                //!< Access permissions
            U32 SH   :2;                //!< Shareability
            U32 BASE :27;               //!< Bits[31:5] of the lower inclusive limit of the selected MPU memory region
        } B;
    } RBAR_A2; //!< MPU region base address register alias 2 (Offset: 0x1C; Reset: 0xXXXX.XXXX)

    union {
        U32 R;
        struct {
            U32 EN       :1;            //!< Region enable
            U32 ATTRINDX :3;            //!< Attribute index
            U32          :1;
            U32 LIMIT    :27;           //!< Limit address
        } B;
    } RLAR_A2; //!< Region limit address register alias 2 (Offset: 0x20; Reset: 0xXXXX.XXXX)

    union {
        U32 R;
        struct {
            U32 XN   :1;                //!< Execute never
            U32 AP   :2;                //!< Access permissions
            U32 SH   :2;                //!< Shareability
            U32 BASE :27;               //!< Bits[31:5] of the lower inclusive limit of the selected MPU memory region
        } B;
    } RBAR_A3; //!< Region base address register alias 3 (Offset: 0x24; Reset: 0xXXXX.XXXX)

    union {
        U32 R;
        struct {
            U32 EN       :1;            //!< Region enable
            U32 ATTRINDX :3;            //!< Attribute index
            U32          :1;
            U32 LIMIT    :27;           //!< Limit address
        } B;
    } RLAR_A3; //!< Region limit address register alias 3 (Offset: 0x28; Reset: 0xXXXX.XXXX)

    union {
        U32 R;
        struct {
            U32 ATTR0 :8;               //!< Memory attribute 0
            U32 ATTR1 :8;               //!< Memory attribute 1
            U32 ATTR2 :8;               //!< Memory attribute 2
            U32 ATTR3 :8;               //!< Memory attribute 3
        } B;
    } MAIR0; //!< Memory attribute indirection register 0 (Offset: 0x; Reset: 0xXXXX.XXXX)

    union {
        U32 R;
        struct {
            U32 ATTR4 :8;               //!< Memory attribute 4
            U32 ATTR5 :8;               //!< Memory attribute 5
            U32 ATTR6 :8;               //!< Memory attribute 6
            U32 ATTR7 :8;               //!< Memory attribute 7
        } B;
    } MAIR1; //!< Memory attribute indirection register 1 (Offset: 0x; Reset: 0xXXXX.XXXX)

} MPU_tag; // end of MPU_tag



//**************************************************************************************************
//! Nested vectored interrupt controller (NVIC) memory map
//**************************************************************************************************
typedef volatile struct NVIC_struct {
    union {
        U32 R;
        struct {
            U32 SETENA :32;             //!< Interrupt set-enable bits
        } B;
    } ISER[16]; //!< Interrupt set-enable register (Offset: 0x000-0x03F; Reset: 0x0000.0000)

    U32 NVIC_Reserved0[16U];

    union {
        U32 R;
        struct {
            U32 CLRENA :32;             //!< Interrupt clear-enable bits
        } B;
    } ICER[16]; //!< Interrupt clear-enable register (Offset: 0x080-0x0BF; Reset: 0x0000.0000)

    U32 NVIC_Reserved1[16U];

    union {
        U32 R;
        struct {
            U32 SETPEND :32;            //!< Interrupt set-pending bits
        } B;
    } ISPR[16]; //!< Interrupt set-pending register (Offset: 0x100-0x13F; Reset: 0x0000.0000)

    U32 NVIC_Reserved2[16U];

    union {
        U32 R;
        struct {
            U32 CLRPEND :32;            //!< Interrupt clear-pending bits
        } B;
    } ICPR[16]; //!< Interrupt clear-pending register (Offset: 0x180-0x1BF; Reset: 0x0000.0000)

    U32 NVIC_Reserved3[16U];

    union {
        U32 R;
        struct {
            U32 ACTIVE :32;             //!< Interrupt active flags
        } B;
    } IABR[16]; //!< Interrupt active bit register (Offset: 0x200-0x23F; Reset: 0x0000.0000)

    U32 NVIC_Reserved4[16U];

    union {
        U32 R;
        struct {
            U32 ITNS :32;               //!< Interrupt targets non-secure bits
        } B;
    } ITNS[16]; //!< Interrupt target non-secure register (Offset: 0x280-0x2BF; Reset: 0x0000.0000)

    U32 NVIC_Reserved5[16U];

    U8 IPR[480];                        //!< Interrupt priority register (Offset: 0x300-0x4DF; Reset: 0x0000.0000)

    U32 NVIC_Reserved6[584U];

    union {
        U32 R;
        struct {
            U32 INTID :9;               //!< Software generated interrupt ID
            U32       :23;
        } B;
    } STIR; //!< Software trigger interrupt register (Offset: 0xE00; Reset: 0x0000.0000)

} NVIC_tag; // end of NVIC_tag



//**************************************************************************************************
//! Security Attribution Unit (SAU) memory map
//**************************************************************************************************
typedef volatile struct SAU_struct {
    U32 SAU_Reserved0[52U];

    union {
        U32 R;
        struct {
            U32 ENABLE :1;              //!< Enables the SAU
            U32 ALLNS  :1;              //!< All Non-secure
            U32        :30;
        } B;
    } CTRL; //!< Control register (Offset: 0xD0; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 SREGION :8;             //!< The number of implemented SAU regions
            U32         :24;
        } B;
    } TYPE; //!< Type register (Offset: 0xD4; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 REGION :8;              //!< Indicates the SAU region accessed by SAU_RBAR and SAU_RLAR
            U32        :24;
        } B;
    } RNR; //!< Region number register (Offset: 0xD8; Reset: 0xXXXX.XXXX)

    union {
        U32 R;
        struct {
            U32       :5;
            U32 BADDR :27;              //!< Base address
        } B;
    } RBAR; //!< Region base register (Offset: 0xDC; Reset: 0xXXXX.XXXX)

    union {
        U32 R;
        struct {
            U32 ENABLE :1;              //!< SAU region enable
            U32 NSC    :1;              //!< Non-secure callable
            U32        :3;
            U32 LADDR  :27;             //!< Limit address
        } B;
    } RLAR; //!< Region limit register (Offset: 0xE0; Reset: 0xXXXX.XXX0)

    union {
        U32 R;
        struct {
            U32 INVEP     :1;           //!< Invalid entry point
            U32 INVIS     :1;           //!< Invalid integrity signature flag
            U32 INVER     :1;           //!< Invalid exception return flag
            U32 AUVIOL    :1;           //!< Attribution unit violation flag
            U32 INVTRAN   :1;           //!< Invalid transition flag
            U32 LSPERR    :1;           //!< Lazy state preservation error flag
            U32 SFARVALID :1;           //!< Secure fault address valid
            U32 LSERR     :1;           //!< Lazy state error flag
            U32           :24;
        } B;
    } SFSR; //!< Secure fault status register (Offset: 0xE4; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 ADDRESS:32;             //!< Holds the address of an access that caused an SAU violation
        } B;
    } SFAR; //!< Secure fault address register (Offset: 0xE8; Reset: 0xXXXX.XXXX)

} SAU_tag; // end of SAU_tag



//**************************************************************************************************
//! System control block (SCB) memory map
//**************************************************************************************************
typedef volatile struct SCB_struct {
    U32 SCB_Reserved0[2U];

    union {
        U32 R;
        struct {
            U32 DISMCYCINT     :1;      //!< Disables interrupt of multi-cycle instructions
            U32                :1;
            U32 DISFOLD        :1;      //!< Disables folding of IT instructions
            U32                :6;
            U32 DISOOFP        :1;      //!< Disables floating point instructions completing out of order with respect to integer instructions
            U32 FPEXCODIS      :1;      //!< Disables FPU exception outputs
            U32                :1;
            U32 DISITMATBFLUSH :1;      //!< Disables ITM and DWT ATB flush
            U32                :16;
            U32 EXTEXCLALL     :1;      //!< Allows external exclusive operations
            U32                :2;
        } B;
    } ACTLR; //!< Auxiliary control register (Offset: 0x008; Reset: 0x0000.0000)

    U32 SCB_Reserved1[829U];

    union {
        U32 R;
        struct {
            U32 Revision    :4;         //!< Revision number
            U32 PartNo      :12;        //!< Part number of the processor (0xC24: Cortex-M4)
            U32 Constant    :4;         //!< Reads as 0xF
            U32 Variant     :4;         //!< Variant number
            U32 Implementer :8;         //!< Implementer code (0x41: Arm)
        } B;
    } CPUID; //!< CPUID base register (Offset: 0xD00; Reset: 0x410F.D214)

    union {
        U32 R;
        struct {
            U32 VECTACTIVE  :9;         //!< Contains the active exception number
            U32             :2;
            U32 RETTOBASE   :1;         //!< Indicates whether there are preempted active exceptions
            U32 VECTPENDING :9;         //!< Indicates the exception number of the highest priority pending enabled exception
            U32             :1;
            U32 ISRPENDING  :1;         //!< Interrupt pending flag, excluding NMI and Faults
            U32             :2;
            U32 PENDSTCLR   :1;         //!< SysTick exception clear-pending bit
            U32 PENDSTSET   :1;         //!< SysTick exception set-pending bit
            U32 PENDSVCLR   :1;         //!< PendSV clear-pending bit
            U32 PENDSVSET   :1;         //!< PendSV set-pending bit
            U32             :1;
            U32 PENDNMICLR  :1;         //!< Pend NMI clear bit
            U32 NMIPENDSET  :1;         //!< NMI set-pending bit
        } B;
    } ICSR; //!< Interrupt control and state register (Offset: 0xD04; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32        :7;
            U32 TBLOFF :25;             //!< Vector table base offset field
        } B;
    } VTOR; //!< Vector table offset register (Offset: 0xD08; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 VECTRESET     :1;       //!< Reserved for Debug use. This bit reads as 0
            U32 VECTCLRACTIVE :1;       //!< Reserved for Debug use. This bit reads as 0
            U32 SYSRESETREQ   :1;       //!< System reset request bit is implementation defined
            U32               :5;
            U32 PRIGROUP      :3;       //!< Interrupt priority grouping field is implementation defined
            U32               :4;
            U32 ENDIANNESS    :1;       //!< Data endianness bit is implementation defined
            U32 VECTKEY       :16;      //!< Register key
        } B;
    } AIRCR; //!< Application interrupt and reset control register (Offset: 0xD0C; Reset: 0xFA05.0000)

    union {
        U32 R;
        struct {
            U32             :1;
            U32 SLEEPONEXIT :1;         //!< Indicates sleep-on-exit when returning from Handler mode to Thread mode
            U32 SLEEPDEEP   :1;         //!< Controls whether the processor uses sleep or deep sleep as its low power mode
            U32 SLEEPDEEPS  :1;         //!< Controls whether the SLEEPDEEP bit is only accessible from the Secure state
            U32 SEVONPEND   :1;         //!< Send Event on Pending bit
            U32             :27;
        } B;
    } SCR; //!< System control register (Offset: 0xD10; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32              :1;
            U32 USERSETMPEND :1;        //!< Enables unprivileged software access to the STIR
            U32              :1;
            U32 UNALIGN_TRP  :1;        //!< Enables unaligned access traps
            U32 DIV_0_TRP    :1;        //!< Enables faulting or halting when the processor executes an SDIV or UDIV instruction with a divisor of 0
            U32              :3;
            U32 BFHFNMIGN    :1;        //!< Enables handlers with priority -1 or -2 to ignore data BusFaults caused by load and store instructions
            U32              :1;
            U32 STKOFHFNMIGN :1;        //!< Controls the effect of a stack limit violation while executing at a requested priority less than 0
            U32              :5;
            U32 DC           :1;
            U32 IC           :1;
            U32 BP           :1;
            U32              :13;
        } B;
    } CCR; //!< Configuration and control register (Offset: 0xD14; Reset: 0x0000.0200)

    union {
        U32 R;
        struct {
            U32 PRI_4 :8;               //!< Priority of system handler 4, MemManage
            U32 PRI_5 :8;               //!< Priority of system handler 5, BusFault
            U32 PRI_6 :8;               //!< Priority of system handler 6, UsageFault
            U32 PRI_7 :8;               //!< Priority of system handler 7, SecureFault
        } B;
    } SHPR1; //!< System handler priority register 1 (Offset: 0xD18; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32        :24;
            U32 PRI_11 :8;              //!< Priority of system handler 11, SVCall
        } B;
    } SHPR2; //!< System handler priority register 2 (Offset: 0xD1C; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32        :16;
            U32 PRI_14 :8;              //!< Priority of system handler 14, PendSV
            U32 PRI_15 :8;              //!< Priority of system handler 15, SysTick
        } B;
    } SHPR3; //!< System handler priority register 3 (Offset: 0xD20; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 MEMFAULTACT       :1;   //!< MemManage exception active bit
            U32 BUSFAULTACT       :1;   //!< BusFault exception active bit
            U32 HARDFAULTACT      :1;   //!< HardFault exception active bit
            U32 USGFAULTACT       :1;   //!< UsageFault exception active bit
            U32 SECUREFAULTACT    :1;   //!< SecureFault exception active bit
            U32 NMIACT            :1;   //!< NMI exception active bit
            U32                   :1;
            U32 SVCALLACT         :1;   //!< SVCall active bit
            U32 MONITORACT        :1;   //!< Debug monitor active bit
            U32                   :1;
            U32 PENDSVACT         :1;   //!< PendSV exception active bit
            U32 SYSTICKACT        :1;   //!< SysTick exception active bit
            U32 USGFAULTPENDED    :1;   //!< UsageFault exception pending bit
            U32 MEMFAULTPENDED    :1;   //!< MemManage exception pending bit
            U32 BUSFAULTPENDED    :1;   //!< BusFault exception pending bit
            U32 SVCALLPENDED      :1;   //!< SVCall pending bit
            U32 MEMFAULTENA       :1;   //!< MemManage enable bit
            U32 BUSFAULTENA       :1;   //!< BusFault enable bit
            U32 USGFAULTENA       :1;   //!< UsageFault enable bit
            U32 SECUREFAULTENA    :1;   //!< SecureFault enable bit
            U32 SECUREFAULTPENDED :1;   //!< SecureFault exception pending bit
            U32 HARDFAULTPENDED   :1;   //!< HardFault exception pending bit
            U32                   :10;
        } B;
    } SHCSR; //!< System handler control and state register (Offset: 0xD24; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 IACCVIOL   :1;          //!< Instruction access violation flag
            U32 DACCVIOL   :1;          //!< Data access violation flag
            U32            :1;
            U32 MUNSTKERR  :1;          //!< MemManage fault on unstacking for a return from exception
            U32 MSTKERR    :1;          //!< MemManage fault on stacking for exception entry
            U32 MLSPERR    :1;          //!< MemManage fault on floating-point lazy state
            U32            :1;
            U32 MMARVALID  :1;          //!< MemManage Fault Address Register (MMFAR) valid flag
            U32 IBUSERR    :1;          //!< Instruction bus error
            U32 PRECISERR  :1;          //!< Precise data bus error
            U32            :1;
            U32 UNSTKERR   :1;          //!< BusFault on unstacking for a return from exception
            U32 STKERR     :1;          //!< BusFault on stacking for exception entry
            U32 LSPERR     :1;          //!< Bus fault on floating-point lazy state preservation
            U32            :1;
            U32 BFARVALID  :1;          //!< BusFault Address Register (BFAR) valid flag
            U32 UNDEFINSTR :1;          //!< Undefined instruction UsageFault
            U32 INVSTATE   :1;          //!< Invalid state UsageFault
            U32 INVPC      :1;          //!< Invalid PC load UsageFault
            U32 NOCP       :1;          //!< No coprocessor UsageFault
            U32 STKOF      :1;          //!< Stack overflow flag
            U32            :3;
            U32 UNALIGNED  :1;          //!< Unaligned access UsageFault
            U32 DIVBYZERO  :1;          //!< Divide by zero UsageFault
            U32            :6;
        } B;
    } CFSR; //!< Configurable fault status register (Offset: 0xD28; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32          :1;
            U32 VECTTBL  :1;            //!< Indicates a BusFault on a vector table read during exception processing
            U32          :28;
            U32 FORCED   :1;            //!< Indicates a forced hard fault
            U32 DEBUG_VT :1;            //!< Reserved for Debug use
        } B;
    } HFSR; //!< Hard fault status register (Offset: 0xD2C; Reset: 0x0000.0000)

    U32 SCB_Reserved2[1U];

    union {
        U32 R;
        struct {
            U32 ADDRESS :32;            //!< The MMFAR contains the address of the location that generated a MemManage fault
        } B;
    } MMFAR; //!< Memory management fault address register (Offset: 0xD34; Reset: 0xXXXX.XXXX)

    union {
        U32 R;
        struct {
            U32 ADDRESS :32;            //!< The BFAR contains the address of the location that generated a BusFault
        } B;
    } BFAR; //!< Bus fault address register (Offset: 0xD38; Reset: 0xXXXX.XXXX)

    U32 SCB_Reserved3[19U];

    union {
        U32 R;
        struct {
            U32      :20;
            U32 CP10 :2;                //!< CP10 privilege
            U32 CP11 :2;                //!< CP11 privilege
            U32      :8;
        } B;
    } CPACR; //!< Coprocessor access control register (Offset: 0xD88; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32      :10;
            U32 CP10 :1;                //!< Enables Non-secure access to the Floating-point Extension
            U32 CP11 :1;                //!< Enables Non-secure access to the Floating-point Extension
            U32      :20;
        } B;
    } NSACR; //!< Non-secure access control register (Offset: 0xD8C; Reset: UNKNOWN)

} SCB_tag; // end of SCB_tag



//**************************************************************************************************
//! SysTick timer (STK) memory map
//**************************************************************************************************
typedef volatile struct STK_struct {
    union {
        U32 R;
        struct {
            U32 ENABLE    :1;           //!< Counter enable
            U32 TICKINT   :1;           //!< SysTick exception request enable
            U32 CLKSOURCE :1;           //!< Clock source selection
            U32           :13;
            U32 COUNTFLAG :1;           //!< Returns 1 if timer counted to 0 since last time this was read
            U32           :15;
        } B;
    } CTRL; //!< Control and status register (CSR) (Offset: 0x00; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 RELOAD :24;             //!< Reload value
            U32        :8;
        } B;
    } LOAD; //!< Reload value register (RVR) (Offset: 0x04; Reset: UNKNOWN)

    union {
        U32 R;
        struct {
            U32 CURRENT :24;            //!< Current counter value
            U32         :8;
        } B;
    } VAL; //!< Current value register (CVR) (Offset: 0x08; Reset: UNKNOWN)

    union {
        U32 R;
        struct {
            U32 TENMS :24;              //!< Calibration value
            U32       :6;
            U32 SKEW  :1;               //!< SKEW flag: Indicates whether the TENMS value is exact. Reads as one
            U32 NOREF :1;               //!< NOREF flag. Reads as zero. Indicates that a separate reference clock is provided
        } B;
    } CALIB; //!< Calibration value register (CALIB) (Offset: 0x0C; Reset: 0xC000.0000)

} STK_tag; // end of STK_tag



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

//! Floating Point Unit
#define FPU                     (*(FPU_tag *)           0xE000EF30UL)

//! Memory Protection Unit
#define MPU                     (*(MPU_tag *)           0xE000ED90UL)

//! Nested Vectored Interrupt Controller
#define NVIC                    (*(NVIC_tag *)          0xE000E100UL)

//! Security Attribution Unit
#define SAU                     (*(SAU_tag *)           0xE000ED00UL)

//! System Control Block
#define SCB                     (*(SCB_tag *)           0xE000E000UL)

//! SysTick Timer
#define STK                     (*(STK_tag *)           0xE000E010UL)



#endif // CORTEX_M33_CORE_SFR_H

//****************************************** end of file *******************************************
