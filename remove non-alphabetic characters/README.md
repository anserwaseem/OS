- Create “input.txt”.
- Write a simple program that read a text file “input.txt” and remove non-Alphabetic characters and copy text in “output.txt” file.
- Execute program using “gcc” command.

## Compiling C/C++ program using g++ and gcc:
### For C++:

```sh 
g++ source_files… -o output_file
```

### For C:
```sh 
gcc source_files… -o output_file
```

Source files need not be cpp or c files. They can be preprocessed files, assembly files, or object files.

The whole compilation file works in the following way:
Cpp/c file(s) -> Preprocessed file(s) -> Assembly File(s) Generation -> Object file(s) Generation -> Final Executable

Every c/cpp file has its own preprocessed file, assembly file, and object file.

1. For running only the preprocessor, we use
-E option.
2. For running the compilation process till assembly file generation, we use –S option.
3. For running the compilation process till object file creation, we use –c option.
4. If no option is specified, the whole compilation process till the generation of executable will run.

A file generated using any option can be used to create the final executable. For example, let’s suppose that we have two source
files: math.cpp and main.cpp, and we create object files:

```sh
g++ main.cpp –c –o main.o

g++ math.cpp –c –o math.o
```

The object files created using above two commands can be used to generate the final executable.
g++ main.o math.o –o my_executable

The file named “my_executable” is the final exe file. There is specific extension for executable files in Linux.
