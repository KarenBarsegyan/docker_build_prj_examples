# Set library name
set(LIB_NAME tests)

# Create library and add source files
file(GLOB_RECURSE SRC_FILES *.c *.h)
add_library(${LIB_NAME} ${SRC_FILES}) 

# Add Headers
target_include_directories(${LIB_NAME} PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR})

# Add Dependencies
target_link_libraries(${LIB_NAME} PRIVATE cfg)
target_link_libraries(${LIB_NAME} PRIVATE os)
target_link_libraries(${LIB_NAME} PRIVATE compiler)
target_link_libraries(${LIB_NAME} PRIVATE spi_drv)
target_link_libraries(${LIB_NAME} PRIVATE gpio_drv)