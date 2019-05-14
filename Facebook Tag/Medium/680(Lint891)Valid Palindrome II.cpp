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
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.
*/

/**
 * @param s: a string
 * @return bool: whether you can make s a palindrome by deleting at most one character
 */
bool validPalindrome(string &s) {
    // Write your code here
    //two pointers
    int left = 0;
    int right = s.size()-1;
    //to see how many mismatch
    int count = 0;
    //loop from left and right to the middle
    while(left<right){
        //if the current left and right are the same, move pointers and continue
        if(s[left] == s[right]){
            left++;
            right--;
        }
        else{
            //increase count;
            count++;
            //return false when count is greater than 1
            if(count>1){
                return false;
            }
            //if it`s ok to jump over the right pointer
            if(s[left] == s[right-1]){
                left++;
                right-=2;
            }
            //if it`s ok to jump over the left pointer
            else if(s[left+1] == s[right]){
                left+=2;
                right--;
            }
            //impossible to jump
            else{
                return false;
            }
        }
    }
    
    return true;
}