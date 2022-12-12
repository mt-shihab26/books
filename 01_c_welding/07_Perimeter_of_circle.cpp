#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
    cout << "Enter the Radius of circle: ";
    double radius;
    cin >> radius;
    double pi = acos(-1.0);
    double perimeter = 2*pi*radius;
    cout << perimeter << endl;
    return 0;
}
