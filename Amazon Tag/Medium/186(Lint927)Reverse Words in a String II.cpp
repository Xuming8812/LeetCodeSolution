#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_map>

using namespace std;

/*
Given an input character array, reverse the array word by word. A word is defined as a sequence of non-space characters.

The input character array does not contain leading or trailing spaces and the words are always separated by a single space.
*/


/**
 * @param str: a string
 * @return: return a string
 */
string reverseWords(string &str) {
    // write your code here
    if(str.empty()){
        return str;
    }
    int index = 0;
    while(index <str.size()){
        if(!isLetter(str[index])){
            index++;
            continue;
        }
        
        int end = index;
        
        while(end<str.size() && isLetter(str[end])){
            end++;
        }
        
        reverse(str,index,end-1);
        
        index = end;
    }
    
    reverse(str,0,str.size()-1);
    
    return str;
}

void reverse(string & str, int start, int end){
    while(start<end){
        swap(str[start++],str[end--]);
    }
}

bool isLetter(char input){
    return (input>='a'&& input<='z')|| (input>='A'&& input<='Z');
}