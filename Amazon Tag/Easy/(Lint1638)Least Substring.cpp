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
    //the pointer
    int start = 0;
    
    while(start<s.size()){
        //update result
        result++;
        //reset the length of the substring
        int length = 1;
        //get the substring with same letters and length does not exceed k
        while(length<k && start+length<s.size() && s[start] == s[start+length]){
            length++;
        }
        //update the pointer
        start = start+length;
    }
    
    return result;
}