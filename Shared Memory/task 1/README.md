1. Create a private shared memory. 
2. The process then creates a child and 
    - waits for the child to write the file’s contents to shared memory. 
3. The parent then reads the shared memory and 
    - changes the case of each character and removes all integers from the data. 
4. The child reads it back and 
    - writes the changed data back to the same file. (The file name is passed as command
line argument).
