#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

/*
Given a roman numeral, convert it to an integer.
*/    

/**
 * @param s: Roman representation
 * @return: an integer
 */
int romanToInt(string &s) {
    // write your code here
    map<char,int> dict{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    
    if(s.empty()){
        return 0;
    }
    
    int result = dict[s[0]];
    
    for(int i = 1;i<s.size();i++){
        result+=dict[s[i]];
        
        if(dict[s[i-1]]<dict[s[i]]){
            result-=dict[s[i-1]]*2;
        }
    }
    
    return result;
}