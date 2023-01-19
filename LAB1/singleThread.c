#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]){

	double total_time = 0.0;
	clock_t begin = clock();
	if(argc != 5) {
		printf("Error: Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}
	FILE *fp;
	char *word;
	char buffer[10000];
	int count = 0;
	size_t bufsize = 10000;

	fp = fopen(argv[1], "r");

	//buffer = (char *)malloc(bufsize * sizeof(char));
	while(fgets(buffer, bufsize, fp) != NULL){
		word = buffer;
		while((word = strstr(word, argv[2])) != NULL) {
			count++;
			word++;
		}
	}
	fclose(fp);
	printf("%s Count: %d\n", argv[2], count);
	
	FILE *fp2;
	char buffer2[10000];
	count = 0;
	
	fp2 = fopen(argv[3], "r");
	while(fgets(buffer2, bufsize, fp2) != NULL){
		word = buffer2;
		while((word = strstr(word, argv[4])) != NULL) {
			count++;
			word++;
		}
	}
	fclose(fp2);
	printf("%s Count: %d\n", argv[4], count);
	clock_t end = clock();
	total_time += (double)(end - begin) / CLOCKS_PER_SEC * 1000;
	
	FILE * fp3;
	fp3 = fopen("README.md", "w");
	fprintf(fp3, "%.0fms\n", total_time);
	exit(EXIT_SUCCESS);

}

