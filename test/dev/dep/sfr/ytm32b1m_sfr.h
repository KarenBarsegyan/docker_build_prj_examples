//**************************************************************************************************
//  @Module     YTM32B1M_SFR_FILE
//! \file   ytm32b1m_sfr.h
//! \brief  Register definitions. Based on YTM32B1ME0 Reference Manual Rev. 1.0
//! \par    Platform
//!             Yuntu YTM32B1M
//! \par    Compatible
//!             Independent
//! \par    Abbreviations
//!             None
//! \par    History
//! | Date       | Version | Author | Comment
//! |:----------:|:-------:|:------:|---------------------------------------------------------------
//! | 22.05.2023 |  1.0.11 |  MAV   | Fixed SCU module reserved areas
//! | 15.05.2023 |  1.0.10 |  MAV   | Renamed FLAXCAN.MCR.DMAEN, INTM.TMRV and RCU.RSSR.WTDG
//! |            |         |        | for avoid macros conflicts. Changed unsigned type to signed
//! |            |         |        | for some DMA registers
//! | 10.05.2023 |  1.0.9  |  MAV   | Fixed SCU.CMUCMP structure size
//! | 03.05.2023 |  1.0.8  |  MAV   | Fixed some errors
//! | 20.04.2023 |  1.0.7  |  MAV   | Redesigned file. Added Doxygen comments
//! | 04.04.2023 |  1.0.6  |  CAV   | Delete structures from LINFLEX DATA register
//! | 06.03.2023 |  1.0.5  |  CAV   | Fix UARTCR.B.TFFM field name
//! | 03.03.2023 |  1.0.4  |  CAV   | Fix SCU.CMUCMP fields name error
//! | 15.01.2023 |  1.0.3  |  CAV   | Fix I2C SRADDR field name error. Add IRQ, DMA description
//! | 19.10.2022 |  1.0.2  |  CAV   | Cleared of excess
//! | 18.10.2022 |  1.0.1  |  CAV   | Preliminary release of CIM, SCU, GPIO, PCTRL, IPC memory map
//! | 07.10.2022 |  1.0.0  |  CAV   | First version.
//**************************************************************************************************

#ifndef YTM32B1M_SFR_H
#define YTM32B1M_SFR_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Get data types
#include "compiler.h"



//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************

//**************************************************************************************************
//! Analog Comparator (ACMP) memory map
//**************************************************************************************************
typedef volatile struct ACMP_struct {
    union {
        U32 R;
        struct {
            U32 EN      :1;             // Module Enable
            U32 PWRMD   :1;             // Power Mode
            U32 IREF    :2;             // Internal Current Control
            U32 SMPMD   :2;             // Sample Mode Selection
            U32 CLKSEL  :2;             // Functional Clock Selection
            U32 INPSEL  :2;             // Positive Input Selection
            U32         :2;
            U32 INNSEL  :2;             // Negative Input Selection
            U32         :2;
            U32 HYSTVAL :2;             // Comparator Hysteresis Value
            U32 OFFSET  :1;             // Comparator Offset Control Register
            U32 POL     :1;             // Output Polarity
            U32 OUTSEL  :1;             // Output Selection
            U32 AUTODIS :1;             // Automatic Disable Hard Block
            U32         :6;
            U32 EDGESEL :2;             // Edge Selection
            U32         :2;
        } B;
    } CTRL; // Control Register (Offset: 0x00; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 EN   :1;                // DAC Enable
            U32 VREF :1;                // DAC Voltage Reference Source
            U32      :6;
            U32 VAL  :8;                // DAC Output Voltage Level
            U32      :16;
        } B;
    } DAC; // DAC Register (Offset: 0x04; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CHPSEL :3;              // Positive Channel Selection
            U32        :1;
            U32 CHNSEL :3;              // Negative Channel Selection
            U32        :25;
        } B;
    } MUX; // Channels Multiplexer (Offset: 0x08; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 PER    :8;              // Digital Filter Period
            U32 CNT    :3;              // Digital Filter Counter
            U32        :5;
            U32 CLKSRC :1;              // Filter Clock Source
            U32        :15;
        } B;
    } FILT; // Filter Register (Offset: 0x0c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 EN :1;                  // DMA Enable
            U32    :31;
        } B;
    } DMACR; // DMA Control Register (Offset: 0x10; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 OUT    :1;              // Current comparator output
            U32 OUTPF  :1;              // Comparator Output Positive Edge Flag
            U32 OUTNF  :1;              // Comparator Output Negative Edge Flag
            U32        :5;
            U32 CHID   :3;              // Current Channel identity
            U32        :5;
            U32 CH0F   :1;              // Channel 0 Output Flag
            U32 CH1F   :1;              // Channel 1 Output Flag
            U32 CH2F   :1;              // Channel 2 Output Flag
            U32 CH3F   :1;              // Channel 3 Output Flag
            U32 CH4F   :1;              // Channel 4 Output Flag
            U32 CH5F   :1;              // Channel 5 Output Flag
            U32 CH6F   :1;              // Channel 6 Output Flag
            U32 CH7F   :1;              // Channel 7 Output Flag
            U32 CH0OUT :1;              // Channel 0 Output In Continuous Mode
            U32 CH1OUT :1;              // Channel 1 Output In Continuous Mode
            U32 CH2OUT :1;              // Channel 2 Output In Continuous Mode
            U32 CH3OUT :1;              // Channel 3 Output In Continuous Mode
            U32 CH4OUT :1;              // Channel 4 Output In Continuous Mode
            U32 CH5OUT :1;              // Channel 5 Output In Continuous Mode
            U32 CH6OUT :1;              // Channel 6 Output In Continuous Mode
            U32 CH7OUT :1;              // Channel 7 Output In Continuous Mode
        } B;
    } STS; // Status register (Offset: 0x18; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 IE     :1;              // Interrupt Enable
            U32        :15;
            U32 CONTIE :1;              // Continuous Mode Interrupt Enable
            U32        :15;
        } B;
    } INTE; // Interrupt Enable Register (Offset: 0x1c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 EN    :1;               // Continuous Enable
            U32 CHFIX :1;               // Fix Channel
            U32 MODE  :1;               // Continuous Mode
            U32       :5;
            U32 CH0EN :1;               // Channel 0 Enable in Continuous Mode
            U32 CH1EN :1;               // Channel 1 Enable in Continuous Mode
            U32 CH2EN :1;               // Channel 2 Enable in Continuous Mode
            U32 CH3EN :1;               // Channel 3 Enable in Continuous Mode
            U32 CH4EN :1;               // Channel 4 Enable in Continuous Mode
            U32 CH5EN :1;               // Channel 5 Enable in Continuous Mode
            U32 CH6EN :1;               // Channel 6 Enable in Continuous Mode
            U32 CH7EN :1;               // Channel 7 Enable in Continuous Mode
            U32 PER   :8;               // Continuous Mode Period
            U32 SMP   :8;               // Sample Point in Continuous Mode
        } B;
    } CONT; // Continuous Mode Register (Offset: 0x20; Reset: 0x18300000)

} ACMP_tag; // end of ACMP_tag



//**************************************************************************************************
//! Analog-to-Digital Converter (ADC) memory map
//**************************************************************************************************
typedef volatile struct ADC_struct {
    union {
        U32 R;
        struct {
            U32 ADRDY :1;               // ADC Ready Flag
            U32 EOSMP :1;               // End of Sampling Flag
            U32 EOC   :1;               // End of Conversion Flag
            U32 EOSEQ :1;               // End of Sequence Flag
            U32 OVR   :1;               // ADC Overrun
            U32 FULL  :1;               // FIFO Full Status
            U32 EMPTY :1;               // FIFO Empty Status
            U32 WD    :1;               // Watchdog Flag
            U32       :24;
        } B;
    } STS; // Status register (Offset: 0x00; Reset: 0x00000040)

    union {
        U32 R;
        struct {
            U32 ADRDYE  :1;             // ADC Ready Interrupt Enable
            U32 EOSMPIE :1;             // End of Sampling Flag Interrupt Enable
            U32 EOCIE   :1;             // End of Conversion Interrupt Enable
            U32 EOSEQIE :1;             // End of Conversion Sequence Interrupt Enable
            U32 OVRIE   :1;             // ADC Overrun Interrupt Enable
            U32         :2;
            U32 WDIE    :1;             // Watchdog Interrupt Enable
            U32         :24;
        } B;
    } INTE; // Interrupt Enable Register (Offset: 0x04; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 ADEN    :1;             // ADC Enable Command
            U32 ADDIS   :1;             // ADC Disable Command
            U32 ADSTART :1;             // ADC Start Conversion Command
            U32 ADSTOP  :1;             // ADC Stop Conversion Command
            U32 TSEN    :1;             // Tempsenser Enable
            U32         :27;
        } B;
    } CTRL; // Control Register (Offset: 0x08; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 DMAEN   :1;             // Direct Memory Access Enable
            U32         :3;
            U32 WM      :4;             // Conversion Data Water Mark
            U32 RES     :2;             // Data Resolution
            U32         :1;
            U32 TRIGMD  :1;             // Trigger Mode Select
            U32         :8;
            U32 CONT    :1;             // Continuous Mode Enable
            U32 WAIT    :1;             // Wait Mode
            U32 AUTOOFF :1;             // Auto-off Mode
            U32 DISCEN  :1;             // Discontinuous Mode Enable
            U32 SEQLEN  :3;             // Sequence Length
            U32         :3;
            U32 OVRMD   :1;             // Overrun Management Mode
            U32         :1;
        } B;
    } CFG0; // Configuration 0 Register (Offset: 0x0c; Reset: 0x07000010)

    union {
        U32 R;
        struct {
            U32 STCNT :8;               // ADC Startup Counter
            U32 PRS   :4;               // Function Clock Prescaler
            U32       :20;
        } B;
    } CFG1; // Configuration 1 Register (Offset: 0x10; Reset: 0x000002A0)

    union {
        U32 R;
        struct {
            U32 SMP :8;                 // Sampling Time Selection
            U32     :24;
        } B;
    } SMP; // Sampling Register (SMP) (Offset: 0x14; Reset: 0x00000002)

    union {
        U32 R;
        struct {
            U32 WDCHSEL :5;             // Watchdog Channel Select
            U32         :1;
            U32 WDSGL   :1;             // Apply the Watchdog on a Single Channel
            U32 WDEN    :1;             // Watchdog Enable
            U32         :24;
        } B;
    } WDCTRL; // Watchdog Control Register (Offset: 0x18; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 LOW  :12;               // Watchdog Lower Threshold
            U32      :4;
            U32 HIGH :12;               // Watchdog Higher Threshold
            U32      :3;
            U32 THMD :1;                // Watchdog Threshold Effective Mode
        } B;
    } WDTH; // Watchdog Threshold Register (Offset: 0x1c; Reset: 0x0FFF0000)

    U32 ADC_Reserved0[3U];

    union {
        U8 R;
        struct {
            U8 CHSEL :5;                // Conversion Channel Select
            U8       :3;
        } B;
    } CHSEL[8U]; // Channel Configure 0 Register (Offset: 0x2c-33; Reset: 0x00)

    U32 ADC_Reserved1[6U];

    union {
        U32 R;
        struct {
            U32 DATA :16;               // Converted Data
            U32 CHID :5;                // Channel ID
            U32      :11;
        } B;
    } FIFO; // FIFO Access Register (Offset: 0x4c; Reset: see descr.)

} ADC_tag; // end of ADC_tag



//**************************************************************************************************
//! Chip Integration Module (CIM) memory map
//**************************************************************************************************
typedef volatile struct CIM_struct {
    union {
        U32 R;
        struct {
            U32 WICENREQ       :1;      // Enable WIC to wakeup low power mode
            U32 NMIEN          :1;      // Non-mask Interrupt Enable
            U32 LOCKUPEN       :1;      // CPU Lockup Reset Enable
            U32                :5;
            U32 ACMP0_TRIG_SEL :2;      // ACMP0 Trigger Select
            U32                :6;
            U32 ADC0_TRIG_SEL  :2;      // ADC0 Trigger Select
            U32 ADC1_TRIG_SEL  :2;      // ADC1 Trigger Select
            U32                :12;
        } B;
    } CTRL; // CIM control register (Offset: 0x00; Reset: 0x0000.0001)

    U32 CIM_Reserved0[3U];

    union {
        U32 R;
        struct {
            U32 FPIOCIE :1;             // FPU Invalid Operation Interrupt Enable
            U32 FPDZCIE :1;             // FPU Divide-by-Zero Interrupt Enable
            U32 FPUFCIE :1;             // CPU FPU Underflow Interrupt Enable
            U32 FPOFCIE :1;             // FPU Overflow Interrupt Enable
            U32 FPIDCIE :1;             // FPU Input Denormal Interrupt Enable
            U32 FPIXCIE :1;             // FPU Inexact Interrupt Enable
            U32         :26;
        } B;
    } FPUIE; // FPU Interrupt Enable Register (Offset: 0x10; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 SWT    :1;              // Generate software trigger enable
            U32 SWTCNT :7;              // Software Trigger Count Register
            U32        :24;
        } B;
    } SWTRIG; // Software Trigger Register (Offset: 0x14; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 ETMR0_EXTCLK_SEL :2;    // eTMR0 External Clock Select
            U32 ETMR1_EXTCLK_SEL :2;    // eTMR1 External Clock Select
            U32 ETMR2_EXTCLK_SEL :2;    // eTMR2 External Clock Select
            U32 ETMR3_EXTCLK_SEL :2;    // eTMR3 External Clock Select
            U32 ETMR4_EXTCLK_SEL :2;    // eTMR4 External Clock Select
            U32 ETMR5_EXTCLK_SEL :2;    // eTMR5 External Clock Select
            U32                  :4;
            U32 ETMR0_FAULT_SEL  :3;    // eTMR0 Fault Select
            U32                  :1;
            U32 ETMR1_FAULT_SEL  :3;    // eTMR1 Fault Select
            U32                  :1;
            U32 ETMR2_FAULT_SEL  :3;    // eTMR2 Fault Select
            U32                  :1;
            U32 ETMR3_FAULT_SEL  :3;    // eTMR3 Fault Select
            U32                  :1;
        } B;
    } ETMROPT0; // Option register 0 (Offset: 0x18; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 ETMR0SS1C       :1;     // eTMR0 Synchronize Source 1 Control
            U32 ETMR1SS1C       :1;     // eTMR1 Synchronize Source 1 Control
            U32 ETMR2SS1C       :1;     // eTMR2 Synchronize Source 1 Control
            U32 ETMR3SS1C       :1;     // eTMR3 Synchronize Source 1 Control
            U32 ETMR4SS1C       :1;     // eTMR4 Synchronize Source 1 Control
            U32 ETMR5SS1C       :1;     // eTMR5 Synchronize Source 1 Control
            U32                 :2;
            U32 ETMR1CH0SEL     :1;     // eTMR1 Channel 0 Select
            U32                 :1;
            U32 ETMR2CH0SEL     :1;     // eTMR2 Channel 0 Select
            U32                 :1;
            U32 ETMR2CH1SEL     :1;     // eTMR2 Channel 1 Select
            U32                 :1;
            U32 ETMR_GTBE_SEL   :1;     // eTMR GTB split enable/disable bit
            U32                 :1;
            U32 ETMR0_CH0OUTSEL :1;     // Select modulation with eTMR1_CH0 for eTMR0 channel 0
            U32 ETMR0_CH1OUTSEL :1;     // Select modulation with eTMR1_CH1 for eTMR0 channel 1
            U32 ETMR0_CH2OUTSEL :1;     // Select modulation with eTMR1_CH2 for eTMR0 channel 2
            U32 ETMR0_CH3OUTSEL :1;     // Select modulation with eTMR1_CH3 for eTMR0 channel 3
            U32 ETMR0_CH4OUTSEL :1;     // Select modulation with eTMR1_CH4 for eTMR0 channel 4
            U32 ETMR0_CH5OUTSEL :1;     // Select modulation with eTMR1_CH5 for eTMR0 channel 5
            U32 ETMR0_CH6OUTSEL :1;     // Select modulation with eTMR1_CH6 for eTMR0 channel 6
            U32 ETMR0_CH7OUTSEL :1;     // Select modulation with eTMR1_CH7 for eTMR0 channel 7
            U32 ETMR3_CH0OUTSEL :1;     // Select modulation with eTMR3_CH0 for eTMR2 channel 0
            U32 ETMR3_CH1OUTSEL :1;     // Select modulation with eTMR3_CH1 for eTMR2 channel 1
            U32 ETMR3_CH2OUTSEL :1;     // Select modulation with eTMR3_CH2 for eTMR2 channel 2
            U32 ETMR3_CH3OUTSEL :1;     // Select modulation with eTMR3_CH3 for eTMR2 channel 3
            U32 ETMR3_CH4OUTSEL :1;     // Select modulation with eTMR3_CH4 for eTMR2 channel 4
            U32 ETMR3_CH5OUTSEL :1;     // Select modulation with eTMR3_CH5 for eTMR2 channel 5
            U32 ETMR3_CH6OUTSEL :1;     // Select modulation with eTMR3_CH6 for eTMR2 channel 6
            U32 ETMR3_CH7OUTSEL :1;     // Select modulation with eTMR3_CH7 for eTMR2 channel 7
        } B;
    } ETMROPT1; // Option register 1 (Offset: 0x1C; Reset: 0x0000.0000)

    U32 CIM_Reserved1[32U];

    union {
        U32 R;
        struct {
            U32 MINVER   :4;            // Minor Version Information
            U32 MAJVER   :4;            // Major Version Information
            U32          :4;
            U32 FAB      :4;
            U32 SUBFAMID :8;            // Product sub family information.
            U32 GENID    :4;            // Product generation information
            U32 FAMID    :4;            // Product family information
        } B;
    } DIEINFO; // Die Information Register (Offset: 0x40; Reset: 0x0114.0000)

    union {
        U32 R;
        struct {
            U32                :8;
            U32 PFLASHS        :4;      // Program flash size information
            U32 DFLASHS        :4;      // Data flash size information
            U32 SRAMS          :4;      // Sram size information
            U32 PKGS           :4;      // Package size
            U32 FLEXCAN0_FD_EN :1;      // FlexCAN0 FD Feature Enable
            U32 FLEXCAN1_FD_EN :1;      // FlexCAN2 FD Feature Enable
            U32 FLEXCAN2_FD_EN :1;      // FlexCAN3 FD Feature Enable
            U32 FLEXCAN3_FD_EN :1;      // FlexCAN4 FD Feature Enable
            U32 FLEXCAN4_FD_EN :1;      // FlexCAN5 FD Feature Enable
            U32 FLEXCAN5_FD_EN :1;      // FlexCAN6 FD Feature Enable
            U32                :2;
        } B;
    } CHIPINFO; // CHIPINFO Register (Offset: 0x44; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 UID0 :32;               // Unique identification for the chip
        } B;
    } UID0; // UID0 Register (Offset: 0x48; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 UID1 :32;               // Unique identification for the chip
        } B;
    } UID1; // UID0 Register (Offset: 0x4C; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 UID2 :32;               // Unique identification for the chip
        } B;
    } UID2; // UID2 Register (Offset: 0x50; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 UID3 :32;               // Unique identification for the chip
        } B;
    } UID3; // UID3 Register (Offset: 0x54; Reset: 0x0000.0000)

} CIM_tag; // end of CIM_tag



//**************************************************************************************************
//! Cyclic Redundancy Check (CRC) memory map
//**************************************************************************************************
typedef volatile struct CRC_struct {
    union {
        U32 R;
        struct {
            U32 MODE     :2;            // CRC Mode
            U32          :2;
            U32 SWAP_IN  :1;            // Swap Input
            U32 SWAP_OUT :1;            // Swap Output
            U32 INV_OUT  :1;            // Invert Output
            U32          :25;
        } B;
    } CTRL; // Control Register (Offset: 0x00; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 SEED :32;               // Initial Seed
        } B;
    } INIT; // Initial Seed Register (Offset: 0x04; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 DATA :32;               // CRC Data Input
        } DATA_IN32; // Data in 32 bits

        struct {
            U16 DATA :16;               // CRC Data Input
        } DATA_IN16; // Data in 16 bits

        struct {
            U8 DATA :8;                 // CRC Data Input
        } DATA_IN8; // Data in 8 bits
    } DATA; // Data Register (Offset: 0x08; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 RESULT :32;             // CRC Result
        } B;
    } RESULT; // Result Register (Offset: 0x0c; Reset: 0x00000000)

} CRC_tag; // end of CRC_tag



//**************************************************************************************************
//! Direct memory access (DMA) memory map
//**************************************************************************************************
typedef volatile struct DMA_struct {
    union {
        U32 R;
        struct {
            U32 STACH  :1;              // Start All DMA Channel
            U32 CLRAD  :1;              // Clear All DMA Done
            U32        :8;
            U32 LOEN   :1;              // Loop Offset Enable
            U32        :8;
            U32 CX     :1;              // Cancel DMA Transfer
            U32        :4;
            U32 ACTCH  :4;              // DMA Active Channel Shows current DMA active channel
            U32        :3;
            U32 ACTIVE :1;              // DMA Active Shows current DMA active state
        } B;
    } CTRL; // Control register (Offset: 0x00; Reset: 0x00003000)

    union {
        U32 R;
        struct {
            U32 CH :16;                 // DMA Channel Trigger Loop Done Interrupt Flag
            U32    :16;
        } B;
    } CHTLDIF; // Channel Trigger Loop Done Interrupt Flag Register (Offset: 0x04; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CH :16;                 // DMA Channel Trigger Loop Half Done Interrupt Flag
            U32    :16;
        } B;
    } CHTLHDIF; // Channel Trigger Loop Done Interrupt Flag Register (Offset: 0x08; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CH :16;                 // DMA Channel Error Interrupt Flag
            U32    :16;
        } B;
    } CHEIF; // Channel Error Interrupt Flag Register (Offset: 0x0C; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CH :16;                 // DMA Channel Error Interrupt Enable
            U32    :16;
        } B;
    } CHEIE; // Channel Error Interrupt Enable Register (Offset: 0x10; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 ECH   :4;               // Error Channel Index
            U32       :4;
            U32 DBE   :1;               // Destination Bus Error
            U32 SBE   :1;               // Source Bus error
            U32 RLDE  :1;               // Configuration RAM Reload Error
            U32 BTCE  :1;               // Byte/Trigger Count Configuration Error
            U32 DOE   :1;               // Destination Offset Error
            U32 DAE   :1;               // Destination Address Error
            U32 SOE   :1;               // Source Offset Error
            U32 SAE   :1;               // Source Address Error
            U32       :2;
            U32 ECX   :1;               // Error Cancel Transfer
            U32       :12;
            U32 VALID :1;               // DMA Configuration Valid
        } B;
    } ERS; // Error Status Register (Offset: 0x14; Reset: 0x00003000)

    union {
        U32 R;
        struct {
            U32 CH :16;                 // DMA Channel Request Enable
            U32    :16;
        } B;
    } REQEN; // Hardware Request Enable Register (Offset: 0x18; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CH :16;                 // DMA Channel Request Status
            U32    :16;
        } B;
    } REQS; // Request Status Register (Offset: 0x1C; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CH :16;                 // DMA Channel Start
            U32    :16;
        } B;
    } START; // Channel Start Register (Offset: 0x20; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CH :16;                 // DMA Channel Done
            U32    :16;
        } B;
    } DONE; // Channel DONE Register (Offset: 0x24; Reset: 0x00000000)

    U32 DMA_Reserved0[6U];

    union {
        U8 R;
        struct {
            U8 CH :7;                   // DMA Hardware Channel
            U8    :1;
        } B;
    } CHMUX[16U]; // Channel Mux Register (Offset: 0x40; Reset: 0x00)

    U32 DMA_Reserved1[236U];

    struct {
        union {
            U32 R;
            struct {
                U32 SADDR :32;          // Source address of DMA transfer.
            } B;
        } SADDR; // Source Address Register (Offset: 0x400; Reset: 0x00000000)

        union {
            S16 R;
            struct {
                S16 SOFF :16;           // Source Address Offset
            } B;
        } SOFF; // Source Address Offset Register (Offset: 0x404; Reset: 0x00000000)

        union {
            U16 R;
            struct {
                U16 DSIZE :3;           // Destination Data Transfer Size
                S16 DMOD  :5;           // Destination Address Modulo
                U16 SSIZE :3;           // Source Data Transfer Size
                S16 SMOD  :5;           // Source Address Modulo Value
            } B;
        } TCR; // Transfer Control Register (Offset: 0x406; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 BCNT :32;           // Transfer Loop Byte Count
            } BCNT; // Source Address Register (Offset: 0x408; Reset: 0x00000000)
            struct {
                U32 BCNT :30;           // Byte Transfer Count
                U32 DLOE :1;            // Destination Minor Loop Offset Enable
                U32 SLOE :1;            // Source Loop Offset Enable
            } LODIS; // Transfer Loop Offset Disable Mapping Register (Offset: 0x408; Reset: 0x00000000)
            struct {
                U32 BCNT   :10;         // Byte Transfer Count
                S32 OFFSET :20;         // Loop Offset
                U32 DLOE   :1;          // Destination Minor Loop Offset Enable
                U32 SLOE   :1;          // Source Loop Offset Enable
            } LOEN; // Transfer Loop Offset Enable Mapping Register (Offset: 0x408; Reset: 0x00000000)
        } BCNT; // (Offset: 0x408; Reset: 0x00000000)

        union {
            S32 R;
            struct {
                S32 STLOFF :32;         // Source address will add offset value
            } B;
        } STO; // Source Address Register (Offset: 0x40C; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 DADDR :32;          // Destination Address
            } B;
        } DADDR; // Destination Address Register (Offset: 0x410; Reset: 0x00000000)

        union {
            S16 R;
            struct {
                S16 DOFF :16;           // Destination Address Offset
            } B;
        } DOFF; // Source Address Offset Register (Offset: 0x414; Reset: 0x0000)

        union {
            U16 R;
            struct {
                U16 TCNT :15;           // Trigger Count
                U16 LKEN :1;            // Link Enable
            } LKDIS; // Trigger Count with Link Disable Register (Offset: 0x416; Reset: 0x0000)
            struct {
                U16 TCNT :9;            // Trigger Count
                U16 LKCH :4;            // Link Channel
                U16      :2;
                U16 LKEN :1;            // Link Enable
            } LKEN; // Trigger Count with Link Enable Register (Offset: 0x416; Reset: 0x0000)
        } TCNT; // (Offset: 0x416; Reset: 0x0000)

        union {
            U32 R;
            struct {
                S32 OFFSET :32;         // Destination Trigger Loop Offset
            } DTO; // Destination Trigger Loop Offset Register (Offset: 0x418; Reset: 0x00000000)
            struct {
                U32 ADDR :32;           // RAM Reload Address
            } RLD; // RAM Reload Address Register (Offset: 0x418; Reset: 0x00000000)
        } DTO_RLD; // (Offset: 0x418; Reset: 0x00000000)

        union {
            U16 R;
            struct {
                U16 START   :1;         // Channel Start
                U16 DONE    :1;         // Trigger Loop Done
                U16 ACTIVE  :1;         // Channel Active
                U16 DREQ    :1;         // Disable Request
                U16 BWC     :2;         // Bandwidth Control
                U16 RLDEN   :1;         // RAM Reload Enable
                U16 TLKEN   :1;         // Trigger Loop Link Enable
                U16 TLKCH   :4;         // Trigger Loop Link Channel Index
                U16         :1;
                U16 LOOPINT :1;         // Loop Done Interrupt Enable
                U16 THDINT  :1;         // Trigger Half Done Interrupt Enable
                U16 TDINT   :1;         // Enable an interrupt when channel all trigger loop done
            } B;
        } CSR; // Control and Status Register (Offset: 0x41C; Reset: 0x0000)

        union {
            U16 R;
            struct {
                U16 RV :16;             // Reload Value
            } B;
        } TCNTRV; // TCNT Reload Value Register (Offset: 0x41E; Reset: 0x0000)
    } CTS[16U];

} DMA_tag; // end of DMA_tag



//**************************************************************************************************
//! Embedded FLASH Module (EFM) memory map
//**************************************************************************************************
typedef volatile struct EFM_struct {
    union {
        U32 R;
        struct {
            U32 DONEIE       :1;        // Command Done Interrupt Enable
            U32 RECOVERRIE   :1;        // Recovery Error Interrupt Enable
            U32 UNRECOVERRIE :1;        // when UNRECOVERR interrupt will be generated
            U32 ACCERRIE     :1;        // Access Error Interrupt Enable
            U32              :4;
            U32 RWS          :4;        // Read Wait State
            U32              :3;
            U32 PREFETCH_EN  :1;        // Prefetch Enable
            U32 PRESCALER    :8;        // PRESCALER = core frequency / 2
            U32 AES_KEY_SEL  :4;        // AES Key Selection
            U32              :3;
            U32 DPD_EN       :1;        // Deep Power Down Enable
        } B;
    } CTRL; // Control register (Offset: 0x00; Reset: 0x00180300)

    union {
        U32 R;
        struct {
            U32 DONE          :1;       // Current command is completed
            U32 RECOVERR      :1;       // Recovery Error Status
            U32 UNRECOVERR    :1;       // Unrecovery Error Status
            U32 ACCERR        :1;       // Access Error Status
            U32               :2;
            U32 FAIL          :1;       // Command FAIL Status
            U32 IDLE          :1;       // Command IDLE Status
            U32               :5;
            U32 CUS_KEY_MATCH :1;       // Customer Key Match Status
            U32               :1;
            U32 BOOT_INFO     :1;       // PRESCALER = core frequency / 2
            U32               :16;
        } B;
    } STS; // Status register (Offset: 0x04; Reset: 0x00000080)

    union {
        U32 R;
        struct {
            U32 CMD :8;                 // Command Control
            U32     :24;
        } B;
    } CMD; // Command register (Offset: 0x08; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 TPROG    :16;           // Timing of Program
            U32 TPREPROG :16;           // Timing of Pre-program
        } B;
    } TIMING1; // Timing 1 Control register (Offset: 0x010; Reset: 0x00060012)

    union {
        U32 R;
        struct {
            U32 TERASE   :16;           // Timing of Program
            U32 TPREPROG :16;           // Timing of Pre-program
        } B;
    } TIMING2; // Timing 2 Control register (Offset: 0x014; Reset: 0x06407D00)

    union {
        U32 R;
        struct {
            U32 NVR_ADDR :10;           // NVR Access Address
            U32          :22;
        } B;
    } NVR_ADDR; // NVR Address Control register (Offset: 0x018; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 EFM_NVR_DATA :10;       // NVR Access DATA
            U32              :22;
        } B;
    } NVR_DATA[2U]; // NVR Data Control register (Offset: 0x01C; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 ADDR_PROT :32;          // Address protect
        } B;
    } ADDR_PROT[3U]; // Address protect register (Offset: 0x024; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 ECC_ERR_ADDR :32;       // ECC Error Address
        } B;
    } ERR_ADDR; // Error Address register (Offset: 0x030; Reset: 0x00000000)

    U32 EFM_Reserved0[115U];

    union {
        U32 R;
        struct {
            U32 CMD_UNLOCK_KEY :32;     // EFM Command Unlock Key (0xfd9573f5)
        } B;
    } CMD_UNLOCK; // Unlock Address protect register (Offset: 0x200; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CUS_KEY :24;            // EFM Customer Key
            U32         :8;             // Software Debugger Disable
        } B;
    } CUS_KEYR; // Customer Key Register (Offset: 0x204; Reset: 0x00000000)

    U32 EFM_Reserved1[130U];

    union {
        U32 R;
        struct {
            U32 ECC_DISABLE :1;         // ECC Disable
            U32 SWD_DISABLE :1;         // Software Debugger Disable
            U32             :30;
        } B;
    } CTRL_OVRD; // Control Override Register (Offset: 0x300; Reset: 0x00000000)

    U32 EFM_Reserved2[1U];

    union {
        U32 R;
        struct {
            U32 CFG_KEY :24;            // EFM Config Key
            U32         :8;
        } B;
    } CFG_KEY; // Config Key Register (Offset: 0x308; Reset: 0x00000000)

} EFM_tag; // end of EFM_tag



//**************************************************************************************************
//! ECC Management Unit (EMU) memory map
//**************************************************************************************************
typedef volatile struct EMU_struct {
    union {
        U32 R;
        struct {
            U32 GEN :1;                 // Global Error Injection Enable
            U32     :31;
        } B;
    } EIGCR; // Error Injection Global Control Register (Offset: 0x00; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CH0EN :1;               // Channel 0 Error Injection Enable
            U32 CH1EN :1;               // Channel 1 Error Injection Enable
            U32       :30;
        } B;
    } EICHCR; // Error Injection Channel Control Register (Offset: 0x04; Reset: 0x00000000)

    U32 EMU_Reserved0[2U];

    struct {
        union {
            U32 R;
            struct {
                U32 ADDR :32;           // Channel n Error Injection Address
            } B;
        } ADDR; // Channel Error Injection Address Register (Offset: 0x10-20; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 CHKBIT :7;          // Error Injection CheckBit Mask
                U32        :25;
            } B;
        } HKBIT;// Error Injection CheckBit Mask Register (Offset: 0x14-24; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 DATA :32;           // Data Mask
            } B;
        } DATA; // Error injection DATA Mask Register (Offset: 0x18-28; Reset: 0x00000000)

        U32 EMU_Reserved1[1U];

    } EICHD[2U];

    U32 EMU_Reserved2[52U];

    union {
        U32 R;
        struct {
            U32 SCIE :2;                // Single Correctable Interrupt Enable
            U32      :14;
            U32 NCIE :2;                // Non-Correctable Interrupt Enable
            U32      :14;
        } B;
    } ERIE; // Error Report Interrupt Enable Register (Offset: 0x100; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 SCIF :2;                // Single Correctable Interrupt Flag
            U32      :14;
            U32 NCIF :2;                // Non-Correctable Interrupt Flag
            U32      :14;
        } B;
    } ERIF; // Error Report Interrupt Flag Register (Offset: 0x104; Reset: 0x00000000)

    struct {
        union {
            U32 R;
            struct {
                U32 ADDR :32;           // Error Report Address n
            } B;
        } ADDR; // Error Report Address Register (Offset: 0x110-120; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 SYNDROME :7;        // Error Report Syndrome n
                U32          :25;
            } B;
        } SYND; // Error Report Syndrome Register (Offset: 0x114-124; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 CNT :7;             // SRAM_L/U Correctable Error Count
                U32     :25;
            } B;
        } CNT; // Correctable ErrorCount Register (Offset: 0x118-128; Reset: 0x00000000)

        U32 EMU_Reserved3[1U];

    } ERINFO[2U];

} EMU_tag; // end of EMU_tag



//**************************************************************************************************
//! Enhanced Timer (ETMR) memory map
//**************************************************************************************************
typedef volatile struct ETMR_struct {
    union {
        U32 R;
        struct {
            U32 CH0F   :1;              // Channel 0 Flag
            U32 CH1F   :1;              // Channel 1 Flag
            U32 CH2F   :1;              // Channel 2 Flag
            U32 CH3F   :1;              // Channel 3 Flag
            U32 CH4F   :1;              // Channel 4 Flag
            U32 CH5F   :1;              // Channel 5 Flag
            U32 CH6F   :1;              // Channel 6 Flag
            U32 CH7F   :1;              // Channel 7 Flag
            U32 F0F    :1;              // Fault 0 Flag
            U32 F1F    :1;              // Fault 1 Flag
            U32 F2F    :1;              // Fault 2 Flag
            U32 F3F    :1;              // Fault 3 Flag
            U32 RF     :1;              // Reload Flag
            U32 TOF    :1;              // Timer Overflow Flag
            U32 QDTOF  :1;              // Quadrature Decoder Timer Overflow Flag
            U32 QDDIR  :1;              // Quadrature Decoder Direction
            U32 CH0PPF :1;              // Channel 0 Positive Pulse Ready Flag
            U32 CH1PPF :1;              // Channel 1 Positive Pulse Ready Flag
            U32 CH2PPF :1;              // Channel 2 Positive Pulse Ready Flag
            U32 CH3PPF :1;              // Channel 3 Positive Pulse Ready Flag
            U32 CH4PPF :1;              // Channel 4 Positive Pulse Ready Flag
            U32 CH5PPF :1;              // Channel 5 Positive Pulse Ready Flag
            U32 CH6PPF :1;              // Channel 6 Positive Pulse Ready Flag
            U32 CH7PPF :1;              // Channel 7 Positive Pulse Ready Flag
            U32 CH0NPF :1;              // Channel 0 Negative Pulse Ready Flag
            U32 CH1NPF :1;              // Channel 1 Negative Pulse Ready Flag
            U32 CH2NPF :1;              // Channel 2 Negative Pulse Ready Flag
            U32 CH3NPF :1;              // Channel 3 Negative Pulse Ready Flag
            U32 CH4NPF :1;              // Channel 4 Negative Pulse Ready Flag
            U32 CH5NPF :1;              // Channel 5 Negative Pulse Ready Flag
            U32 CH6NPF :1;              // Channel 6 Negative Pulse Ready Flag
            U32 CH7NPF :1;              // Channel 7 Negative Pulse Ready Flag
        } B;
    } STS; // Status Register (Offset: 0x00; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CH0IO :1;               // Channel 0 I/O Status
            U32 CH1IO :1;               // Channel 1 I/O Status
            U32 CH2IO :1;               // Channel 2 I/O Status
            U32 CH3IO :1;               // Channel 3 I/O Status
            U32 CH4IO :1;               // Channel 4 I/O Status
            U32 CH5IO :1;               // Channel 5 I/O Status
            U32 CH6IO :1;               // Channel 6 I/O Status
            U32 CH7IO :1;               // Channel 7 I/O Status
            U32       :8;
            U32 F0    :1;               // Fault 0 Status
            U32 F1    :1;               // Fault 1 Status
            U32 F2    :1;               // Fault 2 Status
            U32 F3    :1;               // Fault 3 Status
            U32       :4;
            U32 PHA   :1;               // Phase A Status
            U32 PHB   :1;               // Phase B Status
            U32       :6;
        } B;
    } TOSTS; // Input/Output Status Register (Offset: 0x04; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CNT :32;                // Counter Initial or Value Register
        } B;
    } CNT; // CounterValue Register (Offset: 0x08; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 QDCNT :16;              // Quadrature Decoder Counter Value
            U32       :16;
        } B;
    } QDCNT; // Quadrature Decoder Counter Value Register (Offset: 0x0c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 EN      :1;             // eTMR Enable
            U32 GLOBEN  :1;             // Global Enable
            U32 DITHMD  :2;             // Dithering Mode
            U32 CLKSRC  :1;             // Clock Source
            U32         :3;
            U32 CLKPRS  :7;             // Clock Prescaler
            U32 DBGDIS  :1;             // Debug Mode Disabled
            U32 DBSW01  :1;             // Double Switch Channel 0 and 1
            U32 DBSW23  :1;             // Double Switch Channel 2 and 3
            U32 DBSW45  :1;             // Double Switch Channel 4 and 5
            U32 DBSW67  :1;             // Double Switch Channel 6 and 7
            U32         :4;
            U32 COMPL01 :1;             // Complementary Mode enable for channel 0 and channel 1
            U32 COMPL23 :1;             // Complementary Mode enable for channel 2 and channel 3
            U32 COMPL45 :1;             // Complementary Mode enable for channel 4 and channel 5
            U32 COMPL67 :1;             // Complementary Mode enable for channel 6 and channel 7
            U32         :3;
            U32 CAPTST  :1;             // Capture Test
        } B;
    } CTRL; // Control Register (Offset: 0x10; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 LDOK    :1;             // Registers Loading OK
            U32 CLDOK   :1;             // Clear LDOK
            U32 CNTINIT :1;             // Counter Initial Value Control
            U32         :1;
            U32 TRIGS0  :2;             // Trigger Source 0
            U32 REGLD   :2;             // Registers Loading Opportunity
            U32 TRIGS1  :2;             // Trigger Source 1
            U32 CNTLD   :2;             // Counter Loading Opportunity
            U32 TRIGS2  :2;             // Trigger Source 2
            U32 MASKLD  :2;             // CHMASK Loading Opportunity
            U32 SWTRIG  :1;             // Software Trigger
            U32 TRIG0EN :1;             // Hardware Trigger 0 Enable
            U32 TRIG1EN :1;             // Hardware Trigger 1 Enable
            U32 TRIG2EN :1;             // Hardware Trigger 2 Enable
            U32         :4;
            U32 LDFRQ   :4;             // Registers Loading Frequency
            U32         :3;
            U32 GLOB    :1;             // Global Base
        } B;
    } SYNC; // Synchronous Register (Offset: 0x14; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 INITTEN  :1;            // INIT Matching Trigger Enable
            U32 MIDTEN   :1;            // MID Matching Trigger Enable
            U32 MODTEN   :1;            // MOD Matching Trigger Enable
            U32          :1;
            U32 TSRC     :1;            // Trigger Source
            U32          :3;
            U32 PULSESRC :3;            // Pulse-out Source
            U32          :1;
            U32 TFRQ     :4;            // Trigger Frequency
            U32 TWD      :8;            // Output Trigger Width
            U32          :8;
        } B;
    } OTRIG; // Output Trigger Register (Offset: 0x18; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CH0IE  :1;              // Channel 0 Interrupt Enable
            U32 CH1IE  :1;              // Channel 1 Interrupt Enable
            U32 CH2IE  :1;              // Channel 2 Interrupt Enable
            U32 CH3IE  :1;              // Channel 3 Interrupt Enable
            U32 CH4IE  :1;              // Channel 4 Interrupt Enable
            U32 CH5IE  :1;              // Channel 5 Interrupt Enable
            U32 CH6IE  :1;              // Channel 6 Interrupt Enable
            U32 CH7IE  :1;              // Channel 7 Interrupt Enable
            U32 FIE    :1;              // Fault Interrupt Enable
            U32        :4;
            U32 TOIE   :1;              // Timer Overflow Interrupt Enable
            U32 QDTOIE :1;              // Quadrature Decoder Timer Overflow Interrupt Enable
            U32        :17;
        } B;
    } INTE; // Interrupt Enable Register (Offset: 0x1c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CH0INIT :1;             // Channel 0 Output Initial Value
            U32 CH1INIT :1;             // Channel 1 Output Initial Value
            U32 CH2INIT :1;             // Channel 2 Output Initial Value
            U32 CH3INIT :1;             // Channel 3 Output Initial Value
            U32 CH4INIT :1;             // Channel 4 Output Initial Value
            U32 CH5INIT :1;             // Channel 5 Output Initial Value
            U32 CH6INIT :1;             // Channel 6 Output Initial Value
            U32 CH7INIT :1;             // Channel 7 Output Initial Value
            U32         :24;
        } B;
    } CHINIT; // Channel Output Initial Value Register (Offset: 0x20; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CH0SWV :1;              // Channel 0 Software Value
            U32 CH1SWV :1;              // Channel 1 Software Value
            U32 CH2SWV :1;              // Channel 2 Software Value
            U32 CH3SWV :1;              // Channel 3 Software Value
            U32 CH4SWV :1;              // Channel 4 Software Value
            U32 CH5SWV :1;              // Channel 5 Software Value
            U32 CH6SWV :1;              // Channel 6 Software Value
            U32 CH7SWV :1;              // Channel 7 Software Value
            U32        :24;
        } B;
    } CHSWV; // Channel Software Value Register (Offset: 0x24; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CH0M  :1;               // Channel 0 Output Mask
            U32 CH1M  :1;               // Channel 1 Output Mask
            U32 CH2M  :1;               // Channel 2 Output Mask
            U32 CH3M  :1;               // Channel 3 Output Mask
            U32 CH4M  :1;               // Channel 4 Output Mask
            U32 CH5M  :1;               // Channel 5 Output Mask
            U32 CH6M  :1;               // Channel 6 Output Mask
            U32 CH7M  :1;               // Channel 7 Output Mask
            U32       :8;
            U32 CH0MV :2;               // Channel 0 Output Mask Value
            U32 CH1MV :2;               // Channel 1 Output Mask Value
            U32 CH2MV :2;               // Channel 2 Output Mask Value
            U32 CH3MV :2;               // Channel 3 Output Mask Value
            U32 CH4MV :2;               // Channel 4 Output Mask Value
            U32 CH5MV :2;               // Channel 5 Output Mask Value
            U32 CH6MV :2;               // Channel 6 Output Mask Value
            U32 CH7MV :2;               // Channel 7 Output Mask Value
        } B;
    } CHMASK; // Channel Output Mask Value Register (Offset: 0x28; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CH0FV :2;               // Channel 0 Output Mask Value
            U32 CH1FV :2;               // Channel 1 Output Mask Value
            U32 CH2FV :2;               // Channel 2 Output Mask Value
            U32 CH3FV :2;               // Channel 3 Output Mask Value
            U32 CH4FV :2;               // Channel 4 Output Mask Value
            U32 CH5FV :2;               // Channel 5 Output Mask Value
            U32 CH6FV :2;               // Channel 6 Output Mask Value
            U32 CH7FV :2;               // Channel 7 Output Mask Value
            U32       :16;
        } B;
    } CHFV; // Channel Fault Value Register (Offset: 0x2c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 INIT :32;               // Counter Initial Value
        } B;
    } INIT; // Counter Initial Value Register (Offset: 0x30; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 MOD :32;                // Counter Modulus Value
        } B;
    } MOD; // Counter Modulus Value Register (Offset: 0x34; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 MODFRAC :5;             // Modulus Fractional Part
            U32         :3;
            U32 MODINT  :7;             // Modulus Integer Part
            U32         :17;
        } B;
    } DITHMOD; // Dithering MOD Register (Offset: 0x38; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 MID :32;                // Counter Middle Value
        } B;
    } MID; // Counter Middle Value Register (Offset: 0x3c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 QDEN     :1;            // Quadrature Decoder Enable
            U32          :3;
            U32 QDMODE   :2;            // Quadrature Decoder Mode
            U32          :6;
            U32 QDCLKPRS :3;            // Quadrature Decoder Clock Prescaler
            U32          :1;
            U32 PHAPOL   :1;            // Phase A Polarity
            U32 PHBPOL   :1;            // Phase B Polarity
            U32          :6;
            U32 QDFPER   :4;            // Quadrature Decoder Filter Sample Period
            U32 QDFCNT   :4;            // Quadrature Decoder Filter Sample Count
        } B;
    } QDCTRL; // Quadrature Decoder Control Register (Offset: 0x40; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 QDINIT :16;             // Quadrature Decoder Counter Initial value
            U32        :16;
        } B;
    } QDINIT; // Quadrature Decoder Counter Initial Value Register (Offset: 0x44; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 QDMOD :16;              // Quadrature Decoder Counter Modulus value
            U32       :16;
        } B;
    } QDMOD; // Quadrature Decoder Modulus Register (Offset: 0x48; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 F0EN    :1;             // Fault 0 Enable
            U32 F1EN    :1;             // Fault 1 Enable
            U32 F2EN    :1;             // Fault 2 Enable
            U32 F3EN    :1;             // Fault 3 Enable
            U32         :4;
            U32 F0POL   :1;             // Fault 0 Input Polarity
            U32 F1POL   :1;             // Fault 1 Input Polarity
            U32 F2POL   :1;             // Fault 2 Input Polarity
            U32 F3POL   :1;             // Fault 3 Input Polarity
            U32         :4;
            U32 FAUTO   :2;             // Fault Automatic Recovery Mode
            U32 RCVRY   :2;             // PWM Recovery
            U32 FCOMB   :1;             // Fault Combinational Logic
            U32 STRETCH :1;             // Fault Input Stretch
            U32         :2;
            U32 FFPER   :4;             // Fault Filter Sample Period
            U32 FFCNT   :4;             // Fault Filter Sample Count
        } B;
    } FAULT; // Fault Control Register (Offset: 0x4c; Reset: 0x00000000)

    struct {
        union {
            U32 R;
            struct {
                U32 CHMODE  :2;         // Channel Mode
                U32         :2;
                U32 CHINIT  :1;         // Channel Output Initialization
                U32 CHPOL   :1;         // Channel Output Polarity
                U32 VAL0TEN :1;         // VAL0 Trigger Enable
                U32 VAL1TEN :1;         // VAL1 Trigger Enable
                U32 PWMSRC  :2;         // PWM Source
                U32         :2;
                U32 VAL0CMP :2;         // VAL0 Compare Mode
                U32 VAL1CMP :2;         // VAL1 Compare Mode
                U32 CFPER   :4;         // Capture Filter Sample Period
                U32 CFCNT   :4;         // Capture Filter Sample Counter
                U32 CAPEDGE :2;         // Capture Edge
                U32         :2;
                U32 LDEN    :1;         // Registers Loading Enable
                U32         :1;
                U32 DMAEN   :1;         // DMA Enable
                U32         :1;
            } B;
        } CTRL; // Channel Control Register (Offset: 0x80-240; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 VAL0 :32;           // Value 0
            } B;
        } VAL0; // Value 0 Register (Offset: 0x84-244; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 VAL1 :32;           // Value 1
            } B;
        } VAL1; // Value 1 Register (Offset: 0x88-248; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 VAL1FRAC :5;        // Value 1 Fractional Part
                U32          :3;
                U32 VAL1INT  :7;        // Value 1 Integer Part
                U32          :17;
            } B;
        } DITHVAL1; // Dithering Value 1 Register (Offset: 0x8c-24c; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 DTVAL :16;          // Deadtime Value
                U32       :16;
            } B;
        } CH_DT; // Deadtime Register (Offset: 0x90-250; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 CVAL :32;           // Capture Value
            } B;
        } CVAL; // Capture Value Register (Offset: 0x94-254; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 PPCNTN :8;          // Positive Pulse Counter Periods Number
                U32        :24;
            } B;
        } PPCNTN; // Positive Pulse Timeout Flag Number Register (Offset: 0x98-258; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 PPCNTV :32;         // Positive Pulse Width Capture Value
            } B;
        } PPCNTV; // Positive Pulse Width Capture Value Register (Offset: 0x9c-25c; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 NPCNTN :8;          // Negative Pulse Counter Periods Number
                U32        :24;
            } B;
        } NPCNTN; // Negative Pulse Timeout Flag Number Register (Offset: 0xa0-260; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 NPCNTV :32;         // Negative Pulse Width Capture Value
            } B;
        } NPCNTV; // Negative Pulse Width Capture Value Register (Offset: 0xa4-264; Reset: 0x00000000)

        U32 ETMR_Reserved[6U];

    } CH[8U]; // 8 channels

} ETMR_tag; // end of ETMR_tag



//**************************************************************************************************
//! External Watchdog (EWDG) memory map
//**************************************************************************************************
typedef volatile struct EWDG_struct {
    union {
        U32 R;
        struct {
            U32 SERVICE :8;             // Service
            U32         :24;
        } B;
    } SERV; // Service Code Register (Offset: 0x00; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 COMPAREL :8;            // Low value of EWDG counter compare
            U32          :24;
        } B;
    } CMPL; // Compare Low Register (Offset: 0x04; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 COMPAREH :8;            // High value of EWDG counter compare
            U32          :24;
        } B;
    } CMPH; // Compare High Register (Offset: 0x08; Reset: 0x000000FF)

    union {
        U32 R;
        struct {
            U32 EN       :1;            // EWDG Enable
            U32 POLARITY :1;            // EWDG_IN Pin Polarity
            U32 INEN     :1;            // EWDG_IN Pin Enable
            U32 INTEN    :1;            // Interrupt Enable
            U32          :28;
        } B;
    } CTRL; // Control Register (Offset: 0x0c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 PRESCALER :8;           // Prescaler of clock
            U32           :8;
            U32 CLKSEL    :1;           // Clock select
            U32           :15;
        } B;
    } CLK_CTRL; // Clock Control Register (Offset: 0x10; Reset: 0x00000000)

} EWDG_tag; // end of EWDG_tag



//**************************************************************************************************
//! Flexible Controller Area Network (FlexCAN) memory map
//**************************************************************************************************
typedef volatile struct FLEXCAN_struct {
    union {
        U32 R;
        struct {
            U32 MAXMB   :7;             // Number of the Last Message Buffer
            U32         :1;
            U32 IDAM    :2;             // ID Acceptance Mode
            U32         :1;
            U32 FDEN    :1;             // CAN FD Operation Enable
            U32 AEN     :1;             // Abort Enable
            U32 LPRIOEN :1;             // Local Priority Enable
            U32 PNET_EN :1;             // Pretended Networking Enable
            U32 DMAEN   :1;             // DMA enable
            U32 IRMQ    :1;             // Indevidual Rx Masking And Queue Enable
            U32 SRXDIS  :1;             // Self Reception Disable
            U32 DOZE    :1;             // Doze Mode Enable
            U32 WAKSRC  :1;             // Wake Up Source
            U32 LPMACK  :1;             // Low-Power Mode Acknowledge
            U32 WRNEN   :1;             // Warning Interrupt Enable
            U32 SLFWAK  :1;             // Self wakeup
            U32 SUPV    :1;             // Supervisor Mode
            U32 FRZACK  :1;             // Freeze Mode Acknowledge
            U32 SOFTRST :1;             // FlexCAN software reset
            U32 WAKMSK  :1;             // FlexCAN wakeup Interrupt Mask
            U32 NOTRDY  :1;             // FlexCAN not ready
            U32 HALT    :1;             // Halt FlexCAN
            U32 RFEN    :1;             // legacy Rx FIFO Enable
            U32 FRZ     :1;             // Freeze Enable
            U32 MDIS    :1;             // Module Disable
        } B;
    } MCR; // Module Configuration Register (Offset: 0x0; Reset: 0xD890000F)

    union {
        U32 R;
        struct {
            U32 PROPSEG :3;             // Propagation Segment
            U32 LOM     :1;             // Listen Only Mode
            U32 LBUF    :1;             // Lowest Buffer Transmitted First
            U32 TSYN    :1;             // Timer Sync
            U32 BOFFREC :1;             // Bus Off Recovery
            U32 SMP     :1;             // CAN bit Sampling
            U32         :2;
            U32 RWRNMSK :1;             // Rx Warning Interrupt Mask
            U32 TWRNMSK :1;             // Tx Warning Interrupt Mask
            U32 LPB     :1;             // Loop Back Mode
            U32 CLKSRC  :1;             // CAN engine clock source
            U32 ERRMSK  :1;             // Error Interrupt Mask
            U32 BOFFMSK :1;             // Bus Off Interrupt Mask
            U32 PSEG2   :3;             // Phase Buffer Segment 2 = (PSEG2 +1) x Time-Quanta
            U32 PSEG1   :3;             // Phase Segment 1
            U32 RJW     :2;             // Resync Jump Width
            U32 PRESDIV :8;             // Prescaler Division Factor
        } B;
    } CTRL1; // Module Configuration Register 1 (Offset: 0x4; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 TIMER :16;              // Timer Value Contains the free-running counter value.
            U32       :16;
        } B;
    } TIMER; // Free Running Timer Register (Offset: 0x8; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 MG :32;                 // Rx Mailboxes Global Mask Register
        } B;
    } RXMGMASK; // Rx Mailboxes Global Mask Register (Offset: 0x10; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 RX14M :32;              // Rx 14 Mask Register
        } B;
    } RX14MASK; // Rx 14 Mask Register (Offset: 0x14; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 RX15M :32;              // Rx 15 Mask Register
        } B;
    } RX15MASK; // Rx 15 Mask Register (Offset: 0x18; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 TXERRCNT      :8;       // Transmit Error Counter
            U32 RXERRCNT      :8;       // Receive Error Counter
            U32 TXERRCNT_FAST :8;       // Transmit Error Counter for Fast Bits
            U32 RXERRCNT_FAST :8;       // Receive Error Counter for Fast Bits
        } B;
    } ECR; // Error Counter Register (Offset: 0x1c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 WAKINT       :1;        // Wakeup Interrupt
            U32 ERRINT       :1;        // Error Interrupt
            U32 BOFFINT      :1;        // Bus Off Interrupt
            U32 RX           :1;        // FlexCAN in Reception
            U32 FLTCONF      :2;        // FlexCAN Fault Confinement State
            U32 TX           :1;        // FlexCAN in Transmission
            U32 IDLE         :1;        // IDLE
            U32 RXWRN        :1;        // RX Error Warning
            U32 TXWRN        :1;        // TX Error Warning
            U32 STFERR       :1;        // Stuffing Error
            U32 FRMERR       :1;        // Form Error
            U32 CRCERR       :1;        // Cyclic Redundancy Check Error
            U32 ACKERR       :1;        // Acknowledge Error
            U32 BIT0ERR      :1;        // Bit 0 Error
            U32 BIT1ERR      :1;        // Bit 1 Error
            U32 RWRNINT      :1;        // RX Warning Interrupt Flag
            U32 TWRNINT      :1;        // TX Warning Interrupt Flag
            U32 SYNCH        :1;        // CAN Synchronous Status
            U32 BOFFDONEINT  :1;        // Bus off done interrupt
            U32 ERRINT_FAST  :1;        // Error Interrupt
            U32 ERROVR       :1;        // Error Overrun
            U32              :4;
            U32 STFERR_FAST  :1;        // Stuffing Error in the Data Phase of CAN FD Frames with BRS bit set
            U32 FRMERR_FAST  :1;        // Form Error in the Data Phase of CAN FD Frames with BRS bit set
            U32 CRCERR_FAST  :1;        // CRC Error in the Data Phase of CAN FD Frames with BRS bit set
            U32              :1;
            U32 BIT0ERR_FAST :1;        // Bit 0 Error in the Data Phase of CAN FD Frames with BRS bit set
            U32 BIT1ERR_FAST :1;        // Bit 1 Error in the Data Phase of CAN FD Frames with BRS bit set
        } B;
    } ESR1; // Error and status register (Offset: 0x20; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 BUF63TO32M :32;         // Buffer MB i Mask
        } B;
    } IMASK2; // Interrupt Mask 2 Register (Offset: 0x24; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 BUF31TO0M :32;          // Buffer MB i Mask
        } B;
    } IMASK1; // Interrupt Mask 1 Register (Offset: 0x28; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 BUF63TO32I :32;         // Buffer MB i Interrupt
        } B;
    } IFLAG2; // Interrupt Flag 2 Register (Offset: 0x2c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 BUF31TO8I :24;          // Buffer MB i Interrupt
            U32 BUF0I     :1;           // Buffer MB0 Interrupt or Clear FIFO bit
            U32 BUF4TO1I  :4;           // Buffer MB Interrupt or Reserved
            U32 BUF5I     :1;           // Buffer MB5 Interrupt or Frames Available in Legacy Rx FIFO
            U32 BUF6I     :1;           // Buffer MB6 Interrupt or Legacy Rx FIFO Warning
            U32 BUF7I     :1;           // Buffer MB7 Interrupt or Legacy Rx FIFO Overflow.
        } B;
    } IFLAG1;  // Interrupt Flag 1 Register (Offset: 0x30; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32             :6;
            U32 TSTAMPCAP   :2;         // Time Stamp Capture Point
            U32 MBTSBASE    :2;         // Message Buffer Time Stamp Base
            U32             :1;
            U32 EDFLTDIS    :1;         // Edge Filter Disable
            U32 ISOCANFDEN  :1;         // ISO CAN FD Enable
            U32             :1;
            U32 PREXCEN     :1;         // Protocol Exception Enable
            U32 TIMER_SRC   :1;         // Timer Source
            U32 EACEN       :1;         // Entire Frame Arbitration Field Comparison Enable For Rx Mailboxes
            U32 RRS         :1;         // Remote Request Storing
            U32 MRP         :1;         // Mailboxes Reception Priority
            U32 TASD        :5;         // Tx Arbitration Start Delay
            U32 RFFN        :4;         // Number of Legacy Rx FIFO Filters
            U32 WRMFRZ      :1;         // Write-Access To Memory In Freeze Mode
            U32 ECRWRE      :1;         // Error-Correction Configuration Register Write Enable
            U32 BOFFDONEMSK :1;         // Bus Off Done Interrupt Mask
            U32 ERRMSK_FAST :1;         // Error Interrupt Mask for errors detected in the Data Phase of fast CAN FD frames
        } B;
    } CTRL2; // Control 2 Register (Offset: 0x34; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32      :13;
            U32 IMB  :1;                // Inactive Mailbox
            U32 VPS  :1;                // Valid Priority Status
            U32      :1;
            U32 LPTM :7;                // Lowest Priority Tx Mailbox
            U32      :9;
        } B;
    } ESR2; // Error and Status 2 Register (Offset: 0x38; Reset: 0x00000000)

    U32 CAN_Reserved0[2U];

    union {
        U32 R;
        struct {
            U32 TXCRC :15;              // Transmitted CRC Value
            U32       :1;
            U32 MBCRC :7;               // CRC Mailbox
            U32       :9;
        } B;
    } CRCR; // CRC Register (Offset: 0x44; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 FGM :32;                // Legacy Rx FIFO Global Mask Bits
        } B;
    } RXFGMASK; // Legacy Rx FIFO Global Mask Register (Offset: 0x48; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 IDHIT :9;               // Identifier Acceptance Filter Hit Indicator
            U32       :23;
        } B;
    } RXFIR; // Legacy Rx FIFO Information Register (Offset: 0x4c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 EPSEG2   :5;            // Extended Phase Segment 2
            U32 EPSEG1   :5;            // Extended Phase Segment 1
            U32 EPROPSEG :6;            // Extended Propagation Segment
            U32 ERJW     :5;            // Extended Resync Jump Width
            U32 EPRESDIV :10;           // Extended Prescaler Division Factor
            U32 BTF      :1;            // Bit Timing Format Enable
        } B;
    } CBT; // BitTiming Register (Offset: 0x50; Reset: 0x00000000)

    U32 CAN_Reserved1[5U];

    union {
        U32 R;
        struct {
            U32 BUF127TO96M :32;        // Buffer MB i Mask
        } B;
    } IMASK4; // Interrupt Mask4 Register (Offset: 0x68; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 BUF95TO64M :32;         // Buffer MB i Mask
        } B;
    } IMASK3; // Interrupt Mask3 Register (Offset: 0x6c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 BUF127TO96 :32;         // Buffer MB Interrupt
        } B;
    } IFLAG4; // Interrupt Flags 4 Register (Offset: 0x70; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 BUF95TO64 :32;          // Buffer MB i Interrupt
        } B;
    } IFLAG3; // Interrupt Flags 3 Register (Offset: 0x74; Reset: 0x00000000)

    U32 CAN_Reserved2[202U];

    union {
        U32 R;
        struct {
            U32 MI :32;                 // Individual Mask Bits
        } B;
    } RXIMRn[32U]; // RX Individual Mask Register (Offset: 0x880; Reset: 0x00000000)

    U32 CAN_Reserved3[78U];

    union {
        U32 R;
        struct {
            U32            :7;
            U32 NCEFAFRZ   :1;          // Non-Correctable Errors In FlexCAN Access Put Device In Freeze Mode
            U32 ECCDIS     :1;          // Error Correction Disable
            U32 RERRDIS    :1;          // Error Report Disable
            U32            :3;
            U32 EXTRRIE    :1;          // Extended Error Injection Enable
            U32 FAERRIE    :1;          // FlexCAN Access Error Injection Enable
            U32 HAERRIE    :1;          // Host Access Error Injection Enable
            U32 CEI_MSK    :1;          // Correctable Errors Interrupt Mask
            U32            :1;
            U32 FANCEI_MSK :1;          // FlexCAN Access With Non-Correctable Errors Interrupt Mask
            U32 HANCEI_MSK :1;          // Host Access With Non-Correctable Errors Interrupt Mask
            U32            :11;
            U32 ECRWRDIS   :1;          // Error Configuration Register Write Disable
        } B;
    } MECR; // Memory Error Control Register (Offset: 0xae0; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 INJADDR_L :2;           // Error Injection Address Low
            U32 INJADDR_H :12;          // Error Injection Address High.
            U32 MI        :18;
        } B;
    } ERRIAR; // Error Injection address Register (Offset: 0xae4; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 DFLIP :32;              // Data Flip Pattern
        } B;
    } ERRIDPR; // Error Injection Data Pattern Register (Offset: 0xae8; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 PFLIP0 :5;              // Parity Flip Pattern For Byte 0 (least significant)
            U32        :3;
            U32 PFLIP1 :5;              // Parity Flip Pattern For Byte 1
            U32        :3;
            U32 PFLIP2 :5;              // Parity Flip Pattern For Byte 2
            U32        :3;
            U32 PFLIP3 :5;              // Parity Flip Pattern For Byte 3 (most significant)
            U32        :3;
        } B;
    } ERRIPPR; // Error Injection Parity Pattern Register (Offset: 0xaec; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 ERRADDR :14;            // Address Where the Error was Detected
            U32         :2;
            U32 SAID    :3;             // SAID
            U32         :5;
            U32 NCE     :1;             // Non-Correctable Error
            U32         :7;
        } B;
    } RERRAR; // Error Report Address Register (Offset: 0xaf0; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 RDATA :32;              // Raw data word read from memory with error
        } B;
    } RERRDR; // Error Report Data Register (Offset: 0xaf4; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 SYND0 :5;               // Error Syndrome For Byte 0 (least significant)
            U32       :2;
            U32 BE0   :1;               // Byte Enabled For Byte 0 (least significant)
            U32 SYND1 :5;               // Error Syndrome For Byte 1
            U32       :2;
            U32 BE1   :1;               // Byte Enabled For Byte 1
            U32 SYND2 :5;               // Error Syndrome For Byte 2
            U32       :2;
            U32 BE2   :1;               // Byte Enabled For Byte 2
            U32 SYND3 :5;               // Error Syndrome For Byte 3 (most significant)
            U32       :2;
            U32 BE3   :1;               // Byte Enabled For Byte 3 (most significant)
        } B;
    } RERRSYNR; // Error Report Syndrome Register (Offset: 0xaf8; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CEIOF    :1;            // Correctable Error Interrupt Overrun Flag
            U32          :1;
            U32 FANCEIOF :1;            // FlexCAN Access With Non-Correctable Error Interrupt Overrun Flag
            U32 HANCEIOF :1;            // Host Access With Non-Correctable Error Interrupt Overrun Flag
            U32          :12;
            U32 CEIF     :1;            // Correctable Error Interrupt Flag
            U32          :1;
            U32 FANCEIF  :1;            // FlexCAN Access With Non-Correctable Error Interrupt Flag
            U32 HANCEIF  :1;            // Host Access With Non-Correctable Error Interrupt Flag
            U32          :12;
        } B;
    } ERRSR; // Error Status Register (Offset: 0xafc; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 FCS      :2;            // Filtering Combination Selection
            U32 IDFS     :2;            // ID Filtering Selection
            U32 PLFS     :2;            // Payload Filtering Selection
            U32          :2;
            U32 NMATCH   :8;            // Number of Messages Matching the Same Filtering Criteria
            U32 WUMF_MSK :1;            // Wake Up by Match Flag Mask Bit
            U32 WTOF_MSK :1;            // Wake Up by Timeout Flag Mask Bit
            U32          :14;
        } B;
    } CTRL1_PN; // Pretended Networking Control 1 Register (Offset: 0xb00; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 MATCHTO :16;            // Timeout for No Message Matching the Filtering Criteria
            U32         :16;
        } B;
    } CTRL2_PN; // Pretended Networking Control 2 Register (Offset: 0xb04; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32          :8;
            U32 MCOUNTER :8;            // Number of Matches while in Pretended Networking
            U32 WUMF     :1;            // Wake Up by Match Flag Bit
            U32 WTOF     :1;            // Wake Up by Timeout Flag Bit
            U32          :14;
        } B;
    } WU_MTC; // Pretended Networking Wake Up Match Register (Offset: 0xb08; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 FLT_ID1 :29;            // ID Filter 1 for Pretended Networking Filtering
            U32 FLT_PTR :1;             // Remote Transmission Request Filter
            U32 FLT_IDE :1;             // Wake Up by Match Flag Bit
            U32         :1;
        } B;
    } FLT_ID1; // Pretended Networking ID Filter 1 Register (Offset: 0xb0c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 FLT_DLC_HI :4;          // Lower Limit for Length of Data Bytes Filter
            U32            :12;
            U32 FLT_DLC_LO :4;          // Upper Limit for Length of Data Bytes Filter
            U32            :12;
        } B;
    } FLT_DLC; // Pretended Networking DLC Filter Register (Offset: 0xb10; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 Data_byte_3 :8;         // Payload Filter 1 low order bits data byte 3
            U32 Data_byte_2 :8;         // Payload Filter 1 low order bits data byte 2
            U32 Data_byte_1 :8;         // Payload Filter 1 low order bits data byte 1
            U32 Data_byte_0 :8;         // Payload Filter 1 low order bits data byte 0
        } B;
    } PL1_LO; // Pretended Networking Payload Low Filter 1 Register (Offset: 0xb14; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 Data_byte_7 :8;         // Payload Filter 1 low order bits data byte 7
            U32 Data_byte_6 :8;         // Payload Filter 1 low order bits data byte 6
            U32 Data_byte_5 :8;         // Payload Filter 1 low order bits data byte 5
            U32 Data_byte_4 :8;         // Payload Filter 1 low order bits data byte 4
        } B;
    } PL1_HI; // Pretended Networking Payload High Filter 1 Register (Offset: 0xb18; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 FLT_ID2_IDMASK :29;     // ID Filter 2 for Pretended Networking Filtering
            U32 RST_MSK        :1;      // Remote Transmission Request Mask Bit
            U32 IDE_MSK        :1;      // ID Extended Mask Bit
            U32                :1;
        } B;
    } FLT_ID2_IDMASK; // Pretended Networking ID Filter 2 Register (Offset: 0xb1c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 Data_byte_3 :8;         // Payload Filter 2 low order bits data byte 3
            U32 Data_byte_2 :8;         // Payload Filter 2 low order bits data byte 2
            U32 Data_byte_1 :8;         // Payload Filter 2 low order bits data byte 1
            U32 Data_byte_0 :8;         // Payload Filter 2 low order bits data byte 0
        } B;
    } PL2_PLMASK_LO; // Pretended Networking Payload Low Filter 2 Register (Offset: 0xb20; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 Data_byte_7 :8;         // Payload Filter 2 low order bits data byte 7
            U32 Data_byte_6 :8;         // Payload Filter 2 low order bits data byte 6
            U32 Data_byte_5 :8;         // Payload Filter 2 low order bits data byte 5
            U32 Data_byte_4 :8;         // Payload Filter 2 low order bits data byte 4
        } B;
    } PL2_PLMASK_HI; // Pretended Networking Payload High Filter 2 Register (Offset: 0xb24; Reset: 0x00000000)

    U32 CAN_Reserved4[6U];

    struct {
        union {
            U32 R;
            struct {
                U32     :16;
                U32 DLC :4;             // Length of Data in Bytes
                U32 RTR :1;             // Remote Transmission Request Bit
                U32 IDE :1;             // ID Extended Bit
                U32 SRR :1;             // Substitute Remote Request
                U32     :9;
            } B;
        } WMBn_CS; // Control Status (C/S) information of an incoming Rx message register (Offset: 0xb40; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 ID :29;             // ID information of an incoming Rx message
                U32    :3;
            } B;
        } WMBn_ID; // ID information of an incoming Rx message register (Offset: 0xb44; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 Data_byte_3 :8;     // Received payload corresponding to data byte 3
                U32 Data_byte_2 :8;     // Received payload corresponding to data byte 2
                U32 Data_byte_1 :8;     // Received payload corresponding to data byte 1
                U32 Data_byte_0 :8;     // Received payload corresponding to data byte 0
            } B;
        } WMBn_D03; // Store the data bytes 0-3 of the payload information of an incoming Rx message register (Offset: 0xb48; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 Data_byte_7 :8;     // Received payload corresponding to data byte 7
                U32 Data_byte_6 :8;     // Received payload corresponding to data byte 6
                U32 Data_byte_5 :8;     // Received payload corresponding to data byte 5
                U32 Data_byte_4 :8;     // Received payload corresponding to data byte 4
            } B;
        } WMBn_D47; // Store the data bytes 4-7 of the payload information of an incoming Rx message register (Offset: 0xb4c; Reset: 0x00000000)

    } WMB[4U];

    U32 CAN_Reserved5[28U];

    union {
        U32 R;
        struct {
            U32 ENPRESDIV :8;           // Extended Nominal Phase Prescaler Division Factor
            U32           :8;
            U32 EDPRESDIV :8;           // Extended Data Phase Prescaler Division Factor
            U32           :8;
        } B;
    } EPRS; // Enhanced CAN BitTiming Prescalers Register (Offset: 0xbf0; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 NTSEG1 :8;              // Nominal Time Segment 1
            U32        :4;
            U32 NTSEG2 :7;              // Nominal Time Segment 2
            U32        :3;
            U32 NRJW   :7;              // Nominal Resynchronization Jump Width
            U32        :3;
        } B;
    } ENCBT; // Enhanced Nominal CAN BitTiming Register (Offset: 0xbf4; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 DTSEG1 :5;              // Data Phase Time Segment 1
            U32        :7;
            U32 DTSEG2 :4;              // Data Phase Time Segment 2
            U32        :6;
            U32 DRJW   :4;              // Data Phase Resynchronization Jump Width
            U32        :6;
        } B;
    } EDCBT; // Enhanced Data Phase CAN Bit Timing Register (Offset: 0xbf8; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 ETDCVAL :8;             // Enhanced Transceiver Delay Compensation Value
            U32         :7;
            U32 DTSEG2  :1;             // Transceiver Delay Compensation Fail
            U32 ETDCOFF :7;             // Enhanced Transceiver Delay Compensation Offset
            U32         :7;
            U32 TDMDIS  :1;             // Transceiver Delay Measurement Disable
            U32 ETDCEN  :1;             // Transceiver Delay Compensation Enable
        } B;
    } ETDC; // Enhanced Transceiver Delay Compensation Register (Offset: 0xbfc; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 TDCVAL  :6;             // Transceiver Delay Compensation Value
            U32         :2;
            U32 TDCOFF  :5;             // Transceiver Delay Compensation Offset
            U32         :1;
            U32 TDCFAIL :1;             // Transceiver Delay Compensation Fail
            U32 TDCEN   :1;             // Transceiver Delay Compensation Enable
            U32 MBDSR0  :2;             // Message Buffer Data Size for Region 0
            U32         :13;
            U32 FDRATE  :1;             // Bit Rate Switch Enable
        } B;
    } FDCTRL; // FD Control Register (Offset: 0xc00; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 FPSEG2   :3;            // Fast Phase Segment 2
            U32          :2;
            U32 FPSEG1   :3;            // Fast Phase Segment 1
            U32          :2;
            U32 FPROPSEG :5;            // Fast Propagation Segment
            U32          :1;
            U32 FRJW     :3;            // Fast Resync Jump Width
            U32          :1;
            U32 FPRESDIV :10;            // Fast Prescaler Division Factor
            U32          :2;
        } B;
    } FDCBT;// FD Bit Timing Register (Offset: 0xc04; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 FD_TXCRC :21;           // Extended Transmitted CRC value
            U32          :3;
            U32 FD_MBCRC :7;            // CRC Mailbox Number for FD_TXCRC
            U32          :1;
        } B;
    } FDCRC; // FD CRC Register (Offset: 0xc08; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 ERFWM :5;               // Enhanced Rx FIFO Watermark
            U32       :3;
            U32 NFE   :6;               // Number of Enhanced Rx FIFO Filter Elements
            U32       :2;
            U32 NEXIF :7;               // Number of Extended ID Filter Elements
            U32       :3;
            U32 DMALW :5;               // DMA Last Word
            U32 ERFEN :1;               // Enhanced Rx FIFO Enable
        } B;
    } ERFCR; // Enhanced Rx FIFO Control Register (Offset: 0xc0c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32          :28;
            U32 ERFDAIE  :1;            // Enhanced Rx FIFO Data Available Interrupt Enable
            U32 ERFWMIIE :1;            // Enhanced Rx FIFO Watermark Indication Interrupt Enable
            U32 ERFOVFIE :1;            // Enhanced Rx FIFO Overflow Interrupt Enable
            U32 ERFUFWIE :1;            // Enhanced Rx FIFO Underflow Interrupt Enable
        } B;
    } ERFIER; // Enhanced Rx FIFO Interrupt Enable Register (Offset: 0xc10; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 ERFN   :6;              // Enhanced Rx FIFO Elements Indicates the Number of CAN messages
            U32        :10;
            U32 ERFF   :1;              // Enhanced Rx FIFO Full
            U32 ERFE   :1;              // Enhanced Rx FIFO Empty
            U32        :9;
            U32 ERFCLR :1;              // Enhanced Rx FIFO Clear
            U32 ERFDA  :1;              // Enhanced Rx FIFO Data Available
            U32 ERFWMI :1;              // Enhanced Rx FIFO Watermark Indication
            U32 ERFOVF :1;              // Enhanced Rx FIFO Overflow
            U32 ERFUFW :1;              // Enhanced Rx FIFO Underflow
        } B;
    } ERFSR; // Enhanced Rx FIFO Status Register (Offset: 0xc14; Reset: 0x00000000)

    U32 CAN_Reserved6[6U];

    union {
        U32 R;
        struct {
            U32 TS :32;                 // High Resolution Time Stamp
        } B;
    } HR_TIME_STAMPn[128U]; // High Resolution Time Stamp Registers (Offset: 0xc30; Reset: 0x00000000)

    U32 CAN_Reserved7[2164U];

    union {
        U32 R;
        struct {
            U32 FEL :32;                // Filter Element Bits
        } B;
    } ERFFELn[128U]; // Enhanced Rx FIFO Filter Element Registers (Offset: 0x3000; Reset: 0x00000000)

} FLEXCAN_tag; // end of FLEXCAN_tag



//**************************************************************************************************
//! Inter-Integrated Circuit (I2C) memory map
//**************************************************************************************************
typedef volatile struct I2C_struct {
    union {
        U32 R;
        struct {
            U32 MEN     :1;             // Master Mode Enable
            U32         :7;
            U32 PPEN    :1;             // Push Pull Mode Enable
            U32 HSMOD   :1;             // High Speed Mode Enable
            U32         :4;
            U32 ASTOP   :1;             // Automatically STOP
            U32 IGACK   :1;             // Ignore I2C ACK
            U32 MATCFG  :3;             // Match Configuration
            U32         :6;
            U32 RDMO    :1;             // Receive Data Match Only
            U32         :2;
            U32 RXDMAEN :1;             // Master RX data DMA Enable
            U32 TXDMAEN :1;             // Master TX DATA DMA Enable
            U32         :2;
        } B;
    } MCTRL; // Master Control Register (Offset: 0x00; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 STHD  :6;               // SDA Data Setup/Hold Period
            U32       :2;
            U32 VALID :6;               // SDA Data Valid Period
            U32       :2;
            U32 LOW   :6;               // SCL Low Period
            U32       :2;
            U32 HIGH  :6;               // SCL High Period
            U32       :2;
        } B;
    } MCLKCFG; // Master Clock Configuration Register (Offset: 0x04; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 DIV    :3;              // Function Clock Divider
            U32        :13;
            U32 FLTSDA :4;              // SDA Filter Control
            U32        :4;
            U32 FLTSCL :4;              // SCL Filter Control
            U32        :4;
        } B;
    } MFLTCFG; // Master Clock Filter Configuration and Divider Register (Offset: 0x08; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 RXIF    :1;             // RX Request Flag
            U32 TXIF    :1;             // TX Request Flag
            U32         :2;
            U32 STOPIF  :1;             // STOP Received Interrupt Flag
            U32         :1;
            U32 NACKIF  :1;             // NACK Received Interrupt Flag
            U32 ARBIF   :1;             // Arbitration Lost Interrupt Flag
            U32 TOIF    :1;             // Timeout Interrupt Flag
            U32 MATIF   :1;             // Data Match Interrupt Flag
            U32         :1;
            U32 OPERRIF :1;             // Operation Error Interrupt Flag
            U32         :4;
            U32 BUSY    :1;             // I2C Bus Busy
            U32 ACTIVE  :1;             // I2C Master Active
            U32         :14;
        } B;
    } MSTS; // Master Status Register (Offset: 0x0c; Reset: 0x00000002)

    union {
        U32 R;
        struct {
            U32 RXIE    :1;             // RX DATA Interrupt Enable
            U32 TXIE    :1;             // TX DATA Interrupt Enable
            U32         :2;
            U32 STOPIE  :1;             // STOP Detected Interrupt Enable
            U32         :1;
            U32 NACKIE  :1;             // NACK Detected Interrupt Enable
            U32 ARBIE   :1;             // Arbitration Interrupt Enable
            U32 TOIE    :1;             // Timeout Interrupt Enable
            U32 MATIE   :1;             // Data Match Interrupt Enable
            U32         :1;
            U32 OPERRIE :1;             // Operation Error Interrupt Enable
            U32         :20;
        } B;
    } MIE; // Master Interrupt Register (Offset: 0x10; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 WATER :3;               // TX FIFO Watermark
            U32       :5;
            U32 COUNT :3;               // Word Count in TX FIFO
            U32       :4;
            U32 RESET :1;               // I2C Master TX FIFO Reset
            U32       :8;
            U32 SIZE  :3;               // I2C Master TX FIFO Size
            U32       :5;
        } B;
    } TXFIFO; // MasterTX FIFO Control and Status Register (Offset: 0x14; Reset: 0x02000000)

    union {
        U32 R;
        struct {
            U32 WATER :3;               // RX FIFO Watermark
            U32       :5;
            U32 COUNT :3;               // Word Count in RX FIFO
            U32       :4;
            U32 RESET :1;               // I2C Master RX FIFO Reset
            U32       :8;
            U32 SIZE  :3;               // I2C Master RX FIFO Size
            U32       :5;
        } B;
    } RXFIFO; // Master RX FIFO Control and Status Register (Offset: 0x18; Reset: 0x02000000)

    union {
        U32 R;
        struct {
            U32 DATA  :8;               // TX RX DATA
            U32 START :1;               // Generate START/repeat START
            U32 STOP  :1;               // Send STOP
            U32 REC   :1;               // Receive Data
            U32 HS    :1;               // High Speed Mode
            U32       :4;
            U32 EMPTY :1;               // RX Data Empty
            U32       :15;
        } B;
    } MDATA; // Master Data Register (Offset: 0x1c; Reset: 0x00010000)

    union {
        U32 R;
        struct {
            U32 MATCH0 :8;              // Match Data 0
            U32        :8;
            U32 MATCH1 :8;              // Match Data 1
            U32        :8;
        } B;
    } MATCH; // Data Match Register (Offset: 0x20; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 LOW  :12;               // Line Low Timeout Control
            U32      :3;
            U32 SCL  :1;                // SCL Line Low Detect
            U32 IDLE :12;               // Line Idle Timeout Control
            U32      :4;
        } B;
    } TOCFG; // Timeout Configure Register (Offset: 0x24; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 STHD  :6;               // SDA Data Setup/Hold Period
            U32       :2;
            U32 VALID :6;               // SDA Data Valid Period
            U32       :2;
            U32 LOW   :6;               // SCL Low Period
            U32       :2;
            U32 HIGH  :6;               // SCL High Period
            U32       :2;
        } B;
    } HSCLK; // Master clock configuration under high speed mode register (Offset: 0x28; Reset: 0x00000000)

     U32 I2C_Reserved0[53U];

    union {
        U32 R;
        struct {
            U32 SEN        :1;          // Slave Module Enable
            U32            :1;
            U32 FILTEN     :1;          // Slave Digital Filter Enable
            U32            :1;
            U32 ADRSTALL   :1;          // Address SCL Stall Enable
            U32 ACKSTALL   :1;          // ACK SCL Stall Enable
            U32 RXSTALL    :1;          // RX SCL Stall Enable
            U32 TXSTALL    :1;          // TX SCL Stall Enable
            U32            :2;
            U32 GCEN       :1;          // General Call Address Detect Enable
            U32 ALERTEN    :1;          // Alert Address Detect Enable
            U32 RXRST      :1;          // RX buffer reset
            U32 TXRST      :1;          // TX buffer reset
            U32            :1;
            U32 IGACK      :1;          // Ignore I2C ACK
            U32 ADDRCFG    :3;          // Slave Address Match Config
            U32 TXCFG      :1;          // TX Data Config
            U32 RXCFG      :1;          // RX Data Config
            U32            :1;
            U32 HSEN       :1;          // High Speed Mode Enable
            U32            :3;
            U32 STOPDMAEN  :1;          // Receive STOP DMA Enable
            U32 STARTDMAEN :1;          // Receive START DMA Enable
            U32 RXDMAEN    :1;          // RX data DMA Enable
            U32 TXDMAEN    :1;          // TX data DMA Enable
            U32 ADDRDMAEN  :1;          // Address Valid DMA Enable
            U32            :1;
        } B;
    } SCTRL; // Slave Control Register (Offset: 0x100; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 HOLD  :4;               // Data Hold Period
            U32       :4;
            U32 VALID :6;               // Data Valid Period
            U32       :18;
        } B;
    } SCLKCFG; // Slave Clock Configuration Register (Offset: 0x104; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32        :16;
            U32 FLTSDA :4;              // SDA Filter Control
            U32        :4;
            U32 FLTSCL :4;              // SCL Filter Control
            U32        :4;
        } B;
    } SFLTCFG; // Slave Filter Configuration Register (Offset: 0x108; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 RXIF     :1;            // RX Request Flag
            U32 TXIF     :1;            // TX Request Flag
            U32 ACKIF    :1;            // Ack Request Interrupt Flag
            U32 ADDRIF   :1;            // Address Valid Interrupt Flag
            U32 STOPIF   :1;            // Stop Interrupt Flag
            U32 RSIF     :1;            // Repeat Start Interrupt Flag
            U32          :1;
            U32 ARBIF    :1;            // Arbitration Lost Interrupt Flag
            U32          :1;
            U32 MATCHAIF :1;            // Address A Received Interrupt Flag
            U32 ADRBIF   :1;            // Address B Received Interrupt Flag
            U32 GCIF     :1;            // General Call Address Received Interrupt Flag
            U32 ALERTIF  :1;            // Alert Address Received Interrupt Flag
            U32 OPERRIF  :1;            // Operation Error Interrupt Flag
            U32          :2;
            U32 BUSY     :1;            // I2C Bus Busy
            U32 ACTIVE   :1;            // I2C Slave Active
            U32          :14;
        } B;
    } SSTS; // Slave Status Register (Offset: 0x10c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 RXIF    :1;             // RX DATA Interrupt Enable
            U32 TXIF    :1;             // TX DATA Interrupt Enable
            U32 ACKIE   :1;             // Ack Request Interrupt Enable
            U32 ADDRIE  :1;             // Address Valid Interrupt Enable
            U32 STOPIE  :1;             // Stop Interrupt Enable
            U32 RSIE    :1;             // Repeat Start Interrupt Enable
            U32         :1;
            U32 ARBIE   :1;             // Arbitration Interrupt Enable
            U32         :1;
            U32 MAT0IE  :1;             // Match Address 0 Interrupt Enable
            U32 MAT1IE  :1;             // Match Address 1 Interrupt Enable
            U32 GCIE    :1;             // General Call Address Interrupt Enable
            U32 ALERTIE :1;             // Alert Address Interrupt Enable
            U32 OPERRIE :1;             // Slave Operation Error Interrupt Enable
            U32         :18;
        } B;
    } SIE; // Slave Interrupt Enable Register (Offset: 0x110; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 DATA  :8;               // Slave TX RX DATA
            U32       :8;
            U32 EMPTY :1;               // RX Buffer Empty
            U32       :15;
        } B;
    } SDATA; // Slave Data Register (Offset: 0x114; Reset: 0x00010000)

    union {
        U32 R;
        struct {
            U32 NACK :1;                // Sent NACK
            U32      :31;
        } B;
    } SACK; // Slave Ack Register (Offset: 0x118; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 ADDRA :11;              // Slave ADDR A
            U32       :5;
            U32 ADDRB :11;              // Slave ADDR B
            U32       :5;
        } B;
    } SADDR; // Slave Address Match Configuration Register (Offset: 0x11c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 ADDR  :11;              // Slave Received Address
            U32       :4;
            U32 VALID :1;               // Address Valid
            U32       :16;
        } B;
    } SRADDR; // Slave Received Address Register (Offset: 0x120; Reset: 0x00000000)

} I2C_tag; // end of I2C_tag



//**************************************************************************************************
//! Interrupt Monitor (INTM) memory map
//**************************************************************************************************
typedef volatile struct INTM_struct {
    union {
        U32 R;
        struct {
            U32 GEN :1;                 // Global Enable
            U32     :31;
        } B;
    } GCTRL; // Global Control Register (Offset: 0x00; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 SRC :10;                // Interrupt source
            U32     :22;
        } B;
    } GINTACK; // Global Interrupt Acknowledge Register (Offset: 0x04; Reset: 0x00000000)

    struct {
        union {
            U32 R;
            struct {
                U32 IRQ :10;            // MONn IRQ number
                U32     :21;
                U32 EN  :1;             // MONn Enable
            } B;
        } SEL; // Monitor Channel Selection Register (Offset: 0x10- 0x40; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 THRESHOLD :24;      // MONn timer threshold
                U32           :8;
            } B;
        } THD; // Monitor Timer Threshold Register (Offset: 0x14- 0x44; Reset: 0x00FFFFFF)

        union {
            U32 R;
            struct {
                U32 CNT :24;            // MONn timer value
                U32     :8;
            } B;
        } TMRV; // Monitor Timer Value Register (Offset: 0x18- 0x48; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 CNT :24;            // MONn timer value
                U32     :8;
            } B;
        } STS; // Monitor Status Register (Offset: 0x1c- 0x4c; Reset: 0x00000000)

    } MON[4U];

} INTM_tag; // end of INTM_tag



//**************************************************************************************************
//! Integrated Peripherals Control (IPC) memory map
//**************************************************************************************************
typedef volatile struct IPC_struct {
    union {
        U32 R;
        struct {
            U32 CLKEN  :1;              // Clock divider
            U32 SWREN  :1;              // Software reset
            U32        :6;
            U32 SRCSEL :3;              // Clock Source Selection
            U32        :5;
            U32 DIV    :4;              // Clock divider
            U32        :12;
        } B;
    } CTRL[128U]; // Integrated Peripherals Control register (Offset: 0x00; Reset: 0x0000.0000)

} IPC_tag; // end of IPC_tag



//**************************************************************************************************
//! Hardware Cryptography Unit (HCU) memory map
//**************************************************************************************************
typedef volatile struct HCU_struct {
    union {
        U32 R;
        struct {
            U32 GO :1;                  // Engine Run
            U32    :31;
        } B;
    } GO; // Go Register (Offset: 0x00; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32        :1;
            U32 ENC    :1;              // Encryption/Decryption Select
            U32 DATSWP :2;              // Data Swapping
            U32 ENGSEL :4;              // Engine Selection
            U32 KEYLEN :2;              // Key Length
            U32        :2;
            U32 ALGSEL :4;              // Algorithm Select
            U32 MSGE   :1;              // Message Ending
            U32 MSGB   :1;              // Message Beginning
            U32 CS     :1;              // Context data Store
            U32 SHAVE  :1;              // SHA Verification Enable
            U32        :4;
            U32 MACLEN :4;              // MAC Length
            U32 IFDMAE :1;              // Input FIFO DMA Enable
            U32 OFDMAE :1;              // Output FIFO DMA Enable
            U32 IFSWR  :1;              // Input FIFO Software Reset
            U32 OFSWR  :1;              // Output FIFO Software Reset
        } B;
    } CR; // Configuration Register (Offset: 0x04; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 MSGTOT :28;             // Message Total Byte
            U32        :4;
        } B;
    } MSGINFO; // Message Information Register (Offset: 0x08; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 MSGLEN :16;             // Message Length
            U32 ADLEN  :16;             // Additional Data Length
        } B;
    } MSGADL; // Message and Additional Data Length Register (Offset: 0x0c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 IFWM :5;                // Input FIFO Watermark
            U32      :11;
            U32 OFWM :5;                // Output FIFO Watermark
            U32      :11;
        } B;
    } FIFOWM; // FIFO watermark Register (Offset: 0x14; Reset: 0x00040004)

    union {
        U32 R;
        struct {
            U32 ODIE   :1;              // Operation Done Interrupt Enable
            U32        :8;
            U32 OFFIE  :1;              // Output FIFO Full Interrupt Enable
            U32 IFEIE  :1;              // Input FIFO Empty Interrupt Enable
            U32        :1;
            U32 OFUFIE :1;              // Output FIFO Underflow Interrupt Enable
            U32 IFOFIE :1;              // Input FIFO Overflow Interrupt Enable
            U32 OFWMIE :1;              // Output FIFO Watermark Interrupt Enable
            U32 IFWMIE :1;              // Input FIFO Watermark Interrupt Enable
            U32        :16;
        } B;
    } INTE; // Interrupt Enable Register (Offset: 0x18; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 OD     :1;              // Operation Done
            U32 AESVAL :1;              // AES MAC Valid
            U32 SHAVAL :1;              // SHA hash Valid
            U32        :5;
            U32 OFES   :1;              // Output FIFO Empty Status
            U32 OFFS   :1;              // Output FIFO Full Status
            U32 IFES   :1;              // Input FIFO Empty Status
            U32 IFFS   :1;              // Input FIFO Full Status
            U32 OFUFF  :1;              // Output FIFO Underflow Flag
            U32 IFOFF  :1;              // Input FIFO Overflow Flag
            U32 OFWMF  :1;              // Output FIFO Watermark Flag
            U32 IFWMF  :1;              // Input FIFO Watermark Flag
            U32        :16;
        } B;
    } SR; // Status Register (Offset: 0x1c; Reset: 0x00008504)

    union {
        U32 R;
        struct {
            U32 KEY :32;                // Key value
        } B;
    } KEY[8U]; // Key (0~7) Register (Offset: 0x20h-3c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CNT :32;                // Counter value
        } B;
    } AESCV[4U]; // AES Counter Value (0~3) Register (Offset: 0x50h-5c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 INIT :32;               // Initial Vector value
        } B;
    } AESIV[4U]; // AES Initial Vector (0~3) Register (Offset: 0x60h-6c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 MAC :32;                // MAC value
        } B;
    } AESMAC[4U]; // AES MAC (0~3) Register (Offset: 0x70h-7c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 ICV :32;                // ICV value
        } B;
    } SHAICV[12U]; // SHAICV (0~11) Register (Offset: 0x80h-ac; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 IFDAT :32;              // Input FIFO Data
        } B;
    } IFDAT; // Input FIFO Data Register (Offset: 0xb0; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 OFDAT :32;              // Output FIFO Data
        } B;
    } OFDAT; // Output FIFO Data Register (Offset: 0xb4; Reset: 0x00000000)

} HCU_tag; // end of HCU_tag



//**************************************************************************************************
//! General Port Input / Output (GPIO) memory map
//**************************************************************************************************
typedef volatile struct GPIO_struct {
    union {
        U32 R;
        struct {
            U32 PDO0  :1;               // GPIO pin 0 output value
            U32 PDO1  :1;               // GPIO pin 1 output value
            U32 PDO2  :1;               // GPIO pin 2 output value
            U32 PDO3  :1;               // GPIO pin 3 output value
            U32 PDO4  :1;               // GPIO pin 4 output value
            U32 PDO5  :1;               // GPIO pin 5 output value
            U32 PDO6  :1;               // GPIO pin 6 output value
            U32 PDO7  :1;               // GPIO pin 7 output value
            U32 PDO8  :1;               // GPIO pin 8 output value
            U32 PDO9  :1;               // GPIO pin 9 output value
            U32 PDO10 :1;               // GPIO pin 10 output value
            U32 PDO11 :1;               // GPIO pin 11 output value
            U32 PDO12 :1;               // GPIO pin 12 output value
            U32 PDO13 :1;               // GPIO pin 13 output value
            U32 PDO14 :1;               // GPIO pin 14 output value
            U32 PDO15 :1;               // GPIO pin 15 output value
            U32 PDO16 :1;               // GPIO pin 16 output value
            U32 PDO17 :1;               // GPIO pin 17 output value
            U32 PDO18 :1;               // GPIO pin 18 output value
            U32 PDO19 :1;               // GPIO pin 19 output value
            U32 PDO20 :1;               // GPIO pin 20 output value
            U32 PDO21 :1;               // GPIO pin 21 output value
            U32 PDO22 :1;               // GPIO pin 22 output value
            U32 PDO23 :1;               // GPIO pin 23 output value
            U32 PDO24 :1;               // GPIO pin 24 output value
            U32 PDO25 :1;               // GPIO pin 25 output value
            U32 PDO26 :1;               // GPIO pin 26 output value
            U32 PDO27 :1;               // GPIO pin 27 output value
            U32 PDO28 :1;               // GPIO pin 28 output value
            U32 PDO29 :1;               // GPIO pin 29 output value
            U32 PDO30 :1;               // GPIO pin 30 output value
            U32 PDO31 :1;               // GPIO pin 31 output value
        } B;
    } PDOR; // GPIO port data output register (Offset: 0x00; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 PSO0  :1;               // GPIO pin 0 set bit
            U32 PSO1  :1;               // GPIO pin 1 set bit
            U32 PSO2  :1;               // GPIO pin 2 set bit
            U32 PSO3  :1;               // GPIO pin 3 set bit
            U32 PSO4  :1;               // GPIO pin 4 set bit
            U32 PSO5  :1;               // GPIO pin 5 set bit
            U32 PSO6  :1;               // GPIO pin 6 set bit
            U32 PSO7  :1;               // GPIO pin 7 set bit
            U32 PSO8  :1;               // GPIO pin 8 set bit
            U32 PSO9  :1;               // GPIO pin 9 set bit
            U32 PSO10 :1;               // GPIO pin 10 set bit
            U32 PSO11 :1;               // GPIO pin 11 set bit
            U32 PSO12 :1;               // GPIO pin 12 set bit
            U32 PSO13 :1;               // GPIO pin 13 set bit
            U32 PSO14 :1;               // GPIO pin 14 set bit
            U32 PSO15 :1;               // GPIO pin 15 set bit
            U32 PSO16 :1;               // GPIO pin 16 set bit
            U32 PSO17 :1;               // GPIO pin 17 set bit
            U32 PSO18 :1;               // GPIO pin 18 set bit
            U32 PSO19 :1;               // GPIO pin 19 set bit
            U32 PSO20 :1;               // GPIO pin 20 set bit
            U32 PSO21 :1;               // GPIO pin 21 set bit
            U32 PSO22 :1;               // GPIO pin 22 set bit
            U32 PSO23 :1;               // GPIO pin 23 set bit
            U32 PSO24 :1;               // GPIO pin 24 set bit
            U32 PSO25 :1;               // GPIO pin 25 set bit
            U32 PSO26 :1;               // GPIO pin 26 set bit
            U32 PSO27 :1;               // GPIO pin 27 set bit
            U32 PSO28 :1;               // GPIO pin 28 set bit
            U32 PSO29 :1;               // GPIO pin 29 set bit
            U32 PSO30 :1;               // GPIO pin 30 set bit
            U32 PSO31 :1;               // GPIO pin 31 set bit
        } B;
    } PSOR; // GPIO port set output register (Offset: 0x04; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 PCO0  :1;               // GPIO pin 0 clear bit
            U32 PCO1  :1;               // GPIO pin 1 clear bit
            U32 PCO2  :1;               // GPIO pin 2 clear bit
            U32 PCO3  :1;               // GPIO pin 3 clear bit
            U32 PCO4  :1;               // GPIO pin 4 clear bit
            U32 PCO5  :1;               // GPIO pin 5 clear bit
            U32 PCO6  :1;               // GPIO pin 6 clear bit
            U32 PCO7  :1;               // GPIO pin 7 clear bit
            U32 PCO8  :1;               // GPIO pin 8 clear bit
            U32 PCO9  :1;               // GPIO pin 9 clear bit
            U32 PCO10 :1;               // GPIO pin 10 clear bit
            U32 PCO11 :1;               // GPIO pin 11 clear bit
            U32 PCO12 :1;               // GPIO pin 12 clear bit
            U32 PCO13 :1;               // GPIO pin 13 clear bit
            U32 PCO14 :1;               // GPIO pin 14 clear bit
            U32 PCO15 :1;               // GPIO pin 15 clear bit
            U32 PCO16 :1;               // GPIO pin 16 clear bit
            U32 PCO17 :1;               // GPIO pin 17 clear bit
            U32 PCO18 :1;               // GPIO pin 18 clear bit
            U32 PCO19 :1;               // GPIO pin 19 clear bit
            U32 PCO20 :1;               // GPIO pin 20 clear bit
            U32 PCO21 :1;               // GPIO pin 21 clear bit
            U32 PCO22 :1;               // GPIO pin 22 clear bit
            U32 PCO23 :1;               // GPIO pin 23 clear bit
            U32 PCO24 :1;               // GPIO pin 24 clear bit
            U32 PCO25 :1;               // GPIO pin 25 clear bit
            U32 PCO26 :1;               // GPIO pin 26 clear bit
            U32 PCO27 :1;               // GPIO pin 27 clear bit
            U32 PCO28 :1;               // GPIO pin 28 clear bit
            U32 PCO29 :1;               // GPIO pin 29 clear bit
            U32 PCO30 :1;               // GPIO pin 30 clear bit
            U32 PCO31 :1;               // GPIO pin 31 clear bit
        } B;
    } PCOR; // GPIO port clear output register (Offset: 0x08; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 PTO0  :1;               // GPIO pin 0 toggle bit
            U32 PTO1  :1;               // GPIO pin 1 toggle bit
            U32 PTO2  :1;               // GPIO pin 2 toggle bit
            U32 PTO3  :1;               // GPIO pin 3 toggle bit
            U32 PTO4  :1;               // GPIO pin 4 toggle bit
            U32 PTO5  :1;               // GPIO pin 5 toggle bit
            U32 PTO6  :1;               // GPIO pin 6 toggle bit
            U32 PTO7  :1;               // GPIO pin 7 toggle bit
            U32 PTO8  :1;               // GPIO pin 8 toggle bit
            U32 PTO9  :1;               // GPIO pin 9 toggle bit
            U32 PTO10 :1;               // GPIO pin 10 toggle bit
            U32 PTO11 :1;               // GPIO pin 11 toggle bit
            U32 PTO12 :1;               // GPIO pin 12 toggle bit
            U32 PTO13 :1;               // GPIO pin 13 toggle bit
            U32 PTO14 :1;               // GPIO pin 14 toggle bit
            U32 PTO15 :1;               // GPIO pin 15 toggle bit
            U32 PTO16 :1;               // GPIO pin 16 toggle bit
            U32 PTO17 :1;               // GPIO pin 17 toggle bit
            U32 PTO18 :1;               // GPIO pin 18 toggle bit
            U32 PTO19 :1;               // GPIO pin 19 toggle bit
            U32 PTO20 :1;               // GPIO pin 20 toggle bit
            U32 PTO21 :1;               // GPIO pin 21 toggle bit
            U32 PTO22 :1;               // GPIO pin 22 toggle bit
            U32 PTO23 :1;               // GPIO pin 23 toggle bit
            U32 PTO24 :1;               // GPIO pin 24 toggle bit
            U32 PTO25 :1;               // GPIO pin 25 toggle bit
            U32 PTO26 :1;               // GPIO pin 26 toggle bit
            U32 PTO27 :1;               // GPIO pin 27 toggle bit
            U32 PTO28 :1;               // GPIO pin 28 toggle bit
            U32 PTO29 :1;               // GPIO pin 29 toggle bit
            U32 PTO30 :1;               // GPIO pin 30 toggle bit
            U32 PTO31 :1;               // GPIO pin 31 toggle bit
        } B;
    } PTOR; // GPIO port toggle output register (Offset: 0x0C; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 PDI0  :1;               // GPIO pin 0 input data
            U32 PDI1  :1;               // GPIO pin 1 input data
            U32 PDI2  :1;               // GPIO pin 2 input data
            U32 PDI3  :1;               // GPIO pin 3 input data
            U32 PDI4  :1;               // GPIO pin 4 input data
            U32 PDI5  :1;               // GPIO pin 5 input data
            U32 PDI6  :1;               // GPIO pin 6 input data
            U32 PDI7  :1;               // GPIO pin 7 input data
            U32 PDI8  :1;               // GPIO pin 8 input data
            U32 PDI9  :1;               // GPIO pin 9 input data
            U32 PDI10 :1;               // GPIO pin 10 input data
            U32 PDI11 :1;               // GPIO pin 11 input data
            U32 PDI12 :1;               // GPIO pin 12 input data
            U32 PDI13 :1;               // GPIO pin 13 input data
            U32 PDI14 :1;               // GPIO pin 14 input data
            U32 PDI15 :1;               // GPIO pin 15 input data
            U32 PDI16 :1;               // GPIO pin 16 input data
            U32 PDI17 :1;               // GPIO pin 17 input data
            U32 PDI18 :1;               // GPIO pin 18 input data
            U32 PDI19 :1;               // GPIO pin 19 input data
            U32 PDI20 :1;               // GPIO pin 20 input data
            U32 PDI21 :1;               // GPIO pin 21 input data
            U32 PDI22 :1;               // GPIO pin 22 input data
            U32 PDI23 :1;               // GPIO pin 23 input data
            U32 PDI24 :1;               // GPIO pin 24 input data
            U32 PDI25 :1;               // GPIO pin 25 input data
            U32 PDI26 :1;               // GPIO pin 26 input data
            U32 PDI27 :1;               // GPIO pin 27 input data
            U32 PDI28 :1;               // GPIO pin 28 input data
            U32 PDI29 :1;               // GPIO pin 29 input data
            U32 PDI30 :1;               // GPIO pin 30 input data
            U32 PDI31 :1;               // GPIO pin 31 input data
        } B;
    } PDIR; // GPIO port data input register (Offset: 0x10; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 POE0  :1;               // GPIO pin 0 output enable
            U32 POE1  :1;               // GPIO pin 1 output enable
            U32 POE2  :1;               // GPIO pin 2 output enable
            U32 POE3  :1;               // GPIO pin 3 output enable
            U32 POE4  :1;               // GPIO pin 4 output enable
            U32 POE5  :1;               // GPIO pin 5 output enable
            U32 POE6  :1;               // GPIO pin 6 output enable
            U32 POE7  :1;               // GPIO pin 7 output enable
            U32 POE8  :1;               // GPIO pin 8 output enable
            U32 POE9  :1;               // GPIO pin 9 output enable
            U32 POE10 :1;               // GPIO pin 10 output enable
            U32 POE11 :1;               // GPIO pin 11 output enable
            U32 POE12 :1;               // GPIO pin 12 output enable
            U32 POE13 :1;               // GPIO pin 13 output enable
            U32 POE14 :1;               // GPIO pin 14 output enable
            U32 POE15 :1;               // GPIO pin 15 output enable
            U32 POE16 :1;               // GPIO pin 16 output enable
            U32 POE17 :1;               // GPIO pin 17 output enable
            U32 POE18 :1;               // GPIO pin 18 output enable
            U32 POE19 :1;               // GPIO pin 19 output enable
            U32 POE20 :1;               // GPIO pin 20 output enable
            U32 POE21 :1;               // GPIO pin 21 output enable
            U32 POE22 :1;               // GPIO pin 22 output enable
            U32 POE23 :1;               // GPIO pin 23 output enable
            U32 POE24 :1;               // GPIO pin 24 output enable
            U32 POE25 :1;               // GPIO pin 25 output enable
            U32 POE26 :1;               // GPIO pin 26 output enable
            U32 POE27 :1;               // GPIO pin 27 output enable
            U32 POE28 :1;               // GPIO pin 28 output enable
            U32 POE29 :1;               // GPIO pin 29 output enable
            U32 POE30 :1;               // GPIO pin 30 output enable
            U32 POE31 :1;               // GPIO pin 31 output enable
        } B;
    } POER; // GPIO port output enable register (Offset: 0x14; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 PIE0  :1;               // GPIO pin 0 input enable
            U32 PIE1  :1;               // GPIO pin 1 input enable
            U32 PIE2  :1;               // GPIO pin 2 input enable
            U32 PIE3  :1;               // GPIO pin 3 input enable
            U32 PIE4  :1;               // GPIO pin 4 input enable
            U32 PIE5  :1;               // GPIO pin 5 input enable
            U32 PIE6  :1;               // GPIO pin 6 input enable
            U32 PIE7  :1;               // GPIO pin 7 input enable
            U32 PIE8  :1;               // GPIO pin 8 input enable
            U32 PIE9  :1;               // GPIO pin 9 input enable
            U32 PIE10 :1;               // GPIO pin 10 input enable
            U32 PIE11 :1;               // GPIO pin 11 input enable
            U32 PIE12 :1;               // GPIO pin 12 input enable
            U32 PIE13 :1;               // GPIO pin 13 input enable
            U32 PIE14 :1;               // GPIO pin 14 input enable
            U32 PIE15 :1;               // GPIO pin 15 input enable
            U32 PIE16 :1;               // GPIO pin 16 input enable
            U32 PIE17 :1;               // GPIO pin 17 input enable
            U32 PIE18 :1;               // GPIO pin 18 input enable
            U32 PIE19 :1;               // GPIO pin 19 input enable
            U32 PIE20 :1;               // GPIO pin 20 input enable
            U32 PIE21 :1;               // GPIO pin 21 input enable
            U32 PIE22 :1;               // GPIO pin 22 input enable
            U32 PIE23 :1;               // GPIO pin 23 input enable
            U32 PIE24 :1;               // GPIO pin 24 input enable
            U32 PIE25 :1;               // GPIO pin 25 input enable
            U32 PIE26 :1;               // GPIO pin 26 input enable
            U32 PIE27 :1;               // GPIO pin 27 input enable
            U32 PIE28 :1;               // GPIO pin 28 input enable
            U32 PIE29 :1;               // GPIO pin 29 input enable
            U32 PIE30 :1;               // GPIO pin 30 input enable
            U32 PIE31 :1;               // GPIO pin 31 input enable
        } B;
    } PIER; // GPIO port input enable register (Offset: 0x18; Reset: 0xFFFF.FFFF)

    union {
        U32 R;
        struct {
            U32 PIF0  :1;               // GPIO pin 0 interrupt status flag
            U32 PIF1  :1;               // GPIO pin 1 interrupt status flag
            U32 PIF2  :1;               // GPIO pin 2 interrupt status flag
            U32 PIF3  :1;               // GPIO pin 3 interrupt status flag
            U32 PIF4  :1;               // GPIO pin 4 interrupt status flag
            U32 PIF5  :1;               // GPIO pin 5 interrupt status flag
            U32 PIF6  :1;               // GPIO pin 6 interrupt status flag
            U32 PIF7  :1;               // GPIO pin 7 interrupt status flag
            U32 PIF8  :1;               // GPIO pin 8 interrupt status flag
            U32 PIF9  :1;               // GPIO pin 9 interrupt status flag
            U32 PIF10 :1;               // GPIO pin 10 interrupt status flag
            U32 PIF11 :1;               // GPIO pin 11 interrupt status flag
            U32 PIF12 :1;               // GPIO pin 12 interrupt status flag
            U32 PIF13 :1;               // GPIO pin 13 interrupt status flag
            U32 PIF14 :1;               // GPIO pin 14 interrupt status flag
            U32 PIF15 :1;               // GPIO pin 15 interrupt status flag
            U32 PIF16 :1;               // GPIO pin 16 interrupt status flag
            U32 PIF17 :1;               // GPIO pin 17 interrupt status flag
            U32 PIF18 :1;               // GPIO pin 18 interrupt status flag
            U32 PIF19 :1;               // GPIO pin 19 interrupt status flag
            U32 PIF20 :1;               // GPIO pin 20 interrupt status flag
            U32 PIF21 :1;               // GPIO pin 21 interrupt status flag
            U32 PIF22 :1;               // GPIO pin 22 interrupt status flag
            U32 PIF23 :1;               // GPIO pin 23 interrupt status flag
            U32 PIF24 :1;               // GPIO pin 24 interrupt status flag
            U32 PIF25 :1;               // GPIO pin 25 interrupt status flag
            U32 PIF26 :1;               // GPIO pin 26 interrupt status flag
            U32 PIF27 :1;               // GPIO pin 27 interrupt status flag
            U32 PIF28 :1;               // GPIO pin 28 interrupt status flag
            U32 PIF29 :1;               // GPIO pin 29 interrupt status flag
            U32 PIF30 :1;               // GPIO pin 30 interrupt status flag
            U32 PIF31 :1;               // GPIO pin 31 interrupt status flag
        } B;
    } PIFR; // GPIO port interrupt status flag register (Offset: 0x1c; Reset: 0xFFFF.FFFF)

    U32 GPIO_Reserved0[24U];

    union {
        U32 R;
        struct {
            U32 IRQC :4;                // GPIO interrupt configuration
            U32 INVE :1;                // GPIO invert the input level
            U32      :11;
            U32 DFE  :1;                // GPIO digital filter enable
            U32      :7;
            U32 DFW  :5;                // GPIO digital filter width
            U32      :3;
        } B;
    } PCR[32U]; // GPIO port control register (Offset: 0x80; Reset: 0x0000.0000)

} GPIO_tag; // end of GPIO_tag



//**************************************************************************************************
//! Local Interconnect Network (LINFlexD)
//**************************************************************************************************
typedef volatile struct LINFlexD_struct {
    union {
        U32 R;
        struct {
            U32 INIT   :1;              // Initialization Mode Request
            U32 SLEEP  :1;              // Sleep Mode Request
            U32 RBLM   :1;              // Receiver Buffer Locked Mode
            U32 SSBL   :1;              // Slave Mode Sync Break Length
            U32 MME    :1;              // Master Mode Enable
            U32 LBKM   :1;              // Loop Back Mode
            U32        :1;
            U32 BF     :1;              // Bypass Filter
            U32 MBL    :4;              // Master Break Length
            U32 AUTOWU :1;              // Automatic Wake-Up
            U32 LASE   :1;              // LIN Autosynchronization Enable
            U32 CFD    :1;              // Checksum Field Disable
            U32 CCD    :1;              // Checksum Calculation Disable
            U32 NLSE   :1;              // LIN State Capture Enable on Bit Error
            U32        :15;
        } B;
    } LINCR1; // LIN Control Register 1 (Offset: 0x0; Reset: 0x00000082)

    union {
        U32 R;
        struct {
            U32 HRIE :1;                // Header Received Interrupt Enable
            U32 DTIE :1;                // Data Transmitted Interrupt Enable
            U32 DRIE :1;                // Data Reception Complete Interrupt Enable
            U32 TOIE :1;                // Timeout Interrupt Enable
            U32      :1;
            U32 WUIE :1;                // Wakeup Interrupt Enable
            U32 LSIE :1;                // LIN State Interrupt Enable
            U32 BOIE :1;                // Buffer Overrun Interrupt Enable
            U32 FEIE :1;                // Frame Error Interrupt Enable
            U32      :2;
            U32 HEIE :1;                // Header Error Interrupt Enable
            U32 CEIE :1;                // Checksum Error Interrupt Enable
            U32 BEIE :1;                // Bit Error Interrupt Enable
            U32 OCIE :1;                // Output Compare Interrupt Enable
            U32 SZIE :1;                // Stuck at Zero Interrupt Enable
            U32      :16;
        } B;
    } LINIER; // LIN Interrupt Enable Register (Offset: 0x4; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 HRF           :1;       // Header Received Flag
            U32 DTF           :1;       // Data Transmission Completed Flag
            U32 DRF           :1;       // Data Reception Completed Flag
            U32               :2;
            U32 WUF           :1;       // Wakeup Flag
            U32 RDI           :1;       // Receiver Data Input
            U32 RXBUSY        :1;       // Receiver Busy Flag
            U32 DRBNE         :1;       // Data Reception Buffer Not Empty Flag
            U32 RMB           :1;       // Release Message Buffer
            U32               :2;
            U32 LINS          :4;       // LIN State
            U32 RDC           :3;       // Receive Data Byte Count
            U32 AUTOSYNC_COMP :1;       // Autosynchronization Complete
            U32               :12;
        } B;
    } LINSR; // LIN Status Register (Offset: 0x8; Reset: 0x00000040)

    union {
        U32 R;
        struct {
            U32 NF    :1;               // Noise Flag
            U32       :6;
            U32 BOF   :1;               // Buffer Overrun Flag
            U32 FEF   :1;               // Framing Error Flag
            U32 IDPEF :1;               // ID Parity Error Flag
            U32 SDEF  :1;               // Break Delimiter Error Flag
            U32 SFEF  :1;               // Sync Field Error Flag
            U32 CEF   :1;               // Checksum Error Flag
            U32 BEF   :1;               // Bit Error Flag
            U32 OCF   :1;               // Output Compare Flag
            U32 SZF   :1;               // Stuck at Zero Flag
            U32       :16;
        } B;
    } LINESR; // LIN Error Status Register (Offset: 0xC; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 UART     :1;            // UART Mode Enable
            U32 WL0      :1;            // Word Length 0 in UART Mode
            U32 PCE      :1;            // Parity Control Enable
            U32 PC0      :1;            // Parity Control 0
            U32 TXEN     :1;            // Transmitter Enable
            U32 RXEN     :1;            // Receiver Enable
            U32 PC1      :1;            // Parity Control 1
            U32 WL1      :1;            // Word Length 1 in UART Mode
            U32 TFBM     :1;            // Tx FIFO / Buffer Mode
            U32 RFBM     :1;            // Rx FIFO / Buffer Mode
            U32 RDFL_RFC :3;            // Receiver Data Field Length / Rx FIFO Counter
            U32 TDFL_TFC :3;            // Transmitter Data Field Length / Tx FIFO Counter
            U32 WLS      :1;            // Special Word Length in UART Mode
            U32 SBUR     :2;            // Number of Stop Bits in UART Reception Mode
            U32 DTU      :1;            // Disable Timeout in UART mode
            U32 NEF      :3;            // Number of Expected Frames
            U32 ROSE     :1;            // Reduced Oversampling Enable
            U32 OSR      :4;            // Oversampling Rate
            U32 CSP      :3;            // Configurable Sample Point
            U32 MIS      :1;            // Monitor Idle State
        } B;
    } UARTCR; // UART Mode Control Register (Offset: 0x10; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 NF      :1;             // Noise Flag
            U32 DTF_TFF :1;             // Data Transmission Completed Flag / Tx FIFO Full Flag
            U32 DRF_RFE :1;             // Data Reception Completed Flag / Rx FIFO Empty Flag
            U32 TO      :1;             // Timeout
            U32 RFNE    :1;             // Receive FIFO Not Empty
            U32 WUF     :1;             // Wakeup Flag
            U32 RDI     :1;             // Receiver Data Input
            U32 BOF     :1;             // FIFO/Buffer Overrun Flag
            U32 FEF     :1;             // Framing Error Flag
            U32 RMB     :1;             // Release Message Buffer
            U32 PE      :4;             // Parity Error Flag
            U32 OCF     :1;             // Output Compare Flag
            U32 SZF     :1;             // Stuck at Zero Flag
            U32         :16;
        } B;
    } UARTSR; // UART Mode Status Register (Offset: 0x14; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CNT  :8;                // Counter Value
            U32 TOCE :1;                // Timeout Counter Enable
            U32 IOT  :1;                // Idle on Timeout
            U32 MODE :1;                // Timeout Counter Mode
            U32      :21;
        } B;
    } LINTCSR; // LIN Timeout Control Status Register (Offset: 0x18; Reset: 0x00000200)

    union {
        U32 R;
        struct {
            U32 OC1 :8;                 // Output compare value 1
            U32 OC2 :8;                 // Output compare value 2
            U32     :16;
        } B;
    } LINOCR; // LIN Output Compare Register (Offset: 0x1c; Reset: 0x0000FFFF)

    union {
        U32 R;
        struct {
            U32 HTO :7;                 // Header Timeout Value
            U32     :1;
            U32 RTO :4;                 // Response Timeout Value
            U32     :20;
        } B;
    } LINTOCR; // LIN Timeout Control Register (Offset: 0x20; Reset: 0x00000E2C)

    union {
        U32 R;
        struct {
            U32 FBR :4;                 // Fractional Baud Rate
            U32     :28;
        } B;
    } LINFBRR; // LIN Fractional Baud Rate Register (Offset: 0x24; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 IBR :20;                // Integer Baud Rate
            U32     :12;
        } B;
    } LINIBRR; // LIN Integer Baud Rate Register (Offset: 0x28; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CF :8;                  // Checksum Bits
            U32    :24;
        } B;
    } LINCFR; // LIN Checksum Field Register (Offset: 0x2c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32      :8;
            U32 HTRQ :1;                // Header Transmission Request
            U32 ABRQ :1;                // Abort Request
            U32 DTRQ :1;                // Data Transmission Request
            U32 DDRQ :1;                // Data Discard Request
            U32 WURQ :1;                // Wakeup Generate Request
            U32 IOPE :1;                // Idle on Identifier Parity Error
            U32 IOBE :1;                // Idle on Bit Error
            U32 TBDE :1;                // Two-Bit Delimiter Enable
            U32      :16;
        } B;
    } LINCR2; // LIN Control Register 2 (Offset: 0x30; Reset: 0x00006000)

    union {
        U32 R;
        struct {
            U32 ID  :6;                 // Identifier
            U32     :2;
            U32 CCS :1;                 // Classic Checksum
            U32 DIR :1;                 // Direction
            U32 DFL :3;                 // Data Field Length
            U32     :19;
        } B;
    } BIDR; // Buffer Identifier Register (Offset: 0x34; Reset: 0x00000000)

    union {
        U8   DATA8[8];  // Data in byte (DATA_DATA8)
        U16  DATA16[4]; // Data in half-word (DATA_DATA16)
        U32  DATA32[2]; // Data in word (DATA_DATA32)
    } DATA; // Data buffer ( Offset: 0x38; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 FACT :16;               // Filter Active
            U32      :16;
        } B;
    } IFER; // Identifier Filter Enable Register (Offset: 0x40; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 IFMI :5;                // Filter Match Index
            U32      :27;
        } B;
    } IFMI; // Identifier Filter Match Index (Offset: 0x44; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 IFM :8;                 // Filter Mode
            U32     :24;
        } B;
    } IFMR; // Identifier Filter Mode Register (Offset: 0x48; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 ID  :6;                 // Identifier
            U32     :2;
            U32 CCS :1;                 // Classic Checksum
            U32 DIR :1;                 // Direction
            U32 DFL :3;                 // Data Field Length
            U32     :19;
        } B;
    } IFCR[16U]; // Identifier Filter Control Register (Offset: 0x4c-88; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 SR    :1;               // Soft Reset
            U32 STOP  :1;               // One or Two Stop Bit Configuration
            U32 RDLIS :1;               // Received Data Level Inversion Selection
            U32 TDLIS :1;               // Transmit Data Level Inversion Selection
            U32 RDFBM :1;               // Receive Data First Bit MSB
            U32 TDFBM :1;               // Transmit Data First Bit MSB
            U32       :26;
        } B;
    } GCR; // Global Control Register (Offset: 0x8c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 PTO :12;                // Preset Timeout
            U32     :20;
        } B;
    } UARTPTO; // UART Preset Timeout Register (Offset: 0x90; Reset: 0x00000FFF)

    union {
        U32 R;
        struct {
            U32 CTO :12;                // Preset Timeout
            U32     :20;
        } B;
    } UARTCTO; // UART Current Timeout Register (Offset: 0x94; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 DTE :16;                // DMA Tx Channel n Enable
            U32     :16;
        } B;
    } DMATXE; // DMATx Enable Register (Offset: 0x98; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 DRE :16;                // DMA Tx Channel n Enable
            U32     :16;
        } B;
    } DMARXE; // DMA Rx Enable Register (Offset: 0x9c; Reset: 0x00000000)

} LINFlexD_tag; // end of LINFlexD_tag



//**************************************************************************************************
//! Low Power Timer (LPTMR) memory map
//**************************************************************************************************
typedef volatile struct LPTMR_struct {
    union {
        U32 R;
        struct {
            U32 EN     :1;              // Timer Enable
            U32 MODE   :1;              // Timer Mode Select
            U32 TMODE  :1;              // Timer Free-Running Mode
            U32 PINPOL :1;              // Timer Pin Polarity
            U32 PINSEL :2;              // Timer Pin Select
            U32        :26;
        } B;
    } CTRL; // Control Register (Offset: 0x00; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CLKSEL :2;              // Clock Selection
            U32 BYPASS :1;              // Prescaler Bypass
            U32 PRES   :4;              // Prescaler Value
            U32        :25;
        } B;
    } PRS; // Prescaler Register (Offset: 0x04; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 IE    :2;               // Timer DMA Request Enable
            U32 DMAEN :1;               // Timer Interrupt Enable
            U32       :29;
        } B;
    } DIE; // DMA and Interrupt Enable Register (Offset: 0x08; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CCF :1;                 // Counter Compare Flag
            U32     :31;
        } B;
    } STS; // Status Register (Offset: 0x0c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CMP :16;                // Compare Value
            U32     :16;
        } B;
    } CMP; // Compare Value Register (Offset: 0x10; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 LCVAL :16;              // Latch Timer Counter Value
            U32       :16;
        } B;
    } LCNT; // Latch Timer Counter Register (Offset: 0x14; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CVAL :16;               // Timer Current Counter value
            U32      :16;
        } B;
    } CNT; // Timer Current Counter Register (Offset: 0x18; Reset: 0x00000000)

} LPTMR_tag; // end of LPTMR_tag



//**************************************************************************************************
//! Port Control (PCTRL) memory map
//**************************************************************************************************
typedef volatile struct PCTRL_struct {
    union {
        U32 R;
        struct {
            U32 PS  :1;                 // Pulldown / Pullup
            U32 PE  :1;                 // Pull enable
            U32 SRE :1;                 // Slew rate enable
            U32     :1;
            U32 PFE :1;                 // Passive filter enable
            U32     :1;
            U32 DSE :1;                 // Drive strength configuration
            U32     :1;
            U32 MUX :3;                 // Port function selection
            U32     :21;
        } B;
    } PCR[32U]; // GPIO port pin control register (Offset: 0x00; Reset: 0x0000.0000)

} PCTRL_tag; // end of PCTRL_tag



//**************************************************************************************************
//! Power Control Unit (PCU) memory map
//**************************************************************************************************
typedef volatile struct PCU_struct {
    union {
        U32 R;
        struct {
            U32 LVD50F   :1;            // Low voltage detect flag on VDD in FPM
            U32 LVD50LPF :1;            // Low voltage detect flag on VDD in RPM
            U32          :1;
            U32 HVD50F   :1;            // High voltage detect flag on VDD in FPM
            U32          :4;
            U32 LVD25F   :1;            // Low voltage detect flag on VDD25 in FPM
            U32 LVD25LPF :1;            // Low voltage detect flag on VDD25 in RPM
            U32          :1;
            U32 HVD25F   :1;            // High voltage detect flag on VDD25 in FPM
            U32          :3;
            U32 GNG25F   :1;            // Go/NoGo detect flag on V25 domain Flags
            U32 LVD11F   :1;            // Low voltage detect flag on VDD11 in FPM
            U32 LVD11LPF :1;            // Low voltage detect flag on VDD11 in RPM
            U32          :1;
            U32 HVD11F   :1;            // High voltage detect flag on VDD11 in FPM
            U32          :3;
            U32 GNG11F   :1;            // Go/NoGo detect flag on V11 domain Flags
            U32          :7;
            U32 PORF     :1;            // Flags that a power on reset event has occurred.
        } B;
    } STS; // Status Register (Offset: 0x00; Reset: 0x80000000)

    union {
        U32 R;
        struct {
            U32 LVD50S :1;              // Low voltage detect status on VDD in FPM
            U32        :2;
            U32 HVD50S :1;              // High voltage detect status on VDD in FPM
            U32        :4;
            U32 LVD25S :1;              // Low voltage detect status on VDD25 in FPM
            U32        :2;
            U32 HVD25S :1;              // High voltage detect status on VDD25 in FPM
            U32        :4;
            U32 LVD11S :1;              // Low voltage detect status on VDD11 in FPM
            U32        :2;
            U32 HVD11S :1;              // High voltage detect status on VDD11 in FPM
            U32        :12;
        } B;
    } SSTS; // Sticky Status Register (Offset: 0x04; Reset: 0x03000000)

    union {
        U32 R;
        struct {
            U32 LVD50IE :1;             // Low voltage detect interrupt request on VDD
            U32         :2;
            U32 HVD50IE :1;             // High voltage detect interrupt request on VDD
            U32         :4;
            U32 LVD25IE :1;             // Low voltage detect interrupt request on VDD25
            U32         :2;
            U32 HVD25IE :1;             // High voltage detect interrupt request on VDD25
            U32         :4;
            U32 LVD11IE :1;             // Low voltage detect interrupt request on VDD11
            U32         :2;
            U32 HVD11IE :1;             // High voltage detect interrupt request on VDD11
            U32         :12;
        } B;
    } INTE; // Interrupt Register (Offset: 0x08; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 RPMEN     :1;           // Reduced Performance Mode Enable bit
            U32 STANDBYEN :1;           // Standby Mode Enable bit
            U32           :6;
            U32 FASTREC   :1;           // Fast Recovery from LPM Enable bit
            U32           :6;
            U32 HVDRE     :1;           // High voltage detect reset enable
            U32           :16;
        } B;
    } CTRL; // Control Register (Offset: 0x0C; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 LV50FAM  :4;            // Trim bits of LV50FAM
            U32 LV50RAM  :4;            // Trim bits of LV50RAM
            U32 LDV50FAM :4;            // Trim bits of LDV50FAM
            U32 HV50FAM  :4;            // Trim bits of HV50FAM
            U32          :16;
        } B;
    } TRIM50; // TRIM50 Register (Offset: 0x10; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 LV25FM :4;              // Trim bits of LV25FM
            U32 LV25RM :4;              // Trim bits of LV25RM
            U32        :4;
            U32 HV25FM :4;              // Trim bits of HV25FM
            U32 V25F   :4;              // Trim bits of V25F
            U32 V25R   :4;              // Trim bits of V25R
            U32        :8;
        } B;
    } TRIM25; // TRIM25 Register (Offset: 0x14; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 LV11FM    :4;           // Trim bits of LV11FM
            U32 LV11RM    :4;           // Trim bits of LV11RM
            U32 V11R      :4;           // Trim bits of V11R
            U32 HV11F     :4;           // Trim bits of HV11F
            U32 BOOT_V11F :4;           // Trim bits of BOOT_V11F
            U32           :4;
            U32 V12R      :4;           // Trim bits of V12R
            U32           :4;
        } B;
    } TRIM11; // TRIM11 Register (Offset: 0x18; Reset: 0x00000000)

} PCU_tag; // end of PCU_tag



//**************************************************************************************************
//! Peripheral Protection Unit (PPU) memory map
//**************************************************************************************************
typedef volatile struct PPU_struct {
    U8 PPU_Reserved0[3072U];

    union {
        U8 R;
        struct {
            U8 LOCKBIT :1;              // Lock Bit
            U8         :3;
            U8 WREN    :1;              // Write Enable
            U8         :3;
        } B;
    } SLOCK[256U]; // Soft Lock Register (SLOCK) (Offset: 0xC00-0xCFF ; Reset: 0x00)

    U32 PPU_Reserved1[191U];

    union {
        U32 R;
        struct {
            U32 HLOCK :1;               // Hard Lock
            U32       :7;
            U32 UAE   :1;               // User Access Enable
            U32       :23;
        } B;
    } PROTCFG; // Protect Configuration Register (PROTCFG) (Offset: 0xFFC ; Reset: 0x00000000)

} PPU_tag; // end of PPU_tag



//**************************************************************************************************
//! Periodic Timer (PTMR) memory map
//**************************************************************************************************
typedef volatile struct PTMR_struct {
    union {
        U32 R;
        struct {
            U32 EN  :1;                 // Timer Enable
            U32 FRZ :1;                 // Freeze
            U32     :30;
        } B;
    } MCR; // Module Control Register (Offset: 0x00; Reset: 0x00000000)

    U32 PTMR_Reserved0[63U];

    struct {
        union {
            U32 R;
            struct {
                U32 STVAL :32;          // Start Value
            } B;
        } TSV; // Timer Start Value Register (Offset: 0x100; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 CVAL :32;           // Current Value
            } B;
        } TCV; // Timer Current Value Register (Offset: 0x104; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 TIF   :1;           // Timer Enable
                U32 TIE   :1;           // Timer Interrupt Enable
                U32 CHAIN :1;           // Chain Mode
                U32       :29;          // Channel Compare
            } B;
        } TCR; // Timer Control Register (Offset: 0x108; Reset: 0x00000000)

         union {
            U32 R;
            struct {
                U32 TIF :1;             // Timer Interrupt Flag
                U32     :31;
            } B;
        } TFR; // Timer Flag Register (Offset: 0x10C; Reset: 0x00000000)

    } CH[4U]; // Four 32-bit Compare Channels

} PTMR_tag; // end of PTMR_tag



//**************************************************************************************************
//! Programmable Trigger Unit (PTU) memory map
//**************************************************************************************************
typedef volatile struct PTU_struct {
    union {
        U32 R;
        struct {
            U32 EN     :1;              // PTU Enable
            U32 LDOK   :1;              // Load OK
            U32 LDMD   :1;              // Load Mode Select
            U32 CONT   :1;              // Continuous Mode Enable
            U32 HWTRIG :1;              // External Trigger Enable
            U32 DMAEN  :1;              // DMA enable
            U32 SWTRIG :1;              // Software Trigger
            U32        :25;
        } B;
    } CTRL; // Control Register (Offset: 0x00 ; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 MULT :2;                // Multiplication Factor Select for Prescaler
            U32 DIV  :3;                // Divider Select
            U32      :27;
        } B;
    } PRS; // Prescaler Select Register (Offset: 0x04 ; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 IE  :1;                 // PTU interrupt enable
            U32 EIE :1;                 // PTU sequence error interrupt enable
            U32     :30;
        } B;
    } INTE; // Interrupt Enable Register (Offset: 0x08 ; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 IF  :1;                 // PTU Interrupt Flag
            U32 EIF :1;                 // PTU Sequence Error Interrupt Flag
            U32     :30;
        } B;
    } STS; // Interrupt Flag Register (Offset: 0x0c ; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 MOD :16;                // Modulus
            U32     :16;
        } B;
    } MOD; // Modulus Register (Offset: 0x10 ; Reset: 0x0000FFFF)

    union {
        U32 R;
        struct {
            U32 CNT :16;                // PTU counter current value
            U32     :16;
        } B;
    } CNT; // Counter Current Value Register (Offset: 0x14 ; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 INTDLY :16;             // PTU interrupt delay
            U32        :16;
        } B;
    } INTDLY; // Interrupt Delay Register (Offset: 0x18 ; Reset: 0x0000FFFF)

    union {
        U32 R;
        struct {
            U32 CHEN    :8;             // Channel trigger n enable
            U32 CHDLYEN :8;             // Channel trigger n scale delay disable
            U32         :16;
        } B;
    } CHCTRL; // Channel Control Register (Offset: 0x20 ; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CHEF :8;                // PTU Channel trigger n sequence error flags
            U32      :8;
            U32 CHF  :8;                // PTU Channel Flags
            U32      :8;
        } B;
    } CHSTS; // Channel Status Register (Offset: 0x24 ; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CHDLYn :16;             // Channel Delay n
            U32        :16;
        } B;
    } CHDLYn[8U]; // Channel Delay n Register (Offset: 0x28-44 ; Reset: 0x00000000)

    U32 PTU_Reserved0[82U];
    union {
        U32 R;
        struct {
            U32 POEN :1;                // PTU pulse-out enable
            U32      :31;
        } B;
    } POEN; // Pulse-Out Enable Register (Offset: 0x190 ; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 PODLY0 :16;             // PTU Pulse-Out Delay 0
            U32 PODLY1 :16;             // PTU Pulse-Out Delay 1
        } B;
    } PODLY; // Pulse-Out Delay Register (Offset: 0x194 ; Reset: 0x00000000)

} PTU_tag; // end of PTU_tag



//**************************************************************************************************
//! Reset Control Unit (RCU) memory map
//**************************************************************************************************
typedef volatile struct RCU_struct {
    union {
        U32 R;
        struct {
            U32 LVD          :1;        // Power On Reset or Low Voltage Detect
            U32 PIN          :1;        // Pin Reset
            U32              :6;
            U32 SW           :1;        // Software Reset
            U32 DBG          :1;        // Debug Reset
            U32              :6;
            U32 LOCKUP       :1;        // ARM Core Lockup Reset
            U32 CMU          :1;        // Clock Monitor Reset
            U32 WTDG         :1;        // Watch Dog Reset
            U32 DEEPSLEEPACK :1;        // DEEPSLEEPACK Reset
            U32 HVD          :1;        // High Voltage Detect Reset
            U32              :11;
        } B;
    } RSSR; // Reset Source Status Register (Offset: 0x00; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 FLTEN       :1;         // Reset pin filter enable
            U32 FLTSTEN     :1;         // Reset pin filter enable at deepsleep mode
            U32             :6;
            U32 FLTVAL      :8;         // Reset pin filter counter value
            U32 RSTPIN_OBEN :1;         // Reset pin output enable
            U32 RSTPIN_IBE  :1;         // Reset pin input enable
            U32             :14;
        } B;
    } RPFR; // Reset Pin Filter Register (Offset: 0x04; Reset: 0x0000.0000)

} RCU_tag; // end of RCU_tag



//**************************************************************************************************
//! Register File (REGFILE) memory map
//**************************************************************************************************
typedef volatile struct REGFILE_struct {
    union {
        U32 R;
        struct {
            U32 DATA :32;               // Data value
        } B;
    } DR[8U]; // Data Register (Offset: 0x00; Reset: 0x00000000)

} REGFILE_tag; // end of REGFILE_tag



//**************************************************************************************************
//! Real Time Clock Module (RTC) memory map
//**************************************************************************************************
typedef volatile struct RTC_struct {
    union {
        U32 R;
        struct {
            U32 SEC :32;                // Second Value
        } B;
    } SEC; // Second Register (Offset: 0x00; Reset: 0x00000000)

    U32 RTC_Reserved0[1U];

    union {
        U32 R;
        struct {
            U32 CMPV   :8;              // Compensation Value
            U32 CMPIV  :8;              // Compensation Interval Value
            U32 CMPVS  :8;              // Compensation Value Status
            U32 CMPIVS :8;              // Compensation Interval StatusSecond Value
        } B;
    } CMP; // Compensation Register (Offset: 0x08; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 ALM :32;                // Alarm Value
        } B;
    } ALM; // Alarm Register (Offset: 0x0c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 EN :1;                  // RTC Module Enable
            U32    :31;
        } B;
    } EN; // Enable Register (Offset: 0x10; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 SWRST     :1;           // Software Reset
            U32 CLKSEL    :1;           // RTC Clock Select
            U32 CLKOUTSEL :1;           // RTC Clock Output Select
            U32 CLKOUTEN  :1;           // RTC Clock Output Enable
            U32 UNLOCK    :1;           // Unlock Mode
            U32 DBGDIS    :1;           // Debug Mode Disable
            U32           :26;
        } B;
    } CTRL; // Control Register (Offset: 0x14; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 OVFIF :1;               // Overflow Interrupt Flag
            U32 ALMIF :1;               // Alarm Interrupt Flag
            U32 SECIF :1;               // Second Interrupt Flag
            U32       :29;
        } B;
    } INTF; // Interrupt Flag Register (Offset: 0x18; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 OVFIE  :1;              // Overflow Interrupt Enable
            U32 ALMIE  :1;              // Alarm Interrupt Enable
            U32 SECIE  :1;              // Second Interrupt Enable
            U32        :5;
            U32 SECOCS :3;              // Second Output Clock Select
            U32        :21;
        } B;
    } INTE; // Interrupt Enable Register (Offset: 0x1c; Reset: 0x00000003)

} RTC_tag; // end of RTC_tag



//**************************************************************************************************
//! System Clock Unit (SCU) memory map
//**************************************************************************************************
typedef volatile struct SCU_struct {
    union {
        U32 R;
        struct {
            U32 CLKSRCSEL :2;           // System Clock Source selection bits
            U32           :30;
        } B;
    } CLKS; // Clock Selection Register (Offset: 0x00; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 SBDIVS :4;              // Slow Bus Clock Divider Value
            U32        :4;
            U32 FBDIVS :4;              // Fast Bus Clock Divider Value
            U32        :4;
            U32 CPDIVS :4;              // Core Platform Clock Divider Value
            U32        :12;
        } B;
    } DIV; // DIV Register (Offset: 0x04; Reset: 0x0001.0001)

    union {
        U32 R;
        struct {
            U32 CLKST       :2;         // System Clock Source selection status bits
            U32 FIRC_VALID  :1;         // FIRC Clock valid
            U32 FXOSC_VALID :1;         // FXOSC Clock valid
            U32 SXOSC_VALID :1;         // SXOSC Clock valid
            U32 PLL_LOCK    :1;         // PLL Lock bit
            U32             :26;
        } B;
    } STS; // Status register (Offset: 0x08; Reset: 0x0000.0004)

    union {
        U32 R;
        struct {
            U32 SBDIVST :4;             // Slow Bus Clock Divider Value
            U32         :4;
            U32 FBDIVST :4;             // Fast Bus Clock Divider Value
            U32         :4;
            U32 CPDIVST :4;             // Core Platform Clock Divider Value
            U32         :12;
        } B;
    } DIVSTS; // Clock divider status register (Offset: 0x0C; Reset: 0x0001.0001)

    union {
        U32 R;
        struct {
            U32 FIRC_EN    :1;          // FIRC Enable
            U32 FIRC_DS_EN :1;          // FIRC Deepsleep Enable
            U32            :30;
        } B;
    } FIRC_CTRL; // FIRC control register (Offset: 0x10; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32             :1;
            U32 SIRC_DS_EN  :1;         // SIRC Deepsleep Enable
            U32 SIRC_STB_EN :1;         // SIRC Standby Enable
            U32 SIRC_PD_EN  :1;         // SIRC Power Down Enable
            U32             :28;
        } B;
    } SIRC_CTRL; // SIRC control register (Offset: 0x14; Reset: 0x0000.000F)

    union {
        U32 R;
        struct {
            U32 FXOSC_EN    :1;         // Fast XOSC Enable
            U32 FXOSC_DS_EN :1;         // FXOSC Deepsleep Enable
            U32             :2;
            U32 FXOSC_MODE  :1;         // FXOSC Mode Selection
            U32             :3;
            U32 GMSEL       :4;         // Gain select bit
            U32 COMPEN      :1;         // Comp enable bit
            U32 ALCDIS      :1;         // ALC disable bit
            U32 HYSTDIS     :1;         // Hys disable bit
            U32             :17;
        } B;
    } FXOSC_CTRL; // FXOSC control register (Offset: 0x18; Reset: 0x0000.000F)

    union {
        U32 R;
        struct {
            U32 SXOSC_EN     :1;        // SXOSC Enable
            U32 SXOSC_DS_EN  :1;        // SXOSC Deepsleep Enable
            U32 SXOSC_STB_EN :1;        // SXOSC Standby Enable
            U32 SXOSC_PD_EN  :1;        // SXOSC Power Down Enable
            U32 SXOSC_MODE   :1;        // SXOSC Bypass Mode Selection
            U32              :3;
            U32 GMSEL        :1;        // Gain select bit
            U32              :23;
        } B;
    } SXOSC_CTRL; // SXOSC control register (Offset: 0x1C; Reset: 0x0000.000F)

    union {
        U32 R;
        struct {
            U32 PLL_EN       :1;        // PLL Enable
            U32 PLL_DS_EN    :1;        // PLL Deepsleep Enable
            U32              :2;
            U32 REFCLKSRCSEL :1;        // Reference Clock Selection
            U32              :3;
            U32 REFDIV       :4;        // Reference Clock Divider Value
            U32              :4;
            U32 FBDIV        :6;        // Feedback Divider Value
            U32              :10;
        } B;
    } PLL_CTRL; // PLL control register (Offset: 0x20; Reset: 0x0000.000F)

    U32 SCU_Reserved0[2U];

    union {
        U32 R;
        struct {
            U32 CLKOSEL :3;             // Clock output source select
            U32         :5;
            U32 CLKODIV :8;             // Clock Output Divider
            U32         :16;
        } B;
    } CLKO; // Select the clock sources to output to chip IOs for external use (Offset: 0x2C; Reset: 0x0000.000F)

    union {
        U32 R;
        struct {
            U32 FIRC_FINE_TRIM   :8;    // FIRC FINE Trim bit
            U32 FIRC_COARSE_TRIM :6;    // FIRC COARSE Trim bit
            U32                  :2;
            U32 FIRC_FC_TRIM     :6;    // FIRC TC TRIM bit
            U32                  :10;
        } B;
    } FIRCTRIM; // FIRC trim controller register (Offset: 0x30; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 SIRC_CCO_TRIM  :6;      // SIRC CCO Trim bit
            U32                :2;
            U32 SIRC_CL_TRIM   :6;      // SIRC CL Trim bit
            U32                :2;
            U32 SIRC_TC_TRIM   :5;      // SIRC TC Trim bit
            U32                :3;
            U32 SIRC_FVCH_TRIM :5;      // SIRC FVCH Trim bit
            U32                :3;
        } B;
    } SIRCTRIM; // SIRC trim controller register(Offset: 0x34; Reset: 0x0000.0000)

    U32 SCU_Reserved1[2U];

    union {
        U32 R;
        struct {
            U32 CMU0_EN  :1;            // CMU0 enable
            U32 CMU1_EN  :1;            // CMU1 enable
            U32 CMU2_EN  :1;            // CMU2 enable
            U32 CMU3_EN  :1;            // CMU3 enable
            U32          :4;
            U32 CMU0_RE  :1;            // CMU0 reset enable
            U32 CMU1_RE  :1;            // CMU1 reset enable
            U32 CMU2_RE  :1;            // CMU2 reset enable
            U32 CMU3_RE  :1;            // CMU3 reset enable
            U32          :4;
            U32 CMU0_REF :1;            // CMU0 reference clock selected
            U32 CMU1_REF :1;            // CMU1 reference clock selected
            U32 CMU2_REF :1;            // CMU2 reference clock selected
            U32          :13;
        } B;
    } CMU_CTRL; // Control register (Offset: 0x40; Reset: 0x0000.0000)

    union {
        U32 R;
        struct {
            U32 CMU0_OUTRNG :1;         // CMU0 clock out of range
            U32 CMU1_OUTRNG :1;         // CMU1 clock out of range
            U32 CMU2_OUTRNG :1;         // CMU2 clock out of range
            U32 CMU3_OUTRNG :1;         // CMU3 clock out of range
            U32             :4;
            U32 CMU0_LOSR   :1;         // CMU0 loss of reference clock
            U32 CMU1_LOSR   :1;         // CMU1 loss of reference clock
            U32 CMU2_LOSR   :1;         // CMU2 loss of reference clock
            U32 CMU3_LOSR   :1;         // CMU3 loss of reference clock
            U32             :4;
            U32 CMU0_LOSC   :1;         // CMU0 loss of clock
            U32 CMU1_LOSC   :1;         // CMU1 loss of clock
            U32 CMU2_LOSC   :1;         // CMU2 loss of clock
            U32 CMU3_LOSC   :1;         // CMU3 loss of clock
            U32             :12;
        } B;
    } CMUSTS; // Status register (Offset: 0x44; Reset: 0x0000.0000)

    struct {
        union {
            U32 R;
            struct {
                U32 VAL :16;            // High comparison value
                U32     :16;
            } B;
        } HIGH; // HIGH Comparison Value Register (Offset: 0x48; Reset: 0x0000.FFFF)

        union {
            U32 R;
            struct {
                U32 VAL :16;            // Low comparison value
                U32     :16;
            } B;
        } LOW; // Low Comparison Value Register (Offset: 0x4C; Reset: 0x0000.0000)
    } CMUCMP[4U];

    U32 SCU_Reserved2[1U];

} SCU_tag; // end of SCU_tag



//**************************************************************************************************
//! Serial Port Interface (SPI) memory map
//**************************************************************************************************
typedef volatile struct SPI_struct {
    union {
        U32 R;
        struct {
            U32 EN      :1;             //  SPI Module Enable
            U32         :1;
            U32 MODE    :1;             //  SPI Mode Selection
            U32         :4;
            U32 RXMO    :1;             //  Receive Data Match Only
            U32 PINCFG  :2;             //  Pin configuration
            U32 CSPOL   :4;             //  SPI pin selection polarity selection
            U32 DHZEN   :1;             //  SPI Data Highz after transfer enable
            U32 CSDEN   :1;             //  SPI PCS[3:2] pin as data line enable
            U32 MATCFG  :3;             //  Match Configuration
            U32         :5;
            U32 SPDEN   :1;             //  Sample Point Delay Enable
            U32         :3;
            U32 RXDMAEN :1;             //  RX data DMA Enable
            U32 TXDMAEN :1;             //  TX data DMA Enable
            U32         :2;
        } B;
    } CTRL; // Control Register (Offset: 0x0; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 FRAMESZ  :12;           // Frame Size Control
            U32          :4;
            U32 WIDTH    :2;            // Data Width Control
            U32 MSKTX    :1;            // Mask TX Data
            U32 MSKRX    :1;            // Mask RX Data
            U32 CONTC    :1;            // Continuous Command
            U32 CONT     :1;            // Continuous Transfer
            U32 BSW      :1;            // Byte Swap Mode
            U32 LSBF     :1;            // LSB First Mode
            U32 PCS      :2;            // Peripheral Chip Selection
            U32          :1;
            U32 PRESCALE :3;            // Prescaler Value
            U32 CPHA     :1;            // Clock Phase
            U32 CPOL     :1;            // Clock Polity
        } B;
    } TXCFG; // Transmit Configuration Register (Offset: 0x4; Reset: 0x0000001F)


    union {
        U32 R;
        struct {
            U32 DIV    :8;              // SPI Clock Divider
            U32 FMDLY  :8;              // Frame Delay
            U32 PCSSCK :8;              // PCS to SCK Delay
            U32 SCKPCS :8;              // SCK to PCS Delay
        } B;
    } CLK; // Clock Configuration Register (Offset: 0x8; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 RXIF   :1;              // RX Request Read Data Flag
            U32 TXIF   :1;              // TX Request Data Flag
            U32        :1;
            U32 FCIF   :1;              // Frame Transmit Complete Interrupt Flag
            U32 TCIF   :1;              // Transmit Complete Interrupt Flag
            U32 TXUNIF :1;              // TX FIFO Underflow Interrupt Flag
            U32 RXOVIF :1;              // RX FIFO Overflow Interrupt Flag
            U32 MATIF  :1;              // Data Match Interrupt Flag
            U32        :8;
            U32 SOF    :1;              // Start of Frame
            U32 RXEPT  :1;              // SPI RX FIFO Empty Flag
            U32 BUSY   :1;              // SPI Module Busy
            U32        :13;
        } B;
    } STS; // Status Register (Offset: 0xc; Reset: 0x00020002)

    union {
        U32 R;
        struct {
            U32 RXIE   :1;              // RX Data Interrupt Enable
            U32 TXIE   :1;              // TX Data Interrupt Enable
            U32        :1;
            U32 FCIE   :1;              // SPI Frame Complete Interrupt Enable
            U32 TCIE   :1;              // SPI Transmit Complete Interrupt Enable
            U32 TXUNIE :1;              // TX FIFO Underflow Interrupt Enable
            U32 RXOVIE :1;              // RX FIFO Overflow Interrupt Enable
            U32 MATIE  :1;              // Data Match Interrupt Enable
            U32        :24;
        } B;
    } INTE; // Interrupt Enable Register (Offset: 0x10; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 MATCH0 :32;             // SPI Data Match Register 0
        } B;
    } MATCH0; // Data Match Register 0 (MATCH0) (Offset: 0x14; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 MATCH1 :32;             // SPI Data Match Register 1
        } B;
    } MATCH1; // Data Match Register 1 (Offset: 0x18; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 WATER :4;               // TX FIFO Watermark
            U32       :4;
            U32 COUNT :5;               // Word Count in TX FIFO
            U32       :2;
            U32 RESET :1;               // SPI TX FIFO Reset
            U32       :8;
            U32 SIZE  :5;               // SPI TX FIFO Size
            U32       :3;
        } B;
    } TXFIFO; // TX FIFO Configuration Register (Offset: 0x1c; Reset: 0x02000000)

    union {
        U32 R;
        struct {
            U32 WATER :4;               // RX FIFO Watermark
            U32       :4;
            U32 COUNT :5;               // Word Count in RX FIFO
            U32       :2;
            U32 RESET :1;               // SPI RX FIFO Reset
            U32       :8;
            U32 SIZE  :5;               // SPI RX FIFO Size
            U32       :3;
        } B;
    } RXFIFO; // RX FIFO Configuration Register (Offset: 0x20; Reset: 0x02000000)

    union {
        U32 R;
        struct {
            U32 DATA :32;               // RX TX Data Register
        } B;
    } DATA; // Data Register (Offset: 0x24; Reset: 0x00000000)

} SPI_tag; // end of SPI_tag



//**************************************************************************************************
//! Timer (TMR) memory map
//**************************************************************************************************
typedef volatile struct TMR_struct {
    union {
        U32 R;
        struct {
            U32 TEN    :1;              // Timer Enable
            U32 DBGDIS :1;              // Debug Disable
            U32        :30;
        } B;
    } CTRL; // Control Register (Offset: 0x00; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 PRS :8;                 // Timer Prescaler
            U32     :24;
        } B;
    } PRS; // Prescaler Register (Offset: 0x04; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CNT :32;                // Timer Count
        } B;
    } CNT; // Count Register (Offset: 0x08; Reset: 0x00000000)

    struct {
        union {
            U32 R;
            struct {
                U32 CHEN :1;            // Channel Enable
                U32      :31;
            } B;
        } CTRL; // Channel Control Register (Offset: 0x10-40; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 CHIF :1;            // Channel Interrupt Flag
                U32      :31;
            } B;
        } INT; // Channel Interrupt Register (Offset: 0x14-44; Reset: 0x00000000)

        union {
            U32 R;
            struct {
                U32 CHCMP :32;          // Channel Compare
            } B;
        } CMP; // Channel Compare Register (Offset: 0x18-48; Reset: 0x00000000)

    } CH[4U]; // Four 32-bit Compare Channels

} TMR_tag; // end of TMR_tag



//**************************************************************************************************
//! Trigger Multiplexer Module (TMU) memory map
//**************************************************************************************************
typedef volatile struct TMU_struct {
    union {
        U32 R;
        struct {
            U32 SEL0 :7;                // Trigger MUX Input Source Select 0
            U32      :1;
            U32 SEL1 :7;                // Trigger MUX Input Source Select 1
            U32      :1;
            U32 SEL2 :7;                // Trigger MUX Input Source Select 2
            U32      :1;
            U32 SEL3 :7;                // Trigger MUX Input Source Select 3
            U32 LOCK :1;                // Trigger MUX Locked
        } B;
    } TMU_MUX[32U]; // TMU MUX Register (Offset: 0x00; Reset: 0x0000.0000)

} TMU_tag; // end of TMU_tag



//**************************************************************************************************
//! True Random Number Generator (TRNG) memory map
//**************************************************************************************************
typedef volatile struct TRNG_struct {
    union {
        U32 R;
        struct {
            U32 SWR       :1;           // TRNG Software Reset
            U32 TRNG_EN   :1;           // TRNG Enable
            U32 OSC_DIV   :2;           // OSC Divider
            U32 CLK_OUT   :1;           // TRNG OSC Clock Output
            U32 UNLOCK    :1;           // Configuration Unlock Bit
            U32           :1;
            U32 FOR_SCLK  :1;           // Force System Clock
            U32 HW_ERRIE  :1;           // Hardware Error Interrupt Enable
            U32 ENT_VALIE :1;           // Entropy Valid Interrupt Enable
            U32 FRQ_CTIE  :1;           // Frequency Count Fail Interrupt Enable
            U32           :5;
            U32 LRUN_MAX  :8;           // Long Run Max Limit
            U32 RTY_CT    :4;           // Retry Count
            U32           :4;
        } B;
    } CTRL; // Control Register (Offset: 0x00; Reset: 0x01220020)

    union {
        U32 R;
        struct {
            U32            :1;
            U32 FCT_VAL    :1;          // Frequency Count Valid
            U32            :3;
            U32 IDLE       :1;          // IDLE
            U32            :2;
            U32 HW_ERR_IF  :1;          // Hardware Error Interrupt Flag
            U32 ENT_VAL_IF :1;          // Entropy Valid Interrupt Flag
            U32 FRQ_CT_IF  :1;          // Frequency Count Fail Interrupt Flag
            U32            :21;
        } B;
    } STAT; // Status Register (Offset: 0x04; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 SAMP_SIZE :16;          // Sample Size
            U32 ENT_DLY   :16;          // Entropy Delay
        } B;
    } SDCTL; // Seed Control Register (Offset: 0x08; Reset: 0x0C8009C4)

    union {
        U32 R;
        struct {
            U32 FRG_MIN :22;            // Frequency minimum limit value
            U32         :10;
        } B;
    } FRQMIN; // Frequency Minimum Limit Register (Offset: 0x0c; Reset: 0x00000640)

    union {
        U32 R;
        struct {
            U32 FRG_MIN :22;            // Frequency Maximum Limit Value
            U32         :10;
        } B;
    } FRQMAX; // Frequency Maximum Limit Register (Offset: 0x10; Reset: 0x00006400)

    union {
        U32 R;
        struct {
            U32 FRG_CT :22;             // Frequency Count Value
            U32        :10;
        } B;
    } FRQCNT; // Frequency Count Register (Offset: 0x14; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 MONO_MAX :16;           // Monobit Maximum Limit
            U32 MONO_RNG :16;           // Monobit Range
        } B;
    } SCML; // Statistical Check Monobit Limit Register (Offset: 0x18; Reset: 0x010C0568)

    union {
        U32 R;
        struct {
            U32 MONO_CT :16;            // Monobit Count
            U32         :16;
        } B;
    } SCMC; // Statistical Check Monobit Count Register (Offset: 0x1c; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 ENT :32;                // Entropy Value
        } B;
    } ENT[8U];// Entropy Read Register (Offset: 0x40-0x5c; Reset: 0x00000000)

} TRNG_tag; // end of TRNG_tag



//**************************************************************************************************
//! Watchdog (WDG) memory map
//**************************************************************************************************
typedef volatile struct WDG_struct {
    union {
        U32 R;
        struct {
            U32 SVCODE :16;             // Watchdog Service Code
            U32        :16;
        } B;
    } SVCR; // Service Code Register (Offset: 0x00; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 EN     :1;              // Module Enable
            U32 DBGDIS :1;              // Disable In Debug Mode
            U32 DSDIS  :1;              // Enable In Deepsleep Mode
            U32 CLKSRC :1;              // Clock Source
            U32 IBR    :1;              // Interrupt Before Reset
            U32 WIN    :1;              // Window Mode
            U32 RIA    :1;              // Reset Invalid Apb Enable
            U32        :25;
        } B;
    } CR; // Control Register (Offset: 0x04; Reset: 0x00000043)

    union {
        U32 R;
        struct {
            U32 SL :1;                  // Soft Lock
            U32 HL :1;                  // Hard Lock
            U32    :30;
        } B;
    } LR; // Lock Register (Offset: 0x08; Reset: 0x00000001)

    union {
        U32 R;
        struct {
            U32 TO :32;                 // Timer Overflow Value
        } B;
    } TOVR; // Timer Overflow Value (Offset: 0x0c; Reset: 0x00000300)

    union {
        U32 R;
        struct {
            U32 WIN :32;                // Watchdog Window Value
        } B;
    } WVR; // Window Value Register (Offset: 0x10; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 CVAL :32;               // Counter Current Value
        } B;
    } CNTCVR; // Counter Current Value Register (Offset: 0x14; Reset: 0x00000000)

    union {
        U32 R;
        struct {
            U32 IF :1;                  // Interrupt Flag.
            U32    :31;
        } B;
    } INTF; // Interrupt Flag register (Offset: 0x18; Reset: 0x00000000)

} WDG_tag; // end of WDG_tag



//**************************************************************************************************
//! Wake-up Unit (WKU) memory map
//**************************************************************************************************
typedef volatile struct WKU_struct {
    union {
        U8  R;
        struct {
            U8 WUPE  :2;                // Wake-up Pin Enable For WKU_Pn
            U8 WUPFE :1;                // Wake-up Pin Filter Enable
            U8 WUPFS :1;                // Wake-up Pin Filter Clock Select
            U8 WUPIE :1;                // Wake-up Pin Interrupt Enable
            U8       :3;
        } B;
    } PCR[32U]; // Pin Control Register (Offset: 0x00; Reset: 0x00)

    union {
        U32 R;
        struct {
            U32 WUF :32;                // Wake-up Flag for WKU_Pin
        } B;
    } PFR; // PFR Register (Offset: 0x20; Reset: 0x000000000)

    union {
        U32 R;
        struct {
            U32 WURPE  :1;              // Reset Pin Enable
            U32        :1;
            U32 WURPFE :1;              // Reset Pin Filter Enable
            U32 WURPFS :1;              // Reset Pin Filter Clock Select
            U32        :28;
        } B;
    } RPCR; // RPCR Register (Offset: 0x24; Reset: 0x000000000)

    union {
        U32 R;
        struct {
            U32 WUME :4;                // Wake-up Module Enable bits
            U32      :28;
        } B;
    } MER; // MER Register (Offset: 0x28; Reset: 0x000000000)

} WKU_tag; // end of WKU_tag



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

//! Analog Comparator
#define ACMP                    (*(ACMP_tag *)          0x40043000UL)

//! \name Analog-to-Digital Converter
//! @{
#define ADC0                    (*(ADC_tag *)           0x40040000UL)
#define ADC1                    (*(ADC_tag *)           0x40041000UL)
//! @}

//! Chip Integration Module
#define CIM                     (*(CIM_tag *)           0x4007B000UL)

//! Cyclic Redundancy Check
#define CRC                     (*(CRC_tag *)           0x40065000UL)

//! Direct memory access
#define DMA                     (*(DMA_tag *)           0x40008000UL)

//! Embedded FLASH Module
#define EFM                     (*(EFM_tag *)           0x40010000UL)

//! ECC Management Unit
#define EMU                     (*(EMU_tag *)           0x40072000UL)

//! \name Enhanced Timer
//! @{
#define ETMR0                   (*(ETMR_tag *)          0x40049000UL)
#define ETMR1                   (*(ETMR_tag *)          0x4004A000UL)
#define ETMR2                   (*(ETMR_tag *)          0x4004B000UL)
#define ETMR3                   (*(ETMR_tag *)          0x4004C000UL)
#define ETMR4                   (*(ETMR_tag *)          0x4004D000UL)
#define ETMR5                   (*(ETMR_tag *)          0x4004E000UL)
//! @}

//! External Watchdog (base address 4006b000h)
#define EWDG                    (*(EWDG_tag *)          0x4006B000UL)

//! \name Flexible Controller Area Network
//! @{
#define CAN0                    (*(FLEXCAN_tag *)       0x40030000UL)
#define CAN1                    (*(FLEXCAN_tag *)       0x40034000UL)
#define CAN2                    (*(FLEXCAN_tag *)       0x40038000UL)
#define CAN3                    (*(FLEXCAN_tag *)       0x4003c000UL)
#define CAN4                    (*(FLEXCAN_tag *)       0x4003d000UL)
#define CAN5                    (*(FLEXCAN_tag *)       0x4003e000UL)
//! @}

//! \name Inter-Integrated Circuit
//! @{
#define I2C0                    (*(I2C_tag *)           0x40023000UL)
#define I2C1                    (*(I2C_tag *)           0x40024000UL)
#define I2C2                    (*(I2C_tag *)           0x40025000UL)
//! @}

//! Interrupt Monitor
#define INTM                    (*(INTM_tag *)          0x40071000UL)

//! Integrated Peripherals Control
#define IPC                     (*(IPC_tag *)           0x4007D000UL)

//! Hardware Cryptography Unit
#define HCU                     (*(HCU_tag *)           0x40067000UL)

//! \name General Port Input / Output
//! @{
#define GPIOA                   (*(GPIO_tag *)          0x40011000UL)
#define GPIOB                   (*(GPIO_tag *)          0x40011100UL)
#define GPIOC                   (*(GPIO_tag *)          0x40011200UL)
#define GPIOD                   (*(GPIO_tag *)          0x40011300UL)
#define GPIOE                   (*(GPIO_tag *)          0x40011400UL)
//! @}

//! \name Local Interconnect Network
//! @{
#define LINFlexD0               (*(LINFlexD_tag *)      0x4001B000UL)
#define LINFlexD1               (*(LINFlexD_tag *)      0x4001C000UL)
#define LINFlexD2               (*(LINFlexD_tag *)      0x4001D000UL)
#define LINFlexD3               (*(LINFlexD_tag *)      0x4001E000UL)
#define LINFlexD4               (*(LINFlexD_tag *)      0x4001F000UL)
#define LINFlexD5               (*(LINFlexD_tag *)      0x40020000UL)
//! @}

//! Low Power Timer
#define LPTMR                   (*(LPTMR_tag *)         0x4005D000UL)

//! \name Port Control
//! @{
#define PCTRLA                  (*(PCTRL_tag *)         0x40012000UL)
#define PCTRLB                  (*(PCTRL_tag *)         0x40013000UL)
#define PCTRLC                  (*(PCTRL_tag *)         0x40014000UL)
#define PCTRLD                  (*(PCTRL_tag *)         0x40015000UL)
#define PCTRLE                  (*(PCTRL_tag *)         0x40016000UL)
//! @}

//! Power Control Unit
#define PCU                     (*(PCU_tag *)           0x4007E000UL)

//! Periodic Timer
#define PTMR                    (*(PTMR_tag *)          0x4005A000UL)

//! Programmable Trigger Unit
#define PTU0                    (*(PTU_tag *)           0x40046000UL)
#define PTU1                    (*(PTU_tag *)           0x40047000UL)

//! Reset Control Unit
#define RCU                     (*(RCU_tag *)           0x4007F000UL)

//! Register File
#define REGFILE                 (*(REGFILE_tag*)        0x40061000UL)

//! Real Time Clock Module
#define RTC                     (*(RTC_tag *)           0x40060000UL)

//! System Clock Unit
#define SCU                     (*(SCU_tag *)           0x4007C000UL)

//! \name Serial Port Interface
//! @{
#define SPI0                    (*(SPI_tag *)           0x4002A000UL)
#define SPI1                    (*(SPI_tag *)           0x4002B000UL)
#define SPI2                    (*(SPI_tag *)           0x4002C000UL)
#define SPI3                    (*(SPI_tag *)           0x4002D000UL)
#define SPI4                    (*(SPI_tag *)           0x4002E000UL)
#define SPI5                    (*(SPI_tag *)           0x4002F000UL)
//! @}

//! Timer
#define TMR                     (*(TMR_tag *)           0x40054000UL)

//! Trigger Multiplexer Module
#define TMU                     (*(TMU_tag *)           0x40048000UL)

//! True Random Number Generator
#define TRNG                    (*(TRNG_tag *)          0x40066000UL)

//! Watchdog
#define WDG                     (*(WDG_tag *)           0x4006A000UL)

//! Wake-up Unit
#define WKU                     (*(WKU_tag *)           0x40062000UL)



#endif // YTM32B1M_SFR_H

//****************************************** end of file *******************************************
