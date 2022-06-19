#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ran(int low, int high)
{
    srand(time(0));
    return ((rand() % (high - low + 1)) + low);
}

enum transport
{
    car,
    train,
    ariplane,
    bus
};

int main()
{
    enum transport tp;

    printf("Press a key to select transport: ");

    // generate a new random number each time the program is run

    int num = ran(0, 3);

    printf("%d ", num);

    tp = num;

    getchar();

    switch (tp)
    {
    case car:
        printf("car");
        break;
    case train:
        printf("train");
        break;
    case ariplane:
        printf("airplane");
        break;
    case bus:
        printf("bus");
    }
    printf("\n");

    return 0;
}