/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Points: 3
 */
int bitAnd(int x, int y) {
  return ~(~x | ~y);
}

/* 
 * getByte - Extract nth byte from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + - << >>
 *   Points: 6
 */
int getByte(int x, int n) {
  //return (x & (0xff << n * 8));
  //return (x >> (n * 8)) & 0xff;
  return 0xff & (x >> (n << 3));
}

/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + - << >>
 *  Points: 6
 */
int byteSwap(int x, int n, int m) {
    int first = getByte(x, n);
    int second = getByte(x, m);
    int mask_first = 0xff << (n << 3);
    int mask_second = 0xff << (m << 3);

    int mask = (mask_first | mask_second) ^ (-1);

    return (x & mask) | (first << (m << 3)) | (second << (n << 3));
}

/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + - << >>
 *   Points: 10
 */
int logicalShift(int x, int n) {
  //return (unsigned int)x >> n;
  int mask = 1 << (~n + 32);
  mask = mask | (mask + (~1) + 1);
  return (x >> n) & mask;
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + - << >>
 *   Points: 15
 */
int bitCount(int x) {
 // return (x >> 4) & 00001111;
 //int mask_1 = 0x55; //01010101;
 //x = (x & mask_1) + ((x >> 1) & mask_1);
 int four_mask = 1 | (1 << 8) | (1 << 16) | (1 << 24);
 int one_mask = 0xff;
 
 int y = (x & four_mask) + ((x >> 1) & four_mask) + ((x >> 2) & four_mask) + ((x >> 3) & four_mask) + ((x >> 4) & four_mask) + ((x >> 5) & four_mask) + ((x >> 6) & four_mask) + ((x >> 7) & four_mask);
 
 int result = (y & one_mask) + ((y >> 8) & one_mask) + ((y >> 16) & one_mask) + ((y >> 24) & one_mask);
 return result;
}

/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + - << >>
 *   Points: 15
 */
int bang(int x) {
  int not_x = ~x + 1;
  return ((not_x | x) >> 31) + 1;
}

/*
 * bitParity - returns 1 if x contains an odd number of 1's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + - << >>
 *   Points: 15
 */
int bitParity(int x) {
  int sixt_x = x ^ x >> 16;
  int eight_x = sixt_x ^ sixt_x >> 8;
  int four_x = eight_x ^ eight_x >> 4;
  int final_x = four_x & 0xf;
  return (0x6996 >> final_x) & 1;
}
