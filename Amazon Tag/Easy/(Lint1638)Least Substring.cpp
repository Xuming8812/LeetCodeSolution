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
Given a string containing n lowercase letters, the string needs to be divided into several continuous substrings, 
the letter in the substring should be same, 
and the number of letters in the substring does not exceed k, and output the minimal substring number meeting the requirement.
*/    
    
/**
 * @param s: the string s
 * @param k: the maximum length of substring
 * @return: return the least number of substring
 */
int getAns(string &s, int k) {
    // Write your code here
    
    int result{0};
    
    int start = 0;
    
    while(start<s.size()){
        result++;
        
        int length = 1;
        
        while(length<k && start+length<s.size() && s[start] == s[start+length]){
            length++;
        }
        
        start = start+length;
    }
    
    return result;
}