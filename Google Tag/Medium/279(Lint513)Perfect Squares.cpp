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
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
*/


/**
 * @param n: a positive integer
 * @return: An integer
 */
int numSquares(int n){
    //corner case
    if (n < 1){
        return 0;
    }
        
    //initialize the dp vector
    vector<int> dp(n + 1, INT_MAX);
    //start with index 0
    dp[0] = 0;
    //1 to n, dp[i] is the number of number of perfect square numbers
    for (int i = 1; i <= n; ++i){
        //loop for all possible square numbers
        for (int j = 1; j * j <= i; ++j){
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    
    return dp[n];

}