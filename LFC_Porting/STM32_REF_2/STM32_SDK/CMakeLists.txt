set(STM32_SDK_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

set(MCU_FAMILY STM32F4xx)

set(INCLUDE_DIRECTORIES
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/Legacy
    # ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Device/ST/${MCU_FAMILY}/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Include
)


file(GLOB_RECURSE GENERAL_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/*.c
)

# Add C sources to library
add_library(STM32_SDK ${GENERAL_SOURCES})

# Add included sources to library
target_include_directories(${EXECUTABLE} PRIVATE
    ${INCLUDE_DIRECTORIES})

macro(define X)
    if(DEFINED ${X})
        message(STATUS ${X}=${${X}})
        target_compile_definitions(core PUBLIC ${X}=${${X}})
    endif(DEFINED ${X})
endmacro()

define(STM32F446xx)
define(USE_HAL_DRIVER)
define(STM32F4)