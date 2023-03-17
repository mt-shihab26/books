#include <bits/stdc++.h>
using namespace std;

// Total node = 10000, 0 to 9999.
// Initialize them to -1
int head[10000];
// Total edge = 100000
int data[100000], next[100000];
// Global variable has initial value of 0
int id;

// Add node y in the list of x
void insert(int x, int y)
{
    data[id] = y;
    next[id] = head[x];
    id++;
}

// Erase first nod from head of x
void erase(int x)
{
    // If you are not sure if the linked
    // list is empty, check head[x] == -1?
    head[x] = next[head[x]];
}

// Search node y in list of x
int search(int x, int y)
{
    for (int p = head[x]; p != -1; p = next[p])
        if (data[p] == y)
            return 1; // found
    return 0;         // not found
}

int main()
{
}