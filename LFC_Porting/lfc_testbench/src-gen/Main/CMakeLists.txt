# Template CMakeLists.txt configuration for STM32 MCUS
cmake_minimum_required(VERSION 3.12)
# ##############################################################################
# Edit your MCU information up to the next border



# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DCMAKE_TOOLCHAIN_FILE=arm-none-eabi-gcc.cmake")
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/arm-none-eabi-gcc.cmake)

project(Main LANGUAGES C)



message("\n\nCMAKE FLAGS:" + ${CMAKE_C_FLAGS})
message("\nTOOLCHAIN FILES:" + ${CMAKE_TOOLCHAIN_FILE})
message("\n")




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





enable_language(C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(DEFAULT_BUILD_TYPE Debug)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE ${DEFAULT_BUILD_TYPE} CACHE STRING "Choose the type of build." FORCE)
endif()


# ==============================================================================
#               A bunch of LF stuff I added
# ==============================================================================

# do not print install messages
# set(CMAKE_INSTALL_MESSAGE NEVER)

# LF set system name
set(CMAKE_SYSTEM_NAME Stm32)

# include(${CMAKE_CURRENT_SOURCE_DIR}/arm-none-eabi-gcc.cmake)

# Set default values for build parameters
if (NOT DEFINED LF_REACTION_GRAPH_BREADTH)
    set(LF_REACTION_GRAPH_BREADTH 1)
endif()
if (NOT DEFINED LF_THREADED AND NOT DEFINED LF_UNTHREADED)
    set(LF_UNTHREADED 1)
endif()
if (NOT DEFINED LOG_LEVEL)
    set(LOG_LEVEL 2)
endif()

# ==============================================================================
#
# ==============================================================================

set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(STM_DIR ${CMAKE_CURRENT_SOURCE_DIR}/STM_sdk)


set(MCU_FAMILY STM32F4xx)
set(MCU_MODEL STM32F446xx)
set(CPU_PARAMETERS -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp)

set(STARTUP_SCRIPT ${STM_DIR}/CubeMX/startup_stm32f446xx.s)
set(MCU_LINKER_SCRIPT ${STM_DIR}/CubeMX/STM32F446RETx_FLASH.ld)

set(EXECUTABLE Main)

# Headers
set(PROJECT_INCLUDE_DIRECTORIES
    ${PROJECT_DIR}
    ${PROJECT_DIR}/include/Main
    ${PROJECT_DIR}/include/api
)

set(CUBEMX_INCLUDE_DIRECTORIES
    ${PROJECT_DIR}
    ${PROJECT_DIR}/include/Main
    STM_sdk/Core/Inc
    STM_sdk/Drivers/${MCU_FAMILY}_HAL_Driver/Inc
    STM_sdk/Drivers/${MCU_FAMILY}_HAL_Driver/Inc/Legacy
    STM_sdk/Drivers/CMSIS/Device/ST/${MCU_FAMILY}/Include
    STM_sdk/Drivers/CMSIS/Include
)

# Sources
file(GLOB_RECURSE STM32CUBEMX_SOURCES
    ${STM_DIR}/Core/*.c
    ${STM_DIR}/Drivers/*.c)

# Executable files
add_executable(${EXECUTABLE}
    ${STM32CUBEMX_SOURCES} 
    ${STARTUP_SCRIPT}
    lib/schedule.c
    _main_main.c
    Main.c
)

# Embedded macros(defines)
target_compile_definitions(${EXECUTABLE} PUBLIC
    ${MCU_MODEL}
    USE_HAL_DRIVER)

# Compiler and linker options
target_compile_options(${EXECUTABLE} PRIVATE
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

target_link_options(${EXECUTABLE} PRIVATE
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

add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${EXECUTABLE}>)

add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${EXECUTABLE}>
    ${EXECUTABLE}.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${EXECUTABLE}>
    ${EXECUTABLE}.bin)





# ==============================================================================
#               A bunch of LF stuff I added
# ==============================================================================

cmake_policy(SET CMP0079 NEW)

add_subdirectory(core)
target_include_directories(core PUBLIC ${CUBEMX_INCLUDE_DIRECTORIES})


# target_link_libraries(${EXECUTABLE} PUBLIC ${STM32CUBEMX_SOURCES})
target_link_libraries(${EXECUTABLE} PUBLIC core)
target_include_directories(${EXECUTABLE} PUBLIC .)
target_include_directories(${EXECUTABLE} PUBLIC include/)
target_include_directories(${EXECUTABLE} PUBLIC include/api)
target_include_directories(${EXECUTABLE} PUBLIC include/core)
target_include_directories(${EXECUTABLE} PUBLIC include/core/platform)
target_include_directories(${EXECUTABLE} PUBLIC include/core/modal_models)
target_include_directories(${EXECUTABLE} PUBLIC include/core/utils)



target_compile_definitions( ${EXECUTABLE} PUBLIC LF_UNTHREADED=1)
    install(
        TARGETS ${EXECUTABLE}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )



# ##############################################################################   



# ==============================================================================
#
# ==============================================================================