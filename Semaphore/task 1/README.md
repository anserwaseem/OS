# Task
- producer has to write N values in buffer.
- when producer has written N values, consumer has to read all N values.

## Example
Following 2 threads share that buffer. Both run simultaneously.<br>
Do synchronization with given variables.

Sem1 = N , Sem2 = 1, Mutex = 1 (2 semaphores and 1 is mutex)<br>
Char buffer[n] (shared variable)


Producer                     Consumer          <br>
...................                 ..................<br>
...................                 ..................<br>
writeBuffer(buffer)     readBuffer(buffer)
