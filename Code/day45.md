# Day 45 Code

```cpp
#include <bits/stdc++.h>

using namespace std;

int table[9][9];

bool check_number_in_square(int number, int start_row, int start_column)
{
    for (int i = start_row; i < start_row + 3; i++)
    {
        for (int j = start_column; j < start_column + 3; j++)
        {
            if (table[i][j] == number)
            {
                return true;
            }
        }
    }
    return false;
}

int main ()
{
    string line;
    bool posibilities [10][2][9];
    /*
        9: digits
        {0,1}: 0 -> rows 1 -> columns
        1: save is full or not
        9: digits
    */
    

    for (int i = 0; i < 10; i ++)
        for (int j = 0; j < 2; j++)
            for (int z = 0; z < 9; z++)
                posibilities [i][j][z] = false;
    
    int r_i = 0,c_j,d;
    while(getline(cin, line))
    {
        c_j = 0;
        for (auto &c: line)
        {
            if (c != '.')
            {
                d = c - '0';
                table[r_i][c_j] = d;
                posibilities[d][0][r_i] = true;
                posibilities[d][1][c_j] = true;
            }
            else
                table[r_i][c_j] = -1;
            c_j ++;
        }
        r_i ++;
    }
    
    bool changes = false;
    while (!changes)
    {
        changes = false;
        for (int digit = 1; digit < 10; digit++)
        {
            for(int r = 0; r < 9; r += 3)
            {
                for(int c = 0; c < 9; c += 3)
                {
                    vector <int> possible_rows;
                    vector <int> possible_columns;

                    for (int i = r; i < r + 3; i++)
                    {
                        if (!posibilities[digit][0][i])
                            possible_rows.push_back(i);
                    }

                    for (int j = c; j < c + 3; j++)
                    {
                        if (!posibilities[digit][1][j])
                            possible_columns.push_back(j);
                    }

                    if (check_number_in_square(digit, r, c))
                    {
                        continue;
                    }

                    if (possible_rows.size() == 0 && 
                        possible_columns.size() == 0)
                    {
                        continue;
                    }
                    else if (possible_rows.size() == 1 && 
                        possible_columns.size() == 1)
                    {
                        posibilities[digit][0][possible_rows.front()] = true;
                        posibilities[digit][1][possible_columns.front()] = true;
                        table[possible_rows.front()][possible_columns.front()] = digit;
                        cout << digit << " " << possible_rows.front() << " " << possible_columns.front() << " ps" << endl;
                        changes = true;
                        continue;
                    }

                    bool is_one_chance = false;
                    int row, column;
                    for (auto& i: possible_rows)
                    {
                        for (auto &j: possible_columns)
                        {
                            if (table[i][j] == -1 && !is_one_chance)
                            {
                                is_one_chance = true;
                                row = i;
                                column = j;
                            }
                            else if (table[i][j] == -1 && is_one_chance)
                            {
                                is_one_chance = false;
                                break;
                            }                        
                        }
                    }

                    if (!is_one_chance)
                        continue;
                    else
                    {
                        posibilities[digit][0][row] = true;
                        posibilities[digit][1][column] = true;
                        table[row][column] = digit;
                        changes = true;
                        cout << digit << " " << row << " " << column <<  " s" << endl;
                        cout << "possible rows ";
                        for (auto &x: possible_rows)
                        {
                            cout << x << " ";
                        }
                        cout << endl;
                        cout << "possible columns ";
                        for (auto &x: possible_columns)
                        {
                            cout << x << " ";
                        }
                        cout << endl;
                    }

                }
            }

        }
        /*
        for (int i = 0; i < 9; i++)
        {
            int con = 0;
            bool numbers[10];
            for (int x = 1; x < 10; x++)
            {
                numbers[x] = false;
            }
            int row, column;
            for (int j = 0; j < 9; j++)
            {
                int number = table[i][j];
                if (number == -1)
                {   
                    row = i;
                    column = j;
                }
                else
                {
                    numbers[number] = true;
                    con ++; 
                }
            }
            if (con == 8)
            {
                changes = true;
                for (int z = 1; z < 10; z++)
                {
                    if (!numbers[z])
                    {
                        table[row][column] = z;
                        posibilities[z][0][row] = true;
                        posibilities[z][1][column] = true;
                    }

                }
            }
        }
        for (int j = 0; j < 9; j++)
        {
            int con = 0;
            bool numbers[10];
            for (int x = 1; x < 10; x++)
            {
                numbers[x] = false;
            }
            int row, column;
            for (int i = 0; i < 9; i++)
            {
                int number = table[i][j];
                if (number == -1)
                {   
                    row = i;
                    column = j;
                }
                else
                {
                    numbers[number] = true;
                    con ++; 
                }
            }
            if (con == 8)
            {
                changes = true;
                for (int z = 1; z < 10; z++)
                {
                    if (!numbers[z])
                    {
                        table[row][column] = z;
                        posibilities[z][0][row] = true;
                        posibilities[z][1][column] = true;
                    }

                }
            }
        }*/

    }


    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            if (table[i][j] != -1)
                cout << table[i][j];
            else
                cout << ".";
        cout << endl;
    }
   






}
```