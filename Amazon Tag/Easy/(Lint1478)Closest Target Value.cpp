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
Given an array, find two numbers in the array and their sum is closest to the target value but does not exceed the target value, return their sum.
*/   
    
    
/**
 * @param target: the target
 * @param array: an array
 * @return: the closest value
 */
int closestTargetValue(int target, vector<int> &array) {
    // Write your code here
    if(array.size()<2) return -1;
    
    int result = -1;
    
    sort(array.begin(),array.end());
    
    int start = 0, end = array.size()-1;
    
    int distance = INT_MAX;
    
    while(start<end){
        if(array[start]+array[end] ==target){
            return target;
        }
        else if(array[start]+array[end] >target){
            end--;
        }
        else{
            if(target-array[start]-array[end]<distance){
                distance = target-array[start]-array[end];
                result = array[start]+array[end];
            }
            start++;
        }
    }
    
    return result;
}