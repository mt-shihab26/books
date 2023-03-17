#include <stdio.h>

int main() {
    char **mp, *p, ch, ***ap;
    p = &ch; // get address of ch
    mp = &p; // get address of p
    ap = &mp; // assign ch the value a using multiple indirection

    ***ap = 'A';

    printf("%c", ch);
    

    return 0;
}
// Author: Shihab Mahamud
