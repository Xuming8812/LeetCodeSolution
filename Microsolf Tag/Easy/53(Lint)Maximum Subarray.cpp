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
Given an array of integers, find a contiguous subarray which has the largest sum.
*/


/**
 * @param nums: A list of integers
 * @return: A integer indicate the sum of max subarray
 */
int maxSubArray(vector<int> &nums) {
    // write your code here
    
    if(nums.empty()) return 0;
    
    int length = nums.size();
    
    int sum =0;
    
    int result{INT_MIN};
    
    for(int i = 0;i<length;i++){
        sum += nums[i];
        result = max(sum,result);
        sum = max(sum,0);
    }
    
    return result;
}


int maxSubArray(vector<int>& nums) {
    
    if(nums.empty()){
        return 0;
    }
    
    if(nums.size() == 1){
        return nums[0];
    }
    
    int result{nums[0]};
    int localMax{INT_MIN};

    
    for(size_t i{1};i<nums.size();i++){
        localMax = max(nums[i],localMax+nums[i]);
        result = max(localMax,result);
    }
    
    return result;
  
}