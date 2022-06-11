#include "Includes.h"

void moveZerosToEnd(vector<int>& vec)
{
    int firstZeroIdx = -1;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == 0)
        {
            if (firstZeroIdx < 0)
            {
                firstZeroIdx = i;
            }
        }
        else if (firstZeroIdx >= 0)
        {
            int temp = vec[firstZeroIdx];
            vec[firstZeroIdx] = vec[i];
            vec[i] = temp;

            firstZeroIdx++;
        }
    }
}