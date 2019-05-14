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
Given an integer array nums with all positive numbers and no duplicates, 
find the number of possible combinations that add up to a positive integer target.
*/

/**
 * @param nums: an integer array and all positive numbers, no duplicates
 * @param target: An integer
 * @return: An integer
 */
int backPackVI(vector<int> &nums, int target) {
    // write your code here
    if(nums.empty()){
        return 0;
    }
    //create the dp vector
    vector<int> dp(1+target);
    //get the length of the input vector
    int length = nums.size();
    //set dp[0]
    dp[0] = 1;
    //loop each number smaller or equal to target
    for(int i = 1; i<= target;i++){
        //loop all element in the vector
        for(int j = 0;j<length;j++){
            //current number is bigger than the element
            if(i - nums[j]>=0){
                //use the previous result to update the current result
                dp[i]+=dp[i - nums[j]];
            }
        }
    }
    
    return dp[target];
}