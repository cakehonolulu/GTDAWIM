# Setup the Linux Compiler (In this case GNU GCC)
CC = clang

# Setup the basic compilation flags
# Warn all, extra and compile for c2x
CFLAGS := -Wall -Wextra -pedantic -std=c2x

BINARY := a.out

ifdef SYMB
CFLAGS += -g
endif

ifdef FSAN
CFLAGS += -fsanitize=address
endif

ifdef DEBUG
CFLAGS += -DDEBUG
endif

all: clean $(BINARY)

$(BINARY): *.c
	@echo "🚧 Building..."

ifdef EXTENDED
	$(CC) $(CFLAGS) prac1_extended.c -o $@
else
	$(CC) $(CFLAGS) prac1.c -o $@
endif

gdb:
	gdb a.out

clean:
	@echo "🧹 Cleaning..."
	-@rm $(BINARY)