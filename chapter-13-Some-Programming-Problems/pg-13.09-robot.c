#include <stdio.h>

int main() {
    int x, y;
    char c;
    printf("Please Enter the initial Position: ");
    scanf("%d %d", &x, &y);

    while (1) {
        scanf("%c", &c);
        if (c == 'U') {
            x = x - 1;
        }
        else if (c == 'D') {
            x = x + 1;
        }
        else if (c == 'L') {
            y = y - 1;
        }
        else if (c == 'R') {
            y = y + 1;
        }
        else if (c == 'S') {
            break;
        }
    }
    printf("Final position of the robot is: %d, %d\n", x, y);

    return 0;
}