#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>

int main(int argc, char **argv) {
	int n;
	if (argc == 2)
		sscanf(argv[1], "%d", &n);
	else
		n=20;
	
	int i,s;
	pid_t pids[n];
	char buffer[50];
	for (i = 1; i <= n; ++i) {
		if(!(pids[i-1] = fork())) {
			sprintf(buffer, "%d", i);
			execl("./fils", "fils", buffer, NULL);
		}
	}
	
	for (i =0; i < n; ++i) {
		waitpid(pids[i], &s, 0);
		s = (int)WEXITSTATUS(s);
		printf("i=%d ", s);
	}
	return 0;
	
}



