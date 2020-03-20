# Day 27 Code

```cpp
#include <bits/stdc++.h> 

using namespace std;

int questions [100][9];
int participants [100][2];

void initialize ()
{
    int i,j;

    for (i = 0; i < 100; i ++)
    {
        participants [i][1] = -1;
        participants [i][2] = -1;
    }

    for (i = 0; i < 100; i ++)
        for (j = 0; j < 9; j ++)
            questions [i][j] = -1;
}

void add (int team, int problem, int time, char submission)
{
    switch (submission)
    {
    case 'C':
        participants [team - 1][0] = time;
        participants [team - 1][1] = questions [team - 1][problem - 1] + 1;
        break;
    case 'I':
        questions [team - 1][problem - 1] += 1;
        break;
    }
}

void print_results ()
{
    int i, min = INT_MAX, index_min;
    bool are_participants = true;
    while (are_participants)
    {
        for (i = 0; i < 100; i ++)
        {
            if (participants[i] >= 0 && participants[i][0] < min)
                index_min = i;
        }
        cout << index_min + 1 << " " << (participants[i][0] + participants[i][1] * 20);
    }
}

int main ()
{
    int n, i, j;
    string buffer;
    cin >> n;
    cin.ignore(256, '\n');
    cin.ignore(256, '\n');
    int team, problem, time;
    char sumbmission;
    while (n--)
    {
        initialize();
        while (getline(cin, buffer), buffer.size() != 0)
        {
            istringstream in (buffer);
            in >> team >> problem >> time >> sumbmission;
            add(team, problem, time, sumbmission);
        }
        print_results();
    }
    
}
```
    
    
    