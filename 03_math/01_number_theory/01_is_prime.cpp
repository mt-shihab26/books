#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    int root = sqrt(n + 1);
    if (n % 2 == 0)
        return false;
    for (int i = 3; i <= root; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
    // O(sqrt(n)/2) -> O(sqrt(n))
}

int main()
{
    cout << boolalpha << is_prime(5) << "\n";
}