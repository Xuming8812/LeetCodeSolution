#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

vector<string> results;

void dfs(string current, int left, int right)
{
	if (right == 0) {
		results.push_back(current);
		return;
	}

	if (left == 0) {
		current += ")";
		dfs(current, left, right - 1);
	}
	else {
		if (left < right) {
			dfs(current + ")", left, right - 1);
		}

		dfs(current + "(", left - 1, right);

	}
}

vector<string> generateParenthesis(int n) {

	string result;

	dfs("", n, n);

	return results;
}

