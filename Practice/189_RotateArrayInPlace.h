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

void rotateArrayInPlace(vector<int>& vec, int step)
{
    int currentIdx = 0;

    int i = 0;

    bool repetitive = (vec.size() % step == 0) && (step % 2 == 0);

    int temp;

    while (i < vec.size())
    {
        if (repetitive && i == vec.size() / 2)
        {
            currentIdx++;
        }

        if (i == 0)
        {
            temp = vec[i];
        }
        else
        {
            int tempTemp = vec[i];
            vec[i] = temp;
            temp = tempTemp;
        }
        i++;
    }

    vec[0] = temp;
}