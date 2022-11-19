#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main() {
	int fd;
	char message[100];
	sprintf(message, "bonjour du writer [%d]\n", getpid());
	fd = open("mypipe", O_WRONLY);
	printf("ici writer[%d]\n", getpid());
	if (fd != -1)
		write(fd, message, strlen(message)+1);
	else 
		printf("desole, le tube n'est pas disponible\n");
		
	close(fd);
	return 0;
}
