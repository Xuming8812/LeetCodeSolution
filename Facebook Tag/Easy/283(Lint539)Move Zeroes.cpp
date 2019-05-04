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
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
*/

/**
 * @param nums: an integer array
 * @return: nothing
 */
void moveZeroes(vector<int> &nums) {
    // write your code here
    
    int index{0};
    //insert the non-zero element to right position
    for(int i=0;i<nums.size();i++){
        if(nums[i]){
            nums[index++] = nums[i];
        }
    }
    //set all elements behind by zeros
    for(int i = index;i<nums.size();i++){
        nums[i] = 0;
    }
}