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
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by 
the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its 
eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. 
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.
*/

void gameOfLife(vector<vector<int>>& board) {
	if (board.empty()) return;

	vector<vector<int>> result(board.size(), vector<int>(board[0].size()));

	vector<int> dx{ 1,1,1,0,0,-1,-1,-1 };
	vector<int> dy{ 0,1,-1,1,-1,0,-1,1 };

	for (int row = 0; row < board.size(); row++) {
		for (int col = 0; col < board[0].size(); col++) {
			int count{ 0 };

			for (int i = 0; i < 8; i++) {

				int x = col + dx[i];
				int y = row + dy[i];

				if (x >= 0 && x < board[0].size() && y >= 0 && y < board.size()) {
					count += board[y][x];
				}
			}

			if (board[row][col]) {
				if (count < 2 || count>3) {
					result[row][col] = 0;
				}
				else {
					result[row][col] = 1;
				}
			}
			else {
				if (count == 3) {
					result[row][col] = 1;
				}
				else {
					result[row][col] = 0;
				}
			}
		}
	}

	board = result;
}