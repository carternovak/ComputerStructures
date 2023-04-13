#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#ifndef INCCNT
	#define INCCNT 10
#endif
#include <time.h>

void* print(void* arg);
void* increment(void* arg);

int main(int argc, char* argv[]){

	double time_spent = 0.0;
	clock_t begin = clock();

	if(argc != 3){
		printf("Error: Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}
	pthread_t tid1, tid2;
	char *id1 = argv[1];
	//char *ex = " Example";
	//strcat(id1, ex);
	int id2 = atoi(argv[2]);

	pthread_create(&tid1, NULL, print, id1);
	pthread_create(&tid2, NULL, increment, (void*)&id2);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	//printf("The elapsed time is %f seconds", time_spent);

	return 0;

}

void* print(void *arg){

	char *charp = arg;
	printf("Concat String: %s Example\n", charp);
	return NULL;
}

void* increment(void* arg){

	int* intp = (int*)arg;
	printf("Count: %d\n", *intp + INCCNT);
	return NULL;
}
