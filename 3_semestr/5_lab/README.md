# LabWork 5

## Organization of interaction processes via a pipeline and FIFO in UNIX

- ### 1. Compile program 05-0.c and run it. Note the discrepancy between the access rights to the created file specified in the parameters of the open() system call. Explain the reason for the discrepancy

- ### 2. Compile program 05-1.c and run it. Note the use of the umask() system call with the 0 parameter so that the access rights to the created file exactly contain the indication in the open() system call

- ### 3. Modify program 05-1.c from the load section so that it reads the previously provided information in the file and prints it on the screen. It is advisable to delete all unnecessary operators, leaving the necessary ones

- ### 4. Compile program 05-2.c (working with a pipeline within a single process), run it. Explain the results

- ### 5. Compile program 05-3.c (one-way communication between parent and child), run it. Explain the results

- ### 6. Advanced task: modify example 05-3.c to communicate with each other two related processes executing different programs

- ### 7. Modify program 05-3.c for two-way communication, compile it and run it

- ### 8. Advanced task: determine the pipe size for your system

- ### 9. Compile program 05-4.c, run it. In this program, a parent process and a child process are created via a named program pipe

- ### 10. Write two unrelated programs, one of which writes information to a FIFO, and the other reads from it
