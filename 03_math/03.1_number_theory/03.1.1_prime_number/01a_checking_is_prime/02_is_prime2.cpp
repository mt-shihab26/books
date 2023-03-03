#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
    // O(sqrt(n))
}

int main()
{
    cout << boolalpha << is_prime(5) << "\n";
}