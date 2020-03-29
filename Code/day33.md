# Day 33 code

### Binary

binary.h

```cpp
#if !defined(BINARY_H)
#define BINARY_H
#include <bits/stdc++.h>
#include <exception>

using namespace std;


namespace binary {
    bool isbinary (string binary);
    int convert (string binary);

}  // namespace binary

#endif // BINARY_H
```

binary.cpp

```cpp
#include "binary.h"

namespace binary {
    bool isbinary (string binary)
    {
        for (auto& c: binary)
        {
            if (c != '1' && c != '0')
                return false;

        }

        return true;
    }
    int convert (string binary)
    {
        if (isbinary(binary))
            return stoi(binary, 0, 2);       
        else
            return 0;
    }
}  // namespace binary
```

### Scrabble score

scrabble_score.h

```cpp
#if !defined(SCRABBLE_SCORE_H)
#define SCRABBLE_SCORE_H

#include <bits/stdc++.h>

using namespace std;

namespace scrabble_score {
    int score(string word);
}  // namespace scrabble_score

#endif // SCRABBLE_SCORE_H
```

scrabble_score.cpp

```cpp
#include "scrabble_score.h"

namespace scrabble_score {
    vector <pair <vector <char>, int>>  values =
    {
        {{'A', 'E', 'I', 'O', 'U', 'L', 'N', 'R', 'S', 'T' }, 1},
        {{'D', 'G'}, 2},
        {{'B', 'C', 'M', 'P' }, 3},
        {{'F', 'H', 'V', 'W', 'Y' }, 4},
        {{'K'}, 5},
        {{'J', 'X'}, 8},
        {{'Q', 'Z'}, 10}
    };
    int score(string word)
    {
        string uppercase = word;
        transform(uppercase.begin(), uppercase.end(), uppercase.begin(), ::toupper);
        int total = 0;
        for (auto& c: uppercase)
        {
            for (auto& v: values)
            {
                if (find(v.first.begin(), v.first.end(), c) != v.first.end() )
                {
                    total += v.second;
                    break;
                }
                
            }
        }
        return total;
    }
}  // namespace scrabble_score
```
