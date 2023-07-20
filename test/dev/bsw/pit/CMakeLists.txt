# Set library name
set(LIB_NAME pit)

# Create library and add source files
file(GLOB_RECURSE SRC_FILES *.c *.h)
add_library(${LIB_NAME} ${SRC_FILES}) 

# Add Headers
target_include_directories(${LIB_NAME} PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR})

# Add Dependencies
target_link_libraries(${LIB_NAME} PRIVATE compiler)
target_link_libraries(${LIB_NAME} PRIVATE mcu_drv)
target_link_libraries(${LIB_NAME} PRIVATE error_tracer)
target_link_libraries(${LIB_NAME} PRIVATE cfg)
