#include <stdio.h>

int main()
{
    int n, old_d1, old_d2, old_d3, old_d4, enc, temp;
    printf("Enter a 4-digit number: ");
    scanf("%d", &n);

    old_d1 = n / 1000;
    old_d2 = (n % 1000) / 100;
    old_d3 = (n % 100) / 10;
    old_d4 = n % 10;

    int d1 = (old_d1 + 7) % 10;
    int d2 = (old_d2 + 7) % 10;
    int d3 = (old_d3 + 7) % 10;
    int d4 = (old_d4 + 7) % 10;

    temp = d1;
    d1 = d3;
    d3 = temp;

    temp = d2;
    d2 = d4;
    d4 = temp;

    enc = d1*1000 + d2*100 + d3*10 + d4;

    printf("\nEncrypted Number: %d", enc);

    return 0;
}