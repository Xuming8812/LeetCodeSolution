#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_map>

using namespace std;

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
*/  

/**
 * @param prices: Given an integer array
 * @return: Maximum profit
 */
int maxProfit(vector<int>& prices) {
    int result{0};
    
    for(int i = 1;i<prices.size();i++){
        if(prices[i]>prices[i-1]){
            result +=(prices[i] - prices[i-1]);
        }
    }
    
    return result;
}