#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]){
	
	if(argc != 2){
		printf("Error: Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}

	char *bin = argv[1];
	size_t length = strlen(argv[1]);

	if(length != 32){
		printf("Error: Binary number entered is not 32 bits\n");
		exit(EXIT_FAILURE);
	}

	for(int i = 0; i < 32; i++){
		if(bin[i] != '1' && bin[i] != '0'){
			printf("Incorrent input argument\n");
			exit(EXIT_FAILURE);
		}
	}

	int sign = 0;
	if(bin[0] == '1')
		sign = 1;
	int exp = 0;
	float man = 0.0;
	for(int i = 1; i < 9; i++){
		if(bin[i] == '1')
			exp += (int)pow(2, 7 - (i - 1));
	}

	for(int i = 9; i <= 32; i++){
		if(bin[i] == '1')
			man += 1/pow(2, i - 8);
	}
	float result;
	if(exp > 0 && exp < 255){
		man += 1;
		result = pow(-1, sign) * man * pow(2, exp - 127);
	}else
		result = pow(-1, sign) * man * pow(2, 1 - 127);

	printf("Sign: %d\n", sign);
	printf("Exponent: %d\n", exp);
	printf("Mantissa: %.17g\n", man);
	printf("Number: %.7g\n", result);

}
