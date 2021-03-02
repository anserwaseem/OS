# Semaphore

A very significant technique to manage concurrent processes by using a simple integer value, which is known as a semaphore. <br>
Semaphore is simply a variable which is non-negative and shared between threads. <br>
This variable is used to solve the critical section problem and to achieve process synchronization in the multiprocessing environment. 

A semaphore is like an integer, with three differences:
1. When you create the semaphore, you can initialize its value to any integer, but after that the only operations you are allowed to perform are increment (increase by one) and decrement (decrease by one). You cannot read the current value of the semaphore.
2. When a thread decrements the semaphore, if the result is negative, the thread blocks itself and cannot continue until another thread increments the semaphore.
3. When a thread increments the semaphore, if there are other threads waiting, one of the waiting threads gets unblocked.

We'll use following functions for completing semaphore tasks
- initialize a semaphore (either shared or not) with a value  **sem_init()**
- wait on a semaphore (If the value of the semaphore is negative, the calling process blocks; one of the blocked processes wakes up when another process calls sem_post). **sem_wait()**
- increment the value of the semaphore and wake up a blocked process waiting on the semaphore, if any  **sem_post()**
- destroy a semaphore  **sem_destroy()**

For more information, visit [here](https://www.geeksforgeeks.org/semaphores-in-process-synchronization/)
