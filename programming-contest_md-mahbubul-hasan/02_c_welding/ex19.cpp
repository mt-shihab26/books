#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >>n;
    int temp_n = n;
    int sum = temp_n;
    cout <<temp_n <<" + ";
    temp_n--;
    for (int i = 2; temp_n >= 1; i++) {
        cout<<i * temp_n <<" + ";
        sum += i * temp_n;
        temp_n--;
    }

    cout <<"\nSum = " <<sum <<"\n";
}