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
You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.
*/

int coinChange(vector<int>& coins, int amount) {
	vector<int> dp(amount + 1, amount + 1);

	dp[0] = 0;

	int result{ amount + 1 };

	for (int i = 1; i <= amount; i++) {
		for (int j = 0; j < coins.size(); j++) {
			if (coins[j] <= i) {
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}

	if (dp[amount] > amount) {
		return -1;
	}
	else {
		return dp[amount];
	}
}