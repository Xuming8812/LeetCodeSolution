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
    
    if(numbers.empty()) return {};
    
    map<int,int>dict;
    
    for(int i=0;i<numbers.size();i++){
        if(dict.find(target-numbers[i])!=dict.end()){
            return {dict[target-numbers[i]],i};
        }
        
        dict[numbers[i]] = i;
    }

    return {-1,-1};
}