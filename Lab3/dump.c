/**********************************************************
 * dump.c
 *
 * This dump memory prints out the memory address
 * in different formal
 *
 *   Author: Bo Fang (bofang)
 *           Omar White (omawhite)
 *   Date Created: 01/28/2016
 *   Last Modified by: Bo Fang (bofang)
 *   Date Last Modified: 01/28/2016
 *   Assignment: Lab3
 *   Part of: CSCI-C335 submissions
 */

void dump_memory(void *p, int len)
{
  int i;
  int tmp;
  printf("address         char hexCh short  integer     float          doubleFloat\n");
  for (i = 0; i < len; i++) {
    printf("%8p: ", p + i);//address
    tmp = *(unsigned char *)(p + i);
    if (tmp >= 33 && tmp <= 126) {
      printf("%c    ", tmp);//character
    } else {
      printf("?    ");//if it cannot be shown
    }
    
    printf("0x%02x  ", *(unsigned char *)(p + i));//hex
    if (i % 2 == 0) {
      printf("%+d ", *(short int *)(p + i));//short
      if (i % 4 == 0) {
        printf("%+d ", *(unsigned int *)(p + i));//integer
        printf("%+e ", *(double *)(p + i));//float
        if (i % 8 == 0) {
          printf("%+e", *(float *)(p + i));//double float
        }
      }
    }
    printf("\n");
  }
}
