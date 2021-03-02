# Task
There are exactly 3 threads generate string a, b and c in an arbitrary order. In an absence of any
synchronization mechanism there will be no order in generation of a, b and c. In the form of regular
expression the string (a | b | c)* {* means many times a character an occur, | means or, so different
combinations can be aaaaaaa… , bbbbbbbbbbb… , ccccc… }. Synchronize threads using semaphore in
such a way that your printed string will be (cba)* {* means many times cba can occur, so different
combinations will be cbacbacbacb….}.

Note you are not allowed to add or delete any cout statement


| //Thread 1        | //Thread 2        | //Thread 3        |
| :---              | :---              | :---              |
| while(1)          | while(1)          | while(1)          |
| {                 | {                 | {                 |
|     printf("a");  |     printf("b");  |     printf("c");  |
| }                 | }                 | }                 |
