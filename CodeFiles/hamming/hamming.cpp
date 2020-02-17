#include "hamming.h"
#include <stdexcept>

namespace hamming 
{

int compute (std::string orginalDNA, std::string replicateDNA)
{
    int count = 0;
    if (orginalDNA.length() == replicateDNA.length())
    {
        
        for (long unsigned int i = 0; i < orginalDNA.length(); i ++)
        {
            if (orginalDNA[i] != replicateDNA[i])
            {
                count ++;
            }
        }
    }
    else
    {
        throw std::domain_error("a and b must be of equal length.");
    }
    return count;
}

}  // namespace hamming
