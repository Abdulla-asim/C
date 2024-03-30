#include <stdio.h>

void main()
{
    int n = 9, i, j; 
    
     for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) {
            printf("-");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            if (j % 2 == 1) {
                printf("*");
            } else {
                printf("-");
            }
        }
        for (j = 1; j <= n - i; j++) {
            printf("-");
        }
        printf("\n");
    }

    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= n - i; j++) {
            printf("-");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            if (j % 2 == 1) {
                printf("*");
            } else {
                printf("-");
            }
        }
        for (j = 1; j <= n - i; j++) {
            printf("-");
        }
        printf("\n");
    }



}