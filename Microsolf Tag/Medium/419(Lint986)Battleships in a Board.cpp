#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s.

Note that for a head of a battle, it left and top element must be '.'
*/ 


/**
 * @param board: the given 2D board
 * @return: the number of battle ships
 */

//one pass and needn`t to change the input vector
int countBattleships(vector<vector<char>> &board) {
    // Write your code here
    
    int result{0};
    
    if(board.empty()){
        return result;
    }
    
    int rowNum = board.size();
    int colNum = board[0].size();
    
    for(int row = 0;row<rowNum;row++){
        for(int col = 0;col<colNum;col++){
            if(board[row][col] == 'X'){
                if((row == 0 || board[row-1][col] == '.') && (col == 0 || board[row][col-1] == '.')){
                    result++;
                }
            }
        }
    }
    
    return result;
}