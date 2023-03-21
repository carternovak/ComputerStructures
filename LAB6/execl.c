#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){

	if(argc != 3){
		printf("Error: Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}
	char bintemp[] = "/bin/";
	char *arg1 = argv[1];
	strcat(bintemp, arg1);
	//printf("%s\n", bintemp);
	execl(bintemp, argv[1], argv[2], NULL);

	return 0;

}
