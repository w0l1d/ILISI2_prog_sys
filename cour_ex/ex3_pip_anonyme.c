#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#define R 0
#define W 1
int main() {
	int fd[2];
	pipe(fd);
	char message[100];
	int nboctets;
	char * phrase = "message envoye au pere par le fils";
	if (fork() ==0) {
		close(fd[R]);
		write(fd[W], phrase, strlen(phrase)+1);
		close(fd[W]);
	} else {
		close(fd[W]);
		nboctets = read(fd[R], message, 100);
		printf("Lecture %d octets : %s\n", nboctets, message);
		close(fd[R]);
	}
	return 0;
}
