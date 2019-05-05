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
Given a set of distinct integers, return all possible subsets.
*/


/**
 * @param nums: A set of numbers
 * @return: A list of lists
 */
vector<vector<int>> subsets(vector<int> &nums) {
    // write your code here
    //corner case
    if(nums.empty()){
        powerset.push_back({});
        return powerset;
    }
    //sort first
    sort(nums.begin(),nums.end());
    //call helper function
    dfs(nums,0,{});
    
    return powerset;
}
//helper function to use backtrack to create subset
void dfs(vector<int>& nums, int index, vector<int> chosen){
    //save this subset
    powerset.push_back(chosen);
    //skip the whole set
    if(index == nums.size()){
        return;
    }
    //loop all elements 
    for(int i = index;i<nums.size();i++){
        //try this element
        chosen.push_back(nums[i]);
        //explore
        dfs(nums,i+1,chosen);
        //untry
        chosen.pop_back();
    }
}

vector<vector<int>> powerset;