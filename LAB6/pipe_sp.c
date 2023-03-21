#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){

	if(argc != 3){
		printf("Error: Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}

	int fd[2];
	pipe(fd);
	char result[50];
	write(fd[1], argv[1], 50);
	read(fd[0], result, 50);
	printf("%s\n", result);

	write(fd[1], argv[2], 50);
	read(fd[0], result, 50);
	printf("%s\n", result);

	close(*fd);
	return 0;

}
