#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
A string of '0's and '1's is monotone increasing if it consists of some number of '0's (possibly 0), followed by some number of '1's (also possibly 0.)

We are given a string S of '0's and '1's, and we may flip any '0' to a '1' or a '1' to a '0'.

Return the minimum number of flips to make S monotone increasing.
*/


//use dp, dp[i][0]第i位为0时的解，dp[i][1]为第i位为1时的解，最后返回其中较小的值
int minFlipsMonoIncr(string S) {
	int len = S.length();
	
	if (len == 0) {
		return 0;
	}

	//dp matrix initialization
	vector<vector<int>> dp(len + 1, vector(2, 0));

	for (int i = 1; i <= len; i++)
	{
		if (S[i - 1] == '0')		//if the ith S is '0'
		{
			
			dp[i][0] = dp[i - 1][0]; //no need to flip
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;// need to flip to 1
		}
		else
		{
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);		//no need to flip
			dp[i][0] = dp[i - 1][0] + 1;					//need to flip to 0
		}
	}


	return min(dp[len][0], dp[len][1]);
}