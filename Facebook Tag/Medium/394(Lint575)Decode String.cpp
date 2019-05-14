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
Given an expression s contains numbers, letters and brackets. 
Number represents the number of repetitions inside the brackets(can be a string or another expression)．Please expand expression to be a string.
*/

/**
 * @param s: an expression includes numbers, letters and brackets
 * @return: a string
 */
string expressionExpand(string &s) {
    // write your code here
    
    //use the stack to store
    stack<string> store;
    
    string result;
    //corner case
    if(s.empty()){
        return result;
    }
    //the variable to store the count of a expression
    int count = 0;
    //loop all chars in the string
    for(int i = 0;i<s.size();i++){
        //if it is digit, update the count
        if(isdigit(s[i])){
            count = 10* count + s[i]-'0';
        }
        else if(s[i] == '['){
            //save the count of the expression
            store.push(to_string(count));
            //store '[' as a guard
            store.push("[");
            //reset count
            count = 0;
        }
        else if(s[i] == ']'){
            
            string temp;
            //loop until meeting the guard
            while(store.top()!="["){
                //save the string stored in the stack reversely
                temp = store.top()+temp;
                store.pop();
            }
            //pop out guard "["
            store.pop();
            //get the count
            int number = stoi(store.top());
            store.pop();
            //repeat the string count times
            string current;
            
            for(int j = 0;j<number;j++){
                current += temp;
            }
            //push the string back to stack
            store.push(current);
        }
        else{
            //just push into the stack
            store.push(string(1,s[i]));
        }
    }
    //get all string stored in the stack
    while(!store.empty()){
        result = store.top()+result;
        store.pop();
    }
    
    return result;
}

