#include <stdio.h>

int main(void)
{
    char ch;

    switch (ch) {
    case 'L': load();
        break;
    case 'S': save();
        break;
    case 'E': enter();
        break;
    case 'D': display();
        break;
    case 'Q': quit();
        break;
    }

    return 0;
}