#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define SIZE 5

void my_strings_sort(char *names[]);

void main()
{
    char *names[SIZE];
    for (int i = 0; i < SIZE; ++i)
    {
      printf("Enter name %d: ", i + 1);
      names[i] = (char*) malloc(sizeof(char)*20);

      fgets(names[i], sizeof(char)*20, stdin);

      int len = strlen(names[i]);
      if (len > 0 && names[i][len - 1] == '\n')
         names[i][len - 1] = '\0';
   }
   puts("");

    my_strings_sort(names);

    for (int j = 0; j < SIZE; j++)
        printf("%s\n", names[j]);
}

void my_strings_sort(char *names[])
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (strcmp(names[i], names[j]) < 0) // 
            {
                char *temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
}
