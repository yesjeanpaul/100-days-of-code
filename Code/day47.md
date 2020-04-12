# Day 47 Code

```cpp

#include <bits/stdc++.h>

using namespace std;


class Number
{
    public:
        int digit;
        vector <int> avaliable_rows, avaliable_columns, avaliable_squares;
        bool complete;

        Number (int n)
        {
            digit = n;
            for (int i = 0; i < 9; i++)
            {
                avaliable_rows.push_back(i);
                avaliable_columns.push_back(i);
                avaliable_squares.push_back(i);
            }
        }
        
        int get_index(vector <int> &v, int e)
        {
            vector <int>::iterator it = find(v.begin(), v.end(), e);
            if (it != v.end())
                return distance(v.begin(), it);
            else 
                return -1;
        }

        int search_row (int e)
        {
            return get_index(avaliable_rows, e);
        }

        int search_column (int e)
        {
            return get_index(avaliable_columns, e);
        }

        int search_square(int s)
        {
            return get_index(avaliable_squares, s);
        }

        bool avaliable_square(int s)
        {
            return get_index(avaliable_squares, s) != -1;
        }


        bool update (int i, int j)
        {
            int square = (i/3)*3 + (j/3), index_r, index_c, index_s;
            index_r = search_row(i);
            index_c = search_column(j);
            index_s = search_square(square);
            
            
            /*cout << digit << endl;
            cout << "avaliable_rows ";
            for (auto &r: avaliable_rows)
                cout << r << " ";
            cout << endl;
            cout << "avaliable_columns ";
            for (auto &r: avaliable_columns)
                cout << r << " ";
            cout << endl;
            cout << "avaliable_squares ";
            for (auto &r: avaliable_squares)
                cout << r << " ";
            cout << endl;

            cout << index_r << " " << index_c << " " << index_s << endl;*/
            
            if (index_r != -1 && index_c != - 1 && index_s != -1)
            {
                avaliable_rows.erase(avaliable_rows.begin() + index_r);
                avaliable_columns.erase(avaliable_columns.begin() + index_c);
                avaliable_squares.erase(avaliable_squares.begin() + index_s);
                return true;
            }
            else
                return false;
        }

        pair <vector <int>, vector <int>> avaliable_rows_and_columns_in_square (int s)
        {
            int initial_row = (s/3) , initial_column = s%3;
            initial_row *= 3;
            initial_column *= 3;
            vector <int> rows, columns;
            for (auto &e: avaliable_rows)
            {
                if (e >= initial_row && e < initial_row + 3)
                    rows.push_back(e);
            }
            for (auto &e: avaliable_columns)
            {
                if (e >= initial_column && e < initial_column + 3)
                    columns.push_back(e);
            }
            return make_pair(rows, columns);
        }
};

class Table
{
    public:
        vector <Number> numbers;
        int square [9][9];
        bool solvable;

        Table ()
        {
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++)
                    square[i][j] = -1;
            
            for (int i = 1; i < 10; i++)
                numbers.push_back(Number(i));
            
            solvable = true;
        }

        bool insert (int digit, int i, int j)
        {
            square[i][j] = digit;
            bool result =  numbers.at(digit - 1).update(i,j);
            if (!result)
                solvable = false;
            return result;
        }

        bool change_unique_possiblity (int digit, vector <int> rows, vector <int> columns)
        {
            /*cout << digit << endl;
            cout << "avaliable_rows ";
            for (auto &r: rows)
                cout << r << " ";
            cout << endl;
            cout << "avaliable_columns ";
            for (auto &r: columns)
                cout << r << " ";
            cout << endl;*/
            int row, column;
            bool unique_possibility = false;
            if (rows.size() == 1 && columns.size() == 1)
            {
                row = rows.front();
                column = columns.front();
                if (square[row][column] == -1)
                {
                    insert(digit, row, column);
                    return true;
                }
                else
                {
                    solvable = false;
                    return false;
                }
            }
            for (auto &i: rows)
            {
                for (auto&j: columns)
                {
                    if (square[i][j] == -1 && !unique_possibility)
                    {
                        unique_possibility = true;
                        row = i;
                        column = j;
                    }
                    else if (square[i][j] == -1 && unique_possibility)
                    {
                        return false;
                    }
                }
            }
            if (unique_possibility)
            {
                insert(digit,row,column);
                return true;
            }
            return false;
        }

        void print_table()
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                    if (square[i][j] != -1)
                        cout << square[i][j];
                    else
                        cout << ".";
                if (i != 8)
                    cout << endl;
            }
        }

        int rest_number (vector <int> &v)
        {
            vector <int> n = {1,2,3,4,5,6,7,8,9};
            vector <int> diff;
            set_difference(n.begin(), n.end(), 
                           v.begin(), v.end(),
                           inserter(diff, diff.begin()));
            return diff.front();
        }

        bool check_rows()
        {
            bool changes = false;
            int row, column;
            vector <int> founded_numbers;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (square[i][j] != - 1)
                    {
                        founded_numbers.push_back(square[i][j]);
                    }
                    else
                    {
                        row = i;
                        column = j;
                    }
                    
                }
                if (founded_numbers.size() == 8)
                {
                    int n = rest_number(founded_numbers);
                    //cout << n << endl;
                    insert(n , row, column);
                    if(!insert(n , row, column))
                        solvable = false;
                    else
                        changes = true;
                    //print_table();
                }
                founded_numbers.clear();
            }
            return changes;
        }


        bool check_columns()
        {
            bool changes = false;
            int row, column;
            vector <int> founded_numbers;
            for (int j = 0; j < 9; j++)
            {
                for (int i = 0; i < 9; i++)
                {
                    if (square[i][j] != - 1)
                    {
                        founded_numbers.push_back(square[i][j]);
                    }
                    else
                    {
                        row = i;
                        column = j;
                    }
                }
                if (founded_numbers.size() == 8)
                {
                    int n = rest_number(founded_numbers);
                    if(!insert(n , row, column))
                        solvable = false;
                    else
                        changes = true;
                }
                founded_numbers.clear();
            }
            return changes;
        }


        bool check_squares()
        {
            bool changes = false;
            int row, column;
            vector <int> founded_numbers;
            for (int z = 0; z < 9; z += 3)
            {
                for (int x = 0; x < 9; x += 3)
                {
                    for (int i = z; i < z + 3; i++)
                    {
                        for (int j = x; j < x + 3; j++)
                        {
                            if (square[i][j] != - 1)
                            {
                                founded_numbers.push_back(square[i][j]);
                            }
                            else
                            {
                                row = i;
                                column = j;
                            }
                        }
                        if (founded_numbers.size() == 8)
                        {
                            int n = rest_number(founded_numbers);
                            if(!insert(n , row, column))
                                solvable = false;
                            else
                                changes = true;
                        }
                        founded_numbers.clear();
                    }
                }
            }

            return changes;
        }

           
};

int main ()
{
    Table table;
    string input;
    int digit, i, j;
    while(getline(cin, input))
    {
        j = 0;
        for (auto &c: input)
        {
            if (c != '.')
            {
                digit = c - '0';
                //table.print_table();
                //cout << endl;
                table.insert(digit, i, j);
                /*if(!table.insert(digit, i, j))
                {
                    cout << "ERROR";
                    return 0;
                }*/
            }
            j++;
        }
        i ++;
    }
    //cout << "Im fine" << endl;
    if (!table.solvable)
    {
        cout << "ERROR";
        return 0;
    }
    bool change = true;
    while (change)
    {
        change = false;
        for (auto &n: table.numbers)
        {
            for (auto &s:n.avaliable_squares)
            {
                pair <vector <int>, vector <int>> p;
                p = n.avaliable_rows_and_columns_in_square(s);
                change = change || table.change_unique_possiblity(n.digit, p.first, p.second);
            }
        }
        change = change || table.check_columns();
        change = change || table.check_rows();
        change = change || table.check_squares();
        if (!table.solvable)
        {
            cout << "ERROR";
            return 0;
        }
    }
    table.print_table();
}

```