#=== Compiler and Linker options file ===#

#=== Set compiler options ===#
# Common options
add_compile_options(-std=c${CMAKE_C_STANDARD} -mcpu=${CMAKE_SYSTEM_PROCESSOR} -mlittle-endian -mlong-calls -ffreestanding )
# Debugging options
add_compile_options(-g3 -gdwarf)
# Developer options
add_compile_options(-fno-strict-aliasing -fstack-usage)
# Code optimization
add_compile_options(-O0 -ffunction-sections -fdata-sections)
# Warnings options
add_compile_options(-Wall -Wno-pragmas)
# Stop build on warnings
# add_compile_options(-Werror)


#=== Set linker options ===#
# Common options 
add_link_options(-nostartfiles -nodefaultlibs -nostdlib -Xlinker)

# Linker optimizations
add_link_options(--gc-sections)

# Linker launch pattern
set(CMAKE_C_LINK_EXECUTABLE "<CMAKE_C_COMPILER> <OBJECTS> <LINK_FLAGS> -o <TARGET> <LINK_LIBRARIES>") 

add_link_options(-T ${LINKER_SCRIPT}
                 -Wl,-Map=${PROJECT_NAME}.map
                 -mcpu=${CMAKE_SYSTEM_PROCESSOR}) 