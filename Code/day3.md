# Day 3 Code

## nucleotide count

```cpp
#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H
#include "map"
#include <string.h>
#include <stdexcept>

namespace nucleotide_count {
    class counter
    {
        public:
            counter(const char* DNA);
            std::map <char, int> nucleotide_counts() const;
            int count(char nucleotide) const;
        private:
            std::map<char, int> nucleotideMap;
            const char *sequence;
    };
}  

#endif 
```

```cpp
#include "nucleotide_count.h"

namespace nucleotide_count {
    
    counter::counter (const char* DNA)
    {
        sequence = DNA;
        nucleotideMap['A'] = 0;
        nucleotideMap['T'] = 0;
        nucleotideMap['C'] = 0;
        nucleotideMap['G'] = 0;
        for (unsigned long i = 0; i < strlen(sequence); i++)
        {
            if (sequence [i] == 'A')
                nucleotideMap ['A'] ++;

            else if (sequence [i] == 'T')
                nucleotideMap ['T'] ++;
                
            else if (sequence [i] == 'C')
                nucleotideMap ['C'] ++;

            else if (sequence [i] == 'G')
                nucleotideMap ['G'] ++;
            else
                throw std::invalid_argument("This is not a nucleotid");
        }
    }

    std::map<char, int> counter::nucleotide_counts () const
    {
        return nucleotideMap;
    }
    
    int counter::count (char nucleotide) const
    {
        if (nucleotide == 'A' || nucleotide == 'C' || 
            nucleotide == 'T' || nucleotide == 'G')
            return nucleotideMap.at(nucleotide);
        else
        {
            throw std::invalid_argument("That is not a nucleotid");
        }
        
    }
}  
```