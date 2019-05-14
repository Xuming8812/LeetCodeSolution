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
    //the matrix to save if a position has already been visited
    vector<vector<bool>> used(board.size(),vector<bool>(board[0].size(),false));
    //corner case
    if(board.empty()) return false;


    //loop all position to start the find the word        
    for(int row = 0;row<board.size();row++){
        for(int col = 0;col<board[0].size();col++ ){

            //call the helper function to see if find the string
            bool result = existHelper(board,word,row,col,0,used);
            
            if(result){
                return true;
            }
        }
    }
    
    return false;
}
//the helper function to find a word by dfs
bool existHelper(vector<vector<char>>& board,string word, int row, int col, int index,vector<vector<bool>>& used){
    //find the word
    if(index == word.size()){
        return true;
    }
    //out of range or the current position is visited
    if(row<0 || row>=board.size()||col<0 || col>=board[0].size()||used[row][col]){
        return false;
    }
    //if the current letter match
    if(board[row][col] == word[index]){
        bool result{false};
        //mark the current position
        used[row][col] = true;
        //dfs the 4 neighbors
        result = existHelper(board,word,row-1,col,index+1,used)||
                existHelper(board,word,row+1,col,index+1,used)||
                existHelper(board,word,row,col-1,index+1,used)||
                existHelper(board,word,row,col+1,index+1,used);
        //unmark this position
        used[row][col] = false;
            
        if(result){
            return true;
        }    
        
    }
    
    return false;
}