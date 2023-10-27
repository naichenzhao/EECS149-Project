# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# compile ASM with /usr/local/bin/arm-none-eabi-gcc
# compile C with /usr/local/bin/arm-none-eabi-gcc
# compile CXX with /usr/local/bin/arm-none-eabi-g++
ASM_DEFINES = -DINITIAL_EVENT_QUEUE_SIZE=10 -DINITIAL_REACT_QUEUE_SIZE=10 -DLF_FILE_SEPARATOR=\"/\" -DLF_PACKAGE_DIRECTORY=\"/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench\" -DLF_REACTION_GRAPH_BREADTH=1 -DLF_SOURCE_DIRECTORY=\"/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src\" -DLF_UNTHREADED=1 -DLIB_PICO_BIT_OPS=1 -DLIB_PICO_BIT_OPS_PICO=1 -DLIB_PICO_DIVIDER=1 -DLIB_PICO_DIVIDER_HARDWARE=1 -DLIB_PICO_DOUBLE=1 -DLIB_PICO_DOUBLE_PICO=1 -DLIB_PICO_FLOAT=1 -DLIB_PICO_FLOAT_PICO=1 -DLIB_PICO_INT64_OPS=1 -DLIB_PICO_INT64_OPS_PICO=1 -DLIB_PICO_MALLOC=1 -DLIB_PICO_MEM_OPS=1 -DLIB_PICO_MEM_OPS_PICO=1 -DLIB_PICO_MULTICORE=1 -DLIB_PICO_PLATFORM=1 -DLIB_PICO_PRINTF=1 -DLIB_PICO_PRINTF_PICO=1 -DLIB_PICO_RUNTIME=1 -DLIB_PICO_STANDARD_LINK=1 -DLIB_PICO_STDIO=1 -DLIB_PICO_STDIO_UART=1 -DLIB_PICO_STDLIB=1 -DLIB_PICO_SYNC=1 -DLIB_PICO_SYNC_CRITICAL_SECTION=1 -DLIB_PICO_SYNC_MUTEX=1 -DLIB_PICO_SYNC_SEM=1 -DLIB_PICO_TIME=1 -DLIB_PICO_UTIL=1 -DLOG_LEVEL=2 -DPICO_BOARD=\"pololu_3pi_2040_robot\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Release\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_USE_BLOCKED_RAM=0 -DPLATFORM_RP2040 -DPLATFORM_Rp2040

ASM_INCLUDES = -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include/core -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include/core/federated -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include/core/platform -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include/core/modal_models -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include/core/threaded -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include/core/utils -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_stdlib/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_gpio/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_base/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/build/generated/pico_base -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/boards/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_platform/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2040/hardware_regs/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_base/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2040/hardware_structs/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_claim/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_sync/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_irq/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_sync/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_time/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_timer/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_util/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_uart/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_resets/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_clocks/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_pll/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_vreg/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_watchdog/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_xosc/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_divider/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_runtime/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_printf/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_bit_ops/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_divider/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_double/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_float/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_malloc/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_bootrom/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_binary_info/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_stdio/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_stdio_uart/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_int64_ops/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_mem_ops/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/boot_stage2/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_multicore/include

ASM_FLAGS = -mcpu=cortex-m0plus -mthumb -O3 -DNDEBUG -ffunction-sections -fdata-sections

C_DEFINES = -DINITIAL_EVENT_QUEUE_SIZE=10 -DINITIAL_REACT_QUEUE_SIZE=10 -DLF_FILE_SEPARATOR=\"/\" -DLF_PACKAGE_DIRECTORY=\"/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench\" -DLF_REACTION_GRAPH_BREADTH=1 -DLF_SOURCE_DIRECTORY=\"/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src\" -DLF_UNTHREADED=1 -DLIB_PICO_BIT_OPS=1 -DLIB_PICO_BIT_OPS_PICO=1 -DLIB_PICO_DIVIDER=1 -DLIB_PICO_DIVIDER_HARDWARE=1 -DLIB_PICO_DOUBLE=1 -DLIB_PICO_DOUBLE_PICO=1 -DLIB_PICO_FLOAT=1 -DLIB_PICO_FLOAT_PICO=1 -DLIB_PICO_INT64_OPS=1 -DLIB_PICO_INT64_OPS_PICO=1 -DLIB_PICO_MALLOC=1 -DLIB_PICO_MEM_OPS=1 -DLIB_PICO_MEM_OPS_PICO=1 -DLIB_PICO_MULTICORE=1 -DLIB_PICO_PLATFORM=1 -DLIB_PICO_PRINTF=1 -DLIB_PICO_PRINTF_PICO=1 -DLIB_PICO_RUNTIME=1 -DLIB_PICO_STANDARD_LINK=1 -DLIB_PICO_STDIO=1 -DLIB_PICO_STDIO_UART=1 -DLIB_PICO_STDLIB=1 -DLIB_PICO_SYNC=1 -DLIB_PICO_SYNC_CRITICAL_SECTION=1 -DLIB_PICO_SYNC_MUTEX=1 -DLIB_PICO_SYNC_SEM=1 -DLIB_PICO_TIME=1 -DLIB_PICO_UTIL=1 -DLOG_LEVEL=2 -DPICO_BOARD=\"pololu_3pi_2040_robot\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Release\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_USE_BLOCKED_RAM=0 -DPLATFORM_RP2040 -DPLATFORM_Rp2040

C_INCLUDES = -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include/core -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include/core/federated -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include/core/platform -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include/core/modal_models -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include/core/threaded -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include/core/utils -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_stdlib/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_gpio/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_base/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/build/generated/pico_base -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/boards/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_platform/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2040/hardware_regs/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_base/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2040/hardware_structs/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_claim/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_sync/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_irq/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_sync/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_time/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_timer/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_util/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_uart/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_resets/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_clocks/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_pll/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_vreg/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_watchdog/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_xosc/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_divider/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_runtime/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_printf/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_bit_ops/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_divider/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_double/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_float/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_malloc/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_bootrom/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_binary_info/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_stdio/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_stdio_uart/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_int64_ops/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_mem_ops/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/boot_stage2/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_multicore/include

C_FLAGS = -mcpu=cortex-m0plus -mthumb -w -O3 -DNDEBUG -std=gnu11 -ffunction-sections -fdata-sections

CXX_DEFINES = -DINITIAL_EVENT_QUEUE_SIZE=10 -DINITIAL_REACT_QUEUE_SIZE=10 -DLF_FILE_SEPARATOR=\"/\" -DLF_PACKAGE_DIRECTORY=\"/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench\" -DLF_REACTION_GRAPH_BREADTH=1 -DLF_SOURCE_DIRECTORY=\"/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src\" -DLF_UNTHREADED=1 -DLIB_PICO_BIT_OPS=1 -DLIB_PICO_BIT_OPS_PICO=1 -DLIB_PICO_DIVIDER=1 -DLIB_PICO_DIVIDER_HARDWARE=1 -DLIB_PICO_DOUBLE=1 -DLIB_PICO_DOUBLE_PICO=1 -DLIB_PICO_FLOAT=1 -DLIB_PICO_FLOAT_PICO=1 -DLIB_PICO_INT64_OPS=1 -DLIB_PICO_INT64_OPS_PICO=1 -DLIB_PICO_MALLOC=1 -DLIB_PICO_MEM_OPS=1 -DLIB_PICO_MEM_OPS_PICO=1 -DLIB_PICO_MULTICORE=1 -DLIB_PICO_PLATFORM=1 -DLIB_PICO_PRINTF=1 -DLIB_PICO_PRINTF_PICO=1 -DLIB_PICO_RUNTIME=1 -DLIB_PICO_STANDARD_LINK=1 -DLIB_PICO_STDIO=1 -DLIB_PICO_STDIO_UART=1 -DLIB_PICO_STDLIB=1 -DLIB_PICO_SYNC=1 -DLIB_PICO_SYNC_CRITICAL_SECTION=1 -DLIB_PICO_SYNC_MUTEX=1 -DLIB_PICO_SYNC_SEM=1 -DLIB_PICO_TIME=1 -DLIB_PICO_UTIL=1 -DLOG_LEVEL=2 -DPICO_BOARD=\"pololu_3pi_2040_robot\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Release\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_USE_BLOCKED_RAM=0 -DPLATFORM_RP2040 -DPLATFORM_Rp2040

CXX_INCLUDES = -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include/core -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include/core/federated -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include/core/platform -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include/core/modal_models -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include/core/threaded -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/core/../include/core/utils -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_stdlib/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_gpio/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_base/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/build/generated/pico_base -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/boards/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_platform/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2040/hardware_regs/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_base/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2040/hardware_structs/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_claim/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_sync/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_irq/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_sync/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_time/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_timer/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_util/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_uart/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_resets/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_clocks/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_pll/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_vreg/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_watchdog/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_xosc/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/hardware_divider/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_runtime/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_printf/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_bit_ops/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_divider/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_double/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_float/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_malloc/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_bootrom/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/common/pico_binary_info/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_stdio/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_stdio_uart/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_int64_ops/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_mem_ops/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/boot_stage2/include -I/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/pico-sdk/src/rp2_common/pico_multicore/include

CXX_FLAGS = -mcpu=cortex-m0plus -mthumb -O3 -DNDEBUG -std=gnu++17 -ffunction-sections -fdata-sections -fno-exceptions -fno-unwind-tables -fno-rtti -fno-use-cxa-atexit

