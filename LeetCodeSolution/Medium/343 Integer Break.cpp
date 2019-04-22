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
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. 
Return the maximum product you can get.
*/
int integerBreak(int n) {
	vector<int> dp(n + 1);

	if (n <= 2) return 1;

	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], j*max(dp[i - j], i - j));
		}
	}

	return dp[n];
}
