# Single Threaded Program
- a program which takes some positive integers (let’s say N number of positive integers) as command line parameters.
- creates N synchronous threads.
- send the corresponding integer as parameter to the thread function. 
- The function returns the generated series to the main thread. 
- The main thread will then print the thread number and the series generated by that thread. 

## Example
If you pass as command line argument the following numbers: 3 13 34 89. Then the program will create 4 threads. The first thread will find Fibonacci terms until 3 is generated, the second Fibonacci thread will find Fibonacci terms until the term generated is 13 , so on and so forth. All generated terms will be output on the screen by the main thread as follows:

Thread 0: 0, 1, 1, 2, 3

Thread 1: 0, 1, 1, 2, 3, 5, 8, 13

Thread 2: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34

Thread 3: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89

It is possible that the number passed to the thread is not a Fibonacci number. In this case the thread will generate numbers until the term generated is greater than the passed number. 
For example, if 7 is passed as parameter to a thread, then the thread will return the following series:

0, 1, 1, 2, 3, 5, 8
