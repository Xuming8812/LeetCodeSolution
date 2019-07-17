#include<map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


/*
Given an unsorted array nums, reorder it in-place such that

nums[0] <= nums[1] >= nums[2] <= nums[3]...
*/


/*
 * @param nums: A list of integers
 * @return: nothing
 */
void wiggleSort(vector<int> &nums) {
    // write your code here
    
    if(nums.empty()){
        return;
    }
    //one pass
    for(int i=1;i<nums.size();i++){
        //the odd index
        if(i%2 == 1){
            //invalid, then swap it and its previous one
            if(nums[i]<nums[i-1]){
                swap(nums[i],nums[i-1]);
            }
        }
        else{
            //invalid, then swap it and its previous one
            if(nums[i]>nums[i-1]){
                swap(nums[i],nums[i-1]);
            }
        }
    }
}