cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(pico-pandagotchi C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(pico-pandagotchi
    main.cpp
)

pico_enable_stdio_usb(pico-pandagotchi 1)
pico_enable_stdio_uart(pico-pandagotchi 1)

pico_add_extra_outputs(pico-pandagotchi)

target_link_libraries(pico-pandagotchi pico_stdlib)