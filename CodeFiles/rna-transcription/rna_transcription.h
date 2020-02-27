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