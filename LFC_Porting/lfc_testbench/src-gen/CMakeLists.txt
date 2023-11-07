# Template CMakeLists.txt configuration for STM32 MCUS
cmake_minimum_required(VERSION 3.12)
# ##############################################################################
# Edit your MCU information up to the next border
project(Main)
set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Main)


# ==============================================================================
#               A bunch of LF stuff I added
# ==============================================================================

# do not print install messages
# set(CMAKE_INSTALL_MESSAGE NEVER)

# LF set system name
set(CMAKE_SYSTEM_NAME STM32f4)

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



set(MCU_FAMILY STM32F4xx)
set(MCU_MODEL STM32F446xx)
set(CPU_PARAMETERS
    -mcpu=cortex-m4
    -mthumb
    -mfpu=fpv4-sp-d16
    -mfloat-abi=softfp)

set(STARTUP_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/CubeMX/startup_stm32f446xx.s)
set(MCU_LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/CubeMX/STM32F446RETx_FLASH.ld)
# ##############################################################################
set(EXECUTABLE Main)
enable_language(C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Headers
set(CUBEMX_INCLUDE_DIRECTORIES
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/${MCU_FAMILY}_HAL_Driver/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/${MCU_FAMILY}_HAL_Driver/Inc/Legacy
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Device/ST/${MCU_FAMILY}/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Include)
set(PROJECT_INCLUDE_DIRECTORIES
    ${PROJECT_DIR}
    ${PROJECT_DIR}/include/api
    # ${PROJECT_DIR}/include/Main
    # ${PROJECT_DIR}/include/core
    # # ${PROJECT_DIR}/include/core/federated
    # ${PROJECT_DIR}/include/core/modal_models
    # ${PROJECT_DIR}/include/core/platform
    # # ${PROJECT_DIR}/include/core/threaded
    # ${PROJECT_DIR}/include/core/utils
)

# Sources
file(GLOB_RECURSE STM32CUBEMX_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/*.c)

# Executable files
add_executable(${EXECUTABLE}
    ${STM32CUBEMX_SOURCES} 
    ${STARTUP_SCRIPT}
    ${PROJECT_DIR}/lib/schedule.c
    ${PROJECT_DIR}/_main_main.c
    ${PROJECT_DIR}/Main.c
)

# Embedded macros(defines)
target_compile_definitions(${EXECUTABLE} PRIVATE
    ${MCU_MODEL}
    USE_HAL_DRIVER)

# Add header directories (AFTER add_executable !!)
target_include_directories(${EXECUTABLE} PRIVATE
    ${CUBEMX_INCLUDE_DIRECTORIES}
)

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


# LF add subdirectory
add_subdirectory(${PROJECT_DIR}/core)
target_link_libraries(${EXECUTABLE} PUBLIC core)
target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_DIR})
target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_DIR}/include/)
target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_DIR}/include/api)
target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_DIR}/include/core)
target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_DIR}/include/core/platform)
target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_DIR}/include/core/modal_models)
target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_DIR}/include/core/utils)



target_compile_definitions( ${EXECUTABLE} PUBLIC LF_UNTHREADED=1)
    install(
        TARGETS ${EXECUTABLE}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )

# ==============================================================================
#
# ==============================================================================