#include <stdio.h>

int main()
{
    int i, j, grid[10][10], n, x, y;
    char c;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            grid[i][j] = 1;
        }
    }
    printf("Please enter the number of blocked cells: ");
    scanf("%d", &n);
    printf("Now enter the cells: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        grid[x][y] = 0;
    }

    printf("Please Enter the initial Position: ");
    scanf("%d %d", &x, &y);

    while (1)
    {
        scanf("%c", &c);
        if (grid[x][y] == 1)
        {
            if (c == 'U')
            {
                x = x - 1;
            }
            else if (c == 'D')
            {
                x = x + 1;
            }
            else if (c == 'L')
            {
                y = y - 1;
            }
            else if (c == 'R')
            {
                y = y + 1;
            }
        }
        else if (c == 'S')
        {
            break;
        }
    }
    printf("Final position of the robot is: %d, %d\n", x, y);

    return 0;
}