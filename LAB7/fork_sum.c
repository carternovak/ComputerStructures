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
	//i = atoi(argv[1]);
	i = 0;
	int total = 0;
	int childsum = 0;
	int parentsum = 0;
	int fd[2];
	pipe(fd);
	char result[50];
	char sum[50];
	int returnVal = fork();
	if(returnVal == -1){
		printf("Error");
		exit(EXIT_FAILURE);
	}else if(returnVal == 0){
		wait(NULL);
		i = ASIZE / 2;
		while(i >= ASIZE / 2 && i < ASIZE){
			childsum += array[i];
			i++;
		}
		read(fd[0], sum, 50);
		total = atoi(sum);
		//printf("Test: %s\n", sum);
		printf("Total: %d\n", childsum + total);
	}else if(returnVal > 0){
		while(i < ASIZE / 2){
			parentsum += array[i];
			i++;
		}
		sprintf(result, "%d", parentsum);
		write(fd[1], result, 50);
		//wait(NULL);
		//printf("Parent sum: %d\n", parentsum);
	}
	//printf("Total: %d\n", total);
	return 0;
}
