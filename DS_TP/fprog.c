#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>



int main(int argc, char **argv) {
	int i;
	sscanf(argv[1], "%d", &i);
	printf("pid=%d ", getpid());
	exit(i);
	return i;
}
