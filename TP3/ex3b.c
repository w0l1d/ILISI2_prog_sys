#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>
#include <time.h>

int is_in_tab(int* tab, int length, int val) {
	pid_t p = fork();
	int s,i;
	if (p) {
		for (i = 0; i < length/2; ++i)
			if (tab[i] == val)
				return i;
		wait(&s); 
		char c = WEXITSTATUS(s);
		return c;
	}
	for (i = length/2; i < length; ++i)
		if (tab[i] == val)
			exit(i);
	exit(-1);
	
}


int main() {
	
	int arr[] = {1, 2 ,3 ,5, 6 ,8 ,9};
	printf("\nindice : %d\n", is_in_tab(arr, 7, 0));
	return 0;
}


