## Day 64 Code

phoenix_and_balance.cpp

```cpp
#include <bits/stdc++.h>

using namespace std;


int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long p [34];
    p[0] = 1;
    p[1] = 2;
    for (int i = 2; i <= 34; i++)
        p[i] = p[i -1]*2;
    
    long long v[31], sum1, sum2;
    bool pile = true;
    v[2] = 2;
    for (int n = 4; n <= 30; n +=2)
    {
        sum1 = (long long) 0;
        sum2 = (long long) 0;
        pile = true;
        int con = 1;
        for (int i = 0; i < n/2; i++)
        {
            if (pile)
            {
                sum1 += p[con];
                sum2 += p[con + 1];
                pile = false;
            }
            else
            {
                sum1 += p[con + 1];
                sum2 += p[con];
                pile = true;
            }
            con += 2;
        }

        v[n] = sum1 - sum2;
    }

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << v[n] << "\n";
    }       

}
```