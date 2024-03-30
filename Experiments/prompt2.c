// Prompt for Windows or Linux or Mac
// Use of #ifdef, #else and #endif

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <string.h>

// Declared a buffer of size 2048
static char buffer[2048];

char* readline(char* prompt)
{
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);

    char* cpy = malloc(strlen(buffer) - 1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy) - 1] = '\0';

    return cpy;
}

#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

int main (int argc, char** argv)
{
    // Prints version and exit info
    puts("Lispy version 0.0.0.0.1");
    puts("Press Ctrl + C to Exit");

    // Infinite loop
    while (1)
    {
        char* input = readline("Lispy> ");

        // Echo back to the user
        printf("No you're a %s\n", input);
        free(input);
    }

    return 0;
}