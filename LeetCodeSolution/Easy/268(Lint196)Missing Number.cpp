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
In a 2D grid from (0, 0) to (N-1, N-1), every cell contains a 1, except those cells in the given list mines which are 0. 
What is the largest axis-aligned plus sign of 1s contained in the grid? Return the order of the plus sign. 
If there is none, return 0.

An "axis-aligned plus sign of 1s of order k" has some center grid[x][y] = 1 along 
with 4 arms of length k-1 going up, down, left, and right, and made of 1s. 
This is demonstrated in the diagrams below. Note that there could be 0s or 1s beyond the arms of the plus sign, 
only the relevant area of the plus sign is checked for 1s.
*/


/**
 * @param nums: An array of integers
 * @return: An integer
 */
int findMissing(vector<int>& nums){
    
    int result{0};
    //corner case
    if(nums.empty()){
        return result;
    }
    //get the length of the input vector
    int length = nums.size();
    //make the vector's length to be length +1, so that nums[length] is valid
    nums.push_back(length);
    //loop all elements, use nums[i] as index, reverse nums[index]
    for(int i = 0;i<length;i++){
        
        if(nums[i] == 0){
            result = i;
        }
        
        int index = abs(nums[i]);
        
        nums[index] = -nums[index];

    }
    
    //see which index is not reversed
    for(int i = 0;i<nums.size();i++){
        if(nums[i]>0){
            return i;
        }
    }
    
    return result;
}