#include <stdio.h>
#include <string.h>

int main() {
    
   char *p = "stop";
   char str[80];

   do {
       printf("Enter a string: ");
       gets(str);
   } while (strcmp(p, str));

    return 0;
}
// Author: Shihab Mahamud
// Date: বুধবার, ফেব্রুয়ারী 17, 2021 | 14:39:30
