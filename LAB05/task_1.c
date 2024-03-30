#include <stdio.h>

int main()
{
    int entries, num, sum, smallest;

    printf("The number of values you want to enter: ");
    scanf("%d", &entries);

    printf("\nEnter the first number: ");
    scanf("%d", &num);

    smallest = num;
    sum = num;

    int i = 0;
    while (i < (entries -1))
    {
        printf("\nEnter another number: ");
        scanf("%d", &num);

        sum += num;
        
        if (num < smallest)
            smallest = num;
        
        i++;
    }
    printf("\nThe sum is: %d", sum);
    printf("\nThe smallest value of entered numbers is: %d", smallest);

    return 0;
}