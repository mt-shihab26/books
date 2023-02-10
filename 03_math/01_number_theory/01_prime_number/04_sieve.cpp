#include <bits/stdc++.h>
using namespace std;

int primes[300000], n_prime = 0;

// 1 if not prime, 0 if prime
int mark[1000002];

void sieve(int n)
{
    int i, j, limit = sqrt(n + 1) + 2;

    // 1 is not prime. you can also mark 0
    mark[1] = 1;
    // almost all the evens are not prime
    for (int i = 4; i <= n; i += 2)
        mark[i] = 1;

    // 2 is prime
    primes[n_prime++] = 2;
    // run loop for only odds
    for (int i = 3; i <= n; i += 2)
    {
        // if not prime, no need to do "multiple cutting"
        if (!mark[i])
        {
            // i is prime
            primes[n_prime++] = i;
            cerr << i << ": ";

            // if we don't do it, following
            // i * i may overflow
            if (i <= limit)
            {
                // loop through all odd multiples of i
                // greater then i * i

                // j += i * 2 because we already mark it in even is not prime
                // 3 + 3 = 6, 5 + 5 = 10, so we can go 3 + 3 * 2 = 9, 5 + 5 * 2 = 15 safely
                for (j = i * i; j <= n; j += i * 2)
                {
                    cerr << j << " ";
                    // mark j not prime
                    mark[j] = 1;
                }
            }
            cerr << "\n";
        }
    }
    // O(n log log n)
}

int main()
{
    sieve(100);

    for (int i = 0; i <= 100; i++)
    {
        cout << primes[i] << " ";
    }
    cout << "\n";
}