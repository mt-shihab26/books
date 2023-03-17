#include <stdio.h>
#include <string.h>

int main() {
    char saarc[7][100] = {"Bangladesh", "India", "Sri Lanka", "Pakistan", "Nepal" , "Bhutan", "Maldives"};
    int row, cal, len;

    for (row = 0; row < 7; row++) {
        len = strlen(saarc[row]);
        for (cal = 0; cal < len; cal++) {
            printf("%c ", saarc[row][cal]);
        }
        printf("\n");
    }

    return 0;
}