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
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

/**
 * @param s: A string
 * @return: whether the string is a valid parentheses
 */
bool isValidParentheses(string &s) {
    // write your code here
    //use a stack to store the parentheses
    stack<char> parentheses;
    //the hashmap to store the corresponding parentheses
    map<char,char> dict{{')','('},{']','['},{'}','{'}};
    //loop all chars
    for(auto c : s){
        //save the left parentheses
        if(c == '(' || c =='{' || c=='['){
            parentheses.push(c);
        }
        //the right parentheses
        else if(c == ')' || c == ']' || c =='}'){
            //no left parentheses in the stack
            if(parentheses.empty()){
                return false;
            }
            //if not match
            if(parentheses.top() != dict[c]){
                return false;
            }
            //if match, pop the correponding parentheses
            parentheses.pop();
        }
    }
    
    return parentheses.empty();
}