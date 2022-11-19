#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>



void* routine1(void* f) {
	int i;
	for (i = 0; i <= 100000; ++i)
		fprintf(f, "%d ", i);
		
	fprintf(f, "\n");
}
void* routine2(void* f) {
	int i;
	printf("\n");
	for (i = 1000000; i <= 1100000; ++i)
		fprintf(f, "%d ", i);
		
	fprintf(f, "\n");
}


int main() {
	FILE *f = fopen("file_ex4b", "w");

	pthread_t t1, t2;
	pthread_create(&t1, NULL, &routine1, (void*)f);	
	pthread_create(&t2, NULL, &routine2, (void*)f);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

		
	printf("\n");
	fclose(f);
	return 0;
}
