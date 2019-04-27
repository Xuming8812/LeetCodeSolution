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
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
*/  

/**
 * @param s: a string which consists of lowercase or uppercase letters
 * @return: the length of the longest palindromes that can be built
 */
int longestPalindrome(string &s) {
    // write your code here
    if(s.empty()) return 0;
    
    map<char,int> dict;
    
    for(auto c : s){
        dict[c]++;
    }
    
    bool isOdd=false;
    
    int result{0};
    
    for(auto item : dict){
        if(item.second%2 == 0){
            result+=item.second;
        }
        else{
            isOdd = true;
            result+=(item.second-1);
        }
    }
    
    if(isOdd){
        result++;
    }
    
    return result;
}