#include <stdio.h>

void main() 
{
    int a[2] = {2.2, 1.1};
    int j, *p = a, *q = &a[1];
}
/*
int main ()
{
    int a = 2;
    printf("%d %d %d", a++, a, ++a);

    return 0;
}
*/
/*
int main ()
{
    int a = 2;
    int exp = a + 4 + a++;
    printf("%d %d", exp, a);
}
*/