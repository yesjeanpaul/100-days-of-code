# Day 23

11364_Optimal_parking.cpp

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
    int t, n, i, j, distance, sum;
    vector <int> stores;
    cin >> t;
    for (i = 0; i < t; i ++)
    {
        sum = 0;
        cin >> n;
        for (j = 0; j < n; j++)
        {
            cin >> distance;
            stores.push_back(distance);
        }
        sort(stores.begin(), stores.end());
        for (j = 0; j < n-1; j ++)
            sum += (stores.at(j+1) - stores.at(j));
        sum += stores.at(n-1) - stores.at(0);
        cout << sum << endl;
        stores.clear();
    }
}```