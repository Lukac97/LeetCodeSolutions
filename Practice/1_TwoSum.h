#include "Includes.h"

bool findPair(const int const nrArray[], int sum)
{
    /**
    * Same as twoSum.
    */
    int left_i = 0;
    int right_i = sizeof(nrArray) - 1;


    while (right_i > left_i)
    {
        int new_sum = nrArray[left_i] + nrArray[right_i];
        if (new_sum == sum)
        {
            return true;
        }
        if (new_sum > sum)
        {
            left_i++;
        }
        else
        {
            right_i--;
        }

    }

    return false;
}

vector<int> twoSum(vector<int>& nums, int target) {
    /**
    * Find pair of elements in vector that are equal to the target number.
    * Return their indices.
    */
    unordered_map<int, int> leftovers;
    for (int i = 0; i < nums.size(); i++)
    {
        unordered_map<int, int>::const_iterator key_value_it = leftovers.find(nums[i]);

        if (key_value_it == leftovers.end())
        {
            leftovers.insert(make_pair(target - nums[i], i));
        }
        else
        {
            vector<int> result = { key_value_it->second, i };
            return result;
        }
    }
    vector<int> result = { -1, -1 };
    return result;
}
