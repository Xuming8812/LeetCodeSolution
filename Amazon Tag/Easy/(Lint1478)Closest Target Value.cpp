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
    //sort so that we can use two pointers
    sort(array.begin(),array.end());
    //two pointers
    int start = 0, end = array.size()-1;
    //the distance of sum to target value
    int distance = INT_MAX;
    
    while(start<end){
        //sum equals to target, return
        if(array[start]+array[end] ==target){
            return target;
        }
        else if(array[start]+array[end] >target){
            //sum is bigger than target, move left
            end--;
        }
        else{
            //sum is smaller, update result and move right
            if(target-array[start]-array[end]<distance){
                distance = target-array[start]-array[end];
                result = array[start]+array[end];
            }
            start++;
        }
    }
    
    return result;
}