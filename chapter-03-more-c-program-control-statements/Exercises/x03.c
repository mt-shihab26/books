#include <stdio.h>
#include <math.h>

int main(void)
{
    char ch;
    printf("Do you want to:\nArea of either a Circle, Rectangle or Triangle\nEnter first letter: ");
    ch = getchar();

    if (ch == 'C') {
        int r;
        printf("Enter Circle Radius: ");
        scanf("%d", &r);
        printf("Area of circle is: %.2f\n", 3.1416*r*r);
    }
    else if (ch == 'R') {
        int l, w;
        printf("Enter Rectangle Length: ");
        scanf("%d", &l);
        printf("Enter Rectangle Width: ");
        scanf("%d", &w);
        printf("Area of rectangle is: %d\n", l*w);
    }
    else if (ch == 'T') {
        int f, s, t;
        printf("Enter First side: ");
        scanf("%d", &f);
        printf("Enter Second side: ");
        scanf("%d", &s);
        printf("Enter Third side: ");
        scanf("%d", &t);
        int p = (f+s+t) / 2;
        printf("Area of triangle is: %.2lf\n", sqrt(p*(p-f)*(p-s)*(p-t)));
    }

}