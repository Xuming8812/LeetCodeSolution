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
Given two rectangles, find if the given two rectangles overlap or not.
*/  

/**
 * @param s: A string
 * @return: whether the string is a valid parentheses
 */
bool isValidParentheses(string &s) {
    // write your code here
    stack<char> parentheses;
    
    map<char,char> dict{{')','('},{']','['},{'}','{'}};
    
    for(auto c : s){
        if(c == '(' || c =='{' || c=='['){
            parentheses.push(c);
        }
        else if(c == ')' || c == ']' || c =='}'){
            if(parentheses.empty())
            {
                return false;
            }
            
            if(parentheses.top() != dict[c]){
                return false;
            }
            
            parentheses.pop();
        }
    }
    
    return parentheses.empty();
}
    