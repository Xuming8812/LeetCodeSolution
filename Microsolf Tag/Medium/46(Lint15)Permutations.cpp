#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

/*
Given a list of numbers, return all possible permutations.
*/

/*
* @param nums: A list of integers.
* @return: A list of permutations.
*/
vector<vector<int> > permute(vector<int> nums) {
    
    vector<vector<int> > res;
    int n = nums.size();
    if (n == 0) {
        res.push_back(vector<int>());
        return res;
    }

    helper(res, nums, n - 1);
    
    return res;
}

void helper(vector<vector<int> > &res, vector<int> nums, int n){
    
    if(n == 0){
        res.push_back(nums);
    }
    
    for(int i = 0 ; i <= n; i++){
        swap(nums[i], nums[n]);
        helper(res, nums, n - 1);
        swap(nums[i], nums[n]);
    }
}


// a more intrutive method
vector<vector<int>> permute(vector<int>& nums) {
    
    vector<int> chosen;
    
    permuteHelper(nums, chosen);
    
    return result;
    
}

void permuteHelper(vector<int>& nums, vector<int> chosen){
    if(chosen.size() == nums.size()){
        result.push_back(chosen);
        return;
    }
    
    for(int i = 0;i<nums.size();i++){
        
        auto pos = find(chosen.begin(),chosen.end(),nums[i]);
        
        if(pos == chosen.end()){
            chosen.push_back(nums[i]);          //choose
        
            permuteHelper(nums, chosen);        //choose

            chosen.pop_back();                  //unchoose
        }
    }        
}


vector<vector<int>> result;