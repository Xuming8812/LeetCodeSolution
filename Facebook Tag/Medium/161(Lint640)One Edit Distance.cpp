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
Given two strings S and T, determine if they are both one edit distance apart.
*/

/**
 * @param s: a string
 * @param t: a string
 * @return: true if they are both one edit distance apart or false
 */
bool isOneEditDistance(string &s, string &t) {
    // write your code here
    //corner case
    if(s.empty() || t.empty()){
        return false;
    }
    if(s == t){
        return false;
    }
    
    int lengthS = s.size();
    int lengthT = t.size();
    
    if(abs(lengthT-lengthS)>1){
        return false;
    }
    
    //get the smaller length
    int len = min(lengthT,lengthS);
    
    for(int i = 0;i<len;i++){
        //find the first digit that two strings don't match
        if(s[i] != t[i]){
            //see if one edit distance 
            return s.substr(i) == t.substr(i+1) || s.substr(i+1) == t.substr(i) || s.substr(i+1) == t.substr(i+1);
        }
    }
    
    return true;
}