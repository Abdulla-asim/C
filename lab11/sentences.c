#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

int main ()
{
    char article[5][5] = {"the", "a", "one", "some", "any"};
    char noun[5][5] = {"boy", "girl", "dog", "town", "car"};
    char verb[5][8] = {"drove", "jumped", "ran", "walked", "skipped"};
    char preposition[5][6] = {"to", "from", "over", "under", "on"};
    srand(time(NULL));

    for (int i = 0; i < 20; i++)
    {
        int first_rand = rand() % 5;
        printf("%c%s %s %s %s %s %s.\n", toupper(article[first_rand][0]), article[first_rand]+1, noun[rand() % 5], verb[rand() % 5], 
                preposition[rand() % 5], article[rand() % 5], noun[rand() % 5]);
    }

    return 0;
}
