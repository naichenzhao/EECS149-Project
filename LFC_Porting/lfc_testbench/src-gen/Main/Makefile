
######################################
# target
######################################
TARGET = Main

#######################################
# paths
#######################################
# Build path
BUILD_DIR = ../../STM_build

#######################################
# Generate cmake
#######################################
# cmake -B$(BUILD_DIR) -DCMAKE_TOOLCHAIN_FILE=arm-none-eabi-gcc.cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=true
# cmake --build . --target install --parallel 16 --config Debug
# TOOLCHAIN FILES:+/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/arm-none-eabi-gcc.cmake
# TOOLCHAIN FILES:+/Users/naichenzhao/Desktop/EECS149-Project/LFC_Porting/lfc_testbench/src-gen/Main/arm-none-eabi-gcc.cmake
gen: clean
	clear
	cmake -B$(BUILD_DIR) -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=true

#######################################
# Generate cmake
#######################################
build: gen
	cd $(BUILD_DIR) && make -j8

#######################################
# openocd flash
#######################################
flash: build
	openocd -f /Users/naichenzhao/openocd-0.12.0/tcl/interface/stlink.cfg -f /Users/naichenzhao/openocd-0.12.0/tcl/target/stm32f4x.cfg -c "program $(BUILD_DIR)/$(TARGET).elf verify reset exit"


#######################################
# clean up
#######################################
clean: 
	-rm -fR $(BUILD_DIR)
