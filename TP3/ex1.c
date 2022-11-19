#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int i,n,m = 1;
	pid_t tmp;
	n=50;
	again:;
	tmp=fork();
	
	if (!tmp) {
		for (i = n-50; i < n; i++)
			printf("%d ",i+1);
		return 0;
	}
	waitpid(tmp, NULL, 0);
	n+=50;
	if (tmp && n <= 100)
		goto again;
	
	return 0;
}


