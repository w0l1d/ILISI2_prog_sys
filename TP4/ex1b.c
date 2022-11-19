#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

/*
Exercice 1
2) Le signal SIGCHLD est un signal qui est automatiquement envoyé par le fils à son
père lorsque le fils se termine (par un exit, un return, ou autre). Ajoutez une fonction
et le code nécessaire afin que le père n’attende jamais son fils de façon bloquante et
que le fils ne devienne pas zombie.

*/
int status = -1;

void* handler() {
	wait(&status);
	printf("child is here\n");
}




/*0*/
int main(int argc, char *argv[])
{
	if (signal(SIGCHLD, &handler) == SIG_ERR) {
		perror("error : connot associate handler ignore to child signal\n");
		exit(1);
	}
	
	/*1*/
	if (!fork()) {
		/*2*/
		for (int i = 0 ; i <10 ; i++, sleep(1), printf("calculating..\n")) ; //simule un petit calcul
		/*3*/
		exit(100);
		/*4*/
	}
	
	/*5*/
	int i = 0;
	while(i++ < 100) { 
		if (status != -1) {
			printf ("\nchild exit status : %d", WEXITSTATUS(status));
			status = -1;
		} 
		usleep(500000);
		printf("waiting...\n"); 
	} //Simule un calcul infini
	/*6*/
}



