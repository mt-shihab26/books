#include <stdio.h>

int main()
{
    int num;

    // the loop will not execute
    for (num=11; num<11; num=num+1) printf("%d ", num);

    printf("terminating");

    return 0;
}