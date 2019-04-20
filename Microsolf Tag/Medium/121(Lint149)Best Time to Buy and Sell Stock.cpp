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

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

/**
 * @param prices: Given an integer array
 * @return: Maximum profit
 */
int maxProfit(vector<int> &prices) {
    // write your code here
    
    int result{0}, minValue= INT_MAX;
    
    for(auto item : prices)
    {
        minValue = min(minValue,item);
        
        result = max(result,item - minValue);
    }
    
    return result;
}