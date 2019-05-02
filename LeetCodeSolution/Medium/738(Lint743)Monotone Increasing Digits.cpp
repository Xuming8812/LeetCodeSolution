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
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
*/
    
/**
 * @param s: the maximum length of s is 1000
 * @return: the longest palindromic subsequence's length
 */
int longestPalindromeSubseq(string &s) {
    // write your code here
    if(s.empty()){
        return 0;
    }
    
    int length = s.size();
    
    vector<vector<int>> dp(length,vector<int>(length));
    
    for(int i = length-1;i>=0;i--){
        dp[i][i]=1;
        for(int j = i+1;j<length;j++){
            if(s[i] == s[j]){
                dp[i][j]=dp[i+1][j-1]+2;
            }
            else{
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
        
    return dp[0][length-1];
}