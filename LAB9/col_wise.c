#include <stdio.h>
#include <time.h>
#define SZ 50000

float A[SZ][SZ];

int main(){

	double time_spent = 0.0;
	clock_t begin = clock();

        for(int i = 0; i < SZ; i++){
                for(int j = 0; j < SZ; j++){
                        A[i][j] = i * j;
                }
        }

        for(int j = 1; j < SZ; j++){
                for(int i = 0; i < SZ; i++){
                        A[i][j] = (A[i][j - 1] + A[i][j]) / 2;
                }
        }

	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time: %f micro seconds\n", time_spent * 1000000);

        return 0;
}

