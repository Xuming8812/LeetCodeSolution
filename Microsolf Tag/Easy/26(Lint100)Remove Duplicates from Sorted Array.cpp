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
Given a sorted array, 'remove' the duplicates in place such that each element appear only once and return the 'new' length.

Do not allocate extra space for another array, you must do this in place with constant memory.
*/

/*
    * @param nums: An ineger array
    * @return: An integer
    */
int removeDuplicates(vector<int> &nums) {
    // write your code here
    if(nums.empty()){
        return 0;
    }
    
    int index = 1;
    
    for(int i = 1;i<nums.size();i++){
        if(nums[i] !=nums[i-1]){
            nums[index++] = nums[i];
        }
    }
    
    return index;
}