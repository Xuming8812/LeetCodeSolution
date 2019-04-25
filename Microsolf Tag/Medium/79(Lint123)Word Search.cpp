#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

/*
Given a 2D board and a word, find if the word exists in the grid.
*/

/**
 * @param board: A list of lists of character
 * @param word: A string
 * @return: A boolean
 */
bool exist(vector<vector<char>>& board, string word) {
    vector<vector<bool>> used(board.size(),vector<bool>(board[0].size(),false));
    if(board.empty()) return false;
            
    for(int row = 0;row<board.size();row++){
        for(int col = 0;col<board[0].size();col++ ){
            bool result = existHelper(board,word,row,col,0,used);
            
            if(result){
                return true;
            }
        }
    }
    
    return false;
}

bool existHelper(vector<vector<char>>& board,string word, int row, int col, int index,vector<vector<bool>>& used){
    if(index == word.size()){
        return true;
    }
    
    if(row<0 || row>=board.size()||col<0 || col>=board[0].size()||used[row][col]){
        return false;
    }
    
    if(board[row][col] == word[index]){
        bool result{false};
        
        used[row][col] = true;
        
        result = existHelper(board,word,row-1,col,index+1,used)||
                existHelper(board,word,row+1,col,index+1,used)||
                existHelper(board,word,row,col-1,index+1,used)||
                existHelper(board,word,row,col+1,index+1,used);
        
        used[row][col] = false;
            
        if(result){
            return true;
        }    
        
    }
    
    return false;
}