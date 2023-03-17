#include <stdio.h>
#include <string.h>

int main()
{
    int t, length, i; 
    char n[102];

    scanf("%d", &t);
    for (i = 0; i < t; i += 1) {
        scanf("%s", n);
        length = strlen(n);
        if ((n[length-1] - '0') % 2 == 0) {
            printf("even\n");
        }
        else {
            printf("odd\n");
        }
    }

    return 0;
}