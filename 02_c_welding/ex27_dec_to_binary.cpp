#include <bits/stdc++.h>
using namespace std;

string dec_to_binary(int num) {
    string binary;
    while (num) {
        binary += to_string(num % 2);
        num /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

int main(void) {
    cout <<"Enter Decimal number: ";
    int num;
    cin >>num;

    cout <<"Binary of " <<num <<" is: " <<dec_to_binary(num) <<"\n";
}