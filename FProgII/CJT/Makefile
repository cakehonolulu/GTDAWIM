CFLAGS := -Wall -Wextra -pedantic -g
LDFLAGS:= 

all:
	clang $(CFLAGS) -c main.c -o main.o
	clang $(CFLAGS) -c cjt_paraules.c -o cjt_paraules.o
	clang $(LDFLAGS) main.o cjt_paraules.o -o cjt_paraules
