#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given an array of n integers, and a moving window(size k), 
move the window at each iteration from the start of the array, find the sum of the element inside the window at each moving.
*/

/**
 * @param nums: a list of integers.
 * @param k: length of window.
 * @return: the sum of the element inside the window at each moving.
 */
vector<int> winSum(vector<int> &nums, int k) {
    // write your code here
    vector<int> result;
    //corner case
    if(nums.empty() || nums.size()<k){
        return result;
    }
    
    int currentSum{0};
    //get the first k elements' sum
    for(int i = 0;i<k;i++){
        currentSum+=nums[i];
    }
    
    result.push_back(currentSum);
    //for each iteration, add current element, pop the first element
    for(int i = k;i<nums.size();i++){
        currentSum = currentSum+nums[i]-nums[i-k];
        result.push_back(currentSum);
    }
    
    return result;
}