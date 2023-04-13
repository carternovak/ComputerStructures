#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#define NTHREADS 2
#include <time.h>

void* countWord(void* arg);

struct input_args{
	char* word;
	char* fileName;
};

typedef struct input_args IA;

int main(int argc, char* argv[]){

	double time_spent = 0.0;
	clock_t begin = clock();

	if(argc != 5){
		printf("Error: Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}

	pthread_t tid[NTHREADS];
	//char ids[NTHREADS];
	IA arg1;
	arg1.word = argv[2];
	arg1.fileName = argv[1];

	IA arg2;
	arg2.word = argv[4];
	arg2.fileName = argv[3];
	int i;
	for(i = 0; i < NTHREADS; i++){
		if(i == 0)
			pthread_create(&tid[i], NULL, countWord, (void*)&arg1);
		if(i == 1)
			pthread_create(&tid[i], NULL, countWord, (void*)&arg2);
		//pthread_create(&tid[i], NULL, countWord, ids[i]);
	}
	for(i = 0; i < NTHREADS; i++){
		pthread_join(tid[i], NULL);
	}

	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	//printf("Time for main thread: %f", time_spent);
	return 0;
}

void* countWord(void* arg){	
	double time_spent = 0.0;
	clock_t begin = clock();

	IA* args = (IA*)arg;	
	FILE *fp;
	char buffer[5000];
	int count = 0;
	size_t bufsize = 5000;
	
	fp = fopen(args->fileName, "r");
	char* pt;
	while(fgets(buffer, bufsize, fp) != NULL){
		//char* pt = strstr(buffer, args->word);
		pt = buffer;
		while((pt = strstr(pt, args->word)) != (char*)NULL) {
			//printf("%p\n", pt);
			pt++;
			count++;
		}
	}

	fclose(fp);
	printf("%s Count: %d\n", args->word, count);
	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	//printf("Elapsed time for thread: %f seconds", time_spent);
	return NULL;
}
