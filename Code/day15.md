# Day 15 Code

snail problem

```cpp
#include <stdio.h>
#include <cmath>

int main ()
{
    int H,U,D,F,x;
    float y, u, distance_climb, distance_sliding;
    double percent;
    while (scanf("%d %d %d %d", &H, &U, &D, &F), H > 0)
    {
        x = 0;
        percent = (100.0-F)/100.0;
        y = 0;
        distance_sliding = 0;
        distance_climb = 0;
        u =  U;
        printf("percent %f\n", percent);
        while (distance_sliding >= 0 && distance_climb <= H)
        {
            distance_climb = distance_sliding + u;
            distance_sliding = distance_sliding + u - D;
            u *= percent;
            u = round(u * 10)/10; 
            x ++;
            printf("%lf %lf %lf %lf\n", distance_climb, distance_sliding, u);
        }
        if (distance_sliding < 0)
            printf("failure on day %d\n", x);
        else
            printf("succes on day %d\n", x);
    }
    
}
```