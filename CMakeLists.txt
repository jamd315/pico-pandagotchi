cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(pico-pandagotchi C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

# Use the pico-ssd1306 library
add_subdirectory(pico-ssd1306)

add_executable(pico-pandagotchi
    main.cpp
    PandaStateMachine.cpp
    Animator.cpp
    logging.cpp
    images.cpp
    sequences.cpp
    sounds.cpp
    faces.cpp
)

# Generate image data
find_package(Python3 REQUIRED)

add_custom_target(
    compile_images ALL
    COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/python/compile_images.py ${CMAKE_CURRENT_SOURCE_DIR}
    BYPRODUCTS ${CMAKE_CURRENT_SOURCE_DIR}/images.hpp ${CMAKE_CURRENT_SOURCE_DIR}/images.cpp
    COMMENT "Generating images..."
)

add_custom_target(
    compile_animations ALL
    COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/python/compile_animations.py ${CMAKE_CURRENT_SOURCE_DIR}
    BYPRODUCTS ${CMAKE_CURRENT_SOURCE_DIR}/faces.hpp ${CMAKE_CURRENT_SOURCE_DIR}/faces.cpp ${CMAKE_CURRENT_SOURCE_DIR}/sequences.hpp ${CMAKE_CURRENT_SOURCE_DIR}/sequences.cpp
    COMMENT "Generating sequences..."
)

add_custom_target(
    compile_sounds ALL
    COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/python/compile_sounds.py ${CMAKE_CURRENT_SOURCE_DIR}
    BYPRODUCTS ${CMAKE_CURRENT_SOURCE_DIR}/sounds.hpp ${CMAKE_CURRENT_SOURCE_DIR}/sounds.cpp
    COMMENT "Generating sounds..."
)

add_dependencies(pico-pandagotchi
    compile_images
    compile_animations
    compile_sounds
)

# Emit to USB and UART
pico_enable_stdio_usb(pico-pandagotchi 1)
pico_enable_stdio_uart(pico-pandagotchi 1)

pico_add_extra_outputs(pico-pandagotchi)

target_link_libraries(pico-pandagotchi 
    pico_stdlib
    pico_ssd1306
    hardware_i2c
)