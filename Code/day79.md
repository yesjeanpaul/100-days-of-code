# Day 79 Code

10050_Hartals.cpp

```cpp

#include <bits/stdc++.h>
//#define DEBUG

using namespace std;

set <int> numberDays;

void generateDays(int frecuency, int dayLimit)
{
    int day = frecuency;
    while (day <= dayLimit)
    {
        if (!(day % 7 == 6  || day % 7 == 0 ))
            numberDays.insert(day);
        day += frecuency;
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef DEBUG
        freopen("in.txt","r",stdin);
    #endif
    int T, N, P, h;
    cin >> T;
    while(T --)
    {
        cin >> N >> P;
        while (P--)
        {
            cin >> h;
            generateDays(h, N);
        }
        cout << numberDays.size() << "\n";
        /*for (auto& x: numberDays)
            cout << x << " ";
        cout << "\n";*/
        numberDays.clear();
    }
    
}

```