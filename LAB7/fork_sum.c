#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifndef ASIZE
	#define ASIZE 10
#endif
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char* argv[]){

	if(argc != 2){
		printf("Error: Incorrect number of arguments");
		exit(EXIT_FAILURE);
	}

	int array[ASIZE];
	int i;
	for(i = 0; i < ASIZE; i++) {
		array[i] = i*atoi(argv[1]);
		//printf("%d\n", array[i]);
	}
	int fd[2];
	pipe(fd);
	pid_t returnVal = fork();
	char result[50];
	if(returnVal == -1){
		printf("Error");
		exit(EXIT_FAILURE);
	}else if(returnVal == 0){
		int childsum = 0;
		for(int i = ASIZE/2; i < ASIZE; i++)
			childsum += array[i];

		sprintf(result, "%d", childsum);
		write(fd[1], result, 50);
		//printf("Child sum: %d\n", childsum);
		exit(childsum);
	}else if(returnVal > 0){
		char childPipe[50];
		read(fd[0], childPipe, 50);
		int pipeNum = atoi(childPipe);
		int parentsum = 0;
		for(int i = 0; i < ASIZE/2; i++){
			parentsum += array[i];
		}
		//printf("Parent sum: %d\n", parentsum);
		wait(NULL);
		printf("%d\n", parentsum + pipeNum);
		return 0;
	}
}
