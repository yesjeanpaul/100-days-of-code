# Day 13 Code

11559_Event_Planning.cpp

```cpp
#include <stdio.h>
#include <limits.h>


int main ()
{
    int N,B,H,W,i,j;
    while (scanf("%d %d %d %d", &N, &B, &H, &W) != EOF)
    {
        int hotel_and_price[H][W + 1];
        for (i = 0; i < H; i ++)
        {
            scanf("%d", &hotel_and_price[i][0]);
            for(j = 1; j < W + 1; j++)
            {
                scanf("%d", &hotel_and_price[i][j]);
            }
        }

        int costs = 0, budget = B, min = INT_MAX;
        for (i = 1; i < W +1; i++)
        {
            for (j = 0; j < H; j ++)
            {
                //printf("%d\n", hotel_and_price[i][j]);
                if (hotel_and_price[j][i] >= N && 
                    N * hotel_and_price[j][0] <= budget && 
                    N * hotel_and_price[j][0] < min)
                        
                        min = N * hotel_and_price[j][0];
            
            }
        }

        if (min == INT_MAX)
            printf("stay home\n");
        else
            printf("%d\n", min);        
    }
}
```