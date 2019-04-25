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
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.
*/

/**
 * @param s: a string,  encoded message
 * @return: an integer, the number of ways decoding
 */
int numDecodings(string& s) {

    if(s.empty()){
        return 0;
    }

    vector<int> results(s.size()+1);
    results[0] = 1;

    for(int i = 0;i<s.size();i++){
        if(s[i]!='0'){
            results[i+1]+=results[i];
        }
        
        if(i>=1&& s[i-1]!='0'&&(s[i-1]-'0')*10+s[i]-'0'<=26){
            results[i+1]+=results[i-1];
        }
    }

    return results[s.size()];
    
}