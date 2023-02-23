#include <bits/stdc++.h>
using namespace std;

const int mx = 1e7 + 5;
vector<bool> is_primes(mx + 1);
vector<int> primes;
// we can set mx global variable to how many prime we want
// is_primes[i] == false means i'th value is prime
// in primes global variable we got all primes
void sieve()
{
    int i, j;
    is_primes[1] = true;

    primes.push_back(2);
    for (int i = 4; i <= mx; i += 2)
        is_primes[i] = true;

    int root = sqrt(mx + 1) + 2;

    for (int i = 3; i <= mx; i += 2)
    {
        if (is_primes[i] == false)
        {
            primes.push_back(i);
            if (i <= root)
            {
                for (int j = i * i; j <= mx; j += i)
                    is_primes[j] = true;
            }
        }
    }
    // O(n * log (log n))
}

int main()
{
    cout << boolalpha;
    sieve();
    for (int prime : primes)
    {
        cout << prime << " " << is_primes[prime] << "\n";
    }
    cout << "\n";
}