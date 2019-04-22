#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {

	if (matrix.empty()) {
		return false;
	}

	if (matrix[0].empty())
	{
		return false;
	}

	int rowNum = matrix.size(), colNum = matrix[0].size();

	int start = 0, end = rowNum * colNum - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;

		int row = mid / colNum;
		int col = mid % colNum;
		if (matrix[row][col] == target) {
			return true;
		}
		else if (matrix[row][col] > target) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return false;
}