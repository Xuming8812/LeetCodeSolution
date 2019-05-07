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
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.
*/  


/**
 * @param matrix: a matrix of 0 and 1
 * @return: an integer
 */
int maxSquare(vector<vector<int>> &matrix){
    // write your code here
    //corner case
    int rowNum = matrix.size();
    if (!rowNum) return 0;
    int colNum = matrix[0].size();
    if (!colNum) return 0;
    
    //build the dp matrix, dp[i][j] is the largest edge of all 1 square, for matrix[0][0] to matrix[i][j]
    vector<vector<int>> dp(rowNum, vector<int>(colNum));
    
    //boundary condition
    for(int i = 0; i < colNum; i++){
        dp[0][i] = matrix[0][i];
    }
        
    for(int i = 0; i < rowNum; i++){
        dp[i][0] = matrix[i][0];
    }
        
    int ans = 0;
    
    for(int i = 1; i < rowNum; i++){
        for (int j = 1; j < colNum; j++){
            //if matrix[i][j] is 1
            if (matrix[i][j]){
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
            } 
            else{
                dp[i][j] = 0;
            }
        }
    }
    
    
    //find largest one in dp matrix
    for(int i = 0; i < rowNum; i++){
        for(int j = 0; j < colNum; j++){
            ans = max(ans, dp[i][j]);  
        }
    }

    return ans * ans;

}