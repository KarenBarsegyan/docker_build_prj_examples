# Set library name
set(LIB_NAME asw)

# Create library and add source files
file(GLOB_RECURSE SRC_FILES *.c *.h)
add_library(${LIB_NAME} ${SRC_FILES}) 

# Add Headers
target_include_directories(${LIB_NAME} PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/Asap_Template
                           ${CMAKE_CURRENT_SOURCE_DIR}/Config
                           ${CMAKE_CURRENT_SOURCE_DIR}/Data
                           ${CMAKE_CURRENT_SOURCE_DIR}/Models)

# Add Dependencies
target_link_libraries(${LIB_NAME} PRIVATE cfg)
target_link_libraries(${LIB_NAME} PRIVATE os)
target_link_libraries(${LIB_NAME} PRIVATE inc)
target_link_libraries(${LIB_NAME} PRIVATE tests)