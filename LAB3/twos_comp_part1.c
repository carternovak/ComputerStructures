#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	if(argc > 2){
		printf("Error: Incorrect number of arguments");
		exit(EXIT_FAILURE);
	}

	int decimal = atoi(argv[1]);
	int ref = atoi(argv[1]);
	
	if((decimal > 127) || (decimal < -128)){
		printf("Error: Input value is outside the 8-bit range");
		exit(EXIT_FAILURE);
	}

	decimal = abs(decimal); // Assuring Positive value;
	int bitrep[8];
	int i = 7;
	while((decimal > 0) || (i >= 0)){
		bitrep[i--] = decimal % 2;
	       	decimal /= 2;	
	}
	int carry = 1;
	if(ref < 0){
		for(int i = 0; i < 8; i++){
			if(bitrep[i] == 1)
				bitrep[i] = 0;
			else if(bitrep[i] == 0)
				bitrep[i] = 1;
		}
		for(int j = 7; j >= 0; j--){
			if(bitrep[j] == 1 && carry == 1)
				bitrep[j] = 0;
			else if(bitrep[j] == 0 && carry == 1){
				bitrep[j] = 1;
				carry = 0;
			}
		}
	}

	for(int i = 0; i < 8; i++)
		printf("%d", bitrep[i]);

	printf("\n");
	exit(EXIT_SUCCESS);
}
