#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int     fd;
  ssize_t  size;
  char    ch;

  if((fd = open("myfile", O_RDONLY)) < 0)
  {
    printf("Can\'t open file\n");
    exit(-1);
  }

  //char resstring[14]
  //size = read(fd, resstring, 14);

  while ((size = read(fd, &ch, 1)) > 0)
  { 
    putchar (ch);
  }

  if(size < 0)
  {
    printf("Can\'t read file\n");
    exit(-1);
  }

  if(close(fd) < 0)
  {
    printf("Can\'t close file\n");
  }

  return 0;
}
