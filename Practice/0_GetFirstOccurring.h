#include "Includes.h"

int getFirstOccurring(vector<int> vec, bool& found)
{
    unordered_set<int> existingEls;

    for (int i = 0; i < vec.size(); i++)
    {
        if (existingEls.find(vec[i]) == existingEls.end())
        {
            existingEls.insert(vec[i]);
        }
        else
        {
            found = true;
            return vec[i];
        }
    }

    found = false;
    return -1;
}