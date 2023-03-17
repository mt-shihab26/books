#include <bits/stdc++.h>
using namespace std;

long long int factorial(int num) {
    long long facto = 1;
    for (int i = 1; i <= num; i++) {
        facto *= i;
    }
    return facto;
}

int main(void) {
    cout <<"Enter n and r: ";
    int n, r;
    cin >>n >>r;
    long long int nr;

    nr = factorial(n) / (factorial(r) * factorial(n-r));

    cout <<"n r = " <<nr <<"\n";
}