# Set library name
set(LIB_NAME cfg)

# Create INTERFACE library
add_library(${LIB_NAME} INTERFACE)

# Add Headers
target_include_directories(${LIB_NAME} INTERFACE 
                           ${CMAKE_CURRENT_SOURCE_DIR})       

# Add Dependencies
target_link_libraries(${LIB_NAME} INTERFACE sfr)
# target_link_libraries(${LIB_NAME} INTERFACE gen)