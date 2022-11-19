#include <stdio.h>
#include <stdlib.h>awk -F, '$3 == "c" && $5""' file
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>
#include <time.h>

int main() {
	int s;
	pid_t p1,p2,p3;
	p1=fork();
	if (!p1) {
		execl("ls","ls", "-l", NULL);
		return 0;
	}
	p2=fork();
	if (!p2) {
		execl("ps","ps", "-l", NULL);
		return 0; 
	}
	p3=wait(NULL);
	wait(NULL);
	if (p1 == p3)
		printf("\n la commande ls (%d) a fini en premier.\n", p1);
	else
		printf("\n la commande ps (%d) a fini en premier.\n", p2);
	
	return 0;
}


