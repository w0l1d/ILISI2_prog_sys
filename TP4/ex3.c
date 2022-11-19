#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

#define R 0
#define W 1


int main() {
	int res[2];
	int req[2];
	if (pipe(res) || pipe(req)) {
		perror("\nError: cannot create pipe");
		exit(1);
	}
	
	pid_t pid;
	if ((pid=fork()) < 0) {
		perror("\nError: cannot fork");
		exit(2);
	}
	
	if (pid) {
		//client
		close(res[W]); // connot write reponses
		close(req[R]); // connot read requests
		while (1) {
			int a[2];
			printf("\nEntrer deux valeurs (0 0 pour quitter) : ");
			scanf("%d%d", a,a+1);
			if (!a[0] && !a[1]) {
				kill(pid, SIGKILL);
				return 0;
			}
			write(req[W], a, sizeof (int) *2);
			read(res[R], a, sizeof (int));
			printf("\nla resultat est %d", a[0]);
			
			
		}
	} else {
		//server
		close(res[R]); // connot read reponses
		close(req[W]); // connot write requests
//		dup2(res[W], W);
//		dup2(req[R], R);
		while (1) {
			int a[2];
			read(req[R], a, sizeof(int)*2);
			a[0] += a[1];
			
			write(res[W], a, sizeof (int));
		}
	}
		
	return 0;
}
