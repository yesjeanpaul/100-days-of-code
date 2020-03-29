# Day 34 code

mergesort.cpp

```cpp
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;


vector <int> merge (vector <int> a, vector <int> b)
{
    vector <int> sorted;
    a.push_back(INT_MAX);
    b.push_back(INT_MAX);
    int i = 0, j = 0, num1, num2;
    while(i != a.size() - 1 || j != a.size() - 1)
    {
        num1 = a.at(i), num2 = b.at(j);
        if (num1 < num2)
        {
            sorted.push_back(num1);
            i ++;
        }
        else
        {
            sorted.push_back(num2);
            j ++;
        }
    }
    return sorted;
}

vector <int> mergeSort (vector <int> v)
{
    cout << "Size: " << v.size() << endl;
    if (v.size() == 1)
    {
        cout << "Element alone " << v.at(0) << endl;
        return v;
    }
    else
    {
        int n = v.size()/2;
        vector <int> v1(v.begin(), v.begin() + n);
        vector <int> v2(v.begin() + n , v.end());
        cout << "v1 ";
        for (auto& p: v1)
            cout << p << " ";
        cout << endl;

        cout << "v2 ";
        for (auto& p: v2)
            cout << p << " ";
        cout << endl;
        vector <int> r1 = mergeSort(v1);
        vector <int> r2 = mergeSort(v2);
        return r1;
    }
    
}

int main ()
{
    vector <int> v;
    for (int i = 0; i < 100; i++)
        v.push_back( (rand() % 1000) + 1);
    
    for (auto& p: v)
        cout << p << " ";

    cout << endl;

    vector <int> a {1, 2, 5, 6};
    vector <int> b {3, 4, 8, 9};
    vector <int> r = merge(a,b);

    for (auto& p: r)
        cout << p << " ";
    cout << endl;

    vector <int> c {1, 4, 7, 5, 6, 0, 8, 9};
    for (auto& p: c)
        cout << p << " ";
    cout << endl;
    mergeSort(c);

}
```