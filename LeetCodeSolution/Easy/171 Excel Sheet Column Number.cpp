#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

	A -> 1
	B -> 2
	C -> 3
	...
	Z -> 26
	AA -> 27
	AB -> 28
*/

int titleToNumber(string s) {
	if (s.empty()) return 0;

	int result{ 0 };

	for (int i = 0; i < s.size(); i++) {
		result = result * 26 + s[i] - 'A' + 1;
	}

	return result;
}