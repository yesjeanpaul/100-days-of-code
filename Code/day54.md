# Day 54 Code

kattis_restaurant.cpp

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
                if (stacks[0] > 0)
                {
                    if (m > stacks[0])
                    {
                        int rest = m - stacks[0];
                        cout << "TAKE 1 " << stacks[0] << "\n";
                        stacks[0] = 0;
                        cout << "MOVE 2->1 " << stacks[1]  << "\n";
                        stacks[0] += stacks[1];
                        stacks[1] = 0;
                        stacks[0] -= rest;
                        cout << "TAKE 1 " << rest << "\n";

                    }
                    else
                    {
                        cout << "TAKE 1 " << m << "\n";
                        stacks[0] -= m;
                    }                   
                }
                else
                {
                    cout << "MOVE 2->1 " << stacks[1]  << "\n";
                    stacks[0] += stacks[1];
                    stacks[1] = 0;
                    stacks[0] -= m;
                    cout << "TAKE 1 " << m << "\n";
                }
            }
        }
        cin >> n >> ws;
        if (n)
            cout << "\n";
    }
    
    

}

```