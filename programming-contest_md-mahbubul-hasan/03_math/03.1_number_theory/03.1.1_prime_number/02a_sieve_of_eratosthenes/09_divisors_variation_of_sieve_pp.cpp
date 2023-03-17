#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5;
vector<int> divisors[mx + 1];
void sieve()
{
    int i, j;
    for (int i = 2; i <= mx; i++)
    {
        for (int j = i; j <= mx; j += i)
        {
            divisors[j].push_back(i);
        }
    }
    // O(n log n)
}

int main()
{
    sieve();

    for (int i = 2; i <= 1000; i++)
    {
        cout << i << ": ";
        for (int d : divisors[i])
        {
            cout << d << " ";
        }
        cout << "\n";
    }
}