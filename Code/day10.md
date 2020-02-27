# Day 10 Code

11727_Cost Cutting.cpp

```cpp
#include <stdio.h>
#include <algorithm>

using namespace std;

int main () 
{
    int T, i, v[3];
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%d %d %d", &v[0], &v[1], &v[2]);
        sort(v, v + 3);
        printf("Case %d: %d\n", i + 1, v[1]);
    }

}
```