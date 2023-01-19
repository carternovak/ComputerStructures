#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){

	if(argc != 3) {
		printf("Error: Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}
	FILE *fp;
	char buffer[5000];
	int count = 0;
	size_t bufsize = 5000;

	fp = fopen(argv[1], "r");

	//buffer = (char *)malloc(bufsize * sizeof(char));
	while(fgets(buffer, bufsize, fp) != NULL){
		if(strstr(buffer, argv[2]) != NULL) {
			count++;
		}
	}
	
	printf("%d\n", count);
	//printf("%s", buffer);
	exit(EXIT_SUCCESS);
}
