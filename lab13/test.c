#include <stdio.h>
#include <strings.h>

#define SIZE 5

void main()
{
    char *names[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter name %d: ", i + 1);
        getchar();
        fgets(names[i], 1024, stdin);
        //scanf(" %s", names[i]);
        //puts("");
    }
}