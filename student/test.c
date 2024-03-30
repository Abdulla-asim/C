#include<iostream>

using namespace std;

int main()
{
    int input, count = 0, sum = 0, n = 1;
    puts("A program to find average of numbers:\n");
    while (1)
    {
        printf("Enter number %d (-1 to exit): ", n); // Prompt the user to input marks
        scanf("%d", &input);

        if (input == -1)
            break;

        sum += input;
        count++;
        n++;
    }

    if (sum != 0)
        printf("The average of %d numbers is %.2f", count, (float) sum / count);
    else 
        puts("No data entered...");

    return 0;
}