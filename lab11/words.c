#include <stdio.h>
#include <string.h>

#define SIZE 1024

int main ()
{
    char string[SIZE];
    int count = 0;

    printf("Enter multiple lines of text (enter to exit): \n");
    while (1)
    {
        fgets(string, SIZE, stdin);
        char *token = strtok(string, " \n");
        while (token)
        {
            count++;
            token = strtok(NULL, " \n");
        }
        if (string[0] == '\n') break;
    }


    printf("The number of words in your text is %d\n", count);

    return 0;
}
