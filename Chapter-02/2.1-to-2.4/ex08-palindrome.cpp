#include <bits/stdc++.h>

bool is_palindrome(int num) {
    std::vector<int> digits;
    while (num) {
        digits.push_back(num%10);
        num /= 10;
    }
    for (int i = 0, j = digits.size()-1; i < int(digits.size() / 2); i++, j--) {
        if (digits[i] != digits[j]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int n;
    std::cin >>n;
    int nth_palindrome;

    for (int i = 1, j = 1; j <= n; i++) {
        if (is_palindrome(i)) {
            if (j == n) {
                nth_palindrome = i;
            }
            j++;
        }
    }

    std::cout <<n <<"'th Palindrome is: " <<nth_palindrome <<"\n";
}