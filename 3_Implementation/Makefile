PROJ_NAME = VEHICLE_MONITORING_SYSTEM

BUILD_DIR = Build

# All Source code files
SRC = main_test/main.c\
src/case1.c\
src/case2.c\
src/case3.c

# All header file paths
INC = -I inc

# Configuring for Both Windows and Linux Operating System
ifdef OS	# Windwos OS
# Correct the path based on OS
   FixPath = $(subst /,\,$1)
# AVR Compiler
   CC = avr-gcc.exe
# .elf to .hex
   AVR_OBJ_CPY = avr-objcopy.exe
else # Linux OS
   ifeq ($(shell uname), Linux)
# Correct the path based on Linux
      FixPath = $1				
# AVR Compiler
	  CC = avr-gcc
# N.elf to .hex
	  AVR_OBJ_CPY = avr-objcopy 
   endif
endif

# Command to make to consider these names as targets and not as file names in folder
.PHONY:all analysis clean doc

all:$(BUILD_DIR)
# Compile the code and generate the ELF file
	$(CC) -g -Wall -Os -mmcu=atmega328  $(INC) $(SRC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).elf)

$(BUILD_DIR):
# Create directory to store the built files
	mkdir $(BUILD_DIR)

analysis: $(SRC)
# Analyse the code using Cppcheck command line utility
	cppcheck --enable=all $^

doc:
# Build the code code documentation using Doxygen command line utility
	make -C documentation

clean:
# Remove all the build files and generated document files
	rm -rf $(call FixPath,$(BUILD_DIR)/*)
	make -C documentation clean