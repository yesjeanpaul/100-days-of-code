# Day 42 file

kattis_CollatzConjecture.cpp

```cpp

#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;


void doOperation (long long &n)
{
    n = (n%2 == 0) ? n/2 : 3*n + 1;
}

int search (vector <long long> &v, long long &n)
{
    for (int i = 0; i < v.size(); i ++)
        if (v[i] == n)
            return i;
    return -1;
}

vector <long long> collatz (long long n)
{
    vector <long long> v;
    v.push_back(n);
    while (n != 1)
    {
        doOperation(n);
        v.push_back(n);
    }
    return v;
}


int main ()
{
    long long n,m;
    vector <long long> sequenceN, sequenceM;
    long long originalN = n, originalM = m;
    while (scanf("%lld %lld", &n, &m) == 2, n || m)
    {
        int result;
        originalN = n, originalM = m;
        sequenceN = collatz(n);
        sequenceM = collatz(m);
        int z;
        for (z = 0; z < sequenceN.size(); z++)
        {
            result = search(sequenceM, sequenceN[z]);
            if (result != -1)
                break;
        }

        
        
        
        printf("%llu needs %d steps, %llu needs %d steps, they meet at %llu\n", 
                originalN, z, originalM, result, sequenceN[z]);
    }
}
```