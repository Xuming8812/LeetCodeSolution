#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;


/*
Given a group of two strings, you need to find the longest uncommon subsequence of this group of two strings. 
The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence 
should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing 
he order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be two strings, and the output needs to be the length of the longest uncommon subsequence. 
If the longest uncommon subsequence doesn't exist, return -1.
*/

/**
 * @param a: a string
 * @param b: a string
 * @return: return a integer
 */
int findLUSlength(string &a, string &b) {
    // write your code here

    if(a == b){
        return -1;
    }
    
    return max(a.size(),b.size());
}