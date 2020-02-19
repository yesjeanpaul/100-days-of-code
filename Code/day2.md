# Day 2 Code

## Hamming distance

hamming.h
```cpp
#if !defined(HAMMING_H)
#define HAMMING_H

#include <string.h>

namespace hamming {
    int compute (const char *originalDNA ,const char *replicateDNA);
}  // namespace hamming

#endif // HAMMING_H
```

hamming.cpp
```cpp
#include "hamming.h"
#include <stdexcept>

namespace hamming 
{

int compute (const char *originalDNA ,const char *replicateDNA)
{
    int count = 0;

    unsigned long lenOriginalDNA = strlen(originalDNA);
    unsigned long lenReplicateDNA = strlen(replicateDNA);

    if (lenOriginalDNA == lenReplicateDNA)
    {
        for (unsigned long i = 0; i < lenReplicateDNA; i++)
        {
            if (originalDNA[i] != replicateDNA[i])
                count ++;
        }
    }
    else
    {
        throw std::domain_error("Two strings must be the same length");
    }

    return count;

}

}  // namespace hamming
```

## Nucleotide

nucleotide_count.h
```cpp
#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H
#include "map"
#include <string.h>

namespace nucleotide_count {
    class counter
    {
        int data;
    };
}  // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H
```

nucleotide_count.cpp
```cpp
#include "nucleotide_count.h"

namespace nucleotide_count {
 
    
    std::map<char, int> counter (char *nucleotide)
    {
        std::map<char, int> nucleotideMap;
        nucleotideMap['A'] = 0;
        nucleotideMap['T'] = 0;
        nucleotideMap['C'] = 0;
        nucleotideMap['G'] = 0;
        for (unsigned long i = 0; i < strlen(nucleotide); i++)
        {
            if (nucleotide[i] == 'A')
                nucleotide['A'] ++;
            else if (nucleotide[i] == 'T')
                nucleotide['T'] ++;
            else if (nucleotide[i] == 'C')
                nucleotide['C'] ++;
            else if (nucleotide[i] == 'G')
                nucleotideMap['G'] ++;
        }
        return nucleotideMap;
    }
    
}  // namespace nucleotide_count
```