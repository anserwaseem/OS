1. A program using ordinary pipes in which one process send an integer array to its child.
2. Then, child calculate its sum and send it back to the parent.
3. Parent displays the result. 

This requires the use of two pipes: 
- one for sending the original message from the first to the second process.
- the other for sending the modified message from the second back to the first process.
