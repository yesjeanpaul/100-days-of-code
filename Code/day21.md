# Day 21 Code

10550_Combination_lock.cpp

```cpp
#include <stdio.h>

int marks_counter_clockwise (int actual, int next)
{
    if (next > actual)
        return next - actual;
    else
        return (40 - actual) + next;
}

int marks_clockwise  (int actual, int next)
{
    if (next < actual)
        return actual - next;
    else
        return (40 - next) + actual;
}

int main ()
{
    int dial, n1, n2, n3, marks_to_degrees = 360/40;
    while (scanf("%d %d %d %d", &dial, &n1, &n2, &n3), 
                                dial != 0, n1 != 0, n2 != 0, n3 != 0)
    {
        printf("%d\n", 1080 + 
            (marks_clockwise(dial, n1)+ marks_counter_clockwise(n1, n2) + marks_clockwise(n2,n3)) * marks_to_degrees
        );
    }
    
}
```


11044_Searching_for_nessy.cpp

```cpp
#include <stdio.h>

int get_number_of_radars_per_direction (int n)
{
    return n % 3 == 0 ? n/3 : (n/3) + 1;
}

int main ()
{
    int N,n,m, i;
    scanf("%d", &N);
    while (N --)
    {
        scanf("%d %d", &n, &m);
        printf("%d\n", get_number_of_radars_per_direction(n - 2) * get_number_of_radars_per_direction(m - 2));
    }
    
}
```