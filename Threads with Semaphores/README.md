Write a multi threaded program which creates N instances of a thread (N given by user).

Read the given program and build your logic according to the given instructions in the comments of the code.

```c
void* function(void* param)
{
    int id = *(int*)param;

    printf("%s%d\n", ”This Is thread Number: “, id);
    //block here until all N thread instances have printed (use semaphores + some counter variable)

    printf("%s%d\n", ”Barrier crossed by thread Number: “, id); //this line will not be printed until all N threads have executed the first printf statement.

}

int main()
{
    //Create N threads here.

    //barrier (main function will not print the line below until all N thread have completed. Do not used join; USE SEMAPHORE/S.
    printf(”All threads have completed”);

}
```

> Use the concepts of semaphore and thread.
