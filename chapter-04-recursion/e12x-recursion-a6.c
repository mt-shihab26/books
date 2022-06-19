#include <stdio.h>

void a()
{
    printf("A\n");
    b();
}

void b()
{
    printf("B\n");
    c();
}

void c()
{
    static int count = 1;
    if (count > 5) return;
    printf("C\n");
    count += 1;
    a();
}

int main(void)
{
    a();
}