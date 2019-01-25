#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
*/

vector<int> getRow(int rowIndex) {
	if (rowIndex < 1) return { 1 };

	vector<int> result;

	result.push_back(1);
	result.push_back(1);

	for (int i = 1; i < rowIndex; i++) {
		result.push_back(1);
		for (int j = i; j >= 1; j--) {
			result[j] = result[j - 1] + result[j];
		}
	}

	return result;
}