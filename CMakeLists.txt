cmake_minimum_required(VERSION 3.17) 

project(TEST_SPI_YTM 
        VERSION 1.0.0
        DESCRIPTION "Test spi project"
        LANGUAGES C ASM)

# Set Folder with all project files
set(DEV_ROOT ${CMAKE_SOURCE_DIR}/test/dev)

# Setup toolchain paths and settings
include(${DEV_ROOT}/ide/cmake/toolchain.cmake)

# Setup project settings
include(${DEV_ROOT}/ide/cmake/settings.cmake)

# Set linker script path (it's needed in compiller.cmake)
set(LINKER_SCRIPT ${DEV_ROOT}/bsw/linker/gnu_linker/linker_cfg.ld)
# Setup compiller and linker options
include(${DEV_ROOT}/ide/cmake/compiler.cmake)

# Initialize all modules
add_subdirectory(${DEV_ROOT}/cfg)
add_subdirectory(${DEV_ROOT}/asw)
add_subdirectory(${DEV_ROOT}/bsw)
add_subdirectory(${DEV_ROOT}/tests)

# Make main executable
add_executable(${PROJECT_NAME} ${DEV_ROOT}/bsw/startup/main/main.c)

# Link all libraries on which executable depends 
target_link_libraries(${PROJECT_NAME} PRIVATE  
                      cstart
                      error_tracer
                      inc
                      irq_drv
                      mcu_drv
                      os
                      pit)

# Choose file to create as result of build
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ${CMAKE_EXECUTABLE_SUFFIX})

