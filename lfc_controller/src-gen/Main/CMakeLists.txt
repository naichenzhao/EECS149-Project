
cmake_minimum_required(VERSION 3.19)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/arm-none-eabi-gcc.cmake)
project(Main LANGUAGES C)

if(CMAKE_BUILD_TYPE STREQUAL "Test")
  set(CMAKE_BUILD_TYPE "Debug")
  if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
    find_program(LCOV_BIN lcov)
    if(LCOV_BIN MATCHES "lcov$")
      set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
    else()
      message("Not producing code coverage information since lcov was not found")
    endif()
  else()
    message("Not producing code coverage information since the selected compiler is no gcc")
  endif()
endif()
# Require C11
enable_language(C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DEFAULT_BUILD_TYPE Debug)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE ${DEFAULT_BUILD_TYPE} CACHE STRING "Choose the type of build." FORCE)
endif()

# do not print install messages
set(CMAKE_INSTALL_MESSAGE NEVER)

set(CMAKE_SYSTEM_NAME Stm32)

# Set default values for build parameters
if (NOT DEFINED LF_SINGLE_THREADED)
    set(LF_SINGLE_THREADED 1)
endif()
if (NOT DEFINED LOG_LEVEL)
    set(LOG_LEVEL 2)
endif()
if (NOT DEFINED LF_REACTION_GRAPH_BREADTH)
    set(LF_REACTION_GRAPH_BREADTH 2)
endif()

# ########################################################

# ############## [ Start STM32 main target] ##############

# ########################################################


add_subdirectory(core)

set(LF_MAIN_TARGET Main)
set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(STM_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../STM_sdk)

set(MCU_FAMILY STM32F4xx)
set(MCU_MODEL STM32F446xx)
set(CPU_PARAMETERS -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp)

set(STARTUP_SCRIPT ${STM_DIR}/startup_stm32f446xx.s)
set(MCU_LINKER_SCRIPT ${STM_DIR}/STM32F446RETx_FLASH.ld)

file(GLOB_RECURSE STM32CUBEMX_SOURCES ${STM_DIR}/Core/*.c ${STM_DIR}/Drivers/${MCU_FAMILY}_HAL_Driver/*.c)
set(CUBEMX_INCLUDE_DIRECTORIES
    ${PROJECT_DIR}
    ${PROJECT_DIR}/include/Main
    ${STM_DIR}/Core/Inc
    ${STM_DIR}/Drivers/${MCU_FAMILY}_HAL_Driver/Inc
    ${STM_DIR}/Drivers/${MCU_FAMILY}_HAL_Driver/Inc/Legacy
    ${STM_DIR}/Drivers/CMSIS/Device/ST/${MCU_FAMILY}/Include
    ${STM_DIR}/Drivers/CMSIS/Include
)

# Declare a new executable target and list all its sources
add_executable(
    ${LF_MAIN_TARGET}
    ${STM32CUBEMX_SOURCES} 
    ${STARTUP_SCRIPT} 
    lib/schedule.c
    _main_main.c
    _serial.c
    Main.c
)

target_include_directories(core PUBLIC ${CUBEMX_INCLUDE_DIRECTORIES})
target_compile_definitions(core PUBLIC ${MCU_MODEL} USE_HAL_DRIVER)



# Compiler definitions for the STM32
target_compile_options(core PUBLIC
    ${CPU_PARAMETERS}
    -Wall
    -Wextra
    -Wpedantic
    -Wno-unused-parameter
    $<$<COMPILE_LANGUAGE:CXX>:
        -Wno-volatile
        -Wold-style-cast
        -Wuseless-cast
        -Wsuggest-override>
    $<$<CONFIG:Debug>:-Og -g3 -ggdb>
    $<$<CONFIG:Release>:-Og -g0>)

target_link_options(${LF_MAIN_TARGET} PRIVATE
    -T${MCU_LINKER_SCRIPT}
    ${CPU_PARAMETERS}
    -Wl,-Map=${CMAKE_PROJECT_NAME}.map
    --specs=nosys.specs
    -Wl,--start-group
    -lc
    -lm
    -lstdc++
    -Wl,--end-group
    -Wl,--print-memory-usage)

add_custom_command(TARGET ${LF_MAIN_TARGET} POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${LF_MAIN_TARGET}>)
add_custom_command(TARGET ${LF_MAIN_TARGET} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${LF_MAIN_TARGET}>
    ${LF_MAIN_TARGET}.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${LF_MAIN_TARGET}>
    ${LF_MAIN_TARGET}.bin)


# ######################################################

# ############## [ End STM32 main target] ##############

# ######################################################

find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
  target_link_libraries(${LF_MAIN_TARGET} PUBLIC ${MATH_LIBRARY})
endif()
target_link_libraries(${LF_MAIN_TARGET} PRIVATE core)
target_include_directories(${LF_MAIN_TARGET} PUBLIC .)
target_include_directories(${LF_MAIN_TARGET} PUBLIC include/)
target_include_directories(${LF_MAIN_TARGET} PUBLIC include/api)
target_include_directories(${LF_MAIN_TARGET} PUBLIC include/core)
target_include_directories(${LF_MAIN_TARGET} PUBLIC include/core/platform)
target_include_directories(${LF_MAIN_TARGET} PUBLIC include/core/modal_models)
target_include_directories(${LF_MAIN_TARGET} PUBLIC include/core/utils)
# Set flag to indicate a single-threaded runtime
target_compile_definitions( ${LF_MAIN_TARGET} PUBLIC LF_SINGLE_THREADED=1)


    install(
        TARGETS ${LF_MAIN_TARGET}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )




