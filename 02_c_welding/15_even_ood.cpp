#include <iostream>

int main(void) {
    int a;
    std::cin >>a;

    if (a % 2 == 0) {
        std::cout <<a <<" is even\n";
    }
    else {
        std::cout <<a <<" is odd\n";
    }

    return 0;
}