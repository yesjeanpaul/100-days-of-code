# Day 44 code

 ```cpp

 #include <bits/stdc++.h>

using namespace std;

/* TODO:
    - Fix the comprobation of the interval, is bad
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
            for (int i = z; i < z + 3; i++)
            {
                for (int j = x; j < x + 3; j++)
                {
                    if (table[i][j] == -1)
                    {
                        continue;
                    }
                    else if (!solvable.count(table[i][j]))
                        solvable.insert(table[i][j]);
                    else                    
                    {
                        cout << "Value is " << table[i][j] << " and i, j " <<i << " " << j << endl;  
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
            if (table[i][j] == -1)
            {
                continue;
            }
            else if (!solvable.count(table[i][j])) 
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
            if (table[i][j] == -1)
            {
                continue;
            }
            else if (!solvable.count(table[i][j]))
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

void index (set <int> &set, int start)
{
    for (int i = 0; i < 3; i ++)
        set.insert(start + i);
}


bool fill_spaces (int number, vector <numbers> &v, vector <vector <pair <int,int>>> &p)
{
    bool change = false;
    for (int z = 0; z < 9; z += 3)
    {
        for (int x = 0; x < 9; x+= 3)
        {
            bool isInSquare = false;
            set <int> possibles_rows, possibles_columns;
            set <int> finded_rows, finded_columns;
            index(possibles_rows,z);
            index(possibles_columns,x);
            for (auto &e: p.at(number))
            {
                if (e.first >= z && e.first <= z + 3)
                {
                    finded_rows.insert(e.first);
                }
                if (e.second >= x && e.second <= x + 3)
                {
                    finded_columns.insert(e.second);
                }
                if (e.first >= z && e.first <= z + 3 &&
                    e.second >= x && e.second <= x + 3)
                {
                    isInSquare = true;
                    break;
                }

            }
            
           // cout << "z " << z << "x " << x << endl;

            if (isInSquare)
                continue;

            
            vector <int> difference_columns, difference_rows;
            
            set_difference(possibles_columns.begin(), possibles_columns.end(), 
                           finded_columns.begin(), finded_columns.end(), 
                           inserter(difference_columns, difference_columns.end()));

            set_difference(possibles_rows.begin(), possibles_rows.end(), 
                           finded_rows.begin(), finded_rows.end(), 
                           inserter(difference_rows, difference_rows.end()));
            
            vector <pair <int, int>> posibilities;
            /*cout << "z is " << z;
            cout << " x is " << x << endl;
            cout << "finded_rows ";
            for (auto &e: finded_rows)
                cout << e << " ";
            cout << endl;
            cout << "finded_columns ";
            for (auto &e: finded_columns)
                cout << e << " ";
            cout << endl;
            cout << "difference_rows ";
            for (auto &e: difference_rows)
                cout << e << " ";
            cout << endl;
            cout << "difference_columns ";
            for (auto &e: difference_columns)
                cout << e << " ";
            cout << endl;
            */
            if (difference_rows.size() != 1 || difference_columns.size() != 1)
            {
                for (int i = 0; i < difference_rows.size(); i++)
                {
                    for (int j = 0; j < difference_columns.size(); j++)
                    {
                        if (table[difference_rows.at(i)][difference_columns.at(j)]  == -1)
                        {
                            posibilities.push_back(make_pair(difference_rows.at(i), difference_columns.at(j)));
                        }
                    }

                }
                if (posibilities.size() == 1)
                {
                    int i = posibilities.front().first;
                    int j = posibilities.front().second;
                    table[i][j] = number;
                    change = true;
                }
            }
            else
            {
                int i = difference_columns.front();
                int j = difference_rows.front();
                table[i][j] = number;
                change = true;
            }

        }
    }
    return change;
   // v[number].completed = p.at(number).size() == 9;
}



int main ()
{
    set <int> digits;
    vector <vector <pair <int,int>>> positions (10);
    string input;
    int i = 0, j, digit;
    while(getline(cin, input))
    {
        j = 0;
        for (auto &c: input)
        {
            //cout << input << endl;
            if (c != '.')
            {
                digit = c - '0';
                table[i][j] = digit;
                //cout << digit << endl;
                digits.insert(digit);
                positions.at(digit).push_back(make_pair(i,j));
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

    for (auto &i:digits)
        visited.push_back(numbers(i, positions[i].size() == 9));
    
    bool changes = true;
    while (changes)
    {
        changes = false;
        for (auto &i: visited)
            if (!i.completed)
                fill_spaces(i.number, visited, positions);
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

    vector <int> a;
    *a.rend();
    
}


```