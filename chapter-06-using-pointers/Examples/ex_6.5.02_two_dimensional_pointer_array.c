#include <stdio.h>

char *p[][2] = {
    "Red Delicious", "Red",
    "Golden Delicious", "yellow",
    "Winesap", "Red",
    "Gala", "reddish orange",
    "Lodi", "green",
    "Mutsu", "Yellow",
    "Cortland", "red",
    "Jonathan", "red",
    "", ""
};

int main() {
    int i;
    char apple[80];

    printf("Enter name of apple: ");
    gets(apple);

    for (i = 0; *p[i][0]; i++) {
        if (!strcmp(apple, p[i][0])) {
            printf("%s is %s\n", apple, p[i][1]);
        }
    }

    return 0;
}