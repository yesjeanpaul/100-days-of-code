# Day 58 Code

kattis_dream.cpp

```cpp
#include <bits/stdc++.h>

using namespace std;


int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map <string, int> events;
    vector <string> v;
    int n, size = 0;
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
            events[e] = size;
            v.push_back(e);
            size ++;
            
        }
        else if (action == "S")
        {
            string e;
            int dream = size + 1, event = 0, i;
            bool plot_error = false;
            ss >> i;
            while (i--)
            {
                ss >> e;
                if (e.at(0) == '!')
                {
                    e = e.substr(1);
                    if (events.find(e) != events.end() && 
                        events[e] < dream)
                        dream = events[e];
                }
                else
                {
                    if (events.find(e) == events.end())
                    {
                        plot_error = true;
                        break;
                    }
                    if  (events[e] > event) event = events[e];

                }
                
            }
            //cout << dream << " " << event << "\n";
            if (dream == size + 1 && !plot_error) 
                cout << "Yes\n";
            else if (plot_error || dream <= event)
                cout << "Plot Error\n";
            else 
                cout << size - dream + 1 << " Just A Dream\n";
        }
        else if (action == "D")
        {
            int d;
            ss >> d;
            //cout << "D " << d << " ";
            //cout << size - d << "\n" ;
            while (d--)
            {
                events.erase(v[size - 1]);
                v.pop_back();
                size --;
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