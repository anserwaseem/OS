Implement a program that executes the command:
```sh
ls | sort
```

## Input/output Redirection:
To understand input/output redirection, we need to understand named pipes and dup2 system call first.

### Dup2:
Dup2 system call is used to make alias of a file descriptor, for example: <br>

```c
int fd = open(“file.txt”, O_WRONLY);
dup2(fd, 1);
printf(“This data will not be printed to the screen, but to the file”);
```

The above system call will first close file descriptor 1 using close system call. <br>
Then, file descriptor fd’s data will be copied to file descriptor 1. <br>
So, every write that is made using fd=1 will then be written to file.txt <br>

Similarly, <br>
```c
int fd = open(“file.txt”, O_RDONLY);
dup2(fd, 0);
char buffer[10];
scanf("%s", &buffer);
```

scanf will not get input from keyboard, but from file.txt in above piece of code.

For more information, please visit [here](https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/dup2.html)
