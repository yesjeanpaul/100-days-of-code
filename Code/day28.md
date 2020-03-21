# Day 28 Code

```cpp
#include <bits/stdc++.h> 
#include <stdio.h>

using namespace std;

int questions [100][9];
int participants [100][3];


void initialize ()
{
    int i,j;

    for (i = 0; i < 100; i ++)
    {
        participants [i][0] = -1;
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
        participants [team - 1][0] += time;
        participants [team - 1][1] += questions [team - 1][problem - 1] + 1;
        participants [team - 1][2] ++;
        break;
    case 'I':
        questions [team - 1][problem - 1] ++;
        if (participants [team - 1][0] == -1)
        {
            participants [team - 1][0] = 0;
            participants [team - 1][1] = 1;
            participants [team - 1][2] = 0;
        }
        break;
    }
}

void print_results ()
{
    int i, min = INT_MAX, index, max = INT_MIN;
    bool are_participants = true;
    while (are_participants)
    {
        index = -1;
        for (i = 0; i < 100; i ++)
        {
            if (participants[i][0] >= 0 && participants[i][2] > max)
                index = i;
        }
        printf("%d %d %d\n", index + 1, participants[index][2] + 1, (participants[index][0] + 1) + 20 * participants[index][1]);
        participants [index][0] = -1;
        if (index == -1)
            are_participants = false;

    }   
}

class Participant
{
    public:
        int team_number, score, trials [10], good_answers;

    bool operator > (const Participant &p1)
    {
        if (good_answers > p1.good_answers)
            return true;
        else if (good_answers == p1.good_answers)
            return score > p1.score;
        else
            return false;
    }

};

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
        cout << endl;
    }
    
}
```
