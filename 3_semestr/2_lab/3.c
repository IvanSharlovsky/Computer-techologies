#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid, ppid, chpid;
    int a = 0;

    chpid = fork();

    pid  = getpid();
    ppid = getppid();

    if (chpid > 0) {
        a = 1;
    	printf("My pid = %d, my ppid = %d, result = %d\n", (int)pid, (int)ppid, a);
    }

    if (chpid == 0) {
        a = 2;
	    printf("Child pid = %d, child ppid = %d, result = %d\n", (int)pid, (int)ppid, a);
    }
    return 0;

}
