# Multi Thread Program
- a multithreaded program that calculates various statistical values for a list of numbers. 
- this program will be passed a series of numbers on the command line.
- it will then create three separate worker threads. 
- one thread will determine the average of the numbers.
- the second will determine the maximum value.
- the third will determine the minimum value. 

## Example
For example, suppose your program is passed the integers. (The array of numbers must be passed as parameter to threads, and the thread
must return the calculated value to main thread).
<br>90 81 78 95 79 72 85

The main thread will print:

The average value is 82<br>
The minimum value is 72<br>
The maximum value is 95
