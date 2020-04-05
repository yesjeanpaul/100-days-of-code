# Day 41 Code

kattis_CollatzConjecture.cpp

```cpp

#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

bool isInsequence(map <long long int,long long int> &v, long long int &n)
{
    return v.find(n) != v.end();
}

int doOperation (long long int &n)
{
    return (n%2 == 0) ? n/2 : 3*n + 1;
}

/* TODO :

    - Try with a bitmask and after that get the result find the postion of the element

*/

int main ()
{
    long long int n,m;
    while (scanf("%lld %lld", &n, &m) == 2, n || m)
    {
        bool isInN, calculateNextN = true, calculateNextM = true;
        long long originalN = n, originalM = m;
        map <long long int, long long int> sequenceN, sequenceM;
        int i = 0, j = 0, steps;
        map <long long int,long long int>::iterator result;
        sequenceN[n] = i;
        sequenceM[m] = j;
        while (n!= 1 || m != 1)
        {

            if (calculateNextN)
            {
                i ++;
                n = doOperation(n);
                if (n == 1 || isInsequence(sequenceN, n))
                    calculateNextN = false;
                else
                    sequenceN[n] = i;
            }

            if (calculateNextM)
            {
                j ++;
                m = doOperation(m);
                if (m == 1 || isInsequence(sequenceM, m))
                    calculateNextM = false;
                else
                    sequenceM[m] = j;
            }
            
            result = sequenceN.find(m);
            if (result != sequenceN.end())
            {
                isInN = true;
                steps = result -> second;
                break;
            }
            result = sequenceM.find(n);
            if (result != sequenceM.end())
            {
                isInN = false;
                steps = result -> second;
                break;
            }
            
        }
        
        if (isInN)
            printf("%lld needs %d steps, %lld needs %d steps, they meet at %lld\n", 
                   originalN, steps, originalM, j, m);
        else
            printf("%lld needs %d steps, %lld needs %d steps, they meet at %lld\n", 
                   originalN, i, originalM, steps, n);
    }
}

```