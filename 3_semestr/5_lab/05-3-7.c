#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int     fd_pc[2], fd_cp[2], result;

   ssize_t size;
   char  resstring[20];

   if(pipe(fd_pc) < 0)
   {
     printf("Can\'t open pipe pc\n");
     exit(-1);
   }

   if(pipe(fd_cp) < 0)
   {
     printf("Can\'t open pipe cp\n");
     exit(-1);
   }

   result = fork();

   if(result < 0) 
   {
      printf("Can\'t fork child\n");
      exit(-1);
   } else if (result > 0) {

     /* Parent process */

      close(fd_pc[0]);
      close(fd_cp[1]);

      size = write(fd_pc[1], "Hello from parent!", 19);

      if(size != 19)
      {
        printf("Can\'t write all string to pipe pc\n");
        exit(-1);
      }

      size = read(fd_cp[0], resstring, 19);

      if(size < 0)
      {
         printf("Can\'t read string from pipe cp\n");
         exit(-1);
      }

      close(fd_pc[1]);
      close(fd_cp[0]);
      printf("Parent exit, resstring: %s\n", resstring);

   } else {

      /* Child process */

      close(fd_pc[1]);
      close(fd_cp[0]);

      size = write(fd_cp[1], "Hello from child!!", 19);

      if(size != 19)
      {
        printf("Can\'t write all string to pipe cp\n");
        exit(-1);
      }

      size = read(fd_pc[0], resstring, 19);

      if(size < 0)
      {
         printf("Can\'t read string from pipe pc\n");
         exit(-1);
      }

      close(fd_pc[0]);
      close(fd_cp[1]);
      printf("Child exit, resstring: %s\n", resstring);
   }

   return 0;
}
