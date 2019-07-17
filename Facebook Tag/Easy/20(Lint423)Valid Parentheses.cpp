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

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
*/  

/**
 * @param s: A string
 * @return: whether the string is a valid parentheses
 */
bool isValidParentheses(string &s) {
    // write your code here
    stack<char> parentheses;
    //save pairs of parentheses
    map<char,char> dict{{')','('},{']','['},{'}','{'}};
    
    //loop all element
    for(auto c : s){
        //meet left parenthes, push it into stack
        if(c == '(' || c =='{' || c=='['){
            parentheses.push(c);
        }
        else if(c == ')' || c == ']' || c =='}'){
            //meet the right parenthes
            if(parentheses.empty()){
                return false;
            }
            //pop the corresponding left parenthes
            if(parentheses.top() != dict[c]){
                return false;
            }
            
            parentheses.pop();
        }
    }
    
    return parentheses.empty();
}
    