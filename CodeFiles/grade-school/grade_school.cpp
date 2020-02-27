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
            rosterMap[note].insert(lower_bound(rosterMap[note].begin(), rosterMap[note].end(), name), name);
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
