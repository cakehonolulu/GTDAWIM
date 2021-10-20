# Laboratory 3 - Turisme Rural

## Joc de proves

| Prova | Descripció                          | Entrades               | Sortida esperada                                                   | Sortida obtinguda                                                               | OK? |
| :---- |:----------------------------------- |:---------------------- |:------------------------------------------------------------------ |:------------------------------------------------------------------------------- |:---:|
| 1     | Es supera la capacitat de la casa   | Persones: 13, Nits: 10 | Ha introduit (x > 12) persones, el máxim són 12!                   | Ha introduit 13 persones, el máxim són 12!                                      | ✓   |
| 2     | S'ocupa tota la casa                | Persones: 12, Nits: 10 | Preu allotjament 1500 euros, IVA 135 euros, Preu total 1815 euros  | Preu sense IVA: 1500 €, IVA (21%): 315.00 €, Preu Total (IVA Inclòs): 1815.00 € | ✓   |
| 3     | No s'ocupa tota la casa             | Persones: 11, Nits: 3  | Preu allotjament 450 euros, IVA 94.5 euros, Preu total 554,5 euros | Preu sense IVA: 450 €, IVA (21%): 94.50 €, Preu Total (IVA Inclòs): 544.50 €    | ✓   |
| 4     | Es supera el total de nits permeses | Persones: 11, Nits: 13 | Ha introduit (x > 12) nits, el máxim són 12!                       | El nombre de nits excedeix les 12 máximes permeses!                             | ✓   |

## Compiling

```bash
# Check if we're in the source code dir, should return [path]./GTDAWIM/FProgI/l3TUR_RURAL
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
# By default, we compile the regular (Non-extended) program, if you want the improved one, compile turismerural_e.c instead (Same cmd-line gcc switches!)
gcc turismerural.c -Wall -Wextra
```
## Running

By default I don't change the output binary name nor format (By default my GCC and LD yield the following -> ELF 64-bit Position-Independent-Executable [PIE]), bear in mind that if you decide to do so, you'll have to change the following command accordingly!

```bash
# Run the program
./a.out

# Example output
Càlcul de pressupost - Casa Rural Can Marball
A continuació introdueixi un nombre de persones a allotjar (Màxim 12): 12
Ara introdueixi el nombre de nits a allotjar-se: 11
Calculant pressupost per a 12 persones amb una estància de 11 nits...
Preu sense IVA: 1650 €, IVA (21%): 346.50 €, Preu Total (IVA Inclòs): 1996.50 €
```

## Additional notes

I've decided to split the practise in 2 different files: The one that will get the mark rating based on how it's structured and how it works (turismerural.c) and the one I've added "features" to (turismerural_e.c" which contains a little subset of features I've missed in the original practise.
