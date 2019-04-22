#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
*/


/**
 * @param A: A list of integers
 * @return: A boolean
 */

//dp version
bool canJump(vector<int> &A) {
    // write your code here
    if(A.empty()){
        return false;
    }
    
    vector<bool> dp(A.size());
    
    dp[0] = true;
    
    for(int i = 1; i<A.size();i++){
        for(int j = 0;j<i;j++){
            if(dp[j] && j + A[j]>=i){
                dp[i] = true;
                break;
            }
        }
    }
    
    return dp[A.size()-1];
}

//greedy version
bool canJump(vector<int> &A) {
    // write your code here
    if(A.empty()){
        return false;
    }
    
    int farthest = A[0];
    
    for(int i = 1;i<A.size();i++){
        if(i<=farthest && A[i]+i >= farthest){
            farthest = A[i]+i;
        }
    }
    
    return farthest>=A.size()-1;
}