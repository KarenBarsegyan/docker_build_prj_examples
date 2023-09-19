option(BUILD_DOC "Build documentation" ON)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

find_package(Doxygen REQUIRED)
find_package(Sphinx REQUIRED)

if(DOXYGEN_FOUND)
    set(DOXYGEN_INPUT_DIR ${CMAKE_SOURCE_DIR})
    set(DOXYGEN_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/doxygen)
    
    set(DOXYFILE_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    set(DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    
    set(DOXYGEN_INDEX_FILE ${DOXYGEN_OUTPUT_DIR}/html/index.html)
    
    file(COPY ${PROJECT_SOURCE_DIR}/doc/rst-dir DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    file(COPY ${PROJECT_SOURCE_DIR}/doc/doxyrest-config.lua DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

    configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

    file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIR})

    add_custom_command(OUTPUT ${DOXYGEN_INDEX_FILE}
                       COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
                       MAIN_DEPENDENCY ${DOXYFILE_OUT} ${DOXYFILE_IN}
                       WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                       COMMENT "Generating docs")

    add_custom_target(Doxygen ALL DEPENDS ${DOXYGEN_INDEX_FILE})

    add_custom_target(Doxyrest ALL
                      COMMAND doxyrest -c doxyrest-config.lua
                      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                      COMMENT "Generating documentation with Doxyrest")

    set(SPHINX_SOURCE ${CMAKE_CURRENT_BINARY_DIR}/rst-dir)
    set(SPHINX_BUILD ${CMAKE_CURRENT_BINARY_DIR}/sphinx)

    add_custom_target(Sphinx ALL
                      COMMAND ${SPHINX_EXECUTABLE} -b html
                      ${SPHINX_SOURCE} ${SPHINX_BUILD}
                      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                      COMMENT "Generating documentation with Sphinx")

    set(DOC_DESTINATION_DIR ${CMAKE_SOURCE_DIR}/doxy_docs/)
    add_custom_target(CopyDocs ALL
                      COMMAND mkdir -p ${DOC_DESTINATION_DIR} && cp -r ${CMAKE_CURRENT_BINARY_DIR}/doxygen/html ${DOC_DESTINATION_DIR} &&
                                                                 cp -r ${CMAKE_CURRENT_BINARY_DIR}/sphinx ${DOC_DESTINATION_DIR}
                      COMMENT "Copy Documentation")

else()
    message(STATUS "WARNING: Doxygen NOT Found")
endif()