#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a string, determine if a permutation of the string could form a palindrome.
*/


/**
 * @param s: the given string
 * @return: if a permutation of the string could form a palindrome
 */
bool canPermutePalindrome(string &s) {
    // write your code here
    map<char,int> dict;
    
    for(auto item:s){
        dict[item]++;
    }
    
    int count = 0;
    
    for(int item:dict){
        if(item.second%2==1){
            count++;
        }
    }
    
    return count<2;
}