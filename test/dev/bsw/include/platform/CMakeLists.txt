# Set library name
set(LIB_NAME platform)

# Create INTERFACE library
add_library(${LIB_NAME} INTERFACE) 

# Add Headers
target_include_directories(${LIB_NAME} INTERFACE
                           ${CMAKE_CURRENT_SOURCE_DIR}/arm32)

# Add Dependencies
# target_link_libraries(${LIB_NAME} PRIVATE cfg)
