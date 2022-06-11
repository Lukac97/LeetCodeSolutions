#include "Includes.h"

vector<int> rotateArrayWithCopy(const vector<int>& vec, int step)
{
    if (step == 0)
        return vec;
    vector<int> newArray;

    int i = vec.size() - step - 1;

    do
    {
        newArray.push_back(vec[i]);

        i = (i + 1) % (vec.size() - 1);
    } while (i != vec.size() - step - 1);

    return newArray;

}

void changeValsAndAssignTemp(vector<int>& vec, unordered_set<int>& changedIdxs, const int& idx, int& temp)
{
    int tempTemp = vec[idx];
    vec[idx] = temp;
    temp = tempTemp;

    changedIdxs.insert(idx);
}

void rotateArrayInPlace(vector<int>& vec, int step)
{
    if (step == 0 || step % vec.size() == 0 || vec.size() <= 1)
        return;

    unordered_set<int> changedIdxs;
    int i = 0;

    int temp = vec[i];
    i = (i + step) % vec.size();

    while (changedIdxs.size() < vec.size())
    {
        if (changedIdxs.find(i) != changedIdxs.end())
        {
            if (changedIdxs.size() != 0)
                i++;
            temp = vec[i];
            i = (i + step) % vec.size();
        }
        else
        {
            changeValsAndAssignTemp(vec, changedIdxs, i, temp);

            i = (i + step) % vec.size();
        }
    }
}