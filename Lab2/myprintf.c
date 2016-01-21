/**********************************************************
 * myprintf.c
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

#include <stdarg.h>
#include <stdio.h>

//void putchar(char c) {//I thought I should also define it but it is already in stdio.h
//    printf("%c",c);
//}

void printint(int i) {//if it is an integer printf %d
    printf("%d",i);
}

void printstring(char *c) {//if it is a string printf %s
    printf("%s",c);
}

void printhex(int i) {//if it is in hexadecimal printf %x
    printf("%x",i);
}

void myprintf(const char *fmt, ...) {//instructer's code here:
    const char *p;
    va_list argp;
    int i;
    char *s;
    
    va_start(argp, fmt);
    
    for (p = fmt; *p != '\0'; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'c':
                i = va_arg(argp, int);
                putchar(i);
                break;
                
            case 'd':
                i = va_arg(argp, int);
                printint(i);
                break;
                
            case 's':
                s = va_arg(argp, char *);
                printstring(s);
                break;
                
            case 'x':
                i = va_arg(argp, int);
                printhex(i);
                break;
                
            case '%':
                putchar('%');
                break;
        }
    }
    va_end(argp);
}
