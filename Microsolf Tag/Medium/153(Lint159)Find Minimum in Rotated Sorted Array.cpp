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
Find the minimum element.
*/

/**
 * @param nums: a rotated sorted array
 * @return: the minimum number in the array
 */
int findMin(vector<int> &nums) {
    // write your code here
    int left = 0;
    int right = nums.size()-1;
    
    int target = nums[right];
    
    while(left < right){
        int middle = left + (right-left)/2;
        
        if(nums[middle]<=target){
            right = middle;
        }
        else{
            left = middle+1;
        }
    }
    
    return nums[left];
}