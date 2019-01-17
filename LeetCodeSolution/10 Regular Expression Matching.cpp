#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

bool isMatch(string s, string p) {
	//dp[i][j] indicate s.substr(0,i) matches p.substr(0,j)
	vector<vector<bool>> dp(p.size() + 1, vector<bool>(s.size() + 1, false));

	dp[0][0] = true;

	/*
	if(p.size()>=2 && p[1] == '*'){
		dp[2][0] = true;
	}
	*/

	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '*') {
			dp[i + 1][0] = true;
		}
	}

	for (int i = 1; i <= p.size(); i++) {
		for (int j = 1; j <= s.size(); j++) {
			//match .
			if (p[i - 1] == '.') {
				dp[i][j] = dp[i - 1][j - 1];
				continue;
			}
			//match *
			if (p[i - 1] == '*') {
				dp[i][j] = (i >= 2 && dp[i - 2][j]) || dp[i - 1][j] || (dp[i][j - 1] && (p[i - 2] == '.' || p[i - 2] == s[j - 1]));
				continue;
			}

			//otherwise
			dp[i][j] = dp[i - 1][j - 1] && s[j - 1] == p[i - 1];
		}
	}

	return dp[p.size()][s.size()];
}

int main() {
	string s{ "a" }, p{ "ab*a" };
	isMatch(s, p);
}