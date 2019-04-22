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

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> result;

	if (numRows == 0) return result;

	result.push_back({ 1 });

	for (int i = 1; i < numRows; i++) {
		vector<int> cur{ 1 };

		for (int j = 0; j < result.back().size() - 1; j++) {
			cur.push_back(result.back()[j] + result.back()[j + 1]);
		}

		cur.push_back(1);

		result.push_back(cur);
	}

	return result;
}