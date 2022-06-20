#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cout <<"Enter 3 numbers: ";
    int a, b, c;
    cin >>a >>b >>c;

    int max;
    if (a > b and a > c) {
        max = a;
    }
    else if (b > c) {
        max = b;
    }
    else {
        max = c;
    }
    cout <<max <<"\n";
}