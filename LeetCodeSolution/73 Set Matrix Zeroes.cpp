#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
*/

void setZeroes(vector<vector<int>>& matrix) {

	bool isFirstRow{ false }, isFisrtCol{ false };

	for (int row = 0; row < matrix.size(); row++) {
		if (matrix[row][0] == 0) {
			isFisrtCol = true;
			break;
		}
	}

	for (int col = 0; col < matrix[0].size(); col++) {
		if (matrix[0][col] == 0) {
			isFirstRow = true;
			break;
		}
	}

	//mark
	for (int row = 1; row < matrix.size(); row++) {
		for (int col = 1; col < matrix[0].size(); col++) {
			if (matrix[row][col] == 0) {
				matrix[row][0] = 0;
				matrix[0][col] = 0;
			}
		}
	}

	//change all but the first row and first column
	for (int row = 1; row < matrix.size(); row++) {
		if (matrix[row][0] == 0) {
			for (int col = 0; col < matrix[0].size(); col++) {
				matrix[row][col] = 0;
			}
		}
	}

	for (int col = 1; col < matrix[0].size(); col++) {
		if (matrix[0][col] == 0) {
			for (int row = 0; row < matrix.size(); row++) {
				matrix[row][col] = 0;
			}
		}
	}

	//change all but the first row and first column
	if (isFirstRow) {
		for (int col = 0; col < matrix[0].size(); col++) {
			matrix[0][col] = 0;
		}
	}

	if (isFisrtCol) {
		for (int row = 0; row < matrix.size(); row++) {
			matrix[row][0] = 0;
		}
	}
}