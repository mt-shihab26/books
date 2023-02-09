#include <bits/stdc++.h>
using namespace std;

bool is_prime(const int &num) {
    if (num <= 1) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    if (not(num % 2)) {
        return false;
    }
    long long int root = sqrt(num);
    for (int i = 3; i <= root; i += 2) {
        if (not(num % i)) {
            return false;
        }
    }
    return true;
}

int main(void) {
    cout <<"Enter a Number: ";
    long long int num;
    cin >>num;

    if (is_prime(num)) {
        cout <<num <<" is Prime" <<"\n";
    }
    else {
        cout <<num <<" is Not Prime" <<"\n";
    }

}