#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_set>

using namespace std;

/*
Given a set of positive integers, write a function to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and 
the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.
*/

/**
 * @param nums: the given array
 * @return: the minimum difference between their sums 
 */
int findMin(vector<int> &nums){
    // Calculate sum of all elements
    int n = nums.size();
    int sum = 0; 
    
    //sum up
    for (int i = 0; i < n; i++){
        sum += nums[i];
    }
        
    //用dp[i]表示和为i的集合是否存在
    vector<bool> dp(sum/2+1,false);
    
    dp[0] = true;

    for (int i=0; i < n; i++){
        for (int j=sum/2; j>=nums[i]; j--){
            dp[j] = dp[j] || dp[j-nums[i]];
        }
    }

    // Initialize difference of two sums. 
    int diff = INT_MAX;

    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    for (int j=sum/2; j>=0; j--){
        // Find the 
        if (dp[j] == true){
            diff = sum-2*j;
            break;
        }
    }
    
    return diff;
}