#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>

int glob = 0;

void* routine1(void* p) {
	int i = *((int *)p);
	while (i--)
		glob++;
	printf("\nla valeur du variable globale apres la fin du thread 1 : %d", glob);
}
void* routine2(void* p) {
	int i = *((int *)p);
	while (i--)
		glob++;
	printf("\nla valeur du variable globale apres la fin du thread 2 : %d", glob);
}



int main() {
	int n = 1000000;
	pthread_t t1, t2;
	pthread_create(&t1, NULL, &routine1, (void*)&n);	
	pthread_create(&t2, NULL, &routine2, (void*)&n);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("\n");
	return 0;
}
