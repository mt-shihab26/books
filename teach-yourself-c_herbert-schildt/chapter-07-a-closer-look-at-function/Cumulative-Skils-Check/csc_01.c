#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Useage: a.out <password>\n");
        return 1;
    }

    if (strcmp("hello", argv[1]) == 0)
        printf("Access Permitted\n");
    else
        printf("Access Denied\n");

}