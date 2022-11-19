#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>
#include <time.h>

int main() {
	int s;
	pid_t tmp;
	tmp=fork();
	
	if (!tmp) {
	
		char* arg_list[] = { "ps", "-l", NULL };
		
		execv("ps", arg_list);
		exit (s);
	}
	waitpid(tmp, &s, 0);
	s = WEXITSTATUS(s);
	printf("\n ps return code : %d\n", s);
	return 0;
}


