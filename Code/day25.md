# Day 25 Code 

12356_Army_Buddies.cpp

```cpp
#include <iostream>

int B,S;

using namespace std;

int search_right (int start, bool *soilders)
{
    for (int i = start; i < S; i++)
        if (soilders [i])
            return i + 1;
    return -1;
}

int search_left (int start, bool *soilders)
{
    for (int i = start; i >= 0; i--)
        if (soilders [i])
            return i + 1;
    return -1;
}

int main ()
{
    int L,R,i,left_result,right_result,j;
    while (cin >> S, cin >> B, S != 0, B != 0)
    {
        bool soilders [S];
        for (i = 0; i < S; i ++)
            soilders[i] = true;
        
        for (i = 0; i < B; i ++)
        {
            cin >> L;
            cin >> R;
            for (j = L - 1; j <= R - 1; j ++)
                soilders[j] = false;

            left_result = search_left(L - 1, soilders);
            right_result = search_right(R - 1, soilders);
            
            if (left_result != -1)
                cout << left_result << " ";
            else
                cout << "* ";

            if (right_result != -1)
                cout << right_result << endl;
            else
                cout << "*" << endl;
        }
        cout << "-" << endl;
    }
    
}
```