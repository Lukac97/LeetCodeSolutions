#include "Includes.h"

bool checkExistItem(vector<int> array1, vector<int> array2)
{
    /**
    * Check if item exists in both arrays.
    */
    unordered_set<int> foundItems;

    for (int i = 0; i < array1.size(); i++)
    {
        foundItems.insert(array1[i]);
    }
    for (int i = 0; i < array2.size(); i++)
    {
        if (foundItems.find(array2[i]) != foundItems.end())
        {
            return true;
        }
    }

    return false;
}