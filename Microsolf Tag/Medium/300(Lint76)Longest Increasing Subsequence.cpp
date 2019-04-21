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
Given a sequence of integers, find the longest increasing subsequence (LIS).
You code should return the length of the LIS.
*/

/**
 * @param nums: An integer array
 * @return: The length of LIS (longest increasing subsequence)
 */
int longestIncreasingSubsequence(vector<int> &nums) {
    // write your code here
    
    if(nums.empty()){
        return 0;
    }
    
    int length = nums.size();
    vector<int>dp(length);
    
    int result{INT_MIN};
    
    for(int i = 0;i<length;i++){
        dp[i] = 1;
        
        //for all elements before it and smaller than it
        for(int j = 0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        
        result = max(dp[i],result);
    }
    
    return result;
}