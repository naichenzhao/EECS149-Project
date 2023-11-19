
######################################
# target
######################################
TARGET = Main

#######################################
# paths
#######################################
# Build path
BUILD_DIR = bin
SRC_GEN = src-gen

#######################################
# clean up
#######################################
clean: 
	-rm -fR $(SRC_GEN)


#######################################
# run everything
#######################################
build:
	lfc-dev src/Main.lf

#######################################
# flash the controller
#######################################
flash: build
	openocd -f /Users/naichenzhao/openocd-0.12.0/tcl/interface/stlink.cfg -f /Users/naichenzhao/openocd-0.12.0/tcl/target/stm32f4x.cfg -c "program $(BUILD_DIR)/$(TARGET).elf verify reset exit"
