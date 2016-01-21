/**********************************************************
 * mywc.c
 * 
 * This mywc reads characters from std input and 
 * figure out how many words, characters and lines in it
 *
 *   Author: Bo Fang (bofang)
 *   Date Created: 01/21/2016
 *   Last Modified by: Bo Fang (bofang)
 *   Date Last Modified: 01/21/2016
 *   Assignment: Lab2
 *   Part of: CSCI-C335 submissions
 */

#include <stdio.h>

int main() {
    
    int lines = 0;//set initial count variables
    int words = 0;
    int characters = 0;
    
    int c; /* current character */
    while ((c = getchar()) != EOF) {//if we have not read to end yet
        characters++;//one more character
        if (c=='\n') {
            lines++;//if there is a new line \n, word+1 and line+1
            words++;
        }
        if (c==' ' || c=='\t' || c=='\r' || c=='\f' || c=='\v') {
            words++;//if anything else to stop a word, word+1
        }
    }
    printf("%d  %d %d\n", lines, words, characters);//output
    
    return 0;
}
