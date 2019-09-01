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
Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.    
*/    
    
/**
 * @param str: s string
 * @return: return an integer, denote the number of the palindromic substrings
 */
int countPalindromicSubstrings(string &str) {
    // write your code here
    
    //corner case
    if(str.empty()){
        return 0;
    }
    
    int result{0};
    int length = str.size();
    
    //dp matrix, dp[i][j] is whether str[j...i] is a palindromic
    vector<vector<int>> dp(length,vector<int>(length));
    
    for(int i = 0;i<length;i++){
        for(int j=0;j<=i;j++){
            
            //if str[j...i] is palindromic, firstly str[j] == str[i]
            //if the substr is long enouth(i-j>=2), str[j+1...i-1] should also be palindromic
            if(str[i] == str[j]){
                if(i-j<=2){
                    dp[i][j] = 1;
                }
                else if(i>=1 && j+1<length && dp[i-1][j+1]){
                    dp[i][j] = 1;
                }
                
                result += dp[i][j];
            }
        }
    }    
    return result;
}