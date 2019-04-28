#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).
*/
void rotate(vector<vector<int>>& matrix) {
    

    flip(matrix);
    
    tranpose(matrix);        
}

void flip(vector<vector<int>>& matrix){
    
    int rowNum = matrix.size();
    int colNum = matrix[0].size();
    
    for(int row = 0;row<rowNum/2;row++){
        for(int col = 0 ; col < colNum; col++){
            
            swap(matrix,row,col,rowNum-1-row,col);
            
        }
    }
}

void tranpose(vector<vector<int>>& matrix){
    int rowNum = matrix.size();
    int colNum = matrix[0].size();
    
    for(int row = 0;row<rowNum;row++){
        for(int col = row ; col < colNum; col++){
            
            swap(matrix,row,col,col,row);
            
        }
    }
    
}

void swap(vector<vector<int>>& matrix,int row1, int col1, int row2, int col2){
    int temp{matrix[row1][col1]};
    
    matrix[row1][col1] = matrix[row2][col2];
    
    matrix[row2][col2] = temp;
}