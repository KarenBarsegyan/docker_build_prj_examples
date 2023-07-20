# Set library name
set(LIB_NAME inc)

# Create INTERFACE library
add_library(${LIB_NAME} INTERFACE) 

# Add Headers
target_include_directories(${LIB_NAME} INTERFACE
                           ${CMAKE_CURRENT_SOURCE_DIR})

# Add Dependencies
target_link_libraries(${LIB_NAME} INTERFACE cfg)
target_link_libraries(${LIB_NAME} INTERFACE gen)
target_link_libraries(${LIB_NAME} INTERFACE compiler)


add_subdirectory(compiler)
add_subdirectory(general)
add_subdirectory(platform)