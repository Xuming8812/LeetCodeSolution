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
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.
*/    


/**
 * @param s: a string,  encoded message
 * @return: an integer, the number of ways decoding
 */
int numDecodings(string s) {
    //corner case
    if(s.empty()) return 0;
    if(s[0] == '0') return 0;
    
    //build the dp vector, dp[i] the number of ways of decoding of s[0...i]
    vector<int> dp(s.size(),0);
    
    //the first digit must be decode
    dp[0] = 1;
    //loop all digits
    for(int i = 1;i<s.size();i++){
        //the initial value is the previous number of ways of decode
        dp[i] = dp[i-1];
        //if the current num is '0'
        if (s[i] == '0') {
            //if unable to decode
            if (s[i-1] != '1' && s[i-1] != '2') return 0;
            //combine this '0' with previous number
            dp[i] = i > 1? dp[i-2]: 1;
            
        } else if (s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7')) {
            //the current number can be combined with previous number to become a valid number
            dp[i] += i > 1? dp[i-2]: 1;
        }                 
    }
    
    return dp[s.size()-1];      
}