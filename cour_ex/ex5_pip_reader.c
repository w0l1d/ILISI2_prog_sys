#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main() {
	int fd, n;
	char message[100];
	fd = open("mypipe", O_RDONLY);
	printf("ici reader[%d]\n", getpid());
	if (fd != -1) {
		while((n = read(fd, message, 100))>0)
			printf("%s\n",message);
		
	} else 
		printf("desole, le tube n'est pas disponible\n");
		
	close(fd);
	return 0;
}
