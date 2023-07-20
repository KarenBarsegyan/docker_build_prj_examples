# Set library name
set(LIB_NAME compiler)

# Create INTERFACE library
add_library(${LIB_NAME} INTERFACE) 

# Add Headers
target_include_directories(${LIB_NAME} INTERFACE
                           ${CMAKE_CURRENT_SOURCE_DIR}/gcc_arm)

# Add Dependencies
target_link_libraries(${LIB_NAME} INTERFACE gen)
target_link_libraries(${LIB_NAME} INTERFACE platform)
