#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.
*/

int lengthOfLastWord(string s) {
	if (s.empty())
	{
		return 0;
	}

	int result{ 0 };

	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (result == 0 && s[i] == ' ')
		{
			continue;
		}
		else if (s[i] == ' ')
		{
			return result;
		}
		else
		{
			result++;
		}

	}

	return result;
}

