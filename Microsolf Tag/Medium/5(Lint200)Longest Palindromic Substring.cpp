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
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/


/**
 * @param s: input string
 * @return: the longest palindromic substring
 */
string longestPalindrome(string &s) {
    // write your code here
    string result;
    
    if(s.empty()) return result;
    
    for(int i = 0;i<s.size();i++){
        
        string odd = findlongestFrom(s,i,i);
        string even = findlongestFrom(s,i,i+1);
        
        if(odd.size()>result.size()){
            result = odd;
        }
        
        if(even.size()>result.size()){
            result = even;
        }
    }
    
    return result;
}

string findlongestFrom(string& s, int left, int right) {
    string result{};
    
    while(left>=0 && right<s.size()){
        if(s[left]!=s[right]){
            break;
        }
        
        result = s.substr(left,right-left+1);
        left--;
        right++;
    }
    
    return result;
}]