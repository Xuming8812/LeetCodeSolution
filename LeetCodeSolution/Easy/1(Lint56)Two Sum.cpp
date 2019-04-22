#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice
*/ 
    

/**
 * @param numbers: An array of Integer
 * @param target: target = numbers[index1] + numbers[index2]
 * @return: [index1, index2] (index1 < index2)
 */
vector<int> twoSum(vector<int> &numbers, int target) {
    // write your code here
    vector<int> result;
    
    if(numbers.size()<2){
        return result;
    }
    
    map<int,int>dict;
    
    for(int i = 0;i<numbers.size();i++){
        if(dict.find(target-numbers[i])!=dict.end()){
            result.push_back(dict[target-numbers[i]]);
            result.push_back(i);
            
            return result;
        }
        
        dict[numbers[i]] = i;
    }
    
    return {-1,-1};
}