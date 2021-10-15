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

As of right now, the program doesn't check for integer-only input. If you feed it any other data, it'll result in UB (Undefined-Behaviour) so that's a thing
to change (But depends on the previous statement).