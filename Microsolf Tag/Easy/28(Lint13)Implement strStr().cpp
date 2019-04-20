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
For a given source string and a target string, you should output the first index(from 0) of target string in source string.

If target does not exist in source, just return -1.
*/


/**
 * @param source: 
 * @param target: 
 * @return: return the index
 */
int strStr(string &source, string &target) {
    // Write your code here
    
    int lengthS = source.size();
    int lengthT = target.size();
    
    for(int i = 0;i<lengthS-lengthT+1;i++){
        
        bool isMatch = true;
        
        for(int j = 0;j<lengthT;j++){
            if(target[j]!=source[i+j]){
                isMatch=false;
                break;
            }
        }
        
        if(isMatch){
            return i;
        }
    }
    
    return -1;
}