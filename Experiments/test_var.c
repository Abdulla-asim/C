#include <stdio.h>

int main ()
{
    int a = b = 0; // error
    printf("%d, %d", a, b);
}