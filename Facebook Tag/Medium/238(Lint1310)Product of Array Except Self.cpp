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
Given an array nums of n integers where n > 1,  
return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
*/

/**
 * @param nums: an array of integers
 * @return: the product of all the elements of nums except nums[i].
 */
vector<int> productExceptSelf(vector<int> &nums) {
    // write your code here
    //corner case
    if(nums.empty()){
        return {};
    }
    //initialize the result vector
    vector<int> result(nums.size());
    
    result[0] = 1;
    //result[i] = product of elements from nums[0] ... nums[i-1]
    for(int i = 1;i<nums.size();i++){
        result[i] = result[i-1]*nums[i-1];
    }
    //from right to left to calculate the product of elements from nums[len-1] to nums[i+1]
    int right = 1;
    
    for(int i = nums.size()-1;i>=0;i--){
        result[i] = result[i]*right;
        right *= nums[i];
    }
    
    return result;
}


//another version
vector<int> productExceptSelf(vector<int>& nums) {
    int totalProduct{1};
    int nonZero{1};
    int countZero{0};
    
    for(int i = 0;i<nums.size();i++){
        totalProduct *= nums[i];
        
        if(nums[i] == 0){
            countZero++;
            if(countZero >1){
                nonZero = 0;
            }
        }
        else{
            nonZero*=nums[i];
        }
        
    }
    
    vector<int> result;
    
    for(auto item : nums){
        if(item!=0){
            result.push_back(totalProduct/item);
        }
        else{
            result.push_back(nonZero);
        }
    }
    
    return result;
}