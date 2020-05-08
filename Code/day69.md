# Day 69 Code 

code wars functions

```cpp

#include <math.h>

class Tortoise
{
public:
    static std::vector<int> race(int v1, int v2, int g){
      if (v1 >= v2) return std::vector <int> {-1, -1, -1};
      int t = (3600*g)/(v2 - v1);
      return std::vector <int> {t/3600, t/60 % 60, t % 60};
    }
};

unsigned int countBits(unsigned long long n){
  unsigned int con = 0;
  while (n & -n)
  {
    n -= (n & -n);
    con ++;
  }
  return con;
  
}

#include <string>

std::string createPhoneNumber(const int arr [10]){
  std::stringstream ss;
  ss << "(";
  ss << arr[0] << arr[1] << arr[2];
  ss << ") ";
  ss << arr[3] << arr[4] << arr[5];
  ss << "-";
  ss << arr[6] << arr[7] << arr[8] << arr[9];
  return ss.str();
}

``` 