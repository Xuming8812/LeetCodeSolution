#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_map>

using namespace std;

/*
Given an array of strings, group anagrams together.
*/

/**
 * @param strs: the given array of strings
 * @return: The anagrams which have been divided into groups
 */
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string,vector<string>> dict;
    vector<vector<string>> result;
    
    for(auto item : strs){
        string temp{item};
        sort(temp.begin(),temp.end());
        dict[temp].push_back(item);
    }
    
    for(auto item : dict){
        result.push_back(item.second);
    }
    
    return result;
}