#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.
*/

int numDecodings(string s) {
	if (s.empty()) return 0;
	if (s[0] == '0') return 0;


	vector<int> dp(s.size(), 0);


	dp[0] = 1;

	for (int i = 1; i < s.size(); i++) {
		dp[i] = dp[i - 1];

		if (s[i] == '0') {
			if (s[i - 1] != '1' && s[i - 1] != '2') return 0;

			dp[i] = i > 1 ? dp[i - 2] : 1;

		}
		else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7')) {
			dp[i] += i > 1 ? dp[i - 2] : 1;
		}
	}

	return dp[s.size() - 1];
}