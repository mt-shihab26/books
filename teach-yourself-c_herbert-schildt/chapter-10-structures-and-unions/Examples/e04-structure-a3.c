#include <stdio.h>

struct s_type {
    int i;
    char ch;
    double d;
    char str[80];
} s;

int main(void)
{
    printf("Enter an integer: ");
    scanf("%d: ", &s.i);
    printf("Enter a character: ");
    scanf(" %c", &s.ch);
    printf("Enter a floating point number: ");
    scanf("%lf", &s.d);
    printf("Enter a string: ");
    // scanf("%s", s.str);
    getchar();
    gets(s.str);

    printf("%d %c %f %s\n", s.i, s.ch, s.d, s.str);

    return 0;
}