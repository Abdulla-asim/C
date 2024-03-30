// ex07_19.c of the textbook
// What does this program do?
/* 
    This program inputs two strings from the user 
    and concatenates the second string to the end of the first string. 
*/
#include <stdio.h>
#define SIZE 80

void mystery1( char *s1, const char *s2 ); // prototype

int main( void )
{
    char string1[ SIZE ]; // create char array
    char string2[ SIZE ]; // create char array

    puts( "Enter two strings: " );
    scanf( "%79s%79s" , string1, string2 );
    mystery1( string1, string2 );
    printf("%s", string1 );
} // end main

// What does this function do?
void mystery1( char *s1, const char *s2 )
{
    while ( *s1 != '\0' ) {
        ++s1;
    } // end while

    for ( ; *s1 = *s2; ++s1, ++s2 ) {
        ; // empty statement
    } // end for
} // end function mystery1
