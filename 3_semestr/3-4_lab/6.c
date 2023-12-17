#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    pid_t pid, ppid, chpid;

    chpid = fork();

    pid  = getpid();
    ppid = getppid();

    switch (chpid) {
        case -1:
            printf("Error on fork\n");
            exit(-1);
        case 0:
            (void) execle("/bin/ls", "/bin/ls", getenv("HOME"), "-l", 0, envp);
            printf("Error on execle\n");
            exit(-1);
    	default:
            printf("My pid = %d, my ppid = %d\n", (int)pid, (int)ppid);
    }
    return 0;
}