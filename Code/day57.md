# Day 57 Code

kattis_dream.cpp

```cpp
#include <bits/stdc++.h>

using namespace std;


int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map <string, int> events;
    vector <string> v;
    int n;
    string line, action;
    stringstream ss;
    cin >> n >> ws;
    while (n--)
    {
        getline(cin, line);
        ss << line;
        ss >> action;
        if (action == "E")
        {
            string e;
            ss >> e;
            //cout << "E " << e << "\n" ;
            int i = events.size() + 1;
            events[e] = i;
            v.push_back(e);
            
        }
        else if (action == "S")
        {
            int i, max = 0;
            int con = events.size();
            bool is_a_dream = false;
            string e;
            ss >> i;
            while (i--)
            {
                ss >> e;
                if (e.at(0) == '!')
                {
                    con --;
                    continue;  
                } 
                if (events.find(e) != events.end()) 
                {
                    if (events[e] == con && max == 0)
                    {
                        con --;
                    }
                    else
                    {
                        max = (events[e] > max) ? events[e] : max;
                        //Un bug podría ser que el max esta antes de fallar la busqueda
                    }
                    
                }
                else
                {
                    is_a_dream = true;
                    break;
                }
            }
            if (is_a_dream)
                cout << "Plot Error\n";
            else if (max == 0)
                cout << "Yes\n";
            else
                cout << events.size() - max << " Just A Dream\n";
        }
        else if (action == "D")
        {
            int d, size = (int) v.size();
            ss >> d;
            //cout << "D " << d << " ";
            //cout << size - d << "\n" ;
            for (int i = size - 1; i >= size - d; i--)
            {
                events.erase(v[i]);
                v.pop_back();
            }
        }
        ss.clear();
        /*for (auto &x: events)
            cout << x.first << " " << x.second << "\n";
        cout << "--------------\n";
        for (auto &x: v)
            cout << x << " ";
        cout << "\n--------------\n";*/
        


    }
    
}
```