#include <stdio.h>

void print_square(int len, char fillchar);

int main()
{
    int n;
    char c;

    printf("Length: ");
    scanf("%d", &n);
    printf("Fill Character: ");
    scanf(" %c", &c);

    print_square(n, c);

    return 0;
}

void print_square(int len, char fillchar)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
            printf("%c ", fillchar);
    puts("");
    }
}