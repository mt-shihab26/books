#include <stdio.h>

int main(void)
{
    int i, j;
    char op;

    printf("Enter operation: ");
    scanf("%d %c %d", &i, &op, &j);

    switch(op) {
        case '+':
            printf("%d\n", i+j);
            break;
        case '-':
            printf("%d\n", i-j);
            break;
        case '*':
            printf("%d\n", i*j);
            break;
        case '/':
            if (j)
                printf("%d\n", i/j);
            break;
    }


    

    return 0;
}