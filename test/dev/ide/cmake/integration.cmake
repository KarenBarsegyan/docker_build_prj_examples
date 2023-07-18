#**************************************************************************************************
# @Filename      integration.cmake
#--------------------------------------------------------------------------------------------------
# @Description   Paths to source and header files, linker options.
#--------------------------------------------------------------------------------------------------
# @Version       1.0.0
#--------------------------------------------------------------------------------------------------
# @Date          23.01.2023
#--------------------------------------------------------------------------------------------------
# @History       Version  Author      Comment
# 23.01.2023     1.0.0    DRV         First release.
#**************************************************************************************************



# Source files
aux_source_directory(${CURRENT_PROJ_ROOT}/src
                     TESTED_MODULE)

set(TEST_PRJ_ROOT ${CURRENT_PROJ_ROOT}/test/dev)
MESSAGE(${TEST_PRJ_ROOT})
MESSAGE(${CURRENT_PROJ_ROOT})
# set dep dir
aux_source_directory(${TEST_PRJ_ROOT}/dep/error_tracer       ERROR_TRASER_SRC)
aux_source_directory(${TEST_PRJ_ROOT}/dep/general            GENERAL_SRC)
aux_source_directory(${TEST_PRJ_ROOT}/dep/mcu_drv            MCU_DRV_SRC)
aux_source_directory(${TEST_PRJ_ROOT}/dep/startup            STARTUP_SRC)

# set env dir
aux_source_directory(${TEST_PRJ_ROOT}/env/asw/Data           ASW_DATA_SRC)
aux_source_directory(${TEST_PRJ_ROOT}/env/asw/Models         ASW_MODELS_SRC)
aux_source_directory(${TEST_PRJ_ROOT}/env/irq_drv            IRQ_DRV_SRC)
aux_source_directory(${TEST_PRJ_ROOT}/env/os                 OS_SRC)
aux_source_directory(${TEST_PRJ_ROOT}/env/os/Portable        OS_PORTABLE_SRC)
aux_source_directory(${TEST_PRJ_ROOT}/env/pit                PIT_SRC)

# set tests dir
aux_source_directory(${TEST_PRJ_ROOT}/tests                  TESTS_DIR)

# Create target name 
set(TARGET_NAME ${PROJECT_NAME}) 

# Create and attach source files to the target
add_executable(${TARGET_NAME} 
               ${TESTED_MODULE} 
               ${ERROR_TRASER_SRC}  
               ${GENERAL_SRC}
               ${MCU_DRV_SRC}
               ${STARTUP_SRC}
               ${ASW_DATA_SRC}
               ${ASW_MODELS_SRC}
               ${IRQ_DRV_SRC}
               ${OS_SRC}
               ${OS_PORTABLE_SRC}
               ${PIT_SRC}
               ${TESTS_DIR})

# Attach include paths to the target
target_include_directories(${TARGET_NAME} PUBLIC 
                           ${TEST_PRJ_ROOT}/cfg/compiler/gcc_arm
                           ${TEST_PRJ_ROOT}/cfg/linker/gnu_linker
                           ${TEST_PRJ_ROOT}/cfg/modules_cfg
                           ${TEST_PRJ_ROOT}/cfg/platform/arm32
                           ${TEST_PRJ_ROOT}/dep/error_tracer
                           ${TEST_PRJ_ROOT}/dep/general
                           ${TEST_PRJ_ROOT}/dep/mcu_drv
                           ${TEST_PRJ_ROOT}/dep/sfr
                           ${TEST_PRJ_ROOT}/dep/sfr
                           ${TEST_PRJ_ROOT}/dep/startup
                           ${TEST_PRJ_ROOT}/env/asw/Config
                           ${TEST_PRJ_ROOT}/env/asw/Data
                           ${TEST_PRJ_ROOT}/env/asw/Models
                           ${TEST_PRJ_ROOT}/env/inc
                           ${TEST_PRJ_ROOT}/env/irq_drv
                           ${TEST_PRJ_ROOT}/env/os
                           ${TEST_PRJ_ROOT}/env/os/Portable
                           ${TEST_PRJ_ROOT}/env/pit
                           ${TEST_PRJ_ROOT}/tests)

# Specify CPU model
target_compile_options(${TARGET_NAME} PUBLIC -mcpu=${CMAKE_SYSTEM_PROCESSOR}) 

# Linker script location
set(LINKER_SCRIPT ${CURRENT_PROJ_ROOT}/test/dev/cfg/linker/gnu_linker/linker_cfg.ld)

# Link options
target_link_options(${TARGET_NAME} PUBLIC 
                    -T ${LINKER_SCRIPT}
                    -Wl,-Map=${TARGET_NAME}.map
                    -mcpu=${CMAKE_SYSTEM_PROCESSOR}) 

# Executable file format
set_target_properties(${TARGET_NAME} PROPERTIES SUFFIX ${CMAKE_EXECUTABLE_SUFFIX})



#****************************************** end of file ********************************************
