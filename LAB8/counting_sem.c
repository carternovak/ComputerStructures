#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

sem_t semaphore;

void* func1(){
	sem_wait(&semaphore);
	printf("A\n");
	return NULL;
}

void* func2(){
	sem_wait(&semaphore);
	printf("B\n");
	return NULL;
}

void* func3(){
	sem_wait(&semaphore);
	printf("C\n");
	return NULL;
}

int main(int argc, char* argv[]){
	
	if(argc > 1){
		printf("Error: No input arguments necessary\n");
		exit(EXIT_FAILURE);
	}

	(void)argv[0];

	sem_init(&semaphore, 1, 2);

	pthread_t tid1, tid2, tid3;
	//int id1 = 0, id2 = 0, id3 = 0;

	pthread_create(&tid1, NULL, func1, NULL);
	pthread_create(&tid2, NULL, func2, NULL);
	pthread_create(&tid3, NULL, func3, NULL);
	sem_post(&semaphore); // FIX for code issue
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);

	return 0;
}
