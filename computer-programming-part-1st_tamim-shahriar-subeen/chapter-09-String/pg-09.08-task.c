#include <stdio.h>

int main() {
    char str[1002];
    int i;
    
    gets(str);
    // int len = strlen(str);
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = 'A' + (str[0] - 'a');
    }
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            printf("\n");
            if (str[i+1] >= 'a' && str[i+1] <= 'z') {
                str[i+1] = 'A' + (str[i+1] - 'a');
            }
            i++;
        }
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}