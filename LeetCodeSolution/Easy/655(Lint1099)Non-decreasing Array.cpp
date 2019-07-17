#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

/*
Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n)
*/


/**
 * @param nums: an array
 * @return: if it could become non-decreasing by modifying at most 1 element
 */
bool checkPossibility(vector<int> &nums) {
    // Write your code here
    int index = -1;
    //corner case
    if(nums.size()<3){
        return true;
    }
    //loop all numbers to find the index where nums[i]>nums[i+1]
    for(int i = 0;i<nums.size()-1;i++){
        if(nums[i]>nums[i+1]){
            //if more than this index exists, return false
            if(index!=-1){
                return false;
            }
            
            index = i;
        }
    }
    //if already in non-decreasing order, return true
    if(index==-1){
        return true;
    }
    //if the index is 0 or second last, return true
    if(index==0 || index==nums.size()-2){
        return true;
    }
    //the only possibility to make the the whole vector to be non-decreasing
    if(nums[index]<=nums[index+2] || nums[index-1]<=nums[index+1]){
        return true;
    }
    
    return false;
}