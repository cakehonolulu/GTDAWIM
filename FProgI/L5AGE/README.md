# Laboratory 5 - Edat

## Compiling

```bash
# Check if we're in the source code dir, should return [path]./GTDAWIM/FProgI/L5EDAT
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
# We'll also add -pedantic to further ensure source-code compliance and -g to include debug symbols to use with GDB
gcc jocedat.c -Wall -Wextra -pedantic -g
```
## Running

By default I don't change the output binary name nor format (By default my GCC and LD yield the following -> ELF 64-bit Position-Independent-Executable [PIE]), bear in mind that if you decide to do so, you'll have to change the following command accordingly!

```bash
# Run the program
./a.out

# Example output
Quina edat creus que tinc? 12      
Fred fred!
Prova un nombre més gran!
Quina edat creus que tinc? 20
Fred fred!
Prova un nombre més gran!
Quina edat creus que tinc? 30
Fred fred!
Prova un nombre més gran!
Quina edat creus que tinc? 40
Fred fred!
Prova un nombre més baix!
Quina edat creus que tinc? 35
Fred fred!
Prova un nombre més gran!
Oh... No ha aconseguit esdevinar la meva edat... Ha perdut!
```
## Joc de proves

| Prova | Descripció                            | Entrades                          | Sortida esperada                                                   | Sortida obtinguda                                           | OK? |
| :---- |:------------------------------------- |:--------------------------------- |:------------------------------------------------------------------ |:----------------------------------------------------------- |:---:|
| 1     | L'usuari ha exhaurit tots els intents | input < n < input                 | Oh... No ha aconseguit esdevinar la meva edat... Ha perdut!        | Oh... No ha aconseguit esdevinar la meva edat... Ha perdut! | ✓   |
| 2     | L'usuari ha encertat a l'últim intent | Last attempt, guessed correctly   | Ha encertat la meva edat! Ha guanyat!                              | Ha encertat la meva edat! Ha guanyat!                       | ✓   |
| 3     | L'usuari ha encertat en MAX_TRIES-1   | Guessed correctly below MAX_TRIES | Ha encertat la meva edat! Ha guanyat!                              | Ha encertat la meva edat! Ha guanyat!                       | ✓   |                                                                                                              | ✓   |

## Additional notes

This practise teaches you to use external functions (rand) and gives a very brief explanation on how RNG works on computers (Seed-based RNG).
It also teaches you how you can fluently write a while() loop without much hassle.

The practise uses Code::Blocks in-built GUI Debugger. I'm not particularly fan of GUI Debuggers so I opted for GNU's Command-line-based GDB.
Debugger works even without symbols (-g) but it's better to have them in order to make our life easier when printing variables by it's name ("print (m_edat)").
It'd be harder to start single-stepping through the code and finding the return value of rand() (Usually at (r)ax) using "info r" to print registers after each "s" (Single step).


