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