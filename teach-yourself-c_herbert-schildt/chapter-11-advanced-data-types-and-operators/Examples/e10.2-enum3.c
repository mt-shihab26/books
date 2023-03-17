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
    airplane,
    bus
};

char trans[][20] = {"car", "train", "airplane", "bus"};

int main(void)
{
    enum transport tp;

    printf("Press a key to select transport: ");

    // generate a new random number each time the program is run

    int num = ran(0, 3);
    tp = num;

    getchar();

    printf("%s\n", trans[tp]);

    return 0;
}