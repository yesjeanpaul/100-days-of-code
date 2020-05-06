# Day 68 Code 

arimtetic_progression.cpp

```cpp

static long findMissing(std::vector<long> list){
    //c_d stands for candidate difference
    long c_d_1, c_d_2, c_d_3, diff, initial;
    c_d_1 = list[1] - list[0];
    c_d_2 = list[((int)list.size()) - 1] - list[((int)list.size()) - 2];
    c_d_3 = list[2] - list[1];
    
    if (c_d_1 == c_d_2)
      diff = c_d_1;
    else
      if (c_d_1 == c_d_3)
        diff = c_d_1;
      else
        diff = c_d_2;
    
    initial = list[0];
    for (long i = 1; i < (long) list.size(); i++)
      if (list[(int) i] != initial + diff*i)
        return initial + diff * i;
    
    return -1;
}

```