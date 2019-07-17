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
Given two string S and T, determine if S can be changed to T by deleting some letters (including 0 letter)
*/  


/**
 * @param s: string S
 * @param t: string T
 * @return: whether S can convert to T
 */
bool canConvert(string &s, string &t) {
    // Write your code here
    if(s.size()<t.size()){
        return false;
    }
    if(t.empty()){
        return true;
    }
    
    int index = 0;
    
    for(int i = 0;i<s.size();i++){
        if(s[i] == t[index]){
            index++;
            if(index == t.size()){
                return true;
            }
        }
    }
    
    return false;
}