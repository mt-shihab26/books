#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >>n;

    long long int result;
    for (int i = 1; i <= n; i++) {
        result = i * (n - i + 1);
    }
    cout <<result <<"\n";

}