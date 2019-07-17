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
    //use hashmap to store the number of each letter
    map<char,int> dict;
    //count the number of each letter
    for(auto c : s){
        dict[c]++;
    }
    //see if the string has some letters with odd numbers
    bool isOdd=false;
    
    int result{0};
    //loop all unique letters
    for(auto item : dict){
        //add all letters with even numbers
        if(item.second%2 == 0){
            result+=item.second;
        }
        else{
            isOdd = true;
            result+=(item.second-1);
        }
    }
    //can add another letter with odd numbers
    if(isOdd){
        result++;
    }
    
    return result;
}