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
Given two Sparse Matrix A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.
*/

/**
 * @param A: a sparse matrix
 * @param B: a sparse matrix
 * @return: the result of A * B
 */
vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
    
    // write your code here
    vector<vector<int>> result;
    //corner case
    if (A.empty()||B.empty()){
    return result;
    }
    //row number of first matrix
    int m = A.size();
    //column number of first matrix, also the row number of second matrix
    int t = A[0].size();
    //column number of the second matrix
    int n = B[0].size();
    //the final matrix, same row numbers with first matrix and same column number with the second matrix
    result.resize(m,vector<int>(n,0));
    
    //switch the order of loop, loop all elements in first matrix instead of the final matrix, so that we can ignore the zero elements
    for (int i = 0;i<m;i++){
        for(int k = 0;k<t;k++){
            //skip the zero element
            if(A[i][k] == 0){
                continue;
            }
            //loop columns of the final matrix
            for(int j = 0;j<n;j++){
                result[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    
    return result;

}