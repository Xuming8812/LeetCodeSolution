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
Given an array of strings, group anagrams together.
*/    
    
/**
 * @param strs: the given array of strings
 * @return: The anagrams which have been divided into groups
 */
vector<vector<string>> groupAnagrams(vector<string> &strs) {
    // write your code here
    //use a hash map to group anagrams
    map<string,vector<int>> store;
    
    vector<vector<string>> result;
    //corner case
    if(strs.empty()){
        return result;
    }
    //get the sorted form of the string and use it as the key and store in haspmap
    for(int i = 0;i<strs.size();i++){
        string temp = anagrams(strs[i]);
        
        store[temp].push_back(i);
    }
    //store the grouped result
    for(auto item: store){ 
        result.push_back(item.second);
    }
    
    return result;
}
//helper function to get the sorted string of the input string
string anagrams(string input){
    string result = input;
    sort(result.begin(),result.end());
    return result;
}