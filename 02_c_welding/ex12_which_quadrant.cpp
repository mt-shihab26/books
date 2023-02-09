#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cout <<"Enter (x, y): ";
    int x, y;
    cin >>x >>y;

    int qu;
    if (x > 0 and y > 0) {
        qu = 1;
    }
    else if (x < 0 and y > 0) {
        qu = 2;
    }
    else if (x < 0 and y < 0) {
        qu = 3;
    }
    else if (x > 0 and y < 0) {
        qu = 4;
    }
    else {
        qu = 0;
    }

    if (qu == 0) {
        cout <<"(" <<x <<", " <<y <<") in Origin" <<"\n";
    }
    else {
        cout <<"(" <<x <<", " <<y <<") in "<<qu <<"'th quadrant\n";
    }

}