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
		//processus Fils
		srand(time(NULL));
		s = rand()%255;
		printf("random  : %d", s);
		exit (s);
	}
	waitpid(tmp, &s, 0);
	s=WEXITSTATUS(s);
	printf("\nrandom nombre : %d\n", s);
	return 0;
}


