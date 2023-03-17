// An electronic card catalog
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int menu(void);
void display(int i);
void author_search(void);
void title_search(void);
void enter(void);

char names[MAX][80];   // author names
char titles[MAX][80]; // titles
char pubs[MAX][80];   // publisher

int top = 0; // last lacation used

int main(void)
{
    int choice;

    do {
        choice = menu();
        switch (choice) {
        case 1:
            enter(); // enter books
            break;
        case 2:
            author_search(); // search by author
            break;
        case 3:
            title_search(); // search by title
            break;
        }
    } while (choice != 4);

    return 0;
}

// return a menu selection
menu(void)
{
    char str[80];
    int i;

    printf("CArd Catalog:\n 1. Enter\n 2. Search by Author\n 3. Search by Title\n 4. Quit\n");

    do {
        printf("Choose your selection: ");
        gets(str);
        i = atoi(str);
        printf("\n");
    }   while (i < 1 || i > 4);

    return i;
}

// enter books into database
void enter(void)
{
    int i;
    
    for (i = top; i < MAX; i++) {
        printf("Enter author name (Enter to quit): ");
        gets(names[i]);
        if (! *names[i]) break;
        printf("Enter title: ");
        gets(titles[i]);
        printf("Enter publisher: ");
        gets(pubs[i]);
    }
    top = i;
}

// Search by author
void author_search(void)
{
    char name[80];
    int i, found;

    printf("Name: ");
    gets(name);

    found = 0;
    for (i = 0; i < top; i++) {
        if (!strcmp(name, names[i])) {
            display(i);
            found = 1;
            printf("\n");
        }
    }
    if (!found) printf("Not found\n");
}

// Search by title
void title_search(void)
{
    char title[80];
    int i, found;
    printf("Title: ");
    gets(title);

    found = 0;

    for (i=0; i<top; i++) {
        if (strcmp(title, titles[i])) {
            display(i);
            found = 1;
            printf("\n");
        }
    }
    if (!found) printf("Not found\n");
}

// Display catalog entry.
void display(int i)
{
    printf("%s\n", titles[i]);
    printf("by %s\n", names[i]);
    printf("Published by %s\n", pubs[i]);
}
