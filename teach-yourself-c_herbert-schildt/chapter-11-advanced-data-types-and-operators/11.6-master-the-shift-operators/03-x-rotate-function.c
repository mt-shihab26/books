#include <stdio.h>

void rotate(unsigned char *c)
{
    union
    {
        unsigned char ch[2];
        unsigned u;
    } rot;

    rot.u = 0; /* clear 16 bits */
    rot.ch[0] = *c;

    /* shift integer left */
    rot.u = rot.u << 1;

    /* See if a bit got shifted into c[1]
       if so, or it back onto the other end. */
    if (rot.ch[1])
        rot.ch[0] = rot.ch[0] | 1;

    *c = rot.ch[0];
}

int main(void)
{
    unsigned char ch;
    int i;

    ch = 1;

    for (i = 0; i < 16; i++)
    {
        rotate(&ch);
        printf("%u\n", ch);
    }

    return 0;
}