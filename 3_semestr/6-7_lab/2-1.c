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
    int fd;
    int *array;
    int shmid;
    int src_size = BUFF_SIZE;
    char pathname[] = "2-1.c";
    key_t key;
    char source;

    if ((key = ftok(pathname,0)) < 0)
    {
        printf("Can\'t generate key\n");
        exit(-1);
    }

    if((shmid = shmget(key, 100000 * sizeof(char), 0666|IPC_CREAT|IPC_EXCL)) < 0)
    {
        if (errno != EEXIST)
        {
            printf("Can\'t create shared memory\n");
            exit(-1);
        } 
        else 
        {
            if ((shmid = shmget(key, src_size * sizeof(char), 0)) < 0)
            {
                printf("Can\'t find shared memory\n");
                exit(-1);
            }
        }
    }

    if ((array = (char *)shmat(shmid, NULL, 0)) == (char *)(-1))
    {
        printf("Can't attach shared memory\n");
        exit(-1);
    }

    if ((fd = open(pathname, O_RDONLY)) < 0)
    {
        printf("Can\'t open file\n");
        exit(-1);
    }

    for(int i = 0; read(fd, &source, 1) > 0; i++)
    {
        array[i] = source;
    }

    if (close(fd) < 0)
    {
        printf("Can\'t close file\n");
    }

    if (shmdt(array) < 0)
    {
        printf("Can't detach shared memory\n");
        exit(-1);
    }

    return 0;
}
