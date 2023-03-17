#include <stdio.h>

#define iOS

#ifndef iOS
#error First Include iOS Macro
#else
int main()
{
    printf("I Love Apple Devices!\n");

    return 0;
}
#endif // iOS
