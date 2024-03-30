#include <stdio.h>

void main()
{
    float weight, height;

    printf("Enter your weight (kg): ");
    scanf("%f", &weight);

    printf("Enter your height (metres): ");
    scanf("%f", &height);

    printf("\nYour BMI is: %.2f", weight/(height*height));

    printf("\n\nBMI Values\nUnderweight:\tless than 18.5\nNormal:\t\tbetween 18.8 24.9\nOverweight:\tbetween 25 and 29.9\nObese:\t\t30 or greater\n");
}