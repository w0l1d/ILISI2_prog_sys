#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("Vous devez obligatoirment passe seulement le nom de la commande en argument");
		exit(1);
	}

	execvp(argv[1], argv+1);
	printf("Error : execv est echoue\n" );
/*	int i;
	for ( i =0; i < argc; ++i)
		printf("%s ", argv[i]);
	printf("\n");
*/
	return 1;
}
