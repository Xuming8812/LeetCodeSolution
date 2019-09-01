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
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, 
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*/

/**
 * @param nums: A list of integer which is 0, 1 or 2 
 * @return: nothing
 */
void sortColors(vector<int> &nums) {
    // write your code here
    if(nums.empty()){
        return;
    }
    
    int leftIndex{0},rightIndex=nums.size()-1,index{0};
    
    while(index<=rightIndex){
        if(nums[index] == 0){
            swap(nums,index,leftIndex);
            leftIndex++;
            index++;
        }
        else if(nums[index] == 1){
            index++;
        }
        else{
            swap(nums,index,rightIndex);
            rightIndex--;
        }
    }

}

void swap(vector<int> &nums,int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}