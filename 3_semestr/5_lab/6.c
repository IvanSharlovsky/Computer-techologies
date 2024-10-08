#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
   int      fd[2], result;
   ssize_t  size;
   char     resstring[9];

   if(pipe(fd) < 0)
   {
     printf("Can\'t open pipe\n");
     exit(-1);
   }

   result = fork();

   if(result < 0) 
   {
      printf("Can\'t fork child\n");
      exit(-1);
   } 
   else if (result > 0) 
   {

     /* Parent process */

      close(fd[0]);

      size = write(fd[1], "/bin/ls", 8);

      if(size != 8)
      {
        printf("Can\'t write all string to pipe\n");
        exit(-1);
      }

      close(fd[1]);
      printf("Parent exit\n");

   } 
   else 
   {

      /* Child process */

      close(fd[1]);
      
      size = read(fd[0], resstring, 8);

      if(size < 0)
      {
         printf("Can\'t read string from pipe\n");
         exit(-1);
      }

      close(fd[0]);

      (void) execle(resstring, resstring, getenv("HOME"), "-l", 0, envp);
      printf("Error on execle\n");
      exit(-1);
   }

   return 0;
}
