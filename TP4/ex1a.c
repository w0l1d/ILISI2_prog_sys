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



int counter;
pid_t father, son;



int main() {
	counter = 0;
	father = getpid();
	
	
	if ((son = fork())) {
		// father process
		
		raise(SIGTSTP);
		while (counter < 100) {
			usleep(1000);
			printf("%d ", counter++);
			kill(son, SIGCONT);
			raise(SIGSTOP);
		}
		
		
	} else {
		// son process
		while (counter < 100) {
			usleep(1000);
			printf("%d ", ++counter);
			kill(father, SIGCONT);
			raise(SIGTSTP);
		}
	}
	
	return 0;
}



