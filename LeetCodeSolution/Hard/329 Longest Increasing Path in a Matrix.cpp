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
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: 
left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
*/

//dp matrix
vector<vector<int>> result;

vector<pair<int, int>> direction{ {-1,0},{1,0},{0,-1},{0,1} };

int LIPHelper(vector<vector<int>>& matrix, int row, int col) {
	int len{ 0 };
	//loop all neighbors
	for (auto item : direction) {
		int y = row + item.first;
		int x = col + item.second;

		if (y >= 0 && y < matrix.size() && x >= 0 && x < matrix[0].size()) {
			if (matrix[y][x] > matrix[row][col]) {
				if (result[y][x] == -1) {
					result[y][x] = LIPHelper(matrix, y, x);
				}
				//get the largest value of neighbors
				len = max(len, result[y][x]);
			}
		}
	}
	//set the current value
	result[row][col] = len + 1;

	return result[row][col];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
	if (matrix.empty()) return 0;
	int ans{ 0 };

	int rowNum = matrix.size(), colNum = matrix[0].size();

	result = vector<vector<int>>(rowNum, vector<int>(colNum, -1));

	for (int row = 0; row < rowNum; row++) {
		for (int col = 0; col < colNum; col++) {
			if (result[row][col] == -1) {

				LIPHelper(matrix, row, col);
				ans = max(ans, result[row][col]);
			}
		}
	}

	return ans;
}