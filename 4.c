#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[], char *envp[]) {

	printf("num of arg = %d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("%d = %s\n", i, argv[i]);
	}

	return 0;
	}
