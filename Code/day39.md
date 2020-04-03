# Day 39 Code

kattis_flexibleSpaces.cpp

```cpp

#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int w, p;
    cin >> w;
    cin >> p;
    int l [p];
    for (int i = 0; i < p; i ++)
    {
        cin >> l[i];
    }

    set <int> spaces;
    spaces.insert(w);
    for (int i = 0; i < p; i++)
    {
        spaces.insert(l[i]);
        spaces.insert(w - l[i]);
        if (i != p - 1)
        {
            for (int j = i + 1; j < p; j ++ )
                spaces.insert(l[j] - l[i]);
        }
    }
    for (auto &a: spaces)
    {
        if (a == *spaces.rbegin())
            cout << a;
        else 
            cout << a << " ";
    }
    
}
```