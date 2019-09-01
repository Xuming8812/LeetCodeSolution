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
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. 
You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
*/  
    
/**
 * @param s: a string
 * @return: return a boolean
 */

bool repeatedSubstringPattern(string &s){
    int length = s.size();
    //loop all possible length of pattern
    for(int i = 1;i<length;i++){
        //if the length can be divided by the current number
        if(length%i == 0){
            string temp;
            //get the pattern
            string sub = s.substr(0,i);
            //get the generated string
            for(int times = 0;times<length/i;times++){
                temp+=sub;
            }
            //see if equals to old string
            if(temp == s){
                return true;
            }
        }
    }
    
    return false;
}