#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >>n;
    int sum = 0;
    for (int i = 1, k = 1; i <= n; i++) {
        cout <<"(" <<k;
        if (k != 1) {
            cout <<" + ";
        }
        sum += k;
        k++;
        for (int j = 1; j < i; j++) {
            int temp = 1;
            for (int l = 1; l <= j+1; l++) {
                cout <<k;
                if (l != j+1) {
                    cout <<" * ";
                }
                temp = temp * k;
                k++;
            }
            if (j != i-1) {
                cout <<" + ";
            }
            sum += temp;
        }
        cout <<")";
        if (i != n) cout <<" + ";

    }
    cout <<"\nSum = " <<sum <<"\n";
}