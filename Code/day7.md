# Day 4 Code

## RNA transcription

rna_transcription.h

```cpp
#if !defined(RNA_TRANSCRIPTION_H)
#define RNA_TRANSCRIPTION_H
#include <map>
#include <string.h>

using namespace std;

namespace rna_transcription {
    char to_rna (char DNA);
    string to_rna (string const DNA);
    const map <char, char> translator = 
    {
        {'G', 'C'},
        {'C', 'G'},
        {'T', 'A'},
        {'A', 'U'}
    };
}  // namespace rna_transcription

#endif // RNA_TRANSCRIPTION_H
```

rna_transcription.cpp

```cpp
#include "rna_transcription.h"

namespace rna_transcription {
    char to_rna (char DNA)
    {
        return translator.at(DNA);
    }
    string to_rna (string const DNA)
    {
        int N = DNA.size(), i;
        string transcription;
        for (i = 0; i < N; i++)
            transcription.push_back(to_rna(DNA[i]));
        return transcription;
    }

}  // namespace rna_transcription
```