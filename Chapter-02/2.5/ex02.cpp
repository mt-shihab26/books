#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string str;
    cin >>str;
    string date = str.substr(0, 2);
    char arr[100];

    int data_int = stoi(date);
    cout <<data_int;
    string month = str.substr(3, 1);
    cout <<month;
}