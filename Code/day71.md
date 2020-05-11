# Day 71 Code

codeforces_contest_640_div_4_a.cpp

```cpp
#include <bits/stdc++.h>
#include <math.h> 
//#define DEBUG

using namespace std;

int main ()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef DEBUG
        freopen("in.txt","r",stdin);
    #endif
    int t, n, d, acu;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector <int> v;
        acu = 1;
        while (n)
        {
            d = n % 10;
            if (d)
                v.push_back(acu * d);
            n /= 10;
            acu *= 10;
        }
        cout << v.size() << "\n";
        for (auto &x: v)
            cout << x << " ";
        cout << "\n";
        
    }
    /*
    while(a)
    {
        cout << a % 10 << "\n";
        a /= 10;
    }*/
}
```

codeforces_contest_640_div_4_c.cpp

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
    int t, n, k;
    cin >> t;
    while (t--) 
    {
        cin >> n >> k;
        int c = k/(n-1);
        if (k % (n-1))
        {
            cout << c * (n-1) + c + (k%(n-1)) << "\n";
        }
        else
        {
            cout << c*(n-1) + (c-1) << "\n";
        }
        

    }

}
```

codeforces_contest_640_div_4_d.cpp

```cpp
#include <bits/stdc++.h>
#define DEBUG

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef DEBUG
        freopen("in.txt","r",stdin);
    #endif
    int t, n, w;
    cin >> t;
    while (t--)
    {
        cin >> n;
        deque <int> v;
        while (n--)
        {
            cin >> w;
            v.push_back(w);
        }
        bool possible = true, ana = true;
        int prev_ate = 0, a = 0, b = 0, con = 0;
        while (possible && !v.empty())
        {
            int sum = 0;
            if (ana)
            {
                while (!v.empty())
                {
                    sum += (*v.begin());
                    v.pop_front();
                    if (sum > prev_ate)
                    {
                        prev_ate = sum;
                        a += sum;
                        con ++;
                        break;
                    }
                }
                if (sum < prev_ate)
                {
                    con ++;
                    a += sum;
                }
                ana = false;
            }
            else
            {
                while (!v.empty())
                {
                    sum += (*v.rbegin());
                    v.pop_back();
                    if (sum > prev_ate)
                    {
                        prev_ate = sum;
                        b += sum;
                        con ++;
                        break;
                    }
                }
                 if (sum < prev_ate)
                {
                    con ++;
                    b += sum;
                }
                ana = true;
            }
        }

        cout << con << " " << a << " " << b << "\n";

    }
}
```