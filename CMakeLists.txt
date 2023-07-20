cmake_minimum_required(VERSION 3.17) 

# Set Folder with all project files
set(DEV_ROOT ${CMAKE_SOURCE_DIR}/test/dev)

# Setup toolchain paths and settings
include(${DEV_ROOT}/ide/cmake/toolchain.cmake)

# Create project
project(TEST_SPI_YTM 
        VERSION 1.0.0
        DESCRIPTION "Test spi project"
        LANGUAGES C ASM)

# Setup project settings
include(${DEV_ROOT}/ide/cmake/settings.cmake)

# Set linker script path (it's needed in compiller.cmake)
set(LINKER_SCRIPT ${DEV_ROOT}/bsw/linker/gnu_linker/linker_cfg.ld)
# Setup compiller and linker options
include(${DEV_ROOT}/ide/cmake/compiler.cmake)

# Initialize test driver
add_subdirectory(src)

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

# Generate BIN-file
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY}
        ARGS -Obinary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
        COMMENT "Generate ${PROJECT_NAME}.bin file") 

# Generate HEX-file
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY}
        ARGS -Oihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
        COMMENT "Generate ${PROJECT_NAME}.hex file")

# Generate SREC-file
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
       COMMAND ${CMAKE_OBJCOPY}
       ARGS -Osrec ${PROJECT_NAME}.elf ${PROJECT_NAME}.s19
       COMMENT "Generate ${PROJECT_NAME}.s19 file")

# Generate Doxygen documentation
add_subdirectory(doc)