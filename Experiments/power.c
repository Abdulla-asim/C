/*This is an incorrect version of a program wich "aparently" should find the power
but instead it squares a number and then it squares the "squared number" and so on. . .*/

#include <stdio.h>

int power(int x, int n);

int main()
{
    int pow, num;

    printf ("Enter the number and the power: ");
    scanf("%d %d", &num, &pow);

    printf("Power is : %d", power(num, pow));

}

int power(int x, int n) 
{
    for (int i = 1; i < n; i++)
        x *= x;

    return x;
}