#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>



void* routine(void* p) {
	int i;
	for (i = 0; i < 26; ++i)
		printf("%c", p+i);
}


int main() {
	pthread_t t1, t2;
	pthread_create(&t1, NULL, &routine, (void*)'A');	
	pthread_create(&t2, NULL, &routine, (void*)'a');	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("\n");
	return 0;
}
