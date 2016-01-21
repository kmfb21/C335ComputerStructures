#include<stdio.h>

#include<time.h>
void wait ( int seconds )
{
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
}

int main(){
    wait(5);
    printf("Hello World!\n");
    return 0;
}