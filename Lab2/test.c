/**********************************************************
 * test.c
 *
 * This is a test program which test the myprintf.c
 * It only has some myprintf()
 *
 *   Author: Bo Fang (bofang)
 *   Date Created: 01/21/2016
 *   Last Modified by: Bo Fang (bofang)
 *   Date Last Modified: 01/21/2016
 *   Assignment: Lab2
 *   Part of: CSCI-C335 submissions
 */

#include <stdio.h>

extern void myprintf(const char *, ...);

int main()
{
    myprintf("Nothing much\n");//tests there:
    myprintf("The letter %c\n", 'A');
    myprintf("A string: %s\n", "Splash!");
    myprintf("The number %d\n", 11);
    myprintf("The number %x in hexadecimal\n", 11);
    myprintf("%d is a negative number\n", -5);
    myprintf("The number %d\n", 'A');
    myprintf("The number %x in hexadecimal\n", 'A');
    
    return 0;
}