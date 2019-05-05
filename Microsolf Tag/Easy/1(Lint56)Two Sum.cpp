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
Given an array of integers, find two numbers such that they add up to a specific target number.
*/

/**
 * @param numbers: An array of Integer
 * @param target: target = numbers[index1] + numbers[index2]
 * @return: [index1, index2] (index1 < index2)
 */
vector<int> twoSum(vector<int> &numbers, int target) {
    // write your code here
    vector<int> result;
    //corner case
    if(numbers.empty()) return {};
    //use a dict to store the index of each number
    map<int,int>dict;
    //one pass
    for(int i=0;i<numbers.size();i++){
        //check if the target - current number is already met
        if(dict.find(target-numbers[i])!=dict.end()){
            return {dict[target-numbers[i]],i};
        }
        //save the index of current number
        dict[numbers[i]] = i;
    }

    return {-1,-1};
}