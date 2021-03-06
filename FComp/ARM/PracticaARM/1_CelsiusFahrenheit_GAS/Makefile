#-------------------------------------------------------------------------------
# Example Makefile to build a library and to test the functions of each module
# Authors: Santiago Romani, Pere Millan
# Date: May 2020, March 2021, March 2022
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# options for code generation
#-------------------------------------------------------------------------------
ARCH	:= -march=armv5te -mlittle-endian
INCL    := -I./include
ASFLAGS	:= $(ARCH) $(INCL) -g
CCFLAGS	:= -Wall -g -O0 $(ARCH) $(INCL)
LDFLAGS := -z max-page-size=0x8000 -Lp_lib

#-------------------------------------------------------------------------------
# make commands
#-------------------------------------------------------------------------------
demo.elf : build/demo.o build/CelsiusFahrenheit.o 
	arm-none-eabi-ld $(LDFLAGS) build/demo.o build/CelsiusFahrenheit.o \
						p_lib/startup.o -o demo.elf

build/demo.o: source/demo.s
	arm-none-eabi-as $(ASFLAGS) source/demo.s -o build/demo.o

build/CelsiusFahrenheit.o: source/CelsiusFahrenheit.s include/Q12.i
	arm-none-eabi-as $(ASFLAGS) -c source/CelsiusFahrenheit.s -o build/CelsiusFahrenheit.o

test_CelsiusFahrenheit.elf : build/test_CelsiusFahrenheit.o build/CelsiusFahrenheit.o 
	arm-none-eabi-ld $(LDFLAGS) build/test_CelsiusFahrenheit.o build/CelsiusFahrenheit.o \
						p_lib/startup.o -o test_CelsiusFahrenheit.elf

build/test_CelsiusFahrenheit.o: tests/test_CelsiusFahrenheit.c include/CelsiusFahrenheit.h include/Q12.h
	arm-none-eabi-gcc $(CCFLAGS) -c tests/test_CelsiusFahrenheit.c -o build/test_CelsiusFahrenheit.o

lib: build/CelsiusFahrenheit.o
	arm-none-eabi-ar rcs libcelfahr.a build/CelsiusFahrenheit.o


#-------------------------------------------------------------------------------
# clean commands
#-------------------------------------------------------------------------------
clean : 
	@rm -fv build/*
	@rm -fv *.elf


#-----------------------------------------------------------------------------
# run commands
#-----------------------------------------------------------------------------
run : demo.elf
	arm-eabi-insight demo.elf &


#-----------------------------------------------------------------------------
# debug commands
#-----------------------------------------------------------------------------
debug:
	qemu-arm -L /usr/lib/arm-none-eabi/lib/ -g 1337 demo.elf &
	-@arm-none-eabi-gdb -x gdb_cmd
	-@pkill -9 qemu-arm

debugtest:
	qemu-arm -L /usr/lib/arm-none-eabi/lib/ -g 1337 test_CelsiusFahrenheit.elf &
	-@arm-none-eabi-gdb -x gdb_cmd_test
	-@pkill -9 qemu-arm
