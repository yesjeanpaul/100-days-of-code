#include <stdio.h>
#include <vector>


using namespace std;


int make_simulation (int num_quotas, float initial_payment, float loan, 
                    vector <pair <int, float>> deprecitations)
{
    int i, j = 0;
    double debt = loan, 
          car_value  = initial_payment + loan, 
          percentage = deprecitations[j].second,
          deprecitation = car_value * (1 - percentage),
          quota = debt/num_quotas;

    if (debt < deprecitation)
            return 0;
    
    for (i = 1; i <= num_quotas; i++)
    {
        if (j < deprecitations.size() && deprecitations[j+1].first == i)
        {
            percentage = deprecitations[j+1].second;
            j ++;
        }
        debt -= quota;
        deprecitation *= (1 - percentage);
        if (debt < deprecitation)
            return i;
    }
    return -1;
     
}


int main ()
{
    int num_quotas, depcr_redords, i, result;
    float intial_payment, loan;
    vector <pair <int, float> > deprecitiations;
    while (scanf("%d %f %f %d", &num_quotas, &intial_payment, &loan, &depcr_redords), num_quotas >= 0)
    {
        int num_month;
        float percent;
        for (i = 0; i < depcr_redords; i ++)
        {
            scanf("%d %f", &num_month, &percent);
            deprecitiations.push_back(make_pair(num_month, percent));
        }
        result = make_simulation(num_quotas, intial_payment, loan, deprecitiations);
        if (result == 1)
            printf("1 month\n");
        else
            printf("%d months\n", result);
        deprecitiations.clear();
    }
}