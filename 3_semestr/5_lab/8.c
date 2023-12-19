#define _GNU_SOURCE
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
  int fd[2];

  if(pipe(fd) < 0){
    printf("Can\'t open pipe\n");
    exit(-1);
  }

  close(fd[1]);
    
  printf("%d\n", fcntl(fd[0], F_GETPIPE_SZ));

  close(fd[0]);

  return 0;
}
