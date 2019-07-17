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
You are given a license key represented as a string S which consists only alphanumeric character and dashes. 
The string is separated into N+1 groups by N dashes.

Given a number K, we would want to reformat the strings such that each group contains exactly K characters, 
except for the first group which could be shorter than K, but still must contain at least one character. 
Furthermore, there must be a dash inserted between two groups and all lowercase letters should be converted to uppercase.

Given a non-empty string S and a number K, format the string according to the rules described above.
*/


/**
 * @param S: a string
 * @param K: a integer
 * @return: return a string
 */
string licenseKeyFormatting(string &S, int K) {
    // write your code here
    
    int index = S.size()-1;
    
    transform(S.begin(),S.end(),S.begin(),::toupper);
    
    int count = 0;
    
    string result;
    
    while(index>=0){
        if(S[index]=='-'){
            index--;
            continue;
        }
        
        count++;
        result = string(1,S[index])+result;
        
        if(count == K){
            result = "-" + result;
            count = 0;
        }
        
        index--;
    }
    
    if(!result.empty()&&result[0]=='-'){
        return result.substr(1);
    }
    
    return result;
}