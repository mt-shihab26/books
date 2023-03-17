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
    for (int i = 2; i <= mx; i++)
    {
        if (is_primes[i] == false)
        {
            primes.push_back(i);
            for (int j = i * 2; j <= mx; j += i)
                is_primes[j] = true;
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