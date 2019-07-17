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
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.
Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
*/  

/**
 * @param matrix: the given matrix
 * @return: True if and only if the matrix is Toeplitz
 */
bool isToeplitzMatrix(vector<vector<int>> &matrix) {
    // Write your code here
    if(matrix.empty()){
        return false;
    }
    //get size of matrix
    int rowNum = matrix.size();
    int colNum = matrix[0].size();
    //upper part
    for(int i = 0;i<colNum;i++){
        int step = 1;
        //record the first element
        int current = matrix[0][i];
        //check each element on diagonal line
        while(step<rowNum && i+step<colNum){
            if(matrix[step][i+step]!=current){
                return false;
            }
            
            step++;
        }
    }
    //lower part
    for(int i = 1;i<rowNum;i++){
        int step = 1;
        //record the first element
        int current = matrix[i][0];
        //check each element on diagonal line
        while(i+step<rowNum && step<colNum){
            if(matrix[i+step][step]!=current){
                return false;
            }
            
            step++;
        }
    }
    
    return true;
}

