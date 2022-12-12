#include <iostream>
using namespace std;

int main(void) {
    cout << "Enter 3 number(a, b, c): ";
    int a, b, c;
    cin >> a >> b >> c;
    cout << "Big is ";
    if (a > b && a > c) {
        cout << a;
    }
    else if (b > a && b > c) {
        cout << b;
    }
    else {
        cout << c;
    }
    cout << endl;
}