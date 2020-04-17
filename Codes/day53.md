# Day Code 53

kattis_restaruant.cpp

```cpp

#include <bits/stdc++.h>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n >> ws;
    while (n)
    {
        int stacks [2] {0};
        string s;
        int m;
        while (n--)
        {
            cin >> s >> m >> ws;
            if (s == "DROP")
            {
                stacks[1] += m;
                cout << "DROP 2 " << m << "\n";
            }
            else if (s == "TAKE")
            {
                if (stacks[1] > 0)
                {
                    cout << "MOVE 2->1 " << stacks[1] << "\n";
                    stacks[0] += stacks[1];
                    stacks[1] = 0;
                }
                cout << "TAKE 1 " << m << "\n";
                stacks[0] -= m;
            }
        }
        cin >> n >> ws;
        if (n)
            cout << "\n";
    }
    
}

```

ICPC_Malaysia_2019_b.cpp

```cpp

#include <bits/stdc++.h>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; 
    int w, l;
    cin >> n >> ws;
    while (n--)
    {
        cin >> w >> l;
        string out = (w == l) ? "YES\n" : "NO\n";
        cout << out;
    }
}

```
