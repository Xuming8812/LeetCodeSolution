#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, 
then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.
*/



/**
 * @param nums: an array
 * @return: the shortest subarray's length
 */
int findUnsortedSubarray(vector<int> &nums) {
    // Write your code here
    
    vector<int> sortedVector = nums;
    //sort the vector
    sort(sortedVector.begin(),sortedVector.end());
    
    int left = 0;
    int right = nums.size()-1;
    //find the first element that needs to be sorted
    while(left<nums.size() && nums[left] == sortedVector[left]){
        left++;
    }
    //find the last element that needs to be sorted
    while(left<right&&nums[right] == sortedVector[right]){
        right--;
    }
    
    return right-left+1;
}