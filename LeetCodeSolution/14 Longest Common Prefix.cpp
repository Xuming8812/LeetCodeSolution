#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
*/

string longestCommonPrefix(vector<string>& strs) {
	string result;

	if (strs.empty())
	{
		return result;
	}

	result = strs[0];

	for (int i = 1; i < strs.size(); i++)
	{
		result = commonPrefix(result, strs[i]);
	}

	return result;
}


//get the longest common prefix of current prefix and the input string
string commonPrefix(string current, string input)
{
	string result;
	
	int index{ 0 };

	while (index < current.size() && index < input.size())
	{
		if (current[index] == input[index])
		{
			index++;
		}
		else
		{
			break;
		}
	}
	return current.substr(0, index);
}