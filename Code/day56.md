# Day 56 Code

kattis_dream.cpp

```cpp
#include <bits/stdc++.h>

using namespace std;


int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "Hello\n";
    unordered_map <string, int> events;
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
            int i = events.size() + 1;
            events[e] = i;
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
                if (events.find(e) != events.end()) 
                {
                    if (events[e] == con)
                    {
                        con --;
                    }
                    else
                    {
                        max = (events[e] > max) ? events[e] : max;
                    }
                    
                }
                else
                {
                    is_a_dream = true;
                    ss.clear();
                    break;
                }
            }
        }
        else if (action == "D")
    }
    
}

```