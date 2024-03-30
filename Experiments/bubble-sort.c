#include <stdio.h>

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void print_array(int size, int data[], char *title)
{
    printf("%s", title);

    for (int i = 0; i < size; i++)
        printf("%d\t", data[i]);
}

void bubble(int size, int data[])
{
    int prompt;
    
    for (int i = 0; i < size; i++)
    {
        int swapped = 0;

        print_array(size, data, "\ninside bubble\n");
        printf("i = %d, enter an integer to continue: ", i);
        scanf("%d", &prompt);

        for (int j = size - 1; j > i; j--)
            if (data[j - 1] > data[j])
                swap(&data[j - 1], &data[j]);
                swapped = 1;

        if (!swapped)
            break;
    }
}

#define size 5
int main()
{

    int array[sizeof(int)*size] = {5 , 4, 3, 2, 1};

    print_array(size, array, "my grades\n");
    printf("\n\n");
    bubble(size, array);
    print_array(size, array, "\nMy sorted array!\n");

    return 0;
}