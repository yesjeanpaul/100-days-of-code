# Day 16 code

```cpp
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <math.h>

using namespace std;

string name = "";
float price = 2000000000;
int requirements = -1;

void change (string n, float p, int r)
{
    name = n;
    price = p;
    requirements = r;
}

void reset ()
{
    name = "";
    price = 2000000000;
    requirements = -1;
}

void print(int RFP)
{
    if (RFP > 1)
        cout << endl;
    cout << "RFP #" << RFP << endl;
    cout << name << endl;
}


int main ()
{
    int n, p, i, j, requirements, RFP = 1;
    string name, t;
    float price;

    while (scanf("%d %d", &n, &p), n > 0, p > 0)
    {
        getline(cin, t);
        for (j = 0; j < n; j++)
        {
            getline(cin, t);
        }
        for (i = 0; i < p; i ++)
        {
            getline(cin, name);
            scanf("%f %d\n", &price, &requirements);

            for (j = 0; j < requirements; j++)
                getline(cin, t);

            if (requirements > ::requirements)
                change(name, price, requirements);
            else if (requirements == ::requirements && price < ::price)
                change(name, price, requirements);
        }
        print(RFP);
        reset();
        RFP ++;
    }
    
}
``` 