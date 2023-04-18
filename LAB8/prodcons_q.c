#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define SIZE 5

char globalArr[SIZE];
sem_t sema1, sema2, mutex;

void* func1(void* arg){
	int* idp = (int*)arg;
	for(int i = 0; i < 5; i++){
		char randLetter = 'a' + (rand() % 26);

		sem_wait(&sema1);

		globalArr[i] = randLetter;
		printf("writer ID: %d, char written: %c\n", *idp, randLetter);
		
		sem_post(&mutex);
		sem_post(&sema2);
	}
	return NULL;
}

void* func2(void* arg){
	int* idp = (int*)arg;
	for(int i = 0; i < 5; i++){
		char randLetter = 'A' + (rand() % 26);

		sem_wait(&sema1);

		globalArr[i] = randLetter;
		printf("writer ID: %d, char written: %c\n", *idp, randLetter);
		
		sem_post(&mutex);
		sem_post(&sema2);
	}
	return NULL;
}

void* func3(void* arg){
	int* idp = (int*)arg;
	char c;
	for(int i = 0; i < 5; i++){
		//sem_wait(&sema2);
		sem_wait(&mutex);
		c = globalArr[i];
		printf("reader ID: %d, char read: %c\n", *idp, c);
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
	sem_init(&mutex, 1, 0);

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

	/*
	pthread_t lower1, lower2, upper1, upper2;
	pthread_t buffer[4];
	int lowerId1 = 0, lowerId2 = 1, upperId1 = 2, upperId2 = 3;
	int buffId[4];

	// lowercase function
	pthread_create(&lower1, NULL, func1, (void*)&lowerId1);
	pthread_create(&lower2, NULL, func1, (void*)&lowerId2);

	// uppercase function
	pthread_create(&upper1, NULL, func2, (void*)&upperId1);
	pthread_create(&upper2, NULL, func2, (void*)&upperId2);

	// buffer function
	for(int i = 0; i < 4; i++){
		buffId[i] = i;
		pthread_create(&buffer[i], NULL, func3, (void*)&buffId[i]);
	}

	pthread_join(lower1, NULL);
	pthread_join(lower2, NULL);
	pthread_join(upper1, NULL);
	pthread_join(upper2, NULL);

	for(int i = 0; i < 4; i++)
		pthread_join(buffer[i], NULL);
	*/
	return 0;
}
