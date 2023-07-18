#***************************************************************************************************
# @Filename      CMakeLists.txt
#---------------------------------------------------------------------------------------------------
# @Description   Build tested module with test environment.
#---------------------------------------------------------------------------------------------------
# @Version       1.0.0
#---------------------------------------------------------------------------------------------------
# @Date          16.01.2023
#---------------------------------------------------------------------------------------------------
# @History       Version  Author      Comment
# 16.01.2023     1.0.0    DRV         First release.
#***************************************************************************************************



cmake_minimum_required(VERSION 3.17) 

# Compiler installation directory
include(toolchain.cmake)

# Project name
# Note: write your module name instead of "MODULE" substring
#       write the platform name if is is necessary instead "PLATFORM" substring
project(TEST_SPI_YTM C ASM)

# Variables (EHAL root, linker script location, target processor, C lang standard, MISRA-C settings) 
include(settings.cmake) 

# Compiler options
include(compiler.cmake)

# Paths to header and source files, linker config
include(integration.cmake)

# MISRA-C 2012 checker script (runs only, if MISRA-C flag is ON in settings.cmake)
# include(${MISRA_C_CMAKE})



#=== Post-Build operations ===#
 
# Generate BIN-file
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY}
        ARGS -Obinary ${TARGET_NAME}.elf ${TARGET_NAME}.bin
        COMMENT "Generate ${TARGET_NAME}.bin file") 

# Generate HEX-file
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY}
        ARGS -Oihex ${TARGET_NAME}.elf ${TARGET_NAME}.hex
        COMMENT "Generate ${TARGET_NAME}.hex file")

# Generate SREC-file
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
       COMMAND ${CMAKE_OBJCOPY}
       ARGS -Osrec ${TARGET_NAME}.elf ${TARGET_NAME}.s19
       COMMENT "Generate ${TARGET_NAME}.s19 file")


       
#****************************************** end of file ********************************************
