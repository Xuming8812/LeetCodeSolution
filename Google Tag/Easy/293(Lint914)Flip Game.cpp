#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;


/*
You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, 
you and your friend take turns to flip two consecutive "++" into "--". 
The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to compute all possible states of the string after one valid move.
*/

/**
 * @param s: the given string
 * @return: all the possible states of the string after one valid move
 */
vector<string> generatePossibleNextMoves(string &s) {
    // write your code here
    
    vector<string> result;
    
    if(s.empty()){
        return result;
    }
    
    for(int i=0;i<s.size()-1;i++){
        if(s[i] == '+' && s[i+1] =='+'){
            string temp = s;
            temp[i] = '-';
            temp[i+1] = '-';
            result.push_back(temp);
        }
    }
    
    return result;
}