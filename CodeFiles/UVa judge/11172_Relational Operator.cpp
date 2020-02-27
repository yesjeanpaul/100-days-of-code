#include <stdio.h>

void get_operator (int a, int b)
{
    if (a > b)
        printf(">\n");
    else if (a < b)
        printf("<\n");
    else
        printf("=\n");
}

int main ()
{   
    int N ,a, b;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d %d", &a, &b);
        get_operator(a,b);
    }
    return 0;
}