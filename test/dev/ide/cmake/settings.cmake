#***************************************************************************************************
# @Filename      settings.cmake
#---------------------------------------------------------------------------------------------------
# @Description   Settings of paths, flags etc.
#---------------------------------------------------------------------------------------------------
# @Version       1.0.0
#---------------------------------------------------------------------------------------------------
# @Date          23.01.2023
#---------------------------------------------------------------------------------------------------
# @History       Version  Author      Comment
# 23.01.2023     1.0.0    DRV         First release.
#***************************************************************************************************

# Set C standard
set(CMAKE_C_STANDARD 99)
# Set target processor
set(CMAKE_SYSTEM_PROCESSOR cortex-m33)
# Suffix for library file
set(CMAKE_LIBRARY_SUFFIX ".a")
# Build file extension
set(CMAKE_EXECUTABLE_SUFFIX ".elf") 


# # Turn ON/OFF MISRA-C standard checking (ON - checking, OFF - ignore)
# set(CHECK_MISRA_C  OFF)
# # Path to the cmake script launching MISRA-C checker
# set(MISRA_C_CMAKE  ${PROJECTS_DIR}/CMake/ldra_misra.cmake)



#****************************************** end of file ********************************************
