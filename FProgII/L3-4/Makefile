# Setup the Compiler
CC = clang

# Setup the basic compilation flags
# Warn all, extra and compile for c2x
CFLAGS := -Wall -Wextra -pedantic -std=c2x -I.

BINARY := fp2lab34

ifdef DEBUG
CFLAGS += -g
endif

ifdef BRUTEFORCE
CFLAGS += -DBRUTEFORCE
endif

ifdef OPTIMAL
CFLAGS += -DOPTIMAL -lm
endif

ifdef TABLE
CFLAGS += -DTABLE
endif

ifdef BENCHMARK
CFLAGS += -DBENCHMARK
endif

all: clean $(BINARY)

ifdef BRUTEFORCE
$(BINARY): lab2fp34.c bruteforce.c
endif
ifdef OPTIMAL
$(BINARY): lab2fp34.c optimal.c
endif
ifdef TABLE
$(BINARY): lab2fp34.c table.c
endif
	@echo "🚧 Building..."
	$(CC) $(CFLAGS) $^ -o $@


gdb:
	gdb fp2lab34

clean:
	@echo "🧹 Cleaning..."
	-@rm $(BINARY)