#include <stdio.h>
#include <math.h>

typedef struct {
    int p;
    int q;
} Rational;

void sum_ration(Rational *source1,  Rational *source2, Rational *dis);
void sub_ration(Rational *source1,  Rational *source2, Rational *dis);
void mul_ration(Rational *source1,  Rational *source2, Rational *dis);
int div_ration(Rational *source1,  Rational *source2, Rational *dis);
void make_smallest(Rational *dis);

int main(void)
{
    Rational one_rational;
    printf("One P: ");
    scanf("%d", &one_rational.p);
    printf("One Q: ");
    scanf("%d", &one_rational.q);

    Rational two_rational;
    printf("Two P: ");
    scanf("%d", &two_rational.p);
    printf("Two Q: ");
    scanf("%d", &two_rational.q);

    Rational sum_rational, sub_rational, mul_rational, div_rational;
    sum_ration(&one_rational, &two_rational, &sum_rational);
    printf("Sum of Rational p = %d, q = %d\n", sum_rational.p, sum_rational.q);

    sub_ration(&one_rational, &two_rational, &sub_rational);
    printf("Sub of Rational p = %d, q = %d\n", sub_rational.p, sub_rational.q);

    mul_ration(&one_rational, &two_rational, &mul_rational);
    printf("Mul of Rational p = %d, q = %d\n", mul_rational.p, mul_rational.q);

    if (!div_ration(&one_rational, &two_rational, &div_rational))
        printf("Div of Rational p = %d, q = %d\n", div_rational.p, div_rational.q);
    else 
        printf("Cannot Divideable\n");

    return 0;
}

void make_smallest (Rational *dis)
{
    int root = (int)sqrt(dis->q);
    for (int i = 2; i <= root; ) {
        if ((dis->p % i == 0) && (dis->q % i == 0)) {
            dis->p = dis->p / i;
            dis->q = dis->q / i;
            i = 2;
        }
        else i++;
    }
}

void sum_ration(Rational *source1,  Rational *source2, Rational *dis)
{
    dis->p = (source1->p * source2->q) + (source2->p * source1->q);
    dis->q = source1->q * source2->q;
    make_smallest(dis);
    
}

void sub_ration(Rational *source1,  Rational *source2, Rational *dis)
{
    dis->p = (source1->p * source2->q) - (source2->p * source1->q);
    dis->q = source1->q * source2->q;
    make_smallest(dis);
}

void mul_ration(Rational *source1,  Rational *source2, Rational *dis)
{
    dis->p = (source1->p * source2->q) * (source2->p * source1->q);
    dis->q = source1->q * source2->q;
    make_smallest(dis);
}

int div_ration(Rational *source1,  Rational *source2, Rational *dis)
{
    if (source2->q) { 
        dis->p = (source1->p * source2->q) / (source2->p * source1->q);
        dis->q = source1->q / source2->q;
        make_smallest(dis);
        return 0;
    }
    else 
        return 1;
}