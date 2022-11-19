#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

/*
Exercice 1
1) Ecrire un programme C qui crée deux processus à l'aide de l'appel système fork().
Le père affichera les entiers pairs compris entre 1 et 100, le fils affichera les entiers
impairs compris dans le même intervalle. Synch

*/







int main() {
	pid_t son, ppid = getpid();
	
	int counter;
	
	if ((son = fork()) != 0) {
		// father process
		counter = 0;
		while (counter <= 999) {
			usleep(10000);
			printf("%d ", counter);
			fflush(stdout);
			counter += 2;
			kill(son, SIGCONT);
			raise(SIGSTOP);
		}
	} else {
		// son process
		counter = 1;
		raise(SIGSTOP);
		while (counter <= 1000) {
			usleep(10000);
			printf("%d ", counter);
			fflush(stdout);
			counter += 2;
			kill(ppid, SIGCONT);
			raise(SIGSTOP);
		}
	}
	
	
	return 0;
}



