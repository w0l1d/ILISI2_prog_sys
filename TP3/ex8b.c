#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>
#include <time.h>




void onlyRun(char *cmd[]) {
	pid_t p;
	p = fork();
	if (p == 0)
		execvp(cmd[0], cmd);
	
}

int main(int argc, char **argv) {
	char *list[3][4] = {{"who", NULL}, {"ps", NULL}, {"ls", "-l", NULL}};
	int i;
	
	for (i = 0; i < 3; ++i) {onlyRun(list[i]); wait(NULL)};
		
	return 0;
}


