# Day 59 Code

kattis_dream.cpp

```cpp

#include <bits/stdc++.h>

using namespace std;


int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map <string, int> events;
    set <string> es;
    vector <string> tmp, v;
    int n, size = 0;
    string e;
    char action;
    cin >> n;
    while (n--)
    {
        tmp.clear();
        cin >> action;
        if (action == 'E')
        {
            cin >> e;
            events[e] = size;
            es.insert(e);
            v.push_back(e);
            size ++;
        }
        else if (action == 'S')
        {
            int i;
            cin >> i;
            int dream = -1;
            bool valid = true;
            while (i--)
            {
                cin >> e;
                if (e[0] == '!')
                {
                    e = e.substr(1);
                    if (events.find(e) != events.end())
                        dream = std::max(dream, size - events[e]);

                }
                else
                {
                    if (events.find(e) == events.end())
                        valid = false;
                    else
                        tmp.push_back(e);
                }
            }
            //cout << dream << "\n";
            if (valid)
            {
                if (dream < 0)
                {
                    cout << "Yes\n";
                }
                else
                {
                    int cut = size - dream;
                    bool valid2 = true;
                    for (auto &x: tmp)
                    {
                        if (events[x] >= cut)
                        {
                            valid2 = false;
                            break;
                        }
                    }
                    if (valid2) 
                        cout << dream << " Just A Dream\n";
                    else
                        cout << "Plot Error\n";
                }                
            }

            else
            {
                cout << "Plot Error\n";
            } 
            
        }
        else if (action == 'D')
        {
            int d;
            cin >> d;
            //cout << "D " << d << " ";
            //cout << size - d << "\n" ;
            while (d--)
            {
                events.erase(v[size - 1]);
                v.pop_back();
                size --;
            }
        }
        /*for (auto &x: events)
          cout << x.first << " " << x.second << "\n";
        cout << "--------------\n";
        for (auto &x: v)
            cout << x << " ";
        cout << "\n--------------\n";*/
        


    }
    
}
```