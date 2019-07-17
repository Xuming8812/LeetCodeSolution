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
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. 
You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
*/
    
    
/**
 * @param cost: an array
 * @return: minimum cost to reach the top of the floor
 */
int minCostClimbingStairs(vector<int> &cost) {
    // Write your code here
    //corner case
    if(cost.size()<2) return 0;
    if(cost.size()==2) return min(cost[0],cost[1]);
    
    int length = cost.size();
    cost.push_back(0);
    //the dp vector
    vector<int> dp = cost;

    for(int index = 2;index<=length;index++){
        dp[index] = min(dp[index-1],dp[index-2])+cost[index];
    }
    
    return dp[length];
}