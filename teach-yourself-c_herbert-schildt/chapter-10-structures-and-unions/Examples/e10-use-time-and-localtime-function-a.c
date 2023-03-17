#include <stdio.h>
#include <time.h>

int main(void)
{
    struct tm *systime;
    time_t t;

    time(&t); // or t = time(NULL) are same
    systime = localtime(&t);

    printf("Time is %.2d %.2d %.2d\n", systime->tm_hour, systime->tm_min, systime->tm_sec);
    printf("Date is %.2d/%.2d/%.2d\n", systime->tm_mon+1, systime->tm_mday, systime->tm_year);

    return 0;
}