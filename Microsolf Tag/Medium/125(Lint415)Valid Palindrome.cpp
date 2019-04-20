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
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
*/

/**
 * @param s: A string
 * @return: Whether the string is a valid palindrome
 */
bool isPalindrome(string &s) {
    // write your code here
    
    if(s.empty()){
        return true;
    }
    
    transform(s.begin(),s.end(),s.begin(),::tolower);
    
    int left{0},right =s.size()-1;
    
    while(left<right){
        if(!isValid(s[left])){
            left++;
            continue;
        }
        if(!isValid(s[right])){
            right--;
            continue;
        }
        
        if(s[left]!=s[right]){
            return false;
        }
        
        left++;
        right--;       
    }
    
    return true;
}

bool isValid(char c)
{
    if(c>='0'&&c<='9'){
        return true;
    }
    if(c>='a'&&c<='z'){
        return true;
    }
    
    return false;
}

