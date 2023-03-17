#include <stdio.h>

int encode(int i);

int main(void)
{
    int i;
    i = encode(10); // encode it
    printf("10 encoded is %d\n", i);
    i = encode(i); // decode if
    printf("i decoded is %d\n", i);

    return 0;
}

// Encode an integer, decode an encoded integer
int encode(int i)
{
    union erypt_type {
        int num;
        char c[2];
    } crypt;
    unsigned char ch;
    crypt.num = i;

    // swap bytes
    ch = crypt.c[0];
    crypt.c[0] = crypt.c[1];
    crypt.c[1] = ch;

    // return encoded integer
    return crypt.num;
}