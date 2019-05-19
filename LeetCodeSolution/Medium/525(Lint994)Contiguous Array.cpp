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
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
*/

/**
 * @param nums: a binary array
 * @return: the maximum length of a contiguous subarray
 */
int findMaxLength(vector<int> &nums) {
    // Write your code here
    
    //corner case
    if(nums.empty()){
        return 0;
    }
    
    //set the 0 element to -1, so that the sum of the subarray with equal number of 1 and 0 will be sum up to 0
    for(int i=0;i<nums.size();i++){
        if(nums[i] == 0){
            nums[i] = -1;
        }
    }
    
    int result{0};
    //the map to store the index of one certain occurs the first time
    map<int,int> store;
    //
    store[0]= -1;
    
    //the variable to store the sum from 0 to ith element 
    int sum{0};
    //loop all elements
    for(int i =0;i<nums.size();i++){
        //sum up
        sum+=nums[i];
        //the sum already occurs, means the subarry between has equal number of 1 and 0
        if(store.find(sum)!=store.end()){
            //update the largest length
            result = max(result, i - store[sum]);
        }
        else{
            //record the sum and its index
            store[sum] = i;
        }
    }
    
    return result;
}