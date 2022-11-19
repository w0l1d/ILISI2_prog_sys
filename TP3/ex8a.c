#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>
#include <time.h>

void runInBg(char *cmd[], int cpt) {
	pid_t p;
	p = fork();
	if (p == 0) {
		p = fork();
		if(!p) {
			
			printf("[%d] %d\n", cpt, getpid());
			execvp(cmd[0], cmd);
		}
		wait(NULL);
		
		printf("[%d] - done %s\n", cpt, cmd[0]);
		exit (0);
	}
}



int main(int argc, char **argv) {
	char *list[3][4] = {{"who", NULL}, {"ps", NULL}, {"ls", "-l", NULL}};
	int i;
	
	for (i = 0; i < 2; ++i)
		runInBg(list[i], i+1);
	if(!fork())
		execvp(list[2][0], list[2]);
	wait(NULL);
	return 0;
}


