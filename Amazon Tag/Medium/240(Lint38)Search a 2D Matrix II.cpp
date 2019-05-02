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
Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.

This matrix has the following properties:

Integers in each row are sorted from left to right.
Integers in each column are sorted from up to bottom.
No duplicate integers in each row or column.
*/

/**
 * @param matrix: A list of lists of integers
 * @param target: An integer you want to search in matrix
 * @return: An integer indicate the total occurrence of target in the given matrix
 */
int searchMatrix(vector<vector<int>> &matrix, int target) {
    // write your code here
    int result{0};
    
    if(matrix.empty()) return result;
    
    int row = matrix.size()-1;
    int col = 0;
    
    while(row>=0 && col<matrix[0].size()){
        if(matrix[row][col] == target){
            result++;
            row--;
        }
        else if(matrix[row][col]<target){
            col++;
        }
        else{
            row--;
        }
    }
    
    return result;
    
    
}