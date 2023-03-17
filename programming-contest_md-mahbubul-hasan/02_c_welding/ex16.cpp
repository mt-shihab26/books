#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >>n;
    int sum = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        cout <<"Calculating ... ";
        for (int k = 1; k <= i; k++) {
            cout <<" + " <<j;
            sum += j;
            j++;
        }
        cout<<"\n";
    }
    cout <<"\nSum = " <<sum <<"\n";
}