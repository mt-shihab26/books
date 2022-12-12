#include <bits/stdc++.h>
using namespace std;

double area(int x1, int y1, int x2, int y2, int x3, int y3) {
    // a(x1, y1), b(x2, y2), c(x3, y3)
    double ab = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    double bc = sqrt(pow(x3-x2, 2) + pow(y3-y2, 2));
    double ca = sqrt(pow(x1-x3, 2) + pow(y1-y3, 2));

    double s = (ab+bc+ca) / 2;

    double ara = sqrt(s*(s-ab)*(s-bc)*(s-ca));
    return ara;
}

int main(void) {
    int x1, y1, x2, y2, x3, y3;

    cout <<"Enter (x1, y1): ";
    cin >>x1 >>y1;
    cout <<"Enter (x2, y2): ";
    cin >>x2 >>y2;
    cout <<"Enter (x3, y3): ";
    cin >>x3 >>x3;

    cout <<area(x1, y1, x2, y2, x3, y3);

}