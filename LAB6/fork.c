#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int globe;

int main(int argc, char* argv[]){

	if(argc != 2){
		printf("Error: Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}
	globe = atoi(argv[1]);

	int returnVal = fork();
	printf("Hello World\n");
	if(returnVal == -1){
		printf("Error");
		exit(EXIT_FAILURE);
	}else if(returnVal == 0){
		globe--;
		printf("Child: %d\n", globe);
	}else if(returnVal > 0){
		globe++;
		printf("Parent: %d\n", globe);
	}

	return 0;

}
