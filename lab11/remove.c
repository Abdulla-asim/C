#include <stdio.h>
#include <string.h>

int word_count(char str[]);
void remove_word(char str[], char word[]);

int main()
{
    char in_str[100] = {0}, word[15] = {0};
    
    printf("Enter a string: ");
    fgets(in_str, 100, stdin);

    printf("Enter the word to be removed: ");
    scanf(" %s", word);
    getchar();

    printf("The string is: %s", in_str);
    printf("The number of words in this string is: %d\n", word_count(in_str));

    remove_word(in_str, word);

    printf("The string after removing \"%s\" is: %s", word, in_str);
    printf("\bAnd the no of words in the string is: %d\n", word_count(in_str));

    return 0;
}


// Count the words in string
int word_count(char str[])
{
    int counter = 0;
    char copy[100] = "";
    strcpy(copy, str);

    char *token = strtok(copy, " ");

    while (token)
    {
        counter++;
        token = strtok(NULL, " ");
    }

    return counter;
}

void remove_word(char str[], char word[])
{   
    char final[100] = "";
    char *token = strtok(str, " ");

    while (token)
    {
        if (strcmp(token, word))
        {
            strcat(final, token);
            strcat(final, " ");
        }
        token = strtok(NULL, " ");
    }

    strcpy(str, final);
}  