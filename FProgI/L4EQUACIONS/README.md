# Laboratory 4 - Equacions

## Compiling

```bash
# Check if we're in the source code dir, should return [path]./GTDAWIM/FProgI/L4EQUACIONS
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

# Compile the file
# By default, we add the Wall and Wextra switches to check for potential warnings at compile time.
gcc equacions.c -Wall -Wextra -lm
```
## Running

By default I don't change the output binary name nor format (By default my GCC and LD yield the following -> ELF 64-bit Position-Independent-Executable [PIE]), bear in mind that if you decide to do so, you'll have to change the following command accordingly!

```bash
# Run the program
./a.out

# Example output
Utilitat per calcular les arrels d'una equació de segon grau (ax^2+bx+c=0)
Per començar, escrigui el valor de a: 2
Ara escrigui el valor de b: 8
Finalment, el valor de c: -16
Discriminant: 192
Les sol·lucions son 1.464102 i -5.464102
```
## Joc de proves

| Prova | Descripció                          | Entrades               | Sortida esperada                                                   | Sortida obtinguda                                                                                                                                  | OK? |
| :---- |:----------------------------------- |:---------------------- |:------------------------------------------------------------------ |:-------------------------------------------------------------------------------------------------------------------------------------------------- |:---:|
| 1     | No és equació de 2n grau            | a = 0, b = 1, c = 1    | No és una equació de segon grau!                                   | L'equació no es de segon grau!                                                                                                                     | ✓   |
| 2     | No té solució (Moodle)              | a = 0, b = 1, c = 1    | L'equació no té solucions                                          | L'equació no es de segon grau! (Which is 100% correct, Moodle's wrong beacuse it specifies an if-else that prohibits program execution if a = 0 ‼️ | ✓   |
| 3     | No té solució (Mine)                | a = 1, b = 2, c = 5    | L'equació no té solucions                                          | No existeixen sol·lucions!                                                                                                                         | ✓   |
| 4     | Equació de solució única            | a = 1, b = 8, c = 16   | Les solucions son -4 i -4                                          | La sol·lució és -4.000000                                                                                                                          | ✓   |
| 5     | Dos solucions                       | a = 1, b = 0, c = -4   | Les solucions son 2 i -2                                           | Les sol·lucions son 2.000000 i -2.000000                                                                                                           | ✓   |

## Additional notes

Good practise that teaches you how you can put mathematical problems inside your program and solve them, it's a matter of dividing the operations and processing them accordingly.

I particularly dislike Code::Blocks so I compile and test everything under Linux and GNU's GCC is my go-to compiler, to if you're using it don't forget to specify "-lm" (Link Math) to gcc's command line arguments to link against gcc's math library (I use sqrt() function to calculate the square root of the determinant).
