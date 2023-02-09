#include <iostream>
using namespace std;

int main(void) {
    int a, b, c, tmp;
    cout << "Enter there number(a, b, c): ";
    cin >> a >> b >> c;

    if (a > b) {
        tmp = a;
        a = b;
        b = tmp;
    }
    if (a > c) {
        tmp = a;
        a = c;
        c = tmp;
    }
    if (b > c) {
        tmp = b;
        b = c;
        c = tmp;
    }

    printf("%d %d %d\n", a, b, c);
    
    return 0;
}