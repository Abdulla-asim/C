#include <stdio.h>

int main()
{
    int enc;

    printf("Enter the encrypted number: ");
    scanf("%d", &enc);

    int d1 = enc / 1000;
    int d2 = (enc % 1000) / 100;
    int d3 = (enc % 100) / 10;
    int d4 = enc % 10;

    int temp = d1;
    d1 = d3;
    d3 = temp;

    temp = d2;
    d2 = d4;
    d4 = temp;

    int old_d1 = (d1 + 3) % 10;
    int old_d2 = (d2 + 3) % 10;
    int old_d3 = (d3 + 3) % 10;
    int old_d4 = (d4 + 3) % 10;



    int dec = (old_d1*1000) + (old_d2*100) + (old_d3*10) + (old_d4);

    printf("\nThe decrypted number is: %d", dec);

    return 0;
}