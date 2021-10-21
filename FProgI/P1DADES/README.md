# Practise 0 - Dades

## Compiling

```bash
# Check if we're in the source code dir, should return [path]./GTDAWIM/FProgI/P1DADES
# else just cd onto the path
pwd

# Check your build environment and compare it against mine (There should not be problems if yo're using
# a recent x86_64 PC with Ubuntu [Or any distro you prefer that contains GNUs C Compiler]), next steps are
# OPTIONAL but they can help tracing down incompatibility issues if you can't compile the code succesfully

# Check GCC version
gcc --version

# Check your Linux version
uname -a

# Check your distro version (Command may vary distro to distro, not all are based-off Debian!)
# Command for Ubuntu (And Ubuntu-based distros):
lsb_release -a

# Compile the file you want
# You can compile the one you find suiting, available ones are: estudiants.c  numtodig.c  parquets.c  and pladedades.c
# estudiants.c : Find the boys and girls % in a classroom, good for practising float utilisation
# numtodig.c : A integer digit separation tool, good for understanding how using (%) modulo operations outside mathematical logarithms shows it's not exclusive for math
# parquets.c : Good practise that focuses on calculating areas and perimeters, float use is recommended and you get to see some C rounding operations
# pladedades.c : Same as "parquets.c", 'upp-ing' the difficulty a little bit, I use a char array to simplify the code
# By default, we add the Wall and Wextra switches to check for potential warnings at compile time.
gcc estudiants.c -Wall -Wextra
```
## Running

By default I don't change the output binary name nor format (By default my GCC and LD yield the following -> ELF 64-bit Position-Independent-Executable [PIE]), bear in mind that if you decide to do so, you'll have to change the following command accordingly!

```bash
# Run the program
./a.out

# Example output (estudiants.c)
En aquest programa calcularem el percentatge de nois i noies en una aula
A continuació, introdueixi el nombre de nois: 12
Ara, el nombre de noies: 17 
Nombre total de nois: 12, (41.379311%); Nombre total de noies: 17 (58.620689%); Total d'alumnes: 29
```
