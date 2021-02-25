# Shared Memory
Shared memory is a memory shared between two or more processes. 
However, why do we need to share memory or some other means of communication?

Usually, inter-related process communication is performed using Pipes.
Unrelated processes (say one process running in one terminal and another process in another terminal) communication can be performed through popular IPC techniques of Shared Memory and many others.

We use following system calls to create and utilize shared memory:
1. Allocates a shared memory segment or use already existing one  **shmget()**
2. Maps a shared memory segment onto your process’s address space  **shmat()**
3. Detach a shared memory region from the process’s address space  **shmdt()**
4. Control operations on the shared memory segment  **shmctl()**

Write following command on your terminal to get more information on these system calls.

```sh
man syscall
```
where, syscall can be any system call.

Visit can visit [here](https://www.tutorialspoint.com/inter_process_communication/inter_process_communication_shared_memory.htm) for more information.
