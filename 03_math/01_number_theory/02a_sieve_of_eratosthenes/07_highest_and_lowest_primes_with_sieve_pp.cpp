#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 5;
vector<bool> is_primes(mx + 1);
vector<int> highest_primes(mx + 1, 0), lowest_primes(mx + 1, 0);

void sieve()
{
    int i, j;
    is_primes[1] = true;
    for (int i = 2; i <= mx; i++)
    {
        if (is_primes[i] == false)
        {
            lowest_primes[i] = highest_primes[i] = i;
            for (int j = i * 2; j <= mx; j += i)
            {
                is_primes[j] = true;
                if (lowest_primes[j] == 0)
                    lowest_primes[j] = i;
                highest_primes[j] = i;
            }
        }
    }
}

int main()
{
    sieve();

    for (int i = 2; i <= 1000; i++)
    {
        cout << i << ": " << lowest_primes[i] << " " << highest_primes[i] << "\n";
    }
}