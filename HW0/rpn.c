/**********************************************************
 * rpn.c
 *
 * This is an RPN calculator like dc command in UNIX
 *
 *   Author: Bo Fang (bofang)
 *   Date Created: 01/23/2016
 *   Last Modified by: Bo Fang (bofang)
 *   Date Last Modified: 01/23/2016
 *   Assignment: HW0
 *   Part of: CSCI-C335 submissions
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct CELL* LIST;//typedef our CELL*

struct CELL {//A list as our stack
    int val;
    LIST next;
};

LIST stack;//glabal variable

void push(int val) {//push a value to stack
    LIST c = (LIST) malloc(sizeof(struct CELL));//create a cell in memory
    if (c) {
        c->val = val;//first save value to cell
        c->next = stack;//link it to stack
        stack = c;//change the begin point of stack
    } else {
        perror("Memory error\n");
        exit(1);//error exit
    }
}

int pop() {
    LIST c = stack;
    if (c) {
        stack = stack->next;//pop a stack
        int val = c->val;
        free(c);
        return val;//return the poped value
    } else {
        perror("Nothing in stack!\n");
        exit(1);
    }
}

int main()
{
    stack = NULL;
    LIST tmp;
    char command[255];//a string to save input
    int i,i1,i2;
    while (*command != EOF && *command != 'q') {//if EOF or q, quit
        scanf("%s",command);
        i = atoi(command);//if command is not a number, i will be 0
        if (strcmp(command, "0")==0 || i != 0) push(atoi(command));//if i is number, push to stack
        else {
            switch (*command) {//otherwise match the command
                case 'p':
                    if (stack) printf("%d\n",stack->val);//print first value of stack
                    else printf("dc: stack empty\n");
                    break;
                case 'f':
                    tmp = stack;
                    while (tmp) {//using iteration to print all values in stack
                        printf("%d\n",tmp->val);
                        tmp = tmp->next;
                    }
                    break;
                case 'c':
                    while (stack) {//pop one value from stack
                        pop();
                    }
                    break;
                case '+':
                    if (stack && stack->next) {//if there are at least two values in stack
                        i2 = pop();
                        i1 = pop();
                        push(i1 + i2);//pop the two values and push the calculation result to stack
                    } else printf("dc: stack empty\n");
                    break;
                case '-':
                    if (stack && stack->next) {//same as +
                        i2 = pop();
                        i1 = pop();
                        push(i1 - i2);
                    } else printf("dc: stack empty\n");
                    break;
                case '*':
                    if (stack && stack->next) {
                        i2 = pop();
                        i1 = pop();
                        push(i1 * i2);
                    } else printf("dc: stack empty\n");
                    break;
                case '/':
                    if (stack && stack->next) {
                        i2 = pop();
                        i1 = pop();
                        push(i1 / i2);
                    } else printf("dc: stack empty\n");
                    break;
                case 'q':
                    break;
                default://undefined command
                    printf("dc: '%c' unimplemented\n",*command);
                    break;
            }
        }
    }
    return 0;
}