#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
*/

string convert(string s, int numRows) {

	//if numRows is too big or equals to 1
	if (numRows == 1 || numRows >= s.size())
		return s;

	vector<string> subStrings(numRows);

	//use a bool to indicate direction
	bool isDecending{ false };

	int i{ 0 };

	for (auto c : s) {
		subStrings[i] += string(1, c);
		if (i == 0 || i == numRows - 1)
		{
			isDecending = !isDecending;
		}

		i = (isDecending) ? i + 1 : i - 1;
	}

	//output the result
	string result;

	for (auto str : subStrings)
	{
		result += str;
	}

	return result;
}