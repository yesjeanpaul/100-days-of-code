# Day 48 Code

kattis_cross.cpp

```cpp

# include <bits/stdc++.h>

using namespace std;

char board [9][10];

bool cross (int n)
{
    bool change = false;

    int rows[9] = {0}, columns[9] = {0}, block [3][3] {{0}};

    for (int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            if (board[i][j] == '0' + n)
            {
                if (rows[i]++ > 0) throw 1;
                if (columns[j]++ > 0) throw 1;
                if (block[i/3][j/3]++ > 0) throw 1;
            }
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3;++j)
        {
            if (block[i][j]) continue;

            vector <pair <int, int>> spaces;
            for (int r = 0; r < 3; ++r)
            {
                for (int c = 0; c < 3; ++c)
                {
                    if(board[3*i+r][3*j+c] == '.' &&
                        !rows[3*i+r] && !columns[3*j+c])
                            spaces.push_back(make_pair(3*i+r,3*j+c));
                }
            }
            if (spaces.empty()) throw 1;
            if (spaces.size() == 1)
            {
                int row = spaces[0].first, column = spaces[0].second;
                board[row][column] = '0' + n;
                rows[row] = columns[column] = block[i][j] = 1;
                change = true;
            }
        }
        
    }
    return change;
    
}

int main()
{
    for (int i = 0; i < 9; i++) cin >> board[i];
    
    try
    {
        for (;;)
        {
            bool change = true;
            for (int i = 1; i <= 9; ++i)
                change &= !cross(i);
            if (change)
                break;
        }
    }
    catch (...)
    {
        cout << "ERROR";
        return 0;
    }

    for (int i = 0; i < 9; i++) cout << board[i] << endl;

}

```