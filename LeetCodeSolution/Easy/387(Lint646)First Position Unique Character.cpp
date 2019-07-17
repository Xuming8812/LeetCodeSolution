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
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
*/

/**
 * @param s: a string
 * @return: it's index
 */
int firstUniqChar(string &s) {
    // write your code here
    
    int result = -1;
    
    //corner case
    if(s.empty()){
        return result;
    }
    
    //use a hash map to store number of chars in the string
    map<char,int>dict;
    
    for(auto item:s){
        dict[item]++;
    }
    
    //loop all chars to find which one occurs only once
    for(int i = 0;i<s.size();i++){
        if(dict[s[i]]==1){
            result = i;
            break;
        }
    }
    
    return result;
}