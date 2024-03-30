#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);

    printf("\nisdigit ('%c') =  %d", ch, isdigit(ch));
    printf("\nisalpha ('%c') =  %d", ch, isalpha(ch));
    printf("\nisalnum ('%c') =  %d", ch, isalnum(ch));
    printf("\nisxdigit('%c') =  %d", ch, isxdigit(ch));
    printf("\nislower ('%c') =  %d", ch, islower(ch));
    printf("\nisupper ('%c') =  %d", ch, isupper(ch));
    printf("\ntolower ('%c') =  %d", ch, tolower(ch));
    printf("\ntoupper ('%c') =  %d", ch, toupper(ch));
    printf("\nisspace ('%c') =  %d", ch, isspace(ch));
    printf("\niscntrl ('%c') =  %d", ch, iscntrl(ch));
    printf("\nispunct ('%c') =  %d", ch, ispunct(ch));
    printf("\nisprint ('%c') =  %d", ch, isprint(ch));
    printf("\nisgraph ('%c') =  %d\n", ch, isgraph(ch));
 
    return 0;
}
