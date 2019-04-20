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
Given a collection of intervals, merge all overlapping intervals.
*/

/**
 * @param n: a integer
 * @return: return a string
 */
string convertToTitle(int n) {
    // write your code here
    
    string result;
    
    while(n){
        n = n-1;
        int temp = n%26;
        result = string(1,'A'+temp)+result;
        n = n/26;
    }
    
    return result;
}