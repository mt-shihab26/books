#include <bits/stdc++.h>
using namespace std;

template <typename tp>
void print_vector(const tp &str) {
    for (auto &ith : str)
        cout << ith << " ";
    cout << '\n';
}

void marge_sort(vector<int> &a, int left, int right) {
    if (left == right) return;
    int mid = left + ((right - left) / 2);
    marge_sort(a, left, mid);
    marge_sort(a, mid+1, right);

    int size_left = mid - left + 1;
    int size_right = right - mid;
    
    int a_left[size_left], a_right[size_right];
    
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    print_vector(a);

    marge_sort(a, 0, a.size()-1);

    print_vector(a);

}