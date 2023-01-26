#include "bitops.h"
#include <stdio.h>

/*
 * Return and of x and y
 * Points: 3
 */
int and_op(int x, int y) {
  return (x & y);
}

/* 
 * Return or of x and y
 * Points: 3
 */
int or_op(int x, int y) {
  return (x | y);
}

/*
 * Return xor of x and y
 * Points: 3
 */
int xor_op(int x, int y) {
  return (x ^ y);
}


/*
 * Clear `b`th byte of x
 * Points: 7
 */
int masking_and(int x, int b) {
  	//unsigned int mask = 0xff;
	//return (x & ~(mask >> b * 8));
	return (x & ~(0xff << b * 8));
}

/*
 * Set `b`th byte of x
 * Points: 7
 */
int masking_or(int x, int b) {
  return (x | (0xff << b * 8));
}

/*
 * Toggle `b`th byte of x
 * Points: 7
 */
int masking_xor(int x, int b) {
  return (x ^ (0xff << b * 8));
}

/*
 * Shift x to the left by `sc` # of bits
 * Points: 3
 */
int shifting_left_op(int x, int sc) {
  return x << sc;
}

/*
 * Shift x to the right by `sc` # of bits
 * Points: 3
 */
int shifting_right_op(int x, int sc) {
  return x >> sc;
}


/*
 * Return logical not of x
 * Points: 3
 */
int bang(int x) {
  return !x;
}

/*
 * Print binary string representation for x
 * Points: 30
 */
void bit_conversion(int x) {
	char * bin[8];
	int i = 0;
	while(x > 0) {
		if(x % 2 == 1)
			bin[i] = "1";
		else
			bin[i] = "0";
		x /= 2;
		i++;
	}
	for(int a = i - 1; a >= 0; a--)
		printf("%s", bin[a]);
	printf("\n");
}
