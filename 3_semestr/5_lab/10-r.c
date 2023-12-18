#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int     fd, result;

    size_t  size;
    char    resstring[14];
    char    name[] = "aaa.fifo";

    (void)umask(0);

    /*
    POSIX.1-2001 says: 
    "The only portable use of mknod() is to create a FIFO-special file.
    If mode is not S_IFIFO or dev is not 0, the behavior of mknod() is unspecified."

    However, nowadays one should never use mknod() for this purpose;
    one should use mkfifo(3), a function especially defined for this purpose.
    */

    if((fd = open(name, O_RDONLY)) < 0)
    {
        printf("Can\'t open FIFO for reading\n");
        exit(-1);
    }

    size = read(fd, resstring, 14);

    if(size < 0)
    {
        printf("Can\'t read string from FIFO\n");
        exit(-1);
    }

    printf("Reader completed, got: %s\n", resstring);

    close(fd);
   return 0;
}