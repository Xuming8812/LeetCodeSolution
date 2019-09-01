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
The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.

11 is read off as "two 1s" or 21.

21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.
*/    
    
/**
 * @param n: the nth
 * @return: the nth sequence
 */
string countAndSay(int n) {
    // write your code here
    //corner case
    if(n<1){
        return "";
    }
    
    string result{"1"};
    //loop n times
    while(n>1){
        result = generate(result);
        n--;
    }
    
    return result;   
}
//helper function to generator string based on input string
string generate(string s)
{
    //get current char
    char current = s[0];
    //initialize the counter
    int count = 1;
    
    string result{""};
    //loop all char
    for(int i=1;i<s.size();i++){
        //if equals to previous char
        if(s[i] == current){
            count ++;
        }
        else{
            //update the result
            result = result+to_string(count)+to_string(current-'0');
            //reset current char and counter
            current = s[i];
            
            count =1;
        }
    }
    //save last char
    result = result+to_string(count)+to_string(current-'0');
    
    return result;   
}