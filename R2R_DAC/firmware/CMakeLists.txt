cmake_minimum_required(VERSION 3.13)

include(${CMAKE_CURRENT_LIST_DIR}/../pico-sdk/pico_sdk_init.cmake)

project(csv)

pico_sdk_init()

add_executable(csv)

target_sources(csv PRIVATE ${CMAKE_CURRENT_LIST_DIR}/main.c ${CMAKE_CURRENT_LIST_DIR}/csv/csv.h ${CMAKE_CURRENT_LIST_DIR}/csv/csv.c)

target_link_libraries(csv PRIVATE pico_stdlib hardware_clocks hardware_gpio)
pico_add_extra_outputs(csv)

pico_enable_stdio_usb(csv 1)
pico_enable_stdio_uart(csv 0)