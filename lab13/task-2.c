#include <stdio.h>

int main()
{
    long value1 = 200000, value2;
    long *lptr = &value1;

    printf("Value pointed to by lptr = %li", *lptr);

    value2 = *lptr;
    printf("\nValue of value2 variable = %li", value2);
    printf("\nAddress of value1 = %p", &value1);
    printf("\nAddress of lptr = %p", lptr);
    if (lptr == &value1)
        puts("\nlptr has the same value as the address of value1");

    return 0;
}