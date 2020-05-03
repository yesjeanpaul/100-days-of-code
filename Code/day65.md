# Day 65 code 

wicharein.cpp

```cpp

#include <set>

class WhichAreIn
{

  public:
  static std::vector<std::string> inArray(std::vector<std::string> &array1, std::vector<std::string> &array2);
};

std::vector<std::string> WhichAreIn::inArray(std::vector<std::string> &array1, std::vector<std::string> &array2)
{
  std::set <std::string> answer;
  for (auto word1: array1)
  {
    int n = (int) word1.size();
    for (auto word2: array2)
    {
      for (int i = 0; i <= ((int)word2.size()) - n; i ++)
      {
        bool sub = true;
        
        for (int j = 0; j < n; j++)
          if (word1[j] != word2[j + i])
            sub = false;
        
        if (sub)
        {
          if (word1.size() < word2.size())
            answer.insert(word1);
          else
            answer.insert(word2);
        }
      }
    }
  }
  
  std::vector <std::string> v (answer.begin(), answer.end());
  return v;
}

``` 

isograms.cpp

```cpp
#include <bits/stdc++.h>

using namespace std;

bool is_isogram(std::string str) {
  map <char, int> count;
  for (auto &c : str)
    if (count[tolower(c)] ++ > 0)
      return false;
  return true;
}
```

multiples3or5.cpp

```cpp
int solution(int number) 
{
  //assert (number > 0);
  int n = 0;
  for (int i = 2; i < number; i++)
    if (i % 3 == 0 || i % 5 == 0)
      n += i;
  return n;
}
```