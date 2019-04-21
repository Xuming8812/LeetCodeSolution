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
Given a list of non-negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.
*/
    
/**
 * @param nums: An array of non-negative integers.
 * @return: The maximum amount of money you can rob tonight
 */
int houseRobber2(vector<int> &nums) {
    // write your code here
    
    //corner case
    if(nums.empty()){
        return 0;
    }
    if(nums.size() == 1){
        return nums[0];
    }
    
    int length = nums.size();
    
    vector<int> dp(length);
    
    //rob second to last
    
    dp[0] = 0;
    dp[1] = nums[1];
    
    for(int i = 2;i<length;i++){
        dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
    }
    
    int result = dp[length-1];
    
    //rob 1st to second last
    dp[0] = nums[0];
    dp[1] = max(dp[0],nums[1]);
    
    for(int i = 2;i<length;i++){
        dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
    }
    
    return max(result,dp[length-2]);
}