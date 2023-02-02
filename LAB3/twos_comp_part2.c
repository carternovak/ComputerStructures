#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]){

	if(argc != 3){
		printf("Error: Incorrect number of arguments");
	       	exit(EXIT_FAILURE);	
	}

	char *bin = argv[1];
	int result = 0;
	if(strcmp(argv[2], "signed") == 0){
		for(int i = 0; i < 8; i++)
			if(i == 0 && bin[i] == '1')
				result -= (int)pow(2, 7 - i);
			else if(i > 0 && bin[i] == '1')
				result += (int)pow(2, 7 - i);
	}else
		for(int i = 0; i < 8; i++)
			if(bin[i] == '1')
				result += (int)pow(2, 7 - i);;

	printf("%d\n", result);
	exit(EXIT_SUCCESS);
}
