#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a list of strings, you need to find the longest uncommon subsequence among them. 
The longest uncommon subsequence is defined as the longest subsequence of one of these strings 
and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters 
without changing the order of the remaining elements. Trivially, any string is a subsequence of 
itself and an empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the length of the longest 
uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.
*/


/**
 * @param strs: List[str]
 * @return: return an integer
 */
int findLUSlength(vector<string>& strs) {
    if (strs.empty()){
        return -1;
    } 
    
    int result = -1;
    
    for(auto i = 0; i < strs.size(); i++) {
        
        int j = 0;
        
        for(j=0; j < strs.size(); j++) {
            if(i==j) continue;
            if(LCS(strs[i], strs[j])) break;  // strs[j] is a subsequence of strs[i]
        }
        // strs[i] is not any subsequence of the other strings.
        if(j==strs.size()){
            result = max(result, static_cast<int>(strs[i].size()));
        }
    }
    return result;
}
// iff a is a subsequence of b
bool LCS(const string& a, const string& b) {
    if (b.size() < a.size()) return false;
    int i = 0;
    
    for(auto ch: b) {
        if(i < a.size() && a[i] == ch){
            i++;
        } 
    }
    
    return i == a.size();
}