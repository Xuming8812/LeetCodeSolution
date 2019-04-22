#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<iostream>

using namespace std;

/*
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
*/


//similar with 54 spiral matrix
vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> result(n, vector<int>(n, 0));

	if (n == 0) return result;

	int row{ 0 }, col{ 0 };

	vector<int> dx{ 1,0,-1,0 };
	vector<int> dy{ 0,1,0,-1 };

	int next{ 0 };

	for (int i = 1; i <= n * n; i++) {
		result[row][col] = i;

		int nextRow = row + dy[next];
		int nextCol = col + dx[next];

		if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n || result[nextRow][nextCol] != 0) {
			next = (next + 1) % 4;

			nextRow = row + dy[next];
			nextCol = col + dx[next];
		}

		row = nextRow;
		col = nextCol;
	}

	return result;
}