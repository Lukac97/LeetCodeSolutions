#include "Includes.h"

bool checkDuplicates(const vector<int>& vec)
{
    unordered_set<int> existingVals;

    for (int i = 0; i < vec.size(); i++)
    {
        if (existingVals.find(vec[i]) != existingVals.end())
            return true;

        existingVals.insert(vec[i]);
    }

    return false;
}