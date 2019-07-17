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
Give an integer array，find the longest increasing continuous subsequence in this array.

An increasing continuous subsequence:

Can be from right to left or from left to right.
Indices of the integers in the subsequence should be continuous.   
*/  

/**
 * @param A: An array of Integer
 * @return: an integer
 */
int longestIncreasingContinuousSubsequence(vector<int> &A) {
    // write your code here
    //corner case
    if (A.size() <2) {
        return (int)A.size();
    }

    int n = A.size();
    
    //two variables to save increasing and decreasing length
    int maxI = 1;
    int maxD = 1;
    
    int result = INT_MIN;
    
    //one pass
    for (int i = 1; i < n; i++) {
        
        if (A[i] > A[i - 1]) {
            //if increasing
            maxI++;
            maxD = 1;
        } 
        else if(A[i] < A[i - 1]){
            //if decreasing
            maxI = 1;
            maxD++;
        }
        else{
            //if equal to former element
            maxD = 1;
            maxI = 1;
        }
        //get the max length betwwen increasing and decreasing subsequece
        result = max(max(maxI, maxD), result);
    }
    
    return result;
}