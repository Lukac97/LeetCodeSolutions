#include "Includes.h"

string ReverseString(string iString)
{
    /**
    *Reverse string and return it.
    */
    if (iString.size() == 0)
        return iString;

    ostringstream reverseStream;

    for (auto it = iString.rbegin(); it < iString.rend(); it++)
    {
        reverseStream << *it;
    }

    return reverseStream.str();
}