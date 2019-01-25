#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
*/

int minimumTotal(vector<vector<int>>& triangle) {
	if (triangle.empty()) return 0;

	int rowNum = triangle.size();
	vector<int> dp(rowNum, INT_MAX);

	dp[0] = triangle[0][0];

	for (int row = 1; row < rowNum; row++) {
		vector<int> temp = dp;

		for (int j = 0; j <= row; j++) {
			int left{ INT_MAX }, middle{ INT_MAX };

			if (j >= 1) {
				left = temp[j - 1];
			}
			if (j < row) {
				middle = temp[j];
			}

			dp[j] = min(left, middle) + triangle[row][j];

		}
	}

	return *min_element(dp.begin(), dp.end());
}