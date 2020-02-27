#include <stdio.h>
#include <stdlib.h>

int y_coord, x_coord;

char get_y_direction(int y)
{
    if (y > y_coord)
        return 'N';
    else
        return 'S';
}

char get_x_direction(int x)
{
    if (x > x_coord)
        return 'E';
    else
        return 'O';
}

void get_direction(char* direction, int x, int y)
{
    direction[0] = get_y_direction(y);
    direction[1] = get_x_direction(x);
}

bool verify_divisa (int x, int y)
{
    if (x == x_coord || y == y_coord)
    {
        printf("divisa\n");
        return true;
    }
    return false;
}   

int main ()
{
    int K, i, x, y;
    char direction [3];
    while (scanf("%d", &K), K)
    {
        scanf("%d %d", &x_coord, &y_coord);
        for (i = 0; i < K; i++)
        {
            scanf("%d %d", &x, &y);
            if (!verify_divisa(x,y))
            {
                get_direction(direction,x,y);
                printf("%s\n", direction);
            }
        }
    }
    
}