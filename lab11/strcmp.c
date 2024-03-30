#include<stdio.h>
#include<string.h>

int main()
{
    char str1[50] = {0}, str2[50] = {0};

    printf("Enter two strings:");
    scanf(" %s %s", str1, str2);

    int input;
    printf("How many characters would be compared: ");
    scanf("%d", &input);

    int result = strncmp(str1, str2, input);
    if (result == 0) printf("\"%s\" is equal to \"%s\" up tp %d characters.", str1, str2, input);
    else if (result < 0) printf("\"%s\" is less than \"%s\" up tp %d characters.", str1, str2, input);
    else printf("\"%s\" is greatern than \"%s\" up tp %d characters.", str1, str2, input);

    return 0;
}