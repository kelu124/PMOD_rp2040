cmake_minimum_required(VERSION 3.13)

include(${CMAKE_CURRENT_LIST_DIR}/../../../../pico/pico-sdk/pico_sdk_init.cmake)

project(puls_test ASM C CXX)

pico_sdk_init()

add_executable(puls_test)


target_sources(puls_test PRIVATE ${CMAKE_CURRENT_LIST_DIR}/main.c ${CMAKE_CURRENT_LIST_DIR}/adc/adc.h ${CMAKE_CURRENT_LIST_DIR}/adc/adc.c)

target_link_libraries(puls_test PRIVATE pico_stdlib hardware_pio hardware_dma hardware_clocks hardware_gpio hardware_irq pico_multicore)
pico_add_extra_outputs(puls_test)

pico_enable_stdio_usb(puls_test 1)
pico_enable_stdio_uart(puls_test 0)
