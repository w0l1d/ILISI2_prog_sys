#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Vous devez obligatoirment passe le nom du fichier seulement en argument");
		exit(1);
	}
	char s[100];
	sprintf(s, "cat %s", argv[1]);
	system(s);
	return 0;
}


