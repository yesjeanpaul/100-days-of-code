# Day 26

12356_Army_Buddies.cpp

```cpp
#include <iostream>
#include <vector>

using namespace std;

vector <int> v;
int B,S;


void print_result (int left_boundary, int right_boundary)
{
    int index, i;
    for (i = 0; i < v.size(); i++)
    {
        if (v.at(i) == left_boundary)
        {
            index = i;
            break;
        }
    }
    
    for (i = 0; i <= right_boundary - left_boundary; i ++)
        v.erase(v.begin() + index);
    
    if (index - 1 == -1)
        cout << "* ";
    else if (index - 1 <= v.size() - 1)
        cout << v.at(index-1) << " ";
    else
        cout << "* ";
    
    if (index < v.size())
        cout << v.at(index) << endl;
    else
        cout << "*" << endl;
}



int main ()
{
    int L,R,i;
    while (cin >> S, cin >> B, S != 0, B != 0)
    {
        for (i = 1; i <= S; i ++)
            v.push_back(i);
        for (i = 0; i < B; i ++)
        {
            cin >> L;
            cin >> R;
            print_result(L,R);
        }
        cout << "-" << endl;
        v.clear();
    }
    
}
```