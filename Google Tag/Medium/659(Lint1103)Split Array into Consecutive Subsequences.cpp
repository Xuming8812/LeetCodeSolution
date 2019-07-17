#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<queue>
#include<sstream>
#include<set>

using namespace std;


/*
Given an integer array nums. You need to split nums into several (at least 2) subsequences,
 where each subsequence contains at least 3 consecutive integers.

Return whether you can make such a split.
*/

/**
 * @param nums: a list of integers
 * @return: return a boolean
 */
bool isPossible(vector<int> &nums) {
    // write your code here
    //建立可以加在某个连续子序列后的数字及其可以出现的次数之间的映射need
    unordered_map<int, int> count, need;
    //count the occurence of each number
    for (int num : nums){
        count[num]++;
    } 
    
    for (int num : nums) {
        //the element is already used
        if (count[num] == 0){
            continue;
        }
        //if the current number can be added to an existing subsequence, add it to a subsequence, and add the next element to need
        else if(need[num] > 0) {
            --need[num];
            ++need[num + 1];
        }
        //if the current number can be a start of a subsequence
        else if (count[num + 1] > 0 && count[num + 2] > 0) {
            --count[num + 1];
            --count[num + 2];
            ++need[num + 3];
        }
        else{
            return false;
        } 
        
        --count[num];
    }
    return true;
}