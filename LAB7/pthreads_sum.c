#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

#ifndef NTHREADS
	#define NTHREADS 2
#endif

#ifndef ASIZE
	#define ASIZE 10
#endif

int array[ASIZE];

void* calcSum(void* arg){
	int* intp = (int*) arg;
	int sum = 0;
	for(int i = *intp; i < *intp + ASIZE/NTHREADS; i++){
		sum += array[i];
	}

	int *result = malloc(sizeof(int));
	*result = sum;
	return result;
}

int main(int argc, char* argv[]){

	if(argc != 2){
		printf("Error: Incorrect number of arguments");
		exit(EXIT_FAILURE);
	}

	pthread_t tid[NTHREADS];
	int ids[NTHREADS];
	int i;
	for(i = 0; i < ASIZE; i++){
		array[i] = i*atoi(argv[1]);
	}

	for(i = 0; i < NTHREADS; i++){
		ids[i] = i * ASIZE/NTHREADS;
		pthread_create(&tid[i], NULL, calcSum, (void*)&ids[i]);
	}

	int total = 0;
	for(i = 0; i < NTHREADS; i++){
		int *result;
		pthread_join(tid[i], (void**)&result);
		total += *result;
	}

	printf("%d\n", total);
	return 0;
}
