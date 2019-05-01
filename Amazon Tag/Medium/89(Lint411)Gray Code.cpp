#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_map>

using namespace std;

/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, find the sequence of gray code. 
A gray code sequence must begin with 0 and with cover all 2n integers.
*/
    
/**
 * @param n: a number
 * @return: Gray code
 */
vector<int> grayCode(int n) {
    // write your code here
    vector<int> result;
    
    for(int i = 0; i<1<<n;i++){
        result.push_back(i^(i/2));
    }
    
    return result;
}