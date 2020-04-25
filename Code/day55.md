# Day 55 Code

kattis_addingwords.cpp

```cpp
#include <bits/stdc++.h>

using namespace std;


int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string command, action, args, name;
    map <string, int> definitions;
    map <int, string> results;
    int value, result;
    
    while (getline(cin, command))
    {
        stringstream ss (command);
        ss >> action;
        if (action == "def")
        {
            ss >> name >> value;
            if (definitions.find(name) != definitions.end())
            {
                int i = definitions[name];
                definitions.erase(name);
                results.erase(i);
            }
            

            definitions[name] = value;
            results[value] = name;
        }
        else if (action == "calc")
        {
            stringstream out (command);
            string sign, s;
            result = 0;
            ss >> name;

            if(definitions.find(name) != definitions.end())
                result += definitions[name];
            else
                result = INT_MIN;

            while (ss >> sign)
            {
                if (sign == "=")
                    break;
                ss >> name;
                if(definitions.find(name) != definitions.end()
                    && result != INT_MIN && sign == "+")
                    result += definitions[name];
                else if(definitions.find(name) != definitions.end()
                    && result != INT_MIN && sign == "-")
                    result -= definitions[name];
                else
                    result = INT_MIN;
            }
            out >> action;
            while (out >> s)
                cout << s << " ";
            if (result != INT_MIN && results.find(result) != results.end())
                cout << results[result] << "\n";
            else
                cout << "unknown" << "\n";
        }
        else if (action == "clear")
        {
            definitions.clear();
            results.clear();
        }

        /*for (auto &x: definitions)    
            cout << x.first << " " << x.second << "\n";*/
    }
    
    
    

}
```