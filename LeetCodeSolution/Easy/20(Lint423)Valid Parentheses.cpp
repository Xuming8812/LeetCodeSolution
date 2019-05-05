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
    