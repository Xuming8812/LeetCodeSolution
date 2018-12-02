#include<iostream>
#include<vector>
#include<map>

using namespace std;


/* 
Given two strings s and t , write a function to determine if t is an anagram of s.
*/

bool isAnagram(string s, string t)
{
	//check whether these two strings have the same length
	if (s.size() != t.size())
	{
		return false;
	}
	//use a map to store char and its number
	map<char, int> dict;
	//count chars in string s
	for (auto c : s)
	{
		dict[c]++;
	}
	//count chars in string t
	for (auto c : t)
	{
		dict[c]--;
	}
	//check the fina results
	for (auto item : dict)
	{
		if (item.second != 0)
		{
			return false;
		}
	}

	return true;

}