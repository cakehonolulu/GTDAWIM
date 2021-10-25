# Laboratory 2 - Xifres i Lletres

## Compiling

```bash
# Check if we're in the source code dir, should return [path]./GTDAWIM/FProgI/L2XIF_I_LLET
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
# You can compile the one you find suiting, available ones are: caracters.c  divisions.c  majtomintomaj.c  and sortirderang.c
# caracters.c : Find the numeric representation of alphabetic characters and symbols
# divisions.c : See how divisions of floats work, it's a perfect way of understanding how type-casting works
# majtomintoma.c : A capital letter to a lowercase one (Or the inverse), good for understanding how this sort of conversions are done
# sortirderang.c : A little Proof-of-Concept on how integer-overflows happen, this shows why it's a good idea to check for them as they can be a pain to track down
# By default, we add the Wall and Wextra switches to check for potential warnings at compile time.
gcc caracters.c -Wall -Wextra
```
## Running

By default I don't change the output binary name nor format (By default my GCC and LD yield the following -> ELF 64-bit Position-Independent-Executable [PIE]), bear in mind that if you decide to do so, you'll have to change the following command accordingly!

```bash
# Run the program
./a.out

# Example output (majtomintoma.c)
Programa per convertir entre majúscules i minúscules
A continuació introdueixi la lletra que vulgui (Autodetecta majúscules): b
L'usuari ha escrit b
Lletra minúscula detectada: b convertida a: B
```