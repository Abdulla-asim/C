#include <stdio.h>

int main()
{
    printf("ASCII:\n");

    int i = 0;
    while(i <= 255)
    {
        printf("%c   ", i);
        i++;
    }
    return 0;
}