set(CMAKE_SYSTEM_NAME       Generic)
set(CMAKE_SYSTEM_PROCESSOR  arm)
set(TOOLCHAIN_PREFIX        arm-none-eabi)
set(CMAKE_CROSS_COMPILING   true)
set(CMAKE_EXECUTABLE_SUFFIX ".elf")

include(any_toolchain)

add_compile_options(
    -ffunction-sections -fdata-sections
    -DCORTEX -D${SERIES}
    $<$<COMPILE_LANGUAGE:CXX>:-nostdinc++>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-threadsafe-statics>
    $<$<COMPILE_LANGUAGE:ASM>:-x$<SEMICOLON>assembler-with-cpp>
    $<$<COMPILE_LANGUAGE:ASM>:-MMD>
    $<$<COMPILE_LANGUAGE:ASM>:-MP>
)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
add_link_options(
    -T ${CMAKE_SOURCE_DIR}/hw/${HW}/${CPU_}x_FLASH.ld
    --specs=nano.specs
    -Wl,--start-group -lc -lm -lnosys   -Wl,--end-group
    -Wl,--start-group -lstdc++ -lsupc++ -Wl,--end-group
    -Wl,-Map=${CMAKE_PROJECT_NAME}.map -Wl,--gc-sections
)

# ARM cross compiler binaries
set(ELF ${CMAKE_INSTALL_PREFIX}/${BIN_OUTPUT_NAME}.elf)
set(DFU ${CMAKE_INSTALL_PREFIX}/${BIN_OUTPUT_NAME}.dfu)

add_custom_command(
    OUTPUT  ${DFU}
    DEPENDS ${ELF}
    COMMAND ../elf2dfuse/bin/elf2dfuse ${ELF} ${DFU}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
add_custom_target(dfu DEPENDS ${DFU})
