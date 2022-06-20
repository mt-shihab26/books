#include <bits/stdc++.h>
using namespace std;

int main(void) {
    long long int n;
    cin >>n;
    long long int sum = 0;
    for (int i = 1; i <= n; i++) {
        cout <<"Calculating ... " <<sum <<" + " <<i <<"^" <<i <<"\n";
        sum += (pow(i, i));
    }
    cout <<"\nSum = " <<sum <<"\n";
    return 0;
}
