/***************************************************************************************************
*  @Module        Linker
*  @Filename      linker_cfg.h
* --------------------------------------------------------------------------------------------------
*  @Description   Linker/locator control file for GCC
*                 It locates code to ROM and data to RAM, vector table is generated.
*                 There is no libc support - standard libc sections are not defined here.
* --------------------------------------------------------------------------------------------------
*  @Note          None
* --------------------------------------------------------------------------------------------------
*  @Compatible    HC32F4A0 families
* --------------------------------------------------------------------------------------------------
*  @Version       2.0.0
* --------------------------------------------------------------------------------------------------
*  @Date          31.01.2023
* --------------------------------------------------------------------------------------------------
*  @History       Version  Author    Comment
*  15.09.2022     1.0.0    KPS       First release
*  27.09.2022     2.0.0    MAV       Second release
***************************************************************************************************/

/* Entry Point */
ENTRY(STARTUP_Cstart)


/* Memories definition */
MEMORY {
    /* SRAM */
    ram_marker                      (wx)    : ORIGIN = 0x1FFF0000,          LENGTH = 4
    ram_not_init                    (wx)    : ORIGIN = 0x1FFF0004,          LENGTH = 252
    ram_memory                      (wx)    : ORIGIN = 0x1FFF0100,          LENGTH = 127K - 256

    /* BTLDR */
/*    mem_flash_btldr_image           (rx)    : ORIGIN = 0x00000000,          LENGTH = 184K */

    /* APPL */
/*    mem_flash_appl_ivt              (rx)    : ORIGIN = 0x0002E000,          LENGTH = 2K */
    mem_flash_appl_ivt              (rx)    : ORIGIN = 0x00000000,          LENGTH = 2K
    mem_flash_appl_code             (rx)    : ORIGIN = 0x0002E800,          LENGTH = 774K
    mem_flash_appl_calibr           (rx)    : ORIGIN = 0x000F0000,          LENGTH = 64K

    /* NVR */
    mem_nvr_aes                     (rx)    : ORIGIN = 0x10000000,          LENGTH = 1K
    mem_nvr_otp                     (rx)    : ORIGIN = 0x10010000,          LENGTH = 1K
    mem_nvr_boot                    (rx)    : ORIGIN = 0x10020000,          LENGTH = 1K
    mem_nvr_cus                     (rx)    : ORIGIN = 0x10030000,          LENGTH = 1K
} /* MEMORY */


/* Constants */
/* Highest address of the user mode stack */
_estack = ORIGIN(ram_memory) + LENGTH(ram_memory);
/* Required amount of stack */
_stack_size = 8K;

/* Begin and end of the RAM memory */
_sRAM = ORIGIN(ram_memory);
_eRAM = ORIGIN(ram_memory) + LENGTH(ram_memory);



/* Sections definition */
SECTIONS {
    /* ============ FLASH Sections ============= */

    /* Bootloader image */
/*    .btldr_image : ALIGN(4) {
        KEEP(*(.address_0x0000000))
    } > mem_flash_btldr_image */

    /* Application code and other data */
    .isr_vector : ALIGN(4) {
        /* Interrupts vectors table */
        KEEP(*(.isr_vector))
        . = ALIGN(16);
    } > mem_flash_appl_ivt = 0xFF

    /* Application code and other data */
    .text : ALIGN(4) {
        /* Interrupts vectors table */
/*        KEEP(*(.isr_vector)) */
        /* Startup code */
        KEEP(*(.cstart))
        KEEP(*(.cstart*))
        /* Application code */
        *(.text)
        *(.text*)
        *(.glue_7)      /* glue arm to thumb code */
        *(.glue_7t)     /* glue thumb to arm code */
        *(.eh_frame)
        KEEP(*(.init))
        KEEP(*(.fini))
        . = ALIGN(16);
    } > mem_flash_appl_code = 0xFF

    /* Constant data */
    .rodata : ALIGN(4) {
        KEEP(EXCLUDE_FILE(*ASW_ps_flashdata.o *CSWL_ps_flashdata.o) *(.rodata))
        KEEP(EXCLUDE_FILE(*ASW_ps_flashdata.o *CSWL_ps_flashdata.o) *(.rodata*))
        . = ALIGN(16);
    } > mem_flash_appl_code = 0xFF

    /* Initialized data sections */
    _sidata = LOADADDR(.data);
    .data : ALIGN(4) {
        _sdata = .;
        *(.data)
        *(.data*)
        *(knock_filter_delay*)
        *(.RamFunc)
        *(.RamFunc*)
        . = ALIGN(16);
        _edata = .;
    } > ram_memory AT > mem_flash_appl_code = 0xFF

    /* Section with .text padding data */
    .text_freespace : ALIGN(4) {
        LONG(0xFFFFFFFF)
        . = ORIGIN(mem_flash_appl_code) + LENGTH(mem_flash_appl_code);
    } > mem_flash_appl_code = 0xFF

    /* Calibration data */
    .calROM : {
        /* Set begin address of the calibration data storage */
        CalibrationROMBegin = ORIGIN(mem_flash_appl_calibr);
        KEEP(*ASW_ps_flashdata.o(.rodata*))
        KEEP(*CSWL_ps_flashdata.o(.rodata*))
        . = ALIGN(16);
        /* Set end address of the calibration data storage */
        CalibrationROMEnd = ORIGIN(mem_flash_appl_calibr) + LENGTH(mem_flash_appl_calibr);
    }  > mem_flash_appl_calibr = 0xFF

    /* Section with .calROM padding data */
    .calROM_freespace : ALIGN(4) {
        LONG(0xFFFFFFFF)
        . = ORIGIN(mem_flash_appl_calibr) + LENGTH(mem_flash_appl_calibr);
    } > mem_flash_appl_calibr = 0xFF



    /* ========= Additional FLASH Sections ========== */
/*
    .ARM.extab : ALIGN(4) {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > mem_flash_appl_code = 0xFF

    .ARM : ALIGN(4) {
        __exidx_start = .;
        *(.ARM.exidx*)
        . = ALIGN(4);
        __exidx_end = .;
    } > mem_flash_appl_code = 0xFF
*/


    /* ===============  RAM Sections  =============== */

    /* RAM Marker */
    .btldr_ram_marker (NOLOAD) : {
        *(.MEM_AREA_RAM_BTLDR_MARKER)
    } > ram_marker

    /* Safe section for RAM bootloader marker */
    .not_init : ALIGN(4) {
        . += LENGTH(ram_not_init);
        . = ALIGN(4);
    } > ram_not_init

    /* Uninitialized data section */
    .bss : ALIGN(4) {
        _sbss = .;
        KEEP(*(.bss))
        KEEP(*(.bss*))
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    } > ram_memory

    /* User_stack section, used to check that there is enough RAM type memory left */
    .user_stack : ALIGN(8) {
        . += _stack_size;
        . = ALIGN(8);
    } > ram_memory



    /* ============== Discard Sections ============== */

    /* Remove information from the compiler libraries */
    /DISCARD/ : {
        libc.a ( * )
        libm.a ( * )
        libgcc.a ( * )
    }

    .comment 0 : {
        *(.comment)
    }

    .ARM.attributes 0 : {
        *(.ARM.attributes)
    }
} /* SECTIONS */
