# Day 51 Code

kattis_deduplicatingfiles.cpp

```cpp
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int calculate_hash (string &s)
{
    int r = 0;
    for (auto &c: s)  r ^= int(c);
    return r;
}

int main ()
{
    string s;
    int n;
    while(cin >> n)
    {
        if (!n) return 0;

        getline(cin, s);
        int mask = 0;
        long long  count = 0;
        unordered_map <string, int> M;
        unordered_map <int, int> hashes;
        while (n--)
        {
            getline(cin,s);
            mask = calculate_hash(s);

            M[s]++;
            hashes[mask]++;
            
            count += hashes[mask] - M[s];
        }

        cout << M.size() << " " << count << endl;
    }
}

```