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
In a 2D grid from (0, 0) to (N-1, N-1), every cell contains a 1, except those cells in the given list mines which are 0. 
What is the largest axis-aligned plus sign of 1s contained in the grid? Return the order of the plus sign. 
If there is none, return 0.

An "axis-aligned plus sign of 1s of order k" has some center grid[x][y] = 1 along 
with 4 arms of length k-1 going up, down, left, and right, and made of 1s. 
This is demonstrated in the diagrams below. Note that there could be 0s or 1s beyond the arms of the plus sign, 
only the relevant area of the plus sign is checked for 1s.
*/

/**
 * @param N: size of 2D grid
 * @param mines: in the given list
 * @return: the order of the plus sign
 */
int orderOfLargestPlusSign(int N, vector<vector<int>> &mines) {
    // Write your code here
    //create the matrix and fill it with 1
    vector<vector<int>> matrix(N,vector<int>(N,1));
    //update the matrix by adding mines
    for(auto item:mines){
        matrix[item[0]][item[1]] = 0;
    }
    
    //create dp matrix to store the length of continous 1's length, in different directions
    vector<vector<int>> left(N,vector<int>(N));
    vector<vector<int>> right(N,vector<int>(N));
    vector<vector<int>> up(N,vector<int>(N));
    vector<vector<int>> down(N,vector<int>(N));
    //update up and left dp matrix
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            //update left dp matrix
            if(j == 0){
                left[i][j] = matrix[i][j] == 1? 1: 0;
            }else{
                left[i][j] = matrix[i][j] == 1? 1 + left[i][j-1]: 0;
            }
            
            //update up dp matrix
            if(i == 0){
                up[i][j] = matrix[i][j] == 1? 1: 0;
            }else{
                up[i][j] = matrix[i][j] == 1? 1 + up[i-1][j]: 0;
            }
        }
    }
    
    //update down and right matrix
    for(int i = N-1; i >= 0; i--){
        for(int j = N-1; j>= 0; j--){
            if(j == N-1){
                right[i][j] = matrix[i][j] == 1? 1: 0;
            }else{
                right[i][j] = matrix[i][j] == 1? 1 + right[i][j+1]: 0;
            }
            if(i == N-1){
                down[i][j] = matrix[i][j] == 1? 1: 0;
            }else{
                down[i][j] = matrix[i][j] == 1? 1 + down[i+1][j]: 0;
            }
        }
    }
    //result
    int result = 0;
    //search each center, see the the length of shortest edge of the cross
    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++){
            if(matrix[i][j] == 1){
                int cur = min(min(left[i][j], right[i][j]), min(up[i][j], down[i][j]));
                result = max(result, cur);
            }
        }
    }
    return result;
}