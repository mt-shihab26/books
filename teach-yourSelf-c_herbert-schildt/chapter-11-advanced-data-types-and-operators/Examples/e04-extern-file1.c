#include <stdio.h>
#include "e04-extern-file2.h"

char str[80];

void getname(void);

int main(void) {
    getname();
    printf("Hello %s", str);

    return 0;
}