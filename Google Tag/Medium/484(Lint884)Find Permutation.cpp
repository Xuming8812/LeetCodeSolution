#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_set>

using namespace std;

/*
By now, you are given a secret signature consisting of character 'D' and 'I'. 
'D' represents a decreasing relationship between two numbers, 'I' represents an increasing relationship between two numbers. 
And our secret signature was constructed by a special integer array, which contains uniquely all the different number from 1 to n 
(n is the length of the secret signature plus 1). For example, the secret signature "DI" can be constructed by array [2,1,3] or [3,1,2], 
but won't be constructed by array [3,2,4] or [2,1,3,4], which are both illegal constructing special string that can't represent the "DI" secret signature.

On the other hand, now your job is to find the lexicographically smallest permutation of [1, 2, ... n] could 
refer to the given secret signature in the input.
*/


/**
 * @param s: a string
 * @return: return a list of integers
 */
vector<int> findPermutation(string &s) {
    // write your code here
    
    int length = s.size();
    //create the result vector
    vector<int> result(length + 1);
    for (int i = 0; i < length + 1; ++i){
        result[i] = i + 1;
    } 
    /*
    D D I I D I
    1 2 3 4 5 6 7
    3 2 1 4 6 5 7
    
    只有D对应的位置附近的数字才需要变换，而且变换方法就是倒置一下字符串
    */
    for (int i = 0; i < length; ++i) {
        if (s[i] != 'D') continue;
        
        int j = i;
        
        while (s[i] == 'D' && i < length){
            ++i;
        } 
        //reverse
        reverse(result.begin() + j, result.begin() + i + 1);
        --i;
    }
    return result;

}