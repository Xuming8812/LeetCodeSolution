#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/

vector<string> result;

map<int, string> dict{ {2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"} };

void dfs(string digits, int currentIndex, string currentString) {
	if (currentIndex == digits.size()) {
		result.push_back(currentString);
		return;
	}

	int currentNum = digits[currentIndex] - '0';

	for (auto c : dict[currentNum]) {
		currentString += string(1, c);
		dfs(digits, currentIndex + 1, currentString);
		currentString = currentString.substr(0, currentString.size() - 1);
	}
}

vector<string> letterCombinations(string digits) {

	if (digits.empty()) {
		return result;
	}

	dfs(digits, 0, "");

	return result;
}