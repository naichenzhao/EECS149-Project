
######################################
# target
######################################
TARGET = STM32_REF

#######################################
# paths
#######################################
# Build path
BUILD_DIR = build

#######################################
# Generate cmake
#######################################
gen: clean
	cmake -B$(BUILD_DIR) -DCMAKE_TOOLCHAIN_FILE=arm-none-eabi-gcc.cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=true

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

