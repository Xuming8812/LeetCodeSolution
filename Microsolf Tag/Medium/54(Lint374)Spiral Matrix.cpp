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
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
*/



/**
 * @param matrix: a matrix of m x n elements
 * @return: an integer list
 */
vector<int> spiralOrder(vector<vector<int>> &matrix) {
    // write your code here

    vector<int> result;
    
    if(matrix.empty()){
        return result;
    }
    
    vector<int> dx{1,0,-1,0};
    vector<int> dy{0,1,0,-1};
    
    int rowNums = matrix.size();
    int colNums = matrix[0].size();
    
    vector<vector<bool>> visited(rowNums,vector<bool>(colNums));
    
    int row = 0;
    int col = 0;
    int step = 0;

    //loop m*n times to cover all position
    for(int i = 0;i<rowNums*colNums;i++){
        result.push_back(matrix[row][col]);
        visited[row][col] = true;
        //get next position
        int nextRow = row + dy[step];
        int nextCol = col + dx[step];
        
        //if hit the wall, rotate
        if(nextRow<0 || nextRow>= rowNums || nextCol <0 || nextCol>= colNums || visited[nextRow][nextCol]){
            step = (step+1)%4;
            nextRow = row + dy[step];
            nextCol = col + dx[step];
        }
        
        row = nextRow;
        col = nextCol;
    }
    
    return result;
}