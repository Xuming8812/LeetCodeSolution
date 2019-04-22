#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<bitset>
using namespace std;

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Input:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

int maximalSquare(vector<vector<char>>& matrix) {
	if (matrix.empty()) return 0;

	int rowNum = matrix.size(), colNum = matrix[0].size();

	vector<vector<int>> dp(rowNum + 1, vector<int>(colNum + 1, 0));

	int result{ INT_MIN };

	for (int i = 1; i <= rowNum; i++) {
		for (int j = 1; j <= colNum; j++) {
			if (matrix[i - 1][j - 1] == '0') {
				dp[i][j] = 0;
			}
			else {
				dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;
			}

			result = max(result, dp[i][j]);
		}
	}

	return result * result;
}