#include <iostream>
#include <vector>
#include "min_diff_partition.h"

std::vector<int> partition1, partition2;
std::vector<int> result1, result2;
std::vector<int> mainarray;

void partitionMinDiff(std::vector<int> &res1, std::vector<int> &res2, std::vector<int> m_array, long &difference) {
    mainarray = m_array;
    unsigned int i = 0;
    long sum1 = 0, sum2 = 0;
    partitionRecurse(i, difference, sum1, sum2);
    res1 = result1;
    res2 = result2;
}



void partitionRecurse(unsigned int i, long &diffcurrent, long sum1, long sum2)
{
    if(diffcurrent == 0) return;
    if(i == mainarray.size())
    {
        long diff= abs(sum1 - sum2);
        if(diffcurrent > diff)
        {
            result1 =  partition1;
            result2 = partition2;
            diffcurrent = diff;
        }
        return;
    }

    partition1.push_back(mainarray[i]);
    partitionRecurse(i+1, diffcurrent, sum1 + mainarray[i], sum2);
    partition1.pop_back();

    partition2.push_back(mainarray[i]);
    partitionRecurse(i+1, diffcurrent, sum1, sum2 + mainarray[i]);
    partition2.pop_back();

    return;
}
