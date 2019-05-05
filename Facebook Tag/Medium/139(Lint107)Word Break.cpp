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
    //get length of the given string
    int length = s.size();
    //get the max length of the words in the dict, in order to prune
    int maxLength = getMaxLength(dict);
    //1 dimension dp vector, dp[i] means s[0....i-1] whether can be broken
    vector<bool> dp(length+1);
    //set 
    dp[0] = true;
    //loop all position of the string
    for(int i = 1;i<=length;i++){
        
        //loop for all possible length
        for(int j = 1;j<=i && j<=maxLength;j++){
            //if s[0,i-j] can be broken, then if s[i-j,i-1] is a word, then s[0....i-1] can be broken
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
//the helper function to get the max length of the word in the dict in order to prune
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
    //corner case
    if(s.empty()){
        if(dict.empty()){
            return true;
        }
        else{
            return false;
        }
    }
    //base condition
    if(dict.count(s) == 1){
        return true;
    }
    
    bool result;
    //loop all possible split position
    for(size_t i{1};i<s.size();i++){
        //get the left and right part of the split
        string left = s.substr(0,i),right = s.substr(i);
        //if left is a word in the dict, dfs the right part
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
