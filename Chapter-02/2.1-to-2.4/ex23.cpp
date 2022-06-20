#include <bits/stdc++.h>
using namespace std;

int main(void) {
    for (int i = 1, k = 3; i <= 3; i++, k--) {
        for (int j = i; j > 1; j--) {
            cout <<" ";
        }
        for (int j = 1; j <= k; j++) {
            cout <<j;
        }
        for (int j = 1; j <= k-1; j++) {
            cout <<j;
        }
        cout <<"\n";
    }
}