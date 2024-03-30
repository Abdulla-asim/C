#include <stdio.h>

int found(int num);

int common[10];

int main ()
{
    int input, set1[10], set2[10];
    
    puts("SET - 1");
    for (int i = 0; i < 10; i++)
    {
        printf("Enter number %d : ", i + 1);
        scanf("%d", &set1[i]);
    }
    puts("SET - 2");
    for (int j = 0; j < 10; j++)
    {
        printf("Enter number %d : ", j + 1);
        scanf("%d", &set2[j]);
    }

    for (int x = 0; x < 10; x++)
        for (int y =0; y < 10; y++)
            if (!(found(set1[x])) && (set1[x] == set2[y])) common[x] = set1[x];

    printf("\nThe common elements are: \n");
    for (int z = 0; z < 10; z++)
        if (common[z] > 0) printf("%d\t", common[z]);

    return 0;
}

int found(int num)
{
    for (int i = 0; i < 10; i++)
        if (num == common[i]) return 1;

    return 0; 
}