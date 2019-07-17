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
Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. 
You need to output the maximum average value.
*/  



/**
 * @param nums: an array
 * @param k: an integer
 * @return: the maximum average value
 */
double findMaxAverage(vector<int> &nums, int k) {
    // Write your code here
    //define the prefix sum array
    vector<double> prefixSum(nums.size());
    //calculate the prefix sum
    prefixSum[0] = nums[0];
    
    for(int i = 1;i<nums.size();i++){
        prefixSum[i] = prefixSum[i-1]+nums[i];
    }
    
    double result=prefixSum[k-1];
    //loop for each window
    for(int i=k;i<nums.size();i++){
        result = max(result,(prefixSum[i]-prefixSum[i-k]));
    }
    
    return result/k;
}