#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){

	if(argc != 2){
		printf("Error: Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}

	int fd[2];
	pipe(fd);
	if(pipe(fd) < 0){
		printf("Error");
		exit(EXIT_FAILURE);
	}
	int size = strlen(argv[1]);
	char result[size];
	int returnVal = fork();
	if(returnVal == -1){
		printf("Error");
		exit(EXIT_FAILURE);
	}else if(returnVal > 0){
		write(fd[1], argv[1], size); 
	}else if(returnVal == 0){
		read(fd[0], result, size);
		printf("%s\n", result);
	}

	close(*fd);
	return 0;

}
