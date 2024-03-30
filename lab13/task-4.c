#include <stdio.h>

int binary_search(int *array, int start, int end, int key);

int main()
{
    int key, array[10] = {2, 4, 5, 9, 13, 15, 17 ,20, 23, 25};

    printf("Enter a number between 1 and 25: ");
    scanf("%d", &key);

    int result = binary_search(array, 0, 9, key);

    if (result != -1) printf("\n%d found at %dth index\n", key, result);
    else printf("\n%d not found", key);

    return 0;
}

int binary_search(int *array, int start, int end, int key)
{
    if (start <= end)
    {
        int middle = (int) (((start + end) / 2.0) + 0.5); // calculates the middle term
        if (key == *(array + middle))
        {
            return middle;
        }
        else if (key < *(array + middle))
        {
            return binary_search(array, start, middle - 1, key);
        }
        else
            return binary_search(array, middle + 1, end, key);  
    }
    return -1;
}