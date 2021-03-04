# Task
- Suppose there are two processes. Each process reads a different file (say, f1.txt & f2.txt) having a list of integers.
- Both processes read the integers, calculate their sum, and 
- send the sum and the count of integers to a server process via shared memory. 
- The server then finds the total average by following formulae:<br>
     Total Sum = sum of integers sent by p1 + sum of integers sent by p2 <br>
     Total Count = count sent by p1 + count sent by p2 <br>
     Average = Total Sum/ Total Count <br>   
- After calculating the average, the server sends the average to both processes. 
- Both processes then print the sum on their respective terminal. 
> **synchronize the processes using semaphores on shared memory**

## Example

Suppose we have an array of integers: 1, 10, 9, 100, 23, 4, 11, 12, 3, and 1. The size of this array is 10. <br>
Now if we want to calculate the average, we can simply do: <br>
Average = sum of elements/ total elements. <br>

Now, if we have a large number of elements, then it will take a lot of time to calculate the average. We can utilize parallelism by dividing the task of finding the sum among different processes. Suppose a process p1 finds the sum of first 4 elements: <br>
Sum1 = 1+10+9+100 = 120 <br>
Count = 4 <br>

And another process p2 calculates the sums of remaining 6 elements: <br>
Sum2 = 23+4+11+12+3=53 <br>
Count = 6 <br>

Then average calculated as: <br>
Total Sum = Sum1+Sum2 = 120+53 = 173 <br>
Total Count = Count1 + Count2 = 4+6=10 <br>
Average = Total Sum/Total Count= 173/10 = 17 <br>
