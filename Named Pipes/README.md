# Named Pipe

It is an extension to the traditional pipe concept on Unix. A traditional pipe is “unnamed” and lasts only as long as the process.

A named pipe, however, can last as long as the system is up, beyond the life of the process. It can be deleted if no longer used.

We can use single named pipe that can be used for two-way communication (communication between the server and the client, plus the client and the server at the same time) as Named Pipe supports bi-directional communication.

Usually a named pipe appears as a file, and generally processes attach to it for inter-process communication. A FIFO file is a special kind of file on the local storage which allows two or more processes to communicate with each other by reading/writing to/from this file.

A FIFO special file is entered into the filesystem by calling mkfifo() in C.

Once we have created a FIFO special file in this way, any process can open it for reading or writing, in the same way as an ordinary file. However, it has to be open at both ends simultaneously before you can proceed to do any input or output operations on it.

Reading from or writing to a named pipe occurs just like traditional file reading and writing; except that the data for named pipe is never written to or read from a file in hard disk but memory.

We'll be using following functions for tasks on named pipes.
- create a FIFO special file, which is used for named pipe.  **mkfifo()**

## I/O Redirection
The ability to treat terminal input and output interchangeably with file input/output for most commands.
Programmer can program to standard interface while caller can change where the I/O goes
1. Testing (read from test file)
2. Debugging (splitting output and errors)
3. Logging (save output)
4. Network communication (read/write to/from socket files)

You should visit [here](https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/dup2.html) for more information.
