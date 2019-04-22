#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.
*/

vector<int> findAnagrams(string s, string p)
{
	if (s.size() < p.size()||p.empty())
	{
		return {};
	}
	map<char, int> dict;
	vector<int> result;
	//count number of each char
	for (auto c : p)
	{
		dict[c]++;
	}
	
	int count = dict.size();

	//left and right pointer of the window
	int left = 0, right = 0;

	while (right < s.size())
	{
		char rightChar = s[right];
		//if the current exsit in p
		if (dict.find(rightChar) != dict.end())
		{
			dict[rightChar]--;
			if (dict[rightChar] == 0)
			{
				count--;
			}
		}
		//move window to right
		right++;
		//the string within the window has same numbers of chars with p
		while (count == 0)
		{
			if (right - left == p.size())
			{
				result.push_back(left);
			}

			char leftChar = s[left];

			if (dict.find(leftChar) != dict.end())
			{
				dict[leftChar]++;
				if (dict[leftChar] == 1)
				{
					count++;
				}
			}
			//move the left side of the window to right
			left++;
		}
	}

	return result;
}