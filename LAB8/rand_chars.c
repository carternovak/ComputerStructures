#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lowerC(){
	for(int i = 0; i < 10; i++){
		char letter = 'a';
		int randnum = rand() % 26;
		letter += randnum;
		printf("%c\n", letter);
	}
	return 0;
}

int upperC(){
	for(int i = 0; i < 10; i++){
		//char letter = 'A';
		//int randnum = rand() % 26;
		//letter += randnum;
		char randletter = 'A' + (rand() % 26);
		printf("%c\n", randletter);
	}
	return 0;
}

int main(int argc, char* argv[]){

	if(argc != 2){
		printf("Error: Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}

	if(strcmp(argv[1], "-l") == 0)
		lowerC();
	else if(strcmp(argv[1], "-u") == 0)
		upperC();
	else{
		printf("Error: Input argument invalid\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}
