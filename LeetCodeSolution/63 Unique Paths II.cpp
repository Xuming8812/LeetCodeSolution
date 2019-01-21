#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
*/

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	if (obstacleGrid.empty()) return 0;

	vector<vector<int>> dp(obstacleGrid.size() + 1, vector<int>(obstacleGrid[0].size() + 1, 0));


	for (int i = 1; i <= obstacleGrid.size(); i++) {
		for (int j = 1; j <= obstacleGrid[0].size(); j++) {

			if (i == 1 && j == 1 && obstacleGrid[i - 1][j - 1] == 0) {
				dp[1][1] = 1;
				continue;
			}

			if (obstacleGrid[i - 1][j - 1] == 1) {
				continue;
			}
			else {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}

	return dp[obstacleGrid.size()][obstacleGrid[0].size()];
}