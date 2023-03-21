#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){

	if(argc != 3){
		printf("Error: Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}
	int fd1[2];
	pipe(fd1);
	int fd2[2];
	pipe(fd2);
	char temp[strlen(argv[1])];
	char temp2[strlen(argv[2])];
	int returnVal = fork();
	if(returnVal < 0){
		printf("Error");
	}else if(returnVal > 0){
		write(fd1[1], argv[1], strlen(argv[1]));
		//read(fd[0], temp, strlen(argv[1]));
		write(fd2[1], argv[2], strlen(argv[2]));
		//read(fd[0], temp2, strlen(argv[2]));
	}else if(returnVal == 0){
		read(fd1[0], temp, strlen(argv[1]));
		close(*fd1);
		read(fd2[0], temp2, strlen(argv[2]));
		close(*fd2);
	}

	execl("/bin/", temp, temp2, NULL);

	return 0;

}
