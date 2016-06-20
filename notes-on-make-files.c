/*

NOTES on saving time on compiling many linked files
  Process for compiling many files
    Individual C source files --> [Individually Compiled] --> Individual Object code files --> [All Linked] --> One Executable
  If you only change one file, instead of recompiling all, save the object code for each file, only recompile the changed file, and link all
    1. Create object code for every source code file (.c extension) in directory
      $ gcc -c *.c
    2. Link all object files (.o extension) in directory together and run
      $ gcc *.o -o launch
    3. Recompile single file, re-link object files in directory and launch
      $ gcc -c example.c
      $ gcc *.o -o launch

NOTES on Make files
  Format: rule line and recipe line

  Example:
    launch.o: launch.c launch.h thruster.h
      gcc -c launch.c
    thruster.o: thruster.h thruster.c
      gcc -c thruster.c
    launch: launch.o thruster.o
      gcc launch.o thruster.o -o launch
*/
