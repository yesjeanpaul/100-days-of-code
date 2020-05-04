# Day 66 code

macros.cpp

```cpp
#include <bits/stdc++.h>
#define DEBUG

using namespace std;

int main ()
{
    #ifdef DEBUG
        freopen("in.txt","r",stdin);
    #endif
    int a, b, c;
    cin >> a >> b >> c;
    cout << a << " " << b << " " << c << endl;
}
```