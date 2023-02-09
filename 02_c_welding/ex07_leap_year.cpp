#include <iostream>

int main(void) {
    int year;
    std::cin >> year;

    if (not(year % 400) or (year % 100) and (not(year % 4))) {
        std::cout << year << " is Leap Year\n";
    }
    else {
        std::cout << year << " is Not Leap Year\n";
    }
}