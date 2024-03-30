#include <stdio.h>

int main()
{
    int entry, counter = 0, sum = 0;

    do
    {
        printf("Enter an integer (9999 to exit): ");
        scanf("%d", &entry);

        if(entry != 9999)
        {
            sum += entry;
            counter++;
        }
    }
    while (entry != 9999);

    if (counter > 1)
        printf("\nThe average is: %f", (float) sum / (float) counter);
    else
        printf("No entries!");
    
    return 0;
}