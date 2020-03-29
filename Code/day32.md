# Day 32 code

### Isogram

isogram.h

```cpp
#if !defined(ISOGRAM_H)
#define ISOGRAM_H

#include <bits/stdc++.h>

using namespace std;

namespace isogram {
    bool is_isogram (string word);

}  // namespace isogram

#endif // ISOGRAM_H
```

isogram.cpp

```cpp
#include "isogram.h"

namespace isogram {


    bool is_isogram (string word)
    {
        vector <char> ocurrencies;
        string lowercase_word = word;
        transform(lowercase_word.begin(), lowercase_word.end(), lowercase_word.begin(), ::tolower);
        for (auto &p : lowercase_word)
        {
            if (p == '-' || p == ' ')
                continue;
            else if (find(ocurrencies.begin(), ocurrencies.end(), p) != ocurrencies.end())
                return false;
            else
                ocurrencies.push_back(p);
        }
        return true;
    }

}  // namespace isogram
```

### difference of squares

difference_of_squares.h

```cpp

#if !defined(DIFFERENCE_OF_SQUARES_H)
#define DIFFERENCE_OF_SQUARES_H

namespace difference_of_squares {
    int square_of_sum(int n);
    int sum_of_squares (int n);
    int difference(int n);
}  // namespace difference_of_squares

#endif // DIFFERENCE_OF_SQUARES_H
```

difference_of_squares.cpp

```cpp
#include "difference_of_squares.h"

namespace difference_of_squares {
    int square_of_sum(int n)
    {
        return (n*(n+1))/2 * (n*(n+1))/2;
    }
    int sum_of_squares (int n)
    {
        return (n*(n+1)*(2*n+1))/6;
    }
    int difference(int n)
    {
        return square_of_sum(n) - sum_of_squares(n);
    }

}  // namespace difference_of_squares
```

### Leap

leap.h

```cpp
#if !defined(LEAP_H)
#define LEAP_H

namespace leap {
    bool is_leap_year(int year);
}  // namespace leap

#endif // LEAP_H
```

```cpp
#include "leap.h"

namespace leap {
    bool is_leap_year(int year)
    {
       if (year % 100 == 0 && year % 400 == 0)
            return true;
        else if (year % 100 == 0)
            return false;
        else if (year % 4 == 0)
            return true;
        else
            return false;
    }

}  // namespace leap
```

leap(2).cpp

```cpp
#include "leap.h"

namespace leap {
    bool is_leap_year(int year)
    {
        return (year % 100 == 0 && year % 400 == 0) ?  true 
        : (year % 100 == 0) ?  false : (year % 4 == 0) ? 
         true :  false;
    }

}  // namespace leap
```