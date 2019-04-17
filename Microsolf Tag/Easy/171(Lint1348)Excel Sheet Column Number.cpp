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
Given a column title as appear in an Excel sheet, return its corresponding column number.
*/

/**
 * @param s: a string
 * @return: return a integer
 */
int titleToNumber(string &s) {
    // write your code here
    
    if(s.empty()) return 0;
    
    int result{s[0]-'A'+1};
    
    for(int i = 1;i<s.size();i++){
        result = 26*result+s[i]-'A'+1;
    }
    
    return result;
}