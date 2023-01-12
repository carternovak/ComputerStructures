#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]){

	if (argc > 3) {
		printf("Error: Too many arguments\n");
		exit(EXIT_FAILURE);
	}

	if (strcmp(argv[1], "printf") == 0) {
		printf("You entered: %s\n", argv[2]);

	}else if(strcmp(argv[1], "fprintf") == 0){
		FILE * fp;
		fp = fopen("print.txt", "w");
		fputs(argv[2], fp);
		fclose(fp);
	}else if(strcmp(argv[1], "scanf") == 0){
		char sc;
		printf("Please enter your input: ");
		scanf("%s", &sc);
		printf("You entered: %s\n", &sc);
	}else{
		printf("Error: Incorrect function option\n");
		exit(EXIT_FAILURE);
	}
	
	exit(EXIT_SUCCESS);
}

