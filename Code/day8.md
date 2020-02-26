# Day 8 Code

two_fer.h
```cpp
#if !defined(TWO_FER_H)
#define TWO_FER_H
#include <string>

using namespace std;

namespace two_fer
{
    string two_fer(const string &name = "you");
} // namespace two_fer

#endif //TWO_FER_H
```

two_fer.cpp
```cpp
#include "two_fer.h"


namespace two_fer
{

    string two_fer(const string &name)
    {
        return "One for " + name + ", one for me.";
    }
} // namespace two_fer
```

Vowel Count

```cpp
#include <string>

using namespace std;

int getCount(const string& inputStr){
  int num_vowels = 0, i;
  for (i = 0; i < inputStr.size(); i++)
    if (inputStr[i] == 'a' ||
        inputStr[i] == 'e' ||
        inputStr[i] == 'i' ||
        inputStr[i] == 'o' ||
        inputStr[i] == 'u')
        num_vowels ++;
  return num_vowels;
  
}
```

Find next perfect square

```cpp
#include <math.h>
long int findNextSquare(long int sq) {
  float result = sqrt(sq);
  if (ceil(result) == floor(result))
    return pow((int)(result + 1), 2.0);
  return -1;
}
```