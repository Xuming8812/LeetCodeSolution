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
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/

/**
 * @param matrix: A lsit of lists of integers
 * @return: nothing
 */
    

void setZeroes(vector<vector<int>> &matrix) {
    // write your code here
    
    //corner case
    if(matrix.empty()) return;
    //get rowNum and colNum
    int rowNum = matrix.size();
    int colNum = matrix[0].size();
    //use to see whether the first col and row has zero
    bool isFirstRow{false},isFirstCol{false};
    //check first col
    for(int row = 0;row<rowNum;row++){
        if(matrix[row][0] == 0){
            isFirstCol = true;
            break;
        }
    }
    //check first row
    for(int col = 0;col<colNum;col++){
        if(matrix[0][col]==0){
            isFirstRow = true;
            break;
        }
    }
    
    for(int row = 1;row<rowNum;row++){
        for(int col = 1;col<colNum;col++){
            if(matrix[row][col] == 0){
                matrix[row][0] = 0;
                matrix[0][col] = 0;
            }
        }
    }
    
    for(int row = 1;row<rowNum;row++){
        if(matrix[row][0] == 0){
            for(int col = 0;col<colNum;col++){
                matrix[row][col] = 0;
            }
        }
    }
    
    for(int col = 1;col<colNum;col++){
        if(matrix[0][col] == 0){
            for(int row = 0;row<rowNum;row++){
                matrix[row][col] = 0;
            }
        }
    }
    
    if(isFirstRow){
        for(int col = 0;col<colNum;col++){
            matrix[0][col] = 0;
        }
    }
    
    if(isFirstCol){
        for(int row = 0;row<rowNum;row++){
            matrix[row][0] = 0;
        }
    }
}