#define _GNU_SOURCE
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
  int fd[2];
  int counter = 0;

  if(pipe(fd) < 0){
    printf("Can\'t open pipe\n");
    exit(-1);
  }

  printf("%d %d\n", fcntl(fd[0], F_GETPIPE_SZ), fcntl(fd[1], F_GETPIPE_SZ));

  close(fd[0]);
  close(fd[1]);

  return 0;
}
