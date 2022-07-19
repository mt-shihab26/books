#include <stdio.h>

int main(void)
{
    enum planets
    {
        Mercury,
        Venus,
        Earth,
        Mars,
        Jupiter,
        Saturn,
        Neptune,
        Uranus,
        Pluto
    };

    enum planets x = Pluto;

    printf("%d\n", Pluto);
    printf("%d\n", x);

    return 0;
}