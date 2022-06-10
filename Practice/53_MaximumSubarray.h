#include "Includes.h"

int maxSubArraySum(const vector<int>& vec)
{
    /**
    * Modified Kadene's algorithm of getting max sum of subarray in array.
    */
    int sum = INT_MIN;
    int result = INT_MIN;
    int max_nr = INT_MIN;

    for (int i = 0; i < vec.size(); i++)
    {
        max_nr = max(max_nr, vec[i]);

        if (sum < 0)
            sum = 0;
        sum += vec[i];
        result = max(result, sum);
    }

    if (result > 0)
    {
        return result;
    }

    return max_nr;
}
#pragma once
