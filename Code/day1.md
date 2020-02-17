# Day 1 Code

## Hello world function

hello_world.h
```c
// This is an include guard.
// You could alternatively use '#pragma once'
// See https://en.wikipedia.org/wiki/Include_guard
#if !defined(HELLO_WORLD_H)
#define HELLO_WORLD_H

// Include the string header so that we have access to 'std::string'
#include <string>

// Declare a namespace for the function(s) we are exporting.
// https://en.cppreference.com/w/cpp/language/namespace
namespace hello_world {

// Declare the 'hello()' function, which takes no arguments and returns a
// 'std::string'. The function itself is defined in the hello_world.cpp source
// file. Because it is inside of the 'hello_world' namespace, it's full name is
// 'hello_world::hello()'.
std::string hello();

}  // namespace hello_world

#endif

```

hello_world.cpp
```cpp
#include "hello_world.h"

// Use everything from the 'std' namespace.
// This lets us write 'string' instead of 'std::string'.
using namespace std;

namespace hello_world {

// Define the function itself. This could have also been written as:
// std::string hello_world::hello()
string hello() {
    // Return the string we need.
    return "Hello, World!";
}

}  // namespace hello_world
```

## Hamming distance function

hamming.h

```c
#include <string>

#if !defined(HAMMING_H)
#define HAMMING_H

namespace hamming {
    int compute (std::string orginalDNA, std::string replicateDNA);
}  // namespace hamming

#endif // HAMMING_H
```

hamming.cpp

```cpp
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
```

