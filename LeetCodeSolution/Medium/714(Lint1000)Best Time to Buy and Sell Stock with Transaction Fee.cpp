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
Given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee 
representing a transaction fee. (You need to pay fee only on selling.)

You can complete as many transactions as you like, but you need to pay the transaction fee for each transaction. 
You can not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.
*/ 

/**
 * @param prices: a list of integers
 * @param fee: a integer
 * @return: return a integer
 */
int maxProfit(vector<int> &prices, int fee) {
    //use sell to store the maximum profit if we sell stock today
    int sell = 0;
    //use buy to store the maximum profit if we buy stock or skip
    int buy = -prices[0];

    //loop all stock prices
    for (int price : prices) {
        int sellOld = sell;
        //update sell, the profit of buy plus current stock price and substract the fee
        sell = max(sell, buy + price - fee);
        //update buy, the profit of previous sell substrack the current stock price
        buy = max(buy, sellOld - price);
    }
    
    return sell;
}