# Day 14 code

11799_Horror_Dash.cpp

```cpp
#include <stdio.h>

int main () 
{
    int T, N, max, i, j, v;
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        max = 0;
        scanf("%d", &N);
        for (j = 0; j < N; j++)
        {
            scanf("%d", &v);
            if (v > max)
                max = v;
        }
        printf("Case %d: %d\n", i+1, max);
    }
    
}
```