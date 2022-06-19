#include <stdio.h>
#include <string.h>

int main() {
    char word[80];
    int i, len, hap, j, value;

    scanf("%s", word);

    len = strlen(word);
    hap = len / 2;
    for (i = 0, j = len-1; i < hap; i++, j--) {
        if (word[i] == word[j]) {
            value = 0;
        }
        else {
            value = 1;
            break;
        }
    }
    if (value == 0) {
        printf("%s is Palindrome\n", word);
    }
    else {
        printf("%s is not Palindrome\n", word);
    }


    return 0;
}