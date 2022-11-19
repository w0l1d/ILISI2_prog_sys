#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>


void getArgs(char *str, int *argn, char *args[]) {
	int i = 0;
	char *ptr = strtok(str, " ");

	while (ptr != NULL) {
		args[i++] = ptr;
		ptr = strtok(NULL, " ");
	}
	args[(*argn = i)] = NULL;
}



int main(int argc, char **argv) {
	
	printf("Hello user!!");
	do {
		char cmd[1024];
		printf("\nmonshell> ");
		scanf("%[^\n]%*c", cmd);
		
		if(!strcmp(cmd, "exit")) {
			printf("Good Bye");
			exit(0);
		}
		
		pid_t tmp = fork();
		if(!tmp) {
			int size;
			char *array[30];

			getArgs(cmd, &size, array);
			//int i = 0;
			//while (array[i])
				//printf ("\n%s", array[i++]);
			execvp(array[0], array);
			exit(1);
		}
		wait(NULL);
	} while(1);
		
	return 0;
}


