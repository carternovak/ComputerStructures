#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define SIZE 30
int main(int argc, char* argv[]){

	if(argc != 3){
		printf("Error: Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}
	int fd1[2];
	//pipe(fd1);
	//int fd2[2];
	//pipe(fd2);
	if(pipe(fd1) < 0){
		printf("Pipe 1 Error");
		exit(EXIT_FAILURE);
	}/*
	else if(pipe(fd2) < 0){
		printf("Pipe 2 Error");
		exit(EXIT_FAILURE);
	}*/
	char temp[SIZE];
	//char temp2[strlen(argv[2])];
	int returnVal = fork();
	if(returnVal < 0){
		printf("Error");
		exit(EXIT_FAILURE);
	}else if(returnVal > 0){
		//write(fd1[1], argv[1], strlen(argv[1]));
		write(fd1[1], argv[2], SIZE);
		wait(NULL);
	}else if(returnVal == 0){
		read(fd1[0], temp, SIZE);
		
		char *ret;
		ret = strstr(argv[1], "/bin/");
		//printf("%s\n", ret);
		if(ret){
			if(execl(ret, ret, temp, NULL) != 0){
				printf("Error: Invalid command\n");
				exit(EXIT_FAILURE);
			}
			
			//execl(ret, ret, temp, NULL);
		}else{
			char bintemp[20] = "/bin/";
			char *arg1 = argv[1];
			strcat(bintemp, arg1);
			//printf("%s\n", bintemp);
			
			if(execl(bintemp, bintemp, temp, NULL) != 0){
				printf("Error: Invalid command\n");
				exit(EXIT_FAILURE);
			}
			
			//execl(bintemp, bintemp, temp, NULL);
		}
	}

	return 0;

}
