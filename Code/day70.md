# Day 70 Code

```cpp
#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

int UPPER_BOUND = 39;

int clockwise (int start, int end)
{
    if (start > end) return start - end;
    else if (start == end) return 0;
    return start + (UPPER_BOUND - end + 1);
}

int counter_clockwise (int start, int end)
{
    if (end > start) return end - start;
    else if (start == end)  return 0;
    return (UPPER_BOUND - start) + end + 1; 
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef DEBUG
        freopen("in.txt","r",stdin);
    #endif
    int start, num1, num2, num3, posToDegrees = 360/40;
    cin  >> start >> num1 >> num2 >> num3;
    while (start || num1 || num2 || num3)
    {
        int total_positions = clockwise(start, num1) +
                            counter_clockwise(num1, num2) +
                            clockwise(num2, num3);
        //cout << "total positions " << total_positions << "\n"; 
        cout << 1080 + (total_positions) * posToDegrees << "\n";
        cin  >> start >> num1 >> num2 >> num3;
    }
}
```