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
            bool finded = false;
            vector<string>::iterator v;
            for (v = rosterMap[note].begin(); v < rosterMap[note].end(); v++)
            {
                if (*v > name)
                {
                    rosterMap[note].insert(v,name);
                    finded = true;
                    break;
                }
            }
            if (!finded)
                rosterMap[note].push_back(name);
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
