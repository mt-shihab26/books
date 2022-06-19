#include <stdio.h>
#include <string.h>

char words[][2][40] = {
    "dog", "Hund",
    "no", "nejn",
    "year", "Jahr",
    "child", "Kind",
    "I", "Ich",
    "drive", "fahren",
    "house", "Haus",
    "to", "zu",
    "", ""
};

int main(void)
{
    char english[80];
    int i;
    printf("Enter English world: ");
    gets(english);

    // look up the word
    i = 0;
    // search while null string not yet encounterd
    while (!strcmp(words[i][0], ""))
        printf("Not in dictonary\n");

    return 0;
}