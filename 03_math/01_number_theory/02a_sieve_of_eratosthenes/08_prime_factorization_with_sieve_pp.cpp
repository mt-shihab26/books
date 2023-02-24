#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 5;
vector<bool> is_primes(mx + 1);
vector<int> highest_primes(mx + 1, 0);

void sieve()
{
    int i, j;
    is_primes[1] = true;
    for (int i = 2; i <= mx; i++)
    {
        if (is_primes[i] == false)
        {
            highest_primes[i] = i;
            for (int j = i * 2; j <= mx; j += i)
            {
                is_primes[j] = true;
                highest_primes[j] = i;
            }
        }
    }
    // O(n * log(log(n)))
}

vector<int> prime_factors(int n)
{
    vector<int> pf;
    while (n > 1)
    {
        int prime_factor = highest_primes[n];
        while (n % prime_factor == 0)
        {
            n /= prime_factor;
            pf.push_back(prime_factor);
        }
    }
    return pf;
    // O(log n)
}

int main()
{
    sieve();

    for (int i = 2; i <= 1000; i++)
    {
        cout << i << ": ";
        auto pf = prime_factors(i);
        for (int p : pf)
        {
            cout << p << " ";
        }
        cout << "\n";
    }
}