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
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
You are given a target value to search. If found in the array return its index, otherwise return -1.
Consider the duplicates
*/

int findMin(vector<int>& nums) {
    if(nums.empty()) return 0;
    if(nums.size()==1) return nums[0];
    
    int left = 0,right = nums.size()-1;
    
    while(nums[left] == nums[right] && left<right){
        right--;
    }
    
    while(left<right){
        int mid = left+(right-left)/2;
        
        if(nums[mid]<=nums[right]){
            right = mid;
        }
        else{
            left = mid+1;
        }
    }
    
    return nums[left];
}