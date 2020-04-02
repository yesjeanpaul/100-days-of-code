# Day 35 Code

```cpp

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
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
        //cout << "Element alone " << v.at(0) << endl;
        return v;
    }
    else
    {
        int n = v.size()/2;
        vector <int> v1(v.begin(), v.begin() + n);
        vector <int> v2(v.begin() + n + 1 , v.end());
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
        return merge(r1, r2);
    }
    
}*/


void merge (vector <int> &v, int start, int middle, int end)
{
    vector <int> l;
    vector <int> r;

    

    for(int z = start; z <= middle; z ++)
    {
        l.push_back(v.at(z));   
    }

    for(int x = middle + 1; x <= end; x ++){
        r.push_back(v.at(x));
    }

    l.push_back(INT_MAX);
    r.push_back(INT_MAX);

    /*
    for (auto& a: l)
        cout << a << " ";
    cout << endl;
    
    for (auto& a: r)
        cout << a << " ";
    cout << endl;
    */
    int i = 0, j = 0;
    for (int k = start; k <= end; k ++)
    {
        if (l.at(i) <= r.at(j))
        {
            v[k] = l.at(i);
            i++;
        }
        else
        {
            v[k] = r.at(j);
            j ++;
        }
    }
}

void mergeSort (vector <int> &v, int start, int end)
{

    if (start < end)
    {
        int middle =  (end + start)/2;
        mergeSort(v, start, middle);
        mergeSort(v, middle + 1, end);
        merge(v, start, middle, end);
        //cout << "start: " << start << " middle: " << middle << " end: " << end << endl;
       // for (auto& p: v)
         //   cout << p << " ";
        //cout << endl;
    }
}


int main ()
{
    vector <int> v;
    for (int i = 0; i < 100; i++)
        v.push_back( (rand() % 1000) + 1);
    
    for (auto& p: v)
        cout << p << " ";

//    cout << endl;

    vector <int> a {6, 1 ,2, 5};
    


    mergeSort(v, 0, v.size() - 1);

    cout << endl;
    for (auto& p: v)
        cout << p << " ";
    cout << endl;


    /*
    vector <int> c {1, 4, 7, 5, 6, 0, 8, 9, 10};
    for (auto& p: c)
        cout << p << " ";
    cout << endl;
    vector <int> d = mergeSort(c);
    
    for (auto& p: d)
        cout << p << " ";
    cout << endl;
    */
    /*vector <int> e = mergeSort(v);
    for (auto& p: e)
        cout << p << " ";
    cout << endl;*/

}

```