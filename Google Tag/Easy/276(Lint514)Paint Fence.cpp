#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;


/*
There is a fence with n posts, each post can be painted with one of the k colors.
You have to paint all the posts such that no more than two adjacent fence posts have the same color.
Return the total number of ways you can paint the fence.
*/  



/**
 * @param n: non-negative integer, n posts
 * @param k: non-negative integer, k colors
 * @return: an integer, the total number of ways
 */
/*
当有1个栅栏的时候，有k种；
当有2个栅栏的时候，有kk种；
当有3个栅栏的时候，分两种情况：
a.如果3和2颜色相同，则有k(k-1)。
b.如果3和2颜色不同，则有(kk)(k-1)。
则状态转移方程为：dp[i] = (k - 1) * (dp[i-1] + dp[i-2]);
*/
int numWays(int n, int k) {
    // write your code here
    if(k <=0){
        return 0;
    }
    
    if(n==1){
        return k;
    }
    
    vector<int> dp(n+1);
    
    dp[1] = k;
    dp[2] = k*k;
    
    for(int i=3;i<=n;i++){
        dp[i] = (k-1)*(dp[i-1]+dp[i-2]);
    }
    
    return dp[n];
}