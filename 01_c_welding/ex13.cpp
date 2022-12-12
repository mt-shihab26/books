#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >>n;
    long long int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
        cout <<"Calculating ... " <<sum <<" + " <<i <<"\n";
    }
    cout <<"\nSum = " <<sum <<"\n";
    return 0;
}