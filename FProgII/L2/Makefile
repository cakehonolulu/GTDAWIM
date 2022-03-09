# Host variable
HOST =

# Compiler
CC =

# Check if we're compiling under Windows or UNIX
ifeq ($(OS), Windows_NT)
	HOST = Windows
	BINARY := lab2fp2.exe
	CC := mingw64-gcc
else
	UNAME := $(shell uname -s)
	ifeq ($(UNAME), Linux)
		HOST = Linux
		
		# Default to clang
		CC = clang

		ifdef USE_GCC
		CC = gcc
		endif

		ifdef CCWIN
		CC = mingw64-gcc
		endif

		CFILES := $(notdir $(wildcard *.c))
		COBJECTS := $(CFILES:.c=.o)
		BINARY := lab2fp2
	endif
endif

CFLAGS := -Wall -Wextra -pedantic -std=c2x -I.
LDFLAGS := -s libdades.a

all: clean info $(BINARY)

info:
	@echo "Building With: $(CC)"

$(BINARY): $(COBJECTS)
	@echo " \033[0;36mLD \033[0ml2"
	@$(CC) -o $@ $(COBJECTS) $(LDFLAGS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo " \033[0;35mCC\033[0m $<"

clean:
	-@rm *.exe
	-@rm *.o