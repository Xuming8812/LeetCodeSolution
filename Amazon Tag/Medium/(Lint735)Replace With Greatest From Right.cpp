#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_map>

using namespace std;

/*
Given an array of integers, replace every element with the next greatest element (greatest element on the right side) in the array. 
Since there is no element next to the last element, 
replace it with -1. For example, if the array is [16, 17, 4, 3, 5, 2], then it should be modified to [17, 5, 5, 5, 2, -1]
*/ 

/**
 * @param nums: An array of integers.
 * @return: nothing
 */
void arrayReplaceWithGreatestFromRight(vector<int> &nums) {
    // Write your code here.
    stack<pair<int,int>> store;
    
    if(nums.empty()){
        return;
    }
    
    int length = nums.size();
    
    store.push({nums[length-1],nums[length-1]});
    
    for(int i = length-2;i>=1;i--){
        if(nums[i]<=store.top().second){
            store.push({nums[i],store.top().second});
        }
        else{
            store.push({nums[i],nums[i]});
        }
    }
    
    for(int i = 0;i<length-1;i++){
        nums[i] = store.top().second;
        store.pop();
    }
    
    nums[length-1] = -1;
}

