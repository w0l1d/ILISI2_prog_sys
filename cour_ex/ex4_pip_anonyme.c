#include <unistd.h>
#include <stdio.h>
#define R 0
#define W 1

int main (int argc, char *argv[]) {
	int fd[2];
	pipe(fd);
	char message[100];
	int nboctets;
	char *phrase = "message envoye au pere par le fils";
	if (fork() != 0) {
		close(fd[R]);
		dup2(fd[W], W);
		close(fd[W]);
		if (execlp(argv[1], argv[1], NULL) ==-1);
		perror("error dans execlp");
	} else {
		close(fd[W]);
		dup2(fd[R], 0);
		close(fd[R]);
		execlp(argv[2], argv[2], NULL);
		perror("connect");
	}

	return 0;
}
