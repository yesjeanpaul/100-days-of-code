# Day 78 code

11496_Musical_Loop.cpp

```cpp

#include <bits/stdc++.h>
//#define DEBUG

using namespace std;

void calculate_derivates (vector <int> &v, vector <int> &derivates)
{
    derivates.push_back(v.front() - v.back());
    for (int i = 0; i < (int) v.size() - 1; i++)
    {
        derivates.push_back(v[i + 1]  - v[i] );
    }
    derivates.push_back(v.front() - v.back());
}

int number_peaks (vector <int> &v)
{
    int con = 0, prev = v.front(); 
    for (int i = 1; i < (int) v.size(); i++)
    {
        if ( (prev > 0 && v[i] < 0)  || (prev < 0 && v[i] > 0) )
            con ++;
        prev = v[i];
    }
    return con;
}


int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef DEBUG
        freopen("in.txt","r",stdin);
    #endif
    int n, h;
    vector <int> magnitudes, derivates;
    while (true)
    {
        cin >> n;
        if (!n) return 0;
        while (n--)
        {
            cin >> h;
            magnitudes.push_back(h);
        }
        calculate_derivates(magnitudes, derivates);
        /*for (auto &x: derivates)
            cout << x << " ";
        cout << "\n";*/
        cout << number_peaks(derivates) << "\n";
        magnitudes.clear();
        derivates.clear();
        

    }
}
```