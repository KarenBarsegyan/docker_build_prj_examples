#=== Toolchain settings file ===#

# Set cross-compilation variables

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)

# Set paths to GCC

# S11 compiler
# set(GCC_ROOT_PATH "c:/ProgramFiles/gcc/gcc-arm-11_2-2022_02/bin")

# Local machine GCC
set(GCC_ROOT_PATH "C:/Program Files (x86)/GNU Arm Embedded Toolchain/10 2021.10/bin") 


set(GCC_PREFIX "arm-none-eabi")

set(CMAKE_C_COMPILER   ${GCC_ROOT_PATH}/${GCC_PREFIX}-gcc.exe)
set(CMAKE_CXX_COMPILER ${GCC_ROOT_PATH}/${GCC_PREFIX}-g++.exe)
set(CMAKE_ASM_COMPILER ${GCC_ROOT_PATH}/${GCC_PREFIX}-gcc.exe)
set(CMAKE_AR           ${GCC_ROOT_PATH}/${GCC_PREFIX}-ar.exe)
set(CMAKE_OBJCOPY      ${GCC_ROOT_PATH}/${GCC_PREFIX}-objcopy.exe)
set(CMAKE_OBJDUMP      ${GCC_ROOT_PATH}/${GCC_PREFIX}-objdump.exe)
set(GCC_SIZE           ${GCC_ROOT_PATH}/${GCC_PREFIX}-size.exe)

# Cross-compilation - do not try check compiler
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
#SET (CMAKE_C_COMPILER_WORKS 1)

set(DOXYGEN_PATH "C:/Program Files/doxygen/bin.doxygen.exe")