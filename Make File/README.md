# Makefile in Linux

## Compiler Process

- #### Compiler Stage: 
All C++ language code in the .cpp file is converted
into a lower-level language called Assembly language; making .s
files.

- #### Assembler Stage: 
The assembly language code made by the
previous stage is then converted into object code which are
fragments of code which the computer understands directly. An
object code file ends with .o.

- #### Linker Stage: 
The final stage in compiling a program involves linking the object code to code libraries which contain certain "built-
in" functions, such as cout. This stage produces an executable program, which is named a.out by default.

### Benefits:
- Provide a way for *separate compilation*.
- Describe the *dependencies* among the project files.
- The *make* utility.

### Naming:
- **makefile** or **Makefile** are standard
- other name can be also used

### Running make:
```sh
make
```
OR
```sh
make –f filename
```
– if the name of your file is not “makefile”
or “Makefile”

### Example:
```sh
my_prog : eval.o main.o
g++ -o my_prog eval.o main.o

eval.o : eval.c eval.h
g++ -c eval.c
main.o : main.c eval.h
g++ -c main.c
```
_________________________
- -o to specify executable file name
- -c to compile only (no linking)
