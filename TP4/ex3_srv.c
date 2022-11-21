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
		perror("\nserver: Cannot get keys");
		exit(EXIT_FAILURE);
	}
	
	MSG msg;
	
	int freq = msgget(kreq, 0700|IPC_CREAT), 
		fres = msgget(kres, 0700|IPC_CREAT);
	if (fres == -1 || freq == -1) {
		perror("\nserver: cannot create file with key ");
		exit(1);	
	}
	
	
	while (running) {
		printf("\nserver: waiting for request...\n");
		
		if(msgrcv(freq, (void*)&msg, sizeof(msg.tab[0])*2, 0, 0) == -1)
			perror("\nserver: msgrcv error!");
		else {
			printf("\nreceived %d %d", msg.tab[0], msg.tab[1]);
			msg.tab[0] += msg.tab[1];
			
			if (msgsnd(fres, (void*)&msg, sizeof(long), 0) == -1)
					perror("\nserver: message not sent");
			
		}
	}
	
}
