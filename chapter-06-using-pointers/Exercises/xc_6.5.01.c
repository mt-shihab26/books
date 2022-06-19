#include <stdio.h>
#include <string.h>

int main() {
    char *p[3] = {
        "Yes", "No",
        "Maybe - repharase the question"
    };

    char str[80];

    printf("Enter your question: \n");
    gets(str);

    printf("%s", p[strlen(str) % 3]);

    return 0;
}