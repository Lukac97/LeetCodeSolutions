#include "Includes.h"

int getLongestNonRepeatingSubstringLength1(string s)
{
	unordered_map<char, int> chars;

	int maxLen = 0;
	int first = 0;
	int last = 0;

	while(last < s.size())
	{
		unordered_map<char, int>::iterator it = chars.find(s[last]);
		if (it == chars.end() || (it != chars.end() && (it->second < first)))
		{
			if (it != chars.end())
			{
				it->second = last;
			}
			else
			{
				chars.insert(make_pair(s[last], last));
			}
		}
		else
		{
			maxLen = max(maxLen, last - first);
			first = it->second + 1;
			it->second = last;

		}
		last++;
	}
	maxLen = max(maxLen, last - first);

	return maxLen;
}
