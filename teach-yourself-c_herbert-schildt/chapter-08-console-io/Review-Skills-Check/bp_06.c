#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("%d ", argc);
    printf("%s\n", argv[argc-1]);
}