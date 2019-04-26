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
Given a map size of m*n, 1 means space, 0 means obstacle, 9 means the endpoint. You start at (0,0) and return whether you can reach the endpoint.
*/  
    
/**
 * @param s: a string
 * @return: return a boolean
 */

bool repeatedSubstringPattern(string &s){
    int length = s.size();
    
    for(int i = 1;i<length;i++){
        
        if(length%i == 0){
            string temp;
            string sub = s.substr(0,i);
            for(int times = 0;times<length/i;times++){
                temp+=sub;
            }
            
            if(temp == s){
                return true;
            }
        }
    }
    
    return false;
}