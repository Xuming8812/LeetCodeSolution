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
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
*/

vector<vector<int>> powerset;
vector<int> subset;


/**
 * @param nums: A set of numbers.
 * @return: A list of lists. All valid subsets.
 */
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //sort the array
    sort(nums.begin(),nums.end());
    //call the helper function to backtrack
    backtrack(nums,0);
    
    return powerset;
    
}
//helper function to backtrack to get the subset
void backtrack(vector<int>& nums, int start){
    //save the current subset to the powerset vector
    powerset.push_back(subset);
    
    //loop all the elements start with the given index
    for(int i = start;i<nums.size();++i){
        
        //skip the duplicate combinations, because the combinations with the current element has been collected
        if(i>start && nums[i] == nums[i-1]){
            continue;
        }
        //save
        subset.push_back(nums[i]);
        //explore
        backtrack(nums,i+1);
        //remove
        subset.pop_back();
    }
    
}