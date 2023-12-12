# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# compile ASM with /usr/local/bin/arm-none-eabi-gcc
# compile C with /usr/local/bin/arm-none-eabi-gcc
ASM_DEFINES = -DLF_FILE_SEPARATOR=\"/\" -DLF_PACKAGE_DIRECTORY=\"/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller\" -DLF_REACTION_GRAPH_BREADTH=3 -DLF_SINGLE_THREADED=1 -DLF_SOURCE_DIRECTORY=\"/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src\" -DLOG_LEVEL=2 -DMODAL_REACTORS=TRUE -DPLATFORM_STM32F4 -DPLATFORM_Stm32 -DSTM32F446xx -DUSE_HAL_DRIVER

ASM_INCLUDES = -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/. -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/include -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/include/api -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/include/core -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/include/core/platform -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/include/core/modal_models -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/include/core/utils -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/core/../include -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/core/../include/core -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/core/../include/core/federated -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/core/../include/core/platform -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/core/../include/core/modal_models -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/core/../include/core/threaded -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/core/../include/core/utils -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/include/Main -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/../../STM_sdk/Core/Inc -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/../../STM_sdk/Drivers/STM32F4xx_HAL_Driver/Inc -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/../../STM_sdk/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/../../STM_sdk/Drivers/CMSIS/Device/ST/STM32F4xx/Include -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/../../STM_sdk/Drivers/CMSIS/Include

ASM_FLAGS = -O3 -DNDEBUG -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -Wall -Wextra -Wpedantic -Wno-unused-parameter -Og -g0

C_DEFINES = -DLF_FILE_SEPARATOR=\"/\" -DLF_PACKAGE_DIRECTORY=\"/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller\" -DLF_REACTION_GRAPH_BREADTH=3 -DLF_SINGLE_THREADED=1 -DLF_SOURCE_DIRECTORY=\"/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src\" -DLOG_LEVEL=2 -DMODAL_REACTORS=TRUE -DPLATFORM_STM32F4 -DPLATFORM_Stm32 -DSTM32F446xx -DUSE_HAL_DRIVER

C_INCLUDES = -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/. -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/include -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/include/api -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/include/core -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/include/core/platform -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/include/core/modal_models -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/include/core/utils -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/core/../include -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/core/../include/core -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/core/../include/core/federated -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/core/../include/core/platform -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/core/../include/core/modal_models -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/core/../include/core/threaded -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/core/../include/core/utils -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/include/Main -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/../../STM_sdk/Core/Inc -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/../../STM_sdk/Drivers/STM32F4xx_HAL_Driver/Inc -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/../../STM_sdk/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/../../STM_sdk/Drivers/CMSIS/Device/ST/STM32F4xx/Include -I/Users/naichenzhao/Desktop/EECS149-Project/lfc_controller/src-gen/Main/../../STM_sdk/Drivers/CMSIS/Include

C_FLAGS = -O3 -DNDEBUG -std=gnu11 -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -Wall -Wextra -Wpedantic -Wno-unused-parameter -Og -g0

