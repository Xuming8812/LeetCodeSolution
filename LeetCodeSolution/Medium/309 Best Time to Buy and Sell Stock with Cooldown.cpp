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
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
*/

int maxProfit(vector<int>& prices) {
	if (prices.empty()) return 0;

	int length = prices.size();
	vector<int> buy(length);
	vector<int> sell(length);

	buy[0] = -prices[0];

	int result{ 0 };

	for (int i = 1; i < length; i++) {
		sell[i] = max(buy[i - 1] + prices[i], sell[i - 1] - prices[i - 1] + prices[i]);

		if (i == 1) {
			buy[1] = buy[0] + prices[0] - prices[1];
		}
		else {
			buy[i] = max(sell[i - 2] - prices[i], buy[i - 1] + prices[i - 1] - prices[i]);
		}

		result = max(result, sell[i]);

	}

	return result;
}