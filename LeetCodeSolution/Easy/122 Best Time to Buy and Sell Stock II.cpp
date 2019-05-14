#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
*/

// the total profit is the sum of all the peaks substract the previous vallies
int maxProfit(vector<int>& prices) {
	int result{ 0 };

	for (int i = 1; i < prices.size(); i++) {
		if (prices[i] > prices[i - 1]) {
			result += (prices[i] - prices[i - 1]);
		}
	}

	return result;
}

//the dp version
int maxProfit(vector<int>& prices) {
	if(prices.empty()){
		return  0;
	}
	//use sell to store the maximum profit if we sell stock today
	int sell = 0;
	//use buy to store the maximum profit if we buy stock or skip
	int buy = -prices[0];

	//loop all stock prices
	for (int price : prices) {
		int sellOld = sell;
		//update sell, the profit of buy plus current stock price and substract the fee
		sell = max(sell, buy + price);
		//update buy, the profit of previous sell substrack the current stock price
		buy = max(buy, sellOld - price);
	}

	return sell;        
}