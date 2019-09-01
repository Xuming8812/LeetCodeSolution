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
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
*/

/**
 * @param n: a integer
 * @return: return a string
 */
string convertToTitle(int n) {
    // write your code here
    
    string result;
    
    //turn to 26 base
    while(n){
        //each time minus 1 because it start with 0
        n = n-1;
        int temp = n%26;
        result = string(1,'A'+temp)+result;
        n = n/26;
    }
    
    return result;
}