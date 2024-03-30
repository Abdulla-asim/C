#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int sum = 0;
    char str[100];

    for (int i = 0; i < 4; i++)
    {
        printf("Enter a string of intergers: ");
        scanf(" %s", &str);
        int integers = atoi(str);
        sum += integers;
    }

    printf("The total value is: %d", sum);

    return 0;
}