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
    //corner case
    if(s.empty()){
        return true;
    }
    //tranform all letter to lower case
    transform(s.begin(),s.end(),s.begin(),::tolower);
    //left and right pointer
    int left{0},right =s.size()-1;
    //compare left and right 
    while(left<right){
        //if current left char is not valid, continue
        if(!isValid(s[left])){
            left++;
            continue;
        }
        //if current right char is not valid, continue
        if(!isValid(s[right])){
            right--;
            continue;
        }
        //see if left char equals right char
        if(s[left]!=s[right]){
            return false;
        }
        //move left and right pointer
        left++;
        right--;       
    }
    
    return true;
}
//helper function to see if the current char is digit or letter
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

