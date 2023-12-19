#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFF_SIZE 8

int main()
{
    int *array;
    int shmid;
    int size;
    char pathname[] = "2-1.c";
    key_t key;

    if ((key = ftok(pathname,0)) < 0)
    {
        printf("Can\'t generate key\n");
        exit(-1);
    }

    if ((shmid = shmget(key, sizeof(int), 0)) < 0)
        {
            printf("Can\'t find shared memory\n");
            exit(-1);
        }

    if ((array = (char *)shmat(shmid, NULL, 0)) == (char *)(-1))
    {
        printf("Can't attach shared memory\n");
        exit(-1);
    }

    for (int i = 0; array[i] != 0; i++)
    {
        putchar(array[i]);
    }

    if (shmdt(array) < 0)
    {
        printf("Can't detach shared memory\n");
        exit(-1);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        printf("Can\'t delete shared memory\n");
        exit(-1);
    }

    return 0;
}
