#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cout <<"Enter n: ";
    int n;
    cin >>n;
    long long int facto = 1;
    for (int i = 1; i <= n; i++) {
        facto *= i;
    }
    cout <<"Factorial of N is: " <<facto <<"\n";
}