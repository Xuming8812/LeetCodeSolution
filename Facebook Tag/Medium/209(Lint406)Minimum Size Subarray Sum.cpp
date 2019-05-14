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
Given an array of n positive integers and a positive integer s, 
find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return -1 instead.
*/


/**
 * @param nums: an array of integers
 * @param s: An integer
 * @return: an integer representing the minimum size of subarray
 */
int minimumSize(vector<int> &nums, int s) {
    // write your code here
    //corner case
    if(nums.empty()){
        return -1;
    }
    //initialize the result
    int result = nums.size()+1;
    //two pointers
    int left{0},right{0},sum = 0;
    
    while(right<nums.size()){
        //while sum is smaller than target, move window to the right
        while(right<nums.size() && sum<s){
            sum+=nums[right];
            right++;
        }
        //if the window sum is still smaller than target and reach the boundary, stop searching
        if(sum < s){
            break;
        }
        //move the window left, if possible
        while(left < right && sum >= s){
            sum -= nums[left];
            left++;
        }
        //update result
        result = min(result, right-left+1);
    }
    
    if(result == nums.size()+1){
        return -1;
    }
    else{
        return result;
    }
}