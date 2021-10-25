# FProgI Practise 0

This folder contains Practise 0's source code in C and this README documenting the things I might find or want to note.

## Compiling

```bash
# Check if we're in the source code dir, should return [path]./GTDAWIM/FProgI/PR0
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
# Source code accepts -DDEBUG switch in case you want to have debug printf()s
gcc prac0.c -Wall -Wextra
```

## Notes

I'd like to switch from scanf() to something else, scanf() is a real pain to get it working correctly (And even then, things can go south pretty easily).

~~As of right now, the program doesn't check for integer-only input. If you feed it any other data, it'll result in UB (Undefined-Behaviour) so that's a thing
to change (But depends on the previous statement).~~

-- Fixed in commit [41fc5e2](https://github.com/cakehonolulu/GTDAWIM/commit/41fc5e2da91319899a9dc78328833a5bb32b73fb)

I've done my best to mitigate integer overflows while using scanf(), but my solution has some tradeoffs (Which are the best outcome I've found).

I first tried limitating the user input using %x (Where x is a number from 1-inf), but if I 'overfilled' the scanf() buffer with a large number, the next variables waiting for their own scanf() would all get filled automatically (I suspect scanf() reads the input from a buffer that grows as much as the user input, and the next scanf() reads where the other one ended reading).

The "solution" (Not really a solution, but more of an approach) is to limit the variable assignation in a way that I can only use n-1 digits of it (If unsigned char = 255, then limit it to 99, from 3 to 2 digits and so on with the other types).

With my approach you can *still* overflow the variable (But it's much, much more harder) and it'll only affect the variable I'm filling, next ones won't be affected. So I'm "effectively" reducing the potential bad outcome to only a 1 variable "poisioning".

This is *far* from perfect but it's optimal considering how much of a mess scanf() (And it's family of functions) is and the scope of the program
