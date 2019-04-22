#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.
*/

void changeBoard(vector<vector<char>>& board, char Old, char New) {
	int rowNum = board.size();
	int colNum = board[0].size();

	for (int i = 0; i < rowNum; i++) {
		for (int j = 0; j < colNum; j++) {
			if (board[i][j] == Old) board[i][j] = New;
		}
	}
}

void solve(vector<vector<char>>& board) {
	if (board.empty()) return;

	int rowNum = board.size();
	int colNum = board[0].size();

	vector<vector<int>> neighbor{ {0,1},{0,-1},{-1,0},{1,0} };

	queue<vector<int>> bfs;

	for (int row = 1; row < rowNum - 1; row++) {
		for (int col = 1; col < colNum - 1; col++) {
			if (board[row][col] == 'O') {
				bfs.push({ row,col });

				bool isOK{ true };

				while (!bfs.empty()) {
					int r = bfs.front()[0];
					int c = bfs.front()[1];

					bfs.pop();

					board[r][c] = 'A';

					for (int i = 0; i < 4; i++) {
						int y = r + neighbor[i][0];
						int x = c + neighbor[i][1];

						if (y >= 0 && y < rowNum && x >= 0 && x < colNum && board[y][x] == 'O') {
							board[y][x] = 'A';

							bfs.push({ y,x });
							if (y == 0 || y == rowNum - 1 || x == 0 || x == colNum - 1) {
								board[y][x] = 'A';
								isOK = false;
							}
						}
					}
				}

				if (isOK) {
					changeBoard(board, 'A', 'X');
				}
				else {
					changeBoard(board, 'A', 'U');
				}
			}
		}
	}

	changeBoard(board, 'U', 'O');
}