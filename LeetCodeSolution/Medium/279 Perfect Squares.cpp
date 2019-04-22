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
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
*/

int numSquares(int n) {
	// Write your code here
	vector<int> dp{ 0 };
	dp.resize(n + 1, INT_MAX);
	for (int i = 1, k; (k = i * i) <= n; ++i)
		for (int j = k; j <= n; ++j)
			if (dp[j] > dp[j - k] + 1)
				dp[j] = dp[j - k] + 1;
	return dp[n];
}