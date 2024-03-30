#include <stdio.h> // Abdullah, 455340
void main()
{
    int n1, n2, n3, hyp, side1, side2;
    do // Keeps prompting the user for input as long as the user does not enter a number greater than zero.
    {
        printf("Enter the length of the sides of a triangle: ");
        scanf("%d %d %d", &n1, &n2, &n3);
    }
    while(n1 > 0 && n2 > 0 && n3 > 0);
    
// Identifies the sides and stores them in variables.
    if (n1 > n2 && n1 > n3)
    {
        hyp = n1;
        side1 = n2;
        side2 = n3;
    }
    else if(n2 > n3 && n2 > n2)
    {
        hyp = n2;
        side1 = n1;
        side2 = n3;
    }  
    else
    {
        hyp = n3;
        side1 = n1;
        side2 = n2;
    }
        
// Checks if the sides can be the sides of a right triangle and prints the answer.
    if ((hyp * hyp) == (side1 * side1) + (side2 * side2))
        printf("These are the sides of a right angle triangle.\n");
    else 
        printf("These are not the sides of a right angle triangle.\n");
}