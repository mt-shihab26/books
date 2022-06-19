#include <stdio.h>

void error(char *err_num) {
    printf("%s\n", err_num);
}

int main() {
    char *p[] = {
        "Input exceeds field width",
        "Out of range",
        "Printer not turned on",
        "Paper out",
        "Disk full",
        "Disk writr error"
    };
    error(p[1]);

    return 0;
}