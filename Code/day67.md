# Day 67 Code

```cpp
#include <iomanip>

class RGBToHex
{
  public:
  static std::string rgb(int r, int g, int b)
  {
    std::stringstream ss_r, ss_g, ss_b, ss_pr, ss_pg, ss_pb;
    ss_r << std::hex << r;
    ss_g << std::hex << g;
    ss_b << std::hex << b;
    
     std::ostringstream ss;
    ss << std::setw(7) << std::setfill('0') << num;
    std::string result = ss.str();
    if (result.length() > 7)
    {
        result.erase(0, 
    std::string s = ss_pr.str() + ss_pg.str() + ss_pb.str();
    std::transform(s.begin(), s.end(), s.begin(), ::toupper); 
    return s;
  }
};

```