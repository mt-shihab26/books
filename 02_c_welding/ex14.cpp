#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >>n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cout <<"Calculating ... " <<sum <<" + " <<i <<"^2" <<"\n";
        sum += (i*i);
    }
    cout <<"\nSum = " <<sum <<"\n";
}