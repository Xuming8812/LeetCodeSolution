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
*/

/**
 * @param A: an integer rotated sorted array
 * @param target: an integer to be searched
 * @return: an integer
 */
bool search(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    
    while (start <= end){
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[start] < nums[mid]){
            if (nums[start] <= target && target < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }else if(nums[start] > nums[mid]){
            if (nums[mid] < target && target <= nums[end])
                start = mid + 1;
            else
                end = mid - 1;
        }else {
            //If nums[start] == nums[mid], just move start to the next index. 
            //So the worst case, that the array's elements are same, is O(n).
            start++;
        }
    }
    
    return false;
}