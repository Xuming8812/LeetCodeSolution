#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
*/


//like 205 isomorphic, need to corresponding relation between char and string and likewise
bool wordPattern(string pattern, string str) {
	vector<char> pStore;

	for (auto item : pattern)
	{
		pStore.push_back(item);
	}

	vector<string> sStore;

	//split string into words
	stringstream ss;

	ss << str;

	string temp;
	while (ss >> temp)
	{
		sStore.push_back(temp);
	}

	if (pStore.size() != sStore.size())
	{
		return false;
	}

	map<char, string> storeA;
	map<string, char> storeB;

	for (size_t i{ 0 }; i < pStore.size(); i++)
	{
		if (storeA.find(pStore[i]) == storeA.end())
		{
			storeA[pStore[i]] = sStore[i];
		}
		else
		{
			if (storeA[pStore[i]] != sStore[i])
			{
				return false;
			}
		}
	}

	//special case "abba"-->"dog dog dog dog"
		
	for (size_t i{ 0 }; i < pStore.size(); i++)
	{
		if (storeB.find(sStore[i]) == storeB.end())
		{
			storeB[sStore[i]] = pStore[i];
		}
		else
		{
			if (storeB[sStore[i]] != pStore[i])
			{
				return false;
			}
		}
	}

	return true;
}