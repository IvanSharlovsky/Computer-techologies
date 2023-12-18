#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int     fd;

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

    if(mkfifo(name, 0666) < 0){
        printf("Can\'t create FIFO\n");
        exit(-1);
   }

    if((fd = open(name, O_WRONLY)) < 0)
    {
        printf("Can\'t open FIFO for writting\n");
	    exit(-1);
    }

    size = write(fd, "Hello, world!", 14);

    if(size != 14)
    {
        printf("Can\'t write all string to FIFO\n");
        exit(-1);
    }

    close(fd);
    printf("Writer completed\n");

   return 0;
}