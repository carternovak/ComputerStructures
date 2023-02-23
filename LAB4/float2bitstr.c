#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
	
	if(argc > 2){
		printf("Too many arguments\n");
		exit(EXIT_FAILURE);
	}else if(argc < 2){
		printf("No input given\n");
		exit(EXIT_FAILURE);
	}
	double number = atof(argv[1]);
	//sign
	if(number < 0){
		printf("1");
		number *= -1;
	}else{
		printf("0");
	}
	int n = (int)number;
	double frac = number - n;
	//printf("%.2f\n", frac);
	int size = sizeof(n) * 2;
	//printf("%d\n", n);
	char *bin = malloc(1 + size);
	bin[size] = '\0';
	int index = size - 1;

	while(index >= 0){
		if(n & 1)
			*(bin + index) = '1';
		else
			*(bin + index) = '0';
		n >>= 1;
		index--;
	}
	//printf("%s\n", bin);
	size = sizeof(n) * 8;
	char *fracbin = malloc(1 + size);
	fracbin[size] = '\0';
	index = 0;
	while(index < size){
		frac *= 2.0;
		if(frac > 1){
			*(fracbin + index) = '1';
			frac -= 1.0;
		}else{
			*(fracbin + index) = '0';
		}
		index++;
	}
	//printf("%s\n", fracbin);
	int a = 0;
	int indexp = 0;
	int b = 0;
	while(indexp != 1){
		if(a > 7){
			if(fracbin[b] == '1')
				indexp = 1;
			else{
				a++;
				b++;
			}
		}else{
			if(bin[a] == '1')
				indexp = 1;
			else
				a++;
		}
	}
	int E = 7 - a;
	int exp = E + 127;
	//printf("A: %d, E: %d, Exp: %d\n", a, E, exp);
	size = sizeof(exp) * 2;
	char *expbin = malloc(1 + size);
	expbin[size] = '\0';
	index = size - 1;

	while(index >= 0){
		if(exp & 1)
			*(expbin + index) = '1';
		else
			*(expbin + index) = '0';
		exp >>= 1;
		index--;
	}
	//exp
	printf("%s", expbin);
	//Mantissa
	a++;
	for(int i = 0; i < 23; i++){
		if(a < 8)
			printf("%c", bin[a]);
		else
			printf("%c", fracbin[a - 8]);
		a++;
	}
	printf("\n");
}


