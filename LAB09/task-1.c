#include <stdio.h>
 int main()
 {
    int sum = 0, number[10];
    for (int i = 1; i <= 10; i++)
    {
        printf("Enter the number %d: ", i);
        scanf("%d", &number[i-1]);
    }
    
    for (int j = 0; j < 10; j++)
        sum += number[j];

    printf("\nThe average is %d ", sum / 10);

    return 0;
 }