#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
*/

bool wordBreak(string s, vector<string>& wordDict) {
	set<string> dict;
	for (auto item : wordDict)   dict.insert(item);

	int len_S = s.size();
	vector<bool> dp(len_S, false);
	dp[0] = true;

	for (int i = 1; i <= len_S; i++) {
		for (int j = 0; j < i; j++) {
			if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
				dp[i] = true;
				break;
			}
		}
	}

	return dp[len_S];
}
