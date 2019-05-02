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
Given a string, find the length of the longest substring without repeating characters.
*/ 

/**
 * @param s: a string
 * @return: an integer
 */
int lengthOfLongestSubstring(string &s) {
    // write your code here
    int result{0};
    
    if(s.empty()){
        return result;
    }
    
    int index =0,start = 0;
    int length = s.size();
    
    set<char> dict;
    
    while(index<length){
        char current = s[index];
        if(dict.count(current)>0){
            result = max(result, index-start);
            dict.erase(s[start]);
            start++;
        }
        else{
            dict.insert(current);
            index++;
        }
    }
    
    result = max(result, index-start);
    
    return result;
}    

//better version
int lengthOfLongestSubstring(string s) {
    
    int result{0}, left{0}, right{0};
    
    map<char,int> dict;
    
    while(right<s.size()){
        char current = s[right];
        
        if(dict.count(current) == 1 && dict[current]>=left){
            left = dict[current]+1;
        }
        else{
            dict[current] = right;
            right++;
        }
        
        if(right-left>=result){
            result = right-left;
        }

    }
            
    return result;
}