#include <stdio.h>
#include <math.h>

int main() {
    int t, temp, root;

    scanf("%d", &t);
    while (t--) {
        scanf(" %d", &temp);
        root = sqrt(temp);
        if ((root * root) == temp) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}