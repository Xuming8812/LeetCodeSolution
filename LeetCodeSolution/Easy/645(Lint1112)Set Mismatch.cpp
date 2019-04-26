#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given an array nums representing the data status of this set after the error. 
Your task is to firstly find the number occurs twice and then find the number that is missing. 
Return them in the form of an array.
*/    

/**
 * @param nums: an array
 * @return: the number occurs twice and the number that is missing
 */
vector<int> findErrorNums(vector<int> &nums) {
    // Write your code here
    vector<int> result;
    if(nums.size()<2) return result;
    
    for(int i = 0;i<nums.size();i++){
        int index = abs(nums[i])-1;
        
        if(nums[index]<0){
            result.push_back(index+1);
        }
        else{
            nums[index] = -nums[index];
        }
    }
    
    for(int i = 0;i<nums.size();i++){
        if(nums[i]>0){
            result.push_back(i+1);
        }
    }
    
    return result;
}