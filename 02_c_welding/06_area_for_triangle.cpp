#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
    cout << "Enter Triangle x, y, z: ";
    double x, y, z;
    cin >> x >> y >> z;

    double s = (x+y+z) / 2;
    double area = sqrt(s*(s-x)*(s-y)*(s-z));

    cout << area << endl;

    return 0;
}