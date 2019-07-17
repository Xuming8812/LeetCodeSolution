#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_map>

using namespace std;

/*
Given an array of n integers nums and a target, find the number of index triplets i, j, k 
with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
*/


/**
 * @param nums:  an array of n integers
 * @param target: a target
 * @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
 */
int threeSumSmaller(vector<int> &nums, int target) {
    // Write your code here
    //corner case
    if (nums.size() < 3){
        return 0;
    } 
    
    int result = 0, length = nums.size();
    //sort
    sort(nums.begin(), nums.end());
    //loop all elements
    for (int i = 0; i < length - 2; ++i) {
        
        int left = i + 1, right = length - 1;
        //two pointers
        while (left < right) {
            if (nums[i] + nums[left] + nums[right] < target) {
                result += right - left;
                left++;
            } else {
                right--;
            }
        }
    }
    return result;
}