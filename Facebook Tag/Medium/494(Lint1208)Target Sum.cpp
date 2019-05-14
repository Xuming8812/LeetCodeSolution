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
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. 
Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.
*/


/**
 * @param nums: the given array
 * @param s: the given target
 * @return: the number of ways to assign symbols to make sum of integers equal to target S
 */
int findTargetSumWays(vector<int> &nums, int s) {
    // Write your code here
    //corner case
    if(nums.empty()){
        return result;
    }
    //get length of input vector
    int length = nums.size();
    //initialize the sum array for prune
    vector<int> sum(length);
    //save the sum, sum[i] is the sum from index i to the end of the vector
    sum[length-1] = nums[length-1];
    
    for(int i = length-2;i>=0;i--){
        sum[i] = sum[i+1]+nums[i];
    }
    //special case, if the target is too big or too small
    if(s>sum[0] || (s<0&&s<-sum[0])){
        return result;
    }
    //call the helper function
    helper(nums,0,0,s,sum);
    
    return result;
    
}

//helper function to dfs all possiblilities
void helper(vector<int> &nums, int index, int current, int target, vector<int>& sumArray){
    //when the index reach the end, stop calling
    if(index == nums.size()){
        //see if get the target
        if(current == target){
            result++;
        }
        
        return;
    }
    //dfs, only when it`s possible to move forward
    if(abs(target - current) <= sumArray[index]){
        //use '+' in this number
        helper(nums,index+1,current+nums[index],target,sumArray);
        //use '-' in the number
        helper(nums,index+1,current-nums[index],target,sumArray);
    }
}

int result{0};