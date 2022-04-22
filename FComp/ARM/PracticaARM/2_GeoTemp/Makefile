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

ifdef CHECK_ASM
CCFLAGS += -DCHECK_ASM
endif

#-------------------------------------------------------------------------------
# make commands
#-------------------------------------------------------------------------------
ifdef CHECK_ASM
demo.elf : fahn startup build/data.o build/geotemp.o build/avgmaxmintemp_asm.o build/avgmaxmintemp.o 
	arm-none-eabi-ld $(LDFLAGS) p_lib/startup.o build/data.o build/geotemp.o build/avgmaxmintemp_asm.o \
					 build/avgmaxmintemp.o -Lp_lib -lfoncompus -lcelfahr -o demo.elf
else
demo.elf : fahn startup build/data.o build/geotemp.o build/avgmaxmintemp.o 
	arm-none-eabi-ld $(LDFLAGS) p_lib/startup.o build/data.o build/geotemp.o \
					 build/avgmaxmintemp.o -Lp_lib -lfoncompus -lcelfahr -o demo.elf
endif

test_geotemp.elf : fahn startup build/test_geotemp.o build/avgmaxmintemp_asm.o build/avgmaxmintemp.o build/data.o
	arm-none-eabi-ld $(LDFLAGS) p_lib/startup.o build/data.o build/test_geotemp.o build/avgmaxmintemp_asm.o build/avgmaxmintemp.o \
						-Lp_lib -lfoncompus -lcelfahr -o test_geotemp.elf

startup:
	arm-none-eabi-as $(ASFLAGS) -c p_lib/startup.S -o p_lib/startup.o

fahn:
	make -C ../1_CelsiusFahrenheit_GAS/ lib
	mv ../1_CelsiusFahrenheit_GAS/libcelfahr.a p_lib/

build/data.o: source/data.c
	arm-none-eabi-gcc $(CCFLAGS) -c source/data.c -o build/data.o

build/geotemp.o: source/geotemp.c
	arm-none-eabi-gcc $(CCFLAGS) -c source/geotemp.c -o build/geotemp.o

build/test_geotemp.o: tests/test_geotemp.c
	arm-none-eabi-gcc $(CCFLAGS) -c tests/test_geotemp.c -o build/test_geotemp.o

build/avgmaxmintemp.o: source/avgmaxmintemp.c
	arm-none-eabi-gcc $(CCFLAGS) -c source/avgmaxmintemp.c -o build/avgmaxmintemp.o

build/avgmaxmintemp_asm.o: source/avgmaxmintemp_asm.s
	arm-none-eabi-as $(ASFLAGS) -c source/avgmaxmintemp_asm.s -o build/avgmaxmintemp_asm.o

#-------------------------------------------------------------------------------
# clean commands
#-------------------------------------------------------------------------------
clean : 
	@rm -fv build/*
	@rm -fv *.elf
	@rm -fv p_lib/libcelfahr.a


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

debugc:
	qemu-arm -L /usr/lib/arm-none-eabi/lib/ -g 1338 democ.elf &
	-@arm-none-eabi-gdb -x gdb_cmd_c
	-@pkill -9 qemu-arm

debugtest:
	qemu-arm -L /usr/lib/arm-none-eabi/lib/ -g 1337 test_geotemp.elf &
	-@arm-none-eabi-gdb -x gdb_cmd_test
	-@pkill -9 qemu-arm

twover: clean fahn startup build/data.o build/geotemp.o build/avgmaxmintemp_asm.o build/avgmaxmintemp.o 	
	arm-none-eabi-ld $(LDFLAGS) p_lib/startup.o build/data.o build/geotemp.o build/avgmaxmintemp.o \
					 -lfoncompus -lcelfahr -o democ.elf
	
	arm-none-eabi-ld $(LDFLAGS) p_lib/startup.o build/data.o build/geotemp.o build/avgmaxmintemp_asm.o \
					 -lfoncompus -lcelfahr -o demo.elf
