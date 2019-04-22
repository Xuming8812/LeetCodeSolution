#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a string, find the length of the longest substring without repeating characters.
*/


//slide window
int lengthOfLongestSubstring(string s) {

	int result{ 0 }, left{ 0 }, right{ 0 };

	map<char, int> dict;

	while (right < s.size())
	{
		char current = s[right];

		if (dict.count(current) == 1 && dict[current] >= left) {
			left = dict[current] + 1;
		}
		else
		{
			dict[current] = right;
			right++;
		}

		if (right - left >= result)
		{
			result = right - left;
		}

	}

	return result;
}