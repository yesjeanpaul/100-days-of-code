# Day 4 Code

## Grade school exercise

grade_school.h

```cpp
#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

namespace grade_school {
    class school 
    {
        public:
            school () {};
            map <int, vector<string>> roster () const;
            void add (string name, int note);
            vector <string> grade (int note) const;
        private:
            map <int, vector<string>> rosterMap;
    };
}  // namespace grade_school

#endif // GRADE_SCHOOL_H
```

grade_school.cpp
```cpp
#include "grade_school.h"



namespace grade_school {
    map <int, vector<string>> school::roster () const
    {
        return rosterMap;
    }

    void school::add (string name, int note)
    {
        if (rosterMap.count(note))
        {
            rosterMap[note].push_back(name);
            sort(rosterMap[note].begin(), rosterMap[note].end());
        }
        else
            rosterMap[note] = vector <string> {name};
    }
    
    vector <string> school::grade (int note) const
    {
        if (rosterMap.count(note))
            return rosterMap.at(note);
        else
            return vector <string> {};
    }

}  // namespace grade_school
```

