#include <iostream>
using namespace std;

int main(void) {
    int num, copy_num, rev = 0;
    cout << "Enter a number: ";
    cin >> num;
    copy_num = num;

    while (num!=0) {
        rev = (rev*10) + (num%10);
        num /= 10;
    }

    if (copy_num == rev) {
        cout << "The number is a palindrome." << endl;
    }
    else {
        cout << "The number is not a palindrome." << endl;
    }
    return 0;
}