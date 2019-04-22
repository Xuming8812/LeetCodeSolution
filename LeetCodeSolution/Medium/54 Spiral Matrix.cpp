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
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
*/


vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> result;

	if (matrix.empty()) { return result; }

	vector<int> dx{ 0,1,0,-1 };
	vector<int> dy{ 1,0,-1,0 };

	int next{ 0 };

	int row{ 0 }, col{ 0 };

	for (int i = 0; i < matrix.size()*matrix[0].size(); i++) {
		result.push_back(matrix[row][col]);

		matrix[row][col] = 0;

		int next_x = row + dx[next];
		int next_y = col + dy[next];

		//if cross boundary or visited element
		if (next_x < 0 || next_x >= matrix.size() || next_y >= matrix[0].size() || next_y < 0 || matrix[next_x][next_y] == 0) {

			next = (next + 1) % 4;

			next_x = row + dx[next];
			next_y = col + dy[next];
		}

		row = next_x;
		col = next_y;

	}

	return result;
}