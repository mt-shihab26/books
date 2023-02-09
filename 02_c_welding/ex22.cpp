#include <bits/stdc++.h>
using namespace std;

int main(void) {
    for (int i = 1, k = 1; i <= 3; i++, k += 2) {
        for (int j = 3-i; j >= 1; j--) {
            cout <<" ";
        }
        for (int j = k; j >= 1; j--) {
            cout <<"*";
        }
        cout <<"\n";
    }
}