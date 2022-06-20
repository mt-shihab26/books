#include <iostream>
using namespace std;

int main(void) {
    int a, b;
    cout << "Enter two number a, b: ";
    cin >> a >> b;

    if (a > b) {
        cout << "Big is " << a;
    }
    else {
        cout << "Big is " << b;
    }
    cout << endl;

    return 0;
}