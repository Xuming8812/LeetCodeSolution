#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
*/

int numTrees(int n) {

	vector<int> dp(n + 1, 0);

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] += dp[j - 1] * dp[i - j];
		}
	}

	return dp[n];
}