# Day 29 Code

```cpp
#include <bits/stdc++.h> 
#include <stdio.h>

using namespace std;



//int questions [100][9];
//int participants [100][3];


//void initialize ()
//{
//    int i,j;
//
//    for (i = 0; i < 100; i ++)
//    {
//        participants [i][0] = -1;
//        participants [i][1] = -1;
//        participants [i][2] = -1;
//    }
//
//    for (i = 0; i < 100; i ++)
//        for (j = 0; j < 9; j ++)
//            questions [i][j] = -1;
//}
//
//void add (int team, int problem, int time, char submission)
//{
//    switch (submission)
//    {
//    case 'C':
//        participants [team - 1][0] += time;
//        participants [team - 1][1] += questions [team - 1][problem - 1] + 1;
//        participants [team - 1][2] ++;
//        break;
//    case 'I':
//        questions [team - 1][problem - 1] ++;
//        if (participants [team - 1][0] == -1)
//        {
//            participants [team - 1][0] = 0;
//            participants [team - 1][1] = 1;
//            participants [team - 1][2] = 0;
//        }
//        break;
//    }
//}
//
//void print_results ()
//{
//    int i, min = INT_MAX, index, max = INT_MIN;
//    bool are_participants = true;
//    while (are_participants)
//    {
//        index = -1;
//        for (i = 0; i < 100; i ++)
//        {
//            if (participants[i][0] >= 0 && participants[i][2] > max)
//                index = i;
//        }t
//        printf("%d %d %d\n", index + 1, participants[index][2] + 1, (participants[index][0] + 1) + 20 * participants[index][1]);
//        participants [index][0] = -1;
//        if (index == -1)
//            are_participants = false;
//
//    }   
//}

class Participant
{
    public:
        int team_number, score, trials [10], good_answers;


    Participant (int team_number)
    {
        this -> team_number = team_number;
        for (int i = 0; i < 10; i++)
        {
            trials[i] = 0;
        }
        this -> score = 0;
        this -> good_answers = 0;
    }

    bool operator > (const Participant &p1)
    {
        if (good_answers > p1.good_answers)
            return true;
        else if (good_answers == p1.good_answers)
            if (score == p1.score)
                return team_number < p1.team_number;
            else
                return score > p1.score;
        else
            return false;
    }
    
    bool operator < (const Participant &p1)
    {
        return !(this > &p1);
    }

    void increment (int time, int question)
    {
        this -> score += time;
        this -> score += (trials[question - 1])*20;
        this -> good_answers ++;
    }

    void bad_answer (int question)
    {
        trials[question - 1] ++;
    }

    void print ()
    {
        printf("%d %d %d\n", team_number, good_answers, score);
    }

};

vector <Participant> participants;

int get_index (int team)
{
    for (int i = 0; i < (int) participants.size(); i++)
        if (participants[i].team_number == team)
            return i;

    return -1;
}

void add (int team, int problem, int time, char submission)
{
    int index;
    switch (submission)
    {
    case 'C':
        index = get_index(team);
        if (index != -1)
            participants.at(index).increment(time, problem);
        else
        {
            participants.push_back(Participant(team));
            participants.at(participants.size() -1).increment(time, problem);
        }
        break;
    case 'I':
        index = get_index(team);
        if (index != -1)
            participants.at(index).bad_answer(problem);
        else
        {
            participants.push_back(Participant(team));
            participants.at(participants.size() -1).bad_answer(problem);

        }
    //Falta agregar los otros dos casos

    }
}

void initialize ()
{
    participants.clear();
}

void print_results ()
{
    sort(participants.begin(), participants.end());
    for (Participant& p: participants)
    {
        p.print();
    }
}

void debug ()
{
    for (Participant& p: participants)
    {
        cout << p.team_number << endl; 
        for (int i = 0; i < 10; i++)
        {
            cout << p.trials[i] << " ";
        }
        cout << endl;
        
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
        //debug();
        print_results();
        cout << endl;
    }
    
}
    
```