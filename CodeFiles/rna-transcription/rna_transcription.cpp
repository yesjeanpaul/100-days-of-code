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
