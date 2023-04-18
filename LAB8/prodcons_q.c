#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define SIZE 5

char globalArr[SIZE + 1];
sem_t sema1, sema2, mutex;
int a = 0, b = 0;

void* func1(void* arg){
	int* idp = (int*)arg;
	for(int i = 0; i < SIZE; i++){
		char randLetter = 'a' + (rand() % 26);

		sem_wait(&sema1);
		sem_wait(&mutex);

		globalArr[a] = randLetter;
		printf("writer ID: %d, char written: %c\n", *idp, randLetter);
		a = (a + 1) % SIZE;

		sem_post(&mutex);
		sem_post(&sema2);
	}
	return NULL;
}

void* func2(void* arg){
	int* idp = (int*)arg;
	for(int i = 0; i < SIZE; i++){
		char randLetter = 'A' + (rand() % 26);

		sem_wait(&sema1);
		sem_wait(&mutex);

		globalArr[b] = randLetter;
		printf("writer ID: %d, char written: %c\n", *idp, randLetter);
		a = (a + 1) % SIZE;

		sem_post(&mutex);
		sem_post(&sema2);
	}
	return NULL;
}

void* func3(void* arg){
	int* idp = (int*)arg;
	char c;
	for(int i = 0; i < SIZE; i++){
		sem_wait(&sema2);
		sem_wait(&mutex);

		c = globalArr[b];
		printf("reader ID: %d, char read: %c\n", *idp, c);
		b = (b + 1) % SIZE;

		sem_post(&mutex);
		sem_post(&sema1);
	}
	return NULL;
}

int main(int argc, char* argv[]){
	if(argc > 1){
		printf("Error: No input arguments necessary\n");
		exit(EXIT_FAILURE);
	}
	(void)argv[0];

	sem_init(&sema1, 1, SIZE);
	sem_init(&sema2, 1, 0);
	sem_init(&mutex, 1, 1);

	pthread_t threads[8];
	int ids[8] = {0, 1, 2, 3, 0, 1, 2, 3};

	for(int i = 0; i < 8; i++){
		if(i < 2)
			pthread_create(&threads[i], NULL, func1, &ids[i]);
		if(i >= 2 && i < 4)
			pthread_create(&threads[i], NULL, func2, &ids[i]);
		if(i >= 4 && i < 8)
			pthread_create(&threads[i], NULL, func3, &ids[i]);
	}

	for(int i = 0; i < 8; i++)
		pthread_join(threads[i], NULL);

	return 0;
}
