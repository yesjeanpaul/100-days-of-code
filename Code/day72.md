# Day 72 Code

11044_Searching_for_nessy.cpp

```cpp

#include <bits/stdc++.h>

using namespace std;

int get_number_of_radars_per_direction (int n)
{
    return n % 3 == 0 ? n/3 : (n/3) + 1;
}



int main ()
{
    int N,n,m, i;
    cin >> N;
    while (N --)
    {
        cin >> n >> m;
        printf("%d\n", get_number_of_radars_per_direction(n - 2) * get_number_of_radars_per_direction(m - 2));
    }
    
}
```

11364_Optimal_parking.cpp

```cpp
#include <bits/stdc++.h>

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
}
``` 

11547_Automatic_Answer.cpp

```cpp
#include <bits/stdc++.h>
//#define DEBUG

using namespace std;

int main ()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef DEBUG
        freopen("in.txt","r",stdin);
    #endif
    int t;
    long long n, result;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        result = (((((n*567)/9)+7492)*235)/47)-498;
        //cout << result << "\n";
        if (result > (long long) 9 || result < (long long) -9)
            cout << abs((result/10)%10) << "\n";
    }
    
}
```

12250_Language_Detection.cpp

```cpp

#include <bits/stdc++.h>
//#define DEBUG

using namespace std;

string get_country (string s)
{
    if (s == "HELLO")
        return "ENGLISH";
    else if (s == "HOLA")
        return "SPANISH";
    else if (s == "HALLO")
        return "GERMAN";
    else if (s == "BONJOUR")
        return "FRENCH";
    else if (s == "CIAO")
        return "ITALIAN";
    else if (s == "ZDRAVSTVUJTE")
        return "RUSSIAN";
    else
        return "UNKNOWN";
}

int main ()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef DEBUG
        freopen("in.txt","r",stdin);
    #endif
    string s;
    int con = 1;
    cin >> s;
    while (s != "#")
    {
        cout << "Case " << con << ": " << get_country(s) << "\n";
        cin >> s;
        con ++;
    }
    
}
```