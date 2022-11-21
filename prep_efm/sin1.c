#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>


void action() {
	printf("action handler called\n");
}

int main() {
	pid_t p;
	if((p=fork())) {
		// father
		if(signal(SIGUSR2,(void*)&action)!=SIG_ERR)
			printf("Associated successefuly\n");
		else {
			printf("Error : 000\n");
			wait(NULL);
			exit(5);
		}
//		raise(SIGSTOP);
		pause();
		printf("pause lefted\n");
		int s;
		wait(&s);
		printf("left the wait %d", WEXITSTATUS(s));
		return 0;
	} else {
		// son
		sleep(4);
		printf("left sleep 4 %d\n",getppid());
		kill(getppid(), SIGUSR2);

		printf("signal submited\n");
		return 25;
	}
	
}//main
