#include <stdio.h>
//prints : 
/*A B C D E F G F E D C B A
  A B C D E F   F E D C B A
  A B C D E       E D C B A
  A B C D           D C B A
  A B C               C B A
  A B                   B A
  A                       A */

int main()
{
    int i = 1;
    int a = 65; 
    int odd = 1;

    while (i <= 7) // iterates for 7 rows.
    {
        int s = 0;
        while (s < 8 - i)  // Prints the first triangle.
        {
            printf("%c ", a + s); // 'a'represts the alphabet A and adding 's' advances the alphabets
            s++;
        }

        int w = 1;
        while (w <= odd - 2) // prints odd number of spaces. (1, 3, 5,...)
        {
            if (i != 1) // does not print any space in the first row.
            {
                printf("  ");
                w++;
            }
            else
                break;
        }
        odd += 2; // get the next odd number

        int s2 = 7;
        if (i == 1)  // helps in not printing 'G' the second time.
                s2--;
        while (s2 >= i) // prints the second triangle
        {
            printf("%c ", a + s2 - i);  // 'a' is 65, so adding s2 i.e: 6,   
            s2--;                       // makes the second triangle start from G and 
        }                               // subtracting i, i.e: 1 makes it start from F.
        printf("\n");
        i++;
    }
    return 0;
}