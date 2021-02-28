# Threads
A thread is a single sequence stream within in a process. 
It comprises of:
- thread ID
- program counter
- register set
- stack

It shares with other threads belonging to the same process its code section, data section, and other operating-system resources, such as open files and signals.

## Why using Threads?
Threads operate faster than processes due to following reasons:
1. Thread creation is much faster.
2. Context switching between threads is much faster.
3. Threads can be terminated easily
4. Communication between threads is faster.

 A traditional (or heavyweight) process has a ***single thread*** of control.
 
 If a process has ***multiple threads*** of control, it can perform more than one task at a time.

## Routines Used
C does not contain any built-in support for multithreaded applications. Instead, it relies entirely upon the operating system to provide this feature.
WE'll use following routines for completing our tasks.
1. Create a new thread and make it executable.  **pthread_create()**
2. Block the calling thread until the specified 'threadID' thread terminates.  **pthread_join()**
3. Explicitly exit a thread (when it has completed its work and is no longer required to exist)  **pthread_exit()**

Write following command on your terminal to get more information on these system calls.

```sh
man syscall
```
where, syscall can be any system call or built-in function name.

You can visit [here](https://www.tutorialspoint.com/cplusplus/cpp_multithreading.htm) for more information.
