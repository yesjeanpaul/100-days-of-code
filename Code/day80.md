# Day 80 Code

12356_Army_Buddies.cpp

```cpp

#include <bits/stdc++.h>

using namespace std;

int leftLink[100005], rightLink[100005];

void intialize (int upper_bound)
{
    for (int i = 1; i <= upper_bound; i++)
    {
        leftLink[i] = i - 1;
        rightLink[i] = i + 1;
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int S, B, L, R;
    cin >> S >> B;
    while (S || B)
    {
        intialize(S);
        while(B--)
        {
            cin >> L >> R;


            if (leftLink[L] < 1) cout << "* ";
            else cout << leftLink[L] << " ";

            if (rightLink[R] > S) cout << "*\n";
            else cout << rightLink[R] << "\n";

            leftLink[rightLink[R]] = leftLink[L];
            rightLink[leftLink[L]] = rightLink[R];
        }
        cout << "-\n";
        cin >> S >> B;
    }
}
```