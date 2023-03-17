#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
    int x1, x2, y1, y2;
    cout << "Enter first coordinate x1, y1: ";
    cin >> x1 >> y1;
    cout << "Enter second coordiante x2, y2: ";
    cin >> x2 >> y2;

    double distance = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));

    cout << "Distance is " << distance << endl;

    return 0;
}