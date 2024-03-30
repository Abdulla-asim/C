// Prompt only for Windows

#include <stdio.h>

// Declared a buffer of size 2048
static char input[2048];

int main (int argc, char** argv)
{
    // Prints version and exit info
    puts("Lispy version 0.0.0.0.1");
    puts("Press Ctrl + C to Exit");

    // Infinite loop
    while (1)
    {
        // Output my prompt
        fputs("RudeLispy > ",stdout);

        // Read a line of user input, max size 2048
        fgets(input, 2048, stdin);

        // Echo back to the user
        printf("No you're a %s", input);
        printf("Don't talk to me like %s", input);
    }

    return 0;
}
