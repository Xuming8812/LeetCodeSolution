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
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.empty()) return false;

	int rowNum = matrix.size();
	int colNum = matrix[0].size();

	int row = 0, col = colNum - 1;

	while (row < rowNum && col >= 0) {
		if (matrix[row][col] == target) {
			return true;
		}
		else if (matrix[row][col] > target) {
			col--;
		}
		else {
			row++;
		}
	}

	return false;
}