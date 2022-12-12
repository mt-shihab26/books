#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >>n;
    int sum = 0;
    cout <<"Calculating ... ";
    for (int i = 1; i <= n; i++) {
        if (i % 2) {
            cout <<" + ";
            sum += i;
        }
        else {
            cout <<" - ";
            sum -= i;
        }
        cout <<i;
    }

    cout <<"\nSum = "<<sum <<"\n";
    return 0;
}