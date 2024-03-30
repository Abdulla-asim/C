#include <stdio.h>

int main()
{   long int acc;
    int n = 1;
    double pi = 0;
    

    printf("Set the Accuracy: ");
    scanf("%ld", &acc);

    printf("\nTerm\t\t\tpi\n");

    for (int i = 1; i <= acc; i++)
    {
        if (i % 2)
            pi += 4.0 / n;
        else if (!(i % 2))
            pi -= 4.0 / n;
        
        printf("%10d\t\t%.6lf\n", i, pi);
        n += 2;
    }
    return 0;
}