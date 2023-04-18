#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int globalvar;

void* writerT(void* arg){
	int n = *(int*) arg;
	for(int i = 0; i < n; i++){
		int randnum = rand() % n;
		globalvar = randnum;
		printf("writer wrote: %d\n", randnum);
	}
	return NULL;
}

int main(int argc, char* argv[]){

	if(argc != 2){
		printf("Error: Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}

	int n = atoi(argv[1]);

	if(n <= 0){
		printf("Error: n must be greater than 0\n");
		exit(EXIT_FAILURE);
	}

	pthread_t writer;
	pthread_create(&writer, NULL, writerT, &n);
	//pthread_join(writer, NULL);
	for(int i = 0; i < n; i++)
		printf("main read: %d\n", globalvar);
	pthread_join(writer, NULL);
	return 0;
}
