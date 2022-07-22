#include <stdio.h>

int sum(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int div(int a, int b) { return b == 0 ? 0 : a / b; }

int main(void)
{
    int i, j, result, op, result2;
    int (*func[4])(int, int) = {sum, sub, mul, div};
    // func[0] = sum;
    // func[1] = sub;
    // func[2] = mul;
    // func[3] = div;

    printf("Enter two number: ");
    scanf("%d %d", &i, &j);
    printf("1: add\n2: Subtract\n3: Multiply\n4: Divide\n");
    do
    {
        printf("Enter number of operation: ");
        scanf("%d", &op);
    } while (op < 1 || op > 4);

    result = (*func[op - 1])(i, j);
    /* or */
    result2 = func[op - 1](i, j);

    printf("%d\n%d\n", result, result2);

    return 0;
}
