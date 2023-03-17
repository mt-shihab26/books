#include <stdio.h>

int main(void)
{
    int choiced;

    do {
        printf("Mailing list menu:\n 1.Enter addresses\n 2.Delete address\n 3. Search the list\n 4. Print the list.\n 5. Quit\nEnter the number of your choice(1-5): ");
        scanf("%d", &choiced);
    }   while (choiced < 1 || choiced <= 5);

    return 0;
}