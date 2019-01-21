#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
A robot is located at the top - left corner of a m x n grid(marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time.The robot is trying to reach the bottom - right corner of the grid(marked 'Finish' in the diagram below).

How many possible unique paths are there ?
*/

int uniquePaths(int m, int n) {

	if (m < 1 || n < 1)
	{
		return 0;
	}
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == 1 && j == 1)
			{
				dp[1][1] = 1;
			}
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}

	return dp[m][n];
}
