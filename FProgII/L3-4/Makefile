# Setup the Compiler
CC = clang

# Setup the basic compilation flags
# Warn all, extra and compile for c2x
CFLAGS := -Wall -Wextra -pedantic -std=c2x -I.

BINARY := fp2lab34

TIMEFMT = "\t%E real\n\t%U user\n\t%S sys\n"

ifdef WIN
CC = x86_64-w64-mingw32-gcc
endif

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

ifdef EXTERNAL_TIME
CFLAGS += -DEXTERNAL_TIME
endif

ifdef OPTIMIZATION
CFLAGS += -O3
endif

all: clean $(BINARY)

ifndef EXTERNAL_TIME
ifndef RETAIL
$(BINARY): lab2fp34.c benchmark.c bruteforce.c optimal.c table.c
	@echo "🚧 Building..."
	$(CC) $(CFLAGS) -DBENCHMARK $^ -o $@ -lm
else
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
endif
else
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
	$(CC) $(CFLAGS) -DBENCHMARK $^ -o $@
endif

bench:
	$(CC) $(CFLAGS) -DBENCHMARK -DEXTERNAL_TIME -DBRUTEFORCE lab2fp34.c bruteforce.c -o bf
	$(CC) $(CFLAGS) -DBENCHMARK -DEXTERNAL_TIME -DOPTIMAL -lm lab2fp34.c optimal.c -o op
	$(CC) $(CFLAGS) -DBENCHMARK -DEXTERNAL_TIME -DTABLE lab2fp34.c table.c -o tb
ifndef WIN
	clear
	-@echo "Bruteforce Method:"
	-@/bin/time -f $(TIMEFMT) ./bf
	-@echo "Optimal Method:"
	-@/bin/time -f $(TIMEFMT) ./op
	-@echo "Table Method:"
	-@/bin/time -f $(TIMEFMT) ./tb
	-@rm bf op tb
endif

gdb: clean $(BINARY)
ifndef WIN
	gdb fp2lab34
endif

clean:
	@echo "🧹 Cleaning..."
	-@rm -f $(BINARY)
	-@rm -f bf op tb
	-@rm -f bf.exe op.exe tb.exe