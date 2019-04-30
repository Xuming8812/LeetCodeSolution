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
There are n coins with different value in a line. Two players take turns to take one or two coins from left side until there are no more coins left. The player who take the coins with the most value wins.

Could you please decide the first player will win or lose?
*/ 
    
    
/**
 * @param values: a vector of integers
 * @return: a boolean which equals to true if the first player will win
 */
bool firstWillWin(vector<int> &values) {
    // write your code here
    
    int length = values.size();
    
    if(length<3) return true;
    
    
    //sum[i] is used to store the total value of the ith to the n-1 th coins(in other words, last n-i coins)
    vector<int> sum(length);
    
    //the maximum value that can be taken be from the ith to the n-1 th coins by the first player
    vector<int> dp(length);
    //note that sum[i]-f[i] is the amount that the second player can get from the ith to n-1 th coins
    dp[length-1] = sum[length-1] = values[length-1];
    dp[length-2] = sum[length-2] = values[length-1]+values[length-2];
    
    for(int i = length-3;i>=0;i--){
        sum[i] = sum[i+1] + values[i];
        
        dp[i] = max(sum[i+1]-dp[i+1]+values[i], sum[i+2]-dp[i+2]+values[i]+values[i+1]);
    }
    
    return dp[0]>sum[0]-dp[0];
}