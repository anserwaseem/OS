# System Calls

In computing, a system call is the programmatic way in which a computer program requests a service from the
kernel of the operating system it is executed on. A system call is a way for programs to interact with the operating
system.
- System Calls provide the Interface between a process and the Operating System.
- These calls are generally available as Assembly language instruction.
- System Calls can also be made directly through High Level Language programs for certain systems.
- UNIX System calls can be invoked directly from a C or C++ program.

## Fork

Fork system call is used for creating a new process, which is called child process, which runs concurrently with the
process that makes the fork() call (parent process)

- After a new child process is created, both processes will execute the next instruction following the fork()
system call.
- A child process uses the same pc(program counter), same CPU registers, same open files which use in the
parent process.
- It takes no parameters but returns an integer value.

> How to differentiate between a Parent and Child during execution?
> Below are different values returned by fork():
> - **Negative Value**: creation of a child process was unsuccessful.
> - **Zero**: Returned to the newly created child process.
> - **Positive value**: Returned to parent or caller. The value contains process ID of newly created child process.

*Note: Order of parent and child execution can vary unless controlled.*

## Wait

A call to wait() blocks the calling process until one of its child processes exits or a signal is received. After child
process terminates, parent continues its execution after wait system call instruction.

-----------
- C program that takes an integer array of 10 values from the user in parent process.
- The program then creates a child processes.
- Child 1 sorts the array in ascending order and displays it on the screen.
- Then 2 child processes are made.
- Child 1 sorts the array in ascending order and displays it on the screen.
- Child 2 sorts the array in descending order and displays it on the screen.
- Except input and process creation no work is done by the parent process and parent terminates afterchild process.
