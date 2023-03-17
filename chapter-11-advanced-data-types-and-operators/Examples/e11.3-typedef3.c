#include <stdio.h>

int main(void)
{
    enum e_type
    {
        one,
        two,
        three
    };

    typedef enum e_type nums;
    nums x;

    x = two;

    printf("%d\n", x);
}