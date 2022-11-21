#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define MAX_SIZE 1000
#define REQUEST_FILE	"request"
#define RESPONSE_FILE 	"response"
#define PROJECT 1



typedef struct msgbuf {
	long int mtype;
	long tab[2];
}Request, Response, MSG;


int main() {
	
	int running = 1;
	key_t kreq = ftok(REQUEST_FILE, PROJECT), kres = ftok(RESPONSE_FILE, PROJECT);
	if (kreq == -1 || kres == -1) {
		perror("\nclient: Cannot get keys");
		exit(EXIT_FAILURE);
	}
	
	MSG msg;
	
	int freq = msgget(kreq, 0700|IPC_CREAT), 
		fres = msgget(kres, 0700|IPC_CREAT);
	if (fres == -1 || freq == -1) {
		perror("\nclient: cannot create file with key ");
		exit(1);	
	}
	msg.mtype = getpid();
	
	while (running) {
		
		printf("\n\nclient: Entrer deux entier : ");
		scanf("%d%d", &(msg.tab[0]), &(msg.tab[1]));
		if(msg.tab[0] == 0 && msg.tab[1] == 0)
			running = 0;
		if (msgsnd(freq, (void*)&msg, sizeof(msg.tab[0])*2, 0) == -1) {
				perror("\nclientmessage not sent");
		} else if (msgrcv(fres, (void*)&msg, sizeof(long), getpid(), 0) == -1) {
			perror("\nclient: could not receive result");
		} else 
			printf("\nclient : result.. %d", msg.tab[0]);
			
	}
		
	
}
