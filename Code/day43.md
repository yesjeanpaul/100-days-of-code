# Day 43 Code

kattis_cross.cpp

```cpp
#include <bits/stdc++.h>

using namespace std;

/* TODO:
    - End fill spaces
    - When go trough the matrix change index j = z, j < z + 3
*/



class numbers
{
    public:
        int number;
        bool visited;
        bool completed;
        numbers(int n, bool c)
        {
            number = n;
            visited = false;
            completed = c;
        }
};





int table [9][9];

bool solvable ()
{
    set <int> solvable;
    for (int z = 0; z < 9; z += 3)
    {
        for (int x = 0; x < 9; x+= 3)
        {
            for (int i = x; i < x + 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (solvable.find(table[i][j]) != solvable.end())
                        solvable.insert(table[i][j]);
                    else
                    {
                        cout << ("ERROR") << endl;
                        return false;
                    }
                }
            }
            solvable.clear();
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (solvable.find(table[i][j]) != solvable.end())
                    solvable.insert(table[i][j]);
            else
            {
                cout << ("ERROR") << endl;
                return false;
            }
            
        }
        solvable.clear();
    }

    for (int j = 0; j < 9; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            if (solvable.find(table[i][j]) != solvable.end())
                    solvable.insert(table[i][j]);
            else
            {
                cout << ("ERROR") << endl;
                return false;
            }
            
        }
        solvable.clear();
    }


    return true;
}



void fill_spaces (int number, vector <numbers> &v, vector <pair <int, int>> p)
{

    for (int z = 0; z < 9; z += 3)
    {
        for (int x = 0; x < 9; x+= 3)
        {
               if (i >= e.first && i <= e.first)
                if (j >= e.second && j <= e.second)
            for (int i = x; i < x + 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    for (auto&e: p)
                    {
                     


                    }



                }
            }
            


        }
    }

}



int main ()
{
    set <int> digits;
    vector <pair <int, int>> postions [10];
    string input;
    int i = 0, j = 0, digit;
    while(getline(cin, input))
    {
        j = 0;
        for (auto &c: input)
        {
            if (c != '.')
            {
                digit = c - '0';
                table[i][j] = digit;
                digits.insert(digit);
                postions[i].push_back(make_pair(i,j));
            }
            else
                table[i][j] = -1;
            j++;
        }
        i ++;
    }
    
    //check if is solvable 
    if (!solvable())
        return 0;
    
    vector <numbers> visited;
    for (int i = 1; i < 10; i++)
        visited.push_back(numbers(i, postions[i].size() == 9));
    


    /*for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << table[i][j] << " ";
        cout << endl;
    }*/
    
}

```