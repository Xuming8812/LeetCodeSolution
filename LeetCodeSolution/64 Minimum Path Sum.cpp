#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/


int minPathSum(vector<vector<int>>& grid) {

	if (grid.empty()) return 0;

	int rowNum = grid.size(), colNum = grid[0].size();

	vector<vector<int>> dp(rowNum + 1, vector<int>(colNum + 1, 0));

	dp[1][1] = grid[0][0];

	for (int row = 2; row <= rowNum; row++) {
		dp[row][1] = dp[row - 1][1] + grid[row - 1][0];
	}

	for (int col = 2; col <= colNum; col++) {
		dp[1][col] = dp[1][col - 1] + grid[0][col - 1];
	}

	for (int i = 2; i <= rowNum; i++) {
		for (int j = 2; j <= colNum; j++) {
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
		}
	}

	return dp[rowNum][colNum];
}