#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void print_carac() {
	printf("\nPID: %d, PPID: %d, PGID: %d\n" 
			"propr reel: %d, propr effectif: %d,\n"
			" grp prop reel: %d, grp prop effetif: %d\n\n",
			getpid(),getppid(),getpgrp(), getuid(), geteuid(), getgid(), getegid());
}


int main() {
	pid_t tmp;

	tmp=fork();
	
	if (!tmp) {
		printf("Processus Fils : \n");
		print_carac();
		return 0;
	}
	
	printf("Processus Pere : \n");
	print_carac();

	
	return 0;
}
