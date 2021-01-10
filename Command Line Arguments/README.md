# Command Line Arguments:
Command line arguments are a way to pass data to the program. Command line arguments are passed to the main
function. Suppose we want to pass two integer numbers to main function of an executable program called a.out. On the
terminal write the following line:
```sh
./a.out 1 22
```
./a.out is the usual method of running an executable via the terminal. Here 1 and 22 are the numbers that we have
passed as command line argument to the program. These arguments are passed to the main function. In order for the
main function to be able to accept the arguments, we have to change the signature of main function as follows:
### int main(int argc, char *arg[]);
> argc is the counter. It tells how many arguments have been passed.

> arg is the character pointer to our arguments.

argc in this case will not be equal to 2, but it will be equal to 3. This is because the name ./a.out is also passed as
command line argument. At index 0 of arg, we have ./a.out; at index 1, we have 1; and at index 2, we have 22. Here 1
and 22 are in the form of character string, we have to convert them to integers by using a function atoi. Suppose we want
to add the passed numbers and print the sum on the screen:
```sh
cout << atoi(arg[1]) + atoi(arg[2]);
```
