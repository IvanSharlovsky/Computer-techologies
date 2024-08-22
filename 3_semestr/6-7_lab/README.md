# LabWork 6-7

## System V IPC tools

## Organization of work with shared memory in UNIX

- ### 1. Compile programs 06-1a.c and 06-1b.c, run them several times. Analyze the results

- ### 2. Write two programs that interact via shared memory. The first program should create a shared memory segment and copy its own source code there, the second program should take this text from there, print it on the screen and delete the shared memory segment from the system

- ### 3. Compile programs 06-3a.c and 06-3b.c and run any of them once to create and initialize shared memory. Then run the other one and, while it is in the loop, run (for example, from another virtual terminal) the first program again. Explain the result

- ### 4. Advanced task: modify programs 06-3a.c and 06-3b.c to work correctly using Peterson's algorithm. Assume that shared memory is initialized outside the critical section

## The concept of threads

- ### 5. Compile program 06-2.c to illustrate the operation of two execution threads and run it

- ### 6. Modify the previous program (06-2.c) by adding a third execution thread to it
