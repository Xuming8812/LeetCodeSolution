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
Given an unsorted array of integers, find the length of longest increasing subsequence.
*/

class NumMatrix {
public:
	NumMatrix(vector<vector<int>> matrix) {

		if (!matrix.empty()) {
			int rowNum = matrix.size();
			int colNum = matrix[0].size();

			store.resize(rowNum + 1, vector<int>(colNum + 1, 0));
			store[1][1] = matrix[0][0];

			for (int i = 2; i <= colNum; i++) {
				store[1][i] = store[1][i - 1] + matrix[0][i - 1];
			}

			for (int i = 2; i <= rowNum; i++) {
				store[i][1] = store[i - 1][1] + matrix[i - 1][0];
			}

			for (int row = 2; row <= rowNum; row++) {
				for (int col = 2; col <= colNum; col++) {
					store[row][col] = -store[row - 1][col - 1] + store[row][col - 1] + store[row - 1][col] + matrix[row - 1][col - 1];
				}
			}
		}

	}

	int sumRegion(int row1, int col1, int row2, int col2) {

		if (store.empty()) return 0;
		return store[row2 + 1][col2 + 1] - store[row2 + 1][col1] - store[row1][col2 + 1] + store[row1][col1];
	}

	vector<vector<int>> store;
};