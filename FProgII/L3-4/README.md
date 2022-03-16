# Compiling

## Without make:

### LLVM's CLANG;
clang -Wall -Wextra -pedantic lab2fp34.c benchmark.c bruteforce.c optimal.c table.c -I. -DBENCHMARK -lm -o fp2lab34

### GNU's GCC;
gcc -Wall -Wextra -pedantic lab2fp34.c benchmark.c bruteforce.c optimal.c table.c -I. -DBENCHMARK -lm -o fp2lab34

### Windows Cross-Compilation:
Substitute the compiler by one that supports Windows as a target, examples: mingw...

--------

## With make:
### Default make target builds the practise's result (time spent on function displayed on stdout using time_t structs).

### make EXTERNAL_TIME=1 METHOD=1
Builds 1 of 3 methods (BRUTEFORCE, OPTIMAL, TABLE) individually to be tested using external exec-time-info tools

#### Example: make EXTERNAL_TIME=1 OPTIMAL=1
Builds optimal method in benchmark mode and doesn't append any input/output so that it can be tested using external profiling tools.

--------

### RETAIL=1 METHOD=1
Builds 1 of 3 methods (BRUTEFORCE, OPTIMAL, TABLE) individually and provides a simple Text UI for the user to test 1 number he chooses.

#### Example: make EXTERNAL_TIME=1 BRUTEFORCE=1
Builds bruteforce method in retail mode and the resulting program asks the user for 1 number to check if triangular or not.

# Tested on
## Ryzen PC
### 6-core Ryzen 5 5600G | 16 GB DDR4 3200MHz (1600MT/s)
### Linux 5.10.102.1 | Ubuntu Jammy Jellyfish (development branch) (22.04) (WSL, Hyper-V based)
--------

## HP Pavilion-15  CS3003NS
### 4-core Intel i5-1035G1 | 16 GB DDR4 2667 MHz (1333MT/s)
### Linux 5.16.9 | Ubuntu Jammy Jellyfish (development branch) (22.04) 
