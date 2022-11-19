#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define R 0
#define W 1

/*
	Exercice 2
	Ecrire un programme C équivalente à la commande shell
	ps -uax | grep root | wc –l
*/

int main () {
	int p1[2], p2[2];
	pipe(p1);
	if (fork()) {
		
		//father 0
		close(p1[R]);
		dup2(p1[W], W);
		execlp("ps", "ps", "-uax", NULL); 
	} else {
		//son 0
		close(p1[W]);
		dup2(p1[R], R);
		pipe(p2);
		if (fork()) {
			//father 1
			close(p2[R]);	
			dup2(p2[W], W);
			execlp("grep", "grep", "root", NULL);
		} else {
			//son 1
			close(p2[W]);
			dup2(p2[R], R);	
			execlp("wc", "wc", "-l", NULL);
		}
	}
	return 0;
}



