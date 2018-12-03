#include<map>
#include<algorithm>
using namespace std;

/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character but a character may map to itself.

*/

bool isIsomorphic(string s, string t)
{
	//use two hash maps to store the corresponding relation between string s and t
	map<char, int>sDict, tDict;
	//if the length of two string don`t match, return false;
	if (s.size() != t.size())
	{
		return false;
	}
	//save the correspoinding relation of s in t in sDict
	for (int i = 0;i<s.size();i++)
	{
		if (sDict.find(s[i]) == sDict.end())
		{
			sDict[s[i]] = t[i] - s[i];
		}
		else
		{
			//a char in s matches two chars in t, return false
			if (sDict[s[i]] != (t[i] - s[i]))
			{
				return false;
			}			
		}		
	}
	//save the correspoinding relation of t in s in tDict
	for (int i = 0; i < t.size(); i++)
	{
		if (tDict.find(t[i]) == tDict.end())
		{
			tDict[t[i]] = s[i] - t[i];
		}
		else
		{
			//a char in t matches two chars in s, return false
			if (tDict[t[i]] != (s[i] - t[i]))
			{
				return false;
			}
		}
	}

	return sDict.size()==tDict.size();

}