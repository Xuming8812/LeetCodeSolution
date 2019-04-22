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
add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
*/

void wordBreakHelper(vector<bool>& dp, vector<string>& result, string s, string chosen, int index, set<string> dict) {
	if (index == s.size()) {
		result.push_back(chosen.substr(0, chosen.size() - 1));
		return;
	}

	for (int i = index + 1; i <= s.size(); i++) {
		if (dp[i]) {
			string new_word = s.substr(index, i - index);
			if (dict.find(new_word) != dict.end()) {
				wordBreakHelper(dp, result, s, chosen + new_word + " ", i, dict);
			}
		}
	}
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
	set<string> dict;

	for (auto item : wordDict) dict.insert(item);

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

	vector<string> result;

	if (dp[len_S]) {
		wordBreakHelper(dp, result, s, "", 0, dict);
	}

	return result;
}