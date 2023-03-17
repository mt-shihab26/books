#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;

    fp = fopen("myfile", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1); // or substitute your own error handler
    }

    
    return 0;
}
// Date: শুক্রবার, মার্চ 05, 2021 | 11:45:47
