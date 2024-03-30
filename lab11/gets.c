#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char str[100] = {0};

    puts("Enter a line of text: ");
    fgets(str, 100, stdin);

    for (int i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
    printf("\nThe line in lowercase is: \n%s", str);


    for (int i = 0; i < strlen(str); i++)
        str[i] = toupper(str[i]);
    printf("\nThe line in uppercase is: \n%s", str);  

    return 0;
}