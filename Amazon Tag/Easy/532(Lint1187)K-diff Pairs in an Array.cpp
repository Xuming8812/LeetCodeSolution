#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. 
Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.
*/    


/**
 * @param nums: an array of integers
 * @param k: an integer
 * @return: the number of unique k-diff pairs
 */
int findPairs(vector<int> &nums, int k) {
    // Write your code here
    
    //corner case 
    
    
    if(nums.empty()){
        return 0;
    }
    
    //use a hashmap to store numbers
    map<int,int> dict;
    
    for(auto item : nums){
        dict[item]++;
    }
    
    //use a set to store k-diff pairs
    set<pair<int,int>> results;
    
    //loop all items
    for(auto item : nums){
        if(k == 0){
            if(dict[item]>=2){
                results.insert({item,item});
            }
        }
        else{
            if(dict.find(item-k)!=dict.end()){
                results.insert({item-k,item});
            }
            if(dict.find(item+k)!=dict.end()){
                results.insert({item,item+k});
            }
        }
    }
    
    return (int)results.size();
    
}