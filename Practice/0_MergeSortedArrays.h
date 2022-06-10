#include "Includes.h"

vector<int> MergeSortedArrays(vector<int> a, vector<int> b)
{
    /**
    * Merge two sorted arrays into a single array.
    * Return new array.
    */
    vector<int> result;
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            result.push_back(a[i]);
            i++;
        }
        else
        {
            result.push_back(b[j]);
            j++;
        }
    }
    for (int k = i; k < a.size(); k++)
    {
        result.push_back(a[k]);
    }
    for (int k = j; k < b.size(); k++)
    {
        result.push_back(b[k]);
    }

    return result;
}