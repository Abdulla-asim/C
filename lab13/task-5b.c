// ex07_20.c
// what does this program do?
/*
    This program enters a signle string from the user, 
    calculates the length of the entered string and
    prints the length of the string on the screen.
*/
#include <stdio.h>
#define SIZE 80

int mystery2( const char *s ); // prototype

int main( void )
{
 char string[ SIZE ]; // create char array

 puts( "Enter a string: ");
 scanf( "%79s", string );
 printf( "%d\n", mystery2( string ) );
} // end main

 // What does this function do?
int mystery2( const char *s )
{
 int x; // counter

 // loop through string
 for ( x = 0; *s != '\0'; ++s ) {
 ++x;
 } // end for

 return x;
} // end function mystery2
