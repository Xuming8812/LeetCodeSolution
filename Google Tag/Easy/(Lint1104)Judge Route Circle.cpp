#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;


/*
Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, 
which means it moves back to the original place finally.

The move sequence is represented by a string. And each move is represent by a character. 
The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.
*/  



/**
 * @param moves: a sequence of its moves
 * @return: if this robot makes a circle
 */
bool judgeCircle(string &moves) {
    // Write your code here
    int countUD = 0;
    int countLR = 0;
    //loop each instruction to see the final position
    for(int i=0;i<moves.size();i++){
        if(moves[i] == 'L'){
            countLR++;
        }
        else if(moves[i] == 'R'){
            countLR--;
        }
        else if(moves[i] == 'U'){
            countUD++;
        }
        else if(moves[i] == 'D'){
            countUD--;
        }
    }
    
    return countUD == 0 && countLR==0;
}