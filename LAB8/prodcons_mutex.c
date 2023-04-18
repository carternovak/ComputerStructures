#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int globalvar;
sem_t r_mutex, w_mutex;

void* writerT(void* arg){
	int n = *(int*) arg;
	//sem_wait(&w_mutex);
	for(int i = 0; i < n; i++){
		sem_wait(&w_mutex);
		int randnum = rand() % n;
		globalvar = randnum;
		printf("writer wrote: %d\n", randnum);
		sem_post(&r_mutex);
	}
	//sem_post(&r_mutex);
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
	sem_init(&r_mutex, 1, 0);
	sem_init(&w_mutex, 1, 1);

	pthread_t writer;
	pthread_create(&writer, NULL, writerT, &n);
	//pthread_join(writer, NULL);
	//sem_wait(&r_mutex);
	for(int i = 0; i < n; i++){
		sem_wait(&r_mutex);
		printf("main read: %d\n", globalvar);
		sem_post(&w_mutex);
	}
	//sem_post(&w_mutex);
	pthread_join(writer, NULL);
	return 0;
}
