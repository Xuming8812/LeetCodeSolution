#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
*/


int minDistance(string word1, string word2) {
	int rowNum = word1.size(), colNum = word2.size();

	vector<vector<int>> dp(rowNum + 1, vector<int>(colNum + 1, 0));


	for (int i = 1; i <= rowNum; i++) {
		dp[i][0] = i;
	}

	for (int i = 1; i <= colNum; i++) {
		dp[0][i] = i;
	}

	for (int i = 1; i <= rowNum; i++) {
		for (int j = 1; j <= colNum; j++) {
			if (word1[i - 1] == word2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			}
		}
	}

	return dp[rowNum][colNum];
}