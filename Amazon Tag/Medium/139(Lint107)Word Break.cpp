#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<bitset>
#include<unordered_set>

using namespace std;

/*
Given a string s and a dictionary of words dict, determine if s can be break into a space-separated sequence of one or more dictionary words.
*/

//dp version

/*
* @param s: A string
* @param dict: A dictionary of words dict
* @return: A boolean
*/
bool wordBreak(string &s, unordered_set<string> &dict) {
    // write your code here
    
    int length = s.size();
    
    int maxLength = getMaxLength(dict);
    
    vector<bool> dp(length+1);
    
    dp[0] = true;
    
    for(int i = 1;i<=length;i++){
        
        //loop for all possible length
        for(int j = 1;j<=i && j<=maxLength;j++){
            if(dp[i-j]){
                string temp = s.substr(i-j,j);
                if(dict.find(temp)!=dict.end()){
                    dp[i] = true;
                }
            }
        }
    }
    
    return dp[length];
}

int getMaxLength(unordered_set<string> &dict){
    int result{0};
    
    for(auto item : dict){
        result = max((int)item.size(),result);
    }
    
    return result;
}

//dfs version

/*
* @param s: A string
* @param dict: A dictionary of words dict
* @return: A boolean
*/
bool wordBreak(string &s, unordered_set<string> &dict) {
    // write your code here
    
    if(s.empty()){
        if(dict.empty()){
            return true;
        }
        else{
            return false;
        }
    }
      
    if(dict.count(s) == 1){
        return true;
    }
    
    bool result;
    
    for(size_t i{1};i<s.size();i++){
        string left = s.substr(0,i),right = s.substr(i);
        
        if(dict.count(left) == 1){
            if(right!=""){
                return wordBreak(right,dict);
            }
            else{
                return true;
            }
        }
    }
    
    return result;   
}
