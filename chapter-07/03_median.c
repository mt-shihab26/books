// মাথাপিছু আয়
#include <stdio.h>

int median(int taka[], int len) {
    if (len == 0) {
        return 0;
    }
    if (len % 2 == 1) {
        return taka[len / 2];
    }
    else{
        return (taka[len/2]+taka[(len/2)+1]) / 2;
    }
}

int main() {
    int taka[10] = {10000, 10000, 20000, 20000, 20000, 20000, 20000, 30000, 500000, 500000};
    printf("Median of taka %d\n", median(taka, 10));
}