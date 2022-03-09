# Host variable
HOST =

# Compiler
CC =

# GNU ARchiver (Library manipulation)
AR = ar

# Check if we're compiling under Windows or UNIX
ifeq ($(OS), Windows_NT)
	HOST = Windows
	BINARY := lab2fp2.exe
	CC := mingw64-gcc
else
	UNAME := $(shell uname -s)
	ifeq ($(UNAME), Linux)
		HOST = Linux
		
		CFILES := $(notdir $(wildcard *.c))
		LIB := dades.o
		COBJECTS := $(CFILES:.c=.o)

		BINARY := lab2fp2

		# Default to clang
		CC = clang

		ifdef USE_GCC
		CC = gcc
		endif

		ifdef CCWIN
		CC = mingw64-gcc
		HOST = Windows
		BINARY := lab2fp2.exe
		CFILES := $(filter-out dades.c,$(CFILES))
		COBJECTS := $(CFILES:.c=.o)
		endif
	endif
endif

CFLAGS := -Wall -Wextra -pedantic -std=c2x -I.
LDFLAGS := 

ifeq ($(HOST), Windows)
LDFLAGS += -L. -ldades
else
LDFLAGS += -L. -linhouse_dades
endif

all: clean info $(BINARY)

info:
	@echo "Building With: $(CC)"

$(BINARY): $(COBJECTS)
ifeq ($(HOST), Windows)
	@echo " \033[0;36mLD \033[0m$(BINARY)"
	@$(CC) -o $@ $(COBJECTS) $(LDFLAGS)
else
	@echo " \033[0;33mAR \033[0minhouse_dades.a"
	@$(AR) rcs libinhouse_dades.a dades.o
	@echo " \033[0;36mLD \033[0m$(BINARY)"
	@$(CC) -o $@ $(filter-out $(LIB),$(CFILES:.c=.o)) $(LDFLAGS)
endif

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo " \033[0;35mCC\033[0m $<"

clean:
	-@rm -f *.exe
	-@rm -f *.o
	-@rm -f lab2fp2
	-@rm -f libinhouse_dades.a