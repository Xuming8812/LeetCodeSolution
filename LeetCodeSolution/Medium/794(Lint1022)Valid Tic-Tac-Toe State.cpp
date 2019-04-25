
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

/*
A Tic-Tac-Toe board is given as a string array board. 
Return true if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.
*/

/**
 * @param board: the given board
 * @return: True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game
 */
bool validTicTacToe(vector<string> &board) {
    int xCount = 0, oCount = 0;
    for (string &line : board) {
        xCount += count(line.begin(), line.end(), 'X');
        oCount += count(line.begin(), line.end(), 'O');
    }
    
    if (xCount != oCount && xCount != oCount + 1) {
        return false;
    }
    
    // 两条对角线的胜利状态
    int winState = getWinState(board[0][0], board[1][1], board[2][2]) +
                    getWinState(board[0][2], board[1][1], board[2][0]);
    
    // 三行和三列的胜利状态
    for (int i = 0; i < 3; i++) {
        winState += getWinState(board[i][0], board[i][1], board[i][2]); 
        winState += getWinState(board[0][i], board[1][i], board[2][i]); 
    }        
    
    return winState == 0 ||                         // 没人胜利
            (winState == -10 && xCount == oCount) || // O 胜利, 这时必须是O刚好下完一子
            ((winState == 1 || winState == 2) && xCount == oCount + 1); // X有可能是两条对角线, 或者十字型, 故winState可以等于2 (不可能是两条竖线或两条水平线, 这样不会满足数量关系)
}

// 若 X 胜, 返回1, 若 O 胜, 返回-10
int getWinState(char c1, char c2, char c3) {
    if (c1 != ' ' && c1 == c2 && c2 == c3) {
        return c1 == 'X' ? 1 : -10;
    } 
    else {
        return 0;
    }
}