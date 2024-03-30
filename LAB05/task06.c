#include <stdio.h>

int main()
{
    int n1, n2, small, GCD;

    printf("Enter two numbers: ");
    scanf("%d %d", &n1, &n2);

    if (n1 > n2)
        small = n2;
    else
        small = n1;

    int i = 1;
    while (i <= small)
    {
        if (!(n1 % i) && !(n2 % i))
            GCD = i;
        i++;
    }
    printf("The GCD of %d and %d is %d", n1, n2, GCD);

    return 0;
}