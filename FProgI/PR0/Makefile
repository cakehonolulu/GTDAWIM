# Setup the Linux Compiler (In this case GNU GCC)
CC = gcc

# Setup the basic compilation flags
# Warn all, extra and compile for c2x
CFLAGS := -Wall -Wextra -pedantic -std=c2x

BINARY := a.out

ifdef DEBUG
CFLAGS += -g
endif

all: clean $(BINARY)

$(BINARY): *.c
	@echo "🚧 Building..."

ifdef EXTENDED
	$(CC) $(CFLAGS) prac0_extended.c -o $@
else
	$(CC) $(CFLAGS) prac0.c -o $@
endif

gdb:
	gdb a.out

clean:
	@echo "🧹 Cleaning..."
	-@rm $(BINARY)