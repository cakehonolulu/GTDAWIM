ARCH	:= -march=armv5te -mlittle-endian
ASFLAGS	:= $(ARCH) -g
LDFLAGS := -z max-page-size=0x8000

all:
	arm-none-eabi-as $(ASFLAGS) main.S -o main.o
	arm-none-eabi-as $(ASFLAGS) ../../p_lib/startup.S -o startup.o
	arm-none-eabi-ld $(LFLAGS) startup.o main.o -o main.elf

clean:
	-@rm -f *.o
	-@rm -f p_lib/*.o
	-@rm -f *.elf

debug:
	qemu-arm -L /usr/share/gcc-arm-none-eabi/lib -g 1337 main.elf &
	-@arm-none-eabi-gdb -x gdb_cmd
	-@pkill -9 qemu-arm

