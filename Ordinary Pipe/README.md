# Pipes

Ordinary pipes allow two processes to communicate in standard producer consumer fashion: 
the producer writes to one end of the pipe (the write-end) and the consumer reads from the other end (the read-end).
As a result, ordinary pipes are unidirectional, allowing only one-way communication. 
If two-way communication is required, two pipes must be used, with each pipe sending data in a different direction.
A pipe has a read end and a write end. Data written to the write end of a pipe can be read from the read end of the pipe.

## Create a Pipe

On UNIX and Linux systems, ordinary pipes are constructed
using the function
- int pipe(int fd[2]) -- creates a pipe
- returns two file descriptors, fd[0], fd[1]
- fd[0] is the read-end of the pipe
- fd[1] is the write-end
- fd[0] is opened for reading
- fd[1] for writing
- pipe() returns 0 on success, -1 on failure

**NOTE**: The standard programming model is that after the pipe has
been set up, two (or more) cooperative processes will be created
by a fork and data will be passed using read() and write().
> Pipes opened with pipe() should be closed with
close(int fd).

## When pipe() System Call Fails:
The pipe() system call fails for many reasons, including the following:
1. At least two slots are not empty in the FDT—too many files or
pipes are open in the process.
2. Buffer space not available in the kernel
