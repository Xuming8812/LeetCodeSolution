#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.
*/

int maxProfit(vector<int>& prices) {
	int result{ 0 };

	if (prices.size() < 2)
	{
		return result;
	}

	int minValue = prices[0];

	for (size_t i{ 0 }; i < prices.size(); ++i)
	{
		if (minValue >= prices[i])
		{
			minValue = prices[i];
		}
		else
		{
			result = max(result, prices[i] - minValue);
		}
	}

	return result;
}